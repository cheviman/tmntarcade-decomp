/**
 *    Name:        unsorted/code_01A876.c
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

uint32_t func_01A876(uint32_t d7)
{
	switch (unk_060121)
	{
	case 0:
		return func_01A8B4(d7);
	case 1:
		func_01A928();
		return d7;
	case 2:
		func_01A95C();
		return d7;
	case 3:
		func_01A986();
		return d7;
	case 4:
		func_01AA00();
		return d7;
	case 5:
		func_01AA2A();
		return d7;
	case 6:
		func_01AA54();
		return d7;
	case 7:
		func_01AA7E();
		return d7;
	case 8:
		func_01AAA8();
		return d7;
	case 9:
		func_01AAD2();
		return d7;
	}
}

uint32_t func_01A8B4(uint32_t d7)
{
	uint32_t zero = 0;
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	if (unk_0633EC == 0u)
	{
		unk_0633C2 = 0xFFFFFFFFu;
		unk_0633EC = 0xFFu;
		unk_0633ED = 0u;
		return d7;
	}
	if (unk_0633ED == 0u)
	{
		zero = func_01AAF6();
		if (zero || unk_06120C != 0u)
			return d7;
		unk_0633ED = 0x60u;
		return d7;
	}
	t1 = unk_0633ED;
	unk_0633ED = t1 - 1u;
	if (t1 != 1u)
	{
		if (unk_0633ED != 0x40u)
			return d7;
		d7_2 = (d7 & ~0xFFu) | 0xBAu;
		func_0091A4((uint8_t)d7_2, 0u);
		d7_2 = (d7_2 & ~0xFFu) | 0xFEu;
		func_0091A4((uint8_t)d7_2, 0u);
		return d7_2;
	}
	unk_0633C8 = 0xFFu;
	return d7;
}

void func_01A928(void)
{
	uint32_t zero = 0;

	unk_0633C2 = 0xFFFFFFFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u && (int8_t)unk_0633FE < 0)
		unk_0633C8 = 0xFFu;
}

void func_01A95C(void)
{
	uint32_t zero = 0;

	unk_0633C2 = 0xFFFFFFFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01A986(void)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a0 = 0;

	if ((uint8_t)unk_0600A4 != 0u)
	{
		unk_0633C2 = (unk_0633C2 & 0xFFFFu) | 0xFFFF0000u;
		unk_0633EC = 0xFFu;
		zero = func_01AAF6();
		if (zero == 0u && unk_06120C == 0u)
			unk_0633C8 = 0xFFu;
		return;
	}
	a0 = unk_0623C0_ADDRESS;
	d0 = 0x88u;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && (mem_read8(a0) & 0x80u) != 0u && (int8_t)mem_read8(a0 + 0x4Bu) < 0 && (int8_t)mem_read8(a0 + 0x16u) >= 0 && d0 < mem_read8(a0 + 0x18u))
		{
			mem_write8(a0, 0u);
			unk_06120C--;
		}
		a0 += 0x50u;
	} while (a0 < 0x62780u);
	unk_0633C2 = (unk_0633C2 & 0xFFFFu) | 0xFFFF0000u;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AA00(void)
{
	uint32_t zero = 0;

	unk_0633C2 = 0xFFFFFFFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AA2A(void)
{
	uint32_t zero = 0;

	unk_0633C2 = (unk_0633C2 & 0xFFFFu) | 0xFFFF0000u;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AA54(void)
{
	uint32_t zero = 0;

	unk_0633C9 = 0xFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AA7E(void)
{
	uint32_t zero = 0;

	unk_0633C2 = 0xFFFFFFFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AAA8(void)
{
	uint32_t zero = 0;

	unk_0633C2 = 0xFFFFFFFFu;
	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

void func_01AAD2(void)
{
	uint32_t zero = 0;

	unk_0633EC = 0xFFu;
	zero = func_01AAF6();
	if (zero == 0u && unk_06120C == 0u)
		unk_0633C8 = 0xFFu;
}

uint32_t func_01AAF6(void)
{
	uint32_t zero = 0, carry = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	a6 = unk_062000_ADDRESS;
	d0 = unk_0600A1;
	do
	{
		carry = d0 & 1u;
		d0 = d0 >> 1;
		if (carry)
		{
			t1 = mem_read8(a6);
			zero = (t1 & 1u) == 0u;
			if ((t1 & 1u) == 0u)
				return zero;
			t2 = mem_read8(a6 + 4u);
			zero = (uint8_t)(t2 - 4u) == 0u;
			if (t2 == 4u)
				return zero;
		}
		a6 += 0x50u;
	} while (a6 < 0x62140u);
	zero = 0xFFu == 0u;
	return zero;
}

void func_01AB2C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d5 = 0, d7 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;
	uint32_t t3 = 0, t4 = 0;

	if (mem_read8(a0 + 4u) == 4u)
	{
		d0 = 2u;
		if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
			d0 = 1u;
		mem_write8(a1, d0);
	}
	else if (mem_read8(a0 + 4u) == 3u && (mem_read8(a0 + 5u) >= 9u || (mem_read8(a0 + 2u) == 3u && mem_read8(a0 + 5u) == 7u)))
	{
		d0 = 2u;
		if ((mem_read8(a0) & 0x40u) == 0u)
			mem_write8(a1, d0);
		else
		{
			d0 = 1u;
			mem_write8(a1, d0);
		}
	}
	func_047534(a0);
	func_01DE62(a0, &d5, &d7, &a6);
	d0 = mem_read8(a0 + 0x18u);
	t1 = mem_read8(a0 + 0x10u);
	carry = (uint8_t)(d0 + t1) < d0;
	d0 += t1;
	if (carry || d0 >= 0xF8u)
	{
		mem_write8(a0 + 1u, 0x86u);
		if (unk_060121 != 5u && (mem_read8(a0) & 0x10u) == 0u && ((int8_t)unk_0633D5 < 0 || (int8_t)unk_0633D6 < 0))
			mem_write8(a0 + 1u, 0xFEu);
	}
	else
		func_01AC84(a0, a1, a6);
	if ((mem_read8(a0 + 1u) & 1u) == 0u && mem_read8(a0 + 4u) != 2u && mem_read8(a0 + 4u) != 4u)
	{
		if (mem_read16(a0 + 0x10u) != 0u)
		{
			t2 = mem_read16(a0 + 0x10u);
			mem_write16(a0 + 0x10u, t2 - 0x400u);
			if (t2 < 0x400u)
			{
				mem_write16(a0 + 0x10u, 0u);
				d7 = (d7 & ~0xFFu) | 0x12u;
				if (unk_060121 == 3u)
					d7 = (d7 & ~0xFFu) | 0x30u;
				func_0091A4((uint8_t)d7, a6);
			}
			else if (mem_read8(a0 + 0x10u) < mem_read8(a0 + 0x32u))
			{
				if (mem_read8(a0 + 0x32u) >= 0x60u)
					mem_write8(a0 + 0x32u, 0u);
				mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
				mem_write8(a0 + 0x11u, 0u);
				if ((mem_read8(a0 + 1u) & 0x80u) != 0u)
				{
					d7 = (d7 & ~0xFFu) | 0x12u;
					if (unk_060121 != 3u || mem_read16(a0 + 0x10u) != 0u)
						func_0091A4((uint8_t)d7, a6);
					else
					{
						d7 = (d7 & ~0xFFu) | 0x30u;
						func_0091A4((uint8_t)d7, a6);
					}
				}
			}
		}
		else
		{
			t3 = mem_read32(a0 + 0x16u);
			t4 = t3 - 0x400u;
			mem_write16(a0 + 0x18u, t4);
			mem_write16(a0 + 0x16u, t4 >> 16);
			if (t3 < 0x400u)
			{
				mem_write16(a0 + 0x10u, 0u);
				d7 = (d7 & ~0xFFu) | 0x12u;
				if (unk_060121 == 3u)
					d7 = (d7 & ~0xFFu) | 0x30u;
				func_0091A4((uint8_t)d7, a6);
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void unreached_01AC7E(uint32_t a0)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	func_01DE62(a0, &ignored, &ignored_2, &ignored_3);
}

void func_01AC84(uint32_t a0, uint32_t a1, uint32_t a6)
{
	switch ((uint16_t)((mem_read8(a1) & 0xFu) << 2))
	{
	case 0:
		func_01D6BC(a0, a6);
		return;
	case 16:
		func_01D708(a0, a6);
		return;
	case 12:
	case 32:
		func_01D84C(a0, a6);
		return;
	case 8:
		func_01D8E6(a0, a6);
		return;
	case 4:
		func_01DA20(a0, a6);
		return;
	case 20:
		func_01DB54(a0, a6);
		return;
	case 24:
	case 28:
		func_01DB6E(a0, a6);
		return;
	case 40:
	case 44:
	case 48:
	case 52:
	case 56:
	case 60:
		func_01DCA6(a0, a6);
		return;
	case 36:
		func_01DD9C(a0, a6);
		return;
	}
}

uint32_t func_01ACDA(uint32_t d1, uint32_t a0)
{
	uint32_t carry = 0;
	uint32_t d0 = 0, d1_2 = 0;
	uint16_t t2 = 0, t4 = 0, t6 = 0, t8 = 0;
	uint32_t t1 = 0, t3 = 0, t5 = 0, t7 = 0;

	if ((int8_t)unk_0633C9 >= 0)
		return d1;
	d0 = unk_06330C;
	d1_2 = (d1 & ~0xFFFFu) | d0;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 << 5);
	if (unk_06331B != 0u)
	{
		if ((int8_t)unk_06331B < 0)
		{
			t1 = unk_063300 + d0;
			unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
			unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
			d0 = unk_063300 + 0x15800u;
			t2 = unk_063308;
			carry = (uint16_t)(t2 + d1_2) < t2;
			unk_063308 = t2 + d1_2;
			if (carry)
			{
				unk_06332C = d0;
				unk_063335--;
			}
		}
		else
		{
			t3 = unk_063300 - d0;
			unk_063300 = (unk_063300 & 0xFFFF0000u) | (t3 & 0xFFFFu);
			unk_063300 = (unk_063300 & 0xFFFFu) | ((t3 >> 16 & 0xFFFFu) << 16u);
			d0 = unk_063300 - 0x1800u;
			t4 = unk_063308;
			unk_063308 = t4 - d1_2;
			if (t4 < (uint16_t)d1_2)
			{
				unk_06332C = d0;
				unk_063335--;
			}
		}
	}
	d0 = unk_06330E;
	d1_2 = (d1_2 & ~0xFFFFu) | d0;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 << 5);
	if (unk_06331A == 0u)
		return d1_2;
	if ((int8_t)unk_06331A < 0)
	{
		t5 = unk_063304 - d0;
		unk_063304 = (unk_063304 & 0xFFFF0000u) | (t5 & 0xFFFFu);
		unk_063304 = (unk_063304 & 0xFFFFu) | ((t5 >> 16 & 0xFFFFu) << 16u);
		d0 = unk_063304 - 0xF800u;
		t6 = unk_06330A;
		unk_06330A = t6 - d1_2;
		if (t6 < (uint16_t)d1_2)
			return func_01B520(d0, d1_2, a0);
		return d1_2;
	}
	t7 = unk_063304 + d0;
	unk_063304 = (unk_063304 & 0xFFFF0000u) | (t7 & 0xFFFFu);
	unk_063304 = (unk_063304 & 0xFFFFu) | ((t7 >> 16 & 0xFFFFu) << 16u);
	d0 = unk_063304;
	t8 = unk_06330A;
	carry = (uint16_t)(t8 + d1_2) < t8;
	unk_06330A = t8 + d1_2;
	if (carry)
		return func_01B520(d0, d1_2, a0);
	return d1_2;
}

uint32_t func_01ADA0(uint32_t d1, uint32_t a0, uint32_t a1)
{
	bool L_01AE2C = false, L_01AEA8 = false, L_01AFD4 = false, L_01B012 = false, L_01B086 = false;
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, d2 = 0;
	uint8_t t1 = 0, t10 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0, t18 = 0;
	uint32_t t2 = 0, t6 = 0, t11 = 0, t15 = 0;

	mem_write8(a0 + 3u, 0u);
	t1 = mem_read8(a1) & 3u;
	d0 = t1;
	if (t1 != 0u)
	{
		if ((d0 & 1u) == 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			if ((int8_t)unk_0633C9 >= 0)
			{
				if (unk_06331B != 0u)
				{
					func_01B584(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 0xAu)
					{
						if ((mem_read8(a0 + 1u) & 8u) == 0u)
						{
							d1 &= 0xFFFFu;
							t2 = mem_read32(a0 + 0x12u) + d1;
							mem_write16(a0 + 0x14u, t2);
							mem_write16(a0 + 0x12u, t2 >> 16);
						}
					}
					else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
					{
						d1 &= 0xFFFFu;
						t2 = mem_read32(a0 + 0x12u) + d1;
						mem_write16(a0 + 0x14u, t2);
						mem_write16(a0 + 0x12u, t2 >> 16);
					}
				}
				else
				{
					do
					{
						if (L_01AFD4 || unk_061107 == 0u)
						{
							if (!L_01AFD4 && mem_read32(a0 + 0x12u) < 0x12000u)
							{
								func_01B584(a0, a1, &d0_2, &a6);
								d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
								if ((mem_read8(a1) & 0xFu) != 0xAu)
								{
									if ((mem_read8(a0 + 1u) & 8u) == 0u)
									{
										d1 &= 0xFFFFu;
										t2 = mem_read32(a0 + 0x12u) + d1;
										mem_write16(a0 + 0x14u, t2);
										mem_write16(a0 + 0x12u, t2 >> 16);
									}
								}
								else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
								{
									d1 &= 0xFFFFu;
									t2 = mem_read32(a0 + 0x12u) + d1;
									mem_write16(a0 + 0x14u, t2);
									mem_write16(a0 + 0x12u, t2 >> 16);
								}
							}
							else
							{
								L_01AFD4 = false;
								if (mem_read32(a0 + 0x12u) >= 0x16000u)
								{
									do
									{
										if (L_01B086 || (mem_read8(a1) & 0xFu) != 0xAu)
										{
											if (L_01B086 || (mem_read8(a0 + 1u) & 8u) == 0u)
											{
												L_01B086 = false;
												if ((uint8_t)(unk_0633C2 >> 16u) == 0u)
												{
													d0 = 0x7Fu;
													func_01B5D2(d0, a0, &d1, &carry);
													if (carry == 0u)
													{
														func_01B11C(a0, a1, &d0_2, &d1, &d2, &carry);
														if (carry)
														{
															unk_063300 = d2;
															unk_06330C = 0u;
															unk_063308 = 0u;
															unk_06331B = 0u;
														}
														else
														{
															t3 = unk_063308;
															carry = (uint16_t)(t3 + d1) < t3;
															unk_063308 = t3 + d1;
															if (carry)
															{
																unk_06332C = d0_2;
																unk_063335--;
															}
														}
													}
												}
											}
										}
										else
											L_01B086 = (mem_read8(a0 + 1u) & 0x28u) == 0u;
									} while (L_01B086);
								}
								else if ((uint8_t)(unk_0633C2 >> 16u) != 0u)
								{
									func_01B584(a0, a1, &d0_2, &a6);
									d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
									if ((mem_read8(a1) & 0xFu) != 0xAu)
									{
										if ((mem_read8(a0 + 1u) & 8u) == 0u)
										{
											d1 &= 0xFFFFu;
											t2 = mem_read32(a0 + 0x12u) + d1;
											mem_write16(a0 + 0x14u, t2);
											mem_write16(a0 + 0x12u, t2 >> 16);
										}
									}
									else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
									{
										d1 &= 0xFFFFu;
										t2 = mem_read32(a0 + 0x12u) + d1;
										mem_write16(a0 + 0x14u, t2);
										mem_write16(a0 + 0x12u, t2 >> 16);
									}
								}
								else
								{
									do
									{
										if (L_01B012 || (mem_read8(a1) & 0xFu) != 0xAu)
										{
											if (L_01B012 || (mem_read8(a0 + 1u) & 8u) == 0u)
											{
												L_01B012 = false;
												d0 = 0x7Fu;
												func_01B5D2(d0, a0, &d1, &carry);
												if (carry)
												{
													func_01B584(a0, a1, &d0_2, &a6);
													d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
													if ((mem_read8(a1) & 0xFu) != 0xAu)
													{
														if ((mem_read8(a0 + 1u) & 8u) == 0u)
														{
															d1 &= 0xFFFFu;
															t2 = mem_read32(a0 + 0x12u) + d1;
															mem_write16(a0 + 0x14u, t2);
															mem_write16(a0 + 0x12u, t2 >> 16);
														}
													}
													else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
													{
														d1 &= 0xFFFFu;
														t2 = mem_read32(a0 + 0x12u) + d1;
														mem_write16(a0 + 0x14u, t2);
														mem_write16(a0 + 0x12u, t2 >> 16);
													}
												}
												else
												{
													func_01B11C(a0, a1, &d0_2, &d1, &d2, &carry);
													if (carry)
													{
														d0_2 = unk_063300 - d2;
														d1 = d0_2;
														d0_2 = (d0_2 << 16) | (d0_2 >> 16);
														t4 = unk_06330C;
														unk_06330C = t4 - d1;
														if (t4 == (uint16_t)d1)
															unk_06331B = d0_2;
														unk_063300 = d2;
														unk_063308 = d0_2;
														if ((mem_read8(a1) & 0xFu) != 0xAu)
														{
															if ((mem_read8(a0 + 1u) & 8u) == 0u)
															{
																d1 &= 0xFFFFu;
																t2 = mem_read32(a0 + 0x12u) + d1;
																mem_write16(a0 + 0x14u, t2);
																mem_write16(a0 + 0x12u, t2 >> 16);
															}
														}
														else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
														{
															d1 &= 0xFFFFu;
															t2 = mem_read32(a0 + 0x12u) + d1;
															mem_write16(a0 + 0x14u, t2);
															mem_write16(a0 + 0x12u, t2 >> 16);
														}
													}
													else
													{
														t5 = unk_063308;
														carry = (uint16_t)(t5 + d1) < t5;
														unk_063308 = t5 + d1;
														if (carry)
														{
															unk_06332C = d0_2;
															unk_063335--;
														}
													}
												}
											}
										}
										else
											L_01B012 = (mem_read8(a0 + 1u) & 0x28u) == 0u;
									} while (L_01B012);
								}
							}
						}
						else
						{
							L_01AFD4 = mem_read32(a0 + 0x12u) >= 0x15800u;
							if (!L_01AFD4)
							{
								func_01B584(a0, a1, &d0_2, &a6);
								d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
								if ((mem_read8(a1) & 0xFu) != 0xAu)
								{
									if ((mem_read8(a0 + 1u) & 8u) == 0u)
									{
										d1 &= 0xFFFFu;
										t2 = mem_read32(a0 + 0x12u) + d1;
										mem_write16(a0 + 0x14u, t2);
										mem_write16(a0 + 0x12u, t2 >> 16);
									}
								}
								else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
								{
									d1 &= 0xFFFFu;
									t2 = mem_read32(a0 + 0x12u) + d1;
									mem_write16(a0 + 0x14u, t2);
									mem_write16(a0 + 0x12u, t2 >> 16);
								}
							}
						}
					} while (L_01AFD4);
				}
			}
			else if (unk_060121 == 8u || mem_read32(a0 + 0x12u) < 0x16000u)
			{
				func_01B584(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
				if ((mem_read8(a1) & 0xFu) != 0xAu)
				{
					if ((mem_read8(a0 + 1u) & 8u) == 0u)
					{
						d1 &= 0xFFFFu;
						t2 = mem_read32(a0 + 0x12u) + d1;
						mem_write16(a0 + 0x14u, t2);
						mem_write16(a0 + 0x12u, t2 >> 16);
					}
				}
				else if ((mem_read8(a0 + 1u) & 0x28u) == 0u)
				{
					d1 &= 0xFFFFu;
					t2 = mem_read32(a0 + 0x12u) + d1;
					mem_write16(a0 + 0x14u, t2);
					mem_write16(a0 + 0x12u, t2 >> 16);
				}
			}
		}
		else
		{
			mem_write8(a0, mem_read8(a0) | 0x40u);
			if ((int8_t)unk_0633C9 >= 0)
			{
				if (unk_06331B != 0u || mem_read32(a0 + 0x12u) >= 0xE000u)
				{
					func_01B584(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 9u)
					{
						if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
						{
							d1 &= 0xFFFFu;
							t6 = mem_read32(a0 + 0x12u) - d1;
							mem_write16(a0 + 0x14u, t6);
							mem_write16(a0 + 0x12u, t6 >> 16);
						}
					}
					else if ((mem_read8(a0 + 1u) & 0x50u) == 0u)
					{
						d1 &= 0xFFFFu;
						t6 = mem_read32(a0 + 0x12u) - d1;
						mem_write16(a0 + 0x14u, t6);
						mem_write16(a0 + 0x12u, t6 >> 16);
					}
				}
				else if (mem_read32(a0 + 0x12u) < 0x9100u)
				{
					do
					{
						if (L_01AEA8 || (mem_read8(a1) & 0xFu) != 9u)
						{
							if (L_01AEA8 || (mem_read8(a0 + 1u) & 0x10u) == 0u)
							{
								L_01AEA8 = false;
								if ((uint8_t)(unk_0633C2 >> 24u) == 0u)
								{
									d0 = 0u;
									func_01B5D2(d0, a0, &d1, &carry);
									if (carry == 0u)
									{
										func_01AF32(a0, a1, &d0_2, &d1, &carry);
										if (carry)
										{
											unk_063300 = unk_063324;
											unk_06330C = 0u;
											unk_063308 = 0u;
											unk_06331B = 0u;
										}
										else
										{
											t7 = unk_063308;
											unk_063308 = t7 - d1;
											if (t7 < (uint16_t)d1)
											{
												unk_06332C = d0_2;
												unk_063335--;
											}
										}
									}
								}
							}
						}
						else
							L_01AEA8 = (mem_read8(a0 + 1u) & 0x50u) == 0u;
					} while (L_01AEA8);
				}
				else if ((uint8_t)(unk_0633C2 >> 24u) != 0u)
				{
					func_01B584(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 9u)
					{
						if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
						{
							d1 &= 0xFFFFu;
							t6 = mem_read32(a0 + 0x12u) - d1;
							mem_write16(a0 + 0x14u, t6);
							mem_write16(a0 + 0x12u, t6 >> 16);
						}
					}
					else if ((mem_read8(a0 + 1u) & 0x50u) == 0u)
					{
						d1 &= 0xFFFFu;
						t6 = mem_read32(a0 + 0x12u) - d1;
						mem_write16(a0 + 0x14u, t6);
						mem_write16(a0 + 0x12u, t6 >> 16);
					}
				}
				else
				{
					do
					{
						if (L_01AE2C || (mem_read8(a1) & 0xFu) != 9u)
						{
							if (L_01AE2C || (mem_read8(a0 + 1u) & 0x10u) == 0u)
							{
								L_01AE2C = false;
								d0 = 0u;
								func_01B5D2(d0, a0, &d1, &carry);
								if (carry)
								{
									func_01B584(a0, a1, &d0_2, &a6);
									d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
									if ((mem_read8(a1) & 0xFu) != 9u)
									{
										if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
										{
											d1 &= 0xFFFFu;
											t6 = mem_read32(a0 + 0x12u) - d1;
											mem_write16(a0 + 0x14u, t6);
											mem_write16(a0 + 0x12u, t6 >> 16);
										}
									}
									else if ((mem_read8(a0 + 1u) & 0x50u) == 0u)
									{
										d1 &= 0xFFFFu;
										t6 = mem_read32(a0 + 0x12u) - d1;
										mem_write16(a0 + 0x14u, t6);
										mem_write16(a0 + 0x12u, t6 >> 16);
									}
								}
								else
								{
									func_01AF32(a0, a1, &d0_2, &d1, &carry);
									if (carry)
									{
										d1 = (d1 & ~0xFFFFu) | (uint16_t)(unk_063324 - unk_063300);
										t8 = unk_06330C;
										unk_06330C = t8 - d1;
										if (t8 == (uint16_t)d1)
											unk_06331B = 0u;
										unk_063300 = unk_063324;
										unk_063308 = 0u;
										if ((mem_read8(a1) & 0xFu) != 9u)
										{
											if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
											{
												d1 &= 0xFFFFu;
												t6 = mem_read32(a0 + 0x12u) - d1;
												mem_write16(a0 + 0x14u, t6);
												mem_write16(a0 + 0x12u, t6 >> 16);
											}
										}
										else if ((mem_read8(a0 + 1u) & 0x50u) == 0u)
										{
											d1 &= 0xFFFFu;
											t6 = mem_read32(a0 + 0x12u) - d1;
											mem_write16(a0 + 0x14u, t6);
											mem_write16(a0 + 0x12u, t6 >> 16);
										}
									}
									else
									{
										t9 = unk_063308;
										unk_063308 = t9 - d1;
										if (t9 < (uint16_t)d1)
										{
											unk_06332C = d0_2;
											unk_063335--;
										}
									}
								}
							}
						}
						else
							L_01AE2C = (mem_read8(a0 + 1u) & 0x50u) == 0u;
					} while (L_01AE2C);
				}
			}
			else if (mem_read32(a0 + 0x12u) >= 0x9000u)
			{
				func_01B584(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
				if ((mem_read8(a1) & 0xFu) != 9u)
				{
					if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
					{
						d1 &= 0xFFFFu;
						t6 = mem_read32(a0 + 0x12u) - d1;
						mem_write16(a0 + 0x14u, t6);
						mem_write16(a0 + 0x12u, t6 >> 16);
					}
				}
				else if ((mem_read8(a0 + 1u) & 0x50u) == 0u)
				{
					d1 &= 0xFFFFu;
					t6 = mem_read32(a0 + 0x12u) - d1;
					mem_write16(a0 + 0x14u, t6);
					mem_write16(a0 + 0x12u, t6 >> 16);
				}
			}
		}
	}
	t10 = mem_read8(a1) & 0xCu;
	d0 = t10;
	if (t10 == 0u)
		return d1;
	if ((d0 & 8u) != 0u)
	{
		if ((int8_t)unk_0633C9 >= 0)
		{
			if (unk_06331A != 0u || mem_read32(a0 + 0x16u) >= 0x6000u)
			{
				func_01B584(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((mem_read8(a0 + 1u) & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t11 = mem_read32(a0 + 0x16u) - d1;
				mem_write16(a0 + 0x18u, t11);
				mem_write16(a0 + 0x16u, t11 >> 16);
				return d1;
			}
			if (mem_read32(a0 + 0x16u) < 0x1100u)
			{
				if ((mem_read8(a0 + 1u) & 4u) != 0u || (uint8_t)unk_0633C2 != 0u)
					return d1;
				d0 = 0x80u;
				func_01B5D2(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				if (unk_061107 != 0u)
				{
					d0 = 0x7Fu;
					func_01B5D2(d0, a0, &d1, &carry);
					if (carry)
						return d1;
				}
				func_01B536(a0, a1, &d0_2, &d1, &carry);
				if (carry)
				{
					unk_063304 = unk_063328;
					unk_06330E = 0u;
					unk_06330A = 0u;
					unk_06331A = 0u;
					return d1;
				}
				t12 = unk_06330A;
				unk_06330A = t12 - d1;
				if (t12 < (uint16_t)d1)
					return func_01B520(d0_2, d1, a0);
				if (unk_061107 != 0u)
					return func_01B4C6(a0);
				return d1;
			}
			if ((uint8_t)unk_0633C2 != 0u)
			{
				func_01B584(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((mem_read8(a0 + 1u) & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t11 = mem_read32(a0 + 0x16u) - d1;
				mem_write16(a0 + 0x18u, t11);
				mem_write16(a0 + 0x16u, t11 >> 16);
				return d1;
			}
			if ((mem_read8(a0 + 1u) & 4u) != 0u)
				return d1;
			d0 = 0x80u;
			func_01B5D2(d0, a0, &d1, &carry);
			if (carry)
			{
				func_01B584(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((mem_read8(a0 + 1u) & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t11 = mem_read32(a0 + 0x16u) - d1;
				mem_write16(a0 + 0x18u, t11);
				mem_write16(a0 + 0x16u, t11 >> 16);
				return d1;
			}
			if (unk_061107 != 0u)
			{
				d0 = 0x7Fu;
				func_01B5D2(d0, a0, &d1, &carry);
				if (carry)
				{
					func_01B584(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
					if ((mem_read8(a0 + 1u) & 4u) != 0u)
						return d1;
					d1 &= 0xFFFFu;
					if (mem_read8(a0 + 4u) == 3u)
						d1 = d1 >> 3;
					t11 = mem_read32(a0 + 0x16u) - d1;
					mem_write16(a0 + 0x18u, t11);
					mem_write16(a0 + 0x16u, t11 >> 16);
					return d1;
				}
			}
			func_01B536(a0, a1, &d0_2, &d1, &carry);
			if (carry)
			{
				d1 = (d1 & ~0xFFFFu) | (uint16_t)(unk_063328 - unk_063304);
				t13 = unk_06330E;
				unk_06330E = t13 - d1;
				if (t13 == (uint16_t)d1)
					unk_06331A = 0u;
				unk_063304 = unk_063328;
				unk_06330A = 0u;
				if ((mem_read8(a0 + 1u) & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t11 = mem_read32(a0 + 0x16u) - d1;
				mem_write16(a0 + 0x18u, t11);
				mem_write16(a0 + 0x16u, t11 >> 16);
				return d1;
			}
			t14 = unk_06330A;
			unk_06330A = t14 - d1;
			if (t14 < (uint16_t)d1)
				return func_01B520(d0_2, d1, a0);
			if (unk_061107 != 0u)
				return func_01B4C6(a0);
			return d1;
		}
		if (mem_read32(a0 + 0x16u) < func_001000_ADDRESS)
			return d1;
		func_01B584(a0, a1, &d0_2, &a6);
		d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
		if ((mem_read8(a0 + 1u) & 4u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (mem_read8(a0 + 4u) == 3u)
			d1 = d1 >> 3;
		t11 = mem_read32(a0 + 0x16u) - d1;
		mem_write16(a0 + 0x18u, t11);
		mem_write16(a0 + 0x16u, t11 >> 16);
		return d1;
	}
	if ((int8_t)unk_0633C9 >= 0)
	{
		if (unk_06331A != 0u || mem_read32(a0 + 0x16u) < 0x6000u)
		{
			func_01B584(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((mem_read8(a0 + 1u) & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if (d0 != 6u)
			{
				if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if ((mem_read8(a0 + 1u) & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (mem_read8(a0 + 4u) == 3u)
				d1 = d1 >> 3;
			t15 = mem_read32(a0 + 0x16u) + d1;
			mem_write16(a0 + 0x18u, t15);
			mem_write16(a0 + 0x16u, t15 >> 16);
			return d1;
		}
		if (mem_read32(a0 + 0x16u) >= 0xA000u)
		{
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((mem_read8(a0 + 1u) & 0x50u) != 0u)
					return d1;
				if ((uint8_t)(unk_0633C2 >> 8u) != 0u)
					return d1;
				d0 = 0xFFu;
				func_01B5D2(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				func_01B322(a0, a1, &d0_2, &d1, &d2, &carry);
				if (carry)
				{
					unk_063304 = d2;
					unk_06330E = 0u;
					unk_06330A = 0u;
					unk_06331A = 0u;
					return d1;
				}
				t16 = unk_06330A;
				carry = (uint16_t)(t16 + d1) < t16;
				unk_06330A = t16 + d1;
				if (carry)
					return func_01B520(d0_2, d1, a0);
				return d1;
			}
			if (d0 != 6u)
			{
				if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
					return d1;
				if ((uint8_t)(unk_0633C2 >> 8u) != 0u)
					return d1;
				d0 = 0xFFu;
				func_01B5D2(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				func_01B322(a0, a1, &d0_2, &d1, &d2, &carry);
				if (carry)
				{
					unk_063304 = d2;
					unk_06330E = 0u;
					unk_06330A = 0u;
					unk_06331A = 0u;
					return d1;
				}
				t16 = unk_06330A;
				carry = (uint16_t)(t16 + d1) < t16;
				unk_06330A = t16 + d1;
				if (carry)
					return func_01B520(d0_2, d1, a0);
				return d1;
			}
			if ((mem_read8(a0 + 1u) & 0x28u) != 0u)
				return d1;
			if ((uint8_t)(unk_0633C2 >> 8u) != 0u)
				return d1;
			d0 = 0xFFu;
			func_01B5D2(d0, a0, &d1, &carry);
			if (carry)
				return d1;
			func_01B322(a0, a1, &d0_2, &d1, &d2, &carry);
			if (carry)
			{
				unk_063304 = d2;
				unk_06330E = 0u;
				unk_06330A = 0u;
				unk_06331A = 0u;
				return d1;
			}
			t16 = unk_06330A;
			carry = (uint16_t)(t16 + d1) < t16;
			unk_06330A = t16 + d1;
			if (carry)
				return func_01B520(d0_2, d1, a0);
			return d1;
		}
		if ((uint8_t)(unk_0633C2 >> 8u) != 0u)
		{
			func_01B584(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((mem_read8(a0 + 1u) & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if (d0 != 6u)
			{
				if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if ((mem_read8(a0 + 1u) & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (mem_read8(a0 + 4u) == 3u)
				d1 = d1 >> 3;
			t15 = mem_read32(a0 + 0x16u) + d1;
			mem_write16(a0 + 0x18u, t15);
			mem_write16(a0 + 0x16u, t15 >> 16);
			return d1;
		}
		d0 = mem_read8(a1) & 0xFu;
		if (d0 == 5u)
		{
			if ((mem_read8(a0 + 1u) & 0x50u) != 0u)
				return d1;
		}
		else if (d0 != 6u)
		{
			if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
				return d1;
		}
		else if ((mem_read8(a0 + 1u) & 0x28u) != 0u)
			return d1;
		d0 = 0xFFu;
		func_01B5D2(d0, a0, &d1, &carry);
		if (carry)
		{
			func_01B584(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((mem_read8(a0 + 1u) & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if (d0 != 6u)
			{
				if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (mem_read8(a0 + 4u) == 3u)
					d1 = d1 >> 3;
				t15 = mem_read32(a0 + 0x16u) + d1;
				mem_write16(a0 + 0x18u, t15);
				mem_write16(a0 + 0x16u, t15 >> 16);
				return d1;
			}
			if ((mem_read8(a0 + 1u) & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (mem_read8(a0 + 4u) == 3u)
				d1 = d1 >> 3;
			t15 = mem_read32(a0 + 0x16u) + d1;
			mem_write16(a0 + 0x18u, t15);
			mem_write16(a0 + 0x16u, t15 >> 16);
			return d1;
		}
		func_01B322(a0, a1, &d0_2, &d1, &d2, &carry);
		if (carry == 0u)
		{
			t17 = unk_06330A;
			carry = (uint16_t)(t17 + d1) < t17;
			unk_06330A = t17 + d1;
			if (carry)
				return func_01B520(d0_2, d1, a0);
			return d1;
		}
		d0_2 -= d2;
		d1 = (d1 & ~0xFFFFu) | (uint16_t)d0_2;
		d0_2 = (d0_2 << 16) | (d0_2 >> 16);
		t18 = unk_06330E;
		unk_06330E = t18 - d1;
		if (t18 == (uint16_t)d1)
			unk_06331A = d0_2;
		unk_063304 = d2;
		unk_06330A = d0_2;
		d0 = mem_read8(a1) & 0xFu;
		if (d0 == 5u)
		{
			if ((mem_read8(a0 + 1u) & 0x52u) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (mem_read8(a0 + 4u) == 3u)
				d1 = d1 >> 3;
			t15 = mem_read32(a0 + 0x16u) + d1;
			mem_write16(a0 + 0x18u, t15);
			mem_write16(a0 + 0x16u, t15 >> 16);
			return d1;
		}
		if (d0 != 6u)
		{
			if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (mem_read8(a0 + 4u) == 3u)
				d1 = d1 >> 3;
			t15 = mem_read32(a0 + 0x16u) + d1;
			mem_write16(a0 + 0x18u, t15);
			mem_write16(a0 + 0x16u, t15 >> 16);
			return d1;
		}
		if ((mem_read8(a0 + 1u) & 0x2Au) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (mem_read8(a0 + 4u) == 3u)
			d1 = d1 >> 3;
		t15 = mem_read32(a0 + 0x16u) + d1;
		mem_write16(a0 + 0x18u, t15);
		mem_write16(a0 + 0x16u, t15 >> 16);
		return d1;
	}
	if (mem_read32(a0 + 0x16u) >= 0xA000u)
		return d1;
	func_01B584(a0, a1, &d0_2, &a6);
	d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
	d0 = mem_read8(a1) & 0xFu;
	if (d0 == 5u)
	{
		if ((mem_read8(a0 + 1u) & 0x52u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (mem_read8(a0 + 4u) == 3u)
			d1 = d1 >> 3;
		t15 = mem_read32(a0 + 0x16u) + d1;
		mem_write16(a0 + 0x18u, t15);
		mem_write16(a0 + 0x16u, t15 >> 16);
		return d1;
	}
	if (d0 != 6u)
	{
		if ((mem_read8(a0 + 1u) & 0x62u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (mem_read8(a0 + 4u) == 3u)
			d1 = d1 >> 3;
		t15 = mem_read32(a0 + 0x16u) + d1;
		mem_write16(a0 + 0x18u, t15);
		mem_write16(a0 + 0x16u, t15 >> 16);
		return d1;
	}
	if ((mem_read8(a0 + 1u) & 0x2Au) != 0u)
		return d1;
	d1 &= 0xFFFFu;
	if (mem_read8(a0 + 4u) == 3u)
		d1 = d1 >> 3;
	t15 = mem_read32(a0 + 0x16u) + d1;
	mem_write16(a0 + 0x18u, t15);
	mem_write16(a0 + 0x16u, t15 >> 16);
	return d1;
}

void func_01AF32(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0_2 = 0, d1 = 0;
	uint32_t a6 = 0, d0 = 0, d2 = 0;
	uint32_t t1 = 0;

	unk_06331B = 0x7Fu;
	func_01B584(a0, a1, &d0, &a6);
	unk_06330C = mem_read16(a6 + (uint16_t)d0);
	mem_write8(a0 + 3u, 0x7Fu);
	d0_2 = unk_06330C;
	d1 = (uint16_t)((uint32_t)d0_2 << 5);
	t1 = unk_063300 - d0_2;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	d0 = unk_063300;
	d2 = d0;
	d0 -= 0x1800u;
	carry = d2 < unk_063324;
	*p_d0 = d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

void func_01B11C(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	unk_06331B = 0x80u;
	func_01B584(a0, a1, p_d0, &a6);
	unk_06330C = mem_read16(a6 + (uint16_t)*p_d0);
	mem_write8(a0 + 3u, 0x7Fu);
	d0 = unk_06330C;
	d1 = (uint16_t)((uint32_t)d0 << 5);
	t1 = unk_063300 + d0;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	*p_d0 = unk_063300 + 0x15800u;
	*p_d2 = unk_06331C;
	carry = *p_d2 < unk_063300;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

void func_01B322(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0_2 = 0, d1 = 0;
	uint32_t a6 = 0, d0 = 0;
	uint32_t t1 = 0;

	unk_06331A = 0x7Fu;
	mem_write8(a0 + 3u, mem_read8(a0 + 3u) | 0x80u);
	func_01B584(a0, a1, &d0, &a6);
	d0_2 = mem_read16(a6 + 4u + (uint16_t)d0);
	if (mem_read8(a0 + 4u) == 3u)
		d0_2 = d0_2 >> 3;
	unk_06330E = d0_2;
	d1 = (uint16_t)((uint32_t)d0_2 << 5);
	t1 = unk_063304 + d0_2;
	unk_063304 = (unk_063304 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063304 = (unk_063304 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	d0 = unk_063304;
	*p_d2 = unk_063320;
	carry = *p_d2 < d0;
	*p_d0 = d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

uint32_t func_01B4C6(uint32_t a0)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t d0_2 = 0, d1 = 0;
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	d0 = 0x7Fu;
	func_01B5D2(d0, a0, &d1, &carry);
	if (carry == 0u && unk_06331B == 0u)
	{
		unk_06331B = 0x80u;
		unk_06330C = 0x120u;
		d1 = 0x120u;
		d1 = (uint16_t)(d1 << 5);
		t1 = unk_063300 + 0x120u;
		unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
		unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
		d0_2 = unk_063300;
		t2 = unk_063308;
		carry = (uint16_t)(t2 + d1) < t2;
		unk_063308 = t2 + d1;
		d0_2 += 0x15800u;
		if (carry)
		{
			unk_06332C = d0_2;
			unk_063335--;
		}
	}
	return d1;
}

uint32_t func_01B520(uint32_t d0, uint32_t d1, uint32_t a0)
{
	unk_063330 = d0;
	unk_063334--;
	if (unk_061107 != 0u)
		return func_01B4C6(a0);
	return d1;
}

void func_01B536(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0_2 = 0, d1 = 0;
	uint32_t a6 = 0, d0 = 0, d2 = 0;
	uint32_t t1 = 0;

	unk_06331A = 0x80u;
	mem_write8(a0 + 3u, mem_read8(a0 + 3u) | 0x80u);
	func_01B584(a0, a1, &d0, &a6);
	d0_2 = mem_read16(a6 + 4u + (uint16_t)d0);
	if (mem_read8(a0 + 4u) == 3u)
		d0_2 = d0_2 >> 3;
	unk_06330E = d0_2;
	d1 = (uint16_t)((uint32_t)d0_2 << 5);
	t1 = unk_063304 - d0_2;
	unk_063304 = (unk_063304 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063304 = (unk_063304 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	d0 = unk_063304;
	d2 = d0;
	d0 -= 0xF800u;
	carry = d2 < unk_063328;
	*p_d0 = d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

void func_01B584(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_a6)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d0_2 = 0, d2 = 0;

	d2 = 0u;
	d0 = mem_read8(a1);
	d1 = (uint8_t)d0;
	if ((d0 & 3u) != 0u && (d1 & 0xCu) != 0u)
		d2 = 2u;
	*p_a6 = table_loaded_by_lea_01B5B2_ADDRESS;
	d0_2 = (uint16_t)(((mem_read8(a0 + 2u) & 3u) << 3) + d2);
	*p_d0 = (*p_d0 & 0xFFFF0000u) | d0_2;
}

void func_01B5D2(uint8_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t a6 = 0, d1 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a6 = unk_062000_ADDRESS;
	d1 = 4u;
	if ((uint8_t)d0 != 0u)
	{
		if ((int8_t)d0 < 0)
		{
			if ((d0 & 0x7Fu) != 0u)
			{
				do
				{
					if (a6 != a0 && (mem_read8(a6) & 1u) != 0u && mem_read16(a6 + 0x10u) + mem_read32(a6 + 0x16u) < 0x1100u)
					{
						carry = 1u;
						break;
					}
					t1 = d1;
					carry = t1 == 0u;
					d1 = (uint8_t)(t1 - 1u);
					a6 += 0x50u;
				} while (t1 != 1u);
			}
			else
			{
				do
				{
					if (a6 != a0 && (mem_read8(a6) & 1u) != 0u && mem_read16(a6 + 0x10u) + mem_read32(a6 + 0x16u) >= 0xA000u)
					{
						carry = 1u;
						break;
					}
					t2 = d1;
					carry = t2 == 0u;
					d1 = (uint8_t)(t2 - 1u);
					a6 += 0x50u;
				} while (t2 != 1u);
			}
		}
		else
		{
			do
			{
				if (a6 != a0 && (mem_read8(a6) & 1u) != 0u && mem_read32(a6 + 0x12u) < 0x9100u)
				{
					carry = 1u;
					break;
				}
				t3 = d1;
				carry = t3 == 0u;
				d1 = (uint8_t)(t3 - 1u);
				a6 += 0x50u;
			} while (t3 != 1u);
		}
	}
	else
	{
		do
		{
			if (a6 != a0 && (mem_read8(a6) & 1u) != 0u && mem_read32(a6 + 0x12u) >= 0x16000u)
			{
				carry = 1u;
				break;
			}
			t4 = d1;
			carry = t4 == 0u;
			d1 = (uint8_t)(t4 - 1u);
			a6 += 0x50u;
		} while (t4 != 1u);
	}
	*p_d1 = d1;
	*p_carry = carry;
}

void func_01B69E(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t carry = 0;
	uint8_t d2 = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(a0, mem_read8(a0) & ~2u);
	if (mem_read8(a0 + 0x2Du) == 0u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write8(a0, mem_read8(a0) | 0x80u);
	}
	else
	{
		t1 = mem_read8(a0 + 0x2Du) - 1u;
		mem_write8(a0 + 0x2Du, t1);
		if ((int8_t)t1 >= 0)
			mem_write8(a0, mem_read8(a0) | 0x80u);
		else if (mem_read8(a0 + 0x2Du) != 0x80u)
		{
			if ((unk_0600A4 & 1u) == 0u)
				mem_write8(a0, mem_read8(a0) ^ 0x80u);
		}
		else
		{
			mem_write8(a0 + 0x2Du, 0u);
			mem_write8(a0, mem_read8(a0) | 2u);
			mem_write8(a0, mem_read8(a0) | 0x80u);
		}
	}
	*p_d1 = (*p_d1 & ~0xFFu) | mem_read8(a1);
	d2 = mem_read8(a2);
	if ((d2 & 0x20u) != 0u)
		mem_write8(a0 + 0x31u, 0u);
	t2 = mem_read8(a0 + 0x31u);
	carry = (uint8_t)(t2 + 1u) < t2;
	mem_write8(a0 + 0x31u, t2 + 1u);
	if (carry)
		mem_write8(a0 + 0x31u, mem_read8(a0 + 0x31u) - 1u);
	switch (mem_read8(a0 + 4u))
	{
	case 0:
		func_01B94C(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 1:
		func_01B9BA(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 2:
		func_01BA1C(d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 3:
		func_01BD50(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 4:
		func_01C212(d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 5:
		func_01D512(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01B740(uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	if (unk_060121 == 6u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xCu);
		d0 = 0u;
		if (mem_read8(a0 + 0x45u) == 0u)
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		else
		{
			d0 = 4u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	else
	{
		mem_write8(a0, mem_read8(a0) & ~0xCu);
		d0 = 0x100u;
		if (mem_read8(a0 + 0x45u) != 0u)
			d0 += 2u;
		if ((*p_d1 & 4u) == 0u)
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		else
		{
			d0++;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01B76A(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0 = 0;
	uint16_t d0_2 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	if ((mem_read8(a2) & 0x20u) == 0u)
	{
		unk_0633CA--;
		mem_write8(a0, mem_read8(a0) & ~0xCu);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write32(a0 + 0x1Au, 0x5000010u);
		mem_write8(a0 + 0x1Fu, 0u);
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x500u);
		d0_2 = 0x201u;
		func_01B8C2(d0_2, a0, p_d1, &ignored_2, &d5, &ignored, p_d7);
		func_01BA1C((uint8_t)ignored, a0, a1, a2, p_d1, &d5, p_d7);
	}
	else
	{
		mem_write8(a0, mem_read8(a0) & ~8u);
		mem_write8(a0, mem_read8(a0) | 4u);
		mem_write8(a0 + 0x2Eu, 0u);
		mem_write16(a0 + 0x46u, 6u);
		d0 = 7u;
		if (mem_read8(a0 + 2u) == 3u)
			func_01B85C(d0, a0, p_d1, &d5, &ignored, p_d7);
		else
		{
			d0 = 8u;
			mem_write16(a0 + 0x1Au, 0x900u);
			mem_write16(a0 + 0x1Cu, 0u);
			func_01B85C(d0, a0, p_d1, &d5, &ignored, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01B7D0(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a1) & 3u;
	mem_write8(a1, t1);
	if (t1 != 0u)
	{
		if ((mem_read8(a1) & 1u) != 0u)
			mem_write8(a0, mem_read8(a0) | 0x40u);
		else
			mem_write8(a0, mem_read8(a0) & 0xBFu);
	}
	mem_write8(a1, 0u);
	if (mem_read8(a0 + 0x45u) == 0u)
	{
		d7 = 4u;
		func_048448(a0, &ignored_2, &d7);
		d7 = d7 & 3u;
		d7 = (uint16_t)(d7 + (d7 << 1));
		mem_write16(a0 + 0x46u, d7);
		a6 = rom_01D5F2[mem_read8(a0 + 2u) & 3u];
		if (mem_read8(a0 + 0x44u) == 0u)
		{
			d0_2 = mem_read8(a6 + d7);
			func_01B85C(d0_2, a0, p_d1, &d5, &ignored_2, &d7);
		}
		else
		{
			mem_write8(a0 + 0x2Eu, 1u);
			d7 = (uint16_t)(d7 + 0xCu);
			mem_write16(a0 + 0x46u, mem_read16(a0 + 0x46u) + 0xCu);
			d0_2 = 3u;
			*p_d1 = (*p_d1 & ~0xFFu) | 3u;
			func_01B862(d0_2, a0, p_d1, &d5, &ignored_2, &d7);
		}
	}
	else
	{
		mem_write8(a0, mem_read8(a0) & ~8u);
		mem_write8(a0, mem_read8(a0) | 4u);
		mem_write8(a0 + 0x2Eu, 0u);
		d0 = 0x500u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, &d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void func_01B85C(uint8_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	*p_d1 = (*p_d1 & ~0xFFu) | d0;
	mem_write8(a0 + 0x2Eu, 0u);
	func_01B862(d0, a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01B862(uint16_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0, ignored = 0;

	mem_write8(a0, mem_read8(a0) & ~8u);
	mem_write8(a0, mem_read8(a0) | 4u);
	d1 = (d1 & ~0xFFu) | (uint8_t)(d1 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
	if ((mem_read8(a0) & 0x40u) != 0u)
		d1 = d1 | 0x80u;
	if (d0 == 3u)
		d1 = d1 ^ 0x80u;
	mem_write8(a0 + 6u, d1);
	d1 = LINKED(d1, d1 & 0x7Fu);
	d7_2 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1];
	func_0091A4((uint8_t)d7_2, 0u);
	d1 = LINKED(d1, (uint16_t)(d1 << 1));
	mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1 / 2u]);
	d0 = (uint16_t)((d0 & 0x7Fu) + 0x300u);
	func_01B8C2(d0, a0, &d1, &ignored, &d5, &d6, &d7_2);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_01B8C2(uint16_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d2 = 0;

	if (d0 == 0x411u)
	{
		d7 = (d7 & ~0xFFu) | 0x26u;
		func_0091A4((uint8_t)d7, 0u);
		d1 = (d1 & ~0xFFFFu) | mem_read8(a0 + 2u);
		d2 = (uint16_t)d1;
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 << 3);
		if (RAM16(unk_060100_ADDRESS + (uint16_t)d1) == 0u)
		{
			d0 &= ~0xFFu;
			unk_06014C(d2) = (uint8_t)d0;
			if ((mem_read8(a0) & 0x40u) != 0u)
				d0 |= (uint8_t)(d0 - 1u);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
			d2 = (uint16_t)(mem_read16(a0 + 0xEu) - 0x10u);
			func_030076(d0, d2, a0, &d1, p_d4, &d5, &d6, &d7);
			d0 = 0x411u;
		}
	}
	mem_write8(a0 + 0x1Eu, 0u);
	mem_write16(a0 + 4u, d0);
	d1 = func_01B920(d1, a0);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

uint32_t func_01B920(uint32_t d1, uint32_t a0)
{
	uint16_t d3 = 0;
	uint32_t a6 = 0;

	d3 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
	a6 = animations_0208C0[d3 / 4u];
	d3 = (uint16_t)(IN_PAGE(d3, mem_read8(a0 + 4u)) << 2);
	a6 = mem_read32(mem_read32(a6 + d3) + (uint16_t)(IN_PAGE(d3, mem_read8(a0 + 5u)) << 2));
	return set_animation(d1, a0, a6);
}

void func_01B94C(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d3 = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(a0, mem_read8(a0) & ~0xCu);
	d3 = (uint8_t)d2;
	if (unk_0633C8 != 0u)
	{
		t1 = d1 & 0xFu;
		d1 = (d1 & ~0xFFu) | t1;
		if (t1 != 0u)
			func_01B740(d6, a0, &d1, &d5, p_d7);
		else if (mem_read8(a0 + 0x45u) == 0u && mem_read8(a0 + 0x33u) == 0u)
		{
			mem_write8(a0 + 0x1Eu, mem_read8(a0 + 0x1Eu) + 1u);
			if (mem_read8(a0 + 0x1Eu) >= 0x18u)
			{
				mem_write8(a0 + 0x1Eu, 0u);
				mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
				t2 = mem_read8(a0 + 5u) & 3u;
				mem_write8(a0 + 5u, t2);
				if (t2 != 0u)
					d1 = func_01B920(d1, a0);
				else
				{
					mem_write8(a0 + 5u, 1u);
					d1 = func_01B920(d1, a0);
				}
			}
		}
	}
	else if ((mem_read8(a0 + 1u) & 1u) == 0u || (d2 & 0x10u) == 0u)
	{
		if ((d3 & 0x20u) != 0u)
			func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
		else
		{
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 != 0u)
				func_01B740(d6, a0, &d1, &d5, p_d7);
			else if (mem_read8(a0 + 0x45u) == 0u && mem_read8(a0 + 0x33u) == 0u)
			{
				mem_write8(a0 + 0x1Eu, mem_read8(a0 + 0x1Eu) + 1u);
				if (mem_read8(a0 + 0x1Eu) >= 0x18u)
				{
					mem_write8(a0 + 0x1Eu, 0u);
					mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
					t2 = mem_read8(a0 + 5u) & 3u;
					mem_write8(a0 + 5u, t2);
					if (t2 != 0u)
						d1 = func_01B920(d1, a0);
					else
					{
						mem_write8(a0 + 5u, 1u);
						d1 = func_01B920(d1, a0);
					}
				}
			}
		}
	}
	else
		func_01B76A(d6, a0, a1, a2, &d1, &d5, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01B9BA(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d3 = 0;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(a0, mem_read8(a0) & ~0xCu);
	d3 = (uint8_t)d2;
	if (unk_0633C8 != 0u)
	{
		d0 = 0x100u;
		if (mem_read8(a0 + 0x45u) != 0u)
			d0 += 2u;
		t1 = d1 & 0xFu;
		d1 = (d1 & ~0xFFu) | t1;
		if (t1 == 0u)
		{
			mem_write8(a0, mem_read8(a0) & ~0xCu);
			d0 = 0u;
			if (mem_read8(a0 + 0x45u) == 0u)
				func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			else
			{
				d0 = 4u;
				func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
		}
		else
		{
			t2 = d1 & 4u;
			d1 = (d1 & ~0xFFu) | t2;
			if (t2 != 0u)
			{
				d0++;
				if ((mem_read8(a0 + 5u) & 1u) == 0u)
					func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
			else if ((mem_read8(a0 + 5u) & 1u) != 0u)
				func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	else if ((mem_read8(a0 + 1u) & 1u) == 0u || (d2 & 0x10u) == 0u)
	{
		if ((d3 & 0x20u) != 0u)
			func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
		else
		{
			d0 = 0x100u;
			if (mem_read8(a0 + 0x45u) != 0u)
				d0 += 2u;
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 == 0u)
			{
				mem_write8(a0, mem_read8(a0) & ~0xCu);
				d0 = 0u;
				if (mem_read8(a0 + 0x45u) == 0u)
					func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				else
				{
					d0 = 4u;
					func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				}
			}
			else
			{
				t2 = d1 & 4u;
				d1 = (d1 & ~0xFFu) | t2;
				if (t2 != 0u)
				{
					d0++;
					if ((mem_read8(a0 + 5u) & 1u) == 0u)
						func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				}
				else if ((mem_read8(a0 + 5u) & 1u) != 0u)
					func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
		}
	}
	else
		func_01B76A(d6, a0, a1, a2, &d1, &d5, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BA1C(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	unk_0633CA--;
	mem_write8(a0, mem_read8(a0) & ~0xCu);
	if ((mem_read8(a2) & 0x20u) == 0u)
	{
		switch (mem_read8(a0 + 5u))
		{
		case 0:
		case 1:
			func_01BAA0(d6, a0, a1, &d1, &d5, p_d7);
			break;
		case 2:
			func_01BAE2(d6, a0, a1, &d1, &d5, p_d7);
			break;
		case 3:
			func_01BC70(d6, a0, &d1, &d5, p_d7);
			break;
		case 4:
			func_01BCE6(d6, a0, a1, &d1, &d5, p_d7);
			break;
		}
	}
	else
	{
		d2 = 0x38u;
		if (mem_read8(a0 + 2u) == 3u)
			d2 = 0x20u;
		mem_write8(a0, mem_read8(a0) | 4u);
		d1 = (d1 & ~0xFFu) | mem_read8(a0 + 0x10u);
		d1 = (d1 & ~0xFFu) | (uint8_t)(d1 - mem_read8(a0 + 0x32u));
		mem_write8(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x500u);
		d0 = 0xAu;
		if ((uint8_t)d1 >= 0x60u)
			func_01B85C(d0, a0, &d1, &d5, &ignored, p_d7);
		else
		{
			d0--;
			if (d2 <= (uint8_t)d1)
				func_01B85C(d0, a0, &d1, &d5, &ignored, p_d7);
			else
			{
				mem_write16(a0 + 0x1Au, 0x800u);
				d0 += 2u;
				mem_write8(a0 + 0x1Du, 0u);
				func_01B85C(d0, a0, &d1, &d5, &ignored, p_d7);
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BAA0(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x1Du) == 0u)
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) - 0x50u);
	else
	{
		t1 = mem_read8(a0 + 0x1Du);
		mem_write8(a0 + 0x1Du, t1 - 1u);
		if (t1 == 1u)
			mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) - 0x50u);
		else if ((mem_read8(a1) & 0x10u) == 0u)
			mem_write8(a0 + 0x1Du, 0u);
	}
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
	if (mem_read16(a0 + 0x1Au) < 0x400u)
	{
		d0 = 0x202u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BAE2(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	if (mem_read8(a0 + 0x1Fu) != 0u && mem_read8(a0 + 0x33u) == 0u)
	{
		d0 = 0x203u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	if (mem_read8(a0 + 0x1Cu) != 0u)
	{
		if (mem_read16(a0 + 0x10u) + mem_read32(a0 + 0x16u) < 0xF400u && (uint8_t)(mem_read8(a0 + 0x10u) - mem_read8(a0 + 0x32u)) >= 0x40u)
		{
			if ((mem_read8(a1) & 1u) != 0u)
			{
				if ((mem_read8(a0 + 1u) & 0x10u) != 0u)
				{
					mem_write8(a0 + 0x1Fu, 0u);
					mem_write8(a1, 0u);
					mem_write16(a0 + 0x1Au, 0u);
					d0 = 0x205u;
					func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					mem_write8(a0 + 0x1Du, 8u);
					mem_write8(a0 + 5u, 4u);
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			else if ((mem_read8(a1) & 2u) != 0u && (mem_read8(a0 + 1u) & 8u) != 0u)
			{
				mem_write8(a0 + 0x1Fu, 0xFFu);
				mem_write8(a1, 0u);
				mem_write16(a0 + 0x1Au, 0u);
				d0 = 0x205u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				mem_write8(a0 + 0x1Du, 8u);
				mem_write8(a0 + 5u, 4u);
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if ((mem_read8(a0 + 1u) & 1u) != 0u)
		{
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
			func_01BCAE(d6, a0, p_d1, &d5, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x50u);
		if (mem_read16(a0 + 0x1Au) >= 0x500u)
			mem_write16(a0 + 0x1Au, 0x500u);
		d0 = mem_read16(a0 + 0x1Au);
		t1 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t1 - d0);
		if (t1 < d0)
			func_01BCAA((uint8_t)d6, a0, p_d1, &d5, p_d7);
	}
	else
	{
		if (mem_read16(a0 + 0x10u) + mem_read32(a0 + 0x16u) < 0xF400u && (uint8_t)(mem_read8(a0 + 0x10u) - mem_read8(a0 + 0x32u)) >= 0x40u)
		{
			if ((mem_read8(a1) & 1u) != 0u)
			{
				if ((mem_read8(a0 + 1u) & 0x10u) != 0u)
				{
					mem_write8(a0 + 0x1Fu, 0u);
					mem_write8(a1, 0u);
					mem_write16(a0 + 0x1Au, 0u);
					d0 = 0x205u;
					func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					mem_write8(a0 + 0x1Du, 8u);
					mem_write8(a0 + 5u, 4u);
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			else if ((mem_read8(a1) & 2u) != 0u && (mem_read8(a0 + 1u) & 8u) != 0u)
			{
				mem_write8(a0 + 0x1Fu, 0xFFu);
				mem_write8(a1, 0u);
				mem_write16(a0 + 0x1Au, 0u);
				d0 = 0x205u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				mem_write8(a0 + 0x1Du, 8u);
				mem_write8(a0 + 5u, 4u);
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if (mem_read8(a0 + 0x1Du) != 0u)
		{
			t2 = mem_read8(a0 + 0x1Du);
			mem_write8(a0 + 0x1Du, t2 - 1u);
			if (t2 == 1u)
			{
				t3 = mem_read16(a0 + 0x1Au);
				mem_write16(a0 + 0x1Au, t3 - 0x50u);
				if (t3 >= 0x50u)
				{
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
					if (mem_read16(a0 + 0x1Au) < 0x380u && mem_read8(a0 + 0x1Fu) == 0u)
					{
						mem_write8(a0 + 0x1Fu, mem_read8(a0 + 0x1Fu) - 1u);
						d0 = 0x204u;
						func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
						mem_write8(a0 + 5u, 2u);
					}
				}
				else
				{
					mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
					mem_write8(a0 + 0x1Cu, ~mem_read8(a0 + 0x1Cu));
				}
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			t4 = *p_d1 & 0x10u;
			*p_d1 = (*p_d1 & ~0xFFu) | t4;
			if (t4 != 0u)
			{
				mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
				if (mem_read16(a0 + 0x1Au) < 0x380u && mem_read8(a0 + 0x1Fu) == 0u)
				{
					mem_write8(a0 + 0x1Fu, mem_read8(a0 + 0x1Fu) - 1u);
					d0 = 0x204u;
					func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					mem_write8(a0 + 5u, 2u);
				}
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			mem_write8(a0 + 0x1Du, 0u);
			mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
			if (mem_read16(a0 + 0x1Au) < 0x380u && mem_read8(a0 + 0x1Fu) == 0u)
			{
				mem_write8(a0 + 0x1Fu, mem_read8(a0 + 0x1Fu) - 1u);
				d0 = 0x204u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				mem_write8(a0 + 5u, 2u);
			}
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		t3 = mem_read16(a0 + 0x1Au);
		mem_write16(a0 + 0x1Au, t3 - 0x50u);
		if (t3 >= 0x50u)
		{
			mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
			if (mem_read16(a0 + 0x1Au) < 0x380u && mem_read8(a0 + 0x1Fu) == 0u)
			{
				mem_write8(a0 + 0x1Fu, mem_read8(a0 + 0x1Fu) - 1u);
				d0 = 0x204u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				mem_write8(a0 + 5u, 2u);
			}
		}
		else
		{
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
			mem_write8(a0 + 0x1Cu, ~mem_read8(a0 + 0x1Cu));
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BC70(uint8_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	if ((mem_read8(a0 + 1u) & 1u) == 0u)
	{
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x50u);
		if (mem_read16(a0 + 0x1Au) >= 0x500u)
			mem_write16(a0 + 0x1Au, 0x500u);
		d0 = mem_read16(a0 + 0x1Au);
		t1 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t1 - d0);
		if (t1 < d0)
			func_01BCAA(d6, a0, p_d1, &d5, p_d7);
	}
	else
	{
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
		mem_write8(a0 + 0x11u, 0u);
		func_01BCAE(d6, a0, p_d1, &d5, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BCAA(uint8_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	mem_write16(a0 + 0x10u, 0u);
	func_01BCAE(d6, a0, p_d1, &d5, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BCAE(uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0;

	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	d0 = 0u;
	if (mem_read8(a0 + 0x45u) != 0u)
		d0 = 4u;
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, &ignored_3, &d7);
	d7_2 = (d7 & ~0xFFu) | 0x12u;
	if (unk_060121 == 3u && mem_read16(a0 + 0x10u) == 0u)
		d7_2 = (d7_2 & ~0xFFu) | 0x30u;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7_2;
}

void func_01BCE6(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint16_t t3 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write8(a1, 0u);
	if (mem_read8(a0 + 0x1Du) == 0u)
	{
		if ((mem_read8(a0 + 1u) & 1u) == 0u)
		{
			if (mem_read8(a0 + 0x1Fu) != 0u)
			{
				if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
				{
					t1 = mem_read32(a0 + 0x12u) - 0x300u;
					mem_write16(a0 + 0x14u, t1);
					mem_write16(a0 + 0x12u, t1 >> 16);
				}
			}
			else if ((mem_read8(a0 + 1u) & 8u) == 0u)
			{
				t2 = mem_read32(a0 + 0x12u) + 0x300u;
				mem_write16(a0 + 0x14u, t2);
				mem_write16(a0 + 0x12u, t2 >> 16);
			}
			mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x28u);
			d0 = mem_read16(a0 + 0x1Au);
			t3 = mem_read16(a0 + 0x10u);
			mem_write16(a0 + 0x10u, t3 - d0);
			if (t3 < d0)
				func_01BCAA(d6, a0, p_d1, &d5, p_d7);
		}
		else
		{
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
			func_01BCAE(d6, a0, p_d1, &d5, p_d7);
		}
	}
	else
		mem_write8(a0 + 0x1Du, mem_read8(a0 + 0x1Du) - 1u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BD50(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d2_2 = 0;
	uint16_t d0_2 = 0;
	uint32_t d0 = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;
	uint32_t t1 = 0, t6 = 0;

	unk_0633CA--;
	if (mem_read8(a0 + 5u) >= 8u)
	{
		mem_write8(a1, mem_read8(a1) & 0x10u);
		d0 = 0x400u;
		if (mem_read8(a0 + 5u) != 9u)
		{
			d0 = (uint16_t)(d0 - 0x180u);
			if (mem_read8(a0 + 5u) != 0xBu)
			{
				d0 = (uint16_t)(d0 - 0x80u);
				if (mem_read8(a0 + 5u) != 0xAu)
					d0 = 0u;
			}
		}
		d1 = 3u;
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			d1 = (uint8_t)(d1 + 1u);
			d0 = 0u - d0;
		}
		if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d1))) == 0u)
		{
			t1 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
		}
		if (mem_read8(a0 + 0x1Cu) != 0u)
		{
			if ((mem_read8(a0 + 1u) & 1u) == 0u)
			{
				mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
				if (mem_read16(a0 + 0x1Au) >= 0x500u)
					mem_write16(a0 + 0x1Au, 0x500u);
				d0_2 = mem_read16(a0 + 0x1Au);
				t2 = mem_read16(a0 + 0x10u);
				mem_write16(a0 + 0x10u, t2 - d0_2);
				if (t2 < d0_2)
					func_01BCAA(d6, a0, &d1, &d5, p_d7);
			}
			else
			{
				mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
				mem_write8(a0 + 0x11u, 0u);
				func_01BCAE(d6, a0, &d1, &d5, p_d7);
			}
		}
		else if (mem_read8(a0 + 0x1Du) == 0u)
		{
			t3 = mem_read16(a0 + 0x1Au);
			mem_write16(a0 + 0x1Au, t3 - 0x40u);
			if (t3 >= 0x40u)
				mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
			else
			{
				mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
				mem_write8(a0 + 0x1Cu, ~mem_read8(a0 + 0x1Cu));
			}
		}
		else
		{
			t4 = mem_read8(a0 + 0x1Du);
			mem_write8(a0 + 0x1Du, t4 - 1u);
			if (t4 == 1u)
			{
				t3 = mem_read16(a0 + 0x1Au);
				mem_write16(a0 + 0x1Au, t3 - 0x40u);
				if (t3 >= 0x40u)
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
				else
				{
					mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
					mem_write8(a0 + 0x1Cu, ~mem_read8(a0 + 0x1Cu));
				}
			}
			else
			{
				t5 = mem_read8(a1) & 0x10u;
				mem_write8(a1, t5);
				if (t5 != 0u)
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
				else
				{
					mem_write8(a0 + 0x1Du, 0u);
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
				}
			}
		}
	}
	else if (mem_read8(a0 + 0x33u) == 0u)
		func_01BEA4(d2, d6, a0, a1, a2, &d1, &d5, p_d7);
	else if (mem_read8(a0 + 5u) == 3u)
		mem_write8(a1, mem_read8(a1) & 0xCu);
	else if (mem_read8(a0 + 2u) != 3u || mem_read8(a0 + 5u) != 7u)
	{
		d0 = 0x40u;
		d1 = 1u;
		d2_2 = 3u;
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			d0 = 0u - d0;
			d1 = 0u;
			d2_2++;
		}
		if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d2_2))) != 0u || (mem_read8(a1) & shl32(1u, (int)(d1))) == 0u)
			mem_write8(a1, mem_read8(a1) & 0xCu);
		else
		{
			t6 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t6);
			mem_write16(a0 + 0x12u, t6 >> 16);
			mem_write8(a1, mem_read8(a1) & 0xCu);
		}
	}
	else
	{
		mem_write8(a1, 0u);
		d0 = 0x300u;
		d1 = 3u;
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			d0 = 0u - d0;
			d1 = (uint8_t)(d1 + 1u);
		}
		if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d1))) == 0u)
		{
			t6 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t6);
			mem_write16(a0 + 0x12u, t6 >> 16);
			mem_write8(a1, mem_read8(a1) & 0xCu);
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01BEA4(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	if (unk_0633C8 != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xCu);
		d0 = 0u;
		if (mem_read8(a0 + 0x45u) == 0u)
		{
			func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		d0 = 4u;
		func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	if (mem_read8(a0 + 5u) == 5u)
	{
		mem_write8(a0, mem_read8(a0) | 8u);
		*p_d7 = (*p_d7 & ~0xFFFFu) | 0x401u;
		if (mem_read8(a0 + 2u) != 0u)
		{
			*p_d7 = (*p_d7 & ~0xFFFFu) | 0x408u;
			if (mem_read8(a0 + 2u) != 3u)
			{
				mem_write8(a0, mem_read8(a0) ^ 0x40u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | 0x402u;
				if ((mem_read8(a0 + 2u) & 1u) == 0u)
					*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)(*p_d7 + 2u);
			}
		}
		func_004164((uint16_t)*p_d7);
	}
	if (mem_read8(a0 + 0x31u) < 0xDu)
	{
		if (unk_0633C8 != 0u)
		{
			mem_write8(a0, mem_read8(a0) & ~0xCu);
			d0 = 0u;
			if (mem_read8(a0 + 0x45u) == 0u)
			{
				func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			d0 = 4u;
			func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (mem_read8(a0 + 0x45u) != 0u)
		{
			func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if ((mem_read8(a0) & 8u) == 0u)
		{
			mem_write8(a0, mem_read8(a0) & ~0xCu);
			if ((d2 & 0x10u) != 0u)
			{
				func_01B76A(d6, a0, a1, a2, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			if ((d2 & 0x20u) != 0u)
			{
				func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 != 0u)
			{
				func_01B740(d6, a0, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			mem_write8(a0, mem_read8(a0) & ~0xCu);
			d0 = 0u;
			if (mem_read8(a0 + 0x45u) == 0u)
			{
				func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			d0 = 4u;
			func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		mem_write8(a0, mem_read8(a0) & ~8u);
		mem_write8(a0, mem_read8(a0) | 4u);
		if (mem_read8(a0 + 0x2Eu) == 0u)
		{
			mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) + 1u);
			a4 = rom_01D5F2[mem_read8(a0 + 2u) & 3u];
			if (mem_read8(a0 + 0x44u) != 0u)
			{
				mem_write16(a0 + 0x46u, mem_read16(a0 + 0x46u) + 0xCu);
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x46u);
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
				if ((mem_read8(a0) & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				mem_write8(a0 + 6u, d1_2);
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				func_0091A4((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				func_01B8C2(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			a6 = mem_read32(a0 + 0x4Au);
			if ((int8_t)mem_read8(a6 + 0x4Bu) < 0 && mem_read8(a6 + 9u) != 0u && mem_read8(a6 + 0x10u) == mem_read8(a6 + 0x32u))
			{
				d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 1);
				d1_2 = (d1 & ~0xFFFFu) | d0;
				d0 = (uint16_t)(((uint32_t)d0 << 1) + d1_2);
				d1 = LINKED(d1_2, indexed_table_of_16_bit_values_01C072[d0 / 2u]);
				a5 = TABLE32(rom_01C074, d0);
				if (mem_read16(a5) >= 0x100u)
				{
					mem_write16(a5, 0u);
					mem_write8(a0 + 0x1Eu, 0u);
					mem_write8(a1, 0u);
					mem_write16(a6 + 4u, 0x500u);
					mem_write16(a6 + 0x28u, d1);
					d0_2 = 0u;
					if ((mem_read8(a0) & 0x40u) == 0u)
						d0_2 = 0x80u;
					mem_write8(a6 + 0x30u, d0_2);
					mem_write16(a0 + 0x46u, mem_read16(a0 + 0x46u) + 0x18u);
					d1_2 = (d1 & ~0xFFFFu) | 5u;
					mem_write16(a0 + 4u, 0x305u);
					if (mem_read8(a0 + 2u) == 0u || mem_read8(a0 + 2u) == 3u)
						mem_write8(a0, mem_read8(a0) ^ 0x40u);
					d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
					if ((mem_read8(a0) & 0x40u) != 0u)
						d1_2 = d1_2 | 0x80u;
					mem_write8(a0 + 6u, d1_2);
					d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
					*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
					func_0091A4((uint8_t)*p_d7, a6);
					d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
					mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
					a6 = mem_read32(animations_01C08A[mem_read8(a0 + 2u)] - 0x10u + (uint16_t)((mem_read8(mem_read32(a0 + 0x4Au) + 0x4Bu) & 7u) << 2));
					d1_2 = set_animation(d1_2, a0, a6);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			t2 = mem_read8(a1) & 3u;
			mem_write8(a1, t2);
			if (t2 == 0u)
			{
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x46u);
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
				if ((mem_read8(a0) & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				mem_write8(a0 + 6u, d1_2);
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				func_0091A4((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				func_01B8C2(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			if ((mem_read8(a1) & 1u) != 0u)
			{
				mem_write8(a0, mem_read8(a0) | 0x40u);
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x46u);
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
				if ((mem_read8(a0) & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				mem_write8(a0 + 6u, d1_2);
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				func_0091A4((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				func_01B8C2(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			mem_write8(a1, 0u);
			*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x46u);
			d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
			d1_2 = (d1 & ~0xFFu) | d0;
			d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
			if ((mem_read8(a0) & 0x40u) != 0u)
				d1_2 = d1_2 | 0x80u;
			if (d0 == 3u)
				d1_2 = d1_2 ^ 0x80u;
			mem_write8(a0 + 6u, d1_2);
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
			func_0091A4((uint8_t)*p_d7, a6);
			d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
			mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
			d0 = (uint16_t)((d0 & 7u) + 0x300u);
			func_01B8C2(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (mem_read8(a0 + 0x2Eu) != 1u)
		{
			func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (mem_read8(a0 + 5u) != 5u)
		{
			t3 = mem_read8(a1) & 3u;
			mem_write8(a1, t3);
			if (t3 != 0u)
			{
				if ((mem_read8(a1) & 1u) != 0u)
					mem_write8(a0, mem_read8(a0) | 0x40u);
				else
					mem_write8(a0, mem_read8(a0) & 0xBFu);
			}
		}
		mem_write8(a1, 0u);
		mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) + 1u);
		*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x46u);
		d0 = mem_read8(rom_01D5F2[mem_read8(a0 + 2u) & 3u] + 2u + (int16_t)*p_d7);
		d1_2 = (d1 & ~0xFFu) | d0;
		d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[mem_read8(a0 + 2u) & 3u]);
		if ((mem_read8(a0) & 0x40u) != 0u)
			d1_2 = d1_2 | 0x80u;
		if (d0 == 3u)
			d1_2 = d1_2 ^ 0x80u;
		mem_write8(a0 + 6u, d1_2);
		d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
		*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
		func_0091A4((uint8_t)*p_d7, 0u);
		d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
		mem_write16(a0 + 0xAu, rom_01D592[(uint16_t)d1_2 / 2u]);
		d0 = (uint16_t)((d0 & 7u) + 0x300u);
		func_01B8C2(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1_2;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	mem_write8(a0, mem_read8(a0) & ~0xCu);
	if ((d2 & 0x10u) != 0u)
	{
		func_01B76A(d6, a0, a1, a2, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	if ((d2 & 0x20u) != 0u)
	{
		func_01B7D0(d6, a0, a1, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	t1 = d1 & 0xFu;
	d1 = (d1 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		func_01B740(d6, a0, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	mem_write8(a0, mem_read8(a0) & ~0xCu);
	d0 = 0u;
	if (mem_read8(a0 + 0x45u) == 0u)
	{
		func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	d0 = 4u;
	func_01B8C2(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01C212(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0, d2 = 0;
	uint32_t a6 = 0, d1_2 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;

	mem_write8(a1, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	if (mem_read8(a0 + 5u) == 0u)
	{
		d7_2 = (d7 & ~0xFFu) | rom_01D556[mem_read16(mem_read32(a0 + 0x28u) + 0x28u) >> 2];
		if ((uint8_t)d7_2 != 0xFFu)
			func_0091A4((uint8_t)d7_2, 0u);
		mem_write8(a0 + 0x1Cu, 0u);
		mem_write8(a0 + 0x23u, 0u);
		mem_write16(a0 + 0x24u, 0u);
		mem_write8(a0 + 0x26u, 0u);
		d0 = 0u;
		if ((mem_read8(a0) & 0x40u) != 0u)
		{
			if ((int8_t)mem_read8(a0 + 7u) >= 0)
			{
				d0 = 0x80u;
				d0 = d0 | 1u;
			}
		}
		else if ((int8_t)mem_read8(a0 + 7u) >= 0)
			d0 = d0 | 1u;
		else
			d0 = 0x80u;
		mem_write8(a0 + 0x22u, (uint8_t)d0);
		if (mem_read8(a0 + 0x40u) == 4u)
		{
			d1_2 = IN_PAGE(d1, mem_read8(a0 + 7u));
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			if ((uint8_t)d1_2 != 0xFu && (uint8_t)d1_2 != 0x10u)
			{
				d1_2 = 0x15u;
				if (mem_read8(a0 + 0x27u) != 0x10u && mem_read8(a0 + 0x27u) >= 5u)
					mem_write8(a0 + 0x27u, 4u);
				mem_write8(a0 + 0x23u, d1_2);
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = func_01D416(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
		}
		else
		{
			if (mem_read8(a0 + 0x40u) == 3u && mem_read16(a0 + 0x46u) >= 0x18u)
			{
				a6 = mem_read32(a0 + 0x4Au);
				if ((mem_read8(a6) & 0x80u) == 0u)
				{
					mem_write16(a6 + 4u, 0x500u);
					d1 = LINKED(d1, mem_read8(a0 + 2u));
					d1 = LINKED(d1, (uint16_t)(d1 << 1));
					mem_write16(a6 + 0x28u, rom_01C596[(uint16_t)d1 / 2u]);
				}
			}
			d1_2 = IN_PAGE(d1, mem_read8(a0 + 7u));
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			if ((uint8_t)d1_2 == 0xEu)
			{
				mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
				mem_write8(a0 + 0x11u, 0u);
			}
			if ((uint8_t)d1_2 == 0x18u)
			{
				if (mem_read8(a0 + 8u) == 0u)
				{
					d7_2 = (d7_2 & ~0xFFu) | 0x26u;
					func_0091A4((uint8_t)d7_2, a6);
					if ((int8_t)mem_read8(a0 + 0x22u) >= 0 || (uint8_t)d1_2 >= 9u)
					{
						mem_write8(a0 + 0x23u, d1_2);
						d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
						func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
						d7_2 = func_01D416(d7_2, a0);
						*p_d1 = d1_2;
						*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
						*p_d7 = d7_2;
						return;
					}
					d1_2 = 6u;
					mem_write8(a0 + 0x23u, d1_2);
					d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
					func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
					d7_2 = func_01D416(d7_2, a0);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					*p_d7 = d7_2;
					return;
				}
				d1_2 = 4u;
			}
		}
		if (mem_read8(a0 + 0x27u) != 0x10u)
			mem_write8(a0 + 0x27u, 0u);
		if (mem_read8(a0 + 8u) == 0u && (uint8_t)d1_2 < 9u)
		{
			d1_2 = 7u;
			mem_write8(a0 + 7u, 7u);
		}
		for (;;)
		{
			d0 = mem_read8(a0 + 0x32u);
			if (d0 != mem_read8(a0 + 0x10u))
			{
				if ((uint8_t)d1_2 >= 9u)
				{
					mem_write8(a0 + 0x23u, d1_2);
					d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
					func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
					d7_2 = func_01D416(d7_2, a0);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					*p_d7 = d7_2;
					return;
				}
				if ((uint8_t)d1_2 < 4u)
				{
					d1_2 = 4u;
					if (mem_read8(a0 + 9u) != 0u)
					{
						t1 = mem_read8(a0 + 8u);
						mem_write8(a0 + 8u, t1 - 1u);
						if (t1 == 1u)
						{
							d1_2 = 7u;
							mem_write8(a0 + 7u, 7u);
							continue;
						}
						d1_2 = 0x16u;
					}
				}
				if ((int8_t)mem_read8(a0 + 0x22u) >= 0)
					break;
				if ((uint8_t)d1_2 == 4u)
				{
					mem_write8(a0, mem_read8(a0) ^ 0x40u);
					mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) & 0x7Fu);
					break;
				}
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + 1u);
				break;
			}
			if (mem_read8(a0 + 9u) != 0u)
			{
				if ((int8_t)mem_read8(a0 + 0x22u) < 0 && (uint8_t)d1_2 < 9u)
					d1_2 = 6u;
				mem_write8(a0 + 0x23u, d1_2);
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = func_01D416(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			if ((uint8_t)d1_2 >= 9u)
			{
				mem_write8(a0 + 0x23u, d1_2);
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = func_01D416(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			if ((uint8_t)d1_2 < 4u)
				d1_2 = 4u;
			if ((int8_t)mem_read8(a0 + 0x22u) >= 0)
				break;
			d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + 1u);
			break;
		}
		d2 = (uint16_t)(d1_2 << 2);
		mem_write16(a0 + 0x20u, TABLE16(table_loaded_by_lea_01C546, d2 - 0x10u));
		mem_write16(a0 + 0x1Au, TABLE16(table_loaded_by_lea_01C546, d2 - 0xEu));
		d0 = (uint8_t)unk_0600A4;
		d0 = d0 & 1u;
		mem_write8(a0 + 0x25u, (uint8_t)d0);
		d6 = 0xE000u;
		d7_2 = 0x12000u;
		if ((uint8_t)d1_2 != 4u)
		{
			if ((uint8_t)d1_2 != 5u)
			{
				mem_write8(a0 + 0x23u, d1_2);
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = func_01D416(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			d6 = 0x10000u;
			d7_2 = 0x10000u;
		}
		if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
		{
			if (mem_read32(a0 + 0x12u) <= d7_2)
			{
				d0 = 0u;
				if (mem_read8(a0 + 8u) < 5u)
					d0 = (uint8_t)(d0 + 1u);
				mem_write8(a0 + 0x25u, (uint8_t)d0);
				mem_write8(a0 + 0x23u, d1_2);
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = func_01D416(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			mem_write8(a0 + 0x25u, mem_read8(a0 + 0x25u) + 2u);
			mem_write8(a0 + 0x23u, d1_2);
			d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
			func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
			d7_2 = func_01D416(d7_2, a0);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7_2;
			return;
		}
		if (d6 < mem_read32(a0 + 0x12u))
		{
			d0 = 0u;
			if (mem_read8(a0 + 8u) < 5u)
				d0 = (uint8_t)(d0 + 1u);
			mem_write8(a0 + 0x25u, (uint8_t)d0);
			mem_write8(a0 + 0x23u, d1_2);
			d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
			func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
			d7_2 = func_01D416(d7_2, a0);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7_2;
			return;
		}
		mem_write8(a0 + 0x25u, mem_read8(a0 + 0x25u) + 2u);
		mem_write8(a0 + 0x23u, d1_2);
		d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
		func_01B8C2(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
		d7_2 = func_01D416(d7_2, a0);
		*p_d1 = d1_2;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		*p_d7 = d7_2;
		return;
	}
	switch (mem_read8(a0 + 0x23u))
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 6:
	case 13:
		func_01C59E(a0);
		break;
	case 4:
		func_01C664(a0, &d1, &d5, &ignored, &d7);
		break;
	case 5:
		func_01C7BC(a0, &d1, &d5, &ignored, &d7);
		break;
	case 7:
		unreached_01C8E4(a0, &d1, &d5, &ignored, &d7);
		break;
	case 8:
		func_01CAAE(a0, &d1, &d5, &ignored, &d7);
		break;
	case 9:
		func_01CC96(a0, &d1, &d5, &ignored, &d7);
		break;
	case 10:
	case 11:
		func_01CD30(a0, &d1, &d5, &ignored, &d7);
		break;
	case 12:
		func_01CDA8(a0, &d1, &d5, &ignored, &d7);
		break;
	case 14:
		func_01CE3E(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 15:
		func_01D014(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 16:
		func_01D0EC(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 17:
	case 18:
	case 19:
	case 20:
		d7 = func_01C5AE(d7, a0);
		break;
	case 21:
		func_01CF3A(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 22:
	case 23:
		d7 = func_01D23C(a0);
		break;
	case 24:
		func_01C5BE(a0, &d1, &d5, &ignored, &d7);
		break;
	case 25:
		func_01C630(a0);
		break;
	}
	if (mem_read8(a0 + 0x24u) == 0xFFu)
	{
		if (mem_read8(a0 + 9u) == 0u)
			mem_write8(a0 + 9u, 3u);
		if (mem_read8(a0 + 8u) != 0u)
		{
			d0 = 0u;
			func_01B8C2(d0, a0, &d1, &ignored_2, &d5, &ignored, &d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7;
			return;
		}
		unk_060150 = 0u;
		mem_write8(a0, 0u);
		unk_0600A0 |= shl32(1u, (int)(mem_read8(a0 + 2u) & 7u));
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void func_01C59E(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write8(a0 + 0x24u, 0xFFu);
}

uint32_t func_01C5AE(uint32_t d7, uint32_t a0)
{
	mem_write8(a0 + 0x24u, 0xFFu);
	mem_write16(a0 + 8u, 0xA03u);
	return func_01D416(d7, a0);
}

void func_01C5BE(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;
	uint16_t t1 = 0;

	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	if (mem_read8(a0 + 0x33u) != 0u)
	{
		if (mem_read8(a0 + 0x33u) == 0x30u)
		{
			d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 3);
			if (RAM16(unk_060100_ADDRESS + d0) == 0u)
			{
				*p_d1 = (*p_d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
				t1 = mem_read16(a0 + 0xEu);
				d2 = (uint16_t)(t1 - 0x20u);
				if (t1 < 0x20u)
					d2 = 0u;
				func_030076(d0, d2, a0, p_d1, &ignored, &d5, &d6, p_d7);
			}
		}
	}
	else if (unk_060100(mem_read8(a0 + 2u) * 4u) == 0u)
	{
		mem_write8(a0 + 0x23u, mem_read8(a0 + 0x23u) + 1u);
		d0 = 0x42Bu;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	else
		mem_write8(a0 + 0x24u, 0xFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C630(uint32_t a0)
{
	uint32_t d0 = 0;
	uint32_t t1 = 0;

	d0 = 0x200u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d0 = 0u - d0;
	t1 = mem_read32(a0 + 0x12u) + d0;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	if (mem_read32(a0 + 0x12u) >= 0x16000u || mem_read32(a0 + 0x12u) < 0x9100u)
		mem_write8(a0 + 0x24u, 0xFFu);
}

void func_01C664(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01C688(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		func_01C6B0(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		func_01C724(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C688(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	mem_write8(a0 + 0x26u, 8u);
	*p_d7 = 0x60u;
	func_01D43A((uint16_t)*p_d7, a0);
	if (mem_read8(a0 + 0x1Cu) != 0u && ((mem_read8(a0 + 1u) & 1u) != 0u || mem_read16(a0 + 0x10u) == 0u))
		func_01C732(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C6B0(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t t1 = 0;

	func_01C786(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
		func_01C732(a0, &d1, &d5, &d6, p_d7);
	else
	{
		d0 = 0u;
		if (mem_read8(a0 + 0x26u) != 0u)
		{
			mem_write8(a0 + 0x26u, mem_read8(a0 + 0x26u) - 1u);
			d0 = 0x100u;
		}
		if (mem_read8(a0 + 0x25u) >= 2u)
			d0 = 0x280u;
		d1 = 3u;
		if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
		{
			d0 = (uint16_t)(0u - d0);
			d1 = (uint16_t)(d1 + 1u);
		}
		if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d1))) == 0u)
		{
			t1 = mem_read32(a0 + 0x12u) + (int16_t)d0;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			if (mem_read32(a0 + 0x12u) < 0x16000u)
			{
				if (mem_read32(a0 + 0x12u) < 0x9000u)
					mem_write32(a0 + 0x12u, 0x9000u);
			}
			else
				mem_write32(a0 + 0x12u, 0x16000u);
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C724(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	func_01C786(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
		func_01C732(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C732(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x25u) << 2);
	a6 = indexed_table_of_32_bit_values_01C764[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, mem_read8(a0 + 0x24u));
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		mem_write8(a0 + 0x24u, (uint8_t)d0);
		return;
	}
	d0 += 0x400u;
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C786(uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t t1 = 0;

	if ((mem_read8(a0 + 1u) & 1u) != 0u)
		return;
	t1 = mem_read16(a0 + 0x10u);
	mem_write16(a0 + 0x10u, t1 - 0x300u);
	if (t1 >= 0x300u)
	{
		d0 = mem_read8(a0 + 0x10u);
		if (d0 == mem_read8(a0 + 0x32u) || d0 < mem_read8(a0 + 0x32u))
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 1u);
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
		}
		return;
	}
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 1u);
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
}

void func_01C7BC(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01C7E0(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		func_01C7EA(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		func_01C84C(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C7E0(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		if (mem_read8(a0 + 0x25u) < 2u)
			func_01C87A(a0, p_d1, &d5, &d6, p_d7);
		else
		{
			d0 = 0x1800u;
			if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
				d0 = 0u - d0;
			t1 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			func_01C87A(a0, p_d1, &d5, &d6, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C7EA(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t t1 = 0;

	func_01C786(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
		func_01C87A(a0, &d1, &d5, &d6, p_d7);
	else
	{
		d0 = 0u;
		if (mem_read8(a0 + 0x25u) >= 2u)
			d0 = 0x280u;
		d1 = 3u;
		if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
		{
			d0 = (uint16_t)(0u - d0);
			d1 = (uint16_t)(d1 + 1u);
		}
		if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d1))) == 0u)
		{
			t1 = mem_read32(a0 + 0x12u) + (int16_t)d0;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			if (mem_read32(a0 + 0x12u) < 0x16000u)
			{
				if (mem_read32(a0 + 0x12u) < 0x9000u)
					mem_write32(a0 + 0x12u, 0x9000u);
			}
			else
				mem_write32(a0 + 0x12u, 0x16000u);
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C84C(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	func_01C786(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
		func_01C87A(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C87A(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, ignored = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x25u) << 2);
	a6 = indexed_table_of_32_bit_values_01C8CA[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, mem_read8(a0 + 0x24u));
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		mem_write8(a0 + 0x24u, (uint8_t)d0);
		if (mem_read8(a0 + 0x25u) < 2u)
		{
			d0_2 = func_001000_ADDRESS;
			if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
				d0_2 = 0u - d0_2;
			t2 = mem_read32(a0 + 0x12u) + d0_2;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
		}
	}
	else
	{
		d0 += 0x400u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void unreached_01C8E4(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01C908(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		func_01C986(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		func_01CA32(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01C908(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t d7_2 = 0;

	mem_write8(a0 + 0x26u, 8u);
	d0 = 3u;
	if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
		d0++;
	if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d0))) == 0u)
	{
		d7_2 = 0x50u;
		func_01D43A((uint16_t)d7_2, a0);
		if (mem_read8(a0 + 0x1Cu) != 0u && (mem_read16(a0 + 0x10u) == 0u || (mem_read8(a0 + 1u) & 1u) != 0u))
		{
			d0 = 0u;
			if (mem_read8(a0 + 8u) < 5u)
				d0++;
			if (mem_read8(a0 + 8u) == 0u)
				d0 = 3u;
			mem_write8(a0 + 0x25u, d0);
			func_01CA56(a0, p_d1, &d5, &d6, &d7_2);
		}
	}
	else
	{
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		func_0091A4((uint8_t)d7_2, 0u);
		d0 = 2u;
		if (mem_read8(a0 + 8u) == 0u)
			d0 = 4u;
		mem_write8(a0 + 0x25u, d0);
		func_01CA56(a0, p_d1, &d5, &d6, &d7_2);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_01C986(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;
	uint16_t t1 = 0;
	uint32_t t2 = 0;

	if (mem_read8(a0 + 0x25u) == 2u || mem_read8(a0 + 0x25u) == 4u)
	{
		if (mem_read8(a0 + 0x33u) == 0u)
		{
			if ((mem_read8(a0 + 1u) & 1u) != 0u)
				func_01CA50(a0, p_d1, &d5, &d6, p_d7);
			else
			{
				t1 = mem_read16(a0 + 0x10u);
				mem_write16(a0 + 0x10u, t1 - 0x100u);
				if (t1 >= 0x100u)
				{
					if (mem_read8(a0 + 0x10u) < mem_read8(a0 + 0x32u))
					{
						mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
						mem_write8(a0 + 0x11u, 0u);
						func_01CA50(a0, p_d1, &d5, &d6, p_d7);
					}
				}
				else
				{
					mem_write16(a0 + 0x10u, 0u);
					mem_write8(a0 + 0x32u, 0u);
					func_01CA50(a0, p_d1, &d5, &d6, p_d7);
				}
			}
		}
	}
	else
	{
		if (mem_read8(a0 + 0x26u) != 0u)
		{
			mem_write8(a0 + 0x26u, mem_read8(a0 + 0x26u) - 1u);
			d0 = 0x100u;
			if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
				d0 = 0u - d0;
			t2 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
			if (mem_read32(a0 + 0x12u) < 0x16000u)
			{
				if (mem_read32(a0 + 0x12u) < 0x9000u)
					mem_write32(a0 + 0x12u, 0x9000u);
			}
			else
				mem_write32(a0 + 0x12u, 0x16000u);
		}
		if (mem_read8(a0 + 0x33u) == 0u)
			func_01CA50(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CA32(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t t1 = 0;

	func_01C786(a0);
	if (mem_read8(a0 + 5u) == 0x11u)
	{
		t1 = mem_read8(a0 + 0x26u);
		mem_write8(a0 + 0x26u, t1 - 1u);
		if (t1 == 1u)
			func_01CA50(a0, p_d1, &d5, &d6, p_d7);
	}
	else if (mem_read8(a0 + 0x33u) == 0u)
		func_01CA56(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CA50(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	mem_write8(a0 + 0x26u, 0x60u);
	func_01CA56(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CA56(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x25u) << 2);
	a6 = indexed_table_of_32_bit_values_01CA82[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, mem_read8(a0 + 0x24u));
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		mem_write8(a0 + 0x24u, (uint8_t)d0);
		return;
	}
	d0 += 0x400u;
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CAAE(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01CAD2(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		func_01CB40(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		func_01CBEC(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CAD2(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t d0 = 0;

	mem_write8(a0 + 0x26u, 8u);
	d0 = 3u;
	if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
		d0++;
	if ((mem_read8(a0 + 1u) & shl32(1u, (int)(d0))) == 0u)
	{
		*p_d7 = 0x50u;
		func_01D43A((uint16_t)*p_d7, a0);
		if (mem_read8(a0 + 0x1Cu) != 0u && (mem_read16(a0 + 0x10u) == 0u || (mem_read8(a0 + 1u) & 1u) != 0u))
		{
			d0 = 0u;
			if (mem_read8(a0 + 8u) == 0u)
				d0 = 3u;
			mem_write8(a0 + 0x25u, d0);
			func_01CC12(a0, p_d1, &d5, &d6, p_d7);
		}
	}
	else if (mem_read8(a0 + 8u) != 0u)
	{
		mem_write8(a0 + 0x25u, 1u);
		func_01CC12(a0, p_d1, &d5, &d6, p_d7);
	}
	else
	{
		mem_write8(a0 + 0x25u, 4u);
		func_01CC12(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CB40(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;
	uint16_t t1 = 0;
	uint32_t t2 = 0;

	if (mem_read8(a0 + 0x25u) == 1u || mem_read8(a0 + 0x25u) == 4u)
	{
		if (mem_read8(a0 + 0x33u) == 0u)
		{
			if ((mem_read8(a0 + 1u) & 1u) != 0u)
				func_01CC0C(a0, p_d1, &d5, &d6, p_d7);
			else
			{
				t1 = mem_read16(a0 + 0x10u);
				mem_write16(a0 + 0x10u, t1 - 0x100u);
				if (t1 >= 0x100u)
				{
					if (mem_read8(a0 + 0x10u) < mem_read8(a0 + 0x32u))
					{
						mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
						mem_write8(a0 + 0x11u, 0u);
						func_01CC0C(a0, p_d1, &d5, &d6, p_d7);
					}
				}
				else
				{
					mem_write16(a0 + 0x10u, 0u);
					mem_write8(a0 + 0x32u, 0u);
					func_01CC0C(a0, p_d1, &d5, &d6, p_d7);
				}
			}
		}
	}
	else
	{
		if (mem_read8(a0 + 0x26u) != 0u)
		{
			mem_write8(a0 + 0x26u, mem_read8(a0 + 0x26u) - 1u);
			d0 = 0x100u;
			if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
				d0 = 0u - d0;
			t2 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
			if (mem_read32(a0 + 0x12u) < 0x16000u)
			{
				if (mem_read32(a0 + 0x12u) < 0x9000u)
					mem_write32(a0 + 0x12u, 0x9000u);
			}
			else
				mem_write32(a0 + 0x12u, 0x16000u);
		}
		if (mem_read8(a0 + 0x33u) == 0u)
			func_01CC0C(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CBEC(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t t1 = 0;

	func_01C786(a0);
	if (mem_read8(a0 + 5u) == 0x11u)
	{
		t1 = mem_read8(a0 + 0x26u);
		mem_write8(a0 + 0x26u, t1 - 1u);
		if (t1 == 1u)
			func_01CC0C(a0, p_d1, &d5, &d6, p_d7);
	}
	else if (mem_read8(a0 + 0x33u) == 0u)
		func_01CC12(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CC0C(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	mem_write8(a0 + 0x26u, 0x60u);
	func_01CC12(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CC12(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, ignored = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x25u) << 2);
	a6 = indexed_table_of_32_bit_values_01CC6E[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, mem_read8(a0 + 0x24u));
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		mem_write8(a0 + 0x24u, (uint8_t)d0);
		if (mem_read8(a0 + 0x25u) != 1u && mem_read8(a0 + 0x25u) != 4u)
		{
			d0_2 = func_001000_ADDRESS;
			if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
				d0_2 = 0u - d0_2;
			t2 = mem_read32(a0 + 0x12u) + d0_2;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
		}
	}
	else
	{
		d0 += 0x400u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CC96(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01CCBA(a0);
		break;
	case 1:
		func_01CCC6(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
		func_01CCFE(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 3:
		func_01CD28(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CCBA(uint32_t a0)
{
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	mem_write8(a0 + 0x26u, 0x60u);
}

void func_01CCC6(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if (mem_read16(a0 + 0x10u) != 0u)
	{
		mem_write8(a0 + 0x32u, 0u);
		t1 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t1 - 0x300u);
		if (t1 < 0x300u)
			mem_write16(a0 + 0x10u, 0u);
	}
	t2 = mem_read8(a0 + 0x26u);
	mem_write8(a0 + 0x26u, t2 - 1u);
	if (t2 != 1u)
		return;
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	d0 = 0x41Du;
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, &d7);
	d7_2 = (d7 & ~0xFFu) | 0x2Eu;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_01CCFE(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t ignored = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		if (mem_read8(a0 + 8u) == 0u)
		{
			mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
			mem_write8(a0 + 0x26u, 0x60u);
			d0 = 0x411u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
		}
		else
			mem_write8(a0 + 0x24u, 0xFFu);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CD28(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x26u);
	mem_write8(a0 + 0x26u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x24u, 0xFFu);
		return;
	}
}

void func_01CD30(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (mem_read8(a0 + 0x24u))
	{
	case 0:
		func_01CD50(a0);
		break;
	case 1:
		func_01CD5C(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
		func_01CDA0(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CD50(uint32_t a0)
{
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	mem_write8(a0 + 0x26u, 0x50u);
}

void func_01CD5C(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t ignored = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if (mem_read16(a0 + 0x10u) != 0u)
	{
		mem_write8(a0 + 0x32u, 0u);
		t1 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t1 - 0x200u);
		if (t1 < 0x200u)
			mem_write16(a0 + 0x10u, 0u);
	}
	t2 = mem_read8(a0 + 0x26u);
	mem_write8(a0 + 0x26u, t2 - 1u);
	if (t2 == 1u)
	{
		if (mem_read8(a0 + 8u) == 0u)
		{
			mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
			mem_write8(a0 + 0x26u, 0x60u);
			d0 = 0x411u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
		}
		else
			mem_write8(a0 + 0x24u, 0xFFu);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CDA0(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x26u);
	mem_write8(a0 + 0x26u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x24u, 0xFFu);
		return;
	}
}

void func_01CDA8(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x24u) << 2);
	switch (d0)
	{
	case 0:
		func_01CDC4(a0, p_d1, p_d7);
		break;
	case 4:
		func_01CE04(d0, a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CDC4(uint32_t a0, uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 8u) != 1u)
	{
		mem_write8(a0 + 8u, mem_read8(a0 + 8u) - 1u);
		*p_d7 = func_01D416(*p_d7, a0);
	}
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	a6 = mem_read32(a0 + 0x28u);
	*p_d1 = (uint32_t)mem_read16(a6 + 0xEu) << 8;
	mem_write32(a0 + 0x12u, (uint32_t)mem_read16(a6 + 0xCu) << 8);
	mem_write32(a0 + 0x16u, *p_d1);
	mem_write8(a0 + 0x1Du, 0x1Au);
}

void func_01CE04(uint32_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d2 = 0, d3 = 0;
	uint32_t d4 = 0, ignored = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x24u, 0xFFu);
		mem_write32(a0 + 0x16u, mem_read32(a0 + 0x16u) - 0x1000u);
	}
	else if (mem_read8(a0 + 0x1Du) != 0u)
	{
		t1 = mem_read8(a0 + 0x1Du);
		mem_write8(a0 + 0x1Du, t1 - 1u);
		if (t1 == 1u)
		{
			d0 &= ~0xFFu;
			d1 = (d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
			d2 = mem_read16(a0 + 0xEu);
			if (unk_061112 == 0u || (unk_061112 >= 3u && unk_061112 == 3u && unk_061104 >= 0x80u))
			{
				d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - 0x30u);
				t2 = d2;
				d2 = (uint16_t)(t2 - 0x38u);
				if (t2 < 0x38u)
					d2 = 0u;
				d3 = 0x64u;
				d4 = 0x20u;
				func_0301F0(d2, d3, &d0, &d1, &d4, &d5, &d6, p_d7, &ignored);
				func_03015C(ignored);
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01CE3E(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (mem_read8(a0 + 0x24u))
	{
	case 1:
		func_01CDA0(a0);
		break;
	case 0:
		func_01CE5A(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01CE5A(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	d2 = (uint16_t)(mem_read16(a0 + 0xEu) + mem_read8(a0 + 0x10u));
	func_01D25C(d2, a0, p_d1, p_d6, p_d7);
	if (unk_060121 != 8u || (int8_t)unk_0633C9 >= 0)
	{
		if (mem_read8(a0 + 0x27u) < 8u)
		{
			if (mem_read8(a0 + 8u) == 0u)
				func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
			else if ((unk_0600A4 & 0x7Fu) != 0u)
			{
				mem_write8(a0, mem_read8(a0) | 2u);
				if (mem_read8(a2) != 0u)
				{
					mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
					if (mem_read8(a0 + 0x27u) >= 8u)
					{
						if (mem_read8(a0 + 8u) == 0u)
							func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
						else
						{
							func_01D31E(a0, p_d1, p_d6, p_d7);
							mem_write8(mem_read32(a0 + 0x28u) + 5u, 3u);
							mem_write8(a0 + 9u, 3u);
							mem_write8(a0, mem_read8(a0) & ~2u);
							mem_write8(a0 + 0x27u, 0u);
							mem_write8(a0 + 0x2Eu, 2u);
							d0_2 = 6u;
							func_01B85C(d0_2, a0, p_d1, &d5, p_d6, p_d7);
						}
					}
				}
			}
			else
			{
				mem_write8(a0 + 8u, mem_read8(a0 + 8u) - 1u);
				*p_d7 = func_01D416(*p_d7, a0);
				if (mem_read8(a0 + 8u) == 0u)
					func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
				else
				{
					mem_write8(a0, mem_read8(a0) | 2u);
					if (mem_read8(a2) != 0u)
					{
						mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
						if (mem_read8(a0 + 0x27u) >= 8u)
						{
							if (mem_read8(a0 + 8u) == 0u)
								func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
							else
							{
								func_01D31E(a0, p_d1, p_d6, p_d7);
								mem_write8(mem_read32(a0 + 0x28u) + 5u, 3u);
								mem_write8(a0 + 9u, 3u);
								mem_write8(a0, mem_read8(a0) & ~2u);
								mem_write8(a0 + 0x27u, 0u);
								mem_write8(a0 + 0x2Eu, 2u);
								d0_2 = 6u;
								func_01B85C(d0_2, a0, p_d1, &d5, p_d6, p_d7);
							}
						}
					}
				}
			}
		}
		else
		{
			func_01D31E(a0, p_d1, p_d6, p_d7);
			mem_write8(a0 + 0x27u, 0u);
			d0 = 0u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
	}
	else if (mem_read8(a0 + 8u) == 0u)
		func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
	else
	{
		func_01D31E(a0, p_d1, p_d6, p_d7);
		mem_write8(mem_read32(a0 + 0x28u) + 5u, 3u);
		mem_write8(a0 + 9u, 3u);
		mem_write8(a0, mem_read8(a0) & ~2u);
		mem_write8(a0 + 0x27u, 0u);
		mem_write8(a0 + 0x2Eu, 2u);
		d0_2 = 6u;
		func_01B85C(d0_2, a0, p_d1, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01CF0E(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0;

	func_01D31E(a0, p_d1, p_d6, p_d7);
	a6 = mem_read32(a0 + 0x28u);
	if (mem_read8(a6 + 4u) != 4u)
		mem_write8(a6 + 5u, 3u);
	mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
	mem_write8(a0 + 0x26u, 0x60u);
	d0 = 0x411u;
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01CF3A(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (mem_read8(a0 + 0x24u))
	{
	case 1:
		func_01CDA0(a0);
		break;
	case 0:
		func_01CF56(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01CF56(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	d2 = (uint16_t)(mem_read16(a0 + 0xEu) + mem_read8(a0 + 0x10u));
	func_01D25C(d2, a0, p_d1, p_d6, p_d7);
	if (unk_060121 != 8u || (int8_t)unk_0633C9 >= 0)
	{
		if (mem_read8(a0 + 0x33u) != 0u)
		{
			if (mem_read8(a0 + 0x27u) < 6u)
			{
				if (mem_read8(a2) != 0u)
				{
					mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
					if (mem_read8(a0 + 0x27u) >= 6u)
					{
						if (mem_read8(a0 + 8u) == 0u)
							func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
						else
						{
							func_01D31E(a0, p_d1, p_d6, p_d7);
							mem_write8(mem_read32(a0 + 0x28u) + 5u, 3u);
							mem_write8(a0 + 0x27u, 0u);
							mem_write8(a0 + 9u, 3u);
							mem_write8(a0, mem_read8(a0) & ~2u);
							mem_write8(a0 + 0x2Eu, 2u);
							d0_2 = 6u;
							func_01B85C(d0_2, a0, p_d1, &d5, p_d6, p_d7);
						}
					}
				}
			}
			else
			{
				func_01D31E(a0, p_d1, p_d6, p_d7);
				if (mem_read8(a0 + 8u) == 0u)
				{
					mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
					mem_write8(a0 + 0x26u, 0x60u);
					d0 = 0x411u;
					func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				}
				else
				{
					mem_write8(a0 + 0x27u, 0u);
					d0 = 0u;
					func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				}
			}
		}
		else if (mem_read8(a0 + 8u) == 0u)
			func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
		else
		{
			if (mem_read8(a0 + 9u) == 0u)
				mem_write8(a0 + 9u, 3u);
			mem_write8(a0 + 0x23u, 0xEu);
			mem_write8(a0 + 0x24u, 0u);
			d0 = 0x422u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
	}
	else if (mem_read8(a0 + 8u) == 0u)
		func_01CF0E(a0, p_d1, &d5, p_d6, p_d7);
	else
	{
		func_01D31E(a0, p_d1, p_d6, p_d7);
		mem_write8(mem_read32(a0 + 0x28u) + 5u, 3u);
		mem_write8(a0 + 0x27u, 0u);
		mem_write8(a0 + 9u, 3u);
		mem_write8(a0, mem_read8(a0) & ~2u);
		mem_write8(a0 + 0x2Eu, 2u);
		d0_2 = 6u;
		func_01B85C(d0_2, a0, p_d1, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01D014(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (mem_read8(a0 + 0x24u))
	{
	case 1:
		func_01CDA0(a0);
		break;
	case 0:
		func_01D030(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01D030(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	d2 = (uint16_t)(mem_read16(a0 + 0xEu) + mem_read8(a0 + 0x10u));
	func_01D25C(d2, a0, p_d1, p_d6, p_d7);
	if (unk_060121 != 8u || (int8_t)unk_0633C9 >= 0)
	{
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
		mem_write8(a0 + 0x11u, 0u);
		if (mem_read8(a0 + 0x27u) >= 8u)
		{
			func_01D31E(a0, p_d1, p_d6, p_d7);
			d0 = 0u;
			mem_write8(a0 + 0x27u, 0u);
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
		else if (mem_read8(a0 + 8u) == 0u)
		{
			mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
			func_01D31E(a0, p_d1, p_d6, p_d7);
			mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
			mem_write8(a0 + 0x26u, 0x60u);
			d0 = 0x411u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
		else if ((unk_0600A4 & 0x3Fu) != 0u)
		{
			if (mem_read8(a2) != 0u)
			{
				mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
				if (mem_read8(a0 + 0x27u) >= 8u)
				{
					if (mem_read8(a0 + 8u) == 0u)
					{
						mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
						func_01D31E(a0, p_d1, p_d6, p_d7);
						mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
						mem_write8(a0 + 0x26u, 0x60u);
						d0 = 0x411u;
						func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
					else
					{
						mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
						func_01D31E(a0, p_d1, p_d6, p_d7);
						d0 = 0u;
						mem_write8(a0 + 0x27u, 0u);
						func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
				}
			}
		}
		else
		{
			mem_write8(a0 + 8u, mem_read8(a0 + 8u) - 1u);
			*p_d7 = func_01D416(*p_d7, a0);
			if (mem_read8(a0 + 8u) == 0u)
			{
				mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
				func_01D31E(a0, p_d1, p_d6, p_d7);
				mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
				mem_write8(a0 + 0x26u, 0x60u);
				d0 = 0x411u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			}
			else if (mem_read8(a2) != 0u)
			{
				mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
				if (mem_read8(a0 + 0x27u) >= 8u)
				{
					if (mem_read8(a0 + 8u) == 0u)
					{
						mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
						func_01D31E(a0, p_d1, p_d6, p_d7);
						mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
						mem_write8(a0 + 0x26u, 0x60u);
						d0 = 0x411u;
						func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
					else
					{
						mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
						func_01D31E(a0, p_d1, p_d6, p_d7);
						d0 = 0u;
						mem_write8(a0 + 0x27u, 0u);
						func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
				}
			}
		}
	}
	else if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
		func_01D31E(a0, p_d1, p_d6, p_d7);
		mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
		mem_write8(a0 + 0x26u, 0x60u);
		d0 = 0x411u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	}
	else
	{
		mem_write8(mem_read32(a0 + 0x28u) + 4u, 2u);
		func_01D31E(a0, p_d1, p_d6, p_d7);
		d0 = 0u;
		mem_write8(a0 + 0x27u, 0u);
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01D0EC(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (mem_read8(a0 + 0x24u))
	{
	case 1:
		func_01CDA0(a0);
		break;
	case 0:
		func_01D108(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01D108(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	d2 = (uint16_t)(mem_read16(a0 + 0xEu) + mem_read8(a0 + 0x10u));
	func_01D25C(d2, a0, p_d1, p_d6, p_d7);
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	if (mem_read8(a0 + 0x27u) < 0x10u)
	{
		if (mem_read8(a0 + 8u) == 0u)
		{
			func_01D31E(a0, p_d1, p_d6, p_d7);
			a6 = mem_read32(a0 + 0x28u);
			mem_write8(a6, mem_read8(a6) | 2u);
			mem_write16(a6 + 4u, 0x200u);
			mem_write8(a6 + 0x10u, mem_read8(a6 + 0x32u));
			mem_write8(a6 + 0x22u, 0u);
			mem_write8(a6, mem_read8(a6) | 0x80u);
			mem_write8(a0 + 0x27u, 0u);
			mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
			mem_write8(a0 + 0x26u, 0x60u);
			d0 = 0x411u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if ((unk_0600A4 & 0x3Fu) == 0u)
		{
			mem_write8(a0 + 8u, mem_read8(a0 + 8u) - 1u);
			*p_d7 = func_01D416(*p_d7, a0);
			if (mem_read8(a0 + 8u) == 0u)
			{
				func_01D31E(a0, p_d1, p_d6, p_d7);
				a6 = mem_read32(a0 + 0x28u);
				mem_write8(a6, mem_read8(a6) | 2u);
				mem_write16(a6 + 4u, 0x200u);
				mem_write8(a6 + 0x10u, mem_read8(a6 + 0x32u));
				mem_write8(a6 + 0x22u, 0u);
				mem_write8(a6, mem_read8(a6) | 0x80u);
				mem_write8(a0 + 0x27u, 0u);
				mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
				mem_write8(a0 + 0x26u, 0x60u);
				d0 = 0x411u;
				func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if (mem_read8(a2) == 0u)
		{
			t1 = mem_read8(a0 + 0x26u);
			mem_write8(a0 + 0x26u, t1 - 1u);
			if (t1 != 1u || mem_read8(a0 + 5u) == 0x24u)
			{
				return;
			}
			d0 = 0x424u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		mem_write8(a0 + 0x26u, 0x10u);
		mem_write8(a0 + 0x27u, mem_read8(a0 + 0x27u) + 1u);
		if (mem_read8(a0 + 0x27u) < 8u)
		{
			if (mem_read8(a0 + 5u) == 0x27u)
			{
				return;
			}
			d0 = 0x427u;
			func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
	}
	func_01D31E(a0, p_d1, p_d6, p_d7);
	*p_d7 = (*p_d7 & ~0xFFFFu) | mem_read8(a0 + 2u);
	*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D200[(uint16_t)*p_d7];
	*p_d7 = LINKED(*p_d7, (uint16_t)(*p_d7 + 0x400u));
	func_004164((uint16_t)*p_d7);
	if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write8(a0 + 0x27u, 0u);
		mem_write8(a0 + 0x24u, mem_read8(a0 + 0x24u) + 1u);
		mem_write8(a0 + 0x26u, 0x60u);
		d0 = 0x411u;
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	a6 = mem_read32(a0 + 0x28u);
	if (mem_read8(a6 + 4u) == 5u)
	{
		d0 = 0u;
		mem_write8(a0 + 0x27u, 0u);
		func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	mem_write16(a6 + 4u, 0x500u);
	mem_write8(a6 + 0x22u, 0u);
	mem_write16(a6 + 0x28u, 0x94u);
	d0_2 = 0u;
	if ((int8_t)mem_read8(a0 + 0x22u) >= 0)
		d0_2 = 0x80u;
	mem_write8(a6 + 0x30u, d0_2);
	d0 = 0u;
	mem_write8(a0 + 0x27u, 0u);
	func_01B8C2(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

uint32_t func_01D23C(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 0x50u;
	func_01D43A((uint16_t)d7, a0);
	if (mem_read8(a0 + 0x1Cu) == 0u || (mem_read8(a0 + 1u) & 1u) == 0u)
		return d7;
	mem_write8(a0 + 0x24u, 0xFFu);
	return d7;
}

void func_01D25C(uint16_t d2, uint32_t a0, uint32_t *p_d1, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a5 = 0, a6 = 0, d6_2 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	if (unk_0600A3 == 0u || unk_06014C(mem_read8(a0 + 2u)) != 0u)
		return;
	a6 = table_loaded_by_lea_01D35C_ADDRESS;
	if (mem_read8(a0 + 0x49u) != 0u)
		a6 = 0x1D3ACu;
	mem_write8(a0 + 0x48u, mem_read8(a0 + 0x48u) - 1u);
	if ((mem_read8(a0 + 0x48u) & 0x7Fu) == 0u)
	{
		mem_write8(a0 + 0x49u, mem_read8(a0 + 0x49u) ^ 0xFFu);
		mem_write8(a0 + 0x48u, 0xC0u);
		return;
	}
	if (mem_read8(a0 + 0x48u) == 0x3Fu)
	{
		d1 = ((d1 - 0x20u) & 0x1F8u) >> 2;
		if (d2 < 0x70u)
			d2 = (uint16_t)(((0u - d2 - 0x50u) & 0xF8u) << 4);
		else
			d2 = 0x400u;
		d1 = (uint16_t)(d1 + d2);
		mem_write16(a0 + 0x4Eu, d1);
		d1 += 0x100000u;
		a5 = d1;
	}
	else
	{
		if (mem_read8(a0 + 0x48u) != 0xBFu)
			return;
		a5 = 0x100000u + (int16_t)mem_read16(a0 + 0x4Eu);
	}
	d7_2 = 3u;
	do
	{
		d6_2 = 9u;
		do
		{
			mem_write8(a5, DATA8(a6));
			a6++;
			a5++;
			mem_write8(a5, DATA8(a6));
			t1 = d6_2 - 1u;
			d6_2 = t1;
			a6++;
			a5++;
		} while (t1 != 0xFFFFu);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a5 += 0x6Cu;
	} while (t2 != 0xFFFFu);
	*p_d1 = d1;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

void func_01D31E(uint32_t a0, uint32_t *p_d1, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6_2 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	if (unk_0600A3 == 0u)
		return;
	a6 = 0x100000u + (int16_t)mem_read16(a0 + 0x4Eu);
	d0 = 0u;
	*p_d1 = 0x10u;
	d7_2 = 3u;
	do
	{
		d6_2 = 9u;
		do
		{
			mem_write8(a6, d0);
			a6++;
			mem_write8(a6, *p_d1);
			t1 = d6_2 - 1u;
			d6_2 = t1;
			a6++;
		} while (t1 != 0xFFFFu);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a6 += 0x6Cu;
	} while (t2 != 0xFFFFu);
	unk_06014C(mem_read8(a0 + 2u)) = 0xFFu;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

uint32_t func_01D416(uint32_t d7, uint32_t a0)
{
	unk_060106((uint16_t)((uint32_t)mem_read8(a0 + 2u) << 3)) = mem_read8(a0 + 8u);
	d7 = (d7 & ~0xFFFFu) | 0xB20u | shl32(1u, (int)(mem_read8(a0 + 2u) & 0x1Fu));
	func_004164((uint16_t)d7);
	return d7;
}

void func_01D43A(uint16_t d7, uint32_t a0)
{
	uint16_t d0 = 0;
	uint16_t t3 = 0, t4 = 0;
	uint32_t t1 = 0, t2 = 0;

	if (mem_read8(a0 + 0x1Cu) != 0u && (mem_read8(a0 + 1u) & 1u) != 0u)
	{
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 1u);
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
		mem_write8(a0 + 0x11u, 0u);
		return;
	}
	if ((mem_read8(a0 + 0x22u) & 1u) != 0u)
	{
		if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
		{
			t1 = mem_read32(a0 + 0x12u) - mem_read16(a0 + 0x20u);
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			if (mem_read32(a0 + 0x12u) < 0x9000u)
				mem_write32(a0 + 0x12u, 0x9000u);
			mem_write16(a0 + 0x20u, mem_read16(a0 + 0x20u) - d7);
			if (mem_read16(a0 + 0x20u) < 0x200u)
				mem_write16(a0 + 0x20u, 0x200u);
		}
	}
	else if ((mem_read8(a0 + 1u) & 8u) == 0u)
	{
		t2 = mem_read32(a0 + 0x12u) + mem_read16(a0 + 0x20u);
		mem_write16(a0 + 0x14u, t2);
		mem_write16(a0 + 0x12u, t2 >> 16);
		if (mem_read32(a0 + 0x12u) < 0x16000u)
		{
			mem_write16(a0 + 0x20u, mem_read16(a0 + 0x20u) - d7);
			if (mem_read16(a0 + 0x20u) < 0x200u)
				mem_write16(a0 + 0x20u, 0x200u);
		}
		else
		{
			mem_write32(a0 + 0x12u, 0x16000u);
			mem_write16(a0 + 0x20u, mem_read16(a0 + 0x20u) - d7);
			if (mem_read16(a0 + 0x20u) < 0x200u)
				mem_write16(a0 + 0x20u, 0x200u);
		}
	}
	if (mem_read8(a0 + 0x1Cu) != 0u)
	{
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + d7);
		d0 = mem_read16(a0 + 0x1Au);
		t3 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t3 - d0);
		if (t3 < d0 || mem_read8(a0 + 0x10u) < mem_read8(a0 + 0x32u))
		{
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 1u);
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
			return;
		}
		return;
	}
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
	t4 = mem_read16(a0 + 0x1Au);
	mem_write16(a0 + 0x1Au, t4 - d7);
	if (d7 <= t4)
		return;
	mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
}

void func_01D512(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	unk_0633CA--;
	if (mem_read8(a0 + 0x33u) == 0u)
		func_01BEA4(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
	else
		mem_write8(a1, mem_read8(a1) & 0xCu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01D692(uint8_t d0, uint32_t a0)
{
	if (mem_read8(a0 + 0x10u) != mem_read8(a0 + 0x32u))
		d0 |= 0x80u;
	else if (unk_0633D3 == 1u)
		d0 |= 1u;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
}

void func_01D6BC(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	if (unk_0633D3 != 1u)
	{
		if ((mem_read8(a0 + 0x22u) & 1u) == 0u)
		{
			func_01D9A2(d0, a0, a6);
			return;
		}
		func_01DAD6(d0, a0, a6);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
		func_01D742(d0, a0);
		return;
	}
	if (mem_read8(a0 + 0x32u) <= d1)
	{
		d0 |= 0x80u;
		func_01D742(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01D742(d0, a0);
}

void func_01D708(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	if (unk_0633D3 != 1u)
	{
		func_01D7C0(d0, a0, a6);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
		func_01D742(d0, a0);
		return;
	}
	if (mem_read8(a0 + 0x32u) <= d1)
	{
		d0 |= 0x80u;
		func_01D742(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01D742(d0, a0);
}

void func_01D742(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d2 = unk_0633D9;
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	t2 = unk_0633D5;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && d0 == 0xFBu)))
		d0 |= 8u;
	d2 = unk_0633DB;
	t3 = unk_0633D6;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || d2 != 0xFAu)))
	{
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 0x10u;
	func_01DC5E(d0, a0);
}

void func_01D7C0(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;
	uint32_t t1 = 0;

	if (mem_read32(a0 + 0x16u) < 0x6800u)
	{
		t1 = mem_read32(a0 + 0x16u) + 0x400u;
		mem_write16(a0 + 0x18u, t1);
		mem_write16(a0 + 0x16u, t1 >> 16);
		mem_write16(a0 + 0xEu, mem_read32(a0 + 0x16u) >> 8);
	}
	d2 = 0u;
	d3 = 0x14u;
	do
	{
		mem_write8(a0 + 0x32u, mem_read8(a0 + 0x32u) + 8u);
		a6 -= 0x40u;
		if (a6 < 0x61800u)
			a6 += 0x800u;
		d2++;
		if (d3 <= d2)
		{
			mem_write32(a0 + 0x12u, 0xC000u);
			mem_write32(a0 + 0x16u, 0x2000u);
			d0_2 = 0x7Bu;
			mem_write8(a0 + 0x32u, 0u);
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0_2);
			return;
		}
	} while ((int8_t)mem_read8(a6) < 0);
	mem_write8(a0 + 0x19u, 0xFFu);
	d0 |= 0x82u;
	if (mem_read8(a0 + 0x32u) <= mem_read8(a0 + 0x10u))
	{
		func_01DC5E(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01DC5E(d0, a0);
}

void func_01D84C(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0;
	uint32_t t1 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	if ((int8_t)unk_0633D4 < 0)
		d0 |= 2u;
	if (unk_0633D3 != 1u)
	{
		func_01D8A8(d0, a0, a6);
		t1 = mem_read32(a0 + 0x16u) - 0x400u;
		mem_write16(a0 + 0x18u, t1);
		mem_write16(a0 + 0x16u, t1 >> 16);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
		func_01D742(d0, a0);
		return;
	}
	if (mem_read8(a0 + 0x32u) <= d1)
	{
		d0 |= 0x80u;
		func_01D742(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01D742(d0, a0);
}

void func_01D8A8(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;
	uint8_t t1 = 0;

	d2 = 0u;
	d3 = 0x14u;
	for (;;)
	{
		t1 = mem_read8(a0 + 0x32u);
		mem_write8(a0 + 0x32u, t1 - 8u);
		if (t1 < 8u)
			mem_write8(a0 + 0x32u, 0u);
		a6 += 0x40u;
		if (a6 >= unk_062000_ADDRESS)
			a6 -= 0x800u;
		d2++;
		if (d3 <= d2)
			break;
		if ((int8_t)mem_read8(a6) >= 0)
		{
			mem_write8(a0 + 0x19u, 0u);
			d0 |= 0x82u;
			func_01DC5E(d0, a0);
			return;
		}
	}
	mem_write32(a0 + 0x12u, 0xC000u);
	mem_write32(a0 + 0x16u, 0x2000u);
	d0_2 = 0x7Bu;
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0_2);
}

void func_01D8E6(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	d2 = unk_0633D9;
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (unk_0633D3 != 1u)
	{
		func_01D9A2(d0, a0, a6);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
	}
	else
	{
		if (d1 < mem_read8(a0 + 0x32u))
		{
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
			d0 |= 1u;
			t2 = unk_0633D5;
			d1 = t2;
			if ((int8_t)t2 >= 0)
			{
				t3 = unk_0633D6;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
				{
					func_01DC5E(d0, a0);
					return;
				}
				d0 |= 0x10u;
				func_01DC5E(d0, a0);
				return;
			}
			if (d1 == 0xFEu)
			{
				d0 |= 8u;
				t3 = unk_0633D6;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
				{
					func_01DC5E(d0, a0);
					return;
				}
				d0 |= 0x10u;
				func_01DC5E(d0, a0);
				return;
			}
			if (d1 != 0xFBu)
			{
				t3 = unk_0633D6;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
				{
					func_01DC5E(d0, a0);
					return;
				}
				d0 |= 0x10u;
				func_01DC5E(d0, a0);
				return;
			}
			t4 = unk_0633DA;
			d1 = t4;
			if ((int8_t)t4 >= 0 || d1 != 0xFBu)
			{
				t3 = unk_0633D6;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
				{
					func_01DC5E(d0, a0);
					return;
				}
				d0 |= 0x10u;
				func_01DC5E(d0, a0);
				return;
			}
			d0 |= 8u;
			t3 = unk_0633D6;
			d1 = t3;
			if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
			{
				func_01DC5E(d0, a0);
				return;
			}
			d0 |= 0x10u;
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x80u;
	}
	t2 = unk_0633D5;
	d1 = t2;
	if ((int8_t)t2 >= 0)
	{
		t3 = unk_0633D6;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
		{
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x10u;
		func_01DC5E(d0, a0);
		return;
	}
	if (d1 == 0xFEu)
	{
		d0 |= 8u;
		t3 = unk_0633D6;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
		{
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x10u;
		func_01DC5E(d0, a0);
		return;
	}
	if (d1 != 0xFBu)
	{
		t3 = unk_0633D6;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
		{
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x10u;
		func_01DC5E(d0, a0);
		return;
	}
	t4 = unk_0633DA;
	d1 = t4;
	if ((int8_t)t4 >= 0 || d1 != 0xFBu)
	{
		t3 = unk_0633D6;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
		{
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x10u;
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 8u;
	t3 = unk_0633D6;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
	{
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 0x10u;
	func_01DC5E(d0, a0);
}

void func_01D9A2(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d1_2 = 0;
	uint32_t d1 = 0;
	uint32_t t1 = 0, t2 = 0;

	if (mem_read8(a0 + 0x10u) != mem_read8(a0 + 0x32u))
	{
		d1_2 = unk_0633D3;
		if (d1_2 == 0xFBu || d1_2 == 0xFCu)
		{
			func_01D7C0(d0, a0, a6);
			return;
		}
		func_01D8A8(d0, a0, a6);
		t1 = mem_read32(a0 + 0x12u) + 0x400u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
		return;
	}
	if (unk_0633D3 == 0xFAu || unk_0633D3 == 0xFCu || unk_0633D3 == 0xFFu)
	{
		func_01D8A8(d0, a0, a6);
		t1 = mem_read32(a0 + 0x12u) + 0x400u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
		return;
	}
	d1 = func_001000_ADDRESS;
	if (mem_read8(a0 + 4u) == 4u && mem_read8(a0 + 0x25u) >= 2u)
		d1 = 0x1800u;
	t2 = mem_read32(a0 + 0x12u) - d1;
	mem_write16(a0 + 0x14u, t2);
	mem_write16(a0 + 0x12u, t2 >> 16);
	d0 |= 0x7Bu;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
}

void func_01DA20(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	d2 = unk_0633D9;
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (unk_0633D3 != 1u)
	{
		func_01DAD6(d0, a0, a6);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
	}
	else
	{
		if (d1 < mem_read8(a0 + 0x32u))
		{
			mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
			mem_write8(a0 + 0x11u, 0u);
			d0 |= 1u;
			t2 = unk_0633D6;
			d1 = t2;
			if ((int8_t)t2 < 0 && (d1 == 0xFDu || (d1 == 0xFAu && unk_0633DB == 0xFAu)))
				d0 |= 0x10u;
			t3 = unk_0633D5;
			d1 = t3;
			if ((int8_t)t3 >= 0 || (d1 != 0xFEu && (d1 != 0xFBu || unk_0633DA != 0xFBu)))
			{
				func_01DC5E(d0, a0);
				return;
			}
			d0 |= 8u;
			func_01DC5E(d0, a0);
			return;
		}
		d0 |= 0x80u;
	}
	t2 = unk_0633D6;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 == 0xFDu || (d1 == 0xFAu && unk_0633DB == 0xFAu)))
		d0 |= 0x10u;
	t3 = unk_0633D5;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFEu && (d1 != 0xFBu || unk_0633DA != 0xFBu)))
	{
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 8u;
	func_01DC5E(d0, a0);
}

void func_01DAD6(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d1_2 = 0;
	uint32_t d1 = 0;
	uint32_t t1 = 0, t2 = 0;

	if (mem_read8(a0 + 0x10u) != mem_read8(a0 + 0x32u))
	{
		d1_2 = unk_0633D3;
		if (d1_2 == 0xFAu || d1_2 == 0xFCu)
		{
			func_01D7C0(d0, a0, a6);
			return;
		}
		func_01D8A8(d0, a0, a6);
		t1 = mem_read32(a0 + 0x12u) - 0x400u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
		return;
	}
	if (unk_0633D3 == 0xFBu || unk_0633D3 == 0xFCu || unk_0633D3 == 0xFFu)
	{
		func_01D8A8(d0, a0, a6);
		t1 = mem_read32(a0 + 0x12u) - 0x400u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
		return;
	}
	d1 = func_001000_ADDRESS;
	if (mem_read8(a0 + 4u) == 4u && mem_read8(a0 + 0x25u) >= 2u)
		d1 = 0x1800u;
	t2 = mem_read32(a0 + 0x12u) + d1;
	mem_write16(a0 + 0x14u, t2);
	mem_write16(a0 + 0x12u, t2 >> 16);
	d0 |= 0x7Bu;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
}

void func_01DB54(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	if (unk_0633D3 != 1u)
	{
		func_01DAD6(d0, a0, a6);
		return;
	}
	func_01DB84(d0, a0);
}

void func_01DB6E(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	d0 = 0u;
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	if (unk_0633D3 != 1u)
	{
		func_01D9A2(d0, a0, a6);
		return;
	}
	func_01DB84(d0, a0);
}

void func_01DB84(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
	}
	else if (mem_read8(a0 + 0x32u) <= d1)
		d0 |= 0x80u;
	else
	{
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
	}
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0)
	{
		if (d1 >= 0xFDu)
			d0 |= 2u;
		else
		{
			t2 = unk_0633D9;
			d2 = t2;
			if ((int8_t)t2 < 0 && d2 < 0xFDu)
			{
				if (d1 != 0xFCu)
				{
					if (d1 != 0xFBu)
					{
						if (d1 == 0xFAu && d2 == 0xFAu)
						{
							d0 |= 2u;
							t3 = unk_0633D5;
							d1 = t3;
							if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && unk_0633DA == 0xFBu)))
								d0 |= 8u;
							t4 = unk_0633D6;
							d1 = t4;
							if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
							{
								func_01DC5E(d0, a0);
								return;
							}
							d0 |= 0x10u;
							func_01DC5E(d0, a0);
							return;
						}
					}
					else if (d2 == 0xFBu)
					{
						d0 |= 2u;
						t3 = unk_0633D5;
						d1 = t3;
						if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && unk_0633DA == 0xFBu)))
							d0 |= 8u;
						t4 = unk_0633D6;
						d1 = t4;
						if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
						{
							func_01DC5E(d0, a0);
							return;
						}
						d0 |= 0x10u;
						func_01DC5E(d0, a0);
						return;
					}
				}
				else if (d2 == 0xFCu)
				{
					d0 |= 2u;
					t3 = unk_0633D5;
					d1 = t3;
					if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && unk_0633DA == 0xFBu)))
						d0 |= 8u;
					t4 = unk_0633D6;
					d1 = t4;
					if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
					{
						func_01DC5E(d0, a0);
						return;
					}
					d0 |= 0x10u;
					func_01DC5E(d0, a0);
					return;
				}
			}
		}
	}
	t3 = unk_0633D5;
	d1 = t3;
	if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && unk_0633DA == 0xFBu)))
		d0 |= 8u;
	t4 = unk_0633D6;
	d1 = t4;
	if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
	{
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 0x10u;
	func_01DC5E(d0, a0);
}

void func_01DC5E(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0;

	d2 = unk_0633DC;
	t1 = unk_0633D7;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 0x20u;
	d2 = unk_0633DD;
	t2 = unk_0633D8;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 0x40u;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
}

void func_01DCA6(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0, t4 = 0;
	uint32_t t2 = 0, t3 = 0;

	d0 = 0u;
	if (unk_0633D3 == 0u)
	{
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
		return;
	}
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	d2 = unk_0633D9;
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (unk_0633D3 != 1u)
	{
		if (unk_0633D3 == 0xFBu)
		{
			func_01D7C0(d0, a0, a6);
			return;
		}
		func_01D8A8(d0, a0, a6);
		t2 = mem_read32(a0 + 0x12u) + 0x400u;
		mem_write16(a0 + 0x14u, t2);
		mem_write16(a0 + 0x12u, t2 >> 16);
		t3 = mem_read32(a0 + 0x16u) - 0x400u;
		mem_write16(a0 + 0x18u, t3);
		mem_write16(a0 + 0x16u, t3 >> 16);
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x400u);
		t4 = mem_read8(a0 + 0x32u);
		mem_write8(a0 + 0x32u, t4 - 4u);
		if (t4 < 4u)
			mem_write8(a0 + 0x32u, 0u);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
		func_01DD0E(d0, a0);
		return;
	}
	if (mem_read8(a0 + 0x32u) <= d1)
	{
		d0 |= 0x80u;
		func_01DD0E(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01DD0E(d0, a0);
}

void func_01DD0E(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = unk_0633D5;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && unk_0633DA == 0xFBu)))
		d0 |= 8u;
	t2 = unk_0633D6;
	d1 = t2;
	if ((int8_t)t2 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || unk_0633DB != 0xFAu)))
	{
		func_01DC5E(d0, a0);
		return;
	}
	d0 |= 0x10u;
	func_01DC5E(d0, a0);
}

void func_01DD9C(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0, t4 = 0;
	uint32_t t2 = 0, t3 = 0;

	d0 = 0u;
	if (unk_0633D3 == 0u)
	{
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d0);
		return;
	}
	if ((mem_read8(a0) & 0x10u) != 0u)
	{
		func_01D692(d0, a0);
		return;
	}
	d2 = unk_0633D9;
	t1 = unk_0633D4;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (unk_0633D3 != 1u)
	{
		if (unk_0633D3 == 0xFAu)
		{
			func_01D7C0(d0, a0, a6);
			return;
		}
		func_01D8A8(d0, a0, a6);
		t2 = mem_read32(a0 + 0x12u) - 0x400u;
		mem_write16(a0 + 0x14u, t2);
		mem_write16(a0 + 0x12u, t2 >> 16);
		t3 = mem_read32(a0 + 0x16u) - 0x400u;
		mem_write16(a0 + 0x18u, t3);
		mem_write16(a0 + 0x16u, t3 >> 16);
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x400u);
		t4 = mem_read8(a0 + 0x32u);
		mem_write8(a0 + 0x32u, t4 - 4u);
		if (t4 < 4u)
			mem_write8(a0 + 0x32u, 0u);
		return;
	}
	d1 = mem_read8(a0 + 0x10u);
	if (d1 == mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x11u, 0u);
		d0 |= 1u;
		func_01DD0E(d0, a0);
		return;
	}
	if (mem_read8(a0 + 0x32u) <= d1)
	{
		d0 |= 0x80u;
		func_01DD0E(d0, a0);
		return;
	}
	mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
	mem_write8(a0 + 0x11u, 0u);
	d0 |= 1u;
	func_01DD0E(d0, a0);
}

void func_01DE3E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_a5, uint32_t *p_a6)
{
	uint16_t d7 = 0;
	uint32_t d5 = 0, d6 = 0;

	d7 = ((mem_read16(a0 + 0xCu) - 0x60u + ((unk_063300 >> 8) & 0x1FFu)) & 0x1FFu) >> 3;
	d6 = mem_read8(a0 + 0xFu);
	func_01DE84(d7, a0, &d5, &d6, p_a5, p_a6);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_01DE62(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d5 = 0, d6 = 0, d7 = 0, ignored = 0;

	d7 = mem_read32(a0 + 0x12u) >> 8;
	d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 - 0x60u);
	d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 + ((unk_063300 >> 8) & 0x1FFu));
	d7 = d7 & ~0xFE00u;
	d7 = (d7 & ~0xFFFFu) | ((uint16_t)d7 >> 3);
	d6 = mem_read8(a0 + 0x18u);
	func_01DE84((uint16_t)d7, a0, &d5, &d6, &ignored, p_a6);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void func_01DE84(uint16_t d7, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_a5, uint32_t *p_a6)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint16_t d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;

	d6 = (uint8_t)(d6 + mem_read8(a0 + 0x32u));
	d5 = (uint16_t)(((uint8_t)(0u - (d6 + (mem_read8(a0 + 0x10u) - mem_read8(a0 + 0x32u))) - (uint8_t)(unk_063304 >> 8u)) & 0xF8u) << 3);
	d6 = (uint16_t)((((uint8_t)(0u - d6 - (uint8_t)(unk_063304 >> 8u)) & 0xF8u) << 3) + d7);
	d5 += d7;
	a6 = 0x61800u + d6;
	a5 = 0x61800u + d5;
	unk_0633D3 = mem_read8(a6);
	unk_0633F4 = mem_read8(a5);
	if (a6 < 0x61840u)
		unk_0633D4 = mem_read8(a6 + 0x7C0u);
	else
		unk_0633D4 = mem_read8(a6 - 0x40u);
	if ((a6 & 0x3Fu) == 0x3Fu)
		unk_0633D5 = mem_read8(a6 - 0x3Fu);
	else
		unk_0633D5 = mem_read8(a6 + 1u);
	if ((a6 & 0x3Fu) == 0u)
		unk_0633D6 = mem_read8(a6 + 0x3Fu);
	else
		unk_0633D6 = mem_read8(a6 - 1u);
	a4 = a6;
	if (a6 < 0x61840u)
		a4 += 0x800u;
	if ((a6 & 0x3Fu) == 0x3Fu)
		a4 -= 0x40u;
	unk_0633D7 = mem_read8(a4 - 0x3Fu);
	a4 = a6;
	if (a6 < 0x61840u)
		a4 += 0x800u;
	if ((a6 & 0x3Fu) == 0u)
		a4 += 0x40u;
	unk_0633D8 = mem_read8(a4 - 0x41u);
	a4 = a6;
	if (a6 >= 0x61FC0u)
		a4 -= 0x800u;
	unk_061118 = mem_read8(a4 + 0x40u);
	if (a5 < 0x61840u)
		unk_0633D9 = mem_read8(a5 + 0x7C0u);
	else
		unk_0633D9 = mem_read8(a5 - 0x40u);
	if ((a5 & 0x3Fu) == 0x3Fu)
		unk_0633DA = mem_read8(a5 - 0x3Fu);
	else
		unk_0633DA = mem_read8(a5 + 1u);
	if ((a5 & 0x3Fu) == 0u)
		unk_0633DB = mem_read8(a5 + 0x3Fu);
	else
		unk_0633DB = mem_read8(a5 - 1u);
	a4 = a5;
	if (a5 < 0x61840u)
		a4 += 0x800u;
	if ((a5 & 0x3Fu) == 0x3Fu)
		a4 -= 0x40u;
	unk_0633DC = mem_read8(a4 - 0x3Fu);
	a4 = a5;
	if (a5 < 0x61840u)
		a4 += 0x800u;
	if ((a5 & 0x3Fu) == 0u)
		a4 += 0x40u;
	unk_0633DD = mem_read8(a4 - 0x41u);
	if ((int8_t)mem_read8(a0 + 0x16u) < 0)
		unk_0633D3 = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_a5 = a5;
	*p_a6 = a6;
}
