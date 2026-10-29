/**
 *    Name:        system/boot.c
 *    Description: the reset, the RAM and ROM tests, and the main loop that runs the jobs the frames queue
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_001000(void)
{
	uint32_t negative = 0;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	uint16_t d0_2 = 0, d1_2 = 0, d2_3 = 0, d4_3 = 0, d6 = 0, d7_2 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a6 = 0, d0_3 = 0, d1_3 = 0, d2_2 = 0, d3_2 = 0, d4_2 = 0, d5 = 0, d6_2 = 0, d7 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t19 = 0, t20 = 0, t21 = 0;
	uint32_t t2 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0;

	write_status(0x2600u);
	take_interrupts();
	io_write8(IO_0A0011, 0u);
	io_write8(UNMAPPED_10E801, 0x13u);
	io_write8(IO_0A0001, 0u);
	io_write8(SPRITE_CONTROL_140000, 0x10u);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106019, 0u);
	d1 = 0u;
	if ((io_read8(IO_0A0019) & 1u) == 0u)
	{
		d1 |= 1u;
		io_write8(SPRITE_CONTROL_140000, 0x18u);
	}
	io_write8(TILES_106D00, d1);
	write_status(0x2500u);
	take_interrupts();
	d7 = 0u;
	a2 = 0x16C4u;
	a0 = PALETTE_RAM;
	d0_2 = 0u;
	d7 = func_0017F6(d0_2, d7, a0, a2);
	a2 = 0x16C6u;
	a0 = TILE_RAM;
	d0_2 = 0x17u;
	d7 = func_0017A6(d0_2, d7, a0, a2);
	func_001708();
	a2 = 0x16C8u;
	a0 = 0x60000u;
	d0_2 = 0xFu;
	d7 = func_0017A6(d0_2, d7, a0, a2);
	d0_2 = 0x1000u;
	do
	{
		t1 = d0_2 - 1u;
		d0_2 = t1;
	} while (t1 != 0xFFFFu);
	a2 = 0x16CAu;
	a0 = SPRITE_RAM;
	d0_2 = 0u;
	d7 = func_0017A6(d0_2, d7, a0, a2);
	sum_program_chips();
	a2 = unk_060018_ADDRESS;
	a3 = 0x16F8u;
	d0_2 = 3u;
	do
	{
		d6 = mem_read16(a2);
		t2 = a3;
		a2 += 2u;
		a3 += 2u;
		if (d6 != DATA16(t2))
			d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 + 1u);
		d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 << 1);
		t3 = d0_2 - 1u;
		d0_2 = t3;
	} while (t3 != 0xFFFFu);
	unk_060010 = d7;
	d7 = func_001890(d7);
	if (d7 != 0u)
	{
		a0 = unk_060018_ADDRESS;
		a1 = 0x16E8u;
		d0_2 = 3u;
		do
		{
			a4 = DATA32(a1);
			d4_3 = mem_read16(a0);
			a1 += 4u;
			a0 += 2u;
			func_001782(d4_3, a4);
			t4 = d0_2 - 1u;
			d0_2 = t4;
		} while (t4 != 0xFFFFu);
	}
	d0_2 = 0x2Fu;
	if (d7 != 0u)
		d0_2 = 0x2Fu;
	do
	{
		d1_2 = 0x7FFFu;
		do
		{
			t5 = d1_2 - 1u;
			d1_2 = t5;
		} while (t5 != 0xFFFFu);
		io_write8(IO_0A0011, (uint8_t)d0_2);
		t6 = d0_2 - 1u;
		d0_2 = t6;
	} while (t6 != 0xFFFFu);
	if (d7 == 0u)
	{
		io_write8(SPRITE_CONTROL_140000, 0x10u);
		io_write16(TILES_106B00, 0u);
		io_write16(TILES_106E00, 0u);
		func_0010BC();
		func_004612();
		func_004604();
		ignored = func_0010D2();
		func_0010EE();
		a6 = 0xA01Eu;
		d7 = 1u;
		unk_060BFB = 0u;
		func_0093EE(a6, &ignored_2, &ignored_3, &d7, &ignored_4);
		a6 = TILE_RAM;
		d0 = 0u;
		d1 = 0x2Cu;
		d2 = 0x2Du;
		d3 = 0x2Eu;
		d4 = 0x2Fu;
		d6 = 0xFu;
		do
		{
			d7_2 = 0x1Fu;
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
				t7 = d7_2 - 1u;
				d7_2 = t7;
				a6++;
			} while (t7 != 0xFFFFu);
			t8 = d6 - 1u;
			d6 = t8;
			a6 += 0x80u;
		} while (t8 != 0xFFFFu);
		io_write8(IO_0A0011, d0);
		d0_2 = 0x80u;
		do
		{
			d1_2 = 0x3000u;
			do
			{
				t9 = d1_2;
				d1_2 = (uint16_t)(t9 - 1u);
			} while (t9 != 1u);
			io_write8(IO_0A0011, (uint8_t)d0_2);
			t10 = d0_2 - 1u;
			d0_2 = t10;
		} while (t10 != 0xFFFFu);
		a0 = 0x64000u;
		d7_2 = 0x1FFu;
		func_00114C(&d1_3, &d2_2, &d3_2, &d4_2, &d5, &d6_2, &a1, &a2);
		do
		{
			t11 = a0 - 4u;
			mem_write16(t11 + 2u, a2);
			mem_write16(t11, a2 >> 16);
			t12 = t11 - 4u;
			mem_write16(t12 + 2u, a1);
			mem_write16(t12, a1 >> 16);
			t13 = t12 - 4u;
			mem_write16(t13 + 2u, d6_2);
			mem_write16(t13, d6_2 >> 16);
			t14 = t13 - 4u;
			mem_write16(t14 + 2u, d5);
			mem_write16(t14, d5 >> 16);
			t15 = t14 - 4u;
			mem_write16(t15 + 2u, d4_2);
			mem_write16(t15, d4_2 >> 16);
			t16 = t15 - 4u;
			mem_write16(t16 + 2u, d3_2);
			mem_write16(t16, d3_2 >> 16);
			t17 = t16 - 4u;
			mem_write16(t17 + 2u, d2_2);
			mem_write16(t17, d2_2 >> 16);
			t18 = t17 - 4u;
			mem_write16(t18 + 2u, d1_3);
			mem_write16(t18, d1_3 >> 16);
			a0 = t18;
			t19 = d7_2 - 1u;
			d7_2 = t19;
		} while (t19 != 0xFFFFu);
		io_write8(IO_0A0011, (uint8_t)d0_2);
		unk_06001C = 0x60400u;
		unk_060018 = 0x60400u;
		unk_060BF0 = 0x60B00u;
		unk_060BF4 = 0x60B00u;
		unk_060BFA = 0u;
		unk_060BFB = 0u;
		unk_060BF8 = 0u;
		unk_060BF9 = 0u;
		unk_060BFC &= 0xFFFF0000u;
		unk_060BFC &= 0xFFFFu;
		a0 = 0x60380u;
		unk_060014 = 0x60380u;
		unk_060010 = 0x60380u;
		d0_3 = 0xFFFFFFFFu;
		d1_2 = 0x1Fu;
		do
		{
			mem_write32(a0, d0_3);
			t20 = d1_2 - 1u;
			d1_2 = t20;
			a0 += 4u;
		} while (t20 != 0xFFFFu);
		func_0082B8();
		unk_060030 = ~io_read8(IO_0A0011);
		unk_060031 = ~io_read8(IO_0A0013);
		unk_060032 = ~io_read8(IO_0A0019);
		d0 = 0u;
		d1_2 = unk_060030;
		d2_3 = (uint16_t)d1_2;
		d1_2 = d1_2 & 0xFu;
		unk_060091 = d0;
		d1_2 = (uint16_t)((uint32_t)d1_2 << 1);
		unk_060303 = rom_001452[d1_2];
		unk_060304 = rom_001453[d1_2];
		d2_3 = (d2_3 & ~0xFu) >> 3;
		unk_06030B = rom_001472[d2_3];
		unk_06030C = rom_001473[d2_3];
		d0_2 = unk_060031;
		unk_060090 = rom_001426[d0_2 & 3u];
		d0_2 = 0u;
		if ((unk_060031 & 4u) == 0u)
			d0_2 = (uint8_t)(d0_2 + 1u);
		unk_060093 = (uint8_t)d0_2;
		unk_06009F = 0u;
		d0_2 = unk_060031;
		d0_2 = d0_2 & 0x18u;
		a0 = 0x142Au + (uint16_t)(d0_2 + (d0_2 >> 2));
		unk_060095 = (uint8_t)DATA16(a0);
		a0 += 2u;
		unk_060096 = DATA32(a0);
		AT32(unk_06009A, -2) = mem_read32(a0 + 4u);
		unk_060094 = (unk_060031 & 0x60u) >> 5;
		unk_060092 = unk_060031 & 0x80u;
		d0 = 4u;
		if ((unk_060032 & 8u) != 0u)
			d0 = 6u;
		unk_0600B9 = d0;
		unk_060058 = 0u;
		io_write8(IO_0A0009, 0u);
		io_write8(IO_0A0001, 8u);
		d1 = 0u;
		d2 = 0u;
		if ((unk_060032 & 1u) != 0u)
		{
			d1 |= 7u;
			d2 |= 8u;
		}
		unk_060059 = d1;
		io_write8(PRIORITY_0C0001, d1);
		unk_06005A = d2;
		io_write8(SPRITE_CONTROL_140000, d2);
		write_status(0u);
		take_interrupts();
		unk_060058 |= 0x20u;
		io_write8(IO_0A0001, unk_060058);
		do
		{
			animate_fire_tiles(&d5, &d6_2);
			a0 = unk_060014;
			frame_wait();
			t21 = mem_read16(a0);
			negative = t21 >> 15;
			d1_2 = t21;
			take_interrupts();
		} while (negative);
		d7 = (uint8_t)d1_2;
		d1_2 = (d1_2 & 0x3F00u) >> 6;
		mem_write16(a0, 0xFFFFu);
		a0 += 2u;
		if (a0 > 0x603FFu)
			a0 = 0x60380u;
		unk_060014 = a0;
		a0 = TABLE32(indexed_table_of_32_bit_values_0013DE, d1_2);
		func_0013C0(d4_2, d5, d6_2, d7, a0);
		return;
	}
	for (;;)
	{
	}
}

void func_0010BC(void)
{
	io_write8(SPRITE_CONTROL_140001, 0u);
	io_write8(SPRITE_CONTROL_140003, 0u);
	io_write8(SPRITE_CONTROL_140002, 0u);
}

uint32_t func_0010D2(void)
{
	uint32_t d7 = 0;

	d7 = 0u;
	io_write8(TILES_106900, 0u);
	io_write8(TILES_106B00, 0u);
	io_write8(TILES_106E00, 0u);
	io_write8(TILES_106C00, 0u);
	return d7;
}

void func_0010EE(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d7 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	d0 = 0u;
	d1 = 0x10u;
	a0 = TILE_RAM;
	d7 = 0x7FFu;
	do
	{
		mem_write8(a0, d0);
		a0++;
		mem_write8(a0, d1);
		t1 = d7 - 1u;
		d7 = t1;
		a0++;
	} while (t1 != 0xFFFFu);
	io_write8(IO_0A0011, d0);
	a0 = TILE_RAM + 0x2000u;
	d7 = 0x1FFFu;
	do
	{
		mem_write8(a0, d0);
		a0++;
		mem_write8(a0, d1);
		t2 = d7 - 1u;
		d7 = t2;
		a0++;
	} while (t2 != 0xFFFFu);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106019, 0u);
	io_write8(IO_0A0011, 0u);
}

void func_00114C(uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_a1, uint32_t *p_a2)
{
	*p_d1 = 0u;
	*p_d2 = 0u;
	*p_d3 = 0u;
	*p_d4 = 0u;
	*p_d5 = 0u;
	*p_d6 = 0u;
	*p_a1 = 0u;
	*p_a2 = 0u;
}

uint32_t func_0013C0(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t negative = 0;
	uint16_t d1 = 0;
	uint32_t a0_2 = 0, ignored = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		switch (a0)
		{
		case 0x001A7Eu:
			d5 = func_001A7E(d4, d5, d6, d7);
			break;
		case 0x001E40u:
			func_001E40();
			break;
		case 0x001E42u:
			func_001E42((uint8_t)d7);
			break;
		case 0x001E98u:
			print_demo_text((uint16_t)d7);
			break;
		case 0x001EA2u:
			print_test_text((uint16_t)d7);
			break;
		case 0x001EACu:
			print_game_text((uint16_t)d7);
			break;
		case 0x001F0Au:
			func_001F0A((uint16_t)d7);
			break;
		case 0x001F2Au:
			func_001F2A((uint16_t)d7);
			break;
		case 0x001F3Au:
			d4 = func_001F3A(d4, d7);
			break;
		case 0x002098u:
			func_002098((uint8_t)d7);
			break;
		case 0x002102u:
			func_002102((uint8_t)d7);
			break;
		case 0x0022FEu:
			func_0022FE();
			break;
		case 0x002300u:
			d4 = func_002300((uint16_t)d7);
			break;
		case 0x002334u:
			func_002334();
			break;
		case 0x002336u:
			func_002336(d7, &ignored, &d4, &d5, &d6);
			break;
		case 0x002604u:
			func_002604();
			break;
		case 0x00263Cu:
			func_00263C(&d4, &d5, &d6, &d7);
			break;
		case 0x002818u:
			func_002818((uint8_t)d7, &d4, &d6);
			break;
		}
		do
		{
			animate_fire_tiles(&d5, &d6);
			a0_2 = unk_060014;
			frame_wait();
			t1 = mem_read16(a0_2);
			negative = t1 >> 15;
			d1 = t1;
			take_interrupts();
		} while (negative);
		d7 = (uint8_t)d1;
		d1 = (d1 & 0x3F00u) >> 6;
		mem_write16(a0_2, 0xFFFFu);
		a0_2 += 2u;
		if (a0_2 > 0x603FFu)
			a0_2 = 0x60380u;
		unk_060014 = a0_2;
		a0 = TABLE32(indexed_table_of_32_bit_values_0013DE, d1);
	}
}

void func_001708(void)
{
	uint8_t d3 = 0, d6 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a1 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a6 = PALETTE_RAM;
	d0 = 0xFu;
	do
	{
		a1 = table_loaded_by_lea_00191E_ADDRESS;
		d1 = 0xFu;
		do
		{
			mem_write8(a6 + 1u, DATA8(a1));
			a1++;
			mem_write8(a6 + 3u, DATA8(a1));
			a6 += 4u;
			t1 = d1 - 1u;
			d1 = t1;
			a1++;
		} while (t1 != 0xFFFFu);
		t2 = d0 - 1u;
		d0 = t2;
	} while (t2 != 0xFFFFu);
	a6 = PALETTE_RAM + 0x400u;
	d0 = 0x1FFu;
	d6 = 0u;
	do
	{
		mem_write8(a6 + 1u, d6);
		mem_write8(a6 + 3u, d6);
		a6 += 4u;
		t3 = d0 - 1u;
		d0 = t3;
	} while (t3 != 0xFFFFu);
	io_write8(IO_0A0011, (uint8_t)d0);
	a6 = TILE_RAM;
	d0 = 0x3FFu;
	do
	{
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x10u);
		a6++;
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x10u);
		t4 = d0 - 1u;
		d0 = t4;
		a6++;
	} while (t4 != 0xFFFFu);
	d3 = 0u;
	func_0018E2(d3);
}

void func_001782(uint16_t d4, uint32_t a4)
{
	uint16_t d5 = 0, d6 = 0;
	uint16_t t1 = 0;

	d5 = 3u;
	do
	{
		d6 = d4 & 0xFu;
		if (d6 >= 0xAu)
			d6 += 7u;
		a4--;
		mem_write8(a4, (uint8_t)d6);
		a4--;
		mem_write8(a4, 0u);
		d4 = d4 >> 4;
		t1 = d5 - 1u;
		d5 = t1;
	} while (t1 != 0xFFFFu);
}

uint32_t func_0017A6(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a2)
{
	uint8_t d1 = 0;
	uint16_t d2 = 0, d3 = 0;
	uint32_t a1 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	d7 = d7 << 2;
	d1 = 0u;
	for (;;)
	{
		a1 = a0;
		d2 = (uint16_t)d0;
		do
		{
			d3 = 0x1FFu;
			do
			{
				mem_write8(a1, d1);
				t1 = mem_read8(a1);
				(void)t1;
				if (t1 != d1)
					d7 = d7 | mem_read8(a2);
				mem_write8(a1 + 1u, d1);
				t2 = mem_read8(a1 + 1u);
				(void)t2;
				if (t2 != d1)
					d7 = d7 | mem_read8(a2 + 1u);
				t3 = d3 - 1u;
				d3 = t3;
				a1 += 2u;
			} while (t3 != 0xFFFFu);
			io_write8(IO_0A0011, (uint8_t)d0);
			t4 = d2 - 1u;
			d2 = t4;
		} while (t4 != 0xFFFFu);
		if (d1 == 0xFFu)
			break;
		d1 += 0x55u;
	}
	return d7;
}

uint32_t func_0017F6(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a2)
{
	uint16_t d2 = 0, d3 = 0;
	uint32_t a1 = 0, d1 = 0;
	uint16_t t1 = 0, t2 = 0;

	d7 = d7 << 2;
	d1 = 0u;
	for (;;)
	{
		a1 = a0;
		d2 = (uint16_t)d0;
		do
		{
			d3 = 0x3FFu;
			do
			{
				mem_write8(a1 + 1u, d1);
				if (mem_read8(a1 + 1u) != (uint8_t)d1)
					d7 = d7 | mem_read8(a2);
				mem_write8(a1 + 3u, d1);
				if (mem_read8(a1 + 3u) != (uint8_t)d1)
					d7 = d7 | mem_read8(a2 + 1u);
				a1 += 4u;
				t1 = d3 - 1u;
				d3 = t1;
			} while (t1 != 0xFFFFu);
			io_write8(IO_0A0011, (uint8_t)d0);
			t2 = d2 - 1u;
			d2 = t2;
		} while (t2 != 0xFFFFu);
		if (d1 == 0xFFu)
			break;
		d1 += 0x55u;
	}
	return d7;
}

void BOARD_ORIGINAL(sum_program_chips)(void)
{
	uint16_t d0 = 0, d2 = 0, d5 = 0, d6_2 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d6 = 0;
	uint16_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	a2 = unk_060018_ADDRESS;
	a0 = 0x16CCu;
	for (;;)
	{
		t1 = DATA32(a0);
		d6 = t1;
		a0 += 4u;
		if ((int32_t)t1 < 0)
			break;
		a1 = d6;
		d0 = (uint16_t)(DATA16(a0) - 1u);
		d6_2 = 0u;
		d5 = 0u;
		a0 += 2u;
		do
		{
			d2 = 0xFFFu;
			for (;;)
			{
				d5 = mem_read8(a1);
				if (d5 != mem_read8(a1))
					continue;
				d6_2 += d5;
				a1 += 2u;
				t2 = d2 - 1u;
				d2 = t2;
				if (t2 == 0xFFFFu)
					break;
			}
			io_write8(IO_0A0011, (uint8_t)d0);
			t3 = d0 - 1u;
			d0 = t3;
		} while (t3 != 0xFFFFu);
		mem_write16(a2, d6_2);
		a2 += 2u;
	}
}

uint32_t func_001890(uint32_t d7)
{
	uint32_t carry = 0;
	uint8_t d3 = 0;
	uint16_t d0 = 0, d5 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM;
	d0 = 0x3FFu;
	do
	{
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x10u);
		a6++;
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x10u);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
	d3 = 1u;
	func_0018E2(d3);
	d5 = 0xBu;
	d3 = 2u;
	d7 = d7 >> 1;
	d6 = d7;
	do
	{
		carry = d6 & 1u;
		d6 = d6 >> 1;
		if (carry)
			func_0018E2(d3);
		d3++;
		t2 = d5 - 1u;
		d5 = t2;
	} while (t2 != 0xFFFFu);
	return d7;
}

void func_0018E2(uint8_t d3)
{
	uint8_t d4 = 0;
	uint32_t a5 = 0, a6 = 0;

	a5 = indexed_table_of_32_bit_values_0015AC[d3 & 0x7Fu];
	for (;;)
	{
		a6 = TILE_RAM + 0x18u + (int16_t)mem_read16(a5);
		a5 += 2u;
		for (;;)
		{
			d4 = mem_read8(a5);
			a5++;
			if (d4 == 0x3Fu)
				return;
			if (d4 == 0x2Fu)
				break;
			mem_write8(a6, 0u);
			a6++;
			mem_write8(a6, (uint8_t)(d4 - 0x30u));
			a6++;
		}
	}
}
