/**
 *    Name:        unsorted/code_005010.c
 *    Description: 
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_005010(void)
{
	uint32_t a0 = 0, a6 = 0, d7 = 0;

	if (unk_060082 == 0u)
	{
		a0 = unk_0623C0_ADDRESS;
		AT16(unk_0623C0, -1) = 0x8100u;
		unk_062402 = 0xFFu;
		a6 = animations_0143D4[unk_060128];
		set_animation(0u, a0, a6);
		d7 = unk_060128;
		a6 = table_loaded_by_lea_005078_ADDRESS + (uint16_t)(d7 << 4);
		unk_0623CC = DATA16(a6);
		a6 += 2u;
		unk_0623CE = DATA16(a6);
		a6 += 2u;
		unk_0623E0 = DATA16(a6);
		a6 += 2u;
		unk_0623E2 = DATA16(a6);
		a6 += 2u;
		unk_0623DA = DATA16(a6);
		unk_0623DC = DATA16(a6 + 2u);
		unk_060007++;
	}
}

void func_0050D8(void)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t a0 = 0;

	if (unk_060152 != 0u)
	{
		d7 = 0x78u;
		func_0091A4(d7, 0u);
	}
	a0 = unk_0623C0_ADDRESS;
	d7_2 = (uint16_t)(unk_0623DA + unk_0623CC);
	if (d7_2 == unk_0623E0)
		unk_0623DA = 0u;
	unk_0623CC = d7_2;
	d7_2 = (uint16_t)(unk_0623DC + unk_0623CE);
	if (d7_2 == unk_0623E2)
		unk_0623DC = 0u;
	unk_0623CE = d7_2;
	if (AT32(unk_0623DA, -2) == 0u)
		unk_060007++;
}

void func_005132(void)
{
	uint8_t d7 = 0;

	func_0185B6();
	if (unk_06342F == 0u)
	{
		unk_060002 = 0x64u;
		unk_060007++;
		d7 = 0xFEu;
		func_0091A4(d7, 0u);
		return;
	}
	if (unk_060152 != 0u)
	{
		d7 = 0x78u;
		func_0091A4(d7, 0u);
	}
}

void func_005170(void)
{
	uint8_t t1 = 0;

	t1 = unk_060002;
	unk_060002 = t1 - 1u;
	if (t1 != 1u)
		return;
	unk_060128++;
	if (unk_060128 >= 6u)
		unk_060128 = 0u;
	unk_060003++;
	unk_060005 = 0u;
	unk_060007 = 0u;
}

void func_0051A8(void)
{
	if (unk_060327 != 0u)
	{
		func_008B1E();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_0051DA();
		return;
	case 1:
		func_0051FC();
		return;
	case 2:
		func_005230();
		return;
	}
}

void func_0051DA(void)
{
	uint16_t d7 = 0;

	func_0044F8();
	func_009A5C();
	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060005++;
}

void func_0051FC(void)
{
	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		unk_060059 &= ~4u;
		func_004072();
		func_008C6A();
		unk_060004 = 1u;
		unk_060005++;
	}
}

void func_005230(void)
{
	uint8_t t1 = 0;

	t1 = unk_060004;
	unk_060004 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_060003 = 0u;
		unk_060005 = 0u;
		unk_060007 = 0u;
		unk_060009 = 0u;
		unk_06000B = 0u;
	}
}

void unreached_005266(void)
{
	uint8_t d6 = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	a6 = table_loaded_by_lea_005294_ADDRESS;
	a5 = SPRITE_RAM;
	d7 = 0x3Fu;
	do
	{
		t1 = a5;
		a5++;
		mem_write8(t1, DATA8(a6));
		t2 = d7 - 1u;
		d7 = t2;
		a6++;
	} while (t2 != 0xFFFFu);
	unk_060062 = 0u;
	unk_060060 = 0x60u;
	d7 = 1u;
	d6 = 1u;
	func_004982(d6, d7);
}

void func_0056C2(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_0056E4();
		return;
	case 1:
		func_0056E8();
		return;
	case 2:
		func_005708();
		return;
	}
}

void func_0056E4(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_0056E8(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 == 0u)
	{
		a6 = 0xA07Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		unk_060007++;
	}
}

void func_005708(void)
{
	if (unk_060083 == 0u)
	{
		unk_060005++;
		unk_060007 = 0u;
	}
}

void func_005720(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_00573E();
		return;
	case 1:
		func_005DA4();
		return;
	}
}

void func_00573E(void)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM;
	d0 = 0u;
	d1 = 0x2Cu;
	d2 = 0x2Du;
	d3 = 0x2Eu;
	d4 = 0x2Fu;
	d6 = 0xFu;
	do
	{
		d7 = 0x1Fu;
		do
		{
			mem_write8(a6 + 0x80u, d0);
			mem_write8(a6 + 0x81u, d1);
			mem_write8(a6 + 0x82u, d0);
			mem_write8(a6 + 0x83u, d2);
			mem_write8(a6, d0);
			a6++;
			mem_write8(a6, d3);
			a6++;
			mem_write8(a6, d0);
			a6++;
			mem_write8(a6, d4);
			t1 = d7 - 1u;
			d7 = t1;
			a6++;
		} while (t1 != 0xFFFFu);
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 0x80u;
	} while (t2 != 0xFFFFu);
	unk_060007++;
}

void func_00577E(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_0057A0();
		return;
	case 1:
		func_0057A4();
		return;
	case 2:
		func_005DA4();
		return;
	}
}

void func_0057A0(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_0057A4(void)
{
	uint8_t d3_2 = 0, d6 = 0;
	uint16_t d3 = 0, d4 = 0, d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	if (unk_060082 != 0u)
		return;
	a5 = table_loaded_by_lea_005846_ADDRESS;
	func_004184(a5);
	d7 = 1u;
	d7 = func_00583A(d7);
	d5 = 7u;
	a5 = rom_00584C;
	a6 = a5;
	do
	{
		d4 = 7u;
		d6 = 0x31u;
		do
		{
			d3 = 3u;
			do
			{
				mem_write8(a6, d7);
				a6++;
				mem_write8(a6, d6);
				t1 = d3 - 1u;
				d3 = t1;
				a6++;
			} while (t1 != 0xFFFFu);
			d6++;
			t2 = d4 - 1u;
			d4 = t2;
		} while (t2 != 0xFFFFu);
		a5 += 0x80u;
		a6 = a5;
		t3 = d5 - 1u;
		d5 = t3;
	} while (t3 != 0xFFFFu);
	a4 = 0x1F1Cu;
	a5 = rom_005850;
	a6 = a5;
	d5 = 3u;
	do
	{
		d4 = 0xFu;
		d6 = 0x30u;
		do
		{
			d3_2 = mem_read8(a4 + (int16_t)d5);
			mem_write8(a6, d3_2);
			mem_write8(a6 + 2u, d3_2);
			mem_write8(a6 + 0x80u, d3_2);
			mem_write8(a6 + 0x82u, d3_2);
			mem_write8(a6 + 1u, d6);
			mem_write8(a6 + 3u, d6);
			mem_write8(a6 + 0x81u, d6);
			mem_write8(a6 + 0x83u, d6);
			d6++;
			t4 = d4 - 1u;
			d4 = t4;
			a6 += 4u;
		} while (t4 != 0xFFFFu);
		a5 += 0x180u;
		a6 = a5;
		t5 = d5 - 1u;
		d5 = t5;
	} while (t5 != 0xFFFFu);
	unk_060007++;
}

uint32_t func_00583A(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

void func_005854(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_005876();
		return;
	case 1:
		func_00587A();
		return;
	case 2:
		func_0058A4();
		return;
	}
}

void func_005876(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_00587A(void)
{
	uint32_t a5 = 0;

	if (unk_060082 != 0u)
		return;
	a5 = table_loaded_by_lea_005896_ADDRESS;
	func_004184(a5);
	unk_060007++;
}

void func_0058A4(void)
{
	func_0058B4();
	func_005902();
	func_00594E();
	func_005DA4();
}

void func_0058B4(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	d7 = 0u;
	do
	{
		d6 = (uint16_t)((uint32_t)d7 << 2);
		d5 = (uint8_t)~mem_read8(indexed_table_of_32_bit_values_0059A6[d6 / 4u]);
		a6 = rom_0059B6[d6 / 4u];
		d6 = 7u;
		do
		{
			if ((uint8_t)d6 != 1u)
			{
				if ((uint8_t)d6 != 0u)
					d5 = func_005990(d5, a6);
			}
			else
				d5 = (uint8_t)d5 >> 1;
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 0x100u;
		} while (t1 != 0xFFFFu);
		d7 = (uint8_t)(d7 + 1u);
	} while (d7 < 4u);
}

void func_005902(void)
{
	uint16_t d6 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0, t2 = 0;

	d5 = (uint8_t)~mem_read8(rom_0059C6);
	a6 = rom_0059CA;
	d6 = 3u;
	do
	{
		d5 = func_005990(d5, a6);
		t1 = d6 - 1u;
		d6 = t1;
		a6 += 0x100u;
	} while (t1 != 0xFFFFu);
	d5 = (uint8_t)~mem_read8(rom_0059C6) >> 4;
	a6 = rom_0059CE;
	d6 = 3u;
	do
	{
		d5 = func_005990(d5, a6);
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 0x100u;
	} while (t2 != 0xFFFFu);
}

void func_00594E(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	d7 = 0u;
	do
	{
		d6 = (uint16_t)((uint32_t)d7 << 2);
		d5 = (uint8_t)~mem_read8(rom_0059D2[d6 / 4u]);
		a6 = rom_0059DE[d6 / 4u];
		d6 = 7u;
		if (d7 == 2u)
			d6 = 3u;
		do
		{
			d5 = func_005990(d5, a6);
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 4u;
		} while (t1 != 0xFFFFu);
		d7 = (uint8_t)(d7 + 1u);
	} while (d7 < 3u);
}

uint32_t func_005990(uint32_t d5, uint32_t a6)
{
	uint32_t carry = 0;
	uint8_t d4 = 0;

	d4 = 0u;
	carry = d5 & 1u;
	d5 = (d5 & ~0xFFu) | ((uint8_t)d5 >> 1);
	if (carry)
		d4 = 1u;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d4);
	return d5;
}

void func_0059EA(void)
{
	unk_060005++;
	unk_060007 = 0u;
}

void unreached_0059F8(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_005A1E();
		break;
	case 1:
		func_005A22();
		break;
	case 2:
		func_005A5E();
		break;
	}
	func_005DA4();
}

void func_005A1E(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_005A22(void)
{
	uint32_t a5 = 0;

	if (unk_060082 == 0u)
	{
		a5 = table_loaded_by_lea_005A58_ADDRESS;
		func_004184(a5);
		unk_060007++;
		unk_0635F8 &= 0xFFu;
		unk_0635FA(0) = 0xFFu;
		unk_0635FB = 0u;
		unk_0635FC = 0u;
	}
}

void func_005A5E(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = (uint8_t)(unk_0635F8 >> 8u);
	unk_0635F8 = (unk_0635F8 & 0xFFu) | ((t1 - 1u & 0xFFu) << 8u);
	if (t1 != 0u)
	{
		if ((uint8_t)(unk_0635F8 >> 8u) == 0x1Eu)
			unk_060058 &= ~3u;
		return;
	}
	unk_0635FA(0)++;
	if (unk_0635FA(0) < 4u)
	{
		a6 = unexplained_005B40;
		d7 = (uint8_t)(unk_0635FB + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		a6 = rom_005B44;
		d7 = (uint8_t)(unk_0635FA(0) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		d7 = (uint8_t)((unk_060058 & ~3u) | shl32(1u, (int)(unk_0635FB & 0x1Fu)));
		io_write8(IO_0A0001, d7);
		unk_060058 = d7;
		unk_0635F8 = (unk_0635F8 & 0xFFu) | 0x2000u;
		return;
	}
	unk_0635FA(0) = 0u;
	unk_0635FB++;
	if (unk_0635FB < 2u)
	{
		a6 = unexplained_005B40;
		d7 = (uint8_t)(unk_0635FB + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		a6 = rom_005B44;
		d7 = (uint8_t)(unk_0635FA(0) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		d7 = (uint8_t)((unk_060058 & ~3u) | shl32(1u, (int)(unk_0635FB & 0x1Fu)));
		io_write8(IO_0A0001, d7);
		unk_060058 = d7;
		unk_0635F8 = (unk_0635F8 & 0xFFu) | 0x2000u;
		return;
	}
	unk_0635FB = 0u;
	unk_0635FC++;
	if (unk_0635FC >= 2u)
	{
		unk_0635FC = 0u;
		unk_060005++;
		unk_060007 = 0u;
		return;
	}
	unk_06005B ^= 7u;
	a6 = unexplained_005B40;
	d7 = (uint8_t)(unk_0635FB + 1u);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d7);
	a6 = rom_005B44;
	d7 = (uint8_t)(unk_0635FA(0) + 1u);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d7);
	d7 = (uint8_t)((unk_060058 & ~3u) | shl32(1u, (int)(unk_0635FB & 0x1Fu)));
	io_write8(IO_0A0001, d7);
	unk_060058 = d7;
	unk_0635F8 = (unk_0635F8 & 0xFFu) | 0x2000u;
}

void func_005B48(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_005B6A();
		return;
	case 1:
		func_005B6E();
		return;
	case 2:
		func_005BA2();
		return;
	}
}

void func_005B6A(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_005B6E(void)
{
	uint32_t a5 = 0;

	if (unk_060082 == 0u)
	{
		a5 = table_loaded_by_lea_005B9C_ADDRESS;
		func_004184(a5);
		unk_0635F8 = 0u;
		unk_0635FA(0) = 0u;
		unk_0635FB = 0u;
		unk_060007++;
	}
}

void func_005BA2(void)
{
	uint8_t d7 = 0;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_0635F8;
	unk_0635F8 = t1 - 1u;
	if (t1 != 0u && (unk_060050 & 0x20u) == 0u)
	{
		func_005DA4();
		return;
	}
	d7 = 0u;
	func_005DFE(d7);
	d7_2 = unk_0635FA(0);
	t2 = indexed_table_of_8_bit_values_006146[d7_2];
	d7_2 = t2;
	if (t2 == 0u)
	{
		unk_060005++;
		unk_060007 = 0u;
		return;
	}
	func_005DFE((uint8_t)d7_2);
	a6 = TILE_RAM + 0x8CAu;
	d6 = 1u;
	d7_2 = unk_0635FB;
	func_01848C(d6, d7_2, a6);
	unk_0635FA(0)++;
	unk_0635FB++;
	unk_0635F8 = 0x12Cu;
	func_005DA4();
}

void unreached_005C0C(void)
{
}

void func_005C1C(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_005C3E();
		return;
	case 1:
		func_005C42();
		return;
	case 2:
		func_005C64();
		return;
	}
}

void func_005C3E(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_005C42(void)
{
	uint32_t a5 = 0;

	if (unk_060082 == 0u)
	{
		a5 = table_loaded_by_lea_005C5E_ADDRESS;
		func_004184(a5);
		unk_060007++;
	}
}

void func_005C64(void)
{
	func_005C80();
	func_005CFE();
	func_005D16();
	func_005D40();
	func_005D54();
	func_005D68();
	func_005DA4();
}

void func_005C80(void)
{
	uint8_t d0 = 0, d1 = 0, d4 = 0, d5 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0;

	d6 = io_read8(IO_0A0011);
	d6 = (uint8_t)~d6;
	d6 = d6 & 0xFu;
	d6 = (uint8_t)((uint32_t)d6 << 1);
	d0 = rom_001452[d6];
	d1 = rom_001453[d6];
	a6 = TILES_10032E;
	io_write8(TILES_10032E, 0u);
	io_write8(TILES_10032F, d0);
	io_write8(TILES_100340, 0u);
	io_write8(TILES_100341, d1);
	d4 = 0x10u;
	d5 = 0x10u;
	if (d0 != 1u)
		d4 = 0x23u;
	if (d1 != 1u)
		d5 = 0x23u;
	mem_write8(a6 + 0xCu, 0u);
	mem_write8(a6 + 0xDu, d4);
	mem_write8(a6 + 0x1Eu, 0u);
	mem_write8(a6 + 0x1Fu, d5);
	d7 = 0x1007u;
	func_004164(d7);
}

void unreached_005CF6(void)
{
	uint16_t d7 = 0;

	d7 = 0x1013u;
	func_004164(d7);
}

void func_005CFE(void)
{
	uint16_t d7 = 0;

	d7 = io_read8(IO_0A0013);
	d7 = (uint8_t)~d7;
	d7 = d7 & 0x60u;
	d7 = d7 >> 5;
	d7 = (uint8_t)(d7 + 9u);
	d7 += 0x1000u;
	func_004164(d7);
}

void func_005D16(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;

	d7 = io_read8(IO_0A0013);
	d7 = (uint8_t)~d7;
	d7_2 = rom_001426[d7 & 3u];
	io_write8(TILES_100838, 0u);
	io_write8(TILES_100839, d7_2);
}

void func_005D40(void)
{
	uint16_t d7 = 0;

	d7 = 0xDu;
	if ((io_read8(IO_0A0013) & 0x80u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	func_004164(d7);
}

void func_005D54(void)
{
	uint16_t d7 = 0;

	d7 = 0xFu;
	if ((io_read8(IO_0A0019) & 1u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	func_004164(d7);
}

void func_005D68(void)
{
	uint16_t d7 = 0;

	d7 = 0x11u;
	if ((io_read8(IO_0A0019) & 4u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	func_004164(d7);
}

void func_005D80(void)
{
	unk_060005 = 0u;
	unk_060007 = 0u;
}

void func_005DA4(void)
{
	uint8_t d7 = 0;

	if ((unk_060050 & 0x10u) != 0u)
	{
		unk_060005++;
		unk_060007 = 0u;
		func_005DF4();
	}
	d7 = unk_06005B;
	if (unk_060005 != 5u)
	{
		d7 &= 2u;
		if ((io_read8(IO_0A0019) & 1u) == 0u)
			d7 ^= 7u;
	}
	unk_06005B = d7;
	io_write8(TILES_106D00, d7);
}

void func_005DF4(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	func_005DFE(d7);
}

void func_005DFE(uint8_t d7)
{
	uint32_t a6 = 0;

	a6 = unk_060018;
	mem_write8(a6, d7);
	a6++;
	if (a6 > 0x6043Fu)
		a6 = 0x60400u;
	unk_060018 = a6;
}

void func_0061CE(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_0061F0();
		break;
	case 1:
		func_006254();
		break;
	}
	func_004206(&ignored, &ignored_2);
}

void func_0061F0(void)
{
	uint8_t d7 = 0;

	if (unk_060082 == 0u)
	{
		func_0044F8();
		func_004284();
		func_004294();
		func_0042A4();
		func_0042B4();
		d7 = 0xFu;
		func_002098(d7);
		unk_06005C = 0u;
		unk_060060 = 0u;
		unk_06005E = 0u;
		unk_060062 = 0u;
		unk_060094 = (unk_060031 & 0x60u) >> 5;
		unk_06111E = 0u;
		unk_0600B8 = 0u;
		unk_060007++;
	}
}

void func_006254(void)
{
	unk_060120 = 0u;
	unk_060005++;
	unk_060007 = 0u;
}

void func_006268(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_006296();
		break;
	case 1:
		func_0062A8();
		break;
	case 2:
		func_0062BA();
		break;
	}
	func_004206(&ignored, &ignored_2);
}

void func_006296(void)
{
	unk_0600C4 = 0u;
	unk_060007++;
}

void func_0062A8(void)
{
	unk_0600C4 = 0x10203u;
	unk_060007++;
}

void func_0062BA(void)
{
	unk_060005++;
	unk_060007 = 0u;
}

void func_0062C8(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_0062EE();
		break;
	case 1:
		func_006360();
		break;
	case 2:
		func_006378();
		break;
	}
	func_004206(&ignored, &ignored_2);
}

void func_0062EE(void)
{
	uint16_t d1 = 0, d7 = 0;

	d1 = (uint16_t)((uint32_t)unk_060120 << 1);
	unk_060122 = indexed_table_of_8_bit_values_00634C[d1];
	unk_060121 = rom_00634D[d1];
	unk_060123 = 0u;
	unk_060124 = 0u;
	unk_060129 = 0u;
	func_0044F8();
	unk_0600BD = 0u;
	unk_0633C8 = 0u;
	unk_0600B8 = 0u;
	unk_060007++;
	unk_060082++;
	d7 = 7u;
	func_004164(d7);
}

void func_006360(void)
{
	if (unk_060082 == 0u)
	{
		func_004604();
		unk_060007++;
	}
}

void func_006378(void)
{
	unk_060005++;
	unk_060007 = 0u;
}

void func_006386(uint32_t d1)
{
	uint32_t ignored = 0, ignored_2 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_0063AC();
		break;
	case 1:
		func_0064B0(d1);
		break;
	case 2:
		func_006658();
		break;
	}
	func_004206(&ignored, &ignored_2);
}

void func_0063AC(void)
{
	if (unk_060120 != 0u || unk_0600A3 == 0u)
	{
		func_006484();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_0063E0();
		return;
	case 1:
		func_006416();
		return;
	}
}

void func_0063E0(void)
{
	unk_060009++;
	unk_0600C2 = 0xB4u;
	io_write8(PRIORITY_0C0001, 0u);
	unk_060059 = 0u;
	func_004604();
	func_004612();
	func_0308D6();
	func_046EEA();
}

void func_006416(void)
{
	uint8_t d7 = 0;
	uint32_t ignored = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	if (unk_061108 != 0u)
	{
		func_006484();
		return;
	}
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
		unk_0600C2 = 0u;
	if (unk_060083 != 0u || unk_0600C2 != 0u || ((unk_060050 | unk_060051 | unk_060052 | unk_060053) & 0x30u) == 0u)
	{
		func_030960();
		func_046F08(&ignored, &ignored_3);
		draw_sprites(&ignored_4, &ignored_3);
		return;
	}
	d7 = 0x7Eu;
	func_0091A4(d7, 0u);
	func_006484();
}

void func_006484(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	func_009A3A();
	func_004604();
	func_004612();
	func_031230(&ignored, &ignored_2);
	unk_060007++;
	unk_060009 = 0u;
	unk_06000B = 0u;
}

void func_0064B0(uint32_t d1)
{
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_0064D6();
		return;
	case 1:
		func_0064FC();
		return;
	case 2:
		func_006524();
		return;
	case 3:
		func_006574(d1);
		return;
	}
}

void func_0064D6(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060009++;
	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	a6 = area_palettes_ADDRESS;
	d7 = 0x10Fu;
	post_palette_request(d7, a6);
}

void func_0064FC(void)
{
	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		func_004604();
		func_008C6A();
		unk_060009++;
	}
}

void func_006524(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	unk_060009++;
	d7 = 0x200u;
	func_004164(d7);
	if (unk_0600A3 == 0u || (int8_t)unk_060122 < 0)
	{
		unk_060007++;
		unk_060009 = 0u;
		return;
	}
	a6 = rom_019866[unk_060121];
	ignored = func_018334(a6);
	unk_0600C2 = 0xB4u;
	d7_2 = 0xB7Fu;
	func_002336(d7_2, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
}

void func_006574(uint32_t d1)
{
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d7 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	func_0065FC();
	d7 = unk_0600A1;
	d7 = (uint16_t)(d7 + 0xB20u);
	func_002336(d7, &d1, &ignored, &ignored_2, &ignored_3);
	func_00434C(d1, &ignored_2, &d7, &ignored_4);
	func_018340();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 != 1u && (unk_0600C2 >= 0x8Cu || ((unk_060050 | unk_060051 | unk_060052 | unk_060053) & 0x30u) == 0u))
		return;
	d7_2 = 3u;
	a6 = unk_060118_ADDRESS;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d7_2 & 7u))) != 0u)
			mem_write8(a6 + 6u, 0xAu);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a6 -= 8u;
	} while (t2 != 0xFFFFu);
	unk_060007++;
	unk_060009 = 0u;
}

void func_0065FC(void)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	if (unk_0600C2 >= 0xAAu || (unk_0600A4 & 7u) != 0u)
		return;
	d6 = 0u;
	d7 = 3u;
	a6 = unk_060118_ADDRESS;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d7 & 7u))) != 0u && mem_read8(a6 + 6u) < 0xAu)
		{
			mem_write8(a6 + 6u, mem_read8(a6 + 6u) + 1u);
			d6 = 1u;
		}
		t1 = d7 - 1u;
		d7 = t1;
		a6 -= 8u;
	} while (t1 != 0xFFFFu);
	if (d6 != 0u)
	{
		d7_2 = 1u;
		func_0091A4(d7_2, a6);
	}
}

void func_006658(void)
{
	unk_060005++;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
}

void func_006672(uint32_t d1, uint16_t d5, uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | unk_060007;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		func_006690(d1, d5, d7_2);
		return;
	case 4:
		func_0068D6(d1, d5, d7_2);
		return;
	}
}

void func_006690(uint32_t d1, uint16_t d5, uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | unk_060009;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		func_0066BA();
		return;
	case 4:
		func_0066E6();
		return;
	case 8:
		func_006796();
		return;
	case 12:
		func_0067BC(d1, d5, (uint16_t)d7_2);
		return;
	case 16:
		func_006874(d1, d7_2);
		return;
	}
}

void func_0066BA(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	a6 = area_palettes_ADDRESS;
	d7 = 0x10Fu;
	post_palette_request(d7, a6);
	func_009AFE();
	unk_060009++;
}

void func_0066E6(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		func_008C6A();
		func_004604();
		d7 = 0xB7Fu;
		func_004164(d7);
		d7 = unk_060121;
		unk_060059 = area_layer_priorities[d7];
		io_write8(PRIORITY_0C0001, unk_060059);
		unk_060127 = area_settings_060127[d7];
		d7 = (uint16_t)((uint32_t)d7 << 1);
		io_write8(TILES_106B00, area_tile_banks[d7]);
		unk_060064 = area_tile_banks[d7];
		io_write8(TILES_106E00, rom_00676F[d7]);
		unk_060065 = rom_00676F[d7];
		unk_060009++;
	}
}

void func_006796(void)
{
	uint16_t d7 = 0;

	if (unk_060082 != 0u)
		return;
	if (unk_0600A3 == 0u)
	{
		d7 = 1u;
		func_0022AA(d7);
	}
	unk_060009++;
}

void func_0067BC(uint32_t d1, uint32_t d5, uint16_t d7)
{
	uint8_t d4 = 0;
	uint16_t d7_2 = 0;
	uint32_t a0 = 0, a1 = 0, d7_3 = 0;
	uint16_t t1 = 0;

	if (unk_060082 != 0u)
		return;
	if (unk_0600A3 == 0u)
	{
		a0 = unk_060118_ADDRESS;
		d7_2 = (uint16_t)((d7 & ~0xFFu) | 3u);
		do
		{
			if ((unk_0600A1 & shl32(1u, (int)(d7_2 & 7u))) != 0u)
				mem_write16(a0, 1u);
			t1 = d7_2 - 1u;
			d7_2 = t1;
			a0 -= 8u;
		} while (t1 != 0xFFFFu);
	}
	if (unk_0600A3 == 0u)
	{
		unk_0600A4 = 0u;
		unk_060130 = 0u;
	}
	unk_061109 = 0u;
	d7_3 = unk_0600A1;
	d7_3 = d7_3 & ~unk_0600A6;
	func_019BEA((uint8_t)d7_3, &d1, &a1);
	func_00434C(d1, &d5, &d7_3, &a1);
	unk_060127 = 0u;
	d4 = 0xFu;
	func_001FB8(d4);
	start_area_spawns();
	func_04776E();
	func_046EEA();
	func_0477EA(&d5, &d7_3, &a1);
	func_0477EA(&d5, &d7_3, &a1);
	unk_060080 = 0u;
	func_006A9C(d7_3);
	unk_060009++;
	unk_0600B8 = 1u;
}

void func_006874(uint32_t d1, uint32_t d7)
{
	uint16_t d7_2 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	func_00434C(d1, &ignored, &d7, &ignored_2);
	func_0049AA();
	if (unk_061109 == 0u)
	{
		func_019F34();
		func_047204();
		func_046F08(&ignored_3, &ignored_4);
		draw_sprites(&ignored_5, &ignored_4);
		return;
	}
	d7_2 = 0xB7Fu;
	func_004164(d7_2);
	if (unk_0600A3 == 0u)
	{
		unk_0600A4 = 0u;
		unk_06120E = 0u;
	}
	unk_060007++;
	unk_060009 = 0u;
	unk_0600B8 = 0u;
}

void func_0068D6(uint32_t d1, uint16_t d5, uint32_t d7)
{
	uint32_t ignored = 0, ignored_2 = 0;

	d7 = func_00467C(d7);
	func_0068E2(d1, d5, d7);
	func_004206(&ignored, &ignored_2);
}

void func_0068E2(uint32_t d1, uint32_t d5, uint32_t d7)
{
	uint8_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	if (unk_0600A3 == 0u)
	{
		d7 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
		d6 = (uint8_t)d7;
		if ((d7 & 0xFu) == 0u)
		{
			d7 = (d7 & ~0xFFFFu) | 1u;
			if ((d6 & 0x30u) == 0u)
				d7 = d7 | 0x80u;
			func_0022AA((uint16_t)d7);
		}
	}
	func_00434C(d1, &d5, &d7, &ignored);
	func_0049AA();
	d7 = func_006A46(d7);
	func_02F5F0(d6, &d1_2, &d5, &d7);
	func_01A328(d1_2, &d5, &d7, &a1);
	func_01EBCE(&d5, &d7, &a1);
	func_0477EA(&d5, &d7, &a1);
	func_047204();
	func_046F08(&ignored_2, &a0);
	draw_sprites(&ignored_3, &a0);
	func_013A1A(a0);
	if (unk_060121 < 2u)
		func_0069CE();
	if ((unk_0600B3 | unk_0600A6 | unk_0600A1) == 0u)
	{
		unk_060005 = 7u;
		unk_060007 = 0u;
		unk_060009 = 0u;
		unk_06000B = 0u;
		return;
	}
	if (unk_0600BD == 0u || ((unk_0600A0 | unk_0600B3) & 0xFu) != 0u)
		return;
	unk_060005 = 5u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
}

void func_0069CE(void)
{
	uint8_t d7 = 0;

	if (unk_0633FE == 0u || unk_0633FE == 0xFFu)
	{
		d7 = indexed_table_of_8_bit_values_006A18[(uint8_t)unk_0600A4 & 7u];
		unk_060059 = d7;
		io_write8(PRIORITY_0C0001, d7);
		return;
	}
	io_write8(PRIORITY_0C0001, 4u);
	unk_060059 = 4u;
}

uint32_t func_006A46(uint32_t d7)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	unk_060130 = 2u;
	if (unk_0600A3 == 0u)
		return d7;
	unk_060130 = unk_060094;
	d7_2 = (d7 & ~0xFFFFu) | 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d7_2 & 7u))) != 0u)
			unk_060130++;
		t1 = d7_2 - 1u;
		d7_2 = (d7_2 & ~0xFFFFu) | t1;
	} while (t1 != 0xFFFFu);
	d7 = (d7_2 & ~0xFFu) | unk_06111E;
	unk_060130 += d7;
	if (unk_060130 >= 7u)
		unk_060130 = 7u;
	return d7;
}

uint32_t func_006A9C(uint32_t d7)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	if (unk_0600A3 == 0u)
		return d7;
	if (unk_063488 != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | 0x34u;
		func_0091A4((uint8_t)d7_2, 0u);
		if (unk_060121 == 6u && unk_06130A != 0u)
		{
			d7_2 = (d7_2 & ~0xFFFFu) | 0xAu;
			func_0091A4((uint8_t)d7_2, 0u);
		}
		return d7_2;
	}
	t1 = unk_060080;
	d7_2 = t1;
	if (t1 == 0u)
	{
		d7_2 = unk_060121;
		d7_2 = (uint16_t)(int8_t)d7_2;
		d7_2 = (d7_2 & ~0xFFu) | TABLE8(indexed_table_of_8_bit_values_006B0C, (uint32_t)(int16_t)d7_2);
		unk_060080 = d7_2;
	}
	func_0091A4((uint8_t)d7_2, 0u);
	if (unk_060121 == 6u && unk_06130A != 0u)
	{
		d7_2 = (d7_2 & ~0xFFFFu) | 0xAu;
		func_0091A4((uint8_t)d7_2, 0u);
	}
	return d7_2;
}

void func_006B16(uint32_t d1, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	d7_2 = (d7 & ~0xFFu) | unk_060007;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		func_006B4E(&d1, &d7_2);
		break;
	case 4:
		func_006B80(d4, d5, d6, a0, &d1, &d7_2);
		break;
	case 8:
		func_006BA4();
		break;
	}
	func_0049AA();
	if (unk_060129 != 0u)
		return;
	func_00434C(d1, &ignored, &d7_2, &ignored_2);
}

void func_006B4E(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;

	unk_060007++;
	if (unk_060121 != 0u)
	{
		d7 = (d7 & ~0xFFFFu) | 0xFEu;
		func_0091A4((uint8_t)d7, 0u);
	}
	func_02B25C(p_d1, &d7);
	unk_0600B8 = 1u;
	unk_060081 = 0x78u;
	*p_d7 = d7;
}

void func_006B80(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t ignored = 0;

	*p_d1 = func_02B5F4(*p_d1, d4, d5, d6, *p_d7, a0);
	func_046F08(p_d7, &ignored);
	draw_sprites(p_d1, &ignored);
	if (unk_060121 < 2u)
		func_0069CE();
}

void func_006BA4(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	func_0091A4(d7, 0u);
	if (unk_060121 == 9u)
	{
		unk_060005++;
		unk_060007 = 0u;
		return;
	}
	unk_060120++;
	unk_0600BD = 0u;
	unk_060005 = 2u;
	unk_060007 = 0u;
}

void func_006BE4(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_006C02();
		return;
	case 1:
		func_006CBC(d6, a5);
		return;
	}
}

void func_006C02(void)
{
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_006C24();
		return;
	case 1:
		func_006C60();
		return;
	case 2:
		func_006C96();
		return;
	}
}

void func_006C24(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_0600B8 = 0u;
	func_007174();
	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	a6 = 0xA03Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	func_009A3A();
	func_004604();
	func_004612();
	unk_060009++;
}

void func_006C60(void)
{
	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		func_01864E();
		func_02FF44();
		func_046EEA();
		unk_060009++;
		unk_060060 = 0x20u;
	}
}

void func_006C96(void)
{
	func_018682();
	if (unk_063497 == 0u)
	{
		unk_0600C2 = 0x28u;
		unk_060007++;
		unk_060009 = 0u;
	}
}

void func_006CBC(uint16_t d6, uint32_t a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_006D06();
		break;
	case 1:
		func_006D30(d6, a5);
		break;
	case 2:
		func_006D5C(d6, a5);
		break;
	case 3:
		func_006E00();
		break;
	case 4:
		func_006E1E(d6, a5);
		break;
	case 5:
		func_006E58();
		break;
	case 6:
		func_006E78();
		break;
	case 7:
		func_006E9E(d6, a5);
		break;
	case 8:
		func_006ED0();
		break;
	case 9:
		func_0070A8();
		break;
	}
	func_046F08(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

void func_006D06(void)
{
	uint8_t d7 = 0;
	uint8_t t1 = 0;

	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
	{
		d7 = 0x22u;
		func_0091A4(d7, 0u);
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
		unk_0600C2 = 0x78u;
		unk_060009++;
	}
}

void func_006D30(uint16_t d6, uint32_t a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
	{
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
		unk_0600C2 = 0x96u;
		unk_060009++;
		return;
	}
	a6 = record_0071DC_ADDRESS;
	if ((uint8_t)(unk_063410 >> 8u) == 0u)
	{
		d6 = DATA16(a6);
		a5 = mem_read32(a6 + 2u);
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
	}
	copy_palette_sets(d6, a5);
}

void func_006D5C(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d7_3 = 0;
	uint8_t t1 = 0;

	func_007302();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
	{
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
		unk_060009++;
		return;
	}
	if (unk_0600C2 >= 0x32u)
	{
		if (unk_0600C2 == 0x32u)
		{
			d7 = 0x1Au;
			func_0091A4(d7, 0u);
			a6 = unk_0623C0_ADDRESS;
			d7_3 = 0xCu;
			func_01830C(&d7_3, &a6);
			if ((uint8_t)d7_3 != 0u)
				a5 = func_007286(a6);
			a6 = 0x71E2u;
			if (unk_0600C2 < 0x78u)
				a6 = 0x71E8u;
			if ((uint8_t)(unk_063410 >> 8u) == 0u)
			{
				d6 = DATA16(a6);
				a5 = mem_read32(a6 + 2u);
				unk_063412 = 0u;
				unk_063413 = 0u;
				unk_063410 = 0u;
			}
			copy_palette_sets(d6, a5);
			return;
		}
		func_0071FA();
		if ((unk_0600C2 & 7u) == 0u)
		{
			d7_2 = (uint8_t)unk_0600A4;
			d7_2 = d7_2 & 0x18u;
			d7 = indexed_table_of_8_bit_values_006DFC[d7_2 >> 3];
			func_0091A4(d7, 0u);
			a6 = unk_0623C0_ADDRESS;
			d7_3 = 0xCu;
			func_01830C(&d7_3, &a6);
			if ((uint8_t)d7_3 != 0u)
				a5 = func_007286(a6);
		}
	}
	a6 = 0x71E2u;
	if (unk_0600C2 < 0x78u)
		a6 = 0x71E8u;
	if ((uint8_t)(unk_063410 >> 8u) == 0u)
	{
		d6 = DATA16(a6);
		a5 = mem_read32(a6 + 2u);
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
	}
	copy_palette_sets(d6, a5);
}

void func_006E00(void)
{
	func_007216();
	func_00722E();
	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063410 = 0u;
	unk_0600C2 = 0xB4u;
	unk_060009++;
}

void func_006E1E(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_007302();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 != 0u)
	{
		a6 = 0x71EEu;
		if ((uint8_t)(unk_063410 >> 8u) == 0u)
		{
			d6 = DATA16(a6);
			a5 = mem_read32(a6 + 2u);
			unk_063412 = 0u;
			unk_063413 = 0u;
			unk_063410 = 0u;
		}
		copy_palette_sets(d6, a5);
		return;
	}
	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063410 = 0u;
	unk_0600C2 = 0x1Eu;
	d7 = 0x6Cu;
	func_0091A4(d7, 0u);
	unk_060009++;
}

void func_006E58(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = unk_0600C2;
	carry = t1 == 0u;
	extend = carry;
	unk_0600C2 = t1 - 1u;
	if (t1 == 1u)
	{
		a6 = 0x199A4u;
		d7 = 2u;
		func_018588(d7, a6, extend);
		unk_060009++;
	}
}

void func_006E78(void)
{
	func_0185B6();
	if (unk_06342F == 0u)
	{
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
		unk_0600C2 = 0xB4u;
		unk_060009++;
	}
}

void func_006E9E(uint16_t d6, uint32_t a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 != 0u)
	{
		a6 = 0x71F4u;
		if ((uint8_t)(unk_063410 >> 8u) == 0u)
		{
			d6 = DATA16(a6);
			a5 = mem_read32(a6 + 2u);
			unk_063412 = 0u;
			unk_063413 = 0u;
			unk_063410 = 0u;
		}
		copy_palette_sets(d6, a5);
		return;
	}
	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063410 = 0u;
	unk_0600C2 = 0xB4u;
	unk_060009++;
	unk_06000B = 0u;
}

void func_006ED0(void)
{
	switch ((uint32_t)(int8_t)unk_06000B)
	{
	case 0:
		func_006F02();
		return;
	case 1:
		func_006F28();
		return;
	case 2:
		func_006F8C();
		return;
	case 3:
		func_00701E();
		return;
	case 4:
		func_007044();
		return;
	case 5:
		func_007062();
		return;
	case 6:
		func_007086();
		return;
	}
}

void func_006F02(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	a6 = 0xA0DEu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	unk_06000B++;
}

void func_006F28(void)
{
	uint8_t d7 = 0;

	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		io_write8(TILES_106B00, 0xF0u);
		unk_060064 = 0xF0u;
		io_write8(TILES_106E00, 7u);
		unk_060065 = 7u;
		unk_060060 = 0x48u;
		func_007404();
		func_00732E();
		unk_06000B++;
		unk_06342E = 0u;
		unk_0600C2 = 0xB4u;
		d7 = 0x70u;
		func_0091A4(d7, 0u);
	}
}

void func_006F8C(void)
{
	uint8_t d7_3 = 0;
	uint16_t d7_2 = 0;
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	func_00739C();
	if (unk_06342E >= 0xEu)
	{
		a5 = TILE_RAM + 0x324u;
		a6 = table_loaded_by_lea_002F26_ADDRESS;
		d7_2 = 0xFu;
		do
		{
			mem_write8(a5, 0u);
			a5++;
			mem_write8(a5, DATA8(a6) - 0x30u);
			t1 = d7_2 - 1u;
			d7_2 = t1;
			a5++;
			a6++;
		} while (t1 != 0xFFFFu);
		a5 = table_loaded_by_lea_007018_ADDRESS;
		func_004184(a5);
		unk_0600C2 = 0xB4u;
		unk_06000B = 6u;
		d7_3 = 0xFEu;
		func_0091A4(d7_3, a6);
		return;
	}
	a5 = TILE_RAM + 0x324u;
	d7 = unk_06342E;
	a6 = 0x7612u + (uint16_t)(d7 << 4);
	d7_2 = 0xFu;
	do
	{
		mem_write8(a5, 0u);
		a5++;
		mem_write8(a5, DATA8(a6) - 0x30u);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a5++;
		a6++;
	} while (t2 != 0xFFFFu);
	func_007430();
	unk_06000B++;
}

void func_00701E(void)
{
	func_00739C();
	func_0073C8();
	func_0074B8();
	if (unk_06342F == 0u)
	{
		unk_0600C2 = 0x14u;
		unk_06000B++;
	}
}

void func_007044(void)
{
	uint8_t t1 = 0;

	func_00739C();
	func_0073C8();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
	{
		unk_06000B++;
		func_00745A();
	}
}

void func_007062(void)
{
	func_00739C();
	func_0073C8();
	func_0074D4();
	if (unk_06342F == 0u)
	{
		unk_06342E++;
		unk_06000B -= 3u;
	}
}

void func_007086(void)
{
	uint8_t t1 = 0;

	func_00739C();
	func_0073C8();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 0u)
	{
		unk_060009++;
		unk_06000B = 0u;
		return;
	}
}

void func_0070A8(void)
{
	switch ((uint32_t)(int8_t)unk_06000B)
	{
	case 0:
		func_0070CA();
		return;
	case 1:
		func_0070FC();
		return;
	case 2:
		func_007146();
		return;
	}
}

void func_0070CA(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	a6 = 0xA01Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	func_004604();
	func_004612();
	unk_06000B++;
}

void func_0070FC(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 != 0u || unk_060083 != 0u)
		return;
	d7 = 1u;
	func_0022AA(d7);
	a6 = 0xD2C4u;
	start_palette_effects(a6);
	a6 = 0xD2E6u;
	start_palette_effects(a6);
	unk_0600C2 = 0xFAu;
	unk_06000B++;
	d7_2 = 0x6Du;
	func_0091A4(d7_2, a6);
}

void func_007146(void)
{
	uint8_t t1 = 0;

	func_0077E2();
	t1 = unk_0600C2;
	unk_0600C2 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_060005 = 8u;
		unk_060007 = 0u;
		unk_060009 = 0u;
		unk_06000B = 0u;
		return;
	}
}

void func_007174(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	a6 = unk_060118_ADDRESS;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d7 & 7u))) != 0u && (unk_0600A6 & shl32(1u, (int)(d7 & 7u))) == 0u)
		{
			unk_0600A6 &= ~shl32(1u, (int)(d7 & 7u));
			unk_0600A1 &= ~shl32(1u, (int)(d7 & 7u));
			mem_write16(a6, 0u);
			mem_write8(a6 + 6u, 0u);
			mem_write8(a6 + 7u, 0u);
		}
		t1 = d7 - 1u;
		d7 = t1;
		a6 -= 8u;
	} while (t1 != 0xFFFFu);
	unk_0600A0 = 0u;
	unk_0600B3 = 0u;
}

void func_0071FA(void)
{
	unk_060062 = (unk_060062 & 0xFF00u) | (0u - ((((uint8_t)unk_0600A4 & 2u) << 1) + (uint8_t)(unk_063384 >> 8u)) & 0xFFu);
}

void func_007216(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d7 = 0x1FFu;
	a6 = TILE_RAM + 0x2200u;
	do
	{
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x10u);
		t1 = d7 - 1u;
		d7 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

void func_00722E(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d7 = 1u;
	a6 = record_007276_ADDRESS;
	do
	{
		a5 = DATA32(a6);
		d0 = DATA8(a6 + 4u);
		d6 = DATA8(a6 + 6u);
		d1 = 0u;
		do
		{
			a4 = a5;
			d5 = DATA8(a6 + 5u);
			d1 &= ~0xFu;
			do
			{
				mem_write8(a4, d0);
				a4++;
				mem_write8(a4, d1);
				d1++;
				t1 = d5 - 1u;
				d5 = t1;
				a4++;
			} while (t1 != 0xFFFFu);
			d1 = (uint8_t)(d1 - 1u + 0x10u);
			t2 = d6 - 1u;
			d6 = t2;
			a5 += 0x80u;
		} while (t2 != 0xFFFFu);
		t3 = d7 - 1u;
		d7 = t3;
		a6 += 8u;
	} while (t3 != 0xFFFFu);
}

uint32_t func_007286(uint32_t a6)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0, a5 = 0, a6_2 = 0;

	a5 = indexed_table_of_16_bit_values_0072E2_ADDRESS;
	d7 = unk_063480;
	d7 = (uint16_t)((d7 & 7u) << 2);
	mem_write16(a6 + 0xCu, indexed_table_of_16_bit_values_0072E2[d7 / 2u]);
	mem_write16(a6 + 0xCu, mem_read16(a6 + 0xCu) + 0x100u);
	mem_write16(a6 + 0xEu, rom_0072E4[d7 / 2u]);
	mem_write16(a6 + 0xEu, mem_read16(a6 + 0xEu) + 0x60u);
	mem_write16(a6, 0x8100u);
	mem_write16(a6 + 2u, 0u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	a0 = a6;
	a6_2 = rom_014C86;
	set_animation(0u, a0, a6_2);
	unk_063480++;
	return a5;
}

void func_007302(void)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0;

	a0 = unk_0623C0_ADDRESS;
	d7 = 0xBu;
	do
	{
		if (mem_read8(a0) != 0u && mem_read8(a0 + 0x33u) == 0u)
			func_01832A(a0);
		t1 = d7 - 1u;
		d7 = t1;
		a0 += 0x50u;
	} while (t1 != 0xFFFFu);
}

void func_00732E(void)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, a6 = 0, d7 = 0, ignored = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	a6 = unk_0623C0_ADDRESS;
	do
	{
		mem_write16(a6, 0x8100u);
		mem_write16(a6 + 2u, 0u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		mem_write8(a6 + 0x2Fu, 0u);
		mem_write16(a6 + 4u, 0u);
		d6 = (uint16_t)(d7 << 2);
		mem_write16(a6 + 0xCu, TABLE16(indexed_table_of_16_bit_values_00738C, (uint32_t)(int16_t)d6));
		mem_write16(a6 + 0xEu, mem_read16(0x738Eu + (int16_t)d6));
		a0 = a6;
		a6 = rom_015764[d7 & 0x3FFFu];
		set_animation(ignored, a0, a6);
		t1 = d7 - 1u;
		d7 = t1;
		a6 = a0 + 0x50u;
	} while (t1 != 0xFFFFu);
}

void func_00739C(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0, t2 = 0;

	d7 = 3u;
	a6 = unk_0623C0_ADDRESS;
	do
	{
		d6 = unk_0600A4 & 1u;
		t1 = mem_read16(a6 + 0xCu);
		mem_write16(a6 + 0xCu, t1 - d6);
		if (t1 < d6)
			mem_write16(a6 + 0xCu, 0x300u);
		t2 = d7 - 1u;
		d7 = t2;
		a6 += 0x50u;
	} while (t2 != 0xFFFFu);
}

void func_0073C8(void)
{
	uint8_t d7 = 0;

	if (unk_06342E == 0u || ((unk_060050 | unk_060051 | unk_060052 | unk_060053) & 0x30u) == 0u)
		return;
	d7 = 0xFEu;
	func_0091A4(d7, 0u);
	unk_060009++;
	unk_06000B = 0u;
}

void func_007404(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d1 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	a0 = TILE_RAM + 0x4018u;
	d0 = 0x14u;
	d1 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1++;
			a0++;
			if (carry)
				d0++;
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x40u;
	} while (t2 != 0xFFFFu);
}

void func_007430(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = 0x63476u;
	d7 = 6u;
	do
	{
		func_007492(a4);
		mem_write8(a4 + 8u, (uint32_t)d7 << 3);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
	unk_06342F = 7u;
}

void func_00745A(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = 0x63476u;
	d7 = 7u;
	do
	{
		func_007492(a4);
		mem_write8(a4 + 8u, (8u - d7) << 3);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
	unk_06342F = 8u;
	unk_063434 = 0x77D2u;
}

void func_007492(uint32_t a4)
{
	uint32_t d6 = 0;

	mem_write32(a4, TILE_RAM + 0x42Au);
	mem_write8(a4 + 9u, 4u);
	d6 = unk_06342E;
	mem_write32(a4 + 4u, 0x76F2u + (uint16_t)(d6 << 4));
}

void func_0074B8(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = 0x63476u;
	d7 = 6u;
	do
	{
		func_0074F8(d7, a4);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
}

void func_0074D4(void)
{
	uint16_t d0 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint16_t t1 = 0;

	a4 = 0x63476u;
	d0 = 7u;
	do
	{
		a3 = a4;
		d7 = (uint16_t)d0;
		if (d0 != 0u)
			d7 = (uint16_t)((d7 & ~0xFFu) | (uint8_t)(d7 - 1u));
		func_0074F8(d7, a4);
		t1 = d0 - 1u;
		d0 = t1;
		a4 = a3 - 0xAu;
	} while (t1 != 0xFFFFu);
}

void func_0074F8(uint16_t d7, uint32_t a4)
{
	uint8_t d5 = 0;
	uint16_t d6 = 0;
	uint32_t a5 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0, t3 = 0;

	if (mem_read32(a4 + 4u) == 0u)
		return;
	t1 = mem_read8(a4 + 8u);
	mem_write8(a4 + 8u, t1 - 1u);
	if (t1 != 0u)
		return;
	a5 = mem_read32(a4);
	d6 = mem_read8(mem_read32(a4 + 4u));
	if (d6 == 0x21u)
	{
		mem_write16(a4 + 2u, 0u);
		mem_write16(a4, 0u);
		mem_write16(a4 + 6u, 0u);
		mem_write16(a4 + 4u, 0u);
		mem_write16(a4 + 8u, 0u);
		unk_06342F--;
		return;
	}
	d5 = TABLE8(rom_001F1B, (uint32_t)(int16_t)d7);
	if (d6 != 0x40u)
		d5 += 0x18u;
	mem_write8(a5, d5);
	mem_write8(a5 + 2u, d5);
	mem_write8(a5 + 0x80u, d5);
	mem_write8(a5 + 0x82u, d5);
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 0x40u) << 2);
	mem_write8(a5 + 1u, indexed_table_of_8_bit_values_007592[d6]);
	mem_write8(a5 + 3u, rom_007593[d6]);
	mem_write8(a5 + 0x81u, rom_007594[d6]);
	mem_write8(a5 + 0x83u, rom_007595[d6]);
	t2 = mem_read32(a4 + 4u) + 1u;
	mem_write16(a4 + 6u, t2);
	mem_write16(a4 + 4u, t2 >> 16);
	t3 = mem_read32(a4) + 4u;
	mem_write16(a4 + 2u, t3);
	mem_write16(a4, t3 >> 16);
	mem_write8(a4 + 8u, mem_read8(a4 + 9u));
}

void func_0077E2(void)
{
	uint8_t d7 = 0;

	if (unk_0600C2 >= 0xF0u || ((unk_060050 | unk_060051 | unk_060052 | unk_060053) & 0x30u) == 0u)
		return;
	d7 = 0u;
	func_0091A4(d7, 0u);
	unk_060005 = 8u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
}

void func_00781E(uint32_t d1, uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_007846();
		break;
	case 1:
		func_0078CE(d1, d6);
		break;
	case 2:
		func_0079F8(d6, a5);
		break;
	}
	func_0049AA();
}

void func_007846(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_007868();
		break;
	case 1:
		func_007880();
		break;
	}
	func_004206(&ignored, &ignored_2);
}

void func_007868(void)
{
	uint16_t d7 = 0;

	unk_060082 = 1u;
	d7 = 1u;
	func_004164(d7);
	unk_060009++;
}

void func_007880(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;

	if (unk_060082 != 0u)
		return;
	d7 = 0xB7Fu;
	func_004164(d7);
	d7 = 0xF02u;
	func_004164(d7);
	unk_060006 = 0x14u;
	unk_060008 = 1u;
	d7_2 = 0u;
	func_0091A4(d7_2, 0u);
	d7_2 = 0x77u;
	func_0091A4(d7_2, 0u);
	unk_060007++;
	unk_060009 = 0u;
}

void func_0078CE(uint32_t d1, uint16_t d6)
{
	uint16_t d7 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d7 = (uint16_t)((uint32_t)(int8_t)unk_060009 << 2);
	switch ((uint32_t)(int16_t)d7)
	{
	case 0:
		d1 = func_0078FC(d1, d6, d7);
		break;
	}
	func_00445E(d1, &ignored, &ignored_2, &ignored_3);
	d7 = (uint16_t)(0xB00u | 0x10u | unk_0600B7);
	func_004164(d7);
}

uint32_t func_0078FC(uint32_t d1, uint32_t d6, uint32_t d7)
{
	uint32_t zero = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	zero = unk_060082 == 0u;
	func_007902(zero, &d1, &ignored, &d6, &d7, &ignored_2);
	return d1;
}

void func_007902(uint32_t zero, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	if (zero == 0u)
	{
		func_004206(p_d1, p_a5);
		*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
		*p_d7 = d7;
		return;
	}
	t1 = unk_060008;
	unk_060008 = t1 - 1u;
	if (t1 == 1u)
	{
		if (unk_060006 == 0u)
		{
			unk_060007++;
			unk_060009 = 0u;
			unk_060006 = 0u;
			unk_060008 = 0u;
			d7 = 0x200u;
			func_004164((uint16_t)d7);
			*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
			*p_d7 = d7;
			return;
		}
		unk_060008 = 0x48u;
		unk_060006--;
		d7 = unk_060006;
		draw_big_character(p_d5, &d6, &d7, p_a5);
	}
	if ((unk_0600A6 | unk_0600A1) != 0u)
	{
		unk_060082 = 1u;
		d7_2 = (d7 & ~0xFFFFu) | 1u;
		func_004164((uint16_t)d7_2);
		d7 = (d7_2 & ~0xFFFFu) | 0xB7Fu;
		func_004164((uint16_t)d7);
		d7 = func_006A9C(d7);
		unk_060005 = 4u;
		unk_060007 = 1u;
		unk_060009 = 0u;
		*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
		*p_d7 = d7;
		return;
	}
	if (unk_060006 > 0x10u)
	{
		func_004206(p_d1, p_a5);
		*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
		*p_d7 = d7;
		return;
	}
	d7 = (d7 & ~0xFFu) | 3u;
	a6 = unk_060034_ADDRESS;
	*p_a5 = unk_060100_ADDRESS;
	do
	{
		d0 = mem_read8(a6);
		a6++;
		if ((d0 & 0x30u) != 0u && mem_read16(*p_a5) == 0u)
		{
			d7_2 = (d7 & ~0xFFFFu) | unk_0600A4;
			t2 = d7_2 & 7u;
			d7 = (d7_2 & ~0xFFFFu) | t2;
			if (t2 == 0u)
			{
				unk_060008 = 1u;
				break;
			}
		}
		t3 = d7 - 1u;
		d7 = (d7 & ~0xFFFFu) | t3;
		*p_a5 += 8u;
	} while (t3 != 0xFFFFu);
	func_004206(p_d1, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_0079F8(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_007A1A();
		return;
	case 1:
		func_007A30();
		return;
	case 2:
		func_007A82(d6, a5);
		return;
	}
}

void func_007A1A(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 1u;
	func_004164(d7);
	unk_060009++;
}

void func_007A30(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 != 0u)
		return;
	unk_060006 = 0xF0u;
	d7 = 1u;
	func_0022AA(d7);
	func_009A3A();
	a6 = 0xD2C4u;
	start_palette_effects(a6);
	a6 = 0xD2E6u;
	start_palette_effects(a6);
	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063410 = 0u;
	unk_060009++;
	d7_2 = 0x6Du;
	func_0091A4(d7_2, a6);
}

void func_007A82(uint16_t d6, uint32_t a5)
{
	uint8_t t1 = 0;

	if (unk_060082 == 0u)
	{
		func_007AD2();
		func_007AB2(d6, a5);
		t1 = unk_060006;
		unk_060006 = t1 - 1u;
		if (t1 == 1u)
		{
			unk_060005++;
			unk_060007 = 0u;
			unk_060009 = 0u;
		}
	}
}

void func_007AB2(uint16_t d6, uint32_t a5)
{
	if ((uint8_t)(unk_063410 >> 8u) == 0u)
	{
		a5 = 0xA08Eu;
		d6 = 0x1E02u;
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
	}
	copy_palette_sets(d6, a5);
}

void func_007AD2(void)
{
	uint8_t d7 = 0;

	if (unk_060006 >= 0xB0u || ((unk_060050 | unk_060051 | unk_060052 | unk_060053) & 0x30u) == 0u)
		return;
	d7 = 0u;
	func_0091A4(d7, 0u);
	unk_060005++;
	unk_060007 = 0u;
	unk_060009 = 0u;
}

void func_007B0C(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_007B42();
		return;
	case 1:
		func_007C16();
		return;
	case 2:
		func_007CE2();
		return;
	case 3:
		func_007D32();
		return;
	case 4:
		func_007DF6();
		return;
	case 5:
		func_007E30();
		return;
	case 6:
		func_007FA6();
		return;
	case 7:
		func_007FC8();
		return;
	}
}

void func_007B42(void)
{
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_007B64();
		return;
	case 1:
		func_007B86();
		return;
	case 2:
		func_007BBA();
		return;
	}
}

void func_007B64(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u)
	{
		unk_060082 = 1u;
		d7 = 7u;
		func_004164(d7);
		unk_060009++;
	}
}

void func_007B86(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 == 0u)
	{
		func_004604();
		func_004612();
		a6 = 0xA02Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		func_009A3A();
		unk_060009++;
	}
}

void func_007BBA(void)
{
	if (unk_060082 != 0u || unk_060083 != 0u)
		return;
	unk_0635F4 = 0u;
	unk_060064 = 0u;
	io_write8(TILES_106B00, 0u);
	unk_060065 = 0u;
	io_write8(TILES_106E00, 0u);
	unk_060062 = 0u;
	unk_060060 = 0x60u;
	unk_0634A0 = 0u;
	unk_060007++;
	unk_060009 = 0u;
}

void func_007C16(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0, d6 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0, a6 = 0, d3 = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;

	a6 = unk_063500_ADDRESS;
	a5 = unk_0635C8_ADDRESS;
	a4 = unk_0635F4_ADDRESS;
	a3 = unk_060118_ADDRESS;
	d7 = 3u;
	do
	{
		extend = 0u;
		unk_0635F0 = 0x41414100u;
		d6 = 0xC4u;
		unk_0635C6 = mem_read16(a3 + 4u);
		do
		{
			d0 = RAM16(unk_063500_ADDRESS + (uint32_t)(int16_t)d6);
			if (RAM16(unk_063502_ADDRESS + (uint32_t)(int16_t)d6) < d0)
				break;
			RAM16(unk_063500_ADDRESS + (uint32_t)(int16_t)d6) = RAM16(unk_063502_ADDRESS + (uint32_t)(int16_t)d6);
			RAM16(unk_063502_ADDRESS + (uint32_t)(int16_t)d6) = d0;
			d0_2 = m68k_sbcd(RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7), 1u, extend);
			RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) = d0_2;
			if (d0_2 < 0x11u)
			{
				d2 = (uint16_t)d0_2;
				if (d2 == 0x10u)
					d2 = 0xAu;
				d2 = (uint16_t)((d2 - 1u) << 2);
				d3 = mem_read32(a5 + 4u + (int16_t)d2);
				mem_write32(a5 + 4u + (int16_t)d2, RAM32(unk_0635C8_ADDRESS + (uint32_t)(int16_t)d2));
				RAM32(unk_0635C8_ADDRESS + (uint32_t)(int16_t)d2) = d3;
			}
			t1 = d6;
			carry = t1 < 2u;
			extend = carry;
			d6 = (uint16_t)(t1 - 2u);
		} while (t1 >= 2u);
		t2 = d7 - 1u;
		d7 = t2;
		a3 -= 8u;
	} while (t2 != 0xFFFFu);
	d7 = 3u;
	do
	{
		d0_2 = RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7);
		t3 = d7;
		carry = t3 == 0u;
		extend = carry;
		d6 = (uint16_t)(t3 - 1u);
		if (t3 != 0u)
		{
			do
			{
				if (d0_2 == 0u)
					break;
				if (RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d6) != 0u && RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d6) <= d0_2)
				{
					t4 = m68k_abcd(d0_2, 1u, extend);
					carry = m68k_abcd_cy(d0_2, 1u, extend);
					extend = carry;
					d0_2 = t4;
				}
				t5 = d6 - 1u;
				d6 = t5;
			} while (t5 != 0xFFFFu);
		}
		RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) = d0_2;
		t6 = d7 - 1u;
		d7 = t6;
	} while (t6 != 0xFFFFu);
	unk_060007++;
}

void func_007CE2(void)
{
	uint8_t d4 = 0;
	uint16_t d0 = 0, d7 = 0;
	uint32_t a0 = 0, d6 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	a0 = unk_0635F4_ADDRESS;
	unk_0635F8 = (unk_0635F8 & 0xFFu) | 0x4F00u;
	do
	{
		if (RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) != 0u)
		{
			d6 = func_008150(d6, d7);
			func_0081CC((uint8_t)d6, d7);
			d4 = (uint8_t)shl32(1u, (int)(d7 & 0x1Fu));
			func_001FB8(d4);
			d7 = (uint16_t)d7;
			func_008212(d7, a0);
			d0 = (uint16_t)d7;
			d7_2 = shl32(1u, (int)(d0 & 0x1Fu));
			unk_0635F8 = (unk_0635F8 & 0xFFu) | (((uint8_t)(unk_0635F8 >> 8u) & ~shl32(1u, (int)(d0 & 7u)) & 0xFFu) << 8u);
			func_008B58(d7_2);
			d7 = (uint16_t)d0;
		}
		t1 = d7 - 1u;
		d7 = t1;
	} while (t1 != 0xFFFFu);
	unk_060007++;
}

void func_007D32(void)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0, d7_3 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = unk_0635F4_ADDRESS;
	d6 = 0u;
	d7 = 3u;
	for (;;)
	{
		if (RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) == 0u)
		{
			d6++;
			t1 = d7 - 1u;
			d7 = t1;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) < 0x11u)
		{
			d7_2 = 0x71u;
			func_0091A4(d7_2, a6);
			a6 = unk_0635F4_ADDRESS;
			a5 = unk_0635FA_ADDRESS;
			d6 = 0u;
			d7 = 3u;
			do
			{
				if (RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) == 0u || RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7) >= 0x11u)
					unk_0635FA((uint32_t)(int16_t)d7) = 3u;
				else
				{
					unk_0635FA((uint32_t)(int16_t)d7) = 0u;
					d6 |= shl32(1u, (int)(d7 & 0x1Fu));
				}
				t2 = d7 - 1u;
				d7 = t2;
			} while (t2 != 0xFFFFu);
			unk_0635FE = d6;
			unk_0635FF = 0u;
			d7_3 = func_00804A();
			d7_3 = (d7_3 & ~0xFFu) | (uint8_t)(unk_0635F8 >> 8u);
			func_008B58(d7_3);
			unk_0635F8 = 0x5DCu;
			unk_060007 += 2u;
			return;
		}
		t1 = d7 - 1u;
		d7 = t1;
		if (t1 == 0xFFFFu)
			break;
	}
	if (d6 == 4u)
	{
		func_007FEC();
		return;
	}
	d7_2 = 0x71u;
	func_0091A4(d7_2, a6);
	d7_3 = func_00804A();
	d7_3 = (d7_3 & ~0xFFu) | (uint8_t)(unk_0635F8 >> 8u);
	func_008B58(d7_3);
	unk_0635F8 = 0x1E0u;
	unk_060007++;
}

void func_007DF6(void)
{
	uint8_t d7 = 0;
	uint16_t t1 = 0;

	t1 = unk_0635F8;
	unk_0635F8 = t1 - 1u;
	if (t1 != 1u && ((unk_060034(0) | unk_060035 | unk_060036 | unk_060037) & 0x30u) == 0u)
		return;
	d7 = 0xFEu;
	func_0091A4(d7, 0u);
	unk_0635F8 = 0x3Cu;
	unk_060007 = 7u;
}

void func_007E30(void)
{
	uint8_t d0 = 0, d1 = 0, d4 = 0, d6 = 0, d7_2 = 0;
	uint16_t d5 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0, a6 = 0;
	uint32_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;
	uint32_t unk_060020_long = 0, t4 = 0;

	t1 = unk_0635F8;
	unk_0635F8 = t1 - 1u;
	if (t1 == 1u)
	{
		d7_2 = 0xFEu;
		func_0091A4(d7_2, 0u);
		unk_0634A0 = 1u;
		unk_0635F8 = 0x3Cu;
		unk_060007 = 7u;
		return;
	}
	if ((unk_0600A4 & 7u) != 0u)
		return;
	d7 = 3u;
	do
	{
		if ((unk_0635FE & shl32(1u, (int)(d7 & 7u))) != 0u)
			func_00809C(d7);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	a3 = unk_0635FA_ADDRESS;
	a4 = unk_0635C8_ADDRESS;
	a5 = unk_0635F4_ADDRESS;
	unk_060020_long = (((uint32_t)unk_060034(0) << 24u) | ((uint32_t)unk_060035 << 16u) | ((uint32_t)unk_060036 << 8u) | unk_060037) | (((uint32_t)unk_060038(0) << 24u) | ((uint32_t)unk_060039 << 16u) | ((uint32_t)unk_06003A << 8u) | unk_06003B) | unk_06003C | unk_060040;
	unk_060020(0) = (uint8_t)(unk_060020_long >> 24u);
	unk_060021 = (uint8_t)(unk_060020_long >> 16u);
	unk_060022 = (uint8_t)(unk_060020_long >> 8u);
	unk_060023 = (uint8_t)unk_060020_long;
	a6 = unk_060020_ADDRESS;
	d0 = 0u;
	d1 = 0u;
	d7 = 3u;
	do
	{
		if (unk_0635FA((uint32_t)(int16_t)d7) < 3u)
		{
			if ((unk_0635FE & shl32(1u, (int)(d7 & 7u))) != 0u)
			{
				t3 = unk_060020((uint32_t)(int16_t)d7);
				d6 = t3;
				if (t3 != 0u)
				{
					if ((d6 & 0x30u) == 0u)
					{
						d5 = RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7);
						if (d5 == 0x10u)
							d5 = 0xAu;
						d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 1u) << 2);
						d5 = (uint16_t)((d5 & ~0xFFu) | (uint8_t)(d5 + unk_0635FA((uint32_t)(int16_t)d7)));
						d4 = (uint8_t)(unk_0635C8(d5) - 0x40u);
						if ((d6 & 1u) == 0u)
						{
							if ((d6 & 2u) != 0u)
							{
								unk_0635C8(d5) = ((d4 + 1u) & 0x1Fu) + 0x40u;
								stack = d0;
								d0 = 1u;
								func_0091F4(d0);
								d0 = (uint8_t)stack;
							}
						}
						else
						{
							unk_0635C8(d5) = ((d4 - 1u) & 0x1Fu) + 0x40u;
							stack = d0;
							d0 = 1u;
							func_0091F4(d0);
							d0 = (uint8_t)stack;
						}
					}
					else
					{
						d1 |= shl32(1u, (int)(d7 & 0x1Fu));
						if ((unk_0635FF & shl32(1u, (int)(d7 & 7u))) != 0u)
						{
							d5 = RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7);
							if (d5 == 0x10u)
								d5 = 0xAu;
							d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 1u) << 2);
							d5 = (uint16_t)((d5 & ~0xFFu) | (uint8_t)(d5 + unk_0635FA((uint32_t)(int16_t)d7)));
							d4 = (uint8_t)(unk_0635C8(d5) - 0x40u);
							if ((d6 & 1u) == 0u)
							{
								if ((d6 & 2u) != 0u)
								{
									unk_0635C8(d5) = ((d4 + 1u) & 0x1Fu) + 0x40u;
									stack = d0;
									d0 = 1u;
									func_0091F4(d0);
									d0 = (uint8_t)stack;
								}
							}
							else
							{
								unk_0635C8(d5) = ((d4 - 1u) & 0x1Fu) + 0x40u;
								stack = d0;
								d0 = 1u;
								func_0091F4(d0);
								d0 = (uint8_t)stack;
							}
						}
						else
						{
							t4 = a3 + (int16_t)d7;
							mem_write8(t4, mem_read8(t4) + 1u);
							stack = d0;
							d0 = 0x1Du;
							func_0091F4(d0);
							d0 = (uint8_t)stack;
						}
					}
				}
			}
		}
		else
			d0++;
		t5 = d7 - 1u;
		d7 = t5;
	} while (t5 != 0xFFFFu);
	unk_0635FF = d1;
	if (d0 == 4u)
	{
		d7_2 = 0xFEu;
		func_0091A4(d7_2, a6);
		unk_0634A0 = 1u;
		unk_0635F8 = 0x78u;
		unk_060007++;
	}
}

void func_007FA6(void)
{
	uint16_t t1 = 0;

	t1 = unk_0635F8;
	unk_0635F8 = t1 - 1u;
	if (t1 == 1u)
	{
		func_007FD4();
		return;
	}
}

void func_007FC8(void)
{
	uint16_t t1 = 0;

	t1 = unk_0635F8;
	unk_0635F8 = t1 - 1u;
	if (t1 == 1u)
	{
		func_007FD4();
		return;
	}
}

void func_007FD4(void)
{
	if (unk_0600B7 != 0u || unk_0634A0 == 0u)
	{
		func_007FEC();
		return;
	}
	unk_060001 = 1u;
	unk_060003 = 6u;
	unk_060005 = 0u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
	unk_0600A3 = 0u;
}

void func_007FEC(void)
{
	unk_060001 = 1u;
	unk_060003 = 0u;
	unk_060005 = 0u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
	unk_0600A3 = 0u;
}

uint32_t func_00804A(void)
{
	uint8_t d5 = 0;
	uint16_t d4 = 0, d6 = 0;
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM + 0x4F18u;
	a5 = indexed_table_of_8_bit_values_00807E_ADDRESS;
	d7 = 0x1Du;
	do
	{
		d6 = 0x27u;
		d5 = mem_read8(a5 + (int16_t)d7);
		do
		{
			d4 = (uint16_t)((uint32_t)(uint8_t)d6 << 1);
			mem_write8(a6 + d4, 0u);
			mem_write8(a6 + 1u + d4, d5);
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a6 -= 0x80u;
	} while (t2 != 0xFFFFu);
	return d7;
}

void func_00809C(uint16_t d7)
{
	uint8_t d0 = 0;
	uint16_t d5 = 0, d6 = 0;
	uint32_t a3 = 0, a4 = 0, a6 = 0;

	a6 = mem_read32(0x840Au + (int16_t)((uint32_t)d7 << 2));
	a3 = unk_0635FA_ADDRESS;
	a4 = unk_0635C8_ADDRESS;
	d6 = mem_read8(unk_0635F4_ADDRESS + (int16_t)d7);
	if (d6 == 0x10u)
		d6 = 0xAu;
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 1u) << 2);
	d5 = unk_0635C8(d6);
	d0 = 0u;
	if (unk_0635FA((uint32_t)(int16_t)d7) == 0u)
		d0 = 0xA0u;
	func_00812E(d0, d5, a6);
	d5 = unk_0635C9(d6);
	d0 = 0u;
	a6 += 4u;
	if (unk_0635FA((uint32_t)(int16_t)d7) == 1u)
		d0 = 0xA0u;
	func_00812E(d0, d5, a6);
	d5 = unk_0635CA(d6);
	d0 = 0u;
	a6 += 4u;
	if (unk_0635FA((uint32_t)(int16_t)d7) == 2u)
		d0 = 0xA0u;
	func_00812E(d0, d5, a6);
}

void func_00812E(uint8_t d0, uint16_t d5, uint32_t a6)
{
	d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 0x30u) << 1);
	mem_write8(a6, d0);
	mem_write8(a6 + 1u, indexed_table_of_8_bit_values_002884[d5]);
	mem_write8(a6 + 0x80u, d0);
	mem_write8(a6 + 0x81u, rom_002885[d5]);
}

uint32_t func_008150(uint32_t d6, uint16_t d7)
{
	uint16_t d4 = 0, d5 = 0;
	uint32_t a5 = 0, a6 = 0, d6_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d6_2 = (d6 & ~0xFFFFu) | d7;
	d6_2 = (d6_2 & ~0xFFFFu) | (uint16_t)(d6_2 << 2);
	a6 = mem_read32(0x83DAu + (int16_t)d6_2);
	d6_2 = (d6_2 & ~0xFFFFu) | d7;
	d6_2 = func_0082A8(d6_2);
	d5 = 8u;
	d4 = 0u;
	a5 = 0x841Au;
	do
	{
		d4 += 0x80u;
		mem_write8(a6 + (int16_t)d4, d6_2);
		mem_write8(a6 + 1u + (int16_t)d4, DATA8(a5 + 9u));
		d4 -= 0x80u;
		mem_write8(a6 + (int16_t)d4, d6_2);
		mem_write8(a6 + 1u + (int16_t)d4, DATA8(a5));
		d4 = (uint16_t)((d4 & ~0xFFu) | (uint8_t)(d4 + 2u));
		t1 = d5 - 1u;
		d5 = t1;
		a5++;
	} while (t1 != 0xFFFFu);
	d5 = 0x17u;
	a6 += 0x100u;
	do
	{
		mem_write8(a6, d6_2);
		mem_write8(a6 + 1u, 0x1Au);
		mem_write8(a6 + 0x10u, d6_2);
		mem_write8(a6 + 0x11u, 0x1Du);
		t2 = d5 - 1u;
		d5 = t2;
		a6 += 0x80u;
	} while (t2 != 0xFFFFu);
	d5 = 8u;
	d4 = 0u;
	a5 = 0x842Cu;
	do
	{
		mem_write8(a6 + d4, d6_2);
		mem_write8(a6 + 1u + d4, DATA8(a5));
		d4 = (uint8_t)(d4 + 2u);
		t3 = d5 - 1u;
		d5 = t3;
		a5++;
	} while (t3 != 0xFFFFu);
	return d6_2;
}

void func_0081CC(uint8_t d6, uint16_t d7)
{
	uint32_t a5 = 0, a6 = 0;

	a6 = mem_read32(0x83EAu + (int16_t)((uint32_t)d7 << 2));
	a5 = TABLE32(rom_00332A, (uint32_t)(int16_t)((uint32_t)d7 << 2));
	mem_write8(a6, d6);
	mem_write8(a6 + 2u, d6);
	mem_write8(a6 + 0x80u, d6);
	mem_write8(a6 + 0x82u, d6);
	mem_write8(a6 + 1u, mem_read8(a5));
	mem_write8(a6 + 3u, mem_read8(a5 + 1u));
	mem_write8(a6 + 0x81u, mem_read8(a5 + 2u));
	mem_write8(a6 + 0x83u, mem_read8(a5 + 3u));
}

void func_008212(uint16_t d7, uint32_t a0)
{
	uint8_t d6 = 0;
	uint16_t d5 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t1 = 0;

	a6 = mem_read32(0x83FAu + (int16_t)((uint32_t)d7 << 2));
	a5 = 0x8436u;
	d6 = RAM8(unk_0635F4_ADDRESS + (uint32_t)(int16_t)d7);
	d5 = (uint16_t)d6;
	d5 = (uint8_t)(d5 - 1u);
	if (d5 >= 3u)
		d5 = 3u;
	d5 = (uint16_t)((uint32_t)d5 << 1);
	mem_write8(a6 + 0x84u, 0u);
	mem_write8(a6 + 0x85u, DATA8(a5 + d5));
	mem_write8(a6 + 0x86u, 0u);
	mem_write8(a6 + 0x87u, DATA8(a5 + 1u + d5));
	a5 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d5 = (uint16_t)((d6 & 0xFu) << 1);
	mem_write8(a6 + 2u, 0u);
	mem_write8(a6 + 3u, indexed_table_of_8_bit_values_002884[d5]);
	mem_write8(a6 + 0x82u, 0u);
	mem_write8(a6 + 0x83u, indexed_table_of_8_bit_values_002884[(uint8_t)(d5 + 1u)]);
	t1 = d6 & 0xF0u;
	d5 = t1;
	if (t1 != 0u)
	{
		d5 = d5 >> 3;
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, DATA8(a5 + d5));
		mem_write8(a6 + 0x80u, 0u);
		mem_write8(a6 + 0x81u, DATA8(a5 + (uint8_t)(d5 + 1u)));
	}
}

uint32_t func_0082A8(uint32_t d6)
{
	uint32_t d6_2 = 0;

	d6_2 = (d6 & ~0xFFu) | TABLE8(rom_001F1B, (uint32_t)(int16_t)d6);
	d6_2 = d6_2 | 1u;
	return d6_2;
}

void func_0082B8(void)
{
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t2 = 0, t4 = 0;
	uint32_t t1 = 0, t3 = 0;

	a6 = unk_063500_ADDRESS;
	a5 = table_loaded_by_lea_0082E6_ADDRESS;
	unk_060076 = 0x1000u;
	d7 = 0x31u;
	do
	{
		t1 = a6;
		a6 += 4u;
		mem_write32(t1, DATA32(a5));
		t2 = d7 - 1u;
		d7 = t2;
		a5 += 4u;
	} while (t2 != 0xFFFFu);
	d7 = 0xAu;
	do
	{
		t3 = a6;
		a6 += 4u;
		mem_write32(t3, DATA32(a5));
		t4 = d7 - 1u;
		d7 = t4;
		a5 += 4u;
	} while (t4 != 0xFFFFu);
}

void func_0088C0(void)
{
	unk_060003++;
	unk_060005 = 0u;
	unk_060007 = 0u;
	unk_060009 = 0u;
}

void func_0088DA(uint32_t d1)
{
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_0088F8();
		return;
	case 1:
		func_0089F4(d1);
		return;
	}
}

void func_0088F8(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_00891E();
		return;
	case 1:
		func_00892E();
		return;
	case 2:
		func_00895E();
		return;
	case 3:
		func_008982();
		return;
	}
}

void func_00891E(void)
{
	unk_060004 = 2u;
	unk_060007++;
}

void func_00892E(void)
{
	uint16_t d7 = 0;
	uint8_t t1 = 0;

	if (unk_060082 == 0u)
	{
		t1 = unk_060004;
		unk_060004 = t1 - 1u;
		if (t1 == 0u)
		{
			func_0044F8();
			unk_060082++;
			d7 = 7u;
			func_004164(d7);
			unk_060007++;
		}
	}
}

void func_00895E(void)
{
	if (unk_060082 == 0u)
	{
		func_009A5C();
		func_009A3A();
		func_009AA8();
		unk_060007++;
	}
}

void func_008982(void)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;

	if (unk_060082 != 0u || unk_060083 != 0u)
		return;
	func_004072();
	func_008C6A();
	d0 = unk_060100(0) | AT16(unk_060108, -1) | AT16(unk_060110, -1) | AT16(unk_060118, -1);
	d0 = (uint16_t)(d0 | unk_060091);
	if ((d0 | unk_060320) == 0u)
	{
		unk_060003++;
		unk_060005 = 0u;
		unk_060007 = 0u;
		return;
	}
	d7 = 0x7Eu;
	func_0091A4(d7, 0u);
	unk_060005++;
	unk_060007 = 0u;
}

void func_0089F4(uint32_t d1)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_008A1E();
		return;
	case 1:
		func_008A2E();
		return;
	case 2:
		func_008A36();
		return;
	case 3:
		func_008A3E();
		return;
	case 4:
		func_008AC6(d1);
		return;
	}
}

void func_008A1E(void)
{
	uint16_t d7 = 0;

	d7 = 0xB5Fu;
	func_004164(d7);
	unk_060007++;
}

void func_008A2E(void)
{
	unk_060007++;
}

void func_008A36(void)
{
	unk_060007++;
}

void func_008A3E(void)
{
	uint8_t d7_2 = 0;
	uint16_t d6 = 0;
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	a5 = table_loaded_by_lea_008ABE_ADDRESS;
	func_004184(a5);
	d7 = 0u;
	d6 = 3u;
	a6 = unk_060118_ADDRESS;
	do
	{
		if (mem_read16(a6) != 0u)
			d7 |= shl32(1u, (int)(d6 & 0x1Fu));
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 8u;
	} while (t1 != 0xFFFFu);
	unk_0600C4 = 0x10203u;
	func_008B58(d7);
	unk_060004 = 0xAu;
	unk_060006 = 0u;
	unk_060007++;
	d7_2 = 0x6Fu;
	func_0091A4(d7_2, a6);
}

void func_008AC6(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t ignored = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	func_00445E(d1, &ignored, &ignored_3, &ignored_4);
	if (unk_060327 != 0u)
	{
		d7_2 = (uint16_t)(0xB00u | 0x10u | unk_0600A2);
		func_004164(d7_2);
		unk_060007--;
		return;
	}
	if (unk_060152 != 0u)
	{
		d7 = 0x6Fu;
		func_0091A4(d7, 0u);
	}
	if ((unk_0600A4 & 0x3Fu) == 0u)
	{
		t1 = unk_060004;
		unk_060004 = t1 - 1u;
		if (t1 == 1u)
			return;
	}
}

void func_008B1E(void)
{
	unk_060005 = 0u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
	unk_060003 = 1u;
	unk_0600A1 = 0u;
	unk_0600A6 = 0u;
	unk_0600A0 = 0u;
	unk_0600B3 = 0u;
}

void func_008B58(uint32_t d7)
{
	uint16_t d6 = 0;

	d6 = 3u;
	func_008B5A(d6, d7);
}

void func_008B5A(uint16_t d6, uint32_t d7)
{
	uint16_t d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a6 = SPRITE_RAM;
	a4 = unk_0600C4_ADDRESS;
	do
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) != 0u)
		{
			d5 = (uint16_t)((uint32_t)RAM8(unk_0600C4_ADDRESS + (uint32_t)(int16_t)d6) << 4);
			a5 = table_loaded_by_lea_008BEA_ADDRESS;
			if ((d7 & 0x80u) != 0u)
				a5 = 0x8C2Au;
			a5 += d5;
			d5 = 3u;
			do
			{
				mem_write8(a6 + (int16_t)d5, mem_read8(a5 + (int16_t)d5));
				mem_write8(a6 + 8u + (int16_t)d5, mem_read8(a5 + 8u + (int16_t)d5));
				t1 = d5 - 1u;
				d5 = t1;
			} while (t1 != 0xFFFFu);
			d5 = (uint16_t)((uint32_t)(uint8_t)d6 << 4);
			a5 = table_loaded_by_lea_008BEA_ADDRESS;
			if ((d7 & 0x80u) != 0u)
				a5 = 0x8C2Au;
			a5 += d5;
			d5 = 3u;
			do
			{
				mem_write8(a6 + 4u + (int16_t)d5, mem_read8(a5 + 4u + (int16_t)d5));
				mem_write8(a6 + 0xCu + (int16_t)d5, mem_read8(a5 + 0xCu + (int16_t)d5));
				t2 = d5 - 1u;
				d5 = t2;
			} while (t2 != 0xFFFFu);
			if ((d7 & 0x40u) != 0u)
			{
				mem_write8(a6 + 3u, 8u);
				mem_write8(a6 + 0xBu, 8u);
			}
		}
		t3 = d6 - 1u;
		d6 = t3;
		a6 += 0x10u;
	} while (t3 != 0xFFFFu);
}

void func_008C6A(void)
{
	unk_06005C = 0u;
	unk_06005E = 0u;
	unk_060060 = 0u;
	unk_060062 = 0u;
	unk_0600C8 = 0u;
	unk_0600CA = 0u;
	unk_0600CC = 0u;
	unk_0600CE = 0u;
	unk_060054 = 0u;
	unk_060055 = 0u;
	unk_060056 = 0u;
	unk_060057 = 0u;
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106019, 0u);
}

void func_008CE4(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;

	if (unk_060327 != 0u)
	{
		d7 = 0x7Eu;
		func_0091A4(d7, 0u);
		func_008B1E();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_008D1A();
		return;
	case 1:
		func_008E04(d6, a5);
		return;
	}
}

void func_008D1A(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_008D40();
		return;
	case 1:
		func_008D66();
		return;
	case 2:
		func_008D8A();
		return;
	case 3:
		func_008DB8();
		return;
	}
}

void func_008D40(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u)
	{
		func_0044F8();
		unk_060082++;
		d7 = 7u;
		func_004164(d7);
		unk_060007++;
	}
}

void func_008D66(void)
{
	if (unk_060082 == 0u)
	{
		func_009A5C();
		func_009A3A();
		func_009AA8();
		unk_060007++;
	}
}

void func_008D8A(void)
{
	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		unk_060059 = 0u;
		io_write8(PRIORITY_0C0001, unk_060059);
		unk_060007++;
	}
}

void func_008DB8(void)
{
	if (unk_060082 == 0u)
	{
		unk_060005++;
		unk_060007 = 0u;
		unk_0600A8 = 0xB2u;
		func_046EEA();
		func_02F790();
		io_write8(TILES_106B00, 0u);
		unk_060064 = 0u;
		io_write8(TILES_106E00, 0u);
		unk_060065 = 0u;
	}
}

void func_008E04(uint16_t d6, uint32_t a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	if ((unk_0600A4 & 3u) == 0u)
	{
		t1 = unk_0600A8;
		unk_0600A8 = t1 - 1u;
		if (t1 == 1u)
		{
			unk_060003++;
			unk_060005 = 0u;
			unk_060007 = 0u;
			return;
		}
	}
	func_02F8AA(d6, a5);
	func_046F08(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

void func_008E46(void)
{
	if (unk_060327 != 0u)
	{
		func_008B1E();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_008E72();
		return;
	case 1:
		unreached_008F7E();
		return;
	}
}

void func_008E72(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_008E94();
		return;
	case 1:
		func_008EBA();
		return;
	case 2:
		func_008EDE();
		return;
	}
}

void func_008E94(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u)
	{
		func_0044F8();
		unk_060082++;
		d7 = 7u;
		func_004164(d7);
		unk_060007++;
	}
}

void func_008EBA(void)
{
	if (unk_060082 == 0u)
	{
		func_009A5C();
		func_009A3A();
		func_009AA8();
		unk_060007++;
	}
}

void func_008EDE(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		a6 = palettes_008F58_ADDRESS;
		d7 = 0x500u;
		post_palette_request(d7, a6);
		unk_060064 = 0u;
		io_write8(TILES_106B00, 0u);
		unk_060065 = 0u;
		io_write8(TILES_106E00, 0u);
		unk_060062 = 0u;
		unk_060060 = 0x60u;
		d7_2 = func_00804A();
		d6 = 4u;
		d7_2 = (d7_2 & ~0xFFu) | 0x8Fu;
		unk_0600C4 = 0x10203u;
		func_008B5A(d6, d7_2);
		func_00902E();
		unk_060005++;
		unk_060007 = 0u;
	}
}

void unreached_008F7E(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_008F9C();
		return;
	case 1:
		func_008FB6();
		return;
	}
}

void func_008F9C(void)
{
	if (unk_060082 == 0u)
	{
		unk_060007++;
		unk_060002 = 0xFFu;
	}
}

void func_008FB6(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = unk_060002;
	unk_060002 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_060003++;
		unk_060005 = 0u;
		unk_060007 = 0u;
		return;
	}
	a6 = SPRITE_RAM;
	d7 = 7u;
	for (;;)
	{
		if ((mem_read8(a6) & 0x80u) == 0u)
		{
			a6 += 8u;
			continue;
		}
		t2 = mem_read8(a6 + 6u);
		unk_0635F8 = (unk_0635F8 & 0xFFu) | ((t2 & 0xFFu) << 8u);
		(void)t2;
		t3 = mem_read8(a6 + 7u);
		unk_0635F8 = (unk_0635F8 & 0xFF00u) | (t3 & 0xFFu);
		(void)t3;
		unk_0635F8 &= 0x1FFu;
		unk_0635F8 += 4u;
		unk_0635F8 &= 0x1FFu;
		mem_write8(a6 + 6u, (uint8_t)(unk_0635F8 >> 8u));
		mem_write8(a6 + 7u, (uint8_t)unk_0635F8);
		t4 = d7 - 1u;
		d7 = t4;
		a6 += 8u;
		if (t4 != 0xFFFFu)
			continue;
		break;
	}
}

void func_00902E(void)
{
	uint32_t a5 = 0;

	a5 = 0x9190u;
	func_004184(a5);
	func_009042();
	func_0090C4();
}

void func_009042(void)
{
	uint8_t d6 = 0;
	uint16_t d6_2 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0, a6 = 0;

	a6 = unexplained_00917E;
	a5 = unk_0635C8_ADDRESS;
	a4 = 0x9186u;
	a3 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d7 = 0u;
	do
	{
		d6 = DATA8(a4 + d7);
		mem_write8(a6, d6);
		mem_write8(a6 + 4u, d6);
		mem_write8(a6 + 8u, d6);
		mem_write8(a6 + 0x80u, d6);
		mem_write8(a6 + 0x84u, d6);
		mem_write8(a6 + 0x88u, d6);
		d6_2 = mem_read8(a5);
		func_0090B0(d6_2, a3, a6);
		d6_2 = mem_read8(a5 + 1u);
		a6 += 4u;
		func_0090B0(d6_2, a3, a6);
		d6_2 = mem_read8(a5 + 2u);
		a6 += 4u;
		func_0090B0(d6_2, a3, a6);
		d7 = (uint8_t)(d7 + 1u);
		a6 += 0xF8u;
		a5 += 4u;
	} while (d7 < 0xAu);
}

void func_0090B0(uint16_t d6, uint32_t a3, uint32_t a6)
{
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 0x30u) << 1);
	mem_write8(a6 + 1u, mem_read8(a3 + d6));
	mem_write8(a6 + 0x81u, mem_read8(a3 + 1u + d6));
}

void func_0090C4(void)
{
	uint8_t d6 = 0;
	uint16_t d0 = 0, d5 = 0, d7 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;

	a5 = unk_063500_ADDRESS;
	a4 = 0x9186u;
	a3 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d7 = 0u;
	do
	{
		a6 = rom_009182 + d7 * 0x100u;
		a2 = a6;
		d0 = mem_read16(a5);
		while (d0 != 0u)
		{
			d6 = DATA8(a4 + d7);
			mem_write8(a6, d6);
			mem_write8(a6 + 0x80u, d6);
			d5 = (uint8_t)d0;
			d5 = (uint16_t)((d5 & 0xFu) << 1);
			mem_write8(a6 + 1u, DATA8(a3 + d5));
			mem_write8(a6 + 0x81u, DATA8(a3 + 1u + d5));
			d0 = d0 >> 4;
			a6 -= 4u;
		}
		d6 = DATA8(a4 + d7);
		mem_write8(a2 + 4u, d6);
		mem_write8(a2 + 6u, d6);
		mem_write8(a2 + 8u, d6);
		mem_write8(a2 + 0x84u, d6);
		mem_write8(a2 + 0x86u, d6);
		mem_write8(a2 + 0x88u, d6);
		mem_write8(a2 + 5u, mem_read8(a3 + 0x40u));
		mem_write8(a2 + 0x85u, DATA8(a3 + 0x41u));
		mem_write8(a2 + 7u, mem_read8(a3 + 0x48u));
		mem_write8(a2 + 0x87u, DATA8(a3 + 0x49u));
		mem_write8(a2 + 9u, mem_read8(a3 + 0x46u));
		mem_write8(a2 + 0x89u, DATA8(a3 + 0x47u));
		d7 = (uint8_t)(d7 + 1u);
		a5 += 2u;
	} while (d7 < 0xAu);
}

void func_00919C(void)
{
	unk_060003++;
}

void func_0091A4(uint8_t d7, uint32_t a6)
{
	if ((unk_060032 & 4u) != 0u || unk_0600A3 != 0u || (((uint8_t)d7 < 0x60u || (uint8_t)d7 > 0x6Bu) && unk_060092 != 0u))
	{
		func_0091D4(d7);
		return;
	}
}

void func_0091D4(uint8_t d7)
{
	uint32_t a6 = 0;

	a6 = unk_060018;
	mem_write8(a6, d7);
	a6++;
	if (a6 > 0x6043Fu)
		a6 = 0x60400u;
	unk_060018 = a6;
}

void func_0091F4(uint8_t d0)
{
	uint8_t d7 = 0;

	d7 = (uint8_t)d0;
	func_0091A4(d7, 0u);
}
