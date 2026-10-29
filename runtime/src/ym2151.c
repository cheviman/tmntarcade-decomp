/**
 *    Name:        ym2151.c
 *    Description: Yamaha YM2151 (OPM) FM sound chip: eight four-operator channels, the LFO and the noise, two
 *                 timers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows ymfm (Aaron Giles) sample for sample: its ym2151, which is fm_engine_base over
 *    opm_registers, and the YM3012 DAC's 10.3 floating point the samples go through. The tables of the
 *    chip's ROMs are ymfm's, which took them from the die (the phase steps from David Viens' analysis).
 *    kref --sound-check compares the two. ymfm's terms are in tools/core/konami/reference/ymfm/LICENSE.
 *
 *    How a sample is made: first the channels whose registers changed are refreshed (each operator works
 *    out its phase step, rates and levels from the registers, and takes its key), then the noise and the
 *    LFO step on, and every operator moves its envelope (on one sample in three) and its phase. Then each
 *    channel that can be heard runs its operators in the order its algorithm gives, each one's output
 *    shifting the phase of the next (the noise takes channel 7's last operator when it is on), and adds its
 *    carriers to the outputs it is routed to, clipped to 16 bits. Levels are logarithmic until the last
 *    step: an envelope or a sine is an attenuation, attenuations add, and one ROM turns the sum into a
 *    linear volume.
 */
#include "tmnt/ym2151.h"

#include <string.h>

#define PRESCALE            2          /* input clocks per operator slot */
#define ALL_CHANNELS        0xff
#define STATUS_TIMER_A      0x01
#define STATUS_TIMER_B      0x02
#define STATUS_BUSY         0x80
#define IRQ_SOURCES         (STATUS_TIMER_A | STATUS_TIMER_B)
#define QUIET               0x380      /* an envelope past this is heard as nothing */
#define STEP_FOLLOWS_LFO    1          /* an operator's step: work it out each sample, with the PM */
#define KEY_REGISTER        0          /* bits of an operator's keys */
#define KEY_CSM             2
#define CLIP                32767
#define BUSY_CLOCKS         (32 * PRESCALE)

enum { ATTACK, DECAY, SUSTAIN, RELEASE };

/* The registers the code names */
#define REG_TEST            0x01
#define REG_KEY             0x08
#define REG_NOISE           0x0f
#define REG_TIMER_A_HIGH    0x10
#define REG_TIMER_A_LOW     0x11
#define REG_TIMER_B         0x12
#define REG_MODE            0x14
#define REG_LFO_RATE        0x18
#define REG_LFO_AM_DEPTH    0x19
#define REG_LFO_PM_DEPTH    0x1a       /* (where the chip's second write to 0x19, bit 7 set, goes) */
#define REG_LFO_WAVE        0x1b

/* ---- arithmetic ---- */

static uint32_t field(uint32_t value, int start, int length)
{
	return (value >> start) & ((1u << length) - 1);
}

static int32_t clamp(int32_t value, int32_t low, int32_t high)
{
	if (value < low)
		return low;
	if (value > high)
		return high;
	return value;
}

/* ---- the chip's ROMs ---- */

/* The attenuation of |sin| over the first quarter of the wave (256 steps), 4.8 fixed point */
static const uint16_t quarter_sine[256] =
{
	0x859, 0x6c3, 0x607, 0x58b, 0x52e, 0x4e4, 0x4a6, 0x471, 0x443, 0x41a, 0x3f5, 0x3d3, 0x3b5, 0x398, 0x37e, 0x365,
	0x34e, 0x339, 0x324, 0x311, 0x2ff, 0x2ed, 0x2dc, 0x2cd, 0x2bd, 0x2af, 0x2a0, 0x293, 0x286, 0x279, 0x26d, 0x261,
	0x256, 0x24b, 0x240, 0x236, 0x22c, 0x222, 0x218, 0x20f, 0x206, 0x1fd, 0x1f5, 0x1ec, 0x1e4, 0x1dc, 0x1d4, 0x1cd,
	0x1c5, 0x1be, 0x1b7, 0x1b0, 0x1a9, 0x1a2, 0x19b, 0x195, 0x18f, 0x188, 0x182, 0x17c, 0x177, 0x171, 0x16b, 0x166,
	0x160, 0x15b, 0x155, 0x150, 0x14b, 0x146, 0x141, 0x13c, 0x137, 0x133, 0x12e, 0x129, 0x125, 0x121, 0x11c, 0x118,
	0x114, 0x10f, 0x10b, 0x107, 0x103, 0x0ff, 0x0fb, 0x0f8, 0x0f4, 0x0f0, 0x0ec, 0x0e9, 0x0e5, 0x0e2, 0x0de, 0x0db,
	0x0d7, 0x0d4, 0x0d1, 0x0cd, 0x0ca, 0x0c7, 0x0c4, 0x0c1, 0x0be, 0x0bb, 0x0b8, 0x0b5, 0x0b2, 0x0af, 0x0ac, 0x0a9,
	0x0a7, 0x0a4, 0x0a1, 0x09f, 0x09c, 0x099, 0x097, 0x094, 0x092, 0x08f, 0x08d, 0x08a, 0x088, 0x086, 0x083, 0x081,
	0x07f, 0x07d, 0x07a, 0x078, 0x076, 0x074, 0x072, 0x070, 0x06e, 0x06c, 0x06a, 0x068, 0x066, 0x064, 0x062, 0x060,
	0x05e, 0x05c, 0x05b, 0x059, 0x057, 0x055, 0x053, 0x052, 0x050, 0x04e, 0x04d, 0x04b, 0x04a, 0x048, 0x046, 0x045,
	0x043, 0x042, 0x040, 0x03f, 0x03e, 0x03c, 0x03b, 0x039, 0x038, 0x037, 0x035, 0x034, 0x033, 0x031, 0x030, 0x02f,
	0x02e, 0x02d, 0x02b, 0x02a, 0x029, 0x028, 0x027, 0x026, 0x025, 0x024, 0x023, 0x022, 0x021, 0x020, 0x01f, 0x01e,
	0x01d, 0x01c, 0x01b, 0x01a, 0x019, 0x018, 0x017, 0x017, 0x016, 0x015, 0x014, 0x014, 0x013, 0x012, 0x011, 0x011,
	0x010, 0x00f, 0x00f, 0x00e, 0x00d, 0x00d, 0x00c, 0x00c, 0x00b, 0x00a, 0x00a, 0x009, 0x009, 0x008, 0x008, 0x007,
	0x007, 0x007, 0x006, 0x006, 0x005, 0x005, 0x005, 0x004, 0x004, 0x004, 0x003, 0x003, 0x003, 0x002, 0x002, 0x002,
	0x002, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000
};

/* The linear volume of the fraction (low 8 bits) of an attenuation: a 10-bit mantissa under an implied
   0x400, from attenuation 0 (loudest) up */
static const uint16_t volume_mantissa[256] =
{
	0x3fa, 0x3f5, 0x3ef, 0x3ea, 0x3e4, 0x3df, 0x3da, 0x3d4, 0x3cf, 0x3c9, 0x3c4, 0x3bf, 0x3b9, 0x3b4, 0x3ae, 0x3a9,
	0x3a4, 0x39f, 0x399, 0x394, 0x38f, 0x38a, 0x384, 0x37f, 0x37a, 0x375, 0x370, 0x36a, 0x365, 0x360, 0x35b, 0x356,
	0x351, 0x34c, 0x347, 0x342, 0x33d, 0x338, 0x333, 0x32e, 0x329, 0x324, 0x31f, 0x31a, 0x315, 0x310, 0x30b, 0x306,
	0x302, 0x2fd, 0x2f8, 0x2f3, 0x2ee, 0x2e9, 0x2e5, 0x2e0, 0x2db, 0x2d6, 0x2d2, 0x2cd, 0x2c8, 0x2c4, 0x2bf, 0x2ba,
	0x2b5, 0x2b1, 0x2ac, 0x2a8, 0x2a3, 0x29e, 0x29a, 0x295, 0x291, 0x28c, 0x288, 0x283, 0x27f, 0x27a, 0x276, 0x271,
	0x26d, 0x268, 0x264, 0x25f, 0x25b, 0x257, 0x252, 0x24e, 0x249, 0x245, 0x241, 0x23c, 0x238, 0x234, 0x230, 0x22b,
	0x227, 0x223, 0x21e, 0x21a, 0x216, 0x212, 0x20e, 0x209, 0x205, 0x201, 0x1fd, 0x1f9, 0x1f5, 0x1f0, 0x1ec, 0x1e8,
	0x1e4, 0x1e0, 0x1dc, 0x1d8, 0x1d4, 0x1d0, 0x1cc, 0x1c8, 0x1c4, 0x1c0, 0x1bc, 0x1b8, 0x1b4, 0x1b0, 0x1ac, 0x1a8,
	0x1a4, 0x1a0, 0x19c, 0x199, 0x195, 0x191, 0x18d, 0x189, 0x185, 0x181, 0x17e, 0x17a, 0x176, 0x172, 0x16f, 0x16b,
	0x167, 0x163, 0x160, 0x15c, 0x158, 0x154, 0x151, 0x14d, 0x149, 0x146, 0x142, 0x13e, 0x13b, 0x137, 0x134, 0x130,
	0x12c, 0x129, 0x125, 0x122, 0x11e, 0x11b, 0x117, 0x114, 0x110, 0x10c, 0x109, 0x106, 0x102, 0x0ff, 0x0fb, 0x0f8,
	0x0f4, 0x0f1, 0x0ed, 0x0ea, 0x0e7, 0x0e3, 0x0e0, 0x0dc, 0x0d9, 0x0d6, 0x0d2, 0x0cf, 0x0cc, 0x0c8, 0x0c5, 0x0c2,
	0x0be, 0x0bb, 0x0b8, 0x0b5, 0x0b1, 0x0ae, 0x0ab, 0x0a8, 0x0a4, 0x0a1, 0x09e, 0x09b, 0x098, 0x094, 0x091, 0x08e,
	0x08b, 0x088, 0x085, 0x082, 0x07e, 0x07b, 0x078, 0x075, 0x072, 0x06f, 0x06c, 0x069, 0x066, 0x063, 0x060, 0x05d,
	0x05a, 0x057, 0x054, 0x051, 0x04e, 0x04b, 0x048, 0x045, 0x042, 0x03f, 0x03c, 0x039, 0x036, 0x033, 0x030, 0x02d,
	0x02a, 0x028, 0x025, 0x022, 0x01f, 0x01c, 0x019, 0x016, 0x014, 0x011, 0x00e, 0x00b, 0x008, 0x006, 0x003, 0x000
};

/* How much an envelope moves on each of eight successive steps at a rate (0-63), a nibble each with the
   first step lowest; on attack it is how big a part of the way to 0 it goes, in sixteenths */
static const uint32_t envelope_steps[64] =
{
	0x00000000, 0x00000000, 0x10101010, 0x10101010,
	0x10101010, 0x10101010, 0x11101110, 0x11101110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x10101010, 0x10111010, 0x11101110, 0x11111110,
	0x11111111, 0x21112111, 0x21212121, 0x22212221,
	0x22222222, 0x42224222, 0x42424242, 0x44424442,
	0x44444444, 0x84448444, 0x84848484, 0x88848884,
	0x88888888, 0x88888888, 0x88888888, 0x88888888
};

/* The phase step a detune of 1-3 adds, by key code (0-31) */
static const uint8_t detune_steps[32][4] =
{
	{ 0, 0, 1, 2 }, { 0, 0, 1, 2 }, { 0, 0, 1, 2 }, { 0, 0, 1, 2 },
	{ 0, 1, 2, 2 }, { 0, 1, 2, 3 }, { 0, 1, 2, 3 }, { 0, 1, 2, 3 },
	{ 0, 1, 2, 4 }, { 0, 1, 3, 4 }, { 0, 1, 3, 4 }, { 0, 1, 3, 5 },
	{ 0, 2, 4, 5 }, { 0, 2, 4, 6 }, { 0, 2, 4, 6 }, { 0, 2, 5, 7 },
	{ 0, 2, 5, 8 }, { 0, 3, 6, 8 }, { 0, 3, 6, 9 }, { 0, 3, 7, 10 },
	{ 0, 4, 8, 11 }, { 0, 4, 8, 12 }, { 0, 4, 9, 13 }, { 0, 5, 10, 14 },
	{ 0, 5, 11, 16 }, { 0, 6, 12, 17 }, { 0, 6, 13, 19 }, { 0, 7, 14, 20 },
	{ 0, 8, 16, 22 }, { 0, 8, 16, 22 }, { 0, 8, 16, 22 }, { 0, 8, 16, 22 }
};

/* The phase step of each of the 768 key codes and fractions of an octave (block 7), from the die */
static const uint32_t phase_steps[12 * 64] =
{
	41568, 41600, 41632, 41664, 41696, 41728, 41760, 41792, 41856, 41888, 41920, 41952,
	42016, 42048, 42080, 42112, 42176, 42208, 42240, 42272, 42304, 42336, 42368, 42400,
	42464, 42496, 42528, 42560, 42624, 42656, 42688, 42720, 42784, 42816, 42848, 42880,
	42912, 42944, 42976, 43008, 43072, 43104, 43136, 43168, 43232, 43264, 43296, 43328,
	43392, 43424, 43456, 43488, 43552, 43584, 43616, 43648, 43712, 43744, 43776, 43808,
	43872, 43904, 43936, 43968, 44032, 44064, 44096, 44128, 44192, 44224, 44256, 44288,
	44352, 44384, 44416, 44448, 44512, 44544, 44576, 44608, 44672, 44704, 44736, 44768,
	44832, 44864, 44896, 44928, 44992, 45024, 45056, 45088, 45152, 45184, 45216, 45248,
	45312, 45344, 45376, 45408, 45472, 45504, 45536, 45568, 45632, 45664, 45728, 45760,
	45792, 45824, 45888, 45920, 45984, 46016, 46048, 46080, 46144, 46176, 46208, 46240,
	46304, 46336, 46368, 46400, 46464, 46496, 46528, 46560, 46656, 46688, 46720, 46752,
	46816, 46848, 46880, 46912, 46976, 47008, 47072, 47104, 47136, 47168, 47232, 47264,
	47328, 47360, 47392, 47424, 47488, 47520, 47552, 47584, 47648, 47680, 47744, 47776,
	47808, 47840, 47904, 47936, 48032, 48064, 48096, 48128, 48192, 48224, 48288, 48320,
	48384, 48416, 48448, 48480, 48544, 48576, 48640, 48672, 48736, 48768, 48800, 48832,
	48896, 48928, 48992, 49024, 49088, 49120, 49152, 49184, 49248, 49280, 49344, 49376,
	49440, 49472, 49504, 49536, 49600, 49632, 49696, 49728, 49792, 49824, 49856, 49888,
	49952, 49984, 50048, 50080, 50144, 50176, 50208, 50240, 50304, 50336, 50400, 50432,
	50496, 50528, 50560, 50592, 50656, 50688, 50752, 50784, 50880, 50912, 50944, 50976,
	51040, 51072, 51136, 51168, 51232, 51264, 51328, 51360, 51424, 51456, 51488, 51520,
	51616, 51648, 51680, 51712, 51776, 51808, 51872, 51904, 51968, 52000, 52064, 52096,
	52160, 52192, 52224, 52256, 52384, 52416, 52448, 52480, 52544, 52576, 52640, 52672,
	52736, 52768, 52832, 52864, 52928, 52960, 52992, 53024, 53120, 53152, 53216, 53248,
	53312, 53344, 53408, 53440, 53504, 53536, 53600, 53632, 53696, 53728, 53792, 53824,
	53920, 53952, 54016, 54048, 54112, 54144, 54208, 54240, 54304, 54336, 54400, 54432,
	54496, 54528, 54592, 54624, 54688, 54720, 54784, 54816, 54880, 54912, 54976, 55008,
	55072, 55104, 55168, 55200, 55264, 55296, 55360, 55392, 55488, 55520, 55584, 55616,
	55680, 55712, 55776, 55808, 55872, 55936, 55968, 56032, 56064, 56128, 56160, 56224,
	56288, 56320, 56384, 56416, 56480, 56512, 56576, 56608, 56672, 56736, 56768, 56832,
	56864, 56928, 56960, 57024, 57120, 57152, 57216, 57248, 57312, 57376, 57408, 57472,
	57536, 57568, 57632, 57664, 57728, 57792, 57824, 57888, 57952, 57984, 58048, 58080,
	58144, 58208, 58240, 58304, 58368, 58400, 58464, 58496, 58560, 58624, 58656, 58720,
	58784, 58816, 58880, 58912, 58976, 59040, 59072, 59136, 59200, 59232, 59296, 59328,
	59392, 59456, 59488, 59552, 59648, 59680, 59744, 59776, 59840, 59904, 59936, 60000,
	60064, 60128, 60160, 60224, 60288, 60320, 60384, 60416, 60512, 60544, 60608, 60640,
	60704, 60768, 60800, 60864, 60928, 60992, 61024, 61088, 61152, 61184, 61248, 61280,
	61376, 61408, 61472, 61536, 61600, 61632, 61696, 61760, 61824, 61856, 61920, 61984,
	62048, 62080, 62144, 62208, 62272, 62304, 62368, 62432, 62496, 62528, 62592, 62656,
	62720, 62752, 62816, 62880, 62944, 62976, 63040, 63104, 63200, 63232, 63296, 63360,
	63424, 63456, 63520, 63584, 63648, 63680, 63744, 63808, 63872, 63904, 63968, 64032,
	64096, 64128, 64192, 64256, 64320, 64352, 64416, 64480, 64544, 64608, 64672, 64704,
	64768, 64832, 64896, 64928, 65024, 65056, 65120, 65184, 65248, 65312, 65376, 65408,
	65504, 65536, 65600, 65664, 65728, 65792, 65856, 65888, 65984, 66016, 66080, 66144,
	66208, 66272, 66336, 66368, 66464, 66496, 66560, 66624, 66688, 66752, 66816, 66848,
	66944, 66976, 67040, 67104, 67168, 67232, 67296, 67328, 67424, 67456, 67520, 67584,
	67648, 67712, 67776, 67808, 67904, 67936, 68000, 68064, 68128, 68192, 68256, 68288,
	68384, 68448, 68512, 68544, 68640, 68672, 68736, 68800, 68896, 68928, 68992, 69056,
	69120, 69184, 69248, 69280, 69376, 69440, 69504, 69536, 69632, 69664, 69728, 69792,
	69920, 69952, 70016, 70080, 70144, 70208, 70272, 70304, 70400, 70464, 70528, 70560,
	70656, 70688, 70752, 70816, 70912, 70976, 71040, 71104, 71136, 71232, 71264, 71360,
	71424, 71488, 71552, 71616, 71648, 71744, 71776, 71872, 71968, 72032, 72096, 72160,
	72192, 72288, 72320, 72416, 72480, 72544, 72608, 72672, 72704, 72800, 72832, 72928,
	72992, 73056, 73120, 73184, 73216, 73312, 73344, 73440, 73504, 73568, 73632, 73696,
	73728, 73824, 73856, 73952, 74080, 74144, 74208, 74272, 74304, 74400, 74432, 74528,
	74592, 74656, 74720, 74784, 74816, 74912, 74944, 75040, 75136, 75200, 75264, 75328,
	75360, 75456, 75488, 75584, 75648, 75712, 75776, 75840, 75872, 75968, 76000, 76096,
	76224, 76288, 76352, 76416, 76448, 76544, 76576, 76672, 76736, 76800, 76864, 76928,
	77024, 77120, 77152, 77248, 77344, 77408, 77472, 77536, 77568, 77664, 77696, 77792,
	77856, 77920, 77984, 78048, 78144, 78240, 78272, 78368, 78464, 78528, 78592, 78656,
	78688, 78784, 78816, 78912, 78976, 79040, 79104, 79168, 79264, 79360, 79392, 79488,
	79616, 79680, 79744, 79808, 79840, 79936, 79968, 80064, 80128, 80192, 80256, 80320,
	80416, 80512, 80544, 80640, 80768, 80832, 80896, 80960, 80992, 81088, 81120, 81216,
	81280, 81344, 81408, 81472, 81568, 81664, 81696, 81792, 81952, 82016, 82080, 82144,
	82176, 82272, 82304, 82400, 82464, 82528, 82592, 82656, 82752, 82848, 82880, 82976
};

/* The algorithms: where operators 2-4 take their modulation from (0 none, 1-3 operator 1-3, 5 operators
   1 + 2, 6 operators 1 + 3, 7 operators 2 + 3), and which of operators 1-3 are carriers besides 4
   (bit 0 operator 1, bit 1 operator 2, bit 2 operator 3) */
typedef struct algorithm
{
	uint8_t input2;
	uint8_t input3;
	uint8_t input4;
	uint8_t carriers;
} algorithm;

static const algorithm algorithms[8] =
{
	{ 1, 2, 3, 0 },     /* 1 > 2 > 3 > 4 */
	{ 0, 5, 3, 0 },     /* (1 + 2) > 3 > 4 */
	{ 0, 2, 6, 0 },     /* (1 + (2 > 3)) > 4 */
	{ 1, 0, 7, 0 },     /* ((1 > 2) + 3) > 4 */
	{ 1, 0, 3, 2 },     /* (1 > 2) + (3 > 4) */
	{ 1, 1, 1, 6 },     /* (1 > 2) + (1 > 3) + (1 > 4) */
	{ 1, 0, 0, 6 },     /* (1 > 2) + 3 + 4 */
	{ 0, 0, 0, 7 }      /* 1 + 2 + 3 + 4 */
};

/* The attenuation of the sine at a point of the wave (10 bits); bit 15 is the sign of the second half */
static uint32_t sine_attenuation(uint32_t point)
{
	const uint32_t quarter = (point & 0x100) ? ~point : point;

	return quarter_sine[quarter & 0xff] | ((point >> 9) & 1) << 15;
}

/* A 5.8 attenuation as a 13-bit linear volume */
static uint32_t attenuation_to_volume(uint32_t attenuation)
{
	return ((volume_mantissa[attenuation & 0xff] | 0x400u) << 2) >> (attenuation >> 8);
}

/* ymfm's opm_key_code_to_phase_step: the block, the key code (12 notes over 16 values) and its fraction,
   moved by 'delta' 64ths of a semitone, as a phase step */
static uint32_t key_code_to_phase_step(uint32_t block_frequency, int32_t delta)
{
	uint32_t block = field(block_frequency, 10, 3);
	const uint32_t adjusted = field(block_frequency, 6, 4) - field(block_frequency, 8, 2);
	int32_t frequency = (int32_t)((adjusted << 6) | field(block_frequency, 0, 6));

	frequency += delta;
	if ((uint32_t)frequency >= 768)
	{
		if (frequency < 0)
		{
			frequency += 768;
			if (block-- == 0)
				return phase_steps[0] >> 7;
		}
		else
		{
			frequency -= 768;
			if (frequency >= 768)
			{
				block++;
				frequency -= 768;
			}
			if (block++ >= 7)
				return phase_steps[767];
		}
	}
	return phase_steps[frequency] >> (block ^ 7);
}

/* ---- registers ---- */

static uint32_t chip_register(const ym2151 *chip, uint32_t number, int start, int length)
{
	return field(chip->registers[number], start, length);
}

/* Key code and fraction (13 bits) of a channel */
static uint32_t channel_frequency(const ym2151 *chip, uint32_t channel)
{
	return chip_register(chip, 0x28 + channel, 0, 7) << 6 | chip_register(chip, 0x30 + channel, 2, 6);
}

static uint32_t pm_sensitivity(const ym2151 *chip, uint32_t channel)
{
	return chip_register(chip, 0x38 + channel, 4, 3);
}

static uint32_t am_sensitivity(const ym2151 *chip, uint32_t channel)
{
	return chip_register(chip, 0x38 + channel, 0, 2);
}

static uint32_t pm_depth(const ym2151 *chip)
{
	return chip_register(chip, REG_LFO_PM_DEPTH, 0, 7);
}

static bool noise_enabled(const ym2151 *chip)
{
	return chip_register(chip, REG_NOISE, 7, 1) != 0;
}

/* ---- status and timers ---- */

static void check_irq(ym2151 *chip)
{
	const uint8_t before = chip->irq_state;

	chip->irq_state = (chip->status & IRQ_SOURCES) != 0;
	if (chip->irq_state != before && chip->update_irq)
		chip->update_irq(chip->host, chip->irq_state != 0);
}

static void change_status(ym2151 *chip, uint8_t set, uint8_t clear)
{
	chip->status = (uint8_t)((chip->status | set) & ~(clear | STATUS_BUSY));
	check_irq(chip);
}

/* Starts a timer that is enabled and not running, with 'delta' added to its period in samples; stops
   one that is not enabled */
static void update_timer(ym2151 *chip, int timer, bool enable, int32_t delta)
{
	if (enable && !chip->timer_running[timer])
	{
		uint32_t period;

		if (timer == 0)
			period = 1024 - ((uint32_t)chip->registers[REG_TIMER_A_HIGH] << 2 | chip_register(chip, REG_TIMER_A_LOW, 0, 2));
		else
			period = 16 * (256 - (uint32_t)chip->registers[REG_TIMER_B]);
		period += (uint32_t)delta;
		if (chip->set_timer)
			chip->set_timer(chip->host, timer, (int32_t)(period * YM2151_OPERATORS * PRESCALE));
		chip->timer_running[timer] = 1;
	}
	else if (!enable)
	{
		if (chip->set_timer)
			chip->set_timer(chip->host, timer, -1);
		chip->timer_running[timer] = 0;
	}
}

/* ---- operators ---- */

/* Hand a key on or off from one source to the operators of a channel: bit n of 'operators' is
   operator n + 1. The envelopes take it at the next refresh. */
static void key_channel(ym2151_channel *channel, uint32_t operators, int source)
{
	for (int index = 0; index < 4; index++)
	{
		ym2151_operator *op = channel->operators[index];

		op->keys = (uint8_t)((op->keys & ~(1u << source)) | field(operators, index, 1) << source);
	}
}

/* An operator's phase step, with the LFO's PM 'pm' (ymfm's opm_registers::compute_phase_step) */
static uint32_t phase_step(const ym2151 *chip, uint32_t channel, uint32_t at, const ym2151_operator *op, int32_t pm)
{
	/* the coarse detune DT2, in 64ths of a semitone */
	static const int16_t detune2[4] = { 0, (600 * 64 + 50) / 100, (781 * 64 + 50) / 100, (950 * 64 + 50) / 100 };
	int32_t delta = detune2[chip_register(chip, 0xc0 + at, 6, 2)];
	const uint32_t sensitivity = pm_sensitivity(chip, channel);

	if (sensitivity != 0)
	{
		if (sensitivity < 6)
			delta += pm >> (6 - sensitivity);
		else
			delta += (int32_t)((uint32_t)pm << (sensitivity - 5));
	}

	uint32_t step = key_code_to_phase_step(op->block_frequency, delta);

	step += (uint32_t)op->detune;
	return (step * op->multiple) >> 1;
}

/* A rate (0-63) with key scaling added; 0 stays 0 */
static uint8_t scaled_rate(uint32_t rate, uint32_t scaling)
{
	if (rate == 0)
		return 0;
	return (uint8_t)(rate + scaling < 63 ? rate + scaling : 63);
}

/* What the registers make of an operator (ymfm's cache_operator_data) */
static void refresh_values(const ym2151 *chip, uint32_t channel, uint32_t at, ym2151_operator *op)
{
	const uint32_t block_frequency = channel_frequency(chip, channel);
	const uint32_t key_code = field(block_frequency, 8, 5);
	const uint32_t detune = chip_register(chip, 0x40 + at, 4, 3);
	const int32_t detune_step = detune_steps[key_code][detune & 3];

	op->block_frequency = block_frequency;
	op->detune = (detune & 4) ? -detune_step : detune_step;
	op->multiple = chip_register(chip, 0x40 + at, 0, 4) * 2;
	if (op->multiple == 0)
		op->multiple = 1;
	if (pm_depth(chip) == 0 || pm_sensitivity(chip, channel) == 0)
		op->step = phase_step(chip, channel, at, op, 0);
	else
		op->step = STEP_FOLLOWS_LFO;
	op->total_level = chip_register(chip, 0x60 + at, 0, 7) << 3;

	/* 4 bits of sustain level, 15 meaning 31 */
	uint32_t sustain = chip_register(chip, 0xe0 + at, 4, 4);

	sustain |= (sustain + 1) & 0x10;
	op->sustain_level = sustain << 5;

	const uint32_t scaling = key_code >> (chip_register(chip, 0x80 + at, 6, 2) ^ 3);

	op->rates[ATTACK] = scaled_rate(chip_register(chip, 0x80 + at, 0, 5) * 2, scaling);
	op->rates[DECAY] = scaled_rate(chip_register(chip, 0xa0 + at, 0, 5) * 2, scaling);
	op->rates[SUSTAIN] = scaled_rate(chip_register(chip, 0xc0 + at, 0, 5) * 2, scaling);
	op->rates[RELEASE] = scaled_rate(chip_register(chip, 0xe0 + at, 0, 4) * 4 + 2, scaling);
}

/* Key on: the attack starts from where the envelope is, the phase from 0 */
static void start_attack(ym2151_operator *op)
{
	if (op->stage == ATTACK)
		return;
	op->stage = ATTACK;
	op->phase = 0;
	/* the fastest attacks jump straight to the top */
	if (op->rates[ATTACK] >= 62)
		op->attenuation = 0;
}

static void start_release(ym2151_operator *op)
{
	if (op->stage >= RELEASE)
		return;
	op->stage = RELEASE;
}

/* The refresh of an operator: its values, and its key. Whether it may still be heard. */
static bool refresh_operator(const ym2151 *chip, uint32_t channel, uint32_t at, ym2151_operator *op)
{
	refresh_values(chip, channel, at, op);

	const uint8_t key = op->keys != 0;

	if (key != op->key)
	{
		op->key = key;
		if (key)
			start_attack(op);
		else
			start_release(op);
	}
	/* CSM keys on for one refresh only */
	op->keys &= (uint8_t)~(1u << KEY_CSM);
	return op->stage != RELEASE || op->attenuation < QUIET;
}

/* A step of the envelope: 'counter' is the envelope counter in whole steps */
static void clock_envelope(ym2151_operator *op, uint32_t counter)
{
	if (op->stage == ATTACK && op->attenuation == 0)
		op->stage = DECAY;
	/* right after the attack too, so that a sustain level of 0 skips the decay */
	if (op->stage == DECAY && op->attenuation >= op->sustain_level)
		op->stage = SUSTAIN;

	/* the rate decides on which steps the envelope moves (the counter as a 5.11 number has no
	   fraction) and by how much (the bits above the fraction) */
	const uint32_t rate = op->rates[op->stage];
	const uint32_t rate_shift = rate >> 2;

	counter <<= rate_shift;
	if (field(counter, 0, 11) != 0)
		return;

	const uint32_t position = field(counter, rate_shift <= 11 ? 11 : (int)rate_shift, 3);
	const uint32_t increment = field(envelope_steps[rate], 4 * (int)position, 4);

	if (op->stage == ATTACK)
	{
		/* the attack goes a part of the way to 0; rates 62 and 63 do not move at all, unless they
		   were set at the key on */
		if (rate < 62)
			op->attenuation = (uint16_t)(op->attenuation + (((~(uint32_t)op->attenuation) * increment) >> 4));
	}
	else
	{
		op->attenuation = (uint16_t)(op->attenuation + increment);
		if (op->attenuation >= 0x400)
			op->attenuation = 0x3ff;
	}
}

static void clock_operator(const ym2151 *chip, uint32_t channel, uint32_t at, ym2151_operator *op,
	uint32_t envelope_counter, int32_t lfo_pm)
{
	if (field(envelope_counter, 0, 2) == 0)
		clock_envelope(op, envelope_counter >> 2);

	uint32_t step = op->step;

	if (step == STEP_FOLLOWS_LFO)
		step = phase_step(chip, channel, at, op, lfo_pm);
	op->phase += step;
}

/* The envelope as heard: with the LFO's AM and the total level, at most 0x3FF */
static uint32_t envelope_attenuation(const ym2151 *chip, uint32_t at, const ym2151_operator *op, uint32_t am_offset)
{
	uint32_t attenuation = op->attenuation;

	if (chip_register(chip, 0xa0 + at, 7, 1))
		attenuation += am_offset;
	attenuation += op->total_level;
	return attenuation < 0x3ff ? attenuation : 0x3ff;
}

/* An operator's output at a point of its wave: 14 bits, signed */
static int32_t operator_output(const ym2151 *chip, uint32_t at, const ym2151_operator *op, uint32_t point, uint32_t am_offset)
{
	if (op->attenuation > QUIET)
		return 0;

	const uint32_t sine = sine_attenuation(point & 0x3ff);
	const uint32_t envelope = envelope_attenuation(chip, at, op, am_offset) << 2;
	const int32_t volume = (int32_t)attenuation_to_volume((sine & 0x7fff) + envelope);

	return (sine & 0x8000) ? -volume : volume;
}

/* The noise in place of channel 7's last operator: the envelope's volume, its sign from the noise */
static int32_t noise_output(const ym2151 *chip, uint32_t at, const ym2151_operator *op, uint32_t am_offset)
{
	const int32_t volume = (int32_t)((envelope_attenuation(chip, at, op, am_offset) ^ 0x3ff) << 1);

	return (chip->noise_state & 1) ? -volume : volume;
}

/* ---- channels ---- */

/* The operators' register offsets (M1, C1, M2, C2) */
static const uint32_t operator_slots[4] = { 0, 16, 8, 24 };

/* A channel's sample, added to the outputs it is routed to (ymfm's output_4op, no shift, 16-bit clip) */
static void channel_output(const ym2151 *chip, uint32_t number, ym2151_channel *channel, int32_t out[2])
{
	const uint32_t sensitivity = am_sensitivity(chip, number);
	const uint32_t am = sensitivity ? (uint32_t)chip->lfo_am << (sensitivity - 1) : 0;
	ym2151_operator *const *ops = channel->operators;

	/* operator 1 modulates itself with the sum of its last two outputs, scaled by the feedback level */
	const uint32_t feedback = chip_register(chip, 0x20 + number, 3, 3);
	int32_t modulation = 0;

	if (feedback != 0)
		modulation = (channel->feedback[0] + channel->feedback[1]) >> (10 - feedback);

	const int32_t first = operator_output(chip, number + operator_slots[0], ops[0], (ops[0]->phase >> 10) + (uint32_t)modulation, am);

	channel->feedback_next = (int16_t)first;
	if (chip_register(chip, 0x20 + number, 6, 2) == 0)
		return;

	const algorithm *route = &algorithms[chip_register(chip, 0x20 + number, 0, 3)];
	int16_t outputs[8];
	int32_t sum;

	outputs[0] = 0;
	outputs[1] = (int16_t)first;
	outputs[2] = (int16_t)operator_output(chip, number + operator_slots[1], ops[1],
		(ops[1]->phase >> 10) + (uint32_t)(outputs[route->input2] >> 1), am);
	outputs[5] = (int16_t)(outputs[1] + outputs[2]);
	outputs[3] = (int16_t)operator_output(chip, number + operator_slots[2], ops[2],
		(ops[2]->phase >> 10) + (uint32_t)(outputs[route->input3] >> 1), am);
	outputs[6] = (int16_t)(outputs[1] + outputs[3]);
	outputs[7] = (int16_t)(outputs[2] + outputs[3]);

	if (noise_enabled(chip) && number == 7)
		sum = noise_output(chip, number + operator_slots[3], ops[3], am);
	else
		sum = operator_output(chip, number + operator_slots[3], ops[3],
			(ops[3]->phase >> 10) + (uint32_t)(outputs[route->input4] >> 1), am);
	for (int index = 0; index < 3; index++)
		if (route->carriers & (1u << index))
			sum = clamp(sum + outputs[index + 1], -CLIP - 1, CLIP);

	if (chip_register(chip, 0x20 + number, 6, 1))
		out[0] += sum;
	if (chip_register(chip, 0x20 + number, 7, 1))
		out[1] += sum;
}

/* The refresh of a channel: whether any of its operators may still be heard */
static bool refresh_channel(const ym2151 *chip, uint32_t number, ym2151_channel *channel)
{
	bool heard = false;

	for (int index = 0; index < 4; index++)
		if (refresh_operator(chip, number, number + operator_slots[index], channel->operators[index]))
			heard = true;
	return heard;
}

/* ---- the core ---- */

static void make_lfo_waveforms(ym2151 *chip)
{
	for (uint32_t index = 0; index < 256; index++)
	{
		uint8_t am, pm;

		/* a sawtooth */
		am = (uint8_t)(index ^ 0xff);
		pm = (uint8_t)index;
		chip->lfo_waveforms[0][index] = (int16_t)(uint16_t)(am | pm << 8);
		/* a square */
		am = (index & 0x80) ? 0 : 0xff;
		pm = (uint8_t)(am ^ 0x80);
		chip->lfo_waveforms[1][index] = (int16_t)(uint16_t)(am | pm << 8);
		/* a triangle */
		am = (uint8_t)((index & 0x80) ? (index << 1) : ((index ^ 0xff) << 1));
		pm = (uint8_t)((index & 0x40) ? am : (uint8_t)~am);
		chip->lfo_waveforms[2][index] = (int16_t)(uint16_t)(am | pm << 8);
		/* the noise, filled in as it goes */
		chip->lfo_waveforms[3][index] = 0;
	}
}

/* ymfm's clock_noise_and_lfo: the noise steps twice and the LFO once; the AM is kept, the PM given */
static int32_t clock_noise_and_lfo(ym2151 *chip)
{
	const uint32_t frequency = chip_register(chip, REG_NOISE, 0, 5) ^ 0x1f;

	for (int repeat = 0; repeat < 2; repeat++)
	{
		chip->noise_lfsr <<= 1;
		chip->noise_lfsr |= field(chip->noise_lfsr, 17, 1) ^ field(chip->noise_lfsr, 14, 1) ^ 1;
		if (chip->noise_counter++ >= frequency)
		{
			chip->noise_counter = 0;
			chip->noise_state = (uint8_t)field(chip->noise_lfsr, 17, 1);
		}
	}

	const uint32_t rate = chip->registers[REG_LFO_RATE];

	chip->lfo_counter += (0x10 | field(rate, 0, 4)) << field(rate, 4, 4);
	if (chip_register(chip, REG_TEST, 1, 1))
		chip->lfo_counter = 0;

	const uint32_t lfo = field(chip->lfo_counter, 22, 8);
	const uint32_t noise = field(chip->noise_lfsr, 17, 8);

	chip->lfo_waveforms[3][(lfo + 1) & 0xff] = (int16_t)(uint16_t)(noise | noise << 8);

	const int32_t ampm = chip->lfo_waveforms[chip_register(chip, REG_LFO_WAVE, 0, 2)][lfo];

	chip->lfo_am = (uint8_t)(((uint32_t)(ampm & 0xff) * chip_register(chip, REG_LFO_AM_DEPTH, 0, 7)) >> 7);
	return ((ampm >> 8) * (int32_t)pm_depth(chip)) >> 7;
}

static void clock_chip(ym2151 *chip)
{
	chip->total_clocks++;

	/* a change to the registers, or 4097 samples without one, refreshes the channels */
	if (chip->modified_channels != 0 || chip->refresh_count++ >= 4096)
	{
		chip->active_channels = 0;
		for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
			if (refresh_channel(chip, index, &chip->channels[index]))
				chip->active_channels |= 1u << index;
		chip->modified_channels = 0;
		chip->refresh_count = 0;
	}

	/* the envelopes step on one sample in three: the low two bits count 0, 1, 2 */
	if (field(++chip->envelope_counter, 0, 2) == 3)
		chip->envelope_counter++;

	const int32_t lfo_pm = clock_noise_and_lfo(chip);

	for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
	{
		ym2151_channel *channel = &chip->channels[index];

		channel->feedback[0] = channel->feedback[1];
		channel->feedback[1] = channel->feedback_next;
		for (int op = 0; op < 4; op++)
			clock_operator(chip, index, index + operator_slots[op], channel->operators[op], chip->envelope_counter, lfo_pm);
	}
}

/* The mode register: CSM, and the timers' resets, enables and loads. Timer B starts short by the low 4 bits
   of the sample count, since its divide by 16 runs free. */
static void write_mode(ym2151 *chip, uint8_t data)
{
	uint8_t clear = 0;

	chip->modified_channels = ALL_CHANNELS;
	chip->registers[REG_MODE] = data;
	if (field(data, 5, 1))
		clear |= STATUS_TIMER_B;
	if (field(data, 4, 1))
		clear |= STATUS_TIMER_A;
	change_status(chip, 0, clear);
	update_timer(chip, 1, field(data, 1, 1) != 0, -(int32_t)(chip->total_clocks & 15));
	update_timer(chip, 0, field(data, 0, 1) != 0, 0);
}

static void write_register(ym2151 *chip, uint32_t number, uint8_t data)
{
	if (number == REG_MODE)
	{
		write_mode(chip, data);
		return;
	}
	chip->modified_channels = ALL_CHANNELS;
	/* the LFO's AM and PM depths share 0x19: bit 7 says which */
	if (number == REG_LFO_AM_DEPTH)
		chip->registers[number + field(data, 7, 1)] = data;
	else if (number != REG_LFO_PM_DEPTH)
		chip->registers[number] = data;
	if (number == REG_KEY)
		key_channel(&chip->channels[field(data, 0, 3)], field(data, 3, 4), KEY_REGISTER);
}

/* ---- the interface ---- */

void ym2151_init(ym2151 *chip)
{
	void *host = chip->host;
	void (*set_timer)(void *, int, int32_t) = chip->set_timer;
	void (*set_busy_end)(void *, uint32_t) = chip->set_busy_end;
	bool (*is_busy)(void *) = chip->is_busy;
	void (*update_irq)(void *, bool) = chip->update_irq;

	memset(chip, 0, sizeof(*chip));
	chip->host = host;
	chip->set_timer = set_timer;
	chip->set_busy_end = set_busy_end;
	chip->is_busy = is_busy;
	chip->update_irq = update_irq;
	chip->noise_lfsr = 1;
	make_lfo_waveforms(chip);
	for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
		for (int op = 0; op < 4; op++)
			chip->channels[index].operators[op] = &chip->operators[index + operator_slots[op]];
	chip->active_channels = ALL_CHANNELS;
	chip->modified_channels = ALL_CHANNELS;
	ym2151_reset(chip);
}

void ym2151_reset(ym2151 *chip)
{
	change_status(chip, 0, 0xff);
	memset(chip->registers, 0, sizeof(chip->registers));
	/* every channel to both outputs */
	for (uint32_t index = 0x20; index < 0x28; index++)
		chip->registers[index] = 0xc0;
	write_mode(chip, 0);
	for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
	{
		ym2151_channel *channel = &chip->channels[index];

		channel->feedback[0] = channel->feedback[1] = 0;
		channel->feedback_next = 0;
	}
	for (uint32_t index = 0; index < YM2151_OPERATORS; index++)
	{
		ym2151_operator *op = &chip->operators[index];

		op->phase = 0;
		op->attenuation = 0x3ff;
		op->stage = RELEASE;
		op->key = 0;
		op->keys = 0;
	}
}

uint8_t ym2151_read(ym2151 *chip, int offset)
{
	if ((offset & 1) == 0)
		return 0xff;

	uint8_t status = chip->status & (uint8_t)~STATUS_BUSY;

	if (chip->is_busy && chip->is_busy(chip->host))
		status |= STATUS_BUSY;
	return status;
}

void ym2151_write(ym2151 *chip, int offset, uint8_t data)
{
	if ((offset & 1) == 0)
	{
		chip->address = data;
		return;
	}
	write_register(chip, chip->address, data);
	if (chip->set_busy_end)
		chip->set_busy_end(chip->host, BUSY_CLOCKS);
}

void ym2151_timer_expired(ym2151 *chip, int timer)
{
	if (timer != 0 && timer != 1)
		return;
	if (timer == 0 && chip_register(chip, REG_MODE, 2, 1))
		change_status(chip, STATUS_TIMER_A, 0);
	else if (timer == 1 && chip_register(chip, REG_MODE, 3, 1))
		change_status(chip, STATUS_TIMER_B, 0);

	/* CSM: timer A keys every channel on at the next refresh, and off at the one after */
	if (timer == 0 && chip_register(chip, REG_MODE, 7, 1))
	{
		for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
			key_channel(&chip->channels[index], 0xf, KEY_CSM);
		chip->modified_channels = ALL_CHANNELS;
	}

	/* and it starts over */
	chip->timer_running[timer] = 0;
	update_timer(chip, timer, true, 0);
}

/* ymfm's roundtrip_fp: the YM3012's 10.3 floating point keeps 10 bits below the leading sign bits */
static int32_t roundtrip_fp(int32_t value)
{
	uint32_t scan;
	int exponent;

	if (value < -32768)
		return -32768;
	if (value > 32767)
		return 32767;
	scan = (uint32_t)(value ^ (value >> 31)) << 17;
	exponent = 7;
	while (exponent > 0 && !(scan & 0x80000000u))
	{
		scan <<= 1;
		exponent--;
	}
	if (exponent < 1)
		exponent = 1;
	return value & ~((1 << (exponent - 1)) - 1);
}

void ym2151_generate(ym2151 *chip, int32_t out[2])
{
	clock_chip(chip);

	const uint32_t channels = ALL_CHANNELS & chip->active_channels;

	out[0] = out[1] = 0;
	for (uint32_t index = 0; index < YM2151_CHANNELS; index++)
		if (channels & (1u << index))
			channel_output(chip, index, &chip->channels[index], out);
	out[0] = roundtrip_fp(out[0]);
	out[1] = roundtrip_fp(out[1]);
}
