/**
 *    Name:        engine/sprites.c
 *    Description: the sprite engine: the objects' animations, their sprites into the K051960, their boxes
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_046EEA(void)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0;

	a0 = SPRITE_RAM;
	d0 = 0x7Fu;
	d1 = 0x4Fu;
	do
	{
		mem_write8(a0, d1);
		d1 = (d1 - 1u) & 0x7Fu;
		t1 = d0 - 1u;
		d0 = t1;
		a0 += 8u;
	} while (t1 != 0xFFFFu);
}

void func_046F08(uint32_t *p_d7, uint32_t *p_a0)
{
	uint8_t d6 = 0;
	uint16_t d0 = 0, d5 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, d4 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	d7 = 0x31u;
	d6 = 0u;
	d5 = 0x300u;
	a0 = unk_062000_ADDRESS;
	a1 = 0x61400u;
	d4 = unk_062000_ADDRESS;
	do
	{
		if ((int8_t)mem_read8(a0) >= 0)
		{
			if (mem_read8(a0) != 0u)
			{
				a3 = mem_read32(a0 + 0x36u);
				step_animation(a0, a3);
			}
		}
		else
		{
			mem_write16(a0 + 0x3Eu, 0u);
			d0 = (uint16_t)(mem_read16(a0 + 0x34u) + mem_read16(a0 + 0xEu) + 0x38u);
			if (d0 >= 0x180u)
			{
				a3 = mem_read32(a0 + 0x36u);
				step_animation(a0, a3);
			}
			else
			{
				d6++;
				d0 &= ~1u;
				if (d0 < d5)
					d5 = (uint16_t)d0;
				if (mem_read16(a1 + (int16_t)d0) == 0u)
					mem_write16(a1 + (int16_t)d0, a0);
				else
				{
					d4 = (d4 & ~0xFFFFu) | mem_read16(a1 + (int16_t)d0);
					do
					{
						a2 = d4;
						t1 = mem_read16(a2 + 0x3Eu);
						d4 = (d4 & ~0xFFFFu) | t1;
					} while (t1 != 0u);
					mem_write16(a2 + 0x3Eu, a0);
				}
			}
		}
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x50u;
	} while (t2 != 0xFFFFu);
	unk_061204 = d5;
	unk_061206 = d6;
	*p_d7 = d7;
	*p_a0 = a0;
}

void draw_sprites(uint32_t *p_d1, uint32_t *p_a0)
{
	uint16_t d1 = (uint16_t)*p_d1;
	uint32_t a0 = *p_a0;
	bool L_047164 = false;
	uint8_t d0 = 0, d3 = 0, d7 = 0;
	uint16_t d2 = 0, d5 = 0;
	uint32_t a1 = 0, a2 = 0, a3 = 0, a4 = 0, a6 = 0, d6 = 0;
	uint8_t t2 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0;
	uint16_t t1 = 0, t3 = 0, t5 = 0, t10 = 0;

	a1 = 0x61400u + (int16_t)unk_061204;
	a2 = SPRITE_RAM;
	d6 = unk_062000_ADDRESS;
	d7 = unk_061206;
	while (a1 < 0x61580u)
	{
		t1 = mem_read16(a1);
		d6 = (d6 & ~0xFFFFu) | t1;
		a1 += 2u;
		if (t1 == 0u)
			continue;
		mem_write16(a1 - 2u, 0u);
		do
		{
			a0 = d6;
			a3 = mem_read32(a0 + 0x36u);
			d5 = mem_read8(a3 + 1u);
			a4 = mem_read32(a3 + 2u);
			do
			{
				a6 = sprite_sizes_ADDRESS + ((mem_read8(a4) & 0xE0u) >> 2);
				d1 = mem_read16(a4 + 4u);
				t2 = (uint32_t)mem_read8(a0) << 1;
				d3 = t2;
				if ((int8_t)t2 < 0)
					d1 = (uint16_t)(0u - d1 - DATA16(a6 + 4u));
				d1 += mem_read16(a0 + 0xCu);
				if ((int16_t)d1 < 0x1A0 && (int16_t)DATA16(a6) < (int16_t)d1)
				{
					t3 = mem_read8(a0 + 0x10u) + mem_read16(a4 + 6u) + mem_read16(a0 + 0xEu);
					d2 = t3;
					if ((int16_t)t3 >= 0 && (int16_t)d2 < (int16_t)DATA16(a6 + 2u))
					{
						d1 &= 0x1FFu;
						d0 = mem_read8(a4 + 3u);
						if ((int8_t)(d3 ^ d0) < 0)
							d1 |= 0x200u;
						d2 &= 0x1FFu;
						if ((d0 & 0x40u) != 0u)
							d2 |= 0x200u;
						mem_write8(a2, mem_read8(a2) | 0x80u);
						mem_write8(a2 + 1u, mem_read8(a4));
						mem_write8(a2 + 2u, mem_read8(a4 + 1u));
						t4 = mem_read8(a0 + 0x42u);
						d0 = t4;
						if ((int8_t)t4 < 0 || mem_read8(a4 + 2u) == 0xFu)
							mem_write8(a2 + 3u, mem_read8(a4 + 2u));
						else
							mem_write8(a2 + 3u, d0 | (mem_read8(a4 + 2u) & 0x90u));
						mem_write16(a2 + 6u, d1);
						mem_write8(a2 + 7u, (uint8_t)d1);
						mem_write16(a2 + 4u, d2);
						mem_write8(a2 + 5u, (uint8_t)d2);
						a2 += 8u;
					}
				}
				t5 = d5 - 1u;
				d5 = t5;
				a4 += 8u;
			} while (t5 != 0xFFFFu);
			if ((int8_t)mem_read8(a0 + 1u) < 0)
			{
				a4 = mem_read32(a0 + 0x3Au);
				d2 = (uint16_t)(mem_read8(a0 + 0x32u) + mem_read16(a4 + 6u) + mem_read16(a0 + 0xEu));
				d1 = (mem_read16(a4 + 4u) + mem_read16(a0 + 0xCu)) & 0x1FFu;
				if ((int8_t)mem_read8(a4 + 3u) < 0)
					d1 |= 0x200u;
				d2 &= 0x1FFu;
				if ((mem_read8(a4 + 3u) & 0x40u) != 0u)
					d2 |= 0x200u;
				mem_write8(a2, mem_read8(a2) | 0x80u);
				mem_write8(a2 + 1u, mem_read8(a4));
				mem_write8(a2 + 2u, mem_read8(a4 + 1u));
				mem_write8(a2 + 3u, mem_read8(a4 + 2u));
				mem_write16(a2 + 6u, d1);
				mem_write8(a2 + 7u, (uint8_t)d1);
				mem_write16(a2 + 4u, d2);
				mem_write8(a2 + 5u, (uint8_t)d2);
				a2 += 8u;
			}
			if (mem_read8(a0 + 0x33u) != 0u)
			{
				t6 = mem_read8(a0 + 0x33u);
				mem_write8(a0 + 0x33u, t6 - 1u);
				if (t6 == 1u)
				{
					a3 += 0xAu;
					if ((int16_t)mem_read16(a3 - 2u) >= 0)
						a3 += 8u;
					t7 = mem_read8(a3);
					d0 = t7;
					if (t7 != 0u)
					{
						mem_write32(a0 + 0x36u, a3);
						d0 += mem_read8(a0 + 0x43u);
					}
					else
					{
						t8 = mem_read8(a3 + 1u);
						d1 = (uint16_t)((d1 & ~0xFFu) | t8);
						if (t8 != 0u)
						{
							a3 = mem_read32(a3 + 2u);
							d0 = mem_read8(a3);
							mem_write32(a0 + 0x36u, a3);
							d0 += mem_read8(a0 + 0x43u);
						}
					}
					mem_write8(a0 + 0x33u, d0);
				}
			}
			t9 = d7;
			d7 = (uint8_t)(t9 - 1u);
			L_047164 = t9 == 1u;
			if (L_047164)
				break;
			t10 = mem_read16(a0 + 0x3Eu);
			d6 = (d6 & ~0xFFFFu) | t10;
		} while (t10 != 0u);
		if (L_047164)
			break;
	}
	for (;;)
	{
		t11 = mem_read8(a2);
		mem_write8(a2, t11 & 0x7Fu);
		if ((t11 & 0x80u) == 0u)
			break;
		a2 += 8u;
	}
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_a0 = a0;
}

void step_animation(uint32_t a0, uint32_t a3)
{
	uint8_t d0 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
	{
		t1 = mem_read8(a0 + 0x33u);
		mem_write8(a0 + 0x33u, t1 - 1u);
		if (t1 != 1u)
			return;
		a3 += 0xAu;
		if ((int16_t)mem_read16(a3 - 2u) >= 0)
			a3 += 8u;
		t2 = mem_read8(a3);
		d0 = t2;
		if (t2 != 0u)
		{
			mem_write32(a0 + 0x36u, a3);
			d0 += mem_read8(a0 + 0x43u);
			mem_write8(a0 + 0x33u, d0);
			return;
		}
		if (mem_read8(a3 + 1u) == 0u)
		{
			mem_write8(a0 + 0x33u, d0);
			return;
		}
		a3 = mem_read32(a3 + 2u);
		d0 = mem_read8(a3);
		mem_write32(a0 + 0x36u, a3);
		d0 += mem_read8(a0 + 0x43u);
		mem_write8(a0 + 0x33u, d0);
		return;
	}
}

void func_047204(void)
{
	uint16_t d0 = 0, d1 = 0, d2 = 0, d7 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	uint8_t t4 = 0, t5 = 0, t13 = 0, t14 = 0, t22 = 0, t23 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0;

	a5 = 0x62140u;
	if ((unk_0600A4 & 1u) != 0u)
		a5 = 0x62190u;
	a0 = unk_062000_ADDRESS;
	d0 = 3u;
	do
	{
		if ((mem_read8(a0) & 4u) != 0u)
		{
			a2 = mem_read32(a0 + 0x36u);
			if ((int16_t)mem_read16(a2 + 8u) >= 0)
			{
				a1 = a5;
				d1 = 0x11u;
				do
				{
					if ((mem_read8(a1) & 2u) != 0u)
					{
						t1 = mem_read16(a0 + 0xEu) - mem_read16(a1 + 0xEu);
						d2 = t1;
						if ((int16_t)t1 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + mem_read16(a2 + 8u) + mem_read16(a1 + 0x34u)) >= 0)
						{
							a3 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a1 + 0x36u) + 6u);
							d2 = mem_read16(a2 + 0xAu);
							if ((mem_read8(a0) & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t2 = d2 + mem_read16(a0 + 0xCu) - mem_read16(a1 + 0xCu);
							d2 = t2;
							if ((int16_t)t2 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + mem_read16(a2 + 0xEu) + mem_read16(a3)) >= 0)
							{
								t3 = mem_read8(a0 + 0x10u) + mem_read16(a2 + 0xCu) - mem_read8(a1 + 0x10u);
								d2 = t3;
								if ((int16_t)t3 >= 0)
								{
									if ((int16_t)(0u - d2 + mem_read16(a2 + 0x10u) + mem_read16(a3 + 2u)) >= 0)
									{
										mem_write16(a1 + 0x4Cu, a0);
										mem_write32(a0 + 0x4Au, a1);
										mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
										mem_write16(a1 + 4u, 0x400u);
										mem_write8(a0, mem_read8(a0) | 8u);
										mem_write8(a1, mem_read8(a1) & ~2u);
										mem_write8(a1 + 7u, mem_read8(a0 + 6u));
										d2 = mem_read16(a1 + 8u);
										t4 = mem_read8(a0 + 0xBu);
										t5 = (uint8_t)d2;
										d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t5 - t4));
										if (t5 <= t4)
										{
											t6 = mem_read16(a0 + 0xAu);
											t7 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
											d2 = (uint16_t)(t7 - t6);
											if (t7 <= t6)
											{
												d7 = (uint16_t)(0x400u | TABLE8(indexed_table_of_8_bit_values_0471F0, (uint32_t)(int16_t)d0));
												func_004164(d7);
												d2 = 0u;
											}
										}
										mem_write16(a1 + 8u, d2);
									}
								}
								else if ((int16_t)(d2 + mem_read16(a2 + 0x10u)) >= 0)
								{
									mem_write16(a1 + 0x4Cu, a0);
									mem_write32(a0 + 0x4Au, a1);
									mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
									mem_write16(a1 + 4u, 0x400u);
									mem_write8(a0, mem_read8(a0) | 8u);
									mem_write8(a1, mem_read8(a1) & ~2u);
									mem_write8(a1 + 7u, mem_read8(a0 + 6u));
									d2 = mem_read16(a1 + 8u);
									t4 = mem_read8(a0 + 0xBu);
									t5 = (uint8_t)d2;
									d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t5 - t4));
									if (t5 <= t4)
									{
										t6 = mem_read16(a0 + 0xAu);
										t7 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
										d2 = (uint16_t)(t7 - t6);
										if (t7 <= t6)
										{
											d7 = (uint16_t)(0x400u | TABLE8(indexed_table_of_8_bit_values_0471F0, (uint32_t)(int16_t)d0));
											func_004164(d7);
											d2 = 0u;
										}
									}
									mem_write16(a1 + 8u, d2);
								}
							}
						}
					}
					t8 = d1 - 1u;
					d1 = t8;
					a1 += 0xA0u;
				} while (t8 != 0xFFFFu);
			}
		}
		t9 = d0 - 1u;
		d0 = t9;
		a0 += 0x50u;
	} while (t9 != 0xFFFFu);
	a0 = a5;
	d0 = 0x11u;
	do
	{
		if ((mem_read8(a0) & 4u) != 0u)
		{
			a2 = mem_read32(a0 + 0x36u);
			if ((int16_t)mem_read16(a2 + 8u) >= 0)
			{
				a1 = unk_062000_ADDRESS;
				d1 = 3u;
				do
				{
					if ((mem_read8(a1) & 2u) != 0u)
					{
						t10 = mem_read16(a0 + 0xEu) - mem_read16(a1 + 0xEu);
						d2 = t10;
						if ((int16_t)t10 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + mem_read16(a2 + 8u) + mem_read16(a1 + 0x34u)) >= 0)
						{
							a3 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a1 + 0x36u) + 6u);
							d2 = mem_read16(a2 + 0xAu);
							if ((mem_read8(a0) & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t11 = d2 + mem_read16(a0 + 0xCu) - mem_read16(a1 + 0xCu);
							d2 = t11;
							if ((int16_t)t11 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + mem_read16(a2 + 0xEu) + mem_read16(a3)) >= 0)
							{
								t12 = mem_read8(a0 + 0x10u) + mem_read16(a2 + 0xCu) - mem_read8(a1 + 0x10u);
								d2 = t12;
								if ((int16_t)t12 >= 0)
								{
									if ((int16_t)(0u - d2 + mem_read16(a2 + 0x10u) + mem_read16(a3 + 2u)) >= 0)
									{
										mem_write8(a1, mem_read8(a1) & ~2u);
										mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
										mem_write16(a1 + 4u, 0x400u);
										mem_write32(a1 + 0x28u, a0);
										mem_write8(a0, mem_read8(a0) | 8u);
										mem_write16(a0 + 0x4Eu, a1);
										mem_write8(a1 + 7u, mem_read8(a0 + 6u));
										d2 = mem_read16(a1 + 8u);
										t13 = mem_read8(a0 + 0xBu);
										t14 = (uint8_t)d2;
										d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t14 - t13));
										if (t14 <= t13)
										{
											t15 = mem_read16(a0 + 0xAu);
											t16 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
											d2 = (uint16_t)(t16 - t15);
											if (t16 < t15)
												d2 = 0u;
										}
										mem_write16(a1 + 8u, d2);
										break;
									}
								}
								else if ((int16_t)(d2 + mem_read16(a2 + 0x10u)) >= 0)
								{
									mem_write8(a1, mem_read8(a1) & ~2u);
									mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
									mem_write16(a1 + 4u, 0x400u);
									mem_write32(a1 + 0x28u, a0);
									mem_write8(a0, mem_read8(a0) | 8u);
									mem_write16(a0 + 0x4Eu, a1);
									mem_write8(a1 + 7u, mem_read8(a0 + 6u));
									d2 = mem_read16(a1 + 8u);
									t13 = mem_read8(a0 + 0xBu);
									t14 = (uint8_t)d2;
									d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t14 - t13));
									if (t14 <= t13)
									{
										t15 = mem_read16(a0 + 0xAu);
										t16 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
										d2 = (uint16_t)(t16 - t15);
										if (t16 < t15)
											d2 = 0u;
									}
									mem_write16(a1 + 8u, d2);
									break;
								}
							}
						}
					}
					t17 = d1 - 1u;
					d1 = t17;
					a1 += 0x50u;
				} while (t17 != 0xFFFFu);
			}
		}
		t18 = d0 - 1u;
		d0 = t18;
		a0 += 0xA0u;
	} while (t18 != 0xFFFFu);
	a0 = DATA32(rom_0471F4_ADDRESS + (uint16_t)(((uint8_t)unk_0600A4 & 3u) << 2));
	d0 = 1u;
	do
	{
		if ((mem_read8(a0) & 4u) != 0u)
		{
			a2 = mem_read32(a0 + 0x36u);
			if ((int16_t)mem_read16(a2 + 8u) >= 0)
			{
				a1 = unk_0623C0_ADDRESS;
				d1 = 0xBu;
				do
				{
					if ((mem_read8(a1) & 2u) != 0u)
					{
						t19 = mem_read16(a0 + 0xEu) - mem_read16(a1 + 0xEu);
						d2 = t19;
						if ((int16_t)t19 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + mem_read16(a2 + 8u) + mem_read16(a1 + 0x34u)) >= 0)
						{
							a3 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a1 + 0x36u) + 6u);
							d2 = mem_read16(a2 + 0xAu);
							if ((mem_read8(a0) & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t20 = d2 + mem_read16(a0 + 0xCu) - mem_read16(a1 + 0xCu);
							d2 = t20;
							if ((int16_t)t20 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + mem_read16(a2 + 0xEu) + mem_read16(a3)) >= 0)
							{
								t21 = mem_read8(a0 + 0x10u) + mem_read16(a2 + 0xCu) - mem_read8(a1 + 0x10u);
								d2 = t21;
								if ((int16_t)t21 >= 0)
								{
									if ((int16_t)(0u - d2 + mem_read16(a2 + 0x10u) + mem_read16(a3 + 2u)) >= 0)
									{
										mem_write16(a1 + 0x4Cu, a0);
										mem_write16(a0 + 0x4Eu, a1);
										mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
										mem_write16(a1 + 4u, 0x400u);
										mem_write8(a0, mem_read8(a0) | 8u);
										mem_write8(a1, mem_read8(a1) & ~2u);
										mem_write8(a1 + 7u, mem_read8(a0 + 6u));
										mem_write8(a1 + 7u, mem_read8(a1 + 7u) ^ 0x80u);
										d2 = mem_read16(a1 + 8u);
										t22 = mem_read8(a0 + 0xBu);
										t23 = (uint8_t)d2;
										d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t23 - t22));
										if (t23 <= t22)
										{
											t24 = mem_read16(a0 + 0xAu);
											t25 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
											d2 = (uint16_t)(t25 - t24);
											if (t25 < t24)
												d2 = 0u;
										}
										mem_write16(a1 + 8u, d2);
									}
								}
								else if ((int16_t)(d2 + mem_read16(a2 + 0x10u)) >= 0)
								{
									mem_write16(a1 + 0x4Cu, a0);
									mem_write16(a0 + 0x4Eu, a1);
									mem_write16(a1 + 0x40u, mem_read16(a1 + 4u));
									mem_write16(a1 + 4u, 0x400u);
									mem_write8(a0, mem_read8(a0) | 8u);
									mem_write8(a1, mem_read8(a1) & ~2u);
									mem_write8(a1 + 7u, mem_read8(a0 + 6u));
									mem_write8(a1 + 7u, mem_read8(a1 + 7u) ^ 0x80u);
									d2 = mem_read16(a1 + 8u);
									t22 = mem_read8(a0 + 0xBu);
									t23 = (uint8_t)d2;
									d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t23 - t22));
									if (t23 <= t22)
									{
										t24 = mem_read16(a0 + 0xAu);
										t25 = (d2 & ~0xFFu) | mem_read8(a0 + 0xBu);
										d2 = (uint16_t)(t25 - t24);
										if (t25 < t24)
											d2 = 0u;
									}
									mem_write16(a1 + 8u, d2);
								}
							}
						}
					}
					t26 = d1 - 1u;
					d1 = t26;
					a1 += 0x50u;
				} while (t26 != 0xFFFFu);
			}
		}
		t27 = d0 - 1u;
		d0 = t27;
		a0 += 0x140u;
	} while (t27 != 0xFFFFu);
}

void func_047534(uint32_t a0)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint32_t t9 = 0, t10 = 0;

	a3 = 0x62140u;
	d7 = 7u;
	mem_write8(a0 + 1u, 0u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 & 0xEFu);
	if ((t1 & 0x10u) != 0u)
		mem_write8(a0 + 0x32u, 0u);
	a4 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a0 + 0x36u) + 6u);
	for (;;)
	{
		if (mem_read8(a3) == 0u)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		d1 = 0xAu;
		t3 = mem_read16(a0 + 0xEu) - mem_read16(a3 + 0xEu);
		d4 = t3;
		if ((int16_t)t3 >= 0)
		{
			d4 = (uint16_t)(0u - d4);
			d1 += 2u;
		}
		t4 = d4 + mem_read16(a0 + 0x34u) + mem_read16(a3 + 0x34u);
		d4 = t4;
		if ((int16_t)t4 < 0)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		a5 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a3 + 0x36u) + 6u);
		t5 = mem_read16(a0 + 0xCu) - mem_read16(a3 + 0xCu);
		d5 = t5;
		if ((int16_t)t5 >= 0)
		{
			d5 = (uint16_t)(0u - d5);
			d1 += 8u;
		}
		t6 = d5 + mem_read16(a4) + mem_read16(a5);
		d5 = t6;
		if ((int16_t)t6 < 0)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < d5)
			d1 &= 0xE7u;
		else
			d1 &= ~6u;
		d0 = mem_read8(a3 + 0x10u);
		t7 = mem_read8(a0 + 0x10u) - d0;
		d6 = t7;
		if ((int16_t)t7 < 0)
		{
			if ((int16_t)(d6 + mem_read16(a4 + 2u)) >= 0)
			{
				mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
				break;
			}
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		d0 += mem_read16(a5 + 2u);
		t8 = 0u - d6 + mem_read16(a5 + 2u);
		d6 = t8;
		if ((int16_t)t8 < 0)
		{
			if (d4 >= 3u && d5 >= 3u)
			{
				mem_write8(a0 + 0x32u, (uint8_t)d0);
				mem_write8(a0, mem_read8(a0) | 0x10u);
				break;
			}
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < 3u || d5 < 3u)
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			return;
		}
		mem_write8(a0, mem_read8(a0) | 0x10u);
		if (d6 >= 5u)
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			return;
		}
		mem_write8(a0 + 0x32u, (uint8_t)d0);
		mem_write8(a0 + 0x10u, (uint8_t)d0);
		mem_write8(a0 + 0x11u, 0u);
		d1 = 1u;
		if ((int8_t)mem_read8(a3 + 2u) >= 0)
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			return;
		}
		t9 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a3 + 0x1Au);
		mem_write16(a0 + 0x14u, t9);
		mem_write16(a0 + 0x12u, t9 >> 16);
		t10 = mem_read32(a0 + 0x16u) + (int16_t)mem_read16(a3 + 0x1Cu);
		mem_write16(a0 + 0x18u, t10);
		mem_write16(a0 + 0x16u, t10 >> 16);
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a3 + 0x1Eu));
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
		return;
	}
}

void func_047662(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = (uint16_t)*p_d6;
	uint32_t a5 = *p_a5;
	uint8_t d1 = 0;
	uint16_t d0 = 0, d4 = 0, d5_2 = 0, d6_2 = 0;
	uint32_t a3 = 0, a4 = 0, d7 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	a3 = 0x62140u;
	d7 = 7u;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 & 0xEFu);
	if ((t1 & 0x10u) != 0u)
		mem_write8(a0 + 0x32u, 0u);
	a4 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a0 + 0x36u) + 6u);
	for (;;)
	{
		if (mem_read8(a3) == 0u)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		d1 = 0xAu;
		t3 = mem_read16(a0 + 0xEu) - mem_read16(a3 + 0xEu);
		d4 = t3;
		if ((int16_t)t3 >= 0)
		{
			d4 = (uint16_t)(0u - d4);
			d1 += 2u;
		}
		t4 = d4 + mem_read16(a0 + 0x34u) + mem_read16(a3 + 0x34u);
		d4 = t4;
		if ((int16_t)t4 < 0)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		a5 = body_boxes_ADDRESS + (int16_t)mem_read16(mem_read32(a3 + 0x36u) + 6u);
		t5 = mem_read16(a0 + 0xCu) - mem_read16(a3 + 0xCu);
		d5_2 = t5;
		if ((int16_t)t5 >= 0)
		{
			d5_2 = (uint16_t)(0u - d5_2);
			d1 += 8u;
		}
		t6 = d5_2 + mem_read16(a4) + mem_read16(a5);
		d5 = t6;
		if ((int16_t)t6 < 0)
		{
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < d5)
			d1 &= 0xE7u;
		else
			d1 &= ~6u;
		d0 = mem_read8(a3 + 0x10u);
		t7 = mem_read8(a0 + 0x10u) - d0;
		d6_2 = t7;
		if ((int16_t)t7 < 0)
		{
			t8 = d6_2 + mem_read16(a4 + 2u);
			d6 = t8;
			if ((int16_t)t8 < 0)
			{
				t2 = d7 - 1u;
				d7 = t2;
				a3 += 0x50u;
				if (t2 == 0xFFFFu)
					break;
				continue;
			}
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			break;
		}
		d0 += mem_read16(a5 + 2u);
		t9 = 0u - d6_2 + mem_read16(a5 + 2u);
		d6 = t9;
		if ((int16_t)t9 < 0)
		{
			if (d4 >= 3u && d5 >= 3u)
			{
				mem_write8(a0 + 0x32u, (uint8_t)d0);
				mem_write8(a0, mem_read8(a0) | 0x10u);
				break;
			}
			t2 = d7 - 1u;
			d7 = t2;
			a3 += 0x50u;
			if (t2 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < 3u || d5 < 3u)
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			break;
		}
		mem_write8(a0, mem_read8(a0) | 0x10u);
		if (d6 >= 5u)
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
			break;
		}
		mem_write8(a0 + 0x32u, (uint8_t)d0);
		mem_write8(a0 + 0x10u, (uint8_t)d0);
		mem_write8(a0 + 0x11u, 0u);
		d1 = 1u;
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d1);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_d7 = d7;
	*p_a5 = a5;
}

void func_04776E(void)
{
	unk_062FA0 = unk_062000_ADDRESS;
	unk_062FB0 = unk_062050_ADDRESS;
	unk_062FC0 = unk_0620A0_ADDRESS;
	unk_062FD0 = unk_0620F0_ADDRESS;
	unk_062FA4 = 0u;
	unk_062FA8 = 0u;
	unk_062FAC = 0u;
	unk_062FB4 = 0u;
	unk_062FB8 = 0u;
	unk_062FBC = 0u;
	unk_062FC4 = 0u;
	unk_062FC8 = 0u;
	unk_062FCC = 0u;
	unk_062FD4 = 0u;
	unk_062FD8 = 0u;
	unk_062FDC = 0u;
	unk_061226 = unk_062FA0_ADDRESS;
	unk_06122E = unk_062000_ADDRESS;
	unk_06124C = rom_048830[unk_060120 & 0xFu];
}

void func_0477EA(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, d6 = 0;

	a1 = spawn_enemies(a1);
	func_01E712();
	func_04783C(&d6, &a5);
	a0 = 0x62140u;
	do
	{
		if (mem_read8(a0) != 0u)
		{
			d0 = (uint16_t)((uint32_t)mem_read8(a0 + 4u) << 2);
			a6 = mem_read32(DATA32(rom_053896_ADDRESS + (uint16_t)((mem_read8(a0 + 2u) & 0x7Fu) << 2)) + d0);
			switch (a6)
			{
			case 0x00DF7Eu:
				func_00DF7E(a0, &d6, &d7, &a5);
				break;
			case 0x00E03Cu:
				func_00E03C(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x00E124u:
				func_00E124(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x00E1A8u:
				func_00E1A8(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x00E21Au:
				d7 = func_00E21A(d7, a0);
				break;
			case 0x00E2A8u:
				func_00E2A8(a0, &d6, &d7, &a5);
				break;
			case 0x00E2DCu:
				func_00E2DC(a0, &d6, &d7, &a5);
				break;
			case 0x00E39Cu:
				func_00E39C(d0, a0, p_d5, &d6, &d7);
				break;
			case 0x00E962u:
				func_00E962(a0);
				break;
			case 0x00E992u:
				d7 = func_00E992(d7, a0);
				break;
			case 0x00E9B6u:
				func_00E9B6(a0);
				break;
			case 0x00EAB6u:
				d7 = func_00EAB6(a0);
				break;
			case 0x00EB2Au:
				func_00EB2A(a0);
				break;
			case 0x00EB3Eu:
				d7 = func_00EB3E(a0);
				break;
			case 0x00EB70u:
				func_00EB70(a0);
				break;
			case 0x00EBFEu:
				func_00EBFE(a0);
				break;
			case 0x00EC4Cu:
				d7 = func_00EC4C(d7, a0);
				break;
			case 0x00EC76u:
				d7 = func_00EC76(d7, a0);
				break;
			case 0x00F8DAu:
				func_00F8DA(a0);
				break;
			case 0x00F8F2u:
				d7 = func_00F8F2(a0);
				break;
			case 0x00F96Au:
				func_00F96A(a0);
				break;
			case 0x00F98Eu:
				d7 = func_00F98E(d7, a0);
				break;
			case 0x00F9DCu:
				d7 = func_00F9DC(a0);
				break;
			case 0x00FA1Cu:
				func_00FA1C(a0);
				break;
			case 0x00FA5Au:
				func_00FA5A(a0);
				break;
			case 0x00FA68u:
				func_00FA68(a0);
				break;
			case 0x00FA9Au:
				func_00FA9A(a0);
				break;
			case 0x00FAACu:
				func_00FAAC(a0);
				break;
			case 0x00FADCu:
				d7 = func_00FADC(d7, a0);
				break;
			case 0x00FB34u:
				d7 = func_00FB34(a0);
				break;
			case 0x00FBB4u:
				func_00FBB4(a0);
				break;
			case 0x00FBD8u:
				func_00FBD8(a0);
				break;
			case 0x00FBDEu:
				d7 = func_00FBDE(d7, a0);
				break;
			case 0x00FC1Cu:
				d7 = func_00FC1C(d7, a0);
				break;
			case 0x00FCA6u:
				func_00FCA6(a0);
				break;
			case 0x00FD3Au:
				d7 = func_00FD3A(a0);
				break;
			case 0x00FDA4u:
				d7 = func_00FDA4(a0);
				break;
			case 0x00FDF2u:
				func_00FDF2(a0);
				break;
			case 0x00FDFCu:
				func_00FDFC(a0);
				break;
			case 0x00FE44u:
				func_00FE44(a0);
				break;
			case 0x00FE4Cu:
				d7 = func_00FE4C(a0);
				break;
			case 0x00FE5Eu:
				d7 = func_00FE5E(d7, a0);
				break;
			case 0x00FE6Eu:
				d7 = func_00FE6E(d7, a0);
				break;
			case 0x00FE7Eu:
				d7 = func_00FE7E(d7, a0);
				break;
			case 0x00FEE2u:
				func_00FEE2(a0, &d6, &d7);
				break;
			case 0x00FF70u:
				d7 = func_00FF70(d7, a0);
				break;
			case 0x00FFA0u:
				func_00FFA0(a0, &d6, &d7);
				break;
			case 0x00FFBEu:
				d7 = func_00FFBE(d7, a0);
				break;
			case 0x010026u:
				func_010026(a0);
				break;
			case 0x010058u:
				d7 = func_010058(a0);
				break;
			case 0x010080u:
				d7 = func_010080(a0);
				break;
			case 0x0100ACu:
				func_0100AC(a0);
				break;
			case 0x0100D4u:
				func_0100D4();
				break;
			case 0x0100D6u:
				d7 = func_0100D6(a0);
				break;
			case 0x0100DAu:
				d7 = func_0100DA(d7, a0);
				break;
			case 0x010108u:
				d7 = func_010108(a0);
				break;
			case 0x010158u:
				func_010158(d0, a0, p_d5, &d6, &d7);
				break;
			case 0x0101DCu:
				func_0101DC(a0);
				break;
			case 0x0101F8u:
				d7 = func_0101F8(d7, a0);
				break;
			case 0x01023Au:
				d7 = func_01023A(d7, a0);
				break;
			case 0x0102BCu:
				d7 = func_0102BC(d7, a0);
				break;
			case 0x0102E0u:
				d7 = func_0102E0(d7, a0);
				break;
			case 0x010354u:
				func_010354(a0);
				break;
			case 0x010398u:
				func_010398(a0);
				break;
			case 0x0103C0u:
				d7 = func_0103C0(a0);
				break;
			case 0x0103F2u:
				func_0103F2(a0);
				break;
			case 0x01042Cu:
				func_01042C(a0);
				break;
			case 0x010450u:
				func_010450(a0);
				break;
			case 0x010458u:
				d7 = func_010458(d7, a0);
				break;
			case 0x010490u:
				func_010490(a0);
				break;
			case 0x0104C2u:
				d7 = func_0104C2(d7, a0);
				break;
			case 0x010520u:
				func_010520(a0);
				break;
			case 0x010554u:
				func_010554(a0, &d6, &d7);
				break;
			case 0x01059Eu:
				func_01059E(a0, &d6, &d7);
				break;
			case 0x0105BCu:
				func_0105BC(a0, &d6, &d7);
				break;
			case 0x010602u:
				func_010602(a0, &d6, &d7, &a5);
				break;
			case 0x010674u:
				d7 = func_010674(d7, a0);
				break;
			case 0x0106D6u:
				func_0106D6(a0, &d6, &d7);
				break;
			case 0x01080Au:
				d7 = func_01080A(d7, a0);
				break;
			case 0x010880u:
				d7 = func_010880(d7, a0);
				break;
			case 0x0108B6u:
				func_0108B6(a0);
				break;
			case 0x0108D4u:
				func_0108D4(a0);
				break;
			case 0x0108FCu:
				func_0108FC(a0);
				break;
			case 0x01090Cu:
				func_01090C(a0);
				break;
			case 0x01092Eu:
				func_01092E(a0);
				break;
			case 0x010952u:
				func_010952(a0);
				break;
			case 0x010958u:
				func_010958(a0);
				break;
			case 0x010970u:
				func_010970();
				break;
			case 0x010972u:
				d7 = func_010972(d7, a0);
				break;
			case 0x0109D2u:
				func_0109D2(a0);
				break;
			case 0x0109F8u:
				func_0109F8(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x010AD4u:
				func_010AD4(a0);
				break;
			case 0x010B22u:
				func_010B22(a0);
				break;
			case 0x010B4Au:
				func_010B4A(a0);
				break;
			case 0x010B6Au:
				d7 = func_010B6A(a0);
				break;
			case 0x010BE0u:
				func_010BE0(a0);
				break;
			case 0x010BF8u:
				func_010BF8(a0, &d6, &d7);
				break;
			case 0x010C46u:
				func_010C46(a0);
				break;
			case 0x010C56u:
				func_010C56(a0, &d6, &d7, &a5);
				break;
			case 0x010C76u:
				d7 = func_010C76(d7, a0);
				break;
			case 0x010CB2u:
				func_010CB2(a0, &d6, &d7, &a5);
				break;
			case 0x010CDAu:
				func_010CDA(a0, &d6, &d7, &a5);
				break;
			case 0x010CFAu:
				func_010CFA(a0, &d6, &d7, &a5);
				break;
			case 0x010D36u:
				func_010D36(a0);
				break;
			case 0x010DA8u:
				d7 = func_010DA8(d7, a0);
				break;
			case 0x010DD4u:
				func_010DD4(a0);
				break;
			case 0x010DE8u:
				d7 = func_010DE8(d7, a0);
				break;
			case 0x010E0Cu:
				func_010E0C(a0);
				break;
			case 0x010E50u:
				func_010E50(a0);
				break;
			case 0x010E76u:
				func_010E76();
				break;
			case 0x0110A8u:
				func_0110A8(a0);
				break;
			case 0x0110B2u:
				func_0110B2(a0);
				break;
			case 0x0110BCu:
				func_0110BC(a0);
				break;
			case 0x0110C6u:
				func_0110C6(a0);
				break;
			case 0x0110D0u:
				func_0110D0(a0);
				break;
			case 0x0110F4u:
				func_0110F4(a0);
				break;
			case 0x011116u:
				func_011116(a0);
				break;
			case 0x01115Au:
				d7 = func_01115A(d7, a0);
				break;
			case 0x011190u:
				d7 = func_011190(d7, a0);
				break;
			case 0x0111C6u:
				d7 = func_0111C6(d7, a0);
				break;
			case 0x011208u:
				d7 = func_011208(d7, a0);
				break;
			case 0x01123Eu:
				d7 = func_01123E(d7, a0);
				break;
			case 0x01129Cu:
				func_01129C(a0);
				break;
			case 0x0112DAu:
				func_0112DA(a0, p_d5, &d6, &d7);
				break;
			case 0x01133Au:
				func_01133A(a0);
				break;
			case 0x011374u:
				func_011374(a0);
				break;
			case 0x01147Eu:
				d7 = func_01147E(d7, a0);
				break;
			case 0x0114C6u:
				d7 = func_0114C6(a0);
				break;
			case 0x0114F6u:
				d7 = func_0114F6(a0);
				break;
			case 0x0114FEu:
				func_0114FE(a0);
				break;
			case 0x011502u:
				d7 = func_011502(d7, a0);
				break;
			case 0x011528u:
				func_011528(a0);
				break;
			case 0x01154Eu:
				func_01154E(d0, a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x0116CCu:
				func_0116CC(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x01186Cu:
				func_01186C(a0, p_d5, &d6, &d7);
				break;
			case 0x0118CAu:
				func_0118CA(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x0118ECu:
				func_0118EC(a0, &d7, &a1);
				break;
			case 0x0119A0u:
				func_0119A0(a0, &d6, &d7, &a5);
				break;
			case 0x0119DEu:
				func_0119DE(a0, &d6, &d7, &a5);
				break;
			case 0x012024u:
				d7 = func_012024(d7, a0);
				break;
			case 0x012076u:
				d7 = func_012076(d7, a0);
				break;
			case 0x012110u:
				d7 = func_012110(a0);
				break;
			case 0x01214Eu:
				d7 = func_01214E(a0);
				break;
			case 0x01217Au:
				func_01217A();
				break;
			case 0x012198u:
				func_012198(a0, &d6, &d7, &a5);
				break;
			case 0x0122C8u:
				func_0122C8(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x012422u:
				func_012422(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x012430u:
				func_012430(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x0126A0u:
				d7 = func_0126A0(d7, a0);
				break;
			case 0x0126F0u:
				d7 = func_0126F0(d7, a0);
				break;
			case 0x01277Eu:
				d7 = func_01277E(d7, a0);
				break;
			case 0x0127D6u:
				func_0127D6(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x012830u:
				func_012830(a0);
				break;
			case 0x012862u:
				func_012862();
				break;
			case 0x012864u:
				func_012864(a0);
				break;
			case 0x01287Au:
				func_01287A(a0);
				break;
			case 0x0128D8u:
				func_0128D8(a0);
				break;
			case 0x0128FEu:
				d7 = func_0128FE(d7, a0);
				break;
			case 0x012924u:
				func_012924(a0);
				break;
			case 0x01293Cu:
				d7 = func_01293C(d7, a0);
				break;
			case 0x0129A6u:
				func_0129A6(a0);
				break;
			case 0x0129E2u:
				d7 = func_0129E2(d7, a0);
				break;
			case 0x012A2Eu:
				func_012A2E(a0);
				break;
			case 0x012A68u:
				d7 = func_012A68(d7, a0);
				break;
			case 0x012A88u:
				d7 = func_012A88(d7, a0);
				break;
			case 0x012AA6u:
				func_012AA6(a0, &d7, &a5);
				break;
			case 0x012AE2u:
				func_012AE2(a0, &d6, &d7);
				break;
			case 0x012B3Cu:
				d7 = func_012B3C(d7, a0);
				break;
			case 0x012C1Cu:
				d7 = func_012C1C(d7, a0);
				break;
			case 0x012C58u:
				d7 = func_012C58(d7, a0);
				break;
			case 0x012CB2u:
				d7 = func_012CB2(a0);
				break;
			case 0x012D06u:
				d7 = func_012D06(d7, a0);
				break;
			case 0x012D4Eu:
				func_012D4E(a0, &d6, &d7);
				break;
			case 0x012DCEu:
				func_012DCE(a0, p_d5, &d6, &d7);
				break;
			case 0x012E06u:
				func_012E06(a0, p_d5, &d6, &d7);
				break;
			case 0x012E50u:
				func_012E50(a0, p_d5, &d6, &d7);
				break;
			case 0x012E9Au:
				func_012E9A(a0, &d6, &d7);
				break;
			case 0x012F10u:
				d7 = func_012F10(a0);
				break;
			case 0x012F40u:
				func_012F40(a0);
				break;
			case 0x0131B8u:
				d7 = func_0131B8(d7, a0);
				break;
			case 0x01320Cu:
				d7 = func_01320C(a0);
				break;
			case 0x013260u:
				func_013260(a0);
				break;
			case 0x013264u:
				func_013264(a0);
				break;
			case 0x0132A2u:
				d7 = func_0132A2(d7, a0);
				break;
			case 0x013310u:
				d7 = func_013310(d7, a0);
				break;
			case 0x013340u:
				func_013340(a0);
				break;
			case 0x0134B6u:
				func_0134B6(a0, &d6, &d7, &a5);
				break;
			case 0x0135B4u:
				func_0135B4(a0, &d6, &d7, &a5);
				break;
			case 0x01360Cu:
				func_01360C(a0, &d6, &d7, &a5);
				break;
			case 0x013656u:
				d7 = func_013656(d7, a0);
				break;
			case 0x0136BAu:
				d7 = func_0136BA(a0);
				break;
			case 0x0136EAu:
				func_0136EA(a0);
				break;
			case 0x013AFCu:
				d7 = func_013AFC(a0);
				break;
			case 0x013B8Au:
				d7 = func_013B8A(d7, a0);
				break;
			case 0x013BB6u:
				d7 = func_013BB6(a0);
				break;
			case 0x013C0Cu:
				func_013C0C(a0);
				break;
			case 0x013C32u:
				func_013C32(d0, a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x013DA8u:
				func_013DA8(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x013E36u:
				func_013E36(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x013E64u:
				func_013E64();
				break;
			case 0x013E66u:
				d7 = func_013E66(d7, a0);
				break;
			case 0x013EC0u:
				func_013EC0(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x013EF4u:
				func_013EF4(a0, &d6, &d7, &a5);
				break;
			case 0x014336u:
				func_014336(a0);
				break;
			case 0x014366u:
				d7 = func_014366(d7, a0);
				break;
			case 0x0143BAu:
				func_0143BA();
				break;
			case 0x0143BCu:
				func_0143BC(a0);
				break;
			case 0x01832Au:
				func_01832A(a0);
				break;
			case 0x0489E2u:
				func_0489E2(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x048A60u:
				func_048A60(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x048A94u:
				func_048A94(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x048D8Au:
				func_048D8A(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x048DBAu:
				func_048DBA(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x048EDAu:
				func_048EDA(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x048F02u:
				func_048F02(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04A744u:
				func_04A744(a0, &d7, &a5);
				break;
			case 0x04A76Au:
				d7 = func_04A76A(d7, a0);
				break;
			case 0x04A7AAu:
				d7 = func_04A7AA(d7, a0);
				break;
			case 0x04A7F8u:
				func_04A7F8(a0);
				break;
			case 0x04A814u:
				func_04A814();
				break;
			case 0x04A830u:
				func_04A830(a0);
				break;
			case 0x04A856u:
				func_04A856(a0);
				break;
			case 0x04A880u:
				func_04A880(a0);
				break;
			case 0x04A8E6u:
				func_04A8E6(a0);
				break;
			case 0x04A97Eu:
				func_04A97E(a0);
				break;
			case 0x04A9B6u:
				func_04A9B6(a0);
				break;
			case 0x04AA82u:
				func_04AA82(a0);
				break;
			case 0x04AAAAu:
				func_04AAAA(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04AAE4u:
				d7 = func_04AAE4(d7, a0);
				break;
			case 0x04AB2Au:
				func_04AB2A(a0);
				break;
			case 0x04AB5Eu:
				d7 = func_04AB5E(d7, a0);
				break;
			case 0x04ABCAu:
				func_04ABCA(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04AC0Eu:
				func_04AC0E(a0);
				break;
			case 0x04AC22u:
				func_04AC22(a0, &d7, &a5);
				break;
			case 0x04ACB0u:
				func_04ACB0(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04AD3Cu:
				func_04AD3C(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04B7F8u:
				func_04B7F8(d0, a0, &d7, &a1);
				break;
			case 0x04B828u:
				func_04B828(d0, a0, &d7, &a1);
				break;
			case 0x04B88Eu:
				func_04B88E(a0, &d7, &a1);
				break;
			case 0x04B89Eu:
				func_04B89E(a0, &d7, &a1);
				break;
			case 0x04B900u:
				func_04B900(d0, a0, &d7, &a1);
				break;
			case 0x04B9C2u:
				func_04B9C2(a0);
				break;
			case 0x04BA04u:
				func_04BA04(a0);
				break;
			case 0x04BA34u:
				func_04BA34(a0);
				break;
			case 0x04BA56u:
				func_04BA56(a0);
				break;
			case 0x04BAB2u:
				func_04BAB2(a0);
				break;
			case 0x04BAC4u:
				func_04BAC4(a0);
				break;
			case 0x04BAE8u:
				d7 = func_04BAE8(d7, a0);
				break;
			case 0x04BB32u:
				func_04BB32(a0);
				break;
			case 0x04BB88u:
				func_04BB88(a0);
				break;
			case 0x04BBB6u:
				func_04BBB6(a0);
				break;
			case 0x04BBD8u:
				d7 = func_04BBD8(d7, a0);
				break;
			case 0x04BC0Eu:
				func_04BC0E(a0);
				break;
			case 0x04BC50u:
				func_04BC50(a0);
				break;
			case 0x04BC60u:
				func_04BC60(a0);
				break;
			case 0x04BC6Eu:
				d7 = func_04BC6E(d7, a0);
				break;
			case 0x04BC98u:
				func_04BC98(a0);
				break;
			case 0x04BCEEu:
				func_04BCEE(a0);
				break;
			case 0x04BD2Cu:
				func_04BD2C(a0);
				break;
			case 0x04BD78u:
				func_04BD78(a0);
				break;
			case 0x04BD9Eu:
				func_04BD9E(a0);
				break;
			case 0x04BDC0u:
				d7 = func_04BDC0(d7, a0);
				break;
			case 0x04BE12u:
				func_04BE12(a0);
				break;
			case 0x04BE5Au:
				func_04BE5A(a0);
				break;
			case 0x04BE92u:
				func_04BE92(a0);
				break;
			case 0x04BEBAu:
				func_04BEBA(a0);
				break;
			case 0x04BECEu:
				d7 = func_04BECE(d7, a0);
				break;
			case 0x04BEE8u:
				func_04BEE8(a0);
				break;
			case 0x04BF0Au:
				func_04BF0A(a0);
				break;
			case 0x04BF4Cu:
				func_04BF4C(a0);
				break;
			case 0x04BF96u:
				func_04BF96(a0);
				break;
			case 0x04BFA4u:
				d7 = func_04BFA4(d7, a0);
				break;
			case 0x04BFE6u:
				func_04BFE6(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x04C054u:
				func_04C054(a0);
				break;
			case 0x04C078u:
				func_04C078(a0);
				break;
			case 0x04C0AEu:
				func_04C0AE(a0);
				break;
			case 0x04C0F0u:
				func_04C0F0(a0);
				break;
			case 0x04C11Au:
				func_04C11A(a0);
				break;
			case 0x04C17Cu:
				func_04C17C(a0);
				break;
			case 0x04C1B6u:
				d7 = func_04C1B6(d7, a0);
				break;
			case 0x04C204u:
				func_04C204(a0);
				break;
			case 0x04C23Cu:
				func_04C23C(a0);
				break;
			case 0x04C264u:
				func_04C264(a0);
				break;
			case 0x04C2CEu:
				d7 = func_04C2CE(d7, a0);
				break;
			case 0x04C30Cu:
				func_04C30C(a0);
				break;
			case 0x04C32Au:
				func_04C32A(a0);
				break;
			case 0x04C35Eu:
				func_04C35E(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04C386u:
				d7 = func_04C386(d7, a0);
				break;
			case 0x04C3F2u:
				func_04C3F2(a0);
				break;
			case 0x04C4E6u:
				func_04C4E6(a0);
				break;
			case 0x04C4FCu:
				d7 = func_04C4FC(d7, a0);
				break;
			case 0x04C522u:
				func_04C522(a0, &d6, &d7, &a5);
				break;
			case 0x04C552u:
				func_04C552(a0);
				break;
			case 0x04C5F4u:
				func_04C5F4(a0, &d6, &d7, &a5);
				break;
			case 0x04C63Au:
				func_04C63A(a0);
				break;
			case 0x04C6E8u:
				func_04C6E8(a0);
				break;
			case 0x04C716u:
				a1 = func_04C716(a0);
				break;
			case 0x04C730u:
				func_04C730(a0, &d7, &a5);
				break;
			case 0x04C784u:
				func_04C784(a0);
				break;
			case 0x04C89Cu:
				func_04C89C(a0);
				break;
			case 0x04C8E0u:
				func_04C8E0(a0);
				break;
			case 0x04C906u:
				func_04C906(a0);
				break;
			case 0x04C936u:
				d7 = func_04C936(d7, a0);
				break;
			case 0x04C964u:
				func_04C964(a0, &d7, &a5);
				break;
			case 0x04C9C6u:
				func_04C9C6(a0);
				break;
			case 0x04CA06u:
				func_04CA06(a0);
				break;
			case 0x04CA2Cu:
				func_04CA2C(a0, &d7, &a5);
				break;
			case 0x04CA68u:
				func_04CA68(a0);
				break;
			case 0x04CA98u:
				func_04CA98(a0, &d7, &a5);
				break;
			case 0x04CAD2u:
				func_04CAD2(a0);
				break;
			case 0x04CBFCu:
				a5 = func_04CBFC(a0);
				break;
			case 0x04CC2Eu:
				func_04CC2E(a0, &d7, &a5);
				break;
			case 0x04CC76u:
				func_04CC76(a0, &d7, &a5);
				break;
			case 0x04CCA0u:
				func_04CCA0(a0);
				break;
			case 0x04CCECu:
				func_04CCEC(a0);
				break;
			case 0x04CD80u:
				func_04CD80(a0);
				break;
			case 0x04CDAAu:
				func_04CDAA(a0, &d7, &a5);
				break;
			case 0x04CE06u:
				func_04CE06(a0);
				break;
			case 0x04CECAu:
				d7 = func_04CECA(d7, a0);
				break;
			case 0x04CF10u:
				func_04CF10(a0);
				break;
			case 0x04D1AEu:
				func_04D1AE(a0);
				break;
			case 0x04D1DEu:
				d7 = func_04D1DE(d7, a0);
				break;
			case 0x04D24Cu:
				func_04D24C(a0, &d7, &a5);
				break;
			case 0x04D288u:
				func_04D288(a0);
				break;
			case 0x04D2A6u:
				func_04D2A6(a0);
				break;
			case 0x04D46Cu:
				func_04D46C(a0, &d6, &d7, &a5);
				break;
			case 0x04D488u:
				func_04D488(a0);
				break;
			case 0x04D4B0u:
				func_04D4B0(a0);
				break;
			case 0x04D4D0u:
				func_04D4D0(a0, &d7, &a5);
				break;
			case 0x04D4FEu:
				func_04D4FE(a0);
				break;
			case 0x04D52Cu:
				func_04D52C(a0);
				break;
			case 0x04D564u:
				func_04D564(a0);
				break;
			case 0x04D58Eu:
				func_04D58E(a0, p_d5, &d6, &d7, &a5);
				break;
			case 0x04D5EEu:
				func_04D5EE(a0, &d7, &a5);
				break;
			case 0x04D624u:
				func_04D624(a0);
				break;
			case 0x04D64Cu:
				func_04D64C(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04D6C8u:
				func_04D6C8(a0);
				break;
			case 0x04D6CEu:
				func_04D6CE(a0, &d7, &a5);
				break;
			case 0x04D722u:
				d7 = func_04D722(d7, a0);
				break;
			case 0x04D76Cu:
				func_04D76C(a0);
				break;
			case 0x04D782u:
				func_04D782(a0, &d7, &a5);
				break;
			case 0x04D7D0u:
				func_04D7D0(a0);
				break;
			case 0x04D7E8u:
				func_04D7E8(a0, &d7, &a5);
				break;
			case 0x04DC04u:
				func_04DC04(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04DC9Eu:
				func_04DC9E(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04E6A2u:
				func_04E6A2(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04E736u:
				func_04E736(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04EE2Eu:
				func_04EE2E(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04EEC8u:
				func_04EEC8(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04EF58u:
				func_04EF58(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04EFECu:
				func_04EFEC(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F002u:
				func_04F002(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F014u:
				func_04F014(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F026u:
				func_04F026(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F1D2u:
				func_04F1D2(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x04F28Au:
				func_04F28A(a0, a1, p_d5, &d6, &d7, &a5);
				break;
			case 0x04F3BAu:
				func_04F3BA(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F5E4u:
				func_04F5E4(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F622u:
				func_04F622(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x04F680u:
				func_04F680(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x0501C6u:
				func_0501C6(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x05027Au:
				func_05027A(a0, a1, p_d5, &d6, &d7, &a5);
				break;
			case 0x0503ECu:
				func_0503EC(d0, a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x050612u:
				func_050612(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x050622u:
				func_050622(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x05066Eu:
				func_05066E(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x050F98u:
				func_050F98(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x051002u:
				func_051002(a0, a1, p_d5, &d6, &d7, &a5);
				break;
			case 0x0510F4u:
				func_0510F4(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x051314u:
				func_051314(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x05144Eu:
				func_05144E(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x051492u:
				func_051492(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x051B56u:
				func_051B56(a0);
				break;
			case 0x051BA2u:
				d7 = func_051BA2(d7, a0);
				break;
			case 0x051BDAu:
				func_051BDA(a0);
				break;
			case 0x051BF4u:
				func_051BF4(a0, &d7, &a5);
				break;
			case 0x051C44u:
				func_051C44(a0, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x051CACu:
				func_051CAC(a0, a1, p_d5, &d6, &d7, &a5);
				break;
			case 0x051D80u:
				func_051D80(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x051FA0u:
				func_051FA0(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x052790u:
				func_052790(a0, a1, a6, p_d5, &d6, &d7, &a5);
				break;
			case 0x052830u:
				func_052830(a0, a1, p_d5, &d6, &d7, &a5);
				break;
			case 0x052840u:
				func_052840(a0, a6, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x052B84u:
				func_052B84(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x052BC8u:
				func_052BC8(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			case 0x052C68u:
				func_052C68(a0, p_d5, &d6, &d7, &a1, &a5);
				break;
			}
			func_04789C(a0);
		}
		a0 += 0x50u;
	} while (a0 < unk_062C80_ADDRESS);
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_04783C(uint32_t *p_d6, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0_2 = 0, d6 = 0;
	uint16_t t1 = 0;

	a6 = unk_062FA0_ADDRESS;
	d6 = 3u;
	d1 = 0u;
	d0 = 0xFFu;
	do
	{
		a5 = mem_read32(a6);
		if (mem_read8(a5) != 0u)
		{
			mem_write8(a5 + 0x44u, 0u);
			d1++;
			if (mem_read8(a6 + 4u) < (uint8_t)d0)
			{
				d0 = mem_read8(a6 + 4u);
				unk_061208 = a6;
				if (mem_read8(a6 + 8u) != 0u)
					mem_write8(a6 + 8u, mem_read8(a6 + 8u) - 1u);
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		a6 += 0x10u;
	} while (t1 != 0xFFFFu);
	d0_2 = 0u;
	unk_061207 = (uint8_t)d1;
	if ((uint8_t)d1 != 0u)
	{
		d0_2 = unk_06120C;
		zero = m68k_divu_z(d0_2, d1);
		d0_2 = d1 == 0u ? d0_2 : m68k_divu(d0_2, d1);
		if (d1 == 0u)
			func_00193E();
		if (zero)
			d0_2 = (uint16_t)(d0_2 + 1u);
	}
	unk_06120D = d0_2;
	*p_d6 = d6;
	*p_a5 = a5;
}

void func_04789C(uint32_t a0)
{
	uint16_t d0 = 0, d1 = 0, d2 = 0;
	uint32_t a4 = 0;

	if (mem_read8(a0) != 0u)
	{
		d0 = (uint16_t)(((int32_t)(mem_read32(a0 + 0x12u) - (unk_061218 & ~0xFFu)) >> 8) + 0x1A0u);
		mem_write16(a0 + 0xCu, d0);
		d2 = (uint16_t)(((int32_t)(mem_read32(a0 + 0x16u) - (unk_06121C & ~0xFFu)) >> 8) + 0x100u);
		mem_write16(a0 + 0xEu, d2);
		mem_write8(a0, mem_read8(a0) & 0xDFu);
		a4 = spawn_offsets_ADDRESS + (int16_t)((uint32_t)(int8_t)mem_read8(a0 + 2u) << 2);
		d1 = (uint16_t)d0;
		if ((int16_t)(d0 - mem_read16(a4)) >= 0x1C0 || (int16_t)(d1 + mem_read16(a4)) < 0x40 || (int16_t)d2 >= 0x120 || (int16_t)(d2 + mem_read16(a4 + 2u)) < -0x20)
		{
			mem_write8(a0, mem_read8(a0) | 0x20u);
			return;
		}
	}
}

uint32_t set_animation(uint32_t d1, uint32_t a0, uint32_t a6)
{
	uint32_t d1_2 = 0;

	d1_2 = (d1 & ~0xFFu) | mem_read8(a6);
	d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + mem_read8(a0 + 0x43u));
	mem_write8(a0 + 0x33u, d1_2);
	mem_write32(a0 + 0x36u, a6);
	return d1_2;
}

void func_047C02(uint16_t d0, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d0 &= 3u;
	d7 = indexed_table_of_8_bit_values_047BDE[d0];
	a6 = DATA32(rom_047BE2_ADDRESS + (uint16_t)((uint32_t)d0 << 2));
	do
	{
		t1 = mem_read8(a6);
		zero = t1 == 0u;
		if (t1 == 0u)
			break;
		t2 = d7 - 1u;
		d7 = t2;
		a6 += 0x50u;
	} while (t2 != 0xFFFFu);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a6 = a6;
	*p_zero = zero;
}

void func_047C30(uint32_t a0, uint32_t a5, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7 = 0;

	d0 = mem_read8(a5 + 5u);
	func_047C02(d0, &d7, &a6, &zero);
	if (zero)
	{
		mem_write16(a6, 0x100u);
		mem_write16(a6 + 2u, mem_read16(a5 + 6u));
		mem_write16(a6 + 4u, 0u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		mem_write8(a6 + 0x4Bu, 0u);
		zero = func_047C88(a0, a5, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a6 = a6;
	*p_zero = zero;
}

void func_047C5A(uint32_t a0, uint32_t a5, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7 = 0;

	d0 = 3u;
	func_047C02(d0, &d7, &a6, &zero);
	if (zero)
	{
		mem_write16(a6, 0x100u);
		mem_write8(a6 + 2u, mem_read8(a5 + 5u));
		mem_write8(a6 + 3u, 0u);
		mem_write16(a6 + 4u, 0u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		mem_write8(a6 + 0x4Bu, 0u);
		mem_write16(a6 + 0x28u, mem_read16(a0 + 0x28u));
		zero = func_047C88(a0, a5, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a6 = a6;
	*p_zero = zero;
}

uint32_t func_047C88(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint32_t zero = 0;
	uint16_t d1 = 0;

	d1 = mem_read16(a5);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a6, mem_read8(a6) | 0x40u);
		d1 = (uint16_t)(0u - d1);
	}
	mem_write32(a6 + 0x12u, ((uint32_t)(int16_t)d1 << 8) + mem_read32(a0 + 0x12u));
	mem_write32(a6 + 0x16u, ((uint32_t)(int16_t)mem_read16(a5 + 2u) << 8) + mem_read32(a0 + 0x16u));
	mem_write8(a6 + 0x10u, mem_read8(a5 + 4u) + mem_read8(a0 + 0x10u));
	zero = 1u;
	mem_write8(a6 + 0x11u, 0u);
	return zero;
}

void func_047CCC(uint8_t d0, uint16_t d1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d4 = 0;
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	*p_a5 = indexed_table_of_8_bit_values_047D50_ADDRESS;
	a6 = 0x47D8Fu;
	d4 = (uint8_t)d0 & 0x3Fu;
	if ((d0 & 0x40u) == 0u)
	{
		t1 = *p_a5;
		*p_a5 = a6;
		a6 = t1;
		d4 = (uint16_t)(0u - d4);
	}
	*p_d6 = ((uint32_t)mem_read8(*p_a5 + (int16_t)d4) * (uint16_t)d1) >> 8;
	if ((int8_t)(d0 + 0x40u) < 0)
		*p_d6 = (uint16_t)(0u - *p_d6);
	*p_d7 = ((uint32_t)mem_read8(a6 + (int16_t)(0u - d4)) * (uint16_t)d1) >> 8;
	if ((int8_t)d0 < 0)
	{
		return;
	}
	*p_d7 = (uint16_t)(0u - *p_d7);
}

void unreached_047D0E(uint8_t d0)
{
}

uint32_t func_047D90(uint32_t d0, uint32_t a0, uint32_t a6)
{
	uint32_t d1 = 0, d2 = 0;

	d1 = mem_read16(a6 + 0xCu);
	d2 = mem_read16(a6 + 0xEu);
	direction_to(a0, &d0, &d1, &d2);
	return d0;
}
