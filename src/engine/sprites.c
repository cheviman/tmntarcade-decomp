/**
 *    Name:        engine/sprites.c
 *    Description: the sprite engine: the objects' animations, their sprites into the K051960, their boxes
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* every sprite of the sprite RAM turned off */
void hide_all_sprites(void)
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
		io_write8(a0, d1);
		d1 = (d1 - 1u) & 0x7Fu;
		t1 = d0 - 1u;
		d0 = t1;
		a0 += 8u;
	} while (t1 != 0xFFFFu);
}

/* every frame: the objects drawn sorted by their depth on the screen into the draw list */
void build_draw_list(uint32_t *p_d7, uint32_t *p_a0)
{
	uint8_t d6 = 0;
	uint16_t d0 = 0, d5 = 0;
	uint32_t a1 = 0, d4 = 0, d7 = 0, frame = 0, object = 0, object_2 = 0;
	uint16_t draw_next = 0, t1 = 0;

	d7 = 0x31u;
	d6 = 0u;
	d5 = 0x300u;
	object = OBJECT_ADDRESS(0);
	a1 = draw_list_ADDRESS;
	d4 = OBJECT_ADDRESS(0);
	do
	{
		if ((int8_t)OBJECT(object)->flags >= 0)
		{
			if (OBJECT(object)->flags != 0u)
			{
				frame = OBJECT(object)->frame;
				step_animation(object, frame);
			}
		}
		else
		{
			OBJECT(object)->draw_next = 0u;
			d0 = (uint16_t)(OBJECT(object)->depth + OBJECT(object)->screen_y + 0x38u);
			if (d0 >= 0x180u)
			{
				frame = OBJECT(object)->frame;
				step_animation(object, frame);
			}
			else
			{
				d6++;
				d0 &= ~1u;
				if (d0 < d5)
					d5 = (uint16_t)d0;
				if (RAM16(draw_list_ADDRESS + (uint32_t)(int16_t)d0) == 0u)
					RAM16(draw_list_ADDRESS + (uint32_t)(int16_t)d0) = object;
				else
				{
					d4 = (d4 & ~0xFFFFu) | RAM16(draw_list_ADDRESS + (uint32_t)(int16_t)d0);
					do
					{
						object_2 = d4;
						draw_next = OBJECT(object_2)->draw_next;
						d4 = (d4 & ~0xFFFFu) | draw_next;
					} while (draw_next != 0u);
					OBJECT(object_2)->draw_next = object;
				}
			}
		}
		t1 = d7 - 1u;
		d7 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
	draw_first = d5;
	draw_count = d6;
	*p_d7 = d7;
	*p_a0 = object;
}

void draw_sprites(uint32_t *p_d1, uint32_t *p_a0)
{
	uint16_t d1 = (uint16_t)*p_d1;
	uint32_t a0 = *p_a0;
	bool L_047164 = false;
	uint8_t d0 = 0, d3 = 0, d7 = 0, flips = 0;
	uint16_t d2 = 0, d5 = 0;
	uint32_t a1 = 0, a2 = 0, d6 = 0, frame = 0, size = 0, sprite = 0;
	uint8_t t2 = 0, colour = 0, frame_time = 0, time = 0, last_sprite = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, draw_next = 0;

	a1 = draw_list_ADDRESS + (int16_t)draw_first;
	a2 = SPRITE_RAM;
	d6 = OBJECT_ADDRESS(0);
	d7 = draw_count;
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
			frame = OBJECT(a0)->frame;
			d5 = ANIMATION_FRAME(frame)->last_sprite;
			sprite = ANIMATION_FRAME(frame)->sprites;
			do
			{
				size = sprite_sizes_ADDRESS + ((SPRITE(sprite)->size_code & 0xE0u) >> 2);
				d1 = (uint16_t)SPRITE(sprite)->x;
				t2 = (uint32_t)OBJECT(a0)->flags << 1;
				d3 = t2;
				if ((int8_t)t2 < 0)
					d1 = (uint16_t)(0u - d1 - SPRITE_SIZE(size)->width);
				d1 += OBJECT(a0)->screen_x;
				if ((int16_t)d1 < 0x1A0 && SPRITE_SIZE(size)->left < (int16_t)d1)
				{
					t3 = OBJECT(a0)->height_whole + SPRITE(sprite)->y + OBJECT(a0)->screen_y;
					d2 = t3;
					if ((int16_t)t3 >= 0 && (int16_t)d2 < SPRITE_SIZE(size)->bottom)
					{
						d1 &= 0x1FFu;
						flips = SPRITE(sprite)->flips;
						if ((int8_t)(d3 ^ flips) < 0)
							d1 |= 0x200u;
						d2 &= 0x1FFu;
						if ((flips & 0x40u) != 0u)
							d2 |= 0x200u;
						io_write8(a2, io_read8(a2) | 0x80u);
						io_write8(a2 + 1u, SPRITE(sprite)->size_code);
						io_write8(a2 + 2u, SPRITE(sprite)->code);
						colour = OBJECT(a0)->colour;
						d0 = colour;
						if ((int8_t)colour < 0 || SPRITE(sprite)->colour == 0xFu)
							io_write8(a2 + 3u, SPRITE(sprite)->colour);
						else
							io_write8(a2 + 3u, d0 | (SPRITE(sprite)->colour & 0x90u));
						io_write16(a2 + 6u, d1);
						io_write8(a2 + 7u, (uint8_t)d1);
						io_write16(a2 + 4u, d2);
						io_write8(a2 + 5u, (uint8_t)d2);
						a2 += 8u;
					}
				}
				t4 = d5 - 1u;
				d5 = t4;
				sprite += 8u;
			} while (t4 != 0xFFFFu);
			if ((int8_t)OBJECT(a0)->contacts < 0)
			{
				sprite = OBJECT(a0)->shadow;
				d2 = (uint16_t)(OBJECT(a0)->floor_height + SPRITE(sprite)->y + OBJECT(a0)->screen_y);
				d1 = (SPRITE(sprite)->x + OBJECT(a0)->screen_x) & 0x1FFu;
				if ((int8_t)SPRITE(sprite)->flips < 0)
					d1 |= 0x200u;
				d2 &= 0x1FFu;
				if ((SPRITE(sprite)->flips & 0x40u) != 0u)
					d2 |= 0x200u;
				io_write8(a2, io_read8(a2) | 0x80u);
				io_write8(a2 + 1u, SPRITE(sprite)->size_code);
				io_write8(a2 + 2u, SPRITE(sprite)->code);
				io_write8(a2 + 3u, SPRITE(sprite)->colour);
				io_write16(a2 + 6u, d1);
				io_write8(a2 + 7u, (uint8_t)d1);
				io_write16(a2 + 4u, d2);
				io_write8(a2 + 5u, (uint8_t)d2);
				a2 += 8u;
			}
			if (OBJECT(a0)->frame_time != 0u)
			{
				frame_time = OBJECT(a0)->frame_time;
				OBJECT(a0)->frame_time = frame_time - 1u;
				if (frame_time == 1u)
				{
					frame += 0xAu;
					if (ANIMATION_FRAME(frame - 0xAu)->attack_depth >= 0)
						frame += 8u;
					time = ANIMATION_FRAME(frame)->time;
					d0 = time;
					if (time != 0u)
					{
						OBJECT(a0)->frame = frame;
						d0 += OBJECT(a0)->animation_delay;
					}
					else
					{
						last_sprite = ANIMATION_FRAME(frame)->last_sprite;
						d1 = (uint16_t)((d1 & ~0xFFu) | last_sprite);
						if (last_sprite != 0u)
						{
							frame = ANIMATION_FRAME(frame)->sprites;
							d0 = ANIMATION_FRAME(frame)->time;
							OBJECT(a0)->frame = frame;
							d0 += OBJECT(a0)->animation_delay;
						}
					}
					OBJECT(a0)->frame_time = d0;
				}
			}
			t5 = d7;
			d7 = (uint8_t)(t5 - 1u);
			L_047164 = t5 == 1u;
			if (L_047164)
				break;
			draw_next = OBJECT(a0)->draw_next;
			d6 = (d6 & ~0xFFFFu) | draw_next;
		} while (draw_next != 0u);
		if (L_047164)
			break;
	}
	for (;;)
	{
		t6 = io_read8(a2);
		io_write8(a2, t6 & 0x7Fu);
		if ((t6 & 0x80u) == 0u)
			break;
		a2 += 8u;
	}
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_a0 = a0;
}

void step_animation(uint32_t a0, uint32_t frame)
{
	uint8_t d0 = 0;
	uint8_t frame_time = 0, time = 0;

	if (OBJECT(a0)->frame_time != 0u)
	{
		frame_time = OBJECT(a0)->frame_time;
		OBJECT(a0)->frame_time = frame_time - 1u;
		if (frame_time != 1u)
			return;
		frame += 0xAu;
		if (ANIMATION_FRAME(frame - 0xAu)->attack_depth >= 0)
			frame += 8u;
		time = ANIMATION_FRAME(frame)->time;
		d0 = time;
		if (time != 0u)
		{
			OBJECT(a0)->frame = frame;
			d0 += OBJECT(a0)->animation_delay;
			OBJECT(a0)->frame_time = d0;
			return;
		}
		if (ANIMATION_FRAME(frame)->last_sprite == 0u)
		{
			OBJECT(a0)->frame_time = d0;
			return;
		}
		frame = ANIMATION_FRAME(frame)->sprites;
		d0 = ANIMATION_FRAME(frame)->time;
		OBJECT(a0)->frame = frame;
		d0 += OBJECT(a0)->animation_delay;
		OBJECT(a0)->frame_time = d0;
		return;
	}
}

/* every frame: the turtles' and the enemies' attacks against each other, the hits and the damage */
void check_attacks(void)
{
	uint16_t d0 = 0, d1 = 0, d2 = 0, d7 = 0, health_bars = 0;
	uint32_t a5 = 0, attack = 0, box = 0, object = 0, object_2 = 0, turtle = 0, turtle_2 = 0;
	uint8_t t4 = 0, t5 = 0, t12 = 0, t13 = 0, t20 = 0, t21 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, damage = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, damage_2 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, damage_3 = 0, t22 = 0, t23 = 0, t24 = 0;

	a5 = OBJECT_ADDRESS(4);
	if ((frame_count & 1u) != 0u)
		a5 = OBJECT_ADDRESS(5);
	turtle = OBJECT_ADDRESS(0);
	d0 = 3u;
	do
	{
		if ((OBJECT(turtle)->flags & 4u) != 0u)
		{
			attack = OBJECT(turtle)->frame;
			if (ATTACK_FRAME(attack)->attack_depth >= 0)
			{
				object_2 = a5;
				d1 = 0x11u;
				do
				{
					if ((OBJECT(object_2)->flags & 2u) != 0u)
					{
						t1 = OBJECT(turtle)->screen_y - OBJECT(object_2)->screen_y;
						d2 = t1;
						if ((int16_t)t1 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_depth + OBJECT(object_2)->depth) >= 0)
						{
							box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(object_2)->frame)->body_box;
							d2 = (uint16_t)ATTACK_FRAME(attack)->attack_x;
							if ((OBJECT(turtle)->flags & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t2 = d2 + OBJECT(turtle)->screen_x - OBJECT(object_2)->screen_x;
							d2 = t2;
							if ((int16_t)t2 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_width + BODY_BOX(box)->half_width) >= 0)
							{
								t3 = OBJECT(turtle)->height_whole + ATTACK_FRAME(attack)->attack_y - OBJECT(object_2)->height_whole;
								d2 = t3;
								if ((int16_t)t3 >= 0)
								{
									if ((int16_t)(0u - d2 + ATTACK_FRAME(attack)->attack_height + BODY_BOX(box)->height) >= 0)
									{
										OBJECT(object_2)->attacker = turtle;
										OBJECT(turtle)->turtle.hit_target = object_2;
										OBJECT(object_2)->hit_routine = (((uint32_t)OBJECT(object_2)->routine << 8u) | OBJECT(object_2)->state);
										OBJECT(object_2)->routine = 4u;
										OBJECT(object_2)->state = 0u;
										OBJECT(turtle)->flags |= 8u;
										OBJECT(object_2)->flags &= ~2u;
										OBJECT(object_2)->hit = OBJECT(turtle)->attack;
										health_bars = (((uint32_t)OBJECT(object_2)->health_bars << 8u) | OBJECT(object_2)->health);
										t4 = (uint8_t)OBJECT(turtle)->damage;
										t5 = (uint8_t)health_bars;
										d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t5 - t4));
										if (t5 <= t4)
										{
											damage = OBJECT(turtle)->damage;
											t6 = (d2 & ~0xFFu) | (uint8_t)OBJECT(turtle)->damage;
											d2 = (uint16_t)(t6 - damage);
											if (t6 <= damage)
											{
												d7 = (uint16_t)(0x400u | TABLE8(indexed_table_of_8_bit_values_0471F0, (uint32_t)(int16_t)d0));
												queue_job(d7);
												d2 = 0u;
											}
										}
										OBJECT(object_2)->health_bars = (uint8_t)(d2 >> 8u);
										OBJECT(object_2)->health = (uint8_t)d2;
									}
								}
								else if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_height) >= 0)
								{
									OBJECT(object_2)->attacker = turtle;
									OBJECT(turtle)->turtle.hit_target = object_2;
									OBJECT(object_2)->hit_routine = (((uint32_t)OBJECT(object_2)->routine << 8u) | OBJECT(object_2)->state);
									OBJECT(object_2)->routine = 4u;
									OBJECT(object_2)->state = 0u;
									OBJECT(turtle)->flags |= 8u;
									OBJECT(object_2)->flags &= ~2u;
									OBJECT(object_2)->hit = OBJECT(turtle)->attack;
									health_bars = (((uint32_t)OBJECT(object_2)->health_bars << 8u) | OBJECT(object_2)->health);
									t4 = (uint8_t)OBJECT(turtle)->damage;
									t5 = (uint8_t)health_bars;
									d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t5 - t4));
									if (t5 <= t4)
									{
										damage = OBJECT(turtle)->damage;
										t6 = (d2 & ~0xFFu) | (uint8_t)OBJECT(turtle)->damage;
										d2 = (uint16_t)(t6 - damage);
										if (t6 <= damage)
										{
											d7 = (uint16_t)(0x400u | TABLE8(indexed_table_of_8_bit_values_0471F0, (uint32_t)(int16_t)d0));
											queue_job(d7);
											d2 = 0u;
										}
									}
									OBJECT(object_2)->health_bars = (uint8_t)(d2 >> 8u);
									OBJECT(object_2)->health = (uint8_t)d2;
								}
							}
						}
					}
					t7 = d1 - 1u;
					d1 = t7;
					object_2 += 0xA0u;
				} while (t7 != 0xFFFFu);
			}
		}
		t8 = d0 - 1u;
		d0 = t8;
		turtle += 0x50u;
	} while (t8 != 0xFFFFu);
	object = a5;
	d0 = 0x11u;
	do
	{
		if ((OBJECT(object)->flags & 4u) != 0u)
		{
			attack = OBJECT(object)->frame;
			if (ATTACK_FRAME(attack)->attack_depth >= 0)
			{
				turtle_2 = OBJECT_ADDRESS(0);
				d1 = 3u;
				do
				{
					if ((OBJECT(turtle_2)->flags & 2u) != 0u)
					{
						t9 = OBJECT(object)->screen_y - OBJECT(turtle_2)->screen_y;
						d2 = t9;
						if ((int16_t)t9 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_depth + OBJECT(turtle_2)->depth) >= 0)
						{
							box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(turtle_2)->frame)->body_box;
							d2 = (uint16_t)ATTACK_FRAME(attack)->attack_x;
							if ((OBJECT(object)->flags & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t10 = d2 + OBJECT(object)->screen_x - OBJECT(turtle_2)->screen_x;
							d2 = t10;
							if ((int16_t)t10 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_width + BODY_BOX(box)->half_width) >= 0)
							{
								t11 = OBJECT(object)->height_whole + ATTACK_FRAME(attack)->attack_y - OBJECT(turtle_2)->height_whole;
								d2 = t11;
								if ((int16_t)t11 >= 0)
								{
									if ((int16_t)(0u - d2 + ATTACK_FRAME(attack)->attack_height + BODY_BOX(box)->height) >= 0)
									{
										OBJECT(turtle_2)->flags &= ~2u;
										OBJECT(turtle_2)->hit_routine = (((uint32_t)OBJECT(turtle_2)->routine << 8u) | OBJECT(turtle_2)->state);
										OBJECT(turtle_2)->routine = 4u;
										OBJECT(turtle_2)->state = 0u;
										OBJECT(turtle_2)->turtle.hit_by = object;
										OBJECT(object)->flags |= 8u;
										OBJECT(object)->hit_object = turtle_2;
										OBJECT(turtle_2)->hit = OBJECT(object)->attack;
										health_bars = (((uint32_t)OBJECT(turtle_2)->health_bars << 8u) | OBJECT(turtle_2)->health);
										t12 = (uint8_t)OBJECT(object)->damage;
										t13 = (uint8_t)health_bars;
										d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t13 - t12));
										if (t13 <= t12)
										{
											damage_2 = OBJECT(object)->damage;
											t14 = (d2 & ~0xFFu) | (uint8_t)OBJECT(object)->damage;
											d2 = (uint16_t)(t14 - damage_2);
											if (t14 < damage_2)
												d2 = 0u;
										}
										OBJECT(turtle_2)->health_bars = (uint8_t)(d2 >> 8u);
										OBJECT(turtle_2)->health = (uint8_t)d2;
										break;
									}
								}
								else if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_height) >= 0)
								{
									OBJECT(turtle_2)->flags &= ~2u;
									OBJECT(turtle_2)->hit_routine = (((uint32_t)OBJECT(turtle_2)->routine << 8u) | OBJECT(turtle_2)->state);
									OBJECT(turtle_2)->routine = 4u;
									OBJECT(turtle_2)->state = 0u;
									OBJECT(turtle_2)->turtle.hit_by = object;
									OBJECT(object)->flags |= 8u;
									OBJECT(object)->hit_object = turtle_2;
									OBJECT(turtle_2)->hit = OBJECT(object)->attack;
									health_bars = (((uint32_t)OBJECT(turtle_2)->health_bars << 8u) | OBJECT(turtle_2)->health);
									t12 = (uint8_t)OBJECT(object)->damage;
									t13 = (uint8_t)health_bars;
									d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t13 - t12));
									if (t13 <= t12)
									{
										damage_2 = OBJECT(object)->damage;
										t14 = (d2 & ~0xFFu) | (uint8_t)OBJECT(object)->damage;
										d2 = (uint16_t)(t14 - damage_2);
										if (t14 < damage_2)
											d2 = 0u;
									}
									OBJECT(turtle_2)->health_bars = (uint8_t)(d2 >> 8u);
									OBJECT(turtle_2)->health = (uint8_t)d2;
									break;
								}
							}
						}
					}
					t15 = d1 - 1u;
					d1 = t15;
					turtle_2 += 0x50u;
				} while (t15 != 0xFFFFu);
			}
		}
		t16 = d0 - 1u;
		d0 = t16;
		object += 0xA0u;
	} while (t16 != 0xFFFFu);
	object = attack_check_objects[(uint8_t)frame_count & 3u];
	d0 = 1u;
	do
	{
		if ((OBJECT(object)->flags & 4u) != 0u)
		{
			attack = OBJECT(object)->frame;
			if (ATTACK_FRAME(attack)->attack_depth >= 0)
			{
				object_2 = OBJECT_ADDRESS(12);
				d1 = 0xBu;
				do
				{
					if ((OBJECT(object_2)->flags & 2u) != 0u)
					{
						t17 = OBJECT(object)->screen_y - OBJECT(object_2)->screen_y;
						d2 = t17;
						if ((int16_t)t17 >= 0)
							d2 = (uint16_t)(0u - d2);
						if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_depth + OBJECT(object_2)->depth) >= 0)
						{
							box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(object_2)->frame)->body_box;
							d2 = (uint16_t)ATTACK_FRAME(attack)->attack_x;
							if ((OBJECT(object)->flags & 0x40u) != 0u)
								d2 = (uint16_t)(0u - d2);
							t18 = d2 + OBJECT(object)->screen_x - OBJECT(object_2)->screen_x;
							d2 = t18;
							if ((int16_t)t18 >= 0)
								d2 = (uint16_t)(0u - d2);
							if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_width + BODY_BOX(box)->half_width) >= 0)
							{
								t19 = OBJECT(object)->height_whole + ATTACK_FRAME(attack)->attack_y - OBJECT(object_2)->height_whole;
								d2 = t19;
								if ((int16_t)t19 >= 0)
								{
									if ((int16_t)(0u - d2 + ATTACK_FRAME(attack)->attack_height + BODY_BOX(box)->height) >= 0)
									{
										OBJECT(object_2)->attacker = object;
										OBJECT(object)->hit_object = object_2;
										OBJECT(object_2)->hit_routine = (((uint32_t)OBJECT(object_2)->routine << 8u) | OBJECT(object_2)->state);
										OBJECT(object_2)->routine = 4u;
										OBJECT(object_2)->state = 0u;
										OBJECT(object)->flags |= 8u;
										OBJECT(object_2)->flags &= ~2u;
										OBJECT(object_2)->hit = OBJECT(object)->attack;
										OBJECT(object_2)->hit ^= 0x80u;
										health_bars = (((uint32_t)OBJECT(object_2)->health_bars << 8u) | OBJECT(object_2)->health);
										t20 = (uint8_t)OBJECT(object)->damage;
										t21 = (uint8_t)health_bars;
										d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t21 - t20));
										if (t21 <= t20)
										{
											damage_3 = OBJECT(object)->damage;
											t22 = (d2 & ~0xFFu) | (uint8_t)OBJECT(object)->damage;
											d2 = (uint16_t)(t22 - damage_3);
											if (t22 < damage_3)
												d2 = 0u;
										}
										OBJECT(object_2)->health_bars = (uint8_t)(d2 >> 8u);
										OBJECT(object_2)->health = (uint8_t)d2;
									}
								}
								else if ((int16_t)(d2 + ATTACK_FRAME(attack)->attack_height) >= 0)
								{
									OBJECT(object_2)->attacker = object;
									OBJECT(object)->hit_object = object_2;
									OBJECT(object_2)->hit_routine = (((uint32_t)OBJECT(object_2)->routine << 8u) | OBJECT(object_2)->state);
									OBJECT(object_2)->routine = 4u;
									OBJECT(object_2)->state = 0u;
									OBJECT(object)->flags |= 8u;
									OBJECT(object_2)->flags &= ~2u;
									OBJECT(object_2)->hit = OBJECT(object)->attack;
									OBJECT(object_2)->hit ^= 0x80u;
									health_bars = (((uint32_t)OBJECT(object_2)->health_bars << 8u) | OBJECT(object_2)->health);
									t20 = (uint8_t)OBJECT(object)->damage;
									t21 = (uint8_t)health_bars;
									d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t21 - t20));
									if (t21 <= t20)
									{
										damage_3 = OBJECT(object)->damage;
										t22 = (d2 & ~0xFFu) | (uint8_t)OBJECT(object)->damage;
										d2 = (uint16_t)(t22 - damage_3);
										if (t22 < damage_3)
											d2 = 0u;
									}
									OBJECT(object_2)->health_bars = (uint8_t)(d2 >> 8u);
									OBJECT(object_2)->health = (uint8_t)d2;
								}
							}
						}
					}
					t23 = d1 - 1u;
					d1 = t23;
					object_2 += 0x50u;
				} while (t23 != 0xFFFFu);
			}
		}
		t24 = d0 - 1u;
		d0 = t24;
		object += 0x140u;
	} while (t24 != 0xFFFFu);
}

/* the turtle against the solid objects: blocked, standing on one, or carried by a platform */
void turtle_collide_with_objects(uint32_t a0)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t box = 0, object = 0, other_box = 0;
	uint8_t flags = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	object = OBJECT_ADDRESS(4);
	d7 = 7u;
	OBJECT(a0)->contacts = 0u;
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags & 0xEFu;
	if ((flags & 0x10u) != 0u)
		OBJECT(a0)->floor_height = 0u;
	box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(a0)->frame)->body_box;
	for (;;)
	{
		if (OBJECT(object)->flags == 0u)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		d1 = 0xAu;
		t2 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
		d4 = t2;
		if ((int16_t)t2 >= 0)
		{
			d4 = (uint16_t)(0u - d4);
			d1 += 2u;
		}
		t3 = d4 + OBJECT(a0)->depth + OBJECT(object)->depth;
		d4 = t3;
		if ((int16_t)t3 < 0)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		other_box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(object)->frame)->body_box;
		t4 = OBJECT(a0)->screen_x - OBJECT(object)->screen_x;
		d5 = t4;
		if ((int16_t)t4 >= 0)
		{
			d5 = (uint16_t)(0u - d5);
			d1 += 8u;
		}
		t5 = d5 + BODY_BOX(box)->half_width + BODY_BOX(other_box)->half_width;
		d5 = t5;
		if ((int16_t)t5 < 0)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < d5)
			d1 &= 0xE7u;
		else
			d1 &= ~6u;
		d0 = OBJECT(object)->height_whole;
		t6 = OBJECT(a0)->height_whole - d0;
		d6 = t6;
		if ((int16_t)t6 < 0)
		{
			if ((int16_t)(d6 + BODY_BOX(box)->height) >= 0)
			{
				OBJECT(a0)->contacts |= d1;
				break;
			}
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		d0 += BODY_BOX(other_box)->height;
		t7 = 0u - d6 + BODY_BOX(other_box)->height;
		d6 = t7;
		if ((int16_t)t7 < 0)
		{
			if (d4 >= 3u && d5 >= 3u)
			{
				OBJECT(a0)->floor_height = (uint8_t)d0;
				OBJECT(a0)->flags |= 0x10u;
				break;
			}
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < 3u || d5 < 3u)
		{
			OBJECT(a0)->contacts |= d1;
			return;
		}
		OBJECT(a0)->flags |= 0x10u;
		if (d6 >= 5u)
		{
			OBJECT(a0)->contacts |= d1;
			return;
		}
		OBJECT(a0)->floor_height = (uint8_t)d0;
		OBJECT(a0)->height_whole = (uint8_t)d0;
		OBJECT(a0)->height &= 0xFF00u;
		d1 = 1u;
		if ((int8_t)OBJECT(object)->kind >= 0)
		{
			OBJECT(a0)->contacts |= d1;
			return;
		}
		OBJECT(a0)->x += OBJECT(object)->x_speed;
		OBJECT(a0)->y += OBJECT(object)->y_speed;
		OBJECT(a0)->height += OBJECT(object)->height_speed;
		OBJECT(a0)->contacts |= d1;
		return;
	}
}

/* the enemy against the solid objects: blocked or standing on one */
void enemy_collide_with_objects(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t a5 = *p_a5;
	uint8_t d1 = 0;
	uint16_t d0 = 0, d4 = 0, d5_2 = 0, d6 = 0;
	uint32_t box = 0, d7 = 0, object = 0;
	uint8_t flags = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	object = OBJECT_ADDRESS(4);
	d7 = 7u;
	OBJECT(a0)->contacts &= 0xE0u;
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags & 0xEFu;
	if ((flags & 0x10u) != 0u)
		OBJECT(a0)->floor_height = 0u;
	box = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(a0)->frame)->body_box;
	for (;;)
	{
		if (OBJECT(object)->flags == 0u)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		d1 = 0xAu;
		t2 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
		d4 = t2;
		if ((int16_t)t2 >= 0)
		{
			d4 = (uint16_t)(0u - d4);
			d1 += 2u;
		}
		t3 = d4 + OBJECT(a0)->depth + OBJECT(object)->depth;
		d4 = t3;
		if ((int16_t)t3 < 0)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		a5 = body_boxes_ADDRESS + (int16_t)ANIMATION_FRAME(OBJECT(object)->frame)->body_box;
		t4 = OBJECT(a0)->screen_x - OBJECT(object)->screen_x;
		d5_2 = t4;
		if ((int16_t)t4 >= 0)
		{
			d5_2 = (uint16_t)(0u - d5_2);
			d1 += 8u;
		}
		t5 = d5_2 + BODY_BOX(box)->half_width + BODY_BOX(a5)->half_width;
		d5 = t5;
		if ((int16_t)t5 < 0)
		{
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < d5)
			d1 &= 0xE7u;
		else
			d1 &= ~6u;
		d0 = OBJECT(object)->height_whole;
		t6 = OBJECT(a0)->height_whole - d0;
		d6 = t6;
		if ((int16_t)t6 < 0)
		{
			if ((int16_t)(d6 + BODY_BOX(box)->height) < 0)
			{
				t1 = d7 - 1u;
				d7 = t1;
				object += 0x50u;
				if (t1 == 0xFFFFu)
					break;
				continue;
			}
			OBJECT(a0)->contacts |= d1;
			break;
		}
		d0 += BODY_BOX(a5)->height;
		t7 = 0u - d6 + BODY_BOX(a5)->height;
		d6 = t7;
		if ((int16_t)t7 < 0)
		{
			if (d4 >= 3u && d5 >= 3u)
			{
				OBJECT(a0)->floor_height = (uint8_t)d0;
				OBJECT(a0)->flags |= 0x10u;
				break;
			}
			t1 = d7 - 1u;
			d7 = t1;
			object += 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (d4 < 3u || d5 < 3u)
		{
			OBJECT(a0)->contacts |= d1;
			break;
		}
		OBJECT(a0)->flags |= 0x10u;
		if (d6 >= 5u)
		{
			OBJECT(a0)->contacts |= d1;
			break;
		}
		OBJECT(a0)->floor_height = (uint8_t)d0;
		OBJECT(a0)->height_whole = (uint8_t)d0;
		OBJECT(a0)->height &= 0xFF00u;
		d1 = 1u;
		OBJECT(a0)->contacts |= d1;
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
	*p_a5 = a5;
}

/* the players' slots the enemies go after, set up for the area */
void start_player_slots(void)
{
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->turtle = OBJECT_ADDRESS(0);
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->turtle = OBJECT_ADDRESS(1);
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->turtle = OBJECT_ADDRESS(2);
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->turtle = OBJECT_ADDRESS(3);
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->enemies = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->rodney_sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->mouser_sides = 0u;
	AT32(PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->grab_time, -3) = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(0))->unused = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->enemies = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->rodney_sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->mouser_sides = 0u;
	AT32(PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->grab_time, -3) = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(1))->unused = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->enemies = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->rodney_sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->mouser_sides = 0u;
	AT32(PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->grab_time, -3) = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(2))->unused = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->enemies = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->rodney_sides = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->mouser_sides = 0u;
	AT32(PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->grab_time, -3) = 0u;
	PLAYER_SLOT(PLAYER_SLOT_ADDRESS(3))->unused = 0u;
	nearest_slot = PLAYER_SLOT_ADDRESS(0);
	nearest_turtle = OBJECT_ADDRESS(0);
	stairs_top_height = rom_048830[area & 0xFu];
}

/* the object loop: the enemies' spawns, the players' slots, and every object's routine and screen place */
void run_objects(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint16_t d0 = 0;
	uint32_t a5 = 0, a6 = 0, object = 0;

	a1 = spawn_enemies(a1);
	load_layer_b();
	a5 = update_player_slots();
	object = OBJECT_ADDRESS(4);
	do
	{
		if (OBJECT(object)->flags != 0u)
		{
			d0 = (uint16_t)((uint32_t)OBJECT(object)->routine << 2);
			a6 = mem_read32(rom_053896[OBJECT(object)->kind & 0x7Fu] + d0);
			switch (a6)
			{
			case 0x00DF7Eu:
				krang_appear(object, &d7, &a5);
				break;
			case 0x00E03Cu:
				krang_walk(object, p_d5, &d7, &a5);
				break;
			case 0x00E124u:
				krang_melee(object, p_d5, &d7, &a5);
				break;
			case 0x00E1A8u:
				krang_fire_lasers(object, p_d5, &d7, &a5);
				break;
			case 0x00E21Au:
				d7 = krang_struck(d7, object);
				break;
			case 0x00E2A8u:
				krang_recoil(object, &d7, &a5);
				break;
			case 0x00E2DCu:
				krang_explode(object, &d7, &a5);
				break;
			case 0x00E39Cu:
				krang_escape(d0, object, p_d5, &d7);
				break;
			case 0x00E962u:
				krang_curtain_start(object);
				break;
			case 0x00E992u:
				d7 = krang_curtain_open(d7, object);
				break;
			case 0x00E9B6u:
				krang_curtain_end(object);
				break;
			case 0x00EAB6u:
				d7 = krang_laser_start(object);
				break;
			case 0x00EB2Au:
				krang_laser_wait(object);
				break;
			case 0x00EB3Eu:
				d7 = krang_laser_fly(object);
				break;
			case 0x00EB70u:
				krang_laser_spark(object);
				break;
			case 0x00EBFEu:
				krang_fist_start(object);
				break;
			case 0x00EC4Cu:
				d7 = krang_fist_launch(d7, object);
				break;
			case 0x00EC76u:
				d7 = krang_fist_fly(d7, object);
				break;
			case 0x00F8DAu:
				ball_dropper_start(object);
				break;
			case 0x00F8F2u:
				d7 = ball_dropper_wait(object);
				break;
			case 0x00F96Au:
				ball_start(object);
				break;
			case 0x00F98Eu:
				d7 = ball_drop(d7, object);
				break;
			case 0x00F9DCu:
				d7 = ball_bounce(object);
				break;
			case 0x00FA1Cu:
				road_barrier_start(object);
				break;
			case 0x00FA5Au:
				road_barrier_stay(object);
				break;
			case 0x00FA68u:
				tire_stack_start(object);
				break;
			case 0x00FA9Au:
				tire_stack_stay(object);
				break;
			case 0x00FAACu:
				technodrome_ball_start(object);
				break;
			case 0x00FADCu:
				d7 = technodrome_ball_drop(d7, object);
				break;
			case 0x00FB34u:
				d7 = technodrome_ball_bounce(object);
				break;
			case 0x00FBB4u:
				hydrant_start(object);
				break;
			case 0x00FBD8u:
				hydrant_stay(object);
				break;
			case 0x00FBDEu:
				d7 = hydrant_spray(d7, object);
				break;
			case 0x00FC1Cu:
				d7 = hydrant_struck(d7, object);
				break;
			case 0x00FCA6u:
				hydrant_recover(object);
				break;
			case 0x00FD3Au:
				d7 = hydrant_water_start(object);
				break;
			case 0x00FDA4u:
				d7 = hydrant_water_fly(object);
				break;
			case 0x00FDF2u:
				roadside_cone_start(object);
				break;
			case 0x00FDFCu:
				roadside_pole_start(object);
				break;
			case 0x00FE44u:
				roadside_stay(object);
				break;
			case 0x00FE4Cu:
				d7 = roadside_fly(object);
				break;
			case 0x00FE5Eu:
				d7 = roadside_speed_sign_struck(d7, object);
				break;
			case 0x00FE6Eu:
				d7 = roadside_cone_struck(d7, object);
				break;
			case 0x00FE7Eu:
				d7 = roadside_parking_meter_struck(d7, object);
				break;
			case 0x00FEE2u:
				d7 = rat_start(object);
				break;
			case 0x00FF70u:
				d7 = rat_drop(d7, object);
				break;
			case 0x00FFA0u:
				d7 = rat_sit(d7, object);
				break;
			case 0x00FFBEu:
				d7 = rat_run(d7, object);
				break;
			case 0x010026u:
				alligator_start(object);
				break;
			case 0x010058u:
				d7 = alligator_swim(object);
				break;
			case 0x010080u:
				d7 = alligator_snap(object);
				break;
			case 0x0100ACu:
				skateboarder_start(object);
				break;
			case 0x0100D4u:
				skateboarder_idle();
				break;
			case 0x0100D6u:
				d7 = skateboarder_glide(object);
				break;
			case 0x0100DAu:
				d7 = skateboarder_struck(d7, object);
				break;
			case 0x010108u:
				d7 = pizza_start(object);
				break;
			case 0x010158u:
				pizza_wait(d0, object, p_d5, &d7);
				break;
			case 0x0101DCu:
				pizza_vanish(object);
				break;
			case 0x0101F8u:
				d7 = billboard_start(d7, object);
				break;
			case 0x01023Au:
				d7 = billboard_wait(d7, object);
				break;
			case 0x0102BCu:
				d7 = billboard_fall(d7, object);
				break;
			case 0x0102E0u:
				d7 = billboard_land(d7, object);
				break;
			case 0x010354u:
				billboard_soldier_start(object);
				break;
			case 0x010398u:
				billboard_soldier_wait(object);
				break;
			case 0x0103C0u:
				d7 = billboard_soldier_jump_down(object);
				break;
			case 0x0103F2u:
				billboard_soldier_become_boomerang_soldier(object);
				break;
			case 0x01042Cu:
				oil_drum_start(object);
				break;
			case 0x010450u:
				oil_drum_stay(object);
				break;
			case 0x010458u:
				d7 = oil_drum_blow_up(d7, object);
				break;
			case 0x010490u:
				oil_drum_become_wreck(object);
				break;
			case 0x0104C2u:
				d7 = oil_drum_struck(d7, object);
				break;
			case 0x010520u:
				oil_drum_recover(object);
				break;
			case 0x010554u:
				d7 = turret_start(object);
				break;
			case 0x01059Eu:
				d7 = turret_move(object);
				break;
			case 0x0105BCu:
				d7 = turret_fire(object);
				break;
			case 0x010602u:
				turret_wreck(object, &d7, &a5);
				break;
			case 0x010674u:
				d7 = turret_struck(d7, object);
				break;
			case 0x0106D6u:
				d7 = turret_recover(object);
				break;
			case 0x01080Au:
				d7 = turret_shot_start(d7, object);
				break;
			case 0x010880u:
				d7 = turret_shot_fly(d7, object);
				break;
			case 0x0108B6u:
				turret_shot_vanish(object);
				break;
			case 0x0108D4u:
				waiting_soldier_start(object);
				break;
			case 0x0108FCu:
				waiting_soldier_wait(object);
				break;
			case 0x01090Cu:
				waiting_soldier_become_knife_soldier(object);
				break;
			case 0x01092Eu:
				one_way_sign_start(object);
				break;
			case 0x010952u:
				one_way_sign_stay(object);
				break;
			case 0x010958u:
				one_way_sign_spin(object);
				break;
			case 0x010970u:
				one_way_sign_idle();
				break;
			case 0x010972u:
				d7 = one_way_sign_struck(d7, object);
				break;
			case 0x0109D2u:
				nozzle_row_start(object);
				break;
			case 0x0109F8u:
				nozzle_row_run(object, p_d5, &d7, &a5);
				break;
			case 0x010AD4u:
				nozzle_row_done(object);
				break;
			case 0x010B22u:
				freeze_nozzle_start(object);
				break;
			case 0x010B4Au:
				freeze_nozzle_rise(object);
				break;
			case 0x010B6Au:
				d7 = freeze_nozzle_spray(object);
				break;
			case 0x010BE0u:
				freeze_nozzle_sink(object);
				break;
			case 0x010BF8u:
				d7 = freeze_nozzle_struck(d7, object);
				break;
			case 0x010C46u:
				freeze_nozzle_broken(object);
				break;
			case 0x010C56u:
				electric_beam_start(object, &d7, &a5);
				break;
			case 0x010C76u:
				d7 = electric_beam_wait(d7, object);
				break;
			case 0x010CB2u:
				electric_beam_shine(object, &d7, &a5);
				break;
			case 0x010CDAu:
				electric_vent_start(object, &d7, &a5);
				break;
			case 0x010CFAu:
				electric_vent_wait(object, &d7, &a5);
				break;
			case 0x010D36u:
				electric_vent_wait_column(object);
				break;
			case 0x010DA8u:
				d7 = electric_column_start(d7, object);
				break;
			case 0x010DD4u:
				electric_column_rise(object);
				break;
			case 0x010DE8u:
				d7 = electric_column_flicker(d7, object);
				break;
			case 0x010E0Cu:
				electric_column_leave(object);
				break;
			case 0x010E50u:
				grille_start(object);
				break;
			case 0x010E76u:
				grille_idle();
				break;
			case 0x0110A8u:
				explosion_small_start(object);
				break;
			case 0x0110B2u:
				explosion_big_start(object);
				break;
			case 0x0110BCu:
				explosion_drum_start(object);
				break;
			case 0x0110C6u:
				explosion_rocket_start(object);
				break;
			case 0x0110D0u:
				explosion_medium_start(object);
				break;
			case 0x0110F4u:
				explosion_end(object);
				break;
			case 0x011116u:
				spiked_pole_start(object);
				break;
			case 0x01115Au:
				d7 = spiked_pole_wait(d7, object);
				break;
			case 0x011190u:
				d7 = spiked_pole_hold_up(d7, object);
				break;
			case 0x0111C6u:
				d7 = spiked_pole_drop(d7, object);
				break;
			case 0x011208u:
				d7 = spiked_pole_hold_down(d7, object);
				break;
			case 0x01123Eu:
				d7 = spiked_pole_rise(d7, object);
				break;
			case 0x01129Cu:
				sewer_launcher_start(object);
				break;
			case 0x0112DAu:
				sewer_launcher_wait(object, p_d5, &d7);
				break;
			case 0x01133Au:
				sewer_launcher_fired(object);
				break;
			case 0x011374u:
				sewer_launcher_remove(object);
				break;
			case 0x01147Eu:
				d7 = sewer_missile_start(d7, object);
				break;
			case 0x0114C6u:
				d7 = sewer_missile_rise(object);
				break;
			case 0x0114F6u:
				d7 = sewer_missile_fly(object);
				break;
			case 0x0114FEu:
				sewer_missile_remove(object);
				break;
			case 0x011502u:
				d7 = sewer_missile_struck(d7, object);
				break;
			case 0x011528u:
				sewer_missile_vanish(object);
				break;
			case 0x01154Eu:
				rock_soldier_site_enter(d0, object, p_d5, &d7, &a5);
				break;
			case 0x0116CCu:
				rock_soldier_site_think(object, p_d5, &d7, &a5);
				break;
			case 0x01186Cu:
				rock_soldier_site_fire(object, p_d5, &d7);
				break;
			case 0x0118CAu:
				rock_soldier_site_finish_attack(object, p_d5, &d7, &a5);
				break;
			case 0x0118ECu:
				rock_soldier_struck(object, &d7, &a1);
				break;
			case 0x0119A0u:
				rock_soldier_recover(object, &d7, &a5);
				break;
			case 0x0119DEu:
				rock_soldier_defeated(object, &d7, &a5);
				break;
			case 0x012024u:
				d7 = gun_blast_start(d7, object);
				break;
			case 0x012076u:
				d7 = gun_blast_fly(d7, object);
				break;
			case 0x012110u:
				d7 = rubble_start(object);
				break;
			case 0x01214Eu:
				d7 = rubble_fall(object);
				break;
			case 0x01217Au:
				rubble_stay();
				break;
			case 0x012198u:
				rock_soldier_technodrome_enter(object, &d7, &a5);
				break;
			case 0x0122C8u:
				rock_soldier_technodrome_think(object, p_d5, &d7, &a5);
				break;
			case 0x012422u:
				rock_soldier_technodrome_fire(object, p_d5, &d7, &a5);
				break;
			case 0x012430u:
				rock_soldier_technodrome_finish_blow(object, p_d5, &d7, &a5);
				break;
			case 0x0126A0u:
				d7 = wall_slab_start(d7, object);
				break;
			case 0x0126F0u:
				d7 = wall_slab_fly(d7, object);
				break;
			case 0x01277Eu:
				d7 = missile_start(d7, object);
				break;
			case 0x0127D6u:
				missile_fly(object, p_d5, &d7, &a5);
				break;
			case 0x012830u:
				missile_explode(object);
				break;
			case 0x012862u:
				missile_idle();
				break;
			case 0x012864u:
				missile_struck(object);
				break;
			case 0x01287Au:
				missile_vanish(object);
				break;
			case 0x0128D8u:
				shock_bars_start(object);
				break;
			case 0x0128FEu:
				d7 = shock_bars_blink_in(d7, object);
				break;
			case 0x012924u:
				shock_bars_on(object);
				break;
			case 0x01293Cu:
				d7 = shock_bars_blink_out(d7, object);
				break;
			case 0x0129A6u:
				shock_bars_hit_box_start(object);
				break;
			case 0x0129E2u:
				d7 = shock_bars_hit_box_zap(d7, object);
				break;
			case 0x012A2Eu:
				parked_car_start(object);
				break;
			case 0x012A68u:
				d7 = parked_car_draw(d7, object);
				break;
			case 0x012A88u:
				d7 = parked_car_wait(d7, object);
				break;
			case 0x012AA6u:
				parked_car_start_drive(object, &d7, &a5);
				break;
			case 0x012AE2u:
				d7 = parked_car_drive_off(d7, object);
				break;
			case 0x012B3Cu:
				d7 = parked_car_release_soldiers(d7, object);
				break;
			case 0x012C1Cu:
				d7 = car_hit_box_start(d7, object);
				break;
			case 0x012C58u:
				d7 = car_hit_box_move(d7, object);
				break;
			case 0x012CB2u:
				d7 = car_soldier_start(object);
				break;
			case 0x012D06u:
				d7 = car_soldier_leap(d7, object);
				break;
			case 0x012D4Eu:
				d7 = helicopter_start(object);
				break;
			case 0x012DCEu:
				helicopter_hover(object, p_d5, &d7);
				break;
			case 0x012E06u:
				helicopter_fire_bullets(object, p_d5, &d7);
				break;
			case 0x012E50u:
				helicopter_drop_missiles(object, p_d5, &d7);
				break;
			case 0x012E9Au:
				d7 = helicopter_struck(object);
				break;
			case 0x012F10u:
				d7 = helicopter_recover(object);
				break;
			case 0x012F40u:
				helicopter_destroyed(object);
				break;
			case 0x0131B8u:
				d7 = copter_bullet_start(d7, object);
				break;
			case 0x01320Cu:
				d7 = copter_bullet_fly(object);
				break;
			case 0x013260u:
				copter_bullet_burst(object);
				break;
			case 0x013264u:
				copter_bullet_vanish(object);
				break;
			case 0x0132A2u:
				d7 = falling_missile_start(d7, object);
				break;
			case 0x013310u:
				d7 = falling_missile_fall(d7, object);
				break;
			case 0x013340u:
				falling_missile_explode(object);
				break;
			case 0x0134B6u:
				flying_drone_enter(object, &d7, &a5);
				break;
			case 0x0135B4u:
				flying_drone_fly(object, &d7, &a5);
				break;
			case 0x01360Cu:
				flying_drone_fire(object, &d7, &a5);
				break;
			case 0x013656u:
				d7 = flying_drone_struck(d7, object);
				break;
			case 0x0136BAu:
				d7 = flying_drone_recover(object);
				break;
			case 0x0136EAu:
				flying_drone_destroyed(object);
				break;
			case 0x013AFCu:
				d7 = drone_shot_start(object);
				break;
			case 0x013B8Au:
				d7 = drone_shot_flash(d7, object);
				break;
			case 0x013BB6u:
				d7 = drone_shot_fly(object);
				break;
			case 0x013C0Cu:
				drone_shot_vanish(object);
				break;
			case 0x013C32u:
				stockman_enter(d0, object, p_d5, &d7, &a5);
				break;
			case 0x013DA8u:
				stockman_fly(object, p_d5, &d7, &a5);
				break;
			case 0x013E36u:
				stockman_drop_mouser(object, p_d5, &d7, &a5);
				break;
			case 0x013E64u:
				stockman_idle();
				break;
			case 0x013E66u:
				d7 = stockman_struck(d7, object);
				break;
			case 0x013EC0u:
				stockman_recover(object, p_d5, &d7, &a5);
				break;
			case 0x013EF4u:
				stockman_defeated(object, &d7, &a5);
				break;
			case 0x014336u:
				falling_mouser_start(object);
				break;
			case 0x014366u:
				d7 = falling_mouser_fall(d7, object);
				break;
			case 0x0143BAu:
				falling_mouser_idle();
				break;
			case 0x0143BCu:
				falling_mouser_struck(object);
				break;
			case 0x01832Au:
				remove_object(object);
				break;
			case 0x0489E2u:
				enemy_foot_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x048A60u:
				enemy_enter(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x048A94u:
				enemy_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x048D8Au:
				enemy_attack(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x048DBAu:
				enemy_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x048EDAu:
				enemy_react(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x048F02u:
				enemy_step_over_edge(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04A744u:
				boss_shutter_start(object, &d7, &a5);
				break;
			case 0x04A76Au:
				d7 = boss_shutter_wait(d7, object);
				break;
			case 0x04A7AAu:
				d7 = boss_shutter_open(d7, object);
				break;
			case 0x04A7F8u:
				scenery_lamp_start(object);
				break;
			case 0x04A814u:
				scenery_stay();
				break;
			case 0x04A830u:
				scenery_open_manhole_start(object);
				break;
			case 0x04A856u:
				scenery_gone_off_screen(object);
				break;
			case 0x04A880u:
				scenery_chair_start(object);
				break;
			case 0x04A8E6u:
				scenery_fire_start(object);
				break;
			case 0x04A97Eu:
				foot_car_start(object);
				break;
			case 0x04A9B6u:
				foot_car_drive(object);
				break;
			case 0x04AA82u:
				falling_debris_start(object);
				break;
			case 0x04AAAAu:
				falling_debris_wait(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04AAE4u:
				d7 = falling_debris_fall(d7, object);
				break;
			case 0x04AB2Au:
				falling_debris_burn(object);
				break;
			case 0x04AB5Eu:
				d7 = motorbike_start(d7, object);
				break;
			case 0x04ABCAu:
				motorbike_ride(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04AC0Eu:
				motorbike_ride_off(object);
				break;
			case 0x04AC22u:
				motorbike_struck(object, &d7, &a5);
				break;
			case 0x04ACB0u:
				enemy_sword_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04AD3Cu:
				enemy_hammer_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04B7F8u:
				whip_arm_start(d0, object, &d7, &a1);
				break;
			case 0x04B828u:
				whip_arm_follow(d0, object, &d7, &a1);
				break;
			case 0x04B88Eu:
				whip_arm_let_go(object, &d7, &a1);
				break;
			case 0x04B89Eu:
				whip_arm_drag(object, &d7, &a1);
				break;
			case 0x04B900u:
				whip_arm_struck(d0, object, &d7, &a1);
				break;
			case 0x04B9C2u:
				laser_bolt_start(object);
				break;
			case 0x04BA04u:
				laser_bolt_fly(object);
				break;
			case 0x04BA34u:
				laser_bolt_vanish(object);
				break;
			case 0x04BA56u:
				rolling_manhole_cover_start(object);
				break;
			case 0x04BAB2u:
				rolling_wait_hittable(object);
				break;
			case 0x04BAC4u:
				rolling_roll(object);
				break;
			case 0x04BAE8u:
				d7 = rolling_struck(d7, object);
				break;
			case 0x04BB32u:
				knife_start(object);
				break;
			case 0x04BB88u:
				knife_fly(object);
				break;
			case 0x04BBB6u:
				knife_vanish(object);
				break;
			case 0x04BBD8u:
				d7 = knife_struck(d7, object);
				break;
			case 0x04BC0Eu:
				spear_start(object);
				break;
			case 0x04BC50u:
				spear_fly(object);
				break;
			case 0x04BC60u:
				spear_vanish(object);
				break;
			case 0x04BC6Eu:
				d7 = spear_struck(d7, object);
				break;
			case 0x04BC98u:
				axe_start(object);
				break;
			case 0x04BCEEu:
				axe_fly(object);
				break;
			case 0x04BD2Cu:
				gun_shot_start(object);
				break;
			case 0x04BD78u:
				gun_shot_fly(object);
				break;
			case 0x04BD9Eu:
				gun_shot_vanish(object);
				break;
			case 0x04BDC0u:
				d7 = gun_shot_struck(d7, object);
				break;
			case 0x04BE12u:
				boomerang_start(object);
				break;
			case 0x04BE5Au:
				boomerang_fly_out(object);
				break;
			case 0x04BE92u:
				boomerang_fly_back(object);
				break;
			case 0x04BEBAu:
				boomerang_fly_on(object);
				break;
			case 0x04BECEu:
				d7 = boomerang_struck(d7, object);
				break;
			case 0x04BEE8u:
				boomerang_vanish(object);
				break;
			case 0x04BF0Au:
				shuriken_start(object);
				break;
			case 0x04BF4Cu:
				shuriken_fly(object);
				break;
			case 0x04BF96u:
				shuriken_vanish(object);
				break;
			case 0x04BFA4u:
				d7 = shuriken_struck(d7, object);
				break;
			case 0x04BFE6u:
				rocksteady_bullet_start(object, p_d5, &d7, &a5);
				break;
			case 0x04C054u:
				rocksteady_bullet_fly(object);
				break;
			case 0x04C078u:
				rocksteady_bullet_vanish(object);
				break;
			case 0x04C0AEu:
				bebop_shot_start(object);
				break;
			case 0x04C0F0u:
				bebop_shot_fly(object);
				break;
			case 0x04C11Au:
				rolling_tire_start(object);
				break;
			case 0x04C17Cu:
				shredder_piece_start(object);
				break;
			case 0x04C1B6u:
				d7 = shredder_piece_bounce(d7, object);
				break;
			case 0x04C204u:
				shredder_ray_start(object);
				break;
			case 0x04C23Cu:
				shredder_ray_shine(object);
				break;
			case 0x04C264u:
				rocket_start(object);
				break;
			case 0x04C2CEu:
				d7 = rocket_fly(d7, object);
				break;
			case 0x04C30Cu:
				rocket_explode(object);
				break;
			case 0x04C32Au:
				dynamite_start(object);
				break;
			case 0x04C35Eu:
				dynamite_throw(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04C386u:
				d7 = dynamite_bounce(d7, object);
				break;
			case 0x04C3F2u:
				dynamite_explode(object);
				break;
			case 0x04C4E6u:
				kicked_door_start(object);
				break;
			case 0x04C4FCu:
				d7 = kicked_door_wait(d7, object);
				break;
			case 0x04C522u:
				kicked_door_break(object, &d7, &a5);
				break;
			case 0x04C552u:
				kicked_door_become_foot_soldier(object);
				break;
			case 0x04C5F4u:
				door_piece_start(object, &d7, &a5);
				break;
			case 0x04C63Au:
				door_piece_fly(object);
				break;
			case 0x04C6E8u:
				elevator_start(object);
				break;
			case 0x04C716u:
				a1 = elevator_wait_on_screen(object);
				break;
			case 0x04C730u:
				elevator_open(object, &d7, &a5);
				break;
			case 0x04C784u:
				elevator_scroll_off(object);
				break;
			case 0x04C89Cu:
				tire_soldier_start(object);
				break;
			case 0x04C8E0u:
				tire_soldier_wait(object);
				break;
			case 0x04C906u:
				tire_soldier_jump(object);
				break;
			case 0x04C936u:
				d7 = tire_soldier_fly(d7, object);
				break;
			case 0x04C964u:
				tire_soldier_throw(object, &d7, &a5);
				break;
			case 0x04C9C6u:
				manhole_soldier_start(object);
				break;
			case 0x04CA06u:
				manhole_soldier_wait(object);
				break;
			case 0x04CA2Cu:
				manhole_soldier_jump_out(object, &d7, &a5);
				break;
			case 0x04CA68u:
				manhole_soldier_fly(object);
				break;
			case 0x04CA98u:
				manhole_soldier_throw(object, &d7, &a5);
				break;
			case 0x04CAD2u:
				thrower_become_foot_soldier(object);
				break;
			case 0x04CBFCu:
				a5 = window_soldier_drop_start(object);
				break;
			case 0x04CC2Eu:
				window_soldier_drop_jump_out(object, &d7, &a5);
				break;
			case 0x04CC76u:
				window_soldier_drop_break_window(object, &d7, &a5);
				break;
			case 0x04CCA0u:
				window_soldier_drop_fall(object);
				break;
			case 0x04CCECu:
				window_soldier_become_foot_soldier(object);
				break;
			case 0x04CD80u:
				window_soldier_dive_start(object);
				break;
			case 0x04CDAAu:
				window_soldier_dive_wait(object, &d7, &a5);
				break;
			case 0x04CE06u:
				window_soldier_dive_fall(object);
				break;
			case 0x04CECAu:
				d7 = glass_shards_start(d7, object);
				break;
			case 0x04CF10u:
				glass_shards_fall(object);
				break;
			case 0x04D1AEu:
				sewer_ripple_start(object);
				break;
			case 0x04D1DEu:
				d7 = sewer_ripple_swim(d7, object);
				break;
			case 0x04D24Cu:
				sewer_ripple_leap_out(object, &d7, &a5);
				break;
			case 0x04D288u:
				sewer_ripple_vanish(object);
				break;
			case 0x04D2A6u:
				sewer_ripple_swim_again(object);
				break;
			case 0x04D46Cu:
				bomber_start(object, &d7, &a5);
				break;
			case 0x04D488u:
				bomber_wait(object);
				break;
			case 0x04D4B0u:
				bomber_lean_out(object);
				break;
			case 0x04D4D0u:
				bomber_throw(object, &d7, &a5);
				break;
			case 0x04D4FEu:
				bomber_step_out(object);
				break;
			case 0x04D52Cu:
				bomber_walk_in(object);
				break;
			case 0x04D564u:
				enemy_rocket_soldier_start(object);
				break;
			case 0x04D58Eu:
				enemy_rocket_soldier_line_up(object, p_d5, &d7, &a5);
				break;
			case 0x04D5EEu:
				enemy_rocket_soldier_fire(object, &d7, &a5);
				break;
			case 0x04D624u:
				enemy_rocket_soldier_unarmed(object);
				break;
			case 0x04D64Cu:
				enemy_rocket_soldier_struck(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04D6C8u:
				double_door_start(object);
				break;
			case 0x04D6CEu:
				double_door_wait(object, &d7, &a5);
				break;
			case 0x04D722u:
				d7 = double_door_open(d7, object);
				break;
			case 0x04D76Cu:
				technodrome_door_start(object);
				break;
			case 0x04D782u:
				technodrome_door_wait(object, &d7, &a5);
				break;
			case 0x04D7D0u:
				technodrome_door_open(object);
				break;
			case 0x04D7E8u:
				technodrome_door_let_out(object, &d7, &a5);
				break;
			case 0x04DC04u:
				enemy_knife_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04DC9Eu:
				enemy_spear_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04E6A2u:
				enemy_axe_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04E736u:
				enemy_gun_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04EE2Eu:
				enemy_boomerang_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04EEC8u:
				enemy_shuriken_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04EF58u:
				enemy_skateboard_soldier_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04EFECu:
				enemy_skateboard_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F002u:
				enemy_skateboard_attack(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F014u:
				enemy_skateboard_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F026u:
				enemy_skateboard_react(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F1D2u:
				enemy_rocksteady_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x04F28Au:
				enemy_rocksteady_enter(object, a1, p_d5, &d7, &a5);
				break;
			case 0x04F3BAu:
				enemy_rocksteady_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F5E4u:
				enemy_rocksteady_attack(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F622u:
				enemy_rocksteady_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x04F680u:
				enemy_rocksteady_react(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x0501C6u:
				enemy_bebop_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x05027Au:
				enemy_bebop_enter(object, a1, p_d5, &d7, &a5);
				break;
			case 0x0503ECu:
				enemy_bebop_think(d0, object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x050612u:
				enemy_bebop_attack(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x050622u:
				enemy_bebop_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x05066Eu:
				enemy_bebop_react(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x050F98u:
				enemy_mouser_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x051002u:
				enemy_mouser_enter(object, a1, p_d5, &d7, &a5);
				break;
			case 0x0510F4u:
				enemy_mouser_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x051314u:
				enemy_mouser_bite(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x05144Eu:
				enemy_mouser_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x051492u:
				enemy_mouser_step_over_edge(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x051B56u:
				mouser_hole_start(object);
				break;
			case 0x051BA2u:
				d7 = mouser_hole_wait(d7, object);
				break;
			case 0x051BDAu:
				mouser_hole_open(object);
				break;
			case 0x051BF4u:
				mouser_hole_let_out(object, &d7, &a5);
				break;
			case 0x051C44u:
				enemy_rodney_start(object, a6, p_d5, &d7, &a5);
				break;
			case 0x051CACu:
				enemy_rodney_enter(object, a1, p_d5, &d7, &a5);
				break;
			case 0x051D80u:
				enemy_rodney_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x051FA0u:
				enemy_rodney_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x052790u:
				enemy_shredder_start(object, a1, a6, p_d5, &d7, &a5);
				break;
			case 0x052830u:
				enemy_shredder_enter(object, a1, p_d5, &d7, &a5);
				break;
			case 0x052840u:
				enemy_shredder_think(object, a6, p_d5, &d7, &a1, &a5);
				break;
			case 0x052B84u:
				enemy_shredder_attack(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x052BC8u:
				enemy_shredder_hit(object, p_d5, &d7, &a1, &a5);
				break;
			case 0x052C68u:
				enemy_shredder_react(object, p_d5, &d7, &a1, &a5);
				break;
			}
			update_object_screen_place(object);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(40));
	*p_d7 = d7;
	*p_a1 = a1;
}

/* every frame: the players' slots counted and the least crowded one found */
uint32_t update_player_slots(void)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint16_t d1 = 0, d6 = 0;
	uint32_t d0_2 = 0, object = 0, player_slot = 0;
	uint16_t t1 = 0;

	player_slot = PLAYER_SLOT_ADDRESS(0);
	d6 = 3u;
	d1 = 0u;
	d0 = 0xFFu;
	do
	{
		object = PLAYER_SLOT(player_slot)->turtle;
		if (OBJECT(object)->flags != 0u)
		{
			OBJECT(object)->unk_44 = 0u;
			d1++;
			if (PLAYER_SLOT(player_slot)->enemies < (uint8_t)d0)
			{
				d0 = PLAYER_SLOT(player_slot)->enemies;
				least_crowded_slot = player_slot;
				if (PLAYER_SLOT(player_slot)->grab_time != 0u)
					PLAYER_SLOT(player_slot)->grab_time--;
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		player_slot += 0x10u;
	} while (t1 != 0xFFFFu);
	d0_2 = 0u;
	turtles_in_play = (uint8_t)d1;
	if ((uint8_t)d1 == 0u)
	{
		enemies_per_turtle = d0_2;
		return object;
	}
	d0_2 = enemies_on_screen;
	zero = m68k_divu_z(d0_2, d1);
	d0_2 = d1 == 0u ? d0_2 : m68k_divu(d0_2, d1);
	if (d1 == 0u)
		exception_hang();
	if (zero)
		d0_2 = (uint16_t)(d0_2 + 1u);
	enemies_per_turtle = d0_2;
	return object;
}

/* the object's place on the screen from its place in the area, and whether it is off the screen */
void update_object_screen_place(uint32_t a0)
{
	uint16_t d0 = 0, d1 = 0, d2 = 0;
	uint32_t a4 = 0;

	if (OBJECT(a0)->flags != 0u)
	{
		d0 = (uint16_t)(((int32_t)(OBJECT(a0)->x - (spawn_x & ~0xFFu)) >> 8) + 0x1A0u);
		OBJECT(a0)->screen_x = d0;
		d2 = (uint16_t)(((int32_t)(OBJECT(a0)->y - (spawn_y & ~0xFFu)) >> 8) + 0x100u);
		OBJECT(a0)->screen_y = d2;
		OBJECT(a0)->flags &= 0xDFu;
		a4 = spawn_offsets_ADDRESS + (int16_t)((uint32_t)(int8_t)OBJECT(a0)->kind << 2);
		d1 = (uint16_t)d0;
		if ((int16_t)(d0 - mem_read16(a4)) >= 0x1C0 || (int16_t)(d1 + mem_read16(a4)) < 0x40 || (int16_t)d2 >= 0x120 || (int16_t)(d2 + mem_read16(a4 + 2u)) < -0x20)
		{
			OBJECT(a0)->flags |= 0x20u;
			return;
		}
	}
}

uint32_t set_animation(uint32_t d1, uint32_t a0, uint32_t animation)
{
	uint32_t d1_2 = 0;

	d1_2 = (d1 & ~0xFFu) | ANIMATION_FRAME(animation)->time;
	d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + OBJECT(a0)->animation_delay);
	OBJECT(a0)->frame_time = d1_2;
	OBJECT(a0)->frame = animation;
	return d1_2;
}

/* the first free object of a group */
void take_free_object_in_group(uint16_t d0, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t d7 = 0;
	uint32_t object = 0;
	uint8_t flags = 0;
	uint16_t t1 = 0;

	d0 &= 3u;
	d7 = object_group_counts[d0];
	object = object_groups[d0 & 0x3FFFu];
	do
	{
		flags = OBJECT(object)->flags;
		zero = flags == 0u;
		if (flags == 0u)
			break;
		t1 = d7 - 1u;
		d7 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a6 = object;
	*p_zero = zero;
}

/* an object started from a record, placed by the object that starts it */
void start_object_from_record(uint32_t a0, uint32_t a5, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint8_t d0 = 0;
	uint32_t d7 = 0, started = 0;
	uint32_t kind_halfword = 0;

	d0 = mem_read8(a5 + 5u);
	take_free_object_in_group(d0, &d7, &started, &zero);
	if (zero)
	{
		OBJECT(started)->flags = 1u;
		OBJECT(started)->contacts = 0u;
		kind_halfword = mem_read16(a5 + 6u);
		OBJECT(started)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(started)->parameter = (uint8_t)kind_halfword;
		OBJECT(started)->routine = 0u;
		OBJECT(started)->state = 0u;
		OBJECT(started)->colour = 0xFFu;
		OBJECT(started)->animation_delay = 0u;
		OBJECT(started)->throw = 0u;
		zero = place_from_record(a0, a5, started);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a6 = started;
	*p_zero = zero;
}

/* a shot started from a record, placed by its shooter */
void start_shot(uint32_t a0, uint32_t a5, uint32_t *p_d7, uint32_t *p_a6, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint8_t d0 = 0;
	uint32_t d7 = 0, shot = 0;

	d0 = 3u;
	take_free_object_in_group(d0, &d7, &shot, &zero);
	if (zero)
	{
		OBJECT(shot)->flags = 1u;
		OBJECT(shot)->contacts = 0u;
		OBJECT(shot)->kind = mem_read8(a5 + 5u);
		OBJECT(shot)->parameter = 0u;
		OBJECT(shot)->routine = 0u;
		OBJECT(shot)->state = 0u;
		OBJECT(shot)->colour = 0xFFu;
		OBJECT(shot)->animation_delay = 0u;
		OBJECT(shot)->throw = 0u;
		OBJECT(shot)->start_shot.hit_sound = OBJECT(a0)->start_shot.hit_sound;
		zero = place_from_record(a0, a5, shot);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a6 = shot;
	*p_zero = zero;
}

/* an object placed by a record's offsets from another, mirrored with it */
uint32_t place_from_record(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint32_t zero = 0;
	uint16_t d1 = 0;

	d1 = mem_read16(a5);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(a6)->flags |= 0x40u;
		d1 = (uint16_t)(0u - d1);
	}
	OBJECT(a6)->x = ((uint32_t)(int16_t)d1 << 8) + OBJECT(a0)->x;
	OBJECT(a6)->y = ((uint32_t)(int16_t)mem_read16(a5 + 2u) << 8) + OBJECT(a0)->y;
	OBJECT(a6)->height_whole = mem_read8(a5 + 4u) + OBJECT(a0)->height_whole;
	zero = 1u;
	OBJECT(a6)->height &= 0xFF00u;
	return zero;
}

/* the speeds across and up or down of a speed in a direction */
void speeds_from_direction(uint8_t d0, uint16_t d1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
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

/* the direction from the object to another one */
uint32_t direction_to_object(uint32_t d0, uint32_t a0, uint32_t a6)
{
	uint32_t d1 = 0, d2 = 0;

	d1 = OBJECT(a6)->screen_x;
	d2 = OBJECT(a6)->screen_y;
	direction_to(a0, &d0, &d1, &d2);
	return d0;
}
