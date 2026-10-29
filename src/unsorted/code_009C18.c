/**
 *    Name:        unsorted/code_009C18.c
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

void unreached_009C18(void)
{
	switch (unk_063408)
	{
	case 0:
		func_009C38();
		break;
	case 1:
		func_009C64();
		break;
	}
}

void func_009C38(void)
{
	uint32_t a5 = 0;

	a5 = table_loaded_by_lea_009C5C_ADDRESS;
	func_004184(a5);
	unk_063402 = 0u;
	unk_063403 = 0u;
	unk_063400(0) = 0u;
	unk_063401 = 0u;
	unk_063406 = 0u;
	unk_063404 = 0u;
	unk_063405 = 0u;
	unk_063405 = 1u;
	unk_063408++;
}

void func_009C64(void)
{
	uint8_t d0 = 0, d6 = 0;
	uint16_t d1 = 0, d2 = 0, d3 = 0, d7 = 0;
	uint32_t a0 = 0, a4 = 0, a6 = 0;
	uint8_t t1 = 0, t4 = 0;
	uint32_t t2 = 0, t3 = 0;

	if ((unk_0600A4 & 3u) != 0u)
		return;
	a0 = unk_063400_ADDRESS;
	func_009DD2(a0);
	func_009DBC(a0);
	unk_063405 = unk_063404;
	mem_write8(6u, io_read8(IO_0A0003));
	mem_write8(6u, ~mem_read8(6u));
	d0 = mem_read8(6u) & 0xFu;
	if ((d0 & 2u) == 0u)
	{
		if ((d0 & 1u) != 0u)
		{
			t1 = unk_063404;
			unk_063404 = t1 - 1u;
			if (t1 == 0u)
				unk_063404 = 5u;
		}
	}
	else
	{
		unk_063404++;
		if (unk_063404 >= 6u)
			unk_063404 = 0u;
	}
	if (unk_063404 >= 3u)
	{
		d7 = unk_063404;
		AS8(unk_063406) = rom_009F16[(uint8_t)(d7 - 3u)];
		a6 = func_009ED2(a0);
		d1 = (uint16_t)((uint32_t)mem_read8(a6 + 1u) << 8);
		d1 |= (uint8_t)(d1 + mem_read8(a6 + 3u));
		a4 = 0x9F0Au;
		d2 = (uint8_t)unk_063406;
		d2 = (uint8_t)((uint32_t)d2 << 2);
		d3 = (uint16_t)d1;
		if ((d0 & 4u) != 0u)
			d3 += DATA16(a4 + 2u + d2);
		if ((d0 & 8u) != 0u)
			d3 -= DATA16(a4 + 2u + d2);
		d1 = (uint16_t)((d1 & ~DATA16(a4 + d2)) + (d3 & DATA16(a4 + d2)));
		mem_write8(a6 + 3u, (uint8_t)d1);
		io_write8(PALETTE_08000F, (uint8_t)d1);
		d1 = d1 >> 8;
		mem_write8(a6 + 1u, (uint8_t)d1);
		io_write8(PALETTE_08000D, (uint8_t)d1);
		return;
	}
	a6 = indexed_table_of_8_bit_values_009D40_ADDRESS;
	d7 = unk_063404;
	if (unk_063401 != 3u)
	{
		d7 = (uint8_t)(d7 + 3u);
		if (unk_063402 >= 8u)
			unk_063402 = 7u;
	}
	d6 = DATA8(a6 + d7);
	d7 = unk_063404;
	d7 = (uint8_t)(d7 + 1u);
	if ((d0 & 8u) == 0u)
	{
		if ((d0 & 4u) != 0u)
		{
			t2 = a0 + d7;
			mem_write8(t2, mem_read8(t2) + 1u);
			if (d6 < unk_063400(d7))
				unk_063400(d7) = 0u;
		}
	}
	else
	{
		t3 = a0 + d7;
		t4 = mem_read8(t3);
		mem_write8(t3, t4 - 1u);
		if (t4 == 0u)
			unk_063400(d7) = d6;
	}
}

void func_009DBC(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = func_009ED2(a0);
	io_write8(PALETTE_08000D, mem_read8(a6 + 1u));
	io_write8(PALETTE_08000F, mem_read8(a6 + 3u));
}

void func_009DD2(uint32_t a0)
{
	uint8_t d3 = 0;
	uint16_t d1 = 0, d7 = 0;
	uint32_t a6 = 0;

	a6 = rom_009F1A;
	d7 = unk_063401;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F1E[d7]);
	a6 = rom_009F22;
	d7 = unk_063402;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F46[d7]);
	a6 = rom_009F26;
	d7 = unk_063403;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F46[d7]);
	a6 = rom_009F2A;
	d1 = (uint16_t)((uint32_t)io_read8(PALETTE_08000D) << 8);
	d1 |= (uint8_t)(d1 + io_read8(PALETTE_08000F));
	d3 = (uint8_t)d1;
	func_009EA2(d3, a6);
	d1 = d1 >> 5;
	d3 = (uint8_t)d1;
	a6 += 6u;
	func_009EA2(d3, a6);
	d3 = (uint8_t)(d1 >> 5);
	a6 += 6u;
	func_009EA2(d3, a6);
	d7 = unk_063404;
	if (d7 != unk_063405)
	{
		a6 = rom_009F2E[d7 & 0x3FFFu];
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, 0x1Fu);
		a6 = rom_009F2E[unk_063405];
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, 0x10u);
	}
}

void func_009EA2(uint8_t d3, uint32_t a6)
{
	uint8_t d2 = 0, d3_2 = 0;

	d2 = 0u;
	d3 &= 0x1Fu;
	if ((d3 & 0x10u) != 0u)
		d2++;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d2);
	d3_2 = rom_009F46[d3 & 0xFu];
	mem_write8(a6 + 2u, 0u);
	mem_write8(a6 + 3u, d3_2);
}

uint32_t func_009ED2(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_009EFA[unk_063401] + (uint16_t)((uint32_t)unk_063402 << 6) + (uint16_t)((uint32_t)unk_063403 << 2);
	return a6;
}

void func_00DF7E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_00DF9E(a0, p_d6, p_d7);
		return;
	case 4:
		*p_d7 = func_00DFF6(*p_d7, a0);
		return;
	case 8:
		func_00E020(a0, p_d6, p_d7, p_a5);
		return;
	}
}

void func_00DF9E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x182D0u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 8u));
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	d7 = (uint16_t)(d7 << 1);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + d7);
	a6 = rom_00EC9C;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_d6 = d6;
	*p_d7 = d7;
}

uint32_t func_00DFF6(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(unk_061314) == 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		d7 = (d7 & ~0xFFu) | 0xB0u;
		func_0091A4((uint8_t)d7, 0u);
		a6 = rom_00ECA0;
		set_animation(0u, a0, a6);
	}
	return d7;
}

void func_00E020(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	unk_06131C = 0u;
	mem_write8(a0, mem_read8(a0) | 6u);
	d0 = 0u;
	func_00E4CA(d0, a0, p_d6, p_d7, p_a5);
}

void func_00E03C(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0, d7 = 0;

	func_00E7D0(a0, &d5, p_d6);
	if (mem_read8(a0 + 5u) == 3u)
	{
		d7 = mem_read8(a0 + 5u);
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			func_00E092(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 4:
			func_00E0AC(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 8:
			func_00E0C6(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 12:
			func_00E0E0(a0, &d5, p_d6, &d7, p_a5);
			break;
		}
	}
	else
	{
		func_00E866(a0, &d0, &d5, p_d6);
		if ((uint8_t)d0 == 0u)
		{
			d7 = mem_read8(a0 + 5u);
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				func_00E092(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 4:
				func_00E0AC(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 8:
				func_00E0C6(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 12:
				func_00E0E0(a0, &d5, p_d6, &d7, p_a5);
				break;
			}
		}
		else
		{
			d7 = 0x10u;
			func_048448(a0, p_d6, &d7);
			if ((uint8_t)d7 < 7u)
			{
				d7 = mem_read8(a0 + 5u);
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					func_00E092(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 4:
					func_00E0AC(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 8:
					func_00E0C6(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 12:
					func_00E0E0(a0, &d5, p_d6, &d7, p_a5);
					break;
				}
			}
			else
			{
				mem_write8(a0 + 0x2Eu, d0);
				d7 = 2u;
				func_048448(a0, p_d6, &d7);
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 8:
					d7 = func_00E5F2(d7, a0);
					break;
				case 0:
					d7 = func_00E624(d7, a0);
					break;
				case 4:
					func_00E66E(a0);
					break;
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_00E092(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t t1 = 0;

	a6 = func_00E718_ADDRESS;
	func_00E0F0(a0, a6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 == 0u)
	{
		d0 = 1u;
		func_00E116(d0, a0, &d5, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_00E0AC(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t t1 = 0;

	a6 = func_00E718_ADDRESS;
	func_00E0F0(a0, a6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 == 0u)
	{
		d0 = 2u;
		func_00E116(d0, a0, &d5, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_00E0C6(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t t1 = 0;

	a6 = func_00E708_ADDRESS;
	func_00E0F0(a0, a6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 == 0u)
	{
		d0 = 3u;
		func_00E116(d0, a0, &d5, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_00E0E0(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	d0 = 4u;
	func_00E116(d0, a0, &d5, p_d6, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_00E0F0(uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
	{
		switch (a6)
		{
		case 0x00E708u:
			func_00E708(a0, &d7_2, p_a5);
			break;
		case 0x00E718u:
			func_00E718(a0, &d7_2, p_a5);
			break;
		}
	}
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = func_00E826(a0);
	*p_d7 = d7_2;
}

void func_00E116(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	func_00E8D0(a0, &d5, &d7);
	if ((uint8_t)d7 != 0u)
	{
		d7 = 8u;
		func_048448(a0, p_d6, &d7);
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 32:
			d7 = func_00E5F2(d7, a0);
			break;
		case 0:
		case 12:
		case 24:
			func_00E686(a0);
			break;
		case 4:
		case 16:
		case 28:
			func_00E69E(a0);
			break;
		case 8:
		case 20:
			func_00E6D0(a0);
			break;
		}
	}
	else
		func_00E4CA(d0, a0, p_d6, &d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_00E124(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = 0, d7 = 0;

	func_00E7D0(a0, &d5, p_d6);
	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		func_00E148(a0, p_d6, &d7, p_a5);
		break;
	case 4:
		d7 = func_00E152(d7, a0);
		break;
	case 8:
		func_00E182(a0, p_d6, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void func_00E148(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 5u, 0u);
		d0 = 6u;
		func_00E4CA(d0, a0, p_d6, p_d7, p_a5);
	}
}

uint32_t func_00E152(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x33u, mem_read8(a0 + 0x33u) + 1u);
		mem_write8(a0, mem_read8(a0) & ~2u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = rom_00ECD0;
		set_animation(0u, a0, a6);
		unk_06131B = 1u;
		d7 = func_00EB8C(d7, a0);
	}
	return d7;
}

void func_00E182(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (unk_06131B != 0u)
		return;
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 4u, 1u);
	mem_write8(a0 + 5u, 0u);
	d0 = 6u;
	func_00E4CA(d0, a0, p_d6, p_d7, p_a5);
}

void func_00E1A8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = 0, d7 = 0;

	func_00E7D0(a0, &d5, p_d6);
	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		func_00E1CC(a0, p_d6, &d7, p_a5);
		break;
	case 4:
		func_00E1E4(a0);
		break;
	case 8:
		func_00E200(a0, p_d6, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void func_00E1CC(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~2u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		d0 = 4u;
		for (;;)
		{
			a6 = 0x62A00u;
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			func_01830C(&d7, &a6);
			if ((uint8_t)d7 == 0u)
				break;
			func_00EA20(a0, a6, p_d6, p_a5);
			d7 = d0 * 2u;
			mem_write8(a6 + 0x30u, d7);
			mem_write8(a6 + 0x31u, 0u);
			t1 = d0 - 1u;
			d0 = t1;
			if (t1 == 0xFFFFu)
			{
				mem_write8(a6 + 0x31u, mem_read8(a6 + 0x31u) | 0x80u);
				break;
			}
		}
		if ((uint8_t)d0 != 4u)
		{
			d7 = (d7 & ~0xFFFFu) | 0x1Bu;
			func_0091A4((uint8_t)d7, a6);
		}
	}
	*p_d7 = d7;
}

void func_00E1E4(uint32_t a0)
{
	if (unk_06131A == 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x30u, 0x14u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

void func_00E200(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 5u, 0u);
		d0 = 7u;
		func_00E4CA(d0, a0, p_d6, p_d7, p_a5);
	}
}

uint32_t func_00E21A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Du, 0x80u);
	mem_write8(a0 + 0x42u, 0xFFu);
	t1 = mem_read8(a0 + 0x24u);
	mem_write8(a0 + 0x24u, t1 - 1u);
	if (t1 != 1u)
	{
		mem_write8(a0 + 8u, 0xAu);
		if (mem_read8(a0 + 0x24u) == 1u)
			mem_write8(a0 + 8u, 1u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0, mem_read8(a0) & ~2u);
		d7_2 = (d7 & ~0xFFu) | 0x82u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = rom_00ECB8;
		set_animation(0u, a0, a6);
		return d7_2;
	}
	a6 = rom_00ECCC;
	set_animation(0u, a0, a6);
	d7 &= ~0xFFu;
	func_0091A4((uint8_t)d7, a6);
	d7 |= 0x8Eu;
	func_0091A4((uint8_t)d7, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	mem_write8(a0 + 5u, 0u);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 0x30u, 0u);
	mem_write8(a0, mem_read8(a0) & ~6u);
	return d7;
}

void func_00E2A8(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (mem_read8(a0 + 0x24u) < 0x14u)
		mem_write8(a0 + 0x42u, 6u);
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 5u, 0u);
	mem_write8(a0 + 0x2Du, 0u);
	mem_write8(a0 + 0x2Au, 0xCu);
	mem_write8(a0 + 0x42u, 0xFFu);
	d0 = 6u;
	func_00E4CA(d0, a0, p_d6, p_d7, p_a5);
}

void func_00E2DC(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_00E300(a0);
		return;
	case 4:
		func_00E316(a0);
		return;
	case 8:
		func_00E330(a0, p_d6, p_d7, p_a5);
		return;
	case 12:
		*p_d7 = func_00E366(*p_d7, a0);
		return;
	}
}

void func_00E300(uint32_t a0)
{
	mem_write8(a0 + 0x30u, 0x8Cu);
	mem_write32(a0 + 0x3Au, 0xF66Cu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_00E316(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = rom_00ECBC;
		set_animation(0u, a0, a6);
	}
}

void func_00E330(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
		d7 = func_00E46A(a0);
	mem_write8(a0 + 0x30u, 0xEu);
	mem_write8(a0 + 5u, 3u);
	a6 = 0x62780u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
		func_010EE8(a0, a6, p_d6, &d7_2, p_a5);
	else
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
	}
	*p_d7 = d7_2;
}

void unreached_00E364(void)
{
}

uint32_t func_00E366(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		d7 = func_00E46A(a0);
	}
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) + 1u);
		if (mem_read8(a0 + 0x2Fu) == 0xAu)
		{
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			mem_write8(a0 + 5u, 0u);
		}
	}
	return d7;
}

void func_00E39C(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		func_00E3C4(d0, a0, &d5, &d6, &d7);
		break;
	case 4:
		d7 = func_00E3F6(d7, a0);
		break;
	case 8:
		d7 = func_00E416(d7, a0);
		break;
	case 12:
		d7 = func_00E44A(d7, a0);
		break;
	case 16:
		func_00E45E(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_00E3C4(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t None = *p_d7;
	uint16_t d0_2 = 0, d1 = 0, d2 = 0;
	uint32_t a6 = 0;

	a6 = rom_00ECC0;
	set_animation(0u, a0, a6);
	*p_d7 = 0xB0u;
	func_0091A4((uint8_t)*p_d7, a6);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
	d2 = mem_read16(a0 + 0xEu);
	d1 = (uint16_t)(mem_read16(a0 + 0xCu) + 0x10u);
	func_030014(d0_2, d1, d2, &d5, &d6, p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_00E3F6(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return func_00E46A(a0);
	a6 = rom_00ECC4;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Eu, 0x280u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_00E416(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - d7_2);
	t1 = mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x1Eu, t1 - 0x20u);
	if (t1 < 0x20u)
	{
		d7_2 = (d7_2 & ~0xFFFFu) | 0x11u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = rom_00ECC8;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 0x1Eu, 0x500u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
	return d7_2;
}

uint32_t func_00E44A(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + d7_2);
	if (mem_read16(a0 + 0x10u) >= 0xF000u)
	{
		func_00E45E(a0);
		return d7_2;
	}
	return d7_2;
}

void func_00E45E(uint32_t a0)
{
	unk_06120C--;
	func_01832A(a0);
}

uint32_t func_00E46A(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = unk_0600A4;
	d7 = d7 & 0x3Eu;
	d7 = indexed_table_of_16_bit_values_00E48A[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x4000u);
	mem_write16(a0 + 0x10u, d7);
	return d7;
}

void func_00E4CA(uint32_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t a6 = 0, d6_2 = 0, d7 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	d7 = 0x10u;
	func_048448(a0, &d6, &d7);
	d6_2 = (d6 & ~0xFFFFu) | 3u;
	a6 = table_loaded_by_lea_00E4FE_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6_2);
		t2 = d7;
		d7 = (d7 & ~0xFFu) | (uint8_t)(t2 - t1);
		if (t2 < t1)
			break;
		t3 = d6_2 - 1u;
		d6_2 = (d6_2 & ~0xFFFFu) | t3;
		if (t3 == 0xFFFFu)
		{
			d6_2 = 2u;
			break;
		}
	}
	d6_2 = (d6_2 & ~0xFFFFu) | (uint16_t)(d6_2 << 2);
	switch ((uint32_t)(int16_t)d6_2)
	{
	case 0:
		func_00E58E(a0, &d6_2, &d7, p_a5);
		break;
	case 4:
		func_00E5BE(a0, &d6_2, &d7);
		break;
	case 8:
		func_00E5D8(a0, &d6_2, &d7);
		break;
	case 12:
		d7 = func_00E5F2(d7, a0);
		break;
	}
	*p_d6 = d6_2;
	*p_d7 = d7;
}

void func_00E58E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0, ignored = 0;

	func_011DFA(a0, &ignored, &d6, &d7, p_a5);
	if ((uint8_t)d7 == 0u)
		d7 = func_00E5F2(d7, a0);
	else
	{
		unk_06131C = 0u;
		d7 = 8u;
		func_00E6EC(a0, &d6, &d7);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write16(a0 + 4u, 0x100u);
		a6 = rom_00ECA4;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_00E5BE(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_00E6EC(a0, &d6, p_d7);
	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x101u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_00E5D8(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_00E6EC(a0, &d6, p_d7);
	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x102u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_00E5F2(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x103u);
	if (unk_06131C == 0u)
	{
		unk_06131C = 1u;
		d7 = (d7 & ~0xFFFFu) | 0x8Fu;
		func_0091A4((uint8_t)d7, 0u);
	}
	a6 = rom_00ECB4;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_00E624(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
	if ((int8_t)mem_read8(a0 + 0x2Eu) >= 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
	}
	mem_write8(a0 + 0x2Eu, 0u);
	d7_2 = (d7 & ~0xFFu) | 8u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_00ECA8;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_00E66E(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 2u);
	mem_write16(a0 + 4u, 0x300u);
	a6 = rom_00ECAC;
	if (mem_read8(a0 + 0x24u) < 0x1Eu)
		a6 = rom_00ECD4;
	set_animation(0u, a0, a6);
}

void func_00E686(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 1u);
	mem_write16(a0 + 4u, 0x300u);
	a6 = rom_00ECAC;
	if (mem_read8(a0 + 0x24u) < 0x1Eu)
		a6 = rom_00ECD4;
	set_animation(0u, a0, a6);
}

void func_00E69E(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x300u);
	a6 = rom_00ECAC;
	if (mem_read8(a0 + 0x24u) < 0x1Eu)
		a6 = rom_00ECD4;
	set_animation(0u, a0, a6);
}

void func_00E6D0(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06131C = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x201u);
	a6 = rom_00ECB0;
	set_animation(0u, a0, a6);
}

void func_00E6EC(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x31u, indexed_table_of_8_bit_values_00E700[*p_d7]);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_00E708(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, d7 = 0;

	func_0184D2(a0, &d0, p_a5);
	a6 = 0xE790u;
	d7 = func_00E724((uint16_t)d0, d7, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_00E718(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, d7 = 0;

	func_0184D2(a0, &d0, p_a5);
	a6 = indexed_table_of_16_bit_values_00E750_ADDRESS;
	d7 = func_00E724((uint16_t)d0, d7, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

uint32_t func_00E724(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	d0 = (uint16_t)((uint32_t)d0 << 2);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a6 + d0);
	mem_write16(a0 + 0x1Au, d7_2);
	d7_2 = (d7_2 & ~0xFFFFu) | mem_read16(a6 + 2u + d0);
	mem_write16(a0 + 0x1Cu, d7_2);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int16_t)mem_read16(a0 + 0x1Au) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	return d7_2;
}

void func_00E7D0(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6)
{
	uint8_t d5 = 0, d6 = 0, d7 = 0;
	uint8_t t1 = 0;

	d5 = 6u;
	d6 = 0xFFu;
	if (mem_read8(a0 + 0x2Au) != 0u)
	{
		t1 = mem_read8(a0 + 0x2Au);
		mem_write8(a0 + 0x2Au, t1 - 1u);
		if (t1 == 1u)
			mem_write8(a0, mem_read8(a0) | 2u);
	}
	if (mem_read8(a0 + 0x24u) < 0x1Eu)
	{
		d7 = 0x3Cu;
		if (mem_read8(a0 + 0x24u) < 0x14u)
		{
			d7 = 8u;
			if (mem_read8(a0 + 0x24u) < 0xAu)
				d7 = 1u;
		}
		mem_write8(a0 + 0x42u, d6);
		if ((d7 & (uint8_t)unk_0600A4) == 0u)
			mem_write8(a0 + 0x42u, d5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
}

uint32_t func_00E826(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0;

	d7 = func_0182EE(a0);
	if (mem_read32(a0 + 0x16u) >= 0x8000u)
		mem_write32(a0 + 0x16u, 0x8000u);
	if (mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
		mem_write32(a0 + 0x16u, func_001000_ADDRESS);
	if ((int16_t)mem_read16(a0 + 0xCu) < 0)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x800u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	return d7;
}

void func_00E866(uint32_t a0, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d6)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d0 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a6 = unk_0620F0_ADDRESS;
	d6 = 3u;
	d0 = 0u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u && (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) == 0u && mem_read8(a6 + 4u) != 4u)
		{
			t1 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
			d5 = t1;
			if ((int16_t)t1 < 0)
				d5 = (uint16_t)~d5;
			if (d5 < 0xBu)
			{
				t2 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d0 = d0 | 0x80u;
					d5 = (uint16_t)~d5;
				}
				if (d5 < 0x3Au)
				{
					d0 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
		}
		d0 = 0u;
		t3 = d6 - 1u;
		d6 = t3;
		a6 -= 0x50u;
	} while (t3 != 0xFFFFu);
	*p_d0 = d0;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
}

void func_00E8D0(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a6 = unk_0620F0_ADDRESS;
	d6 = 3u;
	d7 = 0u;
	for (;;)
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) == 0u || (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) != 0u || mem_read8(a6 + 4u) == 4u)
		{
			t1 = d6 - 1u;
			d6 = t1;
			a6 -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		t2 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
		d5 = t2;
		if ((int16_t)t2 < 0)
			d5 = (uint16_t)~d5;
		if (d5 >= 0xBu)
		{
			t1 = d6 - 1u;
			d6 = t1;
			a6 -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			t3 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
			d5 = t3;
			if ((int16_t)t3 < 0 || d5 < 0x3Eu)
			{
				t1 = d6 - 1u;
				d6 = t1;
				a6 -= 0x50u;
				if (t1 == 0xFFFFu)
					break;
				continue;
			}
			d7 |= shl32(1u, (int)(d6 & 0x1Fu));
			break;
		}
		t4 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
		d5 = t4;
		if ((int16_t)t4 < 0)
		{
			d5 = (uint16_t)~d5;
			if (d5 >= 0x3Eu)
			{
				d7 |= shl32(1u, (int)(d6 & 0x1Fu));
				break;
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 0x50u;
		if (t1 == 0xFFFFu)
			break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
}

void func_00E962(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write16(a0 + 0x42u, 0x800u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	a6 = rom_015E02;
	set_animation(0u, a0, a6);
	unk_061314 = a0;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_00E992(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	d7_2 = (d7 & ~0xFFFFu) | 0x16u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_015E06;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

void func_00E9B6(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_01832A(a0);
}

void func_00EA20(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t a5 = 0, d6 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x6700u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write8(a6 + 0x2Fu, 0u);
	a5 = indexed_table_of_16_bit_values_00EA9E_ADDRESS;
	d7 = mem_read8(a0 + 0x2Fu);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		d7 = (uint8_t)(d7 + 3u);
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
	}
	d7 = (uint16_t)((uint32_t)d7 << 2);
	d6 = (int16_t)DATA16(a5 + d7);
	t1 = mem_read32(a6 + 0x12u) + d6;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	d6 = (d6 & ~0xFFFFu) | DATA16(a5 + 2u + d7);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + d6);
	t2 = mem_read32(a6 + 0x16u) - 0x200u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write32(a6 + 0x20u, a0);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a6, mem_read8(a6) | 0x40u);
	mem_write8(a6 + 3u, mem_read8(a0 + 0x2Fu));
	mem_write16(a6 + 4u, 0u);
	unk_06131A++;
	*p_d6 = d6;
	*p_a5 = a5;
}

uint32_t func_00EAB6(uint32_t a0)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x182DAu;
	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	d7 = (uint16_t)((uint32_t)mem_read8(a0 + 3u) << 2);
	mem_write16(a0 + 0x1Au, indexed_table_of_16_bit_values_00EB1E[d7 / 2u]);
	mem_write16(a0 + 0x1Eu, rom_00EB20[d7 / 2u]);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
	}
	d7_2 = mem_read8(a0 + 3u);
	d7_2 = (uint16_t)(d7_2 << 2);
	a6 = animations_00F760[d7_2 / 4u];
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

void func_00EB2A(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		unk_06131A--;
	}
}

uint32_t func_00EB3E(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	d7 = func_0182EE(a0);
	if ((int16_t)mem_read16(a0 + 0x10u) >= 0)
		return d7;
	if (mem_read8(a0 + 0x31u) != 0u)
	{
		mem_write16(a0 + 0x10u, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = rom_00F76C;
		set_animation(0u, a0, a6);
		return d7;
	}
	func_01832A(a0);
	return d7;
}

void func_00EB70(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_01832A(a0);
}

uint32_t func_00EB8C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	a6 = 0x62780u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x6600u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write8(a6 + 0x2Fu, 0u);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x4500u;
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		d7_2 = (int16_t)~d7_2;
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
	}
	t1 = mem_read32(a6 + 0x12u) + d7_2;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	t2 = mem_read32(a6 + 0x16u) - 0x200u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write16(a6 + 0x10u, 0x3200u);
	mem_write32(a6 + 0x20u, a0);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a6 + 4u, 0u);
	return d7_2;
}

void func_00EBFE(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x182E4u;
	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x1Au, 0x680u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
	{
		mem_write8(a0, mem_read8(a0) & 0xBFu);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
	}
	a6 = animations_00F674;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_00EC4C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		a6 = rom_00F678;
		set_animation(0u, a0, a6);
		d7 = (d7 & ~0xFFu) | 6u;
		func_0091A4((uint8_t)d7, a6);
		mem_write8(a0, mem_read8(a0) | 4u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7;
}

uint32_t func_00EC76(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		unk_06131B = 0u;
		func_01832A(a0);
		return d7;
	}
	d7_2 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7_2;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	return d7_2;
}

void func_00F8DA(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x182B2u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x2Fu, 3u);
}

uint32_t func_00F8F2(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint8_t t1 = 0;

	d7 = mem_read8(a0 + 0x2Fu);
	d7 = (uint16_t)(d7 << 1);
	d7 = indexed_table_of_16_bit_values_00F938[d7 / 2u];
	if (mem_read16(a0 + 0xCu) <= d7)
	{
		a6 = 0x62140u;
		d7 = IN_PAGE(d7, 8u);
		d7 = (uint8_t)d7;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			func_00F94C(a0, a6);
			t1 = mem_read8(a0 + 0x2Fu) - 1u;
			mem_write8(a0 + 0x2Fu, t1);
			if ((int8_t)t1 < 0)
			{
				func_01832A(a0);
				return d7;
			}
		}
	}
	return d7;
}

void func_00F94C(uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x6000u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write16(a6 + 4u, 0u);
}

void func_00F96A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x1829Eu;
	func_0180E0(a0, a6);
	a6 = rom_015D68;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_00F98E(uint32_t d7, uint32_t a0)
{
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - 0x480u);
	if (mem_read16(a0 + 0x10u) < 0x3000u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write16(a0 + 0x10u, 0x3000u);
		mem_write16(a0 + 0x1Au, 0x1E0u);
		mem_write16(a0 + 0x1Cu, 0xFE20u);
		mem_write16(a0 + 0x1Eu, 0x400u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write32(a0 + 0x3Au, 0x16660u);
		d7 = (d7 & ~0xFFu) | 0x24u;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0, mem_read8(a0) | 4u);
	}
	return d7;
}

uint32_t func_00F9DC(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x60u);
	if ((int16_t)mem_read16(a0 + 0x16u) < 0)
	{
		func_01832A(a0);
		return d7;
	}
	if ((int8_t)mem_read8(a0 + 0x10u) < 0)
	{
		mem_write16(a0 + 0x1Eu, 0x400u);
		mem_write16(a0 + 0x10u, 0u);
		d7 = (d7 & ~0xFFu) | 0x24u;
		func_0091A4((uint8_t)d7, 0u);
	}
	return d7;
}

uint32_t func_00FA00(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	mem_write16(a0 + 0x10u, 0u);
	d7_2 = (d7 & ~0xFFu) | 0x24u;
	func_0091A4((uint8_t)d7_2, 0u);
	return d7_2;
}

void func_00FA1C(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x182BCu;
	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) | 4u);
	a6 = rom_015EC2;
	if (mem_read8(a0 + 3u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 0x80u);
		a6 = rom_015EBE;
	}
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_00FA5A(uint32_t a0)
{
	func_01831E(a0);
}

void func_00FA68(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x182C6u;
	func_0180E0(a0, a6);
	a6 = rom_015EEA;
	if (mem_read8(a0 + 3u) != 0u)
		a6 = rom_015EEE;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_00FA9A(uint32_t a0)
{
	func_01831E(a0);
}

void func_00FAAC(uint32_t a0)
{
	uint32_t a6 = 0;

	func_00FB8A(a0);
	mem_write16(a0 + 0x42u, 0x900u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x182A8u;
	func_0180E0(a0, a6);
	a6 = rom_015D68;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_00FADC(uint32_t d7, uint32_t a0)
{
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	func_00FB8A(a0);
	t1 = mem_read32(a0 + 0x12u) + 0x480u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t2 - 0x480u);
	if (t2 < 0x480u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x1Au, 0x3C0u);
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Eu, 0x4E0u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write32(a0 + 0x3Au, 0x16660u);
		mem_write8(a0 + 0x30u, 0x32u);
		d7 = (d7 & ~0xFFu) | 0x24u;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0, mem_read8(a0) | 4u);
	}
	return d7;
}

uint32_t func_00FB34(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t t1 = 0;

	func_00FB8A(a0);
	d7 = func_0182EE(a0);
	if (mem_read8(a0 + 0x30u) != 0u)
	{
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 1u)
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	}
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if (mem_read16(a0 + 0xCu) >= 0x1A0u)
	{
		func_01832A(a0);
		return d7;
	}
	if ((int8_t)mem_read8(a0 + 0x10u) < 0)
	{
		mem_write16(a0 + 0x1Eu, 0x4E0u);
		mem_write16(a0 + 0x10u, 0u);
		d7 = (d7 & ~0xFFu) | 0x24u;
		func_0091A4((uint8_t)d7, 0u);
	}
	return d7;
}

void func_00FB8A(uint32_t a0)
{
	uint32_t t1 = 0, t2 = 0;

	t1 = mem_read32(a0 + 0x12u) + 0x400u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) - 0x400u;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
}

void func_00FBB4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6 = record_0180FA_ADDRESS;
	func_0180E0(a0, a6);
	a6 = rom_01443E;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_00FBD8(uint32_t a0)
{
	func_01831E(a0);
}

uint32_t func_00FBDE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
		return d7;
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write16(a0 + 0x30u, 0u);
		return d7;
	}
	a6 = 0x62140u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	return func_00FC00(d7_2, a0, a6);
}

uint32_t func_00FC00(uint32_t d7, uint32_t a0, uint32_t a6)
{
	if ((uint8_t)d7 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write16(a0 + 0x30u, 0u);
		return d7;
	}
	d7 = func_00FCD0(d7, a0, a6);
	mem_write8(a0 + 0x30u, 4u);
	return d7;
}

uint32_t func_00FC1C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 8u) == 0u)
	{
		unk_061300 = 0u;
		a6 = rom_014446;
		if ((int8_t)mem_read8(a0 + 7u) < 0)
		{
			a6 = rom_01444A;
			unk_061300 = 1u;
		}
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, 2u);
		mem_write8(a0 + 0x30u, 0u);
		mem_write8(a0 + 0x31u, 4u);
		a6 = 0x18104u;
		func_0180E0(a0, a6);
		d7_2 = (d7 & ~0xFFu) | 5u;
		func_0091A4((uint8_t)d7_2, a6);
		mem_write8(a0, mem_read8(a0) & ~6u);
		return d7_2;
	}
	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x28u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014442;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_00FCA6(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 0x30u, 8u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

uint32_t func_00FCD0(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x2100u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x2000u;
	if (unk_061300 != 0u)
		d7_2 = (int16_t)~d7_2;
	t1 = mem_read32(a6 + 0x12u) + d7_2;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	mem_write16(a6 + 0x10u, 0xA00u);
	mem_write8(a6 + 0x2Fu, 0u);
	if (mem_read8(a0 + 0x31u) != 3u)
		mem_write8(a6 + 0x2Fu, 1u);
	if (mem_read8(a0 + 0x31u) == 0u)
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) + 1u);
	if (unk_061300 != 0u)
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
	mem_write16(a6 + 4u, 0u);
	return d7_2;
}

uint32_t func_00FD3A(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, 0x85u);
	a6 = 0x1810Eu;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0x580u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
	{
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
	}
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	d7 = mem_read8(a0 + 0x2Fu);
	d7 = d7 & 3u;
	d7 = (uint16_t)(d7 << 2);
	a6 = rom_0144E8[d7 / 4u];
	set_animation(0u, a0, a6);
	d7 = 0xEu;
	func_0091A4((uint8_t)d7, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7;
}

uint32_t func_00FDA4(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0;

	func_01831E(a0);
	d7 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	return d7;
}

void func_00FDF2(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x18276u;
	func_00FE02(a0, a6);
}

void func_00FDFC(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x18118u;
	func_00FE02(a0, a6);
}

void func_00FE02(uint32_t a0, uint32_t a6)
{
	uint32_t a6_2 = 0;

	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6_2 = 0x1452Au;
	if (mem_read8(a0 + 2u) != 0x22u)
	{
		a6_2 = 0x1456Au;
		if (mem_read8(a0 + 2u) != 0x59u)
			a6_2 = 0x15AF6u;
	}
	a6_2 = DATA32(a6_2);
	set_animation(0u, a0, a6_2);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_00FE44(uint32_t a0)
{
	func_01831E(a0);
}

uint32_t func_00FE4C(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0;

	func_01831E(a0);
	d7 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	return d7;
}

uint32_t func_00FE5E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x1456Au;
	mem_write16(a0 + 0x1Au, 0x500u);
	return func_00FE8A(d7, a0, a6);
}

uint32_t func_00FE6E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x15AF6u;
	mem_write16(a0 + 0x1Au, 0x600u);
	return func_00FE8A(d7, a0, a6);
}

uint32_t func_00FE7E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x1452Au;
	mem_write16(a0 + 0x1Au, 0x400u);
	return func_00FE8A(d7, a0, a6);
}

uint32_t func_00FE8A(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t a6_2 = 0, d7_2 = 0;

	if ((int8_t)mem_read8(a0 + 7u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
	}
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6_2 = mem_read32(a6 + 4u);
	set_animation(0u, a0, a6_2);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, a6_2);
	mem_write8(a0 + 4u, 2u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0, mem_read8(a0) | 4u);
	return d7_2;
}

void func_00FEE2(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint32_t t1 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	d7 = 0x1C0u;
	mem_write8(a0, mem_read8(a0) | 0x40u);
	if ((int8_t)mem_read8(a0 + 3u) >= 0)
	{
		d7 = (uint16_t)~d7;
		mem_write8(a0, mem_read8(a0) & 0xBFu);
	}
	mem_write16(a0 + 0x1Au, d7);
	mem_write8(a0 + 3u, mem_read8(a0 + 3u) & 0x7Fu);
	t1 = mem_read32(a0 + 0x12u) - indexed_table_of_32_bit_values_00FF60[mem_read8(a0 + 3u)];
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	a6 = rom_0145A0;
	mem_write8(a0 + 4u, 3u);
	if (mem_read16(a0 + 0x10u) != 0u)
	{
		a6 = rom_014598;
		mem_write8(a0 + 4u, 1u);
		mem_write16(a0 + 0x1Eu, 0x500u);
	}
	set_animation(0u, a0, a6);
	func_00FFFA(a0, &d6, p_d7);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_00FF70(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - d7_2);
	if (mem_read16(a0 + 0x10u) < 0x1800u)
	{
		a6 = rom_01459C;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 0x30u, 0x40u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7_2;
}

void func_00FFA0(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint32_t a6 = 0, d6_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
		return;
	a6 = rom_0145A0;
	set_animation(0u, a0, a6);
	func_00FFFA(a0, &d6_2, p_d7);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6_2 & 0xFFFFu);
}

uint32_t func_00FFBE(uint32_t d7, uint32_t a0)
{
	func_01831E(a0);
	return func_00FFC4(d7, a0);
}

uint32_t func_00FFC0(uint32_t d7, uint32_t a0)
{
	return func_00FFC4(d7, a0);
}

uint32_t func_00FFC4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		d7_2 = (int16_t)mem_read16(a0 + 0x1Au);
		t2 = mem_read32(a0 + 0x12u) + d7_2;
		mem_write16(a0 + 0x14u, t2);
		mem_write16(a0 + 0x12u, t2 >> 16);
		return d7_2;
	}
	a6 = rom_01459C;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0x32u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 0x30u, 0x40u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
	return d7_2;
}

uint32_t func_00FFE0(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x32u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0 + 0x30u, 0x40u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
	return d7_2;
}

void func_00FFFA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x30u, indexed_table_of_8_bit_values_010012[*p_d7]);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_010026(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x18122u;
	func_0180E0(a0, a6);
	a6 = rom_0145FC;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0xFFC0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_010058(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	d7 = func_010086(a0);
	if (mem_read16(a0 + 0xCu) >= 0xC0u)
		return d7;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7 = (d7 & ~0xFFu) | 0x12u;
	func_0091A4((uint8_t)d7, 0u);
	a6 = rom_014600;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_010080(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_010086(a0);
	return d7;
}

uint32_t func_010086(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0;

	func_01831E(a0);
	d7 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	return d7;
}

void func_0100AC(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6 = 0x18172u;
	func_0180E0(a0, a6);
	a6 = rom_01461A;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0xFE00u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_0100D4();
}

void func_0100D4(void)
{
}

uint32_t func_0100D6(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_010086(a0);
	return d7;
}

uint32_t func_0100DA(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 4u, 1u);
	d7_2 = (d7 & ~0xFFFFu) | 0xBAu;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_01461E;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_010108(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = indexed_table_of_32_bit_values_010148[mem_read8(a0 + 3u)];
	func_0180E0(a0, a6);
	d7 = mem_read8(a0 + 3u);
	d7 = (uint16_t)(d7 << 2);
	a6 = rom_014636[d7 / 4u];
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x2Fu, 0u);
	return d7;
}

void func_010158(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d0_2 = 0, d2 = 0;
	uint32_t a6 = 0, d1 = 0, d7_2 = 0;

	if (mem_read16(a0 + 0xCu) < 0x170u && mem_read8(a0 + 0x2Fu) == 0u)
	{
		mem_write8(a0 + 0x2Fu, 1u);
		d7 = (d7 & ~0xFFFFu) | 0xB7u;
		func_0091A4((uint8_t)d7, 0u);
		d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
		d1 = (uint16_t)(mem_read16(a0 + 0xCu) - 0xCu);
		d2 = (uint16_t)(mem_read16(a0 + 0xEu) - 0x20u);
		if (d2 >= 0x300u)
			d2 = 0u;
		func_030054(d0_2, d1, d2, a0, &d5, &d6, &d7);
	}
	func_01831E(a0);
	if ((mem_read8(a0) & 8u) != 0u)
	{
		d7_2 = (uint8_t)(4u + mem_read8(a0 + 3u));
		d7_2 = (uint16_t)(d7_2 << 2);
		a6 = rom_014636[d7_2 / 4u];
		set_animation(d1, a0, a6);
		mem_write8(a0, mem_read8(a0) & ~4u);
		d7 = 0x19u;
		func_0091A4((uint8_t)d7, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_0101DC(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_01832A(a0);
}

uint32_t func_0101F8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	a6 = rom_01480E;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFFFu) | unk_0600A4;
	d7_2 = LINKED(d7_2, d7_2 & 6u);
	mem_write16(a0 + 0x20u, indexed_table_of_16_bit_values_010232[(uint16_t)d7_2 / 2u]);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_01023A(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x20u);
	if ((uint16_t)d7_2 < mem_read16(a0 + 0xCu))
		return d7_2;
	d0 = 0u;
	a6 = unk_0623C0_ADDRESS;
	d7_2 = (d7_2 & ~0xFFu) | 0xCu;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d7_2 = func_010306(d0, d7_2, a0, a6);
		d0 = 1u;
		a6 = unk_0623C0_ADDRESS;
		d7_2 = (d7_2 & ~0xFFu) | 0xCu;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
		func_01830C(&d7_2, &a6);
		if ((uint8_t)d7_2 != 0u)
			d7_2 = func_010306(d0, d7_2, a0, a6);
	}
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write16(a0 + 0x1Eu, 0x480u);
	t1 = mem_read32(a0 + 0x16u) - 0x1000u;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	t2 = mem_read32(a0 + 0x12u) + 0x1000u;
	mem_write16(a0 + 0x14u, t2);
	mem_write16(a0 + 0x12u, t2 >> 16);
	a6 = 0x1812Cu;
	func_0180E0(a0, a6);
	a6 = rom_014812;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_0102BC(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	t1 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t1 - d7_2);
	if ((uint16_t)d7_2 <= t1)
		return d7_2;
	mem_write16(a0 + 0x10u, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0x3Eu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_0102E0(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x18854u;
	d7 &= ~0xFFFFu;
	draw_tile_block((uint16_t)d7, a6);
	func_01832A(a0);
	return d7;
}

uint32_t func_010306(uint8_t d0, uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x2A00u);
	mem_write16(a6 + 0x42u, 0x600u);
	func_018574(a0, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x2000u;
	if (d0 != 0u)
		d7_2 = (int16_t)~d7_2;
	t1 = mem_read32(a6 + 0x12u) + d7_2;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	t2 = mem_read32(a6 + 0x16u) + 0x100u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, 0u);
	if (d0 != 0u)
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
	unk_06120C++;
	mem_write16(a6 + 4u, 0u);
	return d7_2;
}

void func_010354(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, 0x81u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x30u, 0x28u);
	a6 = rom_014860;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_010398(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 1u)
		return;
	a6 = rom_014864;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Cu, 0x100u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_0103C0(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	d7 = (int16_t)mem_read16(a0 + 0x1Cu);
	t1 = mem_read32(a0 + 0x16u) - d7;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	d7 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	t2 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t2 - d7);
	if (t2 < (uint16_t)d7)
	{
		a6 = rom_014868;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 0x10u, 0u);
		mem_write8(a0 + 0x30u, 0x14u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7;
}

void func_0103F2(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write32(a0, 0x81000B00u);
		mem_write16(a0 + 4u, 0u);
		unk_06120C--;
		return;
	}
}

void func_01042C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6 = 0x1815Eu;
	func_0180E0(a0, a6);
	a6 = rom_01488A;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_010450(uint32_t a0)
{
	func_01831E(a0);
}

uint32_t func_010458(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 1u)
		return d7;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x1Eu);
	a6 = rom_014896;
	set_animation(0u, a0, a6);
	a6 = 0x62140u;
	d7 = (d7 & ~0xFFu) | 8u;
	d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
	func_01830C(&d7, &a6);
	if ((uint8_t)d7 == 0u)
		return d7;
	mem_write16(a6, 0x500u);
	mem_write16(a6 + 2u, 0x3300u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	t2 = mem_read32(a6 + 0x16u) - 0x200u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	d7_2 = (d7 & ~0xFFu) | 0x13u;
	func_0091A4((uint8_t)d7_2, a6);
	return d7_2;
}

void func_010490(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) & ~6u);
		a6 = 0x1815Eu;
		func_0180E0(a0, a6);
		a6 = rom_01489A;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 2u, 0x2D00u);
		mem_write16(a0 + 4u, 0u);
	}
}

uint32_t func_0104C2(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 8u) == 0u)
	{
		d7_2 = (d7 & ~0xFFu) | 5u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = rom_014892;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, 2u);
		mem_write8(a0 + 0x30u, 0x3Cu);
		mem_write8(a0, mem_read8(a0) & ~6u);
		return d7_2;
	}
	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x28u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_01488E;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_010520(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

void func_010554(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write32(a0 + 0x3Au, 0x16660u);
	a6 = 0x1817Cu;
	func_0180E0(a0, a6);
	a6 = rom_014A26;
	set_animation(0u, a0, a6);
	if ((int8_t)mem_read8(a0 + 3u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	func_010796(a0, &d6, p_d7);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01059E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t t1 = 0;

	func_0106F6(a0, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 0x30u, 0u);
		mem_write8(a0 + 0x31u, 4u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

void func_0105BC(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	func_0106F6(a0, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_010796(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	a6 = 0x62A00u;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	*p_d7 = (*p_d7 & ~0xFFFFu) | (uint8_t)*p_d7;
	func_01830C(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_010796(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	func_0107C0(a0, a6);
	mem_write8(a0 + 0x30u, 3u);
}

void func_010602(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_010622(a0, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_01064C(a0);
		return;
	case 8:
		func_01066E(a0);
		return;
	}
}

void func_010622(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0 + 0x30u, 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x62780u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		*p_d6 = 0u;
		*p_a5 = rom_010EAE_ADDRESS;
		d7_2 = rom_010EAE[mem_read8(a0 + 0x2Fu)];
		func_010ED0(a0, a6, p_d6, &d7_2);
		d7_2 = mem_read8(a0 + 0x2Fu);
		d7_2 = d7_2 & 3u;
		d7_2 = indexed_table_of_8_bit_values_010EAA[d7_2];
		func_0091A4((uint8_t)d7_2, a6);
	}
	else
		mem_write8(a0 + 5u, 2u);
	*p_d7 = d7_2;
}

void func_01064C(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) + 1u);
		if (mem_read8(a0 + 0x2Fu) == 7u)
			mem_write8(a0 + 5u, 2u);
	}
}

void func_01066E(uint32_t a0)
{
	func_01831E(a0);
}

uint32_t func_010674(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 8u) == 0u)
	{
		a6 = 0x18186u;
		func_0180E0(a0, a6);
		a6 = rom_014A2E;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, 3u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write8(a0, mem_read8(a0) & ~6u);
		return d7;
	}
	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x28u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014A2A;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_0106D6(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t t1 = 0;

	func_0106F6(a0, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

void func_0106F6(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	func_01831E(a0);
	d7 = mem_read8(a0 + 3u) & 3u;
	a6 = table_loaded_by_lea_010776_ADDRESS + (uint16_t)(d7 << 3);
	d7_2 = mem_read8(a0 + 0x2Fu);
	d7_2 = (uint16_t)((d7_2 & 1u) << 2);
	*p_d6 = (int16_t)DATA16(a6 + d7_2);
	d7 = (int16_t)DATA16(a6 + 2u + d7_2);
	t1 = mem_read32(a0 + 0x12u) + *p_d6;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) + d7;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	if ((mem_read8(a0 + 3u) & 0x40u) != 0u)
	{
		if (mem_read32(a0 + 0x16u) >= 0x7000u || mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
			mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) ^ 1u);
	}
	else if (mem_read32(a0 + 0x16u) >= 0x7000u || mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) ^ 1u);
	*p_d7 = d7;
}

void func_010796(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 4u;
	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x30u, indexed_table_of_8_bit_values_0107AE[*p_d7]);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0107C0(uint32_t a0, uint32_t a6)
{
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x2C00u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write16(a6 + 4u, 0u);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + 0x800u);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a6 + 0x2Fu, 1u);
		t1 = mem_read32(a6 + 0x12u) + 0x2000u;
		mem_write16(a6 + 0x14u, t1);
		mem_write16(a6 + 0x12u, t1 >> 16);
		return;
	}
	mem_write8(a6 + 0x2Fu, 0u);
	t2 = mem_read32(a6 + 0x12u) - 0x2000u;
	mem_write16(a6 + 0x14u, t2);
	mem_write16(a6 + 0x12u, t2 >> 16);
}

uint32_t func_01080A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, 0x85u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	a6 = 0x16668u;
	if (unk_060121 == 8u)
		a6 = 0x16670u;
	mem_write32(a0 + 0x3Au, a6);
	a6 = 0x18190u;
	func_0180E0(a0, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0xF800u;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if (mem_read8(a0 + 0x2Fu) != 0u)
	{
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)~d7_2;
		mem_write8(a0, mem_read8(a0) | 0x40u);
	}
	mem_write16(a0 + 0x1Au, d7_2);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6 = rom_014AA2;
	set_animation(0u, a0, a6);
	d7_2 = (d7_2 & ~0xFFu) | 0xBu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_010880(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint32_t t1 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_01832A(a0);
		return d7;
	}
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
		a6 = rom_014AA6;
		set_animation(0u, a0, a6);
		return d7;
	}
	d7_2 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7_2;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	return d7_2;
}

void func_0108B6(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_0108D4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write16(a0 + 0x42u, 0x700u);
	a6 = 0x1819Au;
	func_0180E0(a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = rom_0156FE;
	set_animation(0u, a0, a6);
}

void func_0108FC(uint32_t a0)
{
	if (mem_read16(a0 + 0xCu) < 0x140u)
	{
		func_01090C(a0);
		return;
	}
	func_01831E(a0);
}

void func_01090C(uint32_t a0)
{
	mem_write32(a0, 0x81000300u);
	mem_write16(a0 + 4u, 0u);
}

void func_01092E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6 = 0x18280u;
	func_0180E0(a0, a6);
	a6 = rom_015B36;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_010952(uint32_t a0)
{
	func_01831E(a0);
}

void func_010958(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
	{
		func_010970();
		return;
	}
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
	func_010970();
}

void func_010970(void)
{
}

uint32_t func_010972(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = rom_015B36_ADDRESS;
	if ((int8_t)mem_read8(a0 + 7u) < 0)
	{
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
		a6 += 4u;
	}
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6 = DATA32(a6 + 4u);
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, 2u);
	mem_write16(a0 + 8u, 0x1001u);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	return d7_2;
}

void func_0109D2(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	a6 = rom_0156F0;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_0109F8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint32_t ignored = 0;
	uint16_t t1 = 0;

	*p_d7 = mem_read8(a0 + 0x2Fu);
	t1 = *p_d7 << 2;
	zero = t1 == 0u;
	*p_d7 = t1;
	switch (*p_d7)
	{
	case 12:
		func_007902(zero, &ignored, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_010A1A(a0, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_010AD0(a0);
		return;
	case 8:
		func_010AD4(a0);
		return;
	}
}

void func_010A1A(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	func_01831E(a0);
	a6 = indexed_table_of_32_bit_values_010AB2[mem_read8(a0 + 3u)];
	d7 = mem_read8(a6);
	a6++;
	do
	{
		d0 = mem_read8(a6);
		*p_d6 = 3u;
		a5 = unk_0620F0_ADDRESS;
		a6++;
		do
		{
			if ((unk_0600A1 & shl32(1u, (int)(*p_d6 & 7u))) != 0u && mem_read8(a5 + 4u) != 4u)
			{
				t1 = mem_read16(a5 + 0xCu);
				t2 = mem_read16(a0 + 0xCu);
				d5 = (uint16_t)(t2 - t1);
				if (t1 <= t2 && d5 < 0x40u)
				{
					t3 = mem_read16(a5 + 0xEu);
					t4 = mem_read16(a0 + 0xEu) - d0;
					d5 = (uint16_t)(t4 - t3);
					if (t4 < t3)
						d5 = (uint16_t)~d5;
					if (d5 < 8u)
					{
						a6 = 0x62140u;
						d7 = (d7 & ~0xFFu) | 8u;
						d7 = (uint8_t)d7;
						func_01830C(&d7, &a6);
						if ((uint8_t)d7 != 0u)
						{
							a5 = func_010AF0(d0, a0, a6);
							mem_write8(a0 + 0x2Fu, 1u);
						}
						*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
						*p_d7 = d7;
						*p_a5 = a5;
						return;
					}
				}
			}
			t5 = *p_d6 - 1u;
			*p_d6 = t5;
			a5 -= 0x50u;
		} while (t5 != 0xFFFFu);
		t6 = d7 - 1u;
		d7 = t6;
	} while (t6 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
	*p_a5 = a5;
}

void func_010AD0(uint32_t a0)
{
	func_01831E(a0);
}

void func_010AD4(uint32_t a0)
{
	func_01831E(a0);
}

uint32_t func_010AF0(uint32_t d0, uint32_t a0, uint32_t a6)
{
	uint32_t a5 = 0;
	uint32_t t1 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x2E00u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x16u) - (uint16_t)(d0 << 8);
	mem_write16(a6 + 0x18u, t1);
	mem_write16(a6 + 0x16u, t1 >> 16);
	a5 = a0 + 0x2Fu;
	mem_write32(a6 + 0x20u, a5);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	return a5;
}

void func_010B22(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181AEu;
	func_0180E0(a0, a6);
	a6 = rom_014AD6;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 0x30u, 0x15u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_010B4A(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write8(a0 + 0x30u, 0xAu);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
		return;
	}
}

uint32_t func_010B6A(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		return func_010B86(d7, a0);
	case 4:
		func_010BB6(a0);
		return d7;
	}
}

uint32_t func_010B86(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 1u)
		return d7;
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 0x30u, 0x3Cu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0x1Fu;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014ADA;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_010BB6(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) & ~6u);
	mem_write8(a0 + 0x30u, 0x15u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 5u, 0u);
	a6 = rom_014ADE;
	set_animation(0u, a0, a6);
}

void func_010BE0(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		func_01832A(a0);
		mem_write8(mem_read32(a0 + 0x20u), 0u);
		return;
	}
}

void func_010BF8(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0, mem_read8(a0) & ~6u);
	mem_write8(a0 + 0x30u, 0u);
	mem_write8(mem_read32(a0 + 0x20u), 2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014AE2;
	set_animation(0u, a0, a6);
	a6 = 0x62780u;
	d7_2 = (d7_2 & ~0xFFu) | 8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		*p_d6 = 0u;
		d7_2 = func_001000_ADDRESS;
		func_010ED0(a0, a6, p_d6, &d7_2);
		d7_2 = (d7_2 & ~0xFFu) | 0x11u;
		func_0091A4((uint8_t)d7_2, a6);
	}
	*p_d7 = d7_2;
}

void func_010C46(uint32_t a0)
{
	func_01831E(a0);
}

void func_010C56(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0, 1u);
	a6 = 0x181C2u;
	func_0180E0(a0, a6);
	*p_a5 = indexed_table_of_8_bit_values_010D5A_ADDRESS;
	func_010D48(a0, *p_a5, &d6, p_d7);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_010C76(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	func_01831E(a0);
	if (mem_read8(a0) == 0u)
		return d7;
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
		return d7;
	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 0x30u, 0x3Cu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFFFu) | 0x20u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014BA0;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_010CB2(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint8_t t1 = 0;

	func_01831E(a0);
	if (mem_read8(a0) != 0u)
	{
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 0u)
		{
			mem_write8(a0 + 4u, 0u);
			func_010C56(a0, &d6, p_d7, p_a5);
		}
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_010CDA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0, 1u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	*p_a5 = 0x10D62u;
	func_010D48(a0, *p_a5, &d6, p_d7);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_010CFA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	func_01831E(a0);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		*p_a5 = 0x10D62u;
		func_010D48(a0, *p_a5, &d6, &d7_2);
		a6 = 0x62A00u;
		d7 = (d7_2 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			func_010D7A(a0, a6);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			mem_write8(a0 + 0x2Fu, 0u);
		}
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_010D36(uint32_t a0)
{
	if (mem_read8(a0 + 0x2Fu) != 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		mem_write8(a0 + 0x2Fu, 0u);
	}
}

void func_010D48(uint32_t a0, uint32_t a5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x30u, mem_read8(a5 + *p_d7));
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_010D7A(uint32_t a0, uint32_t a6)
{
	uint32_t t1 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x3A00u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x16u) - 0x1000u;
	mem_write16(a6 + 0x18u, t1);
	mem_write16(a6 + 0x16u, t1 >> 16);
	mem_write32(a6 + 0x20u, a0);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
}

uint32_t func_010DA8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x181EAu;
	func_0180E0(a0, a6);
	a6 = rom_0150E8;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0x1Bu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

void func_010DD4(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x30u, 0x30u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

uint32_t func_010DE8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	d7 = func_010E2C(d7, a0);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		a6 = rom_0150EC;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0, mem_read8(a0) | 0x80u);
	}
	return d7;
}

void func_010E0C(uint32_t a0)
{
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(mem_read32(a0 + 0x20u) + 0x2Fu, 1u);
		func_01832A(a0);
		return;
	}
	t1 = mem_read32(a0 + 0x16u) - 0x1000u;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
}

uint32_t func_010E2C(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	if ((d7_2 & 1u) == 0u)
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
	return d7_2;
}

void func_010E50(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	unk_061302 = a0;
	a6 = rom_01519C;
	set_animation(0u, a0, a6);
}

void func_010E76(void)
{
}

void func_010ED0(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x3100u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_01104A(a0, a6, p_d6, p_d7);
}

void func_010EE8(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t d6 = 0, d7_2 = 0;

	d7 = (uint16_t)((uint32_t)mem_read8(a0 + 0x2Fu) << 2);
	d6 = indexed_table_of_16_bit_values_010F1C[d7 / 2u];
	d7 = rom_010F1E[d7 / 2u];
	d6 = func_010F80(d6, d7, a0, a6);
	*p_a5 = rom_010F44_ADDRESS;
	d7_2 = mem_read8(a0 + 0x2Fu);
	d7_2 = d7_2 & 1u;
	d7_2 = rom_010F44[d7_2];
	func_0091A4((uint8_t)d7_2, a6);
	*p_d6 = d6;
	*p_d7 = d7_2;
}

uint32_t func_010F80(uint32_t d6, uint32_t d7, uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x3200u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_01104A(a0, a6, &d6, &d7);
	return d6;
}

void unreached_010FEE(uint32_t a0, uint32_t a6)
{
	uint8_t d7_2 = 0;
	uint16_t d6 = 0, d7 = 0;

	d6 = 0u;
	d7 = 0u;
	func_011000(d6, d7, a0, a6);
	d7_2 = 0x11u;
	func_0091A4(d7_2, a6);
}

void func_011000(uint32_t d6, uint32_t d7, uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x500u);
	mem_write16(a6 + 2u, 0x3100u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_01104A(a0, a6, &d6, &d7);
}

void func_01104A(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = *p_d6;
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6 + 0x10u, mem_read16(a0 + 0x10u));
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + d7);
	mem_write32(a6 + 0x12u, mem_read32(a0 + 0x12u));
	d6 = (int16_t)d6;
	t1 = mem_read32(a6 + 0x12u) + d6;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	mem_write32(a6 + 0x16u, mem_read32(a0 + 0x16u));
	d7_2 = mem_read16(a0 + 0x34u);
	d7_2 = (uint16_t)(d7_2 << 8);
	d7_2 = (uint16_t)(d7_2 + 0x200u);
	t2 = mem_read32(a6 + 0x16u) - d7_2;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	*p_d6 = d6;
	*p_d7 = d7_2;
}

void func_0110A8(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = rom_014C3A;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x18168u;
	func_0180E0(a0, a6);
}

void func_0110B2(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = rom_014C86;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x18168u;
	func_0180E0(a0, a6);
}

void func_0110BC(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = rom_014D1C;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x18168u;
	func_0180E0(a0, a6);
}

void func_0110C6(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = rom_015258;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x18168u;
	func_0180E0(a0, a6);
}

void func_0110D0(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = rom_015AA0;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x18168u;
	func_0180E0(a0, a6);
}

void func_0110F4(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_011116(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	if ((mem_read8(a0 + 3u) & 1u) != 0u)
		mem_write8(a0, mem_read8(a0) | 4u);
	a6 = 0x18258u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	unk_061310 = 0u;
	a6 = rom_015838;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_01115A(uint32_t d7, uint32_t a0)
{
	d7 = func_011276(d7, a0);
	if ((int8_t)mem_read8(a0 + 3u) < 0 && mem_read16(a0 + 0xCu) < 0x160u)
		unk_061310 = 1u;
	if (unk_061310 == 1u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 0x30u, 0xAu);
	}
	return d7;
}

uint32_t func_011190(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	d7 = func_011276(d7, a0);
	if (mem_read8(a0 + 3u) != 0u)
	{
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 0u)
			unk_061310 = 2u;
	}
	if (unk_061310 == 2u)
	{
		mem_write16(a0 + 0x1Eu, 0x600u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	func_01831E(a0);
	return d7;
}

uint32_t func_0111C6(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7 = func_011276(d7, a0);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - d7_2);
	if (mem_read16(a0 + 0x10u) < 0x1800u)
	{
		mem_write16(a0 + 0x10u, 0x1800u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		if (mem_read8(a0 + 3u) != 0u)
		{
			mem_write8(a0 + 0x30u, 0x28u);
			unk_061310 = 3u;
			d7_2 = (d7_2 & ~0xFFu) | 0x24u;
			func_0091A4((uint8_t)d7_2, 0u);
		}
	}
	return d7_2;
}

uint32_t func_011208(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	d7 = func_011276(d7, a0);
	if (mem_read8(a0 + 3u) != 0u)
	{
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 0u)
			unk_061310 = 4u;
	}
	if (unk_061310 == 4u)
	{
		mem_write16(a0 + 0x1Eu, 0x300u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	func_01831E(a0);
	return d7;
}

uint32_t func_01123E(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7 = func_011276(d7, a0);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + d7_2);
	if (mem_read16(a0 + 0x10u) >= 0x8000u)
	{
		mem_write16(a0 + 0x10u, 0x8000u);
		mem_write8(a0 + 4u, 2u);
		if (mem_read8(a0 + 3u) != 0u)
		{
			mem_write8(a0 + 0x30u, 0x1Eu);
			unk_061310 = 0u;
		}
	}
	return d7_2;
}

uint32_t func_011276(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		mem_write8(a0, mem_read8(a0) ^ 4u);
	return d7_2;
}

void func_01129C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x30u, 0x28u);
	mem_write8(a0 + 0x31u, 0xCu);
	a6 = rom_0157A0;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x2Fu, 0u);
}

void func_0112DA(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	func_01831E(a0);
	if (mem_read8(a0) == 0u)
		func_011374(a0);
	else
	{
		func_011378(a0, p_d6, &d7);
		if (mem_read8(a0 + 0x30u) != 0u)
		{
			mem_write8(a0 + 0x30u, mem_read8(a0 + 0x30u) - 1u);
			func_01831E(a0);
		}
		else
		{
			func_0113C6(a0, &d5, p_d6, &d7);
			if ((uint8_t)d7 != 0u)
			{
				d0 = (uint8_t)d7;
				a6 = 0x62A00u;
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				func_01830C(&d7, &a6);
				if ((uint8_t)d7 != 0u)
				{
					func_01144A(d0, a0, a6);
					mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
					mem_write8(a0, mem_read8(a0) | 0x80u);
					a6 = rom_0157A4;
					set_animation(0u, a0, a6);
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_01133A(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_01831E(a0);
	if (mem_read8(a0) == 0u)
	{
		func_011374(a0);
		return;
	}
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	mem_write8(a0 + 0x30u, 0x64u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 == 0u)
	{
		func_011374(a0);
		return;
	}
	a6 = rom_0157A0;
	set_animation(0u, a0, a6);
}

void func_011374(uint32_t a0)
{
	func_01832A(a0);
}

void func_011378(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	d7 = mem_read8(a0 + 0x2Fu);
	d7 = (uint16_t)((d7 & 1u) << 2);
	*p_d6 = (int16_t)indexed_table_of_16_bit_values_0113BE[d7 / 2u];
	*p_d7 = (int16_t)rom_0113C0[d7 / 2u];
	t1 = mem_read32(a0 + 0x12u) + *p_d6;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) + *p_d7;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	if (mem_read32(a0 + 0x16u) >= 0x4000u || mem_read32(a0 + 0x16u) < 0x800u)
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) ^ 1u);
}

void func_0113C6(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a6 = unk_0620F0_ADDRESS;
	d6 = 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u && (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) == 0u && mem_read8(a6 + 4u) != 4u)
		{
			t1 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
			d5 = t1;
			if ((int16_t)t1 < 0)
				d5 = (uint16_t)~d5;
			if (d5 < 4u)
			{
				d7 = 0u;
				t2 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d5 = (uint16_t)~d5;
					d7 = 0x80u;
				}
				if (d5 >= 0x30u)
				{
					d7 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
		}
		d7 = 0u;
		t3 = d6 - 1u;
		d6 = t3;
		a6 -= 0x50u;
	} while (t3 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_d7 = d7;
}

void func_01144A(uint8_t d0, uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x5000u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write16(a6 + 4u, 0u);
	mem_write8(a6 + 0x2Fu, 0u);
	if ((int8_t)d0 >= 0)
	{
		mem_write8(a6 + 0x2Fu, 1u);
		mem_write8(a6, mem_read8(a6) | 0x40u);
	}
}

uint32_t func_01147E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x86u);
	a6 = 0x1824Eu;
	func_0180E0(a0, a6);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
	mem_write16(a0 + 0x1Eu, 0x200u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = rom_01579C;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0xEu;
	func_0091A4((uint8_t)d7_2, a6);
	return d7_2;
}

uint32_t func_0114C6(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	if (mem_read16(a0 + 0x10u) < 0x2000u)
		return d7;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7 = (d7 & ~0xFFFFu) | 0xFB80u;
	if (mem_read8(a0 + 0x2Fu) != 0u)
		d7 = (d7 & ~0xFFFFu) | (uint16_t)~d7;
	mem_write16(a0 + 0x1Au, d7);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	return d7;
}

uint32_t func_0114F6(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	func_01831E(a0);
	return d7;
}

void func_0114FE(uint32_t a0)
{
	func_01832A(a0);
}

uint32_t func_011502(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_014C3A;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_011528(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_01154E(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		func_011576(a0, p_d6, &d7);
		break;
	case 4:
		d7 = func_0115EC(d7, a0);
		break;
	case 8:
		func_011616(a0);
		break;
	case 12:
		func_01163C(d0, a0, &d5, p_d6, &d7);
		break;
	case 16:
		func_011688(a0, p_d6, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void func_011576(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181CCu;
	func_0180E0(a0, a6);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 8u));
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	mem_write8(a0 + 0x2Bu, d7);
	d7 = (uint16_t)(d7 << 1);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + d7);
	a6 = rom_014DA0[0];
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 0x2Du, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x26u, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	unk_06120C++;
	unk_061313 = 0u;
	unk_06131D = 0u;
	*p_d6 = d6;
	*p_d7 = d7;
}

uint32_t func_0115EC(uint32_t d7, uint32_t a0)
{
	if (unk_063380 >= 0x6E000u)
	{
		d7 = 0xFEu;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x30u, 0x50u);
	}
	return d7;
}

void func_011616(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = rom_014DA4;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 0x1Eu, 0xF800u);
		mem_write16(a0 + 0x1Cu, 0x200u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_01163C(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0_2 = 0, d1 = 0, d2 = 0;
	uint32_t d7 = 0;

	d7 = func_011F94(a0);
	if (mem_read16(a0 + 0x10u) == 0u)
	{
		d7 = (d7 & ~0xFFFFu) | 0x3Eu;
		func_0091A4((uint8_t)d7, 0u);
		d7 = (d7 & ~0xFFFFu) | 0x64u;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, 0u);
		d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
		d1 = (uint16_t)(mem_read16(a0 + 0xCu) - 0x20u);
		d2 = (uint16_t)(mem_read16(a0 + 0xEu) + 0x20u);
		func_03001C(d0_2, d1, d2, &d5, &d6, &d7);
		mem_write8(a0 + 0x30u, 0x28u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_011688(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0, mem_read8(a0) | 6u);
		d0 = 0u;
		func_011C0E(d0, a0, p_d6, p_d7, p_a5);
		return;
	}
	*p_d7 = func_0116B0(*p_d7);
}

void unreached_0116A2(uint32_t a0)
{
	mem_write16(a0 + 0x30u, 0u);
	mem_write8(a0 + 5u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_0116B0(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	d7_2 = d7_2 & ~0xFDu;
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(d7_2 << 1);
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(d7_2 + (uint8_t)(unk_063384 >> 8u));
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(0u - d7_2);
	unk_060062 = (unk_060062 & 0xFF00u) | (d7_2 & 0xFFu);
	return d7_2;
}

void func_0116CC(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint8_t d7_2 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0, d1_2 = 0, d7 = 0, ignored = 0;

	func_011F3E(a0, &d5, p_d6, &ignored);
	if (mem_read8(a0 + 5u) == 3u || mem_read8(a0 + 5u) == 4u)
	{
		d7 = mem_read8(a0 + 5u);
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			func_011796(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 4:
			func_0117CC(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 8:
			func_0117FE(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 12:
			d7 = func_01180E(d7, a0);
			break;
		case 16:
			func_011844(a0, &d5, p_d6, &d7, p_a5);
			break;
		}
	}
	else
	{
		func_011AD8(a0, &d0, &d5, p_d6);
		if ((uint8_t)d0 == 0u)
		{
			d7 = mem_read8(a0 + 5u);
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				func_011796(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 4:
				func_0117CC(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 8:
				func_0117FE(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 12:
				d7 = func_01180E(d7, a0);
				break;
			case 16:
				func_011844(a0, &d5, p_d6, &d7, p_a5);
				break;
			}
		}
		else
		{
			a6 = indexed_table_of_8_bit_values_01175A_ADDRESS;
			d1 = (uint16_t)((uint32_t)mem_read8(a0 + 0x26u) << 1);
			if ((int8_t)d0 < 0)
			{
				if ((mem_read8(a0) & 0x40u) == 0u)
					d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
			}
			else if ((mem_read8(a0) & 0x40u) != 0u)
				d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
			d1_2 = DATA8(a6 + (uint16_t)(d1 + ((uint32_t)unk_061207 << 2)));
			d7 = 0x40u;
			func_048448(a0, p_d6, &d7);
			if (d1_2 <= (uint8_t)d7)
			{
				d7 = mem_read8(a0 + 5u);
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					func_011796(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 4:
					func_0117CC(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 8:
					func_0117FE(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 12:
					d7 = func_01180E(d7, a0);
					break;
				case 16:
					func_011844(a0, &d5, p_d6, &d7, p_a5);
					break;
				}
			}
			else
			{
				mem_write8(a0 + 0x2Eu, d0);
				mem_write8(a0 + 0x2Fu, 0u);
				mem_write16(a0 + 4u, 0x300u);
				mem_write8(a0, mem_read8(a0) & 0xBFu);
				mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
				if ((int8_t)mem_read8(a0 + 0x2Eu) >= 0)
				{
					mem_write8(a0, mem_read8(a0) | 0x40u);
					mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
				}
				mem_write8(a0 + 0x2Eu, 0u);
				d7_2 = 8u;
				func_0091A4(d7_2, a6);
				d7 = unk_061207;
				d7 = (uint16_t)(d7 << 2);
				d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + mem_read8(a0 + 0x26u));
				d7 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_011D1A[d7];
				a6 = TABLE32(rom_014DA0, d7);
				set_animation(d1_2, a0, a6);
				mem_write8(a0 + 0x26u, mem_read8(a0 + 0x26u) + 1u);
				if (mem_read8(a0 + 0x26u) >= 4u)
					mem_write8(a0 + 0x26u, 3u);
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_011796(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		func_011E6A(a0, &ignored, &d7_2, p_a5);
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = func_011F94(a0);
	t3 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t3 - 1u);
	if (t3 == 0u)
	{
		d0 = 1u;
		func_01185E(d0, a0, &d5, p_d6, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_0117CC(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		func_011E6A(a0, &ignored, &d7_2, p_a5);
	if ((unk_0600A4 & 2u) == 0u)
		d7_2 = func_011F94(a0);
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		d0 = 2u;
		func_01185E(d0, a0, &d5, p_d6, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_0117FE(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 != 0u)
		return;
	d0 = 3u;
	func_01185E(d0, a0, &d5, p_d6, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

uint32_t func_01180E(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	t1 = mem_read16(a0 + 0x10u) + d7_2;
	mem_write16(a0 + 0x10u, t1);
	if ((int16_t)t1 >= 0)
	{
		mem_write8(a0 + 0x31u, mem_read8(a0 + 0x31u) - 1u);
		mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x80u);
		return d7_2;
	}
	d7_2 = (d7_2 & ~0xFFFFu) | 0x3Fu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write16(a0 + 0x10u, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_011844(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	*p_d7 = func_0116B0(*p_d7);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		d0 = 4u;
		func_01185E(d0, a0, &d5, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_01185E(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d7 = 0;

	func_011B42(a0, &d5, &d7);
	if ((uint8_t)d7 != 0u)
	{
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x2Cu, 0u);
		d7 = 4u;
		func_048448(a0, p_d6, &d7);
		mem_write8(a0 + 0x30u, indexed_table_of_8_bit_values_011DEE[d7]);
		mem_write8(a0 + 0x31u, 0x20u);
		a6 = rom_014DB0;
		set_animation(0u, a0, a6);
	}
	else
		func_011C0E(d0, a0, p_d6, &d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_01186C(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d5 = 0, d6 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint32_t t4 = 0;

	func_011F3E(a0, &d5, &d6, &d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Cu, 0u);
		a6 = rom_014DB0;
		set_animation(0u, a0, a6);
	}
	else
	{
		t2 = mem_read8(a0 + 0x31u);
		mem_write8(a0 + 0x31u, t2 - 1u);
		if (t2 != 0u)
		{
			d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 0x30u);
			t3 = d7_2 & 3u;
			d7 = (d7_2 & ~0xFFu) | t3;
			if (t3 == 0u)
			{
				a6 = 0x62780u;
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				func_01830C(&d7, &a6);
				if ((uint8_t)d7 != 0u)
				{
					mem_write16(a6, 0x100u);
					mem_write16(a6 + 2u, 0x3400u);
					mem_write16(a6 + 0x42u, 0xFF00u);
					func_018574(a0, a6);
					mem_write8(a6 + 0x2Fu, 0u);
					d7 = (d7 & ~0xFFFFu) | 0x4800u;
					if ((mem_read8(a0) & 0x40u) == 0u)
					{
						d7 = (int16_t)~d7;
						mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
					}
					t4 = mem_read32(a6 + 0x12u) + d7;
					mem_write16(a6 + 0x14u, t4);
					mem_write16(a6 + 0x12u, t4 >> 16);
					mem_write16(a6 + 0x10u, 0x3000u);
					mem_write32(a6 + 0x20u, a0);
					if ((mem_read8(a0) & 0x40u) == 0u)
						mem_write8(a6, mem_read8(a6) | 0x40u);
					mem_write16(a6 + 4u, 0u);
				}
			}
		}
		else
		{
			mem_write8(a0 + 0x31u, 0u);
			if ((int8_t)mem_read8(a0 + 0x2Cu) < 0)
			{
				mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
				mem_write8(a0 + 5u, 0u);
				mem_write8(a0 + 0x2Cu, 0u);
				a6 = rom_014DB0;
				set_animation(0u, a0, a6);
			}
			else
			{
				d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 0x30u);
				t3 = d7_2 & 3u;
				d7 = (d7_2 & ~0xFFu) | t3;
				if (t3 == 0u)
				{
					a6 = 0x62780u;
					d7 = (d7 & ~0xFFu) | 8u;
					d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
					func_01830C(&d7, &a6);
					if ((uint8_t)d7 != 0u)
					{
						mem_write16(a6, 0x100u);
						mem_write16(a6 + 2u, 0x3400u);
						mem_write16(a6 + 0x42u, 0xFF00u);
						func_018574(a0, a6);
						mem_write8(a6 + 0x2Fu, 0u);
						d7 = (d7 & ~0xFFFFu) | 0x4800u;
						if ((mem_read8(a0) & 0x40u) == 0u)
						{
							d7 = (int16_t)~d7;
							mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
						}
						t4 = mem_read32(a6 + 0x12u) + d7;
						mem_write16(a6 + 0x14u, t4);
						mem_write16(a6 + 0x12u, t4 >> 16);
						mem_write16(a6 + 0x10u, 0x3000u);
						mem_write32(a6 + 0x20u, a0);
						if ((mem_read8(a0) & 0x40u) == 0u)
							mem_write8(a6, mem_read8(a6) | 0x40u);
						mem_write16(a6 + 4u, 0u);
					}
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | (d6 & 0xFFu);
	*p_d7 = d7;
}

void func_0118CA(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	func_011F3E(a0, &d5, p_d6, p_d7);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Du, 0u);
		d0 = 5u;
		func_011C0E(d0, a0, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_0118EC(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d7 = 0;
	uint32_t a1 = 0, a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x2Du, 0x80u);
	mem_write8(a0 + 0x42u, 0xFFu);
	a1 = rom_014DA0_ADDRESS;
	if (mem_read8(a0 + 2u) != 0x1Eu)
		a1 = rom_0153D8_ADDRESS;
	t1 = mem_read8(a0 + 0x24u);
	mem_write8(a0 + 0x24u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = DATA32(a1 + 0x1Cu);
		set_animation(0u, a0, a6);
		if (unk_06120C == 1u)
		{
			d7 = 0u;
			func_0091A4(d7, a6);
		}
		d7 = 0x88u;
		func_0091A4(d7, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write8(a0 + 0x30u, 0u);
		mem_write8(a0 + 0x26u, 0u);
		mem_write8(a0, mem_read8(a0) & ~6u);
	}
	else
	{
		mem_write8(a0 + 8u, 0xAu);
		if (mem_read8(a0 + 0x24u) == 1u)
			mem_write8(a0 + 8u, 1u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 0x26u, 0u);
		mem_write8(a0 + 0x30u, 0x1Cu);
		mem_write8(a0, mem_read8(a0) & ~2u);
		d7 = 0x82u;
		func_0091A4(d7, 0u);
		a6 = DATA32(a1 + 0x18u);
		set_animation(0u, a0, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
	*p_a1 = a1;
}

void func_0119A0(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x24u) < 0x14u)
		mem_write8(a0 + 0x42u, 8u);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Du, 0u);
		mem_write8(a0 + 0x2Au, 8u);
		mem_write8(a0 + 0x42u, 0xFFu);
		d0 = 6u;
		if (mem_read8(a0 + 2u) == 0x1Eu)
			func_011C0E(d0, a0, p_d6, p_d7, p_a5);
		else
			func_012452(d0, a0, p_d6, p_d7, p_a5);
	}
}

void func_0119DE(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_011A0A(a0);
		return;
	case 4:
		func_011A16(a0);
		return;
	case 8:
		func_011A24(a0, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_011A50(a0);
		return;
	case 16:
		func_011A78(a0, p_d6, p_d7, p_a5);
		return;
	case 20:
		func_011AD6();
		return;
	}
}

void func_011A0A(uint32_t a0)
{
	mem_write8(a0 + 0x30u, 0x64u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_011A16(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_011A24(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0 + 0x30u, 0xCu);
	mem_write8(a0 + 5u, 3u);
	a6 = 0x62780u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
		func_010EE8(a0, a6, p_d6, &d7_2, p_a5);
	else
		mem_write8(a0 + 5u, 4u);
	*p_d7 = d7_2;
}

void func_011A50(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) + 1u);
		if (mem_read8(a0 + 0x2Fu) == 0xAu)
		{
			mem_write8(a0 + 5u, 4u);
			mem_write8(a0 + 0x30u, 0x96u);
		}
	}
}

void func_011A78(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;
	uint32_t t3 = 0, t4 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 5u, 5u);
		unk_06120C--;
		unk_061313 = 1u;
		unk_06131D = 1u;
	}
	else
	{
		d7 = IN_PAGE(d7, mem_read8(a0 + 0x30u));
		d0 = 3u;
		a6 = indexed_table_of_8_bit_values_011AD2_ADDRESS;
		for (;;)
		{
			if ((uint8_t)d7 != mem_read8(a6 + (int16_t)d0))
			{
				t2 = d0 - 1u;
				d0 = t2;
				if (t2 == 0xFFFFu)
					break;
				continue;
			}
			a6 = 0x62A00u;
			d7 = IN_PAGE(d7, 8u);
			d7 = (uint8_t)d7;
			func_01830C(&d7, &a6);
			if ((uint8_t)d7 != 0u)
			{
				mem_write16(a6, 0x100u);
				mem_write16(a6 + 2u, 0x4100u);
				mem_write8(a6 + 3u, (uint8_t)d0);
				mem_write16(a6 + 0x42u, 0x800u);
				func_018574(a0, a6);
				*p_a5 = indexed_table_of_8_bit_values_012108_ADDRESS;
				d7 = mem_read8(a6 + 3u);
				d7 = (uint16_t)(d7 << 1);
				t3 = mem_read32(a6 + 0x12u) + ((uint32_t)(int16_t)(int8_t)indexed_table_of_8_bit_values_012108[d7] << 8);
				mem_write16(a6 + 0x14u, t3);
				mem_write16(a6 + 0x12u, t3 >> 16);
				*p_d6 = (uint32_t)(int16_t)(int8_t)rom_012109[d7] << 8;
				t4 = mem_read32(a6 + 0x16u) + *p_d6;
				mem_write16(a6 + 0x18u, t4);
				mem_write16(a6 + 0x16u, t4 >> 16);
				mem_write16(a6 + 0x10u, 0x8000u);
				mem_write16(a6 + 4u, 0u);
				break;
			}
			break;
		}
	}
	*p_d7 = d7;
}

void func_011AD6(void)
{
}

void func_011AD8(uint32_t a0, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d6)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d0 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a6 = unk_0620F0_ADDRESS;
	d6 = 3u;
	d0 = 0u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u && (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) == 0u && mem_read8(a6 + 4u) != 4u)
		{
			t1 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
			d5 = t1;
			if ((int16_t)t1 < 0)
				d5 = (uint16_t)~d5;
			if (d5 < 0xCu)
			{
				t2 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d0 = d0 | 0x80u;
					d5 = (uint16_t)~d5;
				}
				if (d5 < 0x3Cu)
				{
					d0 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
		}
		d0 = 0u;
		t3 = d6 - 1u;
		d6 = t3;
		a6 -= 0x50u;
	} while (t3 != 0xFFFFu);
	*p_d0 = d0;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
}

void func_011B42(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	a6 = unk_0620F0_ADDRESS;
	d6 = 3u;
	d7 = 0u;
	for (;;)
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) == 0u || (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) != 0u || mem_read8(a6 + 4u) == 4u)
		{
			t1 = d6 - 1u;
			d6 = t1;
			a6 -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		t2 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
		d5 = t2;
		if ((int16_t)t2 < 0)
			d5 = (uint16_t)~d5;
		if (d5 >= 0xBu)
		{
			t1 = d6 - 1u;
			d6 = t1;
			a6 -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (mem_read8(a0 + 2u) == 0x1Du)
		{
			if ((mem_read8(a0) & 0x40u) != 0u)
			{
				t3 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
				d5 = t3;
				if ((int16_t)t3 < 0 || d5 < 0x46u)
				{
					t1 = d6 - 1u;
					d6 = t1;
					a6 -= 0x50u;
					if (t1 == 0xFFFFu)
						break;
					continue;
				}
				d7 |= shl32(1u, (int)(d6 & 0x1Fu));
				break;
			}
			t4 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
			d5 = t4;
			if ((int16_t)t4 < 0)
			{
				d5 = (uint16_t)~d5;
				if (d5 >= 0x46u)
				{
					d7 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
			t1 = d6 - 1u;
			d6 = t1;
			a6 -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			t5 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
			d5 = t5;
			if ((int16_t)t5 < 0 || d5 >= 0x8Cu)
			{
				t1 = d6 - 1u;
				d6 = t1;
				a6 -= 0x50u;
				if (t1 == 0xFFFFu)
					break;
				continue;
			}
			d7 |= shl32(1u, (int)(d6 & 0x1Fu));
			break;
		}
		t6 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
		d5 = t6;
		if ((int16_t)t6 < 0)
		{
			d5 = (uint16_t)~d5;
			if (d5 < 0x8Cu)
			{
				d7 |= shl32(1u, (int)(d6 & 0x1Fu));
				break;
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 0x50u;
		if (t1 == 0xFFFFu)
			break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
}

void func_011C0E(uint32_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t a6 = 0, d6_2 = 0, d7 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	d7 = 0x10u;
	func_048448(a0, &d6, &d7);
	d6_2 = (d6 & ~0xFFFFu) | 3u;
	a6 = table_loaded_by_lea_011C42_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6_2);
		t2 = d7;
		d7 = (uint8_t)(t2 - t1);
		if (t2 < t1)
			break;
		t3 = d6_2 - 1u;
		d6_2 = (d6_2 & ~0xFFFFu) | t3;
		if (t3 == 0xFFFFu)
		{
			d6_2 = 2u;
			break;
		}
	}
	d6_2 = (d6_2 & ~0xFFFFu) | (uint16_t)(d6_2 << 2);
	switch ((uint32_t)(int16_t)d6_2)
	{
	case 0:
		func_011D2E(a0, &d6_2, &d7, p_a5);
		break;
	case 4:
		func_011D56(a0, &d6_2, &d7);
		break;
	case 8:
		func_011D6A(a0, &d6_2, &d7);
		break;
	case 12:
		func_011D88(a0, &d6_2, &d7);
		break;
	}
	*p_d6 = d6_2;
	*p_d7 = d7;
}

void func_011D2E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0, ignored = 0, ignored_2 = 0;

	func_011DFA(a0, &ignored, &ignored_2, p_d7, p_a5);
	if ((uint8_t)*p_d7 == 0u)
		func_011D6A(a0, &d6, p_d7);
	else
	{
		*p_d7 = 8u;
		func_011DDA(a0, &d6, p_d7);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write16(a0 + 4u, 0x100u);
		a6 = rom_014DA8;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_011D56(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_011DDA(a0, &d6, p_d7);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x101u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_011D6A(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0;

	*p_d7 = 4u;
	func_011DDA(a0, &d6, p_d7);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x102u);
	a6 = rom_014DAC;
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_011D88(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 0x31u, 0x28u);
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x103u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write32(a0 + 0x3Au, 0x16C50u);
	d7 = 4u;
	func_048448(a0, &d6, &d7);
	if ((uint8_t)d7 == 0u)
	{
		d7 = 0xB1u;
		func_0091A4((uint8_t)d7, 0u);
	}
	a6 = rom_014DA4;
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_011DDA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x31u, rom_011DF2[*p_d7]);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_011DFA(uint32_t a0, uint32_t *p_d0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0;

	a6 = unk_0620F0_ADDRESS;
	*p_a5 = unk_061306_ADDRESS;
	unk_061308 = 0u;
	unk_061306(0) = 0u;
	unk_061306(1) = 0u;
	d6 = 3u;
	d7 = 0u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u && (unk_0600A0 & shl32(1u, (int)(d6 & 7u))) == 0u && mem_read8(a6 + 4u) != 4u)
		{
			unk_061306(d7) = d6;
			d7 = (uint8_t)(d7 + 1u);
		}
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 0x50u;
	} while (t1 != 0xFFFFu);
	if (d7 != 0u)
	{
		func_048448(a0, &d6, &d7);
		d7 = ((d7 & ~0xFFu) | unk_061306(d7)) * 0x50u;
		mem_write32(a0 + 0x20u, unk_062000_ADDRESS + d7);
		func_011E6A(a0, p_d0, &d7, p_a5);
		d7 = IN_PAGE(d7, 1u);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_011E6A(uint32_t a0, uint32_t *p_d0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d0 = 0;

	func_0184D2(a0, &d0, p_a5);
	a6 = indexed_table_of_16_bit_values_011EB2_ADDRESS;
	if (mem_read8(a0 + 2u) != 0x1Eu)
		a6 = 0x11EF2u;
	d0 = (uint16_t)(d0 << 2);
	mem_write16(a0 + 0x1Au, DATA16(a6 + d0));
	d7 = DATA16(a6 + 2u + d0);
	mem_write16(a0 + 0x1Cu, d7);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int16_t)mem_read16(a0 + 0x1Au) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_d0 = d0;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

void func_011F32(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d5 = 0, d6 = 0;

	d5 = 8u;
	d6 = 0xEu;
	*p_d7 = func_011F46(d5, d6, *p_d7, a0);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
}

void func_011F3E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d5 = 0, d6 = 0;

	d5 = 8u;
	d6 = 0xDu;
	*p_d7 = func_011F46(d5, d6, *p_d7, a0);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
}

uint32_t func_011F46(uint8_t d5, uint8_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (mem_read8(a0 + 0x2Au) != 0u)
	{
		t1 = mem_read8(a0 + 0x2Au);
		mem_write8(a0 + 0x2Au, t1 - 1u);
		if (t1 == 1u)
			mem_write8(a0, mem_read8(a0) | 2u);
	}
	if (mem_read8(a0 + 0x24u) >= 0x1Cu)
		return d7;
	d7_2 = 0x1Cu;
	if (mem_read8(a0 + 0x24u) < 0x14u)
	{
		d7_2 = 8u;
		if (mem_read8(a0 + 0x24u) < 0xAu)
			d7_2 = 1u;
	}
	mem_write8(a0 + 0x42u, d6);
	t2 = d7_2 & (uint8_t)unk_0600A4;
	d7 = t2;
	if (t2 == 0u)
		mem_write8(a0 + 0x42u, d5);
	return d7;
}

uint32_t func_011F94(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	if (mem_read32(a0 + 0x16u) >= 0x7800u)
		mem_write32(a0 + 0x16u, 0x7800u);
	if (mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
		mem_write32(a0 + 0x16u, func_001000_ADDRESS);
	return d7;
}

uint32_t func_012024(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x181D6u;
	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x1Au, 0x400u);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
	}
	a6 = rom_014FBE;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 6u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_012076(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u || (mem_read8(a0) & 0x20u) != 0u)
	{
		func_01832A(a0);
		return d7;
	}
	d7_2 = (int16_t)mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7_2;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	if ((mem_read8(a0) & 8u) != 0u)
		mem_write8(mem_read32(a0 + 0x20u) + 0x2Cu, 0x80u);
	return d7_2;
}

uint32_t func_012110(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0xFA00u);
	d7 = mem_read8(a0 + 3u);
	d7 = (uint16_t)(d7 << 2);
	a6 = rom_0151AA[d7 / 4u];
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7;
}

uint32_t func_01214E(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	if ((int16_t)mem_read16(a0 + 0x10u) < 0)
	{
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Eu, 0u);
		d7 = (d7 & ~0xFFFFu) | 0x31u;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7;
}

void func_01217A(void)
{
}

void func_012198(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_0121BC(a0, p_d6, p_d7);
		return;
	case 4:
		*p_d7 = func_012230(*p_d7, a0);
		return;
	case 8:
		*p_d7 = func_01225A(*p_d7, a0);
		return;
	case 12:
		func_01227E(a0, p_d6, p_d7, p_a5);
		return;
	}
}

void func_0121BC(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0;

	a6 = 0x18226u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 8u));
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	mem_write8(a0 + 0x2Bu, d7);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + d7);
	a6 = rom_0153D8[0];
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 0x2Du, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x26u, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	unk_06120C++;
	unk_06130B = 0u;
	unk_061313 = 0u;
	unk_06131D = 0u;
	*p_d6 = d6;
	*p_d7 = d7;
}

uint32_t func_012230(uint32_t d7, uint32_t a0)
{
	if (unk_063380 >= 0xD1000u)
	{
		d7 = 0xFEu;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x30u, 0x50u);
	}
	return d7;
}

uint32_t func_01225A(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		d7 = 0x64u;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, 0u);
		mem_write8(a0 + 0x30u, 0x28u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
	return d7;
}

void func_01227E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d0 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 0x86u);
		d0 = 0u;
		func_012452(d0, a0, p_d6, &d7_2, p_a5);
		a6 = 0x62780u;
		d7 = (d7_2 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			func_012668(a0, a6);
			a6 = 0x62780u;
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			func_01830C(&d7, &a6);
			if ((uint8_t)d7 != 0u)
			{
				mem_write16(a6, 0x100u);
				mem_write16(a6 + 2u, 0x4C00u);
				mem_write16(a6 + 0x42u, 0xFF00u);
				func_018574(a0, a6);
				t2 = mem_read32(a6 + 0x16u) + 0x8A00u;
				mem_write16(a6 + 0x18u, t2);
				mem_write16(a6 + 0x16u, t2 >> 16);
				mem_write32(a6 + 0x20u, a0);
				mem_write16(a6 + 4u, 0u);
				*p_a5 = a6;
				a6 = 0x62780u;
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				func_01830C(&d7, &a6);
				if ((uint8_t)d7 != 0u)
				{
					mem_write16(a6, 0x100u);
					mem_write16(a6 + 2u, 0x4D00u);
					mem_write16(a6 + 0x42u, 0xFF00u);
					func_018574(a0, a6);
					mem_write32(a6 + 0x20u, *p_a5);
					mem_write16(a6 + 4u, 0u);
				}
			}
		}
	}
	*p_d7 = d7;
}

void func_0122C8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, d0 = 0, d1 = 0, d7 = 0, ignored = 0;

	func_011F32(a0, &d5, p_d6, &ignored);
	if (mem_read8(a0 + 5u) == 3u)
	{
		d7 = mem_read8(a0 + 5u);
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			func_012370(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 4:
			func_0123A6(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 8:
			func_0123D8(a0, &d5, p_d6, &d7, p_a5);
			break;
		case 12:
			func_0123E8(a0, &d5, p_d6, &d7, p_a5);
			break;
		}
	}
	else
	{
		func_011AD8(a0, &d0, &d5, p_d6);
		if ((uint8_t)d0 == 0u)
		{
			d7 = mem_read8(a0 + 5u);
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				func_012370(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 4:
				func_0123A6(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 8:
				func_0123D8(a0, &d5, p_d6, &d7, p_a5);
				break;
			case 12:
				func_0123E8(a0, &d5, p_d6, &d7, p_a5);
				break;
			}
		}
		else
		{
			a6 = indexed_table_of_8_bit_values_012338_ADDRESS;
			if (mem_read8(a0 + 0x24u) < 0x14u)
				a6 = 0x1234Cu;
			d1 = DATA8(a6 + (uint16_t)(mem_read8(a0 + 0x26u) + ((uint32_t)unk_061207 << 2)));
			d7 = 0x40u;
			func_048448(a0, p_d6, &d7);
			if (d1 <= (uint8_t)d7)
			{
				d7 = mem_read8(a0 + 5u);
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					func_012370(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 4:
					func_0123A6(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 8:
					func_0123D8(a0, &d5, p_d6, &d7, p_a5);
					break;
				case 12:
					func_0123E8(a0, &d5, p_d6, &d7, p_a5);
					break;
				}
			}
			else
			{
				mem_write8(a0 + 0x2Eu, d0);
				mem_write8(a0 + 0x2Fu, 0u);
				mem_write16(a0 + 4u, 0x300u);
				mem_write8(a0, mem_read8(a0) & 0xBFu);
				mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
				if ((int8_t)mem_read8(a0 + 0x2Eu) >= 0)
				{
					mem_write8(a0, mem_read8(a0) | 0x40u);
					mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
				}
				mem_write8(a0 + 0x2Eu, 0u);
				d7_2 = 8u;
				func_0091A4(d7_2, a6);
				d7 = unk_061207;
				d7 = (uint16_t)(d7 << 2);
				d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + mem_read8(a0 + 0x26u));
				d7 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_01255E[d7];
				a6 = TABLE32(rom_0153D8, d7);
				set_animation(d1, a0, a6);
				mem_write8(a0 + 0x26u, mem_read8(a0 + 0x26u) + 1u);
				if (mem_read8(a0 + 0x26u) >= 4u)
					mem_write8(a0 + 0x26u, 3u);
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_012370(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		func_011E6A(a0, &ignored, &d7_2, p_a5);
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = func_012630(a0);
	t3 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t3 - 1u);
	if (t3 == 0u)
	{
		d0 = 1u;
		func_0123F8(d0, a0, &d5, p_d6, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_0123A6(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		func_011E6A(a0, &ignored, &d7_2, p_a5);
	if ((unk_0600A4 & 2u) == 0u)
		d7_2 = func_012630(a0);
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		d0 = 2u;
		func_0123F8(d0, a0, &d5, p_d6, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_0123D8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 != 0u)
		return;
	d0 = 3u;
	func_0123F8(d0, a0, &d5, p_d6, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_0123E8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	d0 = 4u;
	func_0123F8(d0, a0, &d5, p_d6, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_0123F8(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d7 = 0;

	if (unk_06130B != 0u)
		func_012452(d0, a0, p_d6, &d7, p_a5);
	else
	{
		func_011B42(a0, &d5, &d7);
		if ((uint8_t)d7 == 0u)
			func_012452(d0, a0, p_d6, &d7, p_a5);
		else
		{
			d7 = 0x10u;
			func_048448(a0, p_d6, &d7);
			if ((uint8_t)d7 < 4u)
			{
				mem_write8(a0 + 0x2Fu, 0u);
				mem_write16(a0 + 4u, 0x200u);
				mem_write8(a0 + 0x2Cu, 0u);
				a6 = 0x62780u;
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (uint8_t)d7;
				func_01830C(&d7, &a6);
				if ((uint8_t)d7 == 0u)
					func_012572(a0, p_d6, &d7, p_a5);
				else
				{
					func_012716(a0, a6, &d7, p_a5);
					a6 = rom_0153E8;
					set_animation(0u, a0, a6);
				}
			}
			else
				func_012452(d0, a0, p_d6, &d7, p_a5);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_012422(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	func_011F32(a0, &d5, p_d6, p_d7);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Du, 0u);
		d0 = 5u;
		func_012452(d0, a0, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_012430(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	func_011F32(a0, &d5, p_d6, p_d7);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Du, 0u);
		d0 = 5u;
		func_012452(d0, a0, p_d6, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_012452(uint32_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t a6 = 0, d6_2 = 0, d7 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	d7 = 0x10u;
	func_048448(a0, &d6, &d7);
	d6_2 = (d6 & ~0xFFFFu) | 3u;
	a6 = table_loaded_by_lea_012486_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6_2);
		t2 = d7;
		d7 = (uint8_t)(t2 - t1);
		if (t2 < t1)
			break;
		t3 = d6_2 - 1u;
		d6_2 = (d6_2 & ~0xFFFFu) | t3;
		if (t3 == 0xFFFFu)
		{
			d6_2 = 2u;
			break;
		}
	}
	d6_2 = (d6_2 & ~0xFFFFu) | (uint16_t)(d6_2 << 2);
	switch ((uint32_t)(int16_t)d6_2)
	{
	case 0:
		func_012572(a0, &d6_2, &d7, p_a5);
		break;
	case 4:
		func_01259A(a0, &d6_2, &d7);
		break;
	case 8:
		func_0125AE(a0, &d6_2, &d7);
		break;
	case 12:
		func_0125DA(a0, &d6_2, &d7);
		break;
	}
	*p_d6 = d6_2;
	*p_d7 = d7;
}

void func_012572(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d6 = 0, ignored = 0, ignored_2 = 0;

	func_011DFA(a0, &ignored, &ignored_2, p_d7, p_a5);
	if ((uint8_t)*p_d7 == 0u)
		func_0125DA(a0, &d6, p_d7);
	else
	{
		*p_d7 = 8u;
		func_012610(a0, &d6, p_d7);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write16(a0 + 4u, 0x100u);
		a6 = rom_0153E0;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01259A(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	*p_d7 = 8u;
	func_012610(a0, &d6, p_d7);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x101u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0125AE(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0;

	*p_d7 = 4u;
	func_012610(a0, &d6, p_d7);
	a6 = rom_0153D8[0];
	if (mem_read8(a0 + 4u) == 0u)
		a6 = rom_0153DC;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x102u);
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0125DA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d6_2 = 0;
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	mem_write8(a0 + 0x2Fu, 0u);
	mem_write16(a0 + 4u, 0x103u);
	d7 = 4u;
	func_048448(a0, &d6, &d7);
	d6_2 = (uint16_t)((d6 & ~0xFFu) | (uint8_t)d7);
	d7 = 0xA6u;
	if ((uint8_t)d6_2 == 0u)
		d7 = 0xB1u;
	func_0091A4((uint8_t)d7, 0u);
	a6 = rom_0153E4;
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6_2;
	*p_d7 = d7;
}

void func_012610(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x31u, rom_012628[*p_d7]);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_012630(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = func_0182EE(a0);
	if (mem_read32(a0 + 0x16u) >= 0xF68000u)
		mem_write32(a0 + 0x16u, 0xF68000u);
	if (mem_read32(a0 + 0x16u) < 0xF61000u)
		mem_write32(a0 + 0x16u, 0xF61000u);
	return d7;
}

void func_012668(uint32_t a0, uint32_t a6)
{
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x4800u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x16u) - 0x800u;
	mem_write16(a6 + 0x18u, t1);
	mem_write16(a6 + 0x16u, t1 >> 16);
	t2 = mem_read32(a6 + 0x16u) - 0x800u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + 0x400u);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
}

uint32_t func_0126A0(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, 0x85u);
	a6 = 0x1823Au;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0xF800u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6 = rom_0156DA;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	func_0091A4((uint8_t)d7_2, a6);
	a6 = 0x191A4u;
	d7_2 = (d7_2 & ~0xFFFFu) | 0x25u;
	draw_tile_block((uint16_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_0126F0(uint32_t d7, uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_01832A(a0);
		return d7;
	}
	return func_0182EE(a0);
}

void func_012716(uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;
	uint32_t t1 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x4900u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write8(a6 + 0x2Fu, 0u);
	d7_2 = (d7 & ~0xFFFFu) | 0x4000u;
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		d7_2 = (int16_t)~d7_2;
		mem_write8(a6 + 0x2Fu, mem_read8(a6 + 0x2Fu) | 0x80u);
	}
	t1 = mem_read32(a6 + 0x12u) + d7_2;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	mem_write16(a6 + 0x10u, 0x3800u);
	mem_write32(a6 + 0x20u, a0);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a6 + 4u, 0u);
	mem_write8(a6 + 1u, mem_read8(a6 + 1u) | 0x80u);
	*p_a5 = 0x16F20u;
	mem_write32(a6 + 0x3Au, 0x16F20u);
	*p_d7 = d7_2;
}

uint32_t func_01277E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, mem_read8(a0) | 0x86u);
	a6 = 0x18230u;
	func_0180E0(a0, a6);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x1Au, 0x300u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	if ((int8_t)mem_read8(a0 + 0x2Fu) < 0)
	{
		mem_write8(a0, mem_read8(a0) & 0xBFu);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
		mem_write16(a0 + 0x1Au, ~mem_read16(a0 + 0x1Au));
	}
	a6 = rom_015692;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 6u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

void func_0127D6(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint32_t t1 = 0;

	if (mem_read16(a0 + 0xCu) < 0x60u || mem_read16(a0 + 0xCu) >= 0x180u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		d7_2 = (d7 & ~0xFFu) | 0x13u;
		func_0091A4((uint8_t)d7_2, a6);
		a6 = rom_015258;
		set_animation(0u, a0, a6);
	}
	else
	{
		unk_063300 = unk_063380;
		func_01DE3E(a0, &d5, &d6, p_a5, &a6);
		func_01D8E6(a0, a6);
		if ((mem_read8(a0 + 1u) & 8u) != 0u)
		{
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			d7_2 = (d7 & ~0xFFu) | 0x13u;
			func_0091A4((uint8_t)d7_2, a6);
			a6 = rom_015258;
			set_animation(0u, a0, a6);
		}
		else
		{
			d7_2 = (int16_t)mem_read16(a0 + 0x1Au);
			t1 = mem_read32(a0 + 0x12u) + d7_2;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_012830(uint32_t a0)
{
	if (mem_read16(a0 + 0x10u) != 0u)
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - 0x400u);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, 1u);
		if (unk_06130C == 0u)
		{
			unk_06130B = 0u;
			func_01832A(a0);
			return;
		}
	}
	func_012862();
}

void func_012862(void)
{
}

void func_012864(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = rom_014C3A;
	set_animation(0u, a0, a6);
}

void func_01287A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_0128D8(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 0x2Eu, 0x3Du);
	mem_write8(a0 + 0x30u, mem_read8(a0 + 0x2Eu));
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = rom_01574E;
	set_animation(0u, a0, a6);
}

uint32_t func_0128FE(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	func_012960(a0);
	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
	{
		mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) - 4u);
		if (mem_read8(a0 + 0x2Eu) == 1u)
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7_2;
}

void func_012924(uint32_t a0)
{
	func_012960(a0);
	if (mem_read8(mem_read32(a0 + 0x20u) + 4u) == 6u)
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_01293C(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	func_012960(a0);
	d7_2 = (d7 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d7_2 & 7u;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
		return d7_2;
	mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) + 1u);
	if (mem_read8(a0 + 0x2Eu) < 0x28u)
		return d7_2;
	func_01832A(a0);
	return d7_2;
}

void func_012960(uint32_t a0)
{
	uint8_t t1 = 0;

	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
	{
		mem_write8(a0 + 0x30u, mem_read8(a0 + 0x2Eu));
		mem_write8(a0, mem_read8(a0) | 0x80u);
	}
}

void func_0129A6(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x18244u;
	func_0180E0(a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = rom_01574E;
	set_animation(0u, a0, a6);
}

void unreached_0129C0(uint32_t a0)
{
	if ((unk_0600A4 & 0xFu) == 0u)
	{
		mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) - 4u);
		if (mem_read8(a0 + 0x2Eu) == 1u)
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

uint32_t func_0129E2(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(mem_read32(a0 + 0x20u) + 4u);
	if ((uint8_t)d7_2 == 3u)
	{
		func_01832A(a0);
		return d7_2;
	}
	mem_write8(a0, mem_read8(a0) & ~4u);
	if ((uint8_t)d7_2 == 2u)
	{
		d7_2 = (d7_2 & ~0xFFu) | (uint8_t)unk_0600A4;
		t1 = d7_2 & 0xFu;
		d7_2 = (d7_2 & ~0xFFu) | t1;
		if (t1 == 0u)
			mem_write8(a0, mem_read8(a0) | 4u);
	}
	return d7_2;
}

void func_012A2E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	a6 = rom_015042;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x24u, 0u);
	mem_write16(a0 + 0x26u, 0u);
	mem_write32(a0 + 0x20u, TILE_RAM + 0x2F80u);
	func_012B8C(a0);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_012A68(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write16(a0 + 0x2Au, mem_read16(a0 + 0xCu));
	d7 = func_012B74(d7, a0);
	a6 = 0x18C28u;
	d7_2 = (d7 & ~0xFFFFu) | 5u;
	draw_tile_block((uint16_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_012A88(uint32_t d7, uint32_t a0)
{
	d7 = func_012B74(d7, a0);
	if (mem_read16(a0 + 0xCu) < 0xE0u)
	{
		mem_write8(a0 + 0x30u, 0xAu);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
	}
	return d7;
}

void func_012AA6(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d7 = func_012B74(d7, a0);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		d0 = 2u;
		do
		{
			a6 = 0x62140u;
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			func_01830C(&d7, &a6);
			if ((uint8_t)d7 == 0u)
				break;
			func_012BCC(d0, a0, a6, &d7, p_a5);
			t2 = d0 - 1u;
			d0 = t2;
		} while (t2 != 0xFFFFu);
		mem_write8(a0 + 0x30u, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
	}
	*p_d7 = d7;
}

void func_012AE2(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;

	mem_write8(a0 + 0x30u, mem_read8(a0 + 0x30u) + 1u);
	if (mem_read8(a0 + 0x30u) >= 0x38u)
	{
		mem_write8(a0 + 0x30u, 3u);
		if (unk_061207 >= 2u)
			mem_write8(a0 + 0x30u, 4u);
		mem_write8(a0 + 0x31u, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
	}
	else
	{
		if ((mem_read8(a0 + 0x30u) & 1u) == 0u)
			d6 = func_012B9E(d6, a0);
		mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) - 4u);
		mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) & 0x1FFu);
		mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) - 4u);
		d7 = func_012B74(d7, a0);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

uint32_t func_012B3C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 != 0u)
		return d7;
	t2 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t2 - 1u);
	if (t2 != 0u)
	{
		a6 = unk_0623C0_ADDRESS;
		d7 = (d7 & ~0xFFu) | 0xCu;
		d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			func_012C7E(a0, a6);
			mem_write8(a0 + 0x31u, 8u);
			return d7;
		}
	}
	func_01832A(a0);
	return d7;
}

uint32_t func_012B74(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x2Au);
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - mem_read16(a0 + 0xCu));
	mem_write16(a0 + 0x2Au, mem_read16(a0 + 0xCu));
	mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) + d7_2);
	mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) & 0x1FFu);
	func_012B8C(a0);
	return d7_2;
}

void func_012B8C(uint32_t a0)
{
	unk_06005C = mem_read16(a0 + 0x24u);
	unk_06005E = mem_read16(a0 + 0x26u);
}

uint32_t func_012B9E(uint32_t d6, uint32_t a0)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d6_2 = 0;
	uint16_t t1 = 0;

	a6 = mem_read32(a0 + 0x20u);
	d6_2 = (d6 & ~0xFFFFu) | 0x3Fu;
	d7 = 0u;
	do
	{
		mem_write8(a6 + (int16_t)d7, 0u);
		mem_write8(a6 + 1u + (int16_t)d7, 0x10u);
		d7 += 2u;
		t1 = d6_2 - 1u;
		d6_2 = (d6_2 & ~0xFFFFu) | t1;
	} while (t1 != 0xFFFFu);
	mem_write16(a0 + 0x22u, mem_read16(a0 + 0x22u) - 0x80u);
	return d6_2;
}

void func_012BCC(uint16_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a5 = 0, d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x3600u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	d7 = d0;
	a5 = table_loaded_by_lea_012C10_ADDRESS + (uint16_t)(d7 << 2);
	t1 = mem_read32(a6 + 0x12u) + (int16_t)DATA16(a5);
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	d7 = (int16_t)DATA16(a5 + 2u);
	t2 = mem_read32(a6 + 0x16u) + d7;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	*p_d7 = d7;
	*p_a5 = a5;
}

uint32_t func_012C1C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0, 5u);
	a6 = 0x181E0u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0x400u);
	mem_write16(a0 + 0x1Cu, 0x400u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6 = rom_015046;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0x3Au;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_012C58(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	if (mem_read16(a0 + 0xCu) < 0x10u)
	{
		func_01832A(a0);
		return d7;
	}
	d7_2 = mem_read16(a0 + 0x1Au);
	t1 = mem_read32(a0 + 0x12u) + d7_2;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	d7_2 = mem_read16(a0 + 0x1Cu);
	t2 = mem_read32(a0 + 0x16u) - d7_2;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	return d7_2;
}

void func_012C7E(uint32_t a0, uint32_t a6)
{
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x3800u);
	mem_write16(a6 + 0x42u, 0x500u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x12u) + 0x1000u;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	t2 = mem_read32(a6 + 0x16u) + 0x2000u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, mem_read8(a0 + 0x30u));
	mem_write16(a6 + 4u, 0u);
}

uint32_t func_012CB2(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, 0x81u);
	a6 = 0x181A4u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0x300u);
	mem_write16(a0 + 0x1Cu, 0xFD00u);
	mem_write16(a0 + 0x1Eu, 0u);
	d7 = mem_read8(a0 + 0x2Fu);
	d7 = (uint16_t)(d7 << 1);
	mem_write16(a0 + 0x20u, indexed_table_of_16_bit_values_012CFE[d7 / 2u]);
	a6 = rom_01504E;
	set_animation(0u, a0, a6);
	unk_06120C++;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7;
}

uint32_t func_012D06(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0xEu);
	if ((uint16_t)d7_2 < mem_read16(a0 + 0x20u))
	{
		mem_write32(a0, 0x81000900u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		mem_write16(a0 + 4u, 0u);
		unk_06120C--;
		return d7_2;
	}
	d7_2 = func_0182EE(a0);
	return d7_2;
}

void func_012D4E(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x86u);
	a6 = 0x181FEu;
	func_0180E0(a0, a6);
	a6 = rom_0152EE;
	if ((mem_read8(a0 + 3u) & 1u) != 0u)
		a6 = rom_0152F2;
	set_animation(0u, a0, a6);
	d7 = 0xAu;
	func_0091A4(d7, a6);
	mem_write16(a0 + 0x2Cu, 0x384u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	a6 = 0x171A0u;
	if ((int8_t)mem_read8(a0 + 3u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
		a6 = 0x171A8u;
	}
	mem_write32(a0 + 0x3Au, a6);
	func_01311C(a0, &d6, p_d7);
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	unk_06120C++;
	unk_06130A++;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_012DCE(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t t1 = 0;

	func_0130BE(a0);
	func_012F5C(a0, p_d5, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	mem_write8(a0 + 0x30u, 0u);
	if ((mem_read8(a0 + 3u) & 1u) != 0u)
	{
		mem_write8(a0 + 0x31u, 3u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		return;
	}
	mem_write8(a0 + 0x31u, 4u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_012E06(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	func_0130BE(a0);
	func_012F5C(a0, p_d5, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_01311C(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	a6 = 0x62A00u;
	*p_d7 = 8u;
	func_01830C(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_01311C(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	*p_d7 = func_013168(a0, a6);
	mem_write8(a0 + 0x30u, 5u);
}

void func_012E50(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	func_0130BE(a0);
	func_012F5C(a0, p_d5, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 2u);
		func_01311C(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	a6 = 0x62780u;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	*p_d7 = (*p_d7 & ~0xFFFFu) | (uint8_t)*p_d7;
	func_01830C(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 2u);
		func_01311C(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	func_01327A(a0, a6);
	mem_write8(a0 + 0x30u, 7u);
}

void func_012E9A(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d7 = 0;

	d7 = func_0130BE(a0);
	if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write8(a0 + 4u, 6u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write8(a0, mem_read8(a0) & ~6u);
		if (unk_06130A == 1u)
		{
			d7 = 9u;
			func_0091A4((uint8_t)d7, 0u);
		}
		a6 = 0x62780u;
		d7 = (d7 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			*p_d6 = 0u;
			d7 = 0u;
			mem_write16(a6, 0x100u);
			mem_write16(a6 + 2u, 0x3200u);
			mem_write16(a6 + 0x42u, 0xFF02u);
			func_01104A(a0, a6, p_d6, &d7);
			d7 = (d7 & ~0xFFu) | 0x11u;
			func_0091A4((uint8_t)d7, a6);
		}
	}
	else
	{
		mem_write8(a0 + 0x42u, 9u);
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 0x30u, 0x28u);
		mem_write8(a0, mem_read8(a0) & ~2u);
		d7 = (d7 & ~0xFFu) | 5u;
		func_0091A4((uint8_t)d7, 0u);
	}
	*p_d7 = d7;
}

uint32_t func_012F10(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t t1 = 0;

	d7 = func_013096(a0);
	if (mem_read8(a0 + 0x30u) == 0x20u)
		mem_write8(a0 + 0x42u, 0xFFu);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
	return d7;
}

void func_012F40(uint32_t a0)
{
	func_01831E(a0);
	if (mem_read8(a0) == 0u)
	{
		unk_06120C--;
		unk_06130A--;
	}
}

void func_012F5C(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d4 = 0, d7 = 0;
	uint32_t a6 = 0, d6 = 0, d7_2 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;
	uint32_t t1 = 0, t5 = 0, t6 = 0;

	d7 = mem_read8(a0 + 0x2Fu);
	t1 = mem_read32(a0 + 0x16u) + (int16_t)indexed_table_of_16_bit_values_013092[d7 & 1u];
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	if (mem_read32(a0 + 0x16u) >= 0x7800u || mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) ^ 1u);
	a6 = unk_0620F0_ADDRESS;
	d7_2 = 3u;
	d6 = 0u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d7_2 & 7u))) != 0u && (unk_0600A0 & shl32(1u, (int)(d7_2 & 7u))) == 0u && mem_read8(a6 + 4u) != 4u)
		{
			if ((mem_read8(a0) & 0x40u) != 0u)
			{
				if (d6 == 0u)
					d6 = 0x1FFu;
				if (mem_read16(a6 + 0xCu) <= d6)
				{
					d6 = mem_read16(a6 + 0xCu);
					d5 = 0u;
					t2 = mem_read16(a0 + 0xEu) - mem_read16(a6 + 0xEu);
					d4 = t2;
					if ((int16_t)t2 < 0)
						d4 = (uint16_t)~d4;
					if (d4 < 6u)
						d5 = 1u;
				}
			}
			else if (d6 < mem_read16(a6 + 0xCu))
			{
				d6 = mem_read16(a6 + 0xCu);
				d5 = 0u;
				t2 = mem_read16(a0 + 0xEu) - mem_read16(a6 + 0xEu);
				d4 = t2;
				if ((int16_t)t2 < 0)
					d4 = (uint16_t)~d4;
				if (d4 < 6u)
					d5 = 1u;
			}
		}
		t3 = d7_2 - 1u;
		d7_2 = t3;
		a6 -= 0x50u;
	} while (t3 != 0xFFFFu);
	t4 = mem_read16(a0 + 0x2Cu);
	mem_write16(a0 + 0x2Cu, t4 - 1u);
	if (t4 != 0u)
	{
		if (d6 != 0u)
		{
			d7 = (uint16_t)((unk_0600A4 & 0x3Fu) + 0x10u);
			if ((mem_read8(a0) & 0x40u) != 0u)
				d7 = (uint16_t)~d7;
			d6 = (uint16_t)(d6 + d7);
			d7_2 = 0xFF80u;
			if ((uint8_t)d5 != 0u)
				d7_2 = (uint16_t)(d7_2 << 2);
			d7_2 = (int16_t)d7_2;
			if (mem_read16(a0 + 0xCu) <= d6)
				d7_2 = ~d7_2;
			t5 = mem_read32(a0 + 0x12u) + d7_2;
			mem_write16(a0 + 0x14u, t5);
			mem_write16(a0 + 0x12u, t5 >> 16);
		}
	}
	else
	{
		mem_write16(a0 + 0x2Cu, 0u);
		t6 = mem_read32(a0 + 0x12u) - 0x100u;
		mem_write16(a0 + 0x14u, t6);
		mem_write16(a0 + 0x12u, t6 >> 16);
		if (mem_read16(a0 + 0xCu) < 0x10u)
		{
			unk_06120C--;
			unk_06130A--;
			if (unk_06130A == 0u)
			{
				d7_2 = 9u;
				func_0091A4((uint8_t)d7_2, a6);
			}
			func_01832A(a0);
		}
	}
	*p_d5 = d5;
	*p_d6 = d6;
	*p_d7 = d7_2;
}

uint32_t func_013096(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0;

	t1 = mem_read32(a0 + 0x12u) + 0x600u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	d7 = (uint8_t)unk_0600A4;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_0130F4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x4000u);
	mem_write16(a0 + 0x10u, d7);
	return d7;
}

uint32_t func_0130BE(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = (uint8_t)unk_0600A4;
	d7 = d7 & 0x3Cu;
	d7 = d7 >> 1;
	d7 = TABLE16(rom_0130FC, d7);
	d7 = (uint16_t)(d7 + 0x4000u);
	mem_write16(a0 + 0x10u, d7);
	func_0130DE(a0);
	return d7;
}

void func_0130DE(uint32_t a0)
{
	uint32_t t1 = 0;

	if (unk_060121 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
}

void func_01311C(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	d7 = 4u;
	func_048448(a0, &d6, &d7);
	a6 = indexed_table_of_8_bit_values_013150_ADDRESS;
	if ((mem_read8(a0 + 3u) & 1u) != 0u)
		a6 = 0x13154u;
	mem_write8(a0 + 0x30u, DATA8(a6 + d7));
	d7 = IN_PAGE(d7, unk_060094);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	mem_write8(a0 + 0x30u, mem_read8(a0 + 0x30u) - d7);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

uint32_t func_013168(uint32_t a0, uint32_t a6)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x4400u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x16u) - 1u;
	mem_write16(a6 + 0x18u, t1);
	mem_write16(a6 + 0x16u, t1 >> 16);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) - 0x2200u);
	d7 = 0x3800u;
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a6, mem_read8(a6) | 0x40u);
		d7 = 0xFFFFD500u;
	}
	t2 = mem_read32(a6 + 0x12u) - d7;
	mem_write16(a6 + 0x14u, t2);
	mem_write16(a6 + 0x12u, t2 >> 16);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	return d7;
}

uint32_t func_0131B8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	func_0130DE(a0);
	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x18208u;
	func_0180E0(a0, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0xFB00u;
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)~d7_2;
	}
	mem_write16(a0 + 0x1Au, d7_2);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0xFB00u);
	a6 = rom_015360;
	set_animation(0u, a0, a6);
	d7_2 = (d7_2 & ~0xFFu) | 0x17u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

uint32_t func_01320C(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	func_0130DE(a0);
	d7 = func_0182EE(a0);
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		mem_write8(a0 + 0x43u, 2u);
		a6 = rom_014AA6;
		set_animation(0u, a0, a6);
		return d7;
	}
	if ((int16_t)mem_read16(a0 + 0x10u) < 0)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = rom_015368;
		set_animation(0u, a0, a6);
		return d7;
	}
	return d7;
}

void func_013260(uint32_t a0)
{
	func_0130DE(a0);
	func_013264(a0);
}

void func_013264(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_01327A(uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x4600u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + 0x1000u);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
}

uint32_t func_0132A2(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	func_0130DE(a0);
	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x18212u;
	if (mem_read8(a0 + 3u) != 0u)
		a6 = 0x1821Cu;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0x300u);
	if (mem_read8(a0 + 3u) != 0u)
		mem_write16(a0 + 0x1Eu, 0x800u);
	a6 = rom_01536C;
	if (mem_read8(a0 + 3u) != 0u)
		a6 = rom_01534A;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 3u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	unk_06120C++;
	return d7_2;
}

uint32_t func_013310(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	func_0130DE(a0);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	t1 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t1 - d7_2);
	if ((uint16_t)d7_2 <= t1)
		return d7_2;
	mem_write16(a0 + 0x10u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7_2 & ~0xFFu) | 0x13u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = rom_015258;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_013340(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	unk_06120C--;
	func_01832A(a0);
}

void func_013354(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = 0, a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	a5 = unk_0620F0_ADDRESS;
	d5 = 3u;
	do
	{
		if ((unk_0600A1 & shl32(1u, (int)(d5 & 7u))) != 0u)
		{
			a6 = unk_0623C0_ADDRESS;
			d7 = (d7 & ~0xFFu) | 0xCu;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			func_01830C(&d7, &a6);
			if ((uint8_t)d7 != 0u)
				d7 = func_01338C(a5, a6);
		}
		t1 = d5 - 1u;
		d5 = t1;
		a5 -= 0x50u;
	} while (t1 != 0xFFFFu);
	*p_d5 = d5;
	*p_d7 = d7;
}

uint32_t func_01338C(uint32_t a5, uint32_t a6)
{
	uint32_t d7 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x4601u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	mem_write32(a6 + 0x12u, unk_061218 - 0x1A000u + ((uint32_t)mem_read16(a5 + 0xCu) << 8));
	d7 = unk_06121C - 0x10000u + ((uint32_t)mem_read16(a5 + 0xEu) << 8);
	mem_write32(a6 + 0x16u, d7);
	mem_write16(a6 + 0x10u, 0xF000u);
	mem_write8(a6 + 0x2Fu, 0u);
	mem_write16(a6 + 4u, 0u);
	return d7;
}

void func_0133FE(void)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	d0 = 6u;
	do
	{
		a6 = unk_0623C0_ADDRESS;
		d7 = 0xCu;
		func_01830C(&d7, &a6);
		if ((uint8_t)d7 != 0u)
			func_01342E(d0, a6);
		t1 = d0 - 1u;
		d0 = t1;
	} while (t1 != 0xFFFFu);
	unk_061311 = 0u;
	unk_061312 = 0u;
}

void func_01342E(uint16_t d0, uint32_t a6)
{
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x5400u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	mem_write32(a6 + 0x12u, 0x54C00u);
	mem_write32(a6 + 0x16u, 0x13800u);
	mem_write16(a6 + 0x10u, 0u);
	mem_write8(a6 + 0x2Cu, TABLE8(indexed_table_of_8_bit_values_013486, (uint32_t)(int16_t)d0));
	mem_write8(a6 + 0x2Du, 0u);
	mem_write8(a6 + 0x2Eu, mem_read8(0x1348Eu + (int16_t)d0));
	mem_write8(a6 + 0x2Bu, mem_read8(0x13496u + (int16_t)d0));
	mem_write8(a6 + 0x2Fu, (uint8_t)d0);
	mem_write16(a6 + 4u, 0u);
}

void func_01349E(void)
{
	unk_061311 = 1u;
	unk_061318 = 1u;
	unk_061319 = 0u;
}

void func_0134B6(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	switch (mem_read8(a0 + 5u))
	{
	case 0:
		*p_d7 = func_0134DA(a0);
		break;
	case 1:
		func_013524(a0, p_d6, p_d7);
		break;
	case 2:
		func_013562(a0, p_d6, p_d7);
		break;
	case 3:
		func_01358C(a0, p_d6, p_d7, p_a5);
		break;
	}
}

uint32_t func_0134DA(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	unk_06120C++;
	unk_061312++;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x2Au, (uint32_t)mem_read8(a0 + 0x2Fu) << 2);
	d7 = func_01385E(a0);
	mem_write16(a0 + 0x22u, 0u);
	mem_write16(a0 + 0x20u, 0u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	a6 = 0x18262u;
	func_0180E0(a0, a6);
	a6 = rom_01587E;
	set_animation(0u, a0, a6);
	return d7;
}

void func_013524(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = *p_d6;

	*p_d7 = func_01385E(a0);
	if (unk_061311 != 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write32(a0 + 0x3Au, 0x17958u);
		mem_write32(a0 + 0x12u, 0x54C00u);
		mem_write32(a0 + 0x16u, 0x8800u);
		mem_write8(a0 + 0x30u, 0x12u);
		func_013918(a0, &d6, p_d7);
	}
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | (d6 & 0xFFu);
}

void func_013562(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t t1 = 0;

	func_0138F4(a0, p_d6, p_d7);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 0u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	else
	{
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x100u);
		if (mem_read16(a0 + 0x10u) >= 0x2C00u)
			mem_write16(a0 + 0x10u, 0x2C00u);
	}
}

void func_01358C(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = 0, ignored = 0, ignored_2 = 0;

	mem_write8(a0, mem_read8(a0) | 2u);
	func_011DFA(a0, &ignored, &ignored_2, p_d7, p_a5);
	if ((uint8_t)*p_d7 == 0u)
	{
		mem_write16(a0 + 0x22u, 0u);
		mem_write16(a0 + 0x20u, 0u);
	}
	func_0139B2(a0, &d6, p_d7);
	mem_write16(a0 + 0x24u, 0x708u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 5u, 0u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0135B4(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	if (mem_read16(a0 + 0x24u) != 0u)
	{
		mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) - 1u);
		func_013884(a0);
		func_013724(a0, p_d6, &ignored, p_a5);
		func_013918(a0, p_d6, p_d7);
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 0u)
		{
			mem_write8(a0 + 0x30u, 0u);
			mem_write8(a0 + 0x31u, 4u);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			return;
		}
		return;
	}
	func_013724(a0, p_d6, &ignored, p_a5);
	func_013918(a0, p_d6, p_d7);
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x10u) + 1u);
	if (mem_read8(a0 + 0x10u) < 0xE0u)
	{
		return;
	}
	unk_06120C--;
	unk_061312--;
	func_01832A(a0);
}

void func_01360C(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	*p_d7 = func_013884(a0);
	func_013724(a0, p_d6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	t2 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t2 - 1u);
	if (t2 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_0139B2(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	a6 = 0x62A00u;
	*p_d7 = 8u;
	func_01830C(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		func_0139B2(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
		return;
	}
	func_013A8C(a0, a6, p_d6, p_d7, p_a5);
	mem_write8(a0 + 0x30u, 7u);
}

uint32_t func_013656(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint32_t t1 = 0;

	if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write8(a0 + 4u, 6u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0, mem_read8(a0) & ~6u);
		a6 = rom_015882;
		set_animation(0u, a0, a6);
		a6 = 0x62780u;
		d7_2 = (d7 & ~0xFFu) | 8u;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
		func_01830C(&d7_2, &a6);
		if ((uint8_t)d7_2 == 0u)
			return d7_2;
		mem_write16(a6, 0x100u);
		mem_write16(a6 + 2u, 0x5700u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		func_018574(a0, a6);
		t1 = mem_read32(a6 + 0x16u) - 0x1600u;
		mem_write16(a6 + 0x18u, t1);
		mem_write16(a6 + 0x16u, t1 >> 16);
		mem_write8(a6 + 0x2Fu, 0u);
		mem_write16(a6 + 4u, 0u);
		d7_2 = (d7_2 & ~0xFFu) | 0x11u;
		func_0091A4((uint8_t)d7_2, a6);
		return d7_2;
	}
	mem_write8(a0 + 0x42u, 8u);
	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x1Eu);
	mem_write8(a0, mem_read8(a0) & ~2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, 0u);
	return d7_2;
}

uint32_t func_0136BA(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t t1 = 0;

	d7 = func_013704(a0);
	if (mem_read8(a0 + 0x30u) == 0x16u)
		mem_write8(a0 + 0x42u, 0xFFu);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
	return d7;
}

void func_0136EA(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	unk_06120C--;
	unk_061312--;
	func_01832A(a0);
}

uint32_t func_013704(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = (uint8_t)unk_0600A4;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_0138AC[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2C00u);
	mem_write16(a0 + 0x10u, d7);
	return d7;
}

void func_013724(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d6 = 0, d7_2 = 0, ignored = 0;
	uint16_t t1 = 0;
	uint32_t t2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | unk_0600A4;
	t1 = d7_2 & 0x7Fu;
	d7_2 = (d7_2 & ~0xFFFFu) | t1;
	if (t1 == 0u)
	{
		func_011DFA(a0, &ignored, p_d6, &d7_2, p_a5);
		if ((uint8_t)d7_2 == 0u)
		{
			mem_write16(a0 + 0x22u, 0u);
			mem_write16(a0 + 0x20u, 0u);
		}
	}
	a6 = mem_read32(a0 + 0x20u);
	if (a6 != 0u)
	{
		if (mem_read16(a0 + 0xCu) < mem_read16(a6 + 0xCu))
		{
			if (mem_read8(a0 + 0x2Eu) != 0u)
			{
				mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) - mem_read8(a0 + 0x2Bu));
				mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
				if (mem_read8(a0 + 0x2Cu) == 0xCu)
					mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
			}
			else
			{
				mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) + mem_read8(a0 + 0x2Bu));
				mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
				if (mem_read8(a0 + 0x2Cu) == 4u)
					mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
			}
		}
		else if (mem_read8(a0 + 0x2Eu) != 0u)
		{
			mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) - mem_read8(a0 + 0x2Bu));
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
			if (mem_read8(a0 + 0x2Cu) == 4u)
				mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
		}
		else
		{
			mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) + mem_read8(a0 + 0x2Bu));
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
			if (mem_read8(a0 + 0x2Cu) == 0xCu)
				mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
		}
		d6 = 0x100u;
		if (mem_read16(a6 + 0xEu) <= mem_read16(a0 + 0xEu))
			d6 = ~d6;
		t2 = mem_read32(a0 + 0x16u) + d6;
		mem_write16(a0 + 0x18u, t2);
		mem_write16(a0 + 0x16u, t2 >> 16);
		func_0138F4(a0, p_d6, &d7_2);
		func_01381E(a0);
	}
	*p_d7 = d7_2;
}

void func_01381E(uint32_t a0)
{
	uint32_t t1 = 0;

	if (mem_read16(a0 + 0xCu) < 0x20u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x2000u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	if (mem_read32(a0 + 0x16u) >= 0x7C00u)
	{
		mem_write32(a0 + 0x16u, 0x7C00u);
		return;
	}
	if (mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
	{
		mem_write32(a0 + 0x16u, func_001000_ADDRESS);
		return;
	}
}

uint32_t func_01385E(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 0x2Au);
	d7 = (uint16_t)(d7 << 1);
	d7 = rom_0138B4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2000u);
	mem_write16(a0 + 0x10u, d7);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) + 1u);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) & 0x1Fu);
	return d7;
}

uint32_t func_013884(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 0x2Au);
	d7 = d7 & 0x3Eu;
	d7 = rom_0138B4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2C00u);
	mem_write16(a0 + 0x10u, d7);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) + 1u);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) & 0x3Fu);
	return d7;
}

void func_0138F4(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	d7 = mem_read8(a0 + 0x2Cu);
	d7 = (uint16_t)(d7 << 2);
	t1 = mem_read32(a0 + 0x12u) + (int16_t)rom_0139DA[d7 / 2u];
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	*p_d6 = (int16_t)rom_0139DC[d7 / 2u];
	t2 = mem_read32(a0 + 0x16u) + *p_d6;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	*p_d7 = d7;
}

void func_013918(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;

	if (mem_read32(a0 + 0x20u) == 0u)
	{
		d7 = mem_read8(a0 + 0x2Cu);
		d7 = indexed_table_of_8_bit_values_0139A2[d7];
		mem_write8(a0, mem_read8(a0) & 0xBFu);
		if ((int8_t)d7 < 0)
		{
			d7 = d7 & 0x7Fu;
			mem_write8(a0, mem_read8(a0) | 0x40u);
		}
	}
	else
	{
		mem_write8(a0, mem_read8(a0) & 0xBFu);
		if (mem_read16(a0 + 0xCu) < mem_read16(mem_read32(a0 + 0x20u) + 0xCu))
			mem_write8(a0, mem_read8(a0) | 0x40u);
		d7 = mem_read8(a0 + 0x2Cu);
		d7 = indexed_table_of_8_bit_values_0139A2[d7];
		d7 = d7 & 3u;
	}
	mem_write8(a0 + 0x2Fu, d7);
	d7 = (uint16_t)(d7 << 4);
	d6 = (uint8_t)(((uint8_t)unk_0600A4 & 3u) << 2);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + d6);
	a6 = rom_01584E[d7 / 4u];
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
	*p_d7 = d7;
}

void func_0139B2(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0, d7 = 0;

	d7 = 4u;
	func_048448(a0, &d6, &d7);
	mem_write8(a0 + 0x30u, indexed_table_of_8_bit_values_0139D6[d7]);
	d7 = IN_PAGE(d7, unk_060094);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	mem_write8(a0 + 0x30u, mem_read8(a0 + 0x30u) - d7);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_013A1A(uint32_t a0)
{
	uint8_t d7_2 = 0;
	uint32_t d7 = 0, ignored = 0;
	uint8_t t1 = 0;

	if (unk_060121 != 7u || unk_061318 == 0u)
		return;
	if (unk_061312 == 0u)
	{
		unk_061318 = 0u;
		unk_061319 = 0u;
		return;
	}
	t1 = unk_061319;
	unk_061319 = t1 - 1u;
	if (t1 != 0u)
		return;
	d7 = 4u;
	func_048448(a0, &ignored, &d7);
	unk_061319 = indexed_table_of_8_bit_values_013A74[d7];
	d7_2 = 0x38u;
	func_0091A4(d7_2, 0u);
}

void func_013A8C(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a5 = 0, d6 = 0, d7 = 0;
	uint32_t t1 = 0;

	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x5500u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	func_018574(a0, a6);
	a5 = indexed_table_of_16_bit_values_013AE4_ADDRESS;
	d7 = 0u;
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a6, mem_read8(a6) | 0x40u);
		d7 = 3u;
	}
	d7 = (uint8_t)(d7 + mem_read8(a0 + 0x2Fu));
	d7 = (uint16_t)(d7 << 2);
	d6 = (int16_t)DATA16(a5 + d7);
	t1 = mem_read32(a6 + 0x12u) + d6;
	mem_write16(a6 + 0x14u, t1);
	mem_write16(a6 + 0x12u, t1 >> 16);
	d6 = (d6 & ~0xFFFFu) | DATA16(a5 + 2u + d7);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) + d6);
	mem_write8(a6 + 0x2Fu, mem_read8(a0 + 0x2Fu));
	mem_write16(a6 + 4u, 0u);
	*p_d6 = d6;
	*p_d7 = d7;
	*p_a5 = a5;
}

uint32_t func_013AFC(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	a6 = 0x1826Cu;
	func_0180E0(a0, a6);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
	a6 = rom_015938[mem_read8(a0 + 0x2Fu) * 2u];
	set_animation(0u, a0, a6);
	a6 = indexed_table_of_16_bit_values_013B72_ADDRESS;
	d7 = 0u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d7 = 3u;
	d7 = (uint8_t)(d7 + mem_read8(a0 + 0x2Fu));
	d7 = (uint16_t)(d7 << 2);
	mem_write16(a0 + 0x1Au, DATA16(a6 + d7));
	mem_write16(a0 + 0x1Cu, DATA16(a6 + 2u + d7));
	mem_write16(a0 + 0x1Eu, 0xFC00u);
	d7 = IN_PAGE(d7, 0x14u);
	func_0091A4((uint8_t)d7, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7;
}

uint32_t func_013B8A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		d7 = mem_read8(a0 + 0x2Fu);
		d7 = (uint16_t)(d7 << 3);
		a6 = rom_01593C[d7 / 4u];
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0, mem_read8(a0) & ~4u);
	}
	return d7;
}

uint32_t func_013BB6(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	d7 = func_0182EE(a0);
	func_01381E(a0);
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		mem_write8(a0 + 0x43u, 2u);
		a6 = rom_014AA6;
		set_animation(0u, a0, a6);
		return d7;
	}
	if ((int16_t)mem_read16(a0 + 0x10u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 4u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = rom_015950;
		set_animation(0u, a0, a6);
		return d7;
	}
	return d7;
}

void func_013C0C(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_013C32(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = 0;

	d7 = mem_read8(a0 + 5u);
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		func_013C56(a0);
		break;
	case 4:
		func_013CAC(a0, &d7, p_a5);
		break;
	case 8:
		d7 = func_013CE4(d7, a0);
		break;
	case 12:
		func_013D30(d0, a0, &d5, &d6, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_013C56(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write32(a0 + 0x3Au, 0x17C20u);
	a6 = 0x1828Au;
	func_0180E0(a0, a6);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 8u));
	a6 = rom_015C70;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0u);
	unk_061313 = 0u;
	mem_write8(a0 + 0x2Fu, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	unk_06120C++;
}

void func_013CAC(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint8_t d7_2 = 0;
	uint16_t d7_3 = 0;
	uint32_t a6 = 0;

	if (unk_06120C != 1u)
		return;
	d7_2 = 0xFEu;
	unk_060080 = 0xFEu;
	func_0091A4(d7_2, 0u);
	a6 = 0xC6C4u;
	d7_3 = 0x43Cu;
	*p_a5 = post_palette_request(d7_3, a6);
	mem_write8(a0 + 0x30u, 0x64u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

uint32_t func_013CE4(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	if (unk_060083 == 0u)
	{
		t1 = mem_read8(a0 + 0x30u);
		mem_write8(a0 + 0x30u, t1 - 1u);
		if (t1 == 1u)
		{
			d7_2 = 0x33u;
			func_0091A4((uint8_t)d7_2, 0u);
			d7_2 = 0x64u;
			unk_060080 = d7_2;
			func_0091A4((uint8_t)d7_2, 0u);
			d7 = 0xBFu;
			func_0091A4((uint8_t)d7, 0u);
			mem_write16(a0 + 0x1Au, 0xFD00u);
			mem_write16(a0 + 0x1Cu, 0u);
			mem_write16(a0 + 0x1Eu, 0x100u);
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		}
	}
	return d7;
}

void func_013D30(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0_2 = 0, d1 = 0, d2 = 0;
	uint32_t ignored = 0;

	func_014252(a0);
	*p_d7 = func_0182EE(a0);
	if (mem_read32(a0 + 0x12u) < 0x47000u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 0x2Cu, 0x800u);
		mem_write8(a0 + 0x2Eu, 1u);
		mem_write8(a0 + 0x2Bu, 0x20u);
		mem_write8(a0 + 0x2Au, 0u);
		mem_write16(a0 + 0x22u, 0u);
		mem_write16(a0 + 0x20u, 0u);
		mem_write16(a0 + 0x24u, 0xE10u);
		func_011DFA(a0, &d0, &ignored, p_d7, p_a5);
		if ((uint8_t)*p_d7 == 0u)
		{
			mem_write16(a0 + 0x22u, 0u);
			mem_write16(a0 + 0x20u, 0u);
		}
		func_014218(a0, &d6, p_d7);
		d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
		d1 = mem_read16(a0 + 0xCu);
		d2 = (uint16_t)(mem_read16(a0 + 0xEu) + 0x20u);
		func_030084(d0_2, d1, d2, &d5, &d6, p_d7);
		mem_write16(a0 + 0x10u, 0x2C00u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		mem_write8(a0 + 5u, 0u);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_013DA8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d7 = 0;
	uint8_t t1 = 0;

	func_014252(a0);
	if (mem_read16(a0 + 0x24u) == 0u)
	{
		func_013FC8(a0, p_d6, p_d7, p_a5);
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x10u) + 1u);
		if (mem_read8(a0 + 0x10u) >= 0xE0u)
		{
			unk_06120C--;
			func_01832A(a0);
		}
		return;
	}
	mem_write16(a0 + 0x24u, mem_read16(a0 + 0x24u) - 1u);
	func_014120(a0, p_d5, p_d6, p_d7);
	func_013FC8(a0, p_d6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 != 0u)
	{
		return;
	}
	func_0142AA(p_d5, p_d6, &d7);
	d7 = indexed_table_of_8_bit_values_013E30[d7];
	if (unk_06120C <= d7)
	{
		a6 = unk_0623C0_ADDRESS;
		*p_d7 = 0xCu;
		func_01830C(p_d7, &a6);
		if ((uint8_t)*p_d7 != 0u)
		{
			*p_a5 = func_0142D6(a0, *p_a5, a6);
			a6 = rom_015C74;
			set_animation(0u, a0, a6);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			return;
		}
	}
	func_014218(a0, p_d6, p_d7);
}

void func_013E36(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	func_014252(a0);
	func_014120(a0, p_d5, p_d6, p_d7);
	func_013FC8(a0, p_d6, p_d7, p_a5);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
		a6 = rom_015C70;
		set_animation(0u, a0, a6);
		func_014218(a0, p_d6, p_d7);
		mem_write8(a0 + 0x31u, 0u);
	}
}

void func_013E64(void)
{
}

uint32_t func_013E66(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	func_014252(a0);
	if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write8(a0 + 4u, 6u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a0 + 0x2Fu, 0u);
		mem_write8(a0, mem_read8(a0) & ~6u);
		a6 = rom_015C7C;
		set_animation(0u, a0, a6);
		return d7;
	}
	mem_write8(a0 + 9u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x30u, 0x1Eu);
	mem_write8(a0, mem_read8(a0) & ~2u);
	a6 = rom_015C78;
	set_animation(0u, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 5u;
	func_0091A4((uint8_t)d7_2, a6);
	return d7_2;
}

void func_013EC0(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_014252(a0);
	func_013F82(a0, p_d5, p_d6, p_d7);
	func_013FC8(a0, p_d6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = rom_015C70;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 9u, 1u);
		mem_write8(a0 + 4u, 1u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

void func_013EF4(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = mem_read8(a0 + 5u);
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		func_013F14(a0, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_013F44(a0);
		return;
	case 8:
		func_013F72(a0);
		return;
	}
}

void func_013F14(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d7_3 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_014252(a0);
	mem_write8(a0 + 0x30u, 0xCu);
	mem_write8(a0 + 5u, 1u);
	a6 = 0x62780u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	func_01830C(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d7_3 = (uint16_t)((uint32_t)mem_read8(a0 + 0x2Fu) << 2);
		d6 = indexed_table_of_16_bit_values_010F62[d7_3 / 2u];
		d7_3 = rom_010F64[d7_3 / 2u];
		d6 = func_010F80(d6, d7_3, a0, a6);
		*p_a5 = rom_010F44_ADDRESS;
		d7_2 = mem_read8(a0 + 0x2Fu);
		d7_2 = d7_2 & 1u;
		d7_2 = rom_010F44[d7_2];
		func_0091A4((uint8_t)d7_2, a6);
	}
	else
		mem_write8(a0 + 5u, 2u);
	*p_d6 = d6;
	*p_d7 = d7_2;
}

void func_013F44(uint32_t a0)
{
	uint8_t t1 = 0;

	func_014252(a0);
	t1 = mem_read8(a0 + 0x30u);
	mem_write8(a0 + 0x30u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
		mem_write8(a0 + 0x2Fu, mem_read8(a0 + 0x2Fu) + 1u);
		unk_061313 = 1u;
		if (mem_read8(a0 + 0x2Fu) == 4u)
			mem_write8(a0 + 5u, 2u);
	}
}

void func_013F72(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	unk_06120C--;
	func_01832A(a0);
}

void func_013F82(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d5 = 0, d6 = 0, d7 = 0;

	d7 = (uint8_t)unk_0600A4;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_01416E[d7 / 2u];
	a6 = 0x14176u;
	d5 = 0u;
	d6 = mem_read32(a0 + 0x16u);
	do
	{
		if ((uint16_t)d6 < DATA16(a6))
			break;
		d5 = (uint16_t)(d5 + 2u);
	} while ((uint8_t)d5 < 0x1Eu);
	d6 = (d6 & ~0xFFFFu) | mem_read16(0x14194u + (int16_t)d5);
	d7 = (uint16_t)(d7 + d6);
	mem_write16(a0 + 0x10u, d7);
	*p_d5 = d5;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_013FC8(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d6 = 0, d7_2 = 0, ignored = 0;
	uint16_t t1 = 0;
	uint32_t t2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | unk_0600A4;
	t1 = d7_2 & 0x3Fu;
	d7_2 = (d7_2 & ~0xFFFFu) | t1;
	if (t1 == 0u)
	{
		func_011DFA(a0, &ignored, p_d6, &d7_2, p_a5);
		if ((uint8_t)d7_2 == 0u)
		{
			mem_write16(a0 + 0x22u, 0u);
			mem_write16(a0 + 0x20u, 0u);
		}
	}
	a6 = mem_read32(a0 + 0x20u);
	if (a6 != 0u)
	{
		if (mem_read16(a0 + 0xCu) < mem_read16(a6 + 0xCu))
		{
			if (mem_read8(a0 + 0x2Eu) != 0u)
			{
				mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) - mem_read8(a0 + 0x2Bu));
				mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
				if (mem_read8(a0 + 0x2Cu) == 0xCu)
					mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
			}
			else
			{
				mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) + mem_read8(a0 + 0x2Bu));
				mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
				if (mem_read8(a0 + 0x2Cu) == 4u)
					mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
			}
		}
		else if (mem_read8(a0 + 0x2Eu) != 0u)
		{
			mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) - mem_read8(a0 + 0x2Bu));
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
			if (mem_read8(a0 + 0x2Cu) == 4u)
				mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
		}
		else
		{
			mem_write16(a0 + 0x2Cu, mem_read16(a0 + 0x2Cu) + mem_read8(a0 + 0x2Bu));
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) & 0xFu);
			if (mem_read8(a0 + 0x2Cu) == 0xCu)
				mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) ^ 1u);
		}
		d6 = 0x100u;
		if (mem_read16(a6 + 0xEu) <= mem_read16(a0 + 0xEu))
			d6 = ~d6;
		t2 = mem_read32(a0 + 0x16u) + d6;
		mem_write16(a0 + 0x18u, t2);
		mem_write16(a0 + 0x16u, t2 >> 16);
		func_0141F4(a0, p_d6, &d7_2);
		func_0140C2(a0);
	}
	*p_d7 = d7_2;
}

void func_0140C2(uint32_t a0)
{
	if (mem_read32(a0 + 0x12u) >= 0x47000u)
		mem_write32(a0 + 0x12u, 0x47000u);
	else if (mem_read32(a0 + 0x12u) < 0x3C000u)
		mem_write32(a0 + 0x12u, 0x3C000u);
	if (mem_read32(a0 + 0x16u) >= 0x7800u)
	{
		mem_write32(a0 + 0x16u, 0x7800u);
		return;
	}
	if (mem_read32(a0 + 0x16u) < 0x1800u)
	{
		mem_write32(a0 + 0x16u, 0x1800u);
		return;
	}
}

void func_014120(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d5 = 0, d6 = 0, d7 = 0;

	d7 = mem_read8(a0 + 0x2Au);
	d7 = d7 & 0x3Eu;
	d7 = rom_0141B4[d7 / 2u];
	a6 = 0x14176u;
	d5 = 0u;
	d6 = mem_read32(a0 + 0x16u);
	do
	{
		if ((uint16_t)d6 < DATA16(a6))
			break;
		d5 = (uint16_t)(d5 + 2u);
	} while ((uint8_t)d5 < 0x1Eu);
	d6 = (d6 & ~0xFFFFu) | mem_read16(0x14194u + (int16_t)d5);
	d7 = (uint16_t)(d7 + d6);
	mem_write16(a0 + 0x10u, d7);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) + 1u);
	mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) & 0x3Fu);
	*p_d5 = d5;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_0141F4(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	d7 = mem_read8(a0 + 0x2Cu);
	d7 = (uint16_t)(d7 << 2);
	t1 = mem_read32(a0 + 0x12u) + (int16_t)indexed_table_of_16_bit_values_01426A[d7 / 2u];
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	*p_d6 = (int16_t)rom_01426C[d7 / 2u];
	t2 = mem_read32(a0 + 0x16u) + *p_d6;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	*p_d7 = d7;
}

void func_014218(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t zero = 0;
	uint32_t d6 = 0, d7 = 0;
	uint8_t t1 = 0, t2 = 0;

	d7 = 8u;
	func_048448(a0, &d6, &d7);
	mem_write8(a0 + 0x30u, indexed_table_of_8_bit_values_01424A[d7]);
	d7 = IN_PAGE(d7, unk_060094);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	t1 = mem_read8(a0 + 0x30u);
	t2 = t1 - d7;
	zero = t2 == 0u;
	mem_write8(a0 + 0x30u, t2);
	if (t1 < (uint8_t)d7 || zero)
		mem_write8(a0 + 0x30u, 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_014252(uint32_t a0)
{
	mem_write8(a0 + 0x32u, 0u);
	if (mem_read32(a0 + 0x16u) >= 0x6000u)
		mem_write8(a0 + 0x32u, 0x18u);
}

void func_0142AA(uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d5 = 0;
	uint32_t d6 = 0, d7 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d7 = 0u;
	d6 = 3u;
	d5 = unk_0600A1;
	do
	{
		t1 = d5 >> 1;
		d5 = t1;
		if (t1 != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t2 = d6 - 1u;
		d6 = t2;
	} while (t2 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = d6;
	*p_d7 = d7;
}

uint32_t func_0142D6(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint32_t a5_2 = 0;
	uint32_t t1 = 0;

	if (mem_read32(a0 + 0x16u) >= 0x3800u && mem_read32(a0 + 0x16u) < 0x6800u)
		return a5;
	mem_write16(a6, 0x100u);
	mem_write16(a6 + 2u, 0x5E00u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	mem_write8(a6 + 1u, mem_read8(a6 + 1u) | 0x80u);
	a5_2 = 0x17C38u;
	mem_write32(a6 + 0x3Au, 0x17C38u);
	func_018574(a0, a6);
	t1 = mem_read32(a6 + 0x16u) + 0x280u;
	mem_write16(a6 + 0x18u, t1);
	mem_write16(a6 + 0x16u, t1 >> 16);
	mem_write16(a6 + 0x10u, mem_read16(a6 + 0x10u) - 0x800u);
	mem_write8(a6 + 0x2Fu, 0u);
	unk_06120C++;
	mem_write16(a6 + 4u, 0u);
	return a5_2;
}

void func_014336(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, 0x81u);
	a6 = 0x18294u;
	func_0180E0(a0, a6);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0x400u);
	a6 = rom_015D4A;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_014366(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	t1 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t1 - d7_2);
	if (t1 < (uint16_t)d7_2)
		mem_write16(a0 + 0x10u, 0u);
	if (mem_read32(a0 + 0x16u) >= 0x4800u)
	{
		if (mem_read16(a0 + 0x10u) >= 0x1800u)
		{
			func_0143BA();
			return d7_2;
		}
		mem_write16(a0 + 0x10u, 0x1800u);
		mem_write8(a0 + 0x32u, 0x18u);
		mem_write32(a0, 0x81004E80u);
		mem_write16(a0 + 4u, 0u);
		unk_06120C--;
		func_0143BA();
		return d7_2;
	}
	if (mem_read16(a0 + 0x10u) != 0u)
	{
		func_0143BA();
		return d7_2;
	}
	mem_write8(a0 + 0x32u, 0u);
	mem_write32(a0, 0x81004E80u);
	mem_write16(a0 + 4u, 0u);
	unk_06120C--;
	func_0143BA();
	return d7_2;
}

void func_0143BA(void)
{
}

void func_0143BC(uint32_t a0)
{
	mem_write32(a0, 0x81004E00u);
	mem_write16(a0 + 4u, 0u);
	mem_write8(a0 + 0x32u, 0u);
	unk_06120C--;
}
