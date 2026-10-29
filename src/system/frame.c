/**
 *    Name:        system/frame.c
 *    Description: the VBLANK interrupt: the inputs, the frame's work, the game's states and the job queue
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_003B5C(void)
{
	uint32_t carry = 0;
	uint8_t d0_2 = 0, d7 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, d0 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	unk_060327 = 0u;
	d7 = unk_060058 | 1u;
	a0 = 0x60300u;
	d6 = 3u;
	if (unk_060302 == 0u)
	{
		d6 = (uint8_t)(d6 - 1u);
		a0 += 8u;
		if (unk_06030A == 0u)
		{
			d6 = (uint8_t)(d6 - 1u);
			a0 += 8u;
			if (unk_060312 == 0u)
			{
				d6 = (uint8_t)(d6 - 1u);
				a0 += 8u;
				if (unk_06031A == 0u)
				{
					a0 = 0x60300u;
					d6 = 3u;
				}
			}
		}
	}
	for (;;)
	{
		func_003CB0(a0);
		if (mem_read8(a0 + 5u) != 0u)
			break;
		if (mem_read8(a0 + 2u) == 0u)
		{
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 8u;
			if (t1 != 0xFFFFu)
				continue;
		}
		d7 &= ~1u;
		break;
	}
	unk_060058 = d7;
	io_write8(IO_0A0001, d7);
	d0 = func_003BFE(0u);
	unk_060325 = d0;
	d0_2 = unk_060325;
	a0 = 0x60300u;
	d6 = 3u;
	do
	{
		carry = d0_2 & 1u;
		d0_2 = d0_2 >> 1;
		if (carry)
			func_003CE8(a0);
		t2 = d6 - 1u;
		d6 = t2;
		a0 += 8u;
	} while (t2 != 0xFFFFu);
	d0_2 = unk_060325 >> 4;
	a0 = 0x60300u;
	d6 = 3u;
	do
	{
		carry = d0_2 & 1u;
		d0_2 = d0_2 >> 1;
		if (carry)
		{
			unk_060327 = 1u;
			t3 = mem_read16(a0 + 6u);
			carry = (uint16_t)(t3 + 1u) < t3;
			mem_write16(a0 + 6u, t3 + 1u);
			if (carry)
				mem_write16(a0 + 6u, mem_read16(a0 + 6u) - 1u);
		}
		t4 = d6 - 1u;
		d6 = t4;
		a0 += 8u;
	} while (t4 != 0xFFFFu);
}

uint32_t func_003BFE(uint32_t d0)
{
	uint8_t d7 = 0;
	uint32_t d0_2 = 0;
	uint8_t t1 = 0;

	d0_2 = (d0 & ~0xFFu) | unk_060044;
	d0_2 = d0_2 | unk_060045;
	d0_2 = (d0_2 & ~0xFFu) | (uint8_t)~d0_2;
	t1 = d0_2 & unk_060046;
	d0_2 = (d0_2 & ~0xFFu) | t1;
	if (t1 == 0u || unk_060001 == 3u)
		return d0_2;
	if (unk_0600A3 != 0u)
	{
		d7 = 0x86u;
		func_0091D4(d7);
	}
	else
	{
		d7 = 0xFFu;
		func_0091D4(d7);
		d7 = 0x86u;
		func_0091D4(d7);
		unk_060152 = 1u;
	}
	return d0_2;
}

void func_003CB0(uint32_t a0)
{
	uint8_t d0 = 0, d1 = 0;
	uint8_t t1 = 0;

	d1 = 0u;
	t1 = mem_read8(a0 + 2u);
	d0 = t1;
	if (t1 == 0u)
	{
		if (mem_read8(a0) != 0u)
		{
			mem_write8(a0, mem_read8(a0) - 1u);
			mem_write8(a0 + 5u, d1 + 1u);
			mem_write8(a0 + 2u, 0x3Cu);
		}
		return;
	}
	d0--;
	mem_write8(a0 + 2u, d0);
	if (d0 != 0x1Eu)
		return;
	mem_write8(a0 + 5u, d1);
}

void func_003CE8(uint32_t a0)
{
	uint32_t carry = 0;
	uint16_t d7 = 0;
	uint16_t t1 = 0;

	mem_write8(a0, mem_read8(a0) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) + 1u);
	if (mem_read8(a0 + 1u) != unk_060303)
		return;
	unk_060327 = 1u;
	d7 = unk_060304;
	t1 = mem_read16(a0 + 6u);
	carry = (uint16_t)(d7 + t1) < d7;
	d7 += t1;
	if (carry == 0u)
		mem_write16(a0 + 6u, d7);
	mem_write8(a0 + 1u, 0u);
}

void func_003D1E(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d4 = (uint16_t)*p_d4;
	uint32_t d5 = *p_d5;
	uint32_t carry = 0, extend = 0;
	uint8_t d3 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a1 = 0, d6_2 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a0 = 0x60300u;
	a1 = unk_060100_ADDRESS;
	d7 = 3u;
	d3 = 0u;
	do
	{
		t1 = mem_read16(a0 + 6u);
		d6 = t1;
		if (t1 != 0u)
		{
			unk_0600A2 |= shl32(1u, (int)(d3 & 7u));
			d6 = (uint16_t)((d6 & ~0xFFu) | (uint8_t)(d6 - 1u));
			do
			{
				d5 = unk_060090;
				d4 = mem_read16(a1);
				extend = 0u;
				carry = m68k_abcd_cy((uint8_t)d4, d5, extend);
				d4 = (uint16_t)((d4 & ~0xFFu) | m68k_abcd((uint8_t)d4, d5, extend));
				if (carry)
				{
					d4 += 0x100u;
					if (d4 >= 0x999u)
						d4 = 0x999u;
				}
				mem_write16(a1, d4);
				mem_write16(a0 + 6u, mem_read16(a0 + 6u) - 1u);
				t2 = d6 - 1u;
				d6 = t2;
			} while (t2 != 0xFFFFu);
		}
		d3++;
		t3 = d7 - 1u;
		d7 = t3;
		a0 += 8u;
		a1 += 8u;
	} while (t3 != 0xFFFFu);
	a0 = unk_060118_ADDRESS;
	d7_2 = 3u;
	d6_2 = 0u;
	do
	{
		if (mem_read16(a0) != 0u)
		{
			d6_2 |= shl32(1u, (int)(d7_2 & 0x1Fu));
			unk_0600B3 &= ~shl32(1u, (int)(d7_2 & 7u));
		}
		t4 = d7_2 - 1u;
		d7_2 = t4;
		a0 -= 8u;
	} while (t4 != 0xFFFFu);
	unk_0600B7 = d6_2;
	*p_d4 = (*p_d4 & 0xFFFF0000u) | d4;
	*p_d5 = d5;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

void unreached_003DAA(uint8_t d0)
{
	uint16_t d1 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0;

	a0 = TILE_RAM + 0x11Au;
	d1 = 0x1Bu;
	do
	{
		mem_write8(a0, 0u);
		mem_write8(a0 + 1u, d0);
		a0 += 0x80u;
		t1 = d1 - 1u;
		d1 = t1;
	} while (t1 != 0xFFFFu);
}

void func_003DC4(void)
{
	uint32_t a5 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;

	unk_060058 &= 0xDFu;
	io_write8(IO_0A0001, unk_060058);
	io_write8(IO_0A0011, 0u);
	write_status(0u);
	take_interrupts();
	unk_0600A4++;
	unk_060152 = 0u;
	d6 = func_009202(0u);
	d7 = func_003E70(0u);
	if (unk_060001 != 3u)
	{
		func_003B5C();
		func_003D1E(&d4, &d5, &d6, &d7);
	}
	func_009272(d4, &d5, &d6, &d7, &a5);
	step_palette_effects();
	switch (unk_060001)
	{
	case 0:
		func_003F78();
		break;
	case 1:
		func_0040B4(0u, d4, d5, d6, d7, a5);
		break;
	case 2:
		func_004124(0u, d4, d5, d6, d7, a5);
		break;
	case 3:
		func_00415E();
		break;
	}
	unk_060058 |= 0x20u;
	io_write8(IO_0A0001, unk_060058);
}

uint32_t func_003E70(uint32_t d7)
{
	uint8_t d0 = 0;
	uint32_t d7_2 = 0;

	unk_060040 = unk_06003C;
	unk_06003C = (((uint32_t)unk_060038(0) << 24u) | ((uint32_t)unk_060039 << 16u) | ((uint32_t)unk_06003A << 8u) | unk_06003B);
	unk_060038(0) = unk_060034(0);
	unk_060039 = unk_060035;
	unk_06003A = unk_060036;
	unk_06003B = unk_060037;
	unk_060047 = unk_060046;
	unk_060046 = unk_060045;
	unk_060045 = unk_060044;
	unk_060044 = ~io_read8(IO_0A0001);
	d0 = (uint8_t)~io_read8(IO_0A0003);
	unk_060034(0) = d0;
	unk_060050 = d0 & ~unk_060038(0);
	d0 = (uint8_t)~io_read8(IO_0A0005);
	unk_060035 = d0;
	unk_060051 = d0 & ~unk_060039;
	d0 = (uint8_t)~io_read8(IO_0A0007);
	unk_060036 = d0;
	unk_060052 = d0 & ~unk_06003A;
	d0 = (uint8_t)~io_read8(IO_0A0015);
	unk_060037 = d0;
	unk_060053 = d0 & ~unk_06003B;
	io_write8(TILES_106018, (uint8_t)unk_06005E);
	d7_2 = (d7 & ~0xFFFFu) | unk_06005C;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - 0x60u);
	io_write8(TILES_106400, d7_2);
	d7_2 = (d7_2 & ~0xFFFFu) | ((uint16_t)d7_2 >> 8);
	io_write8(TILES_106402, d7_2);
	io_write8(TILES_106019, (uint8_t)unk_060062);
	d7_2 = (d7_2 & ~0xFFFFu) | unk_060060;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - 0x60u);
	io_write8(TILES_106401, d7_2);
	d7_2 = (d7_2 & ~0xFFFFu) | ((uint16_t)d7_2 >> 8);
	io_write8(TILES_106403, d7_2);
	return d7_2;
}

void func_003F78(void)
{
	switch (unk_060003)
	{
	case 0:
		func_003F9A();
		return;
	case 1:
		func_004008();
		return;
	case 2:
		func_00402C();
		return;
	}
}

void func_003F9A(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060064 = 0u;
	io_write8(TILES_106B00, 0u);
	unk_060065 = 0u;
	io_write8(TILES_106E00, 0u);
	io_write8(SPRITE_CONTROL_140000, unk_06005A);
	func_004072();
	unk_0600A3 = 0u;
	if ((unk_060032 & 4u) != 0u)
	{
		unk_060001 = 3u;
		return;
	}
	unk_060003++;
	unk_060082 = 1u;
	d7 = 1u;
	func_004164(d7);
	d7 = 0x20Fu;
	a6 = 0xA05Eu;
	post_palette_request(d7, a6);
}

void func_004008(void)
{
	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		unk_060002 = 1u;
		unk_060003++;
	}
}

void func_00402C(void)
{
	uint8_t t1 = 0;

	t1 = unk_060002;
	unk_060002 = t1 - 1u;
	if (t1 == 1u || unk_060327 != 0u || (unk_060044 != 0u && unk_060091 != 0u))
	{
		unk_060001++;
		unk_060003 = 0u;
		return;
	}
}

void unreached_004068(void)
{
	func_004072();
}

void func_004072(void)
{
	uint8_t d6 = 0, d7 = 0;

	d7 = unk_06005B & ~1u;
	d6 = unk_06005A & ~8u;
	if ((unk_060032 & 1u) != 0u)
	{
		d7 ^= 1u;
		d6 ^= 8u;
	}
	unk_06005B = d7;
	io_write8(TILES_106D00, d7);
	unk_06005A = d6;
	io_write8(SPRITE_CONTROL_140000, d6);
}

void func_0040B4(uint32_t d1, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a5)
{
	uint8_t d7_2 = 0;
	uint32_t a0 = 0;

	a0 = indexed_table_of_32_bit_values_004100[unk_060003];
	switch (a0)
	{
	case 0x0049ACu:
		func_0049AC();
		break;
	case 0x004CA4u:
		func_004CA4(d1, d4, d5, d6, d7, a0, a5);
		break;
	case 0x004EC4u:
		func_004EC4();
		break;
	case 0x0051A8u:
		func_0051A8();
		break;
	case 0x0088C0u:
		func_0088C0();
		break;
	case 0x0088DAu:
		func_0088DA(d1);
		break;
	case 0x008CE4u:
		func_008CE4((uint16_t)d6, a5);
		break;
	case 0x008E46u:
		func_008E46();
		break;
	case 0x00919Cu:
		func_00919C();
		break;
	}
	func_00419C();
	if (unk_060066 != 0u)
	{
		d7_2 = 0u;
		func_0091A4(d7_2, 0u);
		unk_060003 = 0u;
		unk_060005 = 0u;
		unk_060007 = 0u;
		unk_060009 = 0u;
		unk_060001++;
	}
}

void func_004124(uint32_t d1, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a5)
{
	uint32_t a0 = 0;

	a0 = indexed_table_of_32_bit_values_00413A[unk_060005];
	switch (a0)
	{
	case 0x0061CEu:
		func_0061CE();
		return;
	case 0x006268u:
		func_006268();
		return;
	case 0x0062C8u:
		func_0062C8();
		return;
	case 0x006386u:
		func_006386(d1);
		return;
	case 0x006672u:
		func_006672(d1, (uint16_t)d5, d7);
		return;
	case 0x006B16u:
		func_006B16(d1, d4, d5, d6, d7, a0);
		return;
	case 0x006BE4u:
		func_006BE4((uint16_t)d6, a5);
		return;
	case 0x00781Eu:
		func_00781E(d1, (uint16_t)d6, a5);
		return;
	case 0x007B0Cu:
		func_007B0C();
		return;
	}
}

void func_00415E(void)
{
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_0056C2();
		break;
	case 1:
		func_001942();
		break;
	case 2:
		func_005720();
		break;
	case 3:
		func_00577E();
		break;
	case 4:
		func_005854();
		break;
	case 5:
		func_0059EA();
		break;
	case 6:
		func_005B48();
		break;
	case 7:
		func_005C1C();
		break;
	case 8:
		func_005D80();
		break;
	}
	func_003E70(0u);
}

void func_004164(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = unk_060010;
	mem_write16(a6, d7);
	a6 += 2u;
	if (a6 > 0x603FFu)
		a6 = 0x60380u;
	unk_060010 = a6;
}

void func_004184(uint32_t a5)
{
	uint16_t d7 = 0;

	for (;;)
	{
		d7 = mem_read16(a5);
		a5 += 2u;
		if (d7 == 0xFFFFu)
			break;
		func_004164(d7);
	}
}

void func_004190(void)
{
	unk_0600D0 = 0u;
	return_from_exception();
}

void func_00419C(void)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0;

	unk_060066 = 0u;
	d0 = 0u;
	a6 = unk_060100_ADDRESS;
	a5 = unk_060034_ADDRESS;
	do
	{
		if (mem_read16(a6) != 0u && (unk_060034(d0) & 0x30u) != 0u && (unk_060038(d0) & 0x30u) == 0u)
			unk_060066 |= shl32(1u, (int)(d0 & 7u));
		d0 = (uint8_t)(d0 + 1u);
		a6 += 8u;
	} while (d0 < 4u);
	t1 = unk_060066;
	d1 = t1;
	if (t1 != 0u)
	{
		unk_0600A1 = d1;
		unk_0600A6 = d1;
		unk_0600A3 = 1u;
	}
}

void func_004206(uint32_t *p_d1, uint32_t *p_a5)
{
	uint32_t d1 = *p_d1;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if (unk_0600A3 != 0u)
	{
		unk_060066 = 0u;
		d0 = 0u;
		a6 = unk_060100_ADDRESS;
		*p_a5 = unk_060034_ADDRESS;
		do
		{
			if ((unk_0600A1 & shl32(1u, (int)(d0 & 7u))) == 0u)
			{
				t1 = mem_read16(a6);
				d1 = t1;
				if (t1 != 0u)
				{
					d1 = (d1 & ~0xFFu) | unk_060034(d0);
					if ((d1 & 0x30u) != 0u)
					{
						d1 = (d1 & ~0xFFu) | unk_060038(d0);
						if ((d1 & 0x30u) == 0u)
							unk_060066 |= shl32(1u, (int)(d0 & 7u));
					}
				}
			}
			d0 = (uint8_t)(d0 + 1u);
			a6 += 8u;
		} while (d0 < 4u);
		t2 = unk_060066;
		d1 = (d1 & ~0xFFu) | t2;
		if (t2 != 0u)
		{
			unk_0600A1 |= d1;
			unk_0600A6 |= d1;
			unk_0600A3 = 1u;
		}
	}
	*p_d1 = d1;
}

uint32_t func_004284(void)
{
	uint32_t a6 = 0;

	a6 = unk_060100_ADDRESS;
	func_00433E(a6);
	unk_060106(0) = 0u;
	return a6;
}

uint32_t func_004294(void)
{
	uint32_t a6 = 0;

	a6 = unk_060108_ADDRESS;
	func_00433E(a6);
	unk_06010E = 0u;
	return a6;
}

uint32_t func_0042A4(void)
{
	uint32_t a6 = 0;

	a6 = unk_060110_ADDRESS;
	func_00433E(a6);
	unk_060116 = 0u;
	return a6;
}

uint32_t func_0042B4(void)
{
	uint32_t a6 = 0;

	a6 = unk_060118_ADDRESS;
	func_00433E(a6);
	unk_06011E = 0u;
	return a6;
}

void func_0042C4(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = unk_060100_ADDRESS;
	d7 = 0u;
	func_004304(d7, a6);
}

void func_0042D4(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = unk_060108_ADDRESS;
	d7 = 1u;
	func_004304(d7, a6);
}

void func_0042E4(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = unk_060110_ADDRESS;
	d7 = 2u;
	func_004304(d7, a6);
}

void func_0042F4(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = unk_060118_ADDRESS;
	d7 = 3u;
	func_004304(d7, a6);
}

void func_004304(uint8_t d7, uint32_t a6)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d1 = 0;

	extend = 0u;
	d1 = mem_read8(a6 + 1u);
	carry = m68k_sbcd_cy(d1, 1u, extend);
	d1 = m68k_sbcd(d1, 1u, extend);
	if (carry == 0u)
	{
		mem_write8(a6 + 1u, d1);
		mem_write8(a6 + 6u, 0xAu);
		return;
	}
	if (mem_read8(a6) == 0u)
	{
		unk_0600A1 &= ~shl32(1u, (int)(d7));
		unk_0600B3 |= shl32(1u, (int)(d7));
		return;
	}
	mem_write8(a6, mem_read8(a6) - 1u);
	d1 = 0x99u;
	mem_write8(a6 + 1u, d1);
	mem_write8(a6 + 6u, 0xAu);
}

void func_00433E(uint32_t a6)
{
	mem_write16(a6 + 4u, 0u);
	mem_write16(a6 + 2u, unk_06009A);
}

void func_00434C(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0, ignored = 0;

	func_004378(d7, &d1, &d5, p_a1);
	func_00435E(0u, d7, &d1, &d5);
	func_0043E8(0u, d7, &d1, &d5, p_a1);
	func_00445E(d1, &d5, &ignored, &d7_2);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_00435E(uint32_t d4, uint32_t d7, uint32_t *p_d1, uint32_t *p_d5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + unk_0600A2);
	d7_2 = d7_2 | 0x30u;
	func_002336(d7_2, p_d1, &ignored, &d5, &ignored_2);
	unk_0600A2 = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_004378(uint32_t d7, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	if (unk_0600A6 == 0u)
		return;
	d7_2 = (d7 & ~0xFFu) | unk_0600A6;
	func_019B3A((uint8_t)d7_2, p_d1, &ignored, p_a1);
	if ((unk_0600A6 & 1u) != 0u)
		func_0042C4();
	if ((unk_0600A6 & 2u) != 0u)
		func_0042D4();
	if ((unk_0600A6 & 4u) != 0u)
		func_0042E4();
	if ((unk_0600A6 & 8u) != 0u)
		func_0042F4();
	d7_2 = (d7_2 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + unk_0600A6);
	d7_2 = d7_2 | 0x30u;
	func_002336(d7_2, p_d1, &ignored, &d5, &ignored_2);
	unk_0600A6 = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_0043E8(uint32_t d4, uint32_t d7, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	if (unk_0600A0 == 0u)
		return;
	if ((unk_0600A0 & 1u) != 0u)
		func_0042C4();
	if ((unk_0600A0 & 2u) != 0u)
		func_0042D4();
	if ((unk_0600A0 & 4u) != 0u)
		func_0042E4();
	if ((unk_0600A0 & 8u) != 0u)
		func_0042F4();
	d7_2 = (d7 & ~0xFFu) | unk_0600A1;
	d7_2 = d7_2 & (unk_0600A0 | 0xFFFFFF00u);
	func_019B92((uint8_t)d7_2, p_d1, &ignored, p_a1);
	d7_2 = (d7_2 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + unk_0600A0);
	d7_2 = d7_2 | 0x30u;
	func_002336(d7_2, p_d1, &ignored, &d5, &ignored_2);
	unk_0600A0 = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_00445E(uint32_t d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 3u;
	do
	{
		func_00446A((uint8_t)d0, d1, 0u, &d5, p_d6, p_d7);
		t1 = d0 - 1u;
		d0 = t1;
	} while (t1 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_00446A(uint8_t d0, uint32_t d1, uint32_t d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d1_2 = 0, d7 = 0, ignored = 0;

	d1_2 = (d1 & ~0xFFu) | unk_0600B7;
	d1_2 = d1_2 | unk_0600A6;
	d1_2 = d1_2 | unk_0600A1;
	d1_2 = d1_2 | unk_0600A0;
	if ((d1_2 & shl32(1u, (int)(d0 & 0x1Fu))) != 0u)
	{
		d1_2 = (d1_2 & ~0xFFu) | unk_0600A6;
		d1_2 = d1_2 | unk_0600A1;
		d1_2 = d1_2 | unk_0600A0;
		if (((d1_2 | unk_0600B3) & shl32(1u, (int)(d0 & 0x1Fu))) != 0u || (unk_0600B7 & shl32(1u, (int)(d0 & 7u))) == 0u)
			d7 = 0xCu;
		else
			d7 = 4u;
	}
	else if ((unk_0600B3 & shl32(1u, (int)(d0 & 7u))) != 0u)
		d7 = 8u;
	else
		d7 = 0u;
	d7 = (uint8_t)(d7 | d0);
	d7 = (uint16_t)(d7 + 0xD00u);
	func_00263C(&ignored, &d5, p_d6, &d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void unreached_0044EE(uint16_t d7)
{
	d7 |= 0xB30u;
	func_004164(d7);
}

void func_0044F8(void)
{
	func_009A3A();
	func_004604();
	func_004612();
	func_0045DA();
	func_00455C();
	func_0045E8();
}

void func_004512(uint16_t d0, uint32_t a0)
{
	uint32_t a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t65 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0, t49 = 0, t50 = 0, t51 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0, t59 = 0, t60 = 0, t61 = 0, t62 = 0, t63 = 0, t64 = 0;

	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		t25 = t24 - 4u;
		mem_write16(t25 + 2u, a1);
		mem_write16(t25, a1 >> 16);
		t26 = t25 - 4u;
		mem_write16(t26 + 2u, d7);
		mem_write16(t26, d7 >> 16);
		t27 = t26 - 4u;
		mem_write16(t27 + 2u, d6);
		mem_write16(t27, d6 >> 16);
		t28 = t27 - 4u;
		mem_write16(t28 + 2u, d5);
		mem_write16(t28, d5 >> 16);
		t29 = t28 - 4u;
		mem_write16(t29 + 2u, d4);
		mem_write16(t29, d4 >> 16);
		t30 = t29 - 4u;
		mem_write16(t30 + 2u, d3);
		mem_write16(t30, d3 >> 16);
		t31 = t30 - 4u;
		mem_write16(t31 + 2u, d2);
		mem_write16(t31, d2 >> 16);
		t32 = t31 - 4u;
		mem_write16(t32 + 2u, d1);
		mem_write16(t32, d1 >> 16);
		t33 = t32 - 4u;
		mem_write16(t33 + 2u, a1);
		mem_write16(t33, a1 >> 16);
		t34 = t33 - 4u;
		mem_write16(t34 + 2u, d7);
		mem_write16(t34, d7 >> 16);
		t35 = t34 - 4u;
		mem_write16(t35 + 2u, d6);
		mem_write16(t35, d6 >> 16);
		t36 = t35 - 4u;
		mem_write16(t36 + 2u, d5);
		mem_write16(t36, d5 >> 16);
		t37 = t36 - 4u;
		mem_write16(t37 + 2u, d4);
		mem_write16(t37, d4 >> 16);
		t38 = t37 - 4u;
		mem_write16(t38 + 2u, d3);
		mem_write16(t38, d3 >> 16);
		t39 = t38 - 4u;
		mem_write16(t39 + 2u, d2);
		mem_write16(t39, d2 >> 16);
		t40 = t39 - 4u;
		mem_write16(t40 + 2u, d1);
		mem_write16(t40, d1 >> 16);
		t41 = t40 - 4u;
		mem_write16(t41 + 2u, a1);
		mem_write16(t41, a1 >> 16);
		t42 = t41 - 4u;
		mem_write16(t42 + 2u, d7);
		mem_write16(t42, d7 >> 16);
		t43 = t42 - 4u;
		mem_write16(t43 + 2u, d6);
		mem_write16(t43, d6 >> 16);
		t44 = t43 - 4u;
		mem_write16(t44 + 2u, d5);
		mem_write16(t44, d5 >> 16);
		t45 = t44 - 4u;
		mem_write16(t45 + 2u, d4);
		mem_write16(t45, d4 >> 16);
		t46 = t45 - 4u;
		mem_write16(t46 + 2u, d3);
		mem_write16(t46, d3 >> 16);
		t47 = t46 - 4u;
		mem_write16(t47 + 2u, d2);
		mem_write16(t47, d2 >> 16);
		t48 = t47 - 4u;
		mem_write16(t48 + 2u, d1);
		mem_write16(t48, d1 >> 16);
		t49 = t48 - 4u;
		mem_write16(t49 + 2u, a1);
		mem_write16(t49, a1 >> 16);
		t50 = t49 - 4u;
		mem_write16(t50 + 2u, d7);
		mem_write16(t50, d7 >> 16);
		t51 = t50 - 4u;
		mem_write16(t51 + 2u, d6);
		mem_write16(t51, d6 >> 16);
		t52 = t51 - 4u;
		mem_write16(t52 + 2u, d5);
		mem_write16(t52, d5 >> 16);
		t53 = t52 - 4u;
		mem_write16(t53 + 2u, d4);
		mem_write16(t53, d4 >> 16);
		t54 = t53 - 4u;
		mem_write16(t54 + 2u, d3);
		mem_write16(t54, d3 >> 16);
		t55 = t54 - 4u;
		mem_write16(t55 + 2u, d2);
		mem_write16(t55, d2 >> 16);
		t56 = t55 - 4u;
		mem_write16(t56 + 2u, d1);
		mem_write16(t56, d1 >> 16);
		t57 = t56 - 4u;
		mem_write16(t57 + 2u, a1);
		mem_write16(t57, a1 >> 16);
		t58 = t57 - 4u;
		mem_write16(t58 + 2u, d7);
		mem_write16(t58, d7 >> 16);
		t59 = t58 - 4u;
		mem_write16(t59 + 2u, d6);
		mem_write16(t59, d6 >> 16);
		t60 = t59 - 4u;
		mem_write16(t60 + 2u, d5);
		mem_write16(t60, d5 >> 16);
		t61 = t60 - 4u;
		mem_write16(t61 + 2u, d4);
		mem_write16(t61, d4 >> 16);
		t62 = t61 - 4u;
		mem_write16(t62 + 2u, d3);
		mem_write16(t62, d3 >> 16);
		t63 = t62 - 4u;
		mem_write16(t63 + 2u, d2);
		mem_write16(t63, d2 >> 16);
		t64 = t63 - 4u;
		mem_write16(t64 + 2u, d1);
		mem_write16(t64, d1 >> 16);
		a0 = t64;
		t65 = d0 - 1u;
		d0 = t65;
	} while (t65 != 0xFFFFu);
}

void func_00454A(uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d1 = 0u;
	*p_d2 = 0u;
	*p_d3 = 0u;
	*p_d4 = 0u;
	*p_d5 = 0u;
	*p_d6 = 0u;
	*p_d7 = 0u;
	*p_a1 = 0u;
}

void func_00455C(void)
{
	func_0045BE();
	func_0045CC();
	func_0045F6();
}

void unreached_00456A(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	func_004592();
	func_00459C();
	func_0045A6();
	func_0045B0();
	a0 = 0x60200u;
	d0 = 0u;
	func_004512(d0, a0);
	a0 = unk_061100_ADDRESS;
	d0 = 0u;
	func_004512(d0, a0);
}

void func_004592(void)
{
	uint32_t a0 = 0;

	a0 = unk_060100_ADDRESS;
	AT32(unk_060100(0), -2) = 0u;
	AT32(unk_060104, -2) = 0u;
}

void func_00459C(void)
{
	uint32_t a0 = 0;

	a0 = unk_060108_ADDRESS;
	AT32(unk_060108, -3) = 0u;
	AT32(unk_06010C, -2) = 0u;
}

void func_0045A6(void)
{
	uint32_t a0 = 0;

	a0 = unk_060110_ADDRESS;
	AT32(unk_060110, -3) = 0u;
	AT32(unk_060114, -2) = 0u;
}

void func_0045B0(void)
{
	AT32(unk_060118, -3) = 0u;
	AT32(unk_06011C, -2) = 0u;
}

void func_0045BE(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = unk_061200_ADDRESS;
	d0 = 0u;
	func_004512(d0, a0);
}

void func_0045CC(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = unk_061300_ADDRESS;
	d0 = 0u;
	func_004512(d0, a0);
}

void func_0045DA(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x61400u;
	d0 = 2u;
	func_004512(d0, a0);
}

void func_0045E8(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x61800u;
	d0 = 7u;
	func_004512(d0, a0);
}

void func_0045F6(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x63200u;
	d0 = 0u;
	func_004512(d0, a0);
}

void func_004604(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t9 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	a0 = unk_062FA0_ADDRESS;
	d0 = 0x7Cu;
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		a0 = t8;
		t9 = d0 - 1u;
		d0 = t9;
	} while (t9 != 0xFFFFu);
}

void func_004612(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x140800u;
	d0 = 3u;
	func_004512(d0, a0);
}

void unreached_004620(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = unk_062000_ADDRESS;
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 3u);
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00462E(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = unk_0623C0_ADDRESS;
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xBu);
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00463C(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = 0x62780u;
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00464A(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = 0x62140u;
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_004658(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = 0x62A00u;
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	func_00454A(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}
