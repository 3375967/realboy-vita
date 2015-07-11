/* RealBoy Emulator: Free, Fast, Yet Accurate, Game Boy/Game Boy Color Emulator.
 * Copyright (C) 2013 Sergio Andrés Gómez del Real
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "gboy.h"
#include "gboy_events_vita.h"

long key_bitmap = 0;
static SceCtrlData pad;

static const struct {
	int vita, gb;
} key_map[] = {
	{PSP2_CTRL_CROSS,  D_MASK},
	{PSP2_CTRL_CIRCLE, S_MASK},
	{PSP2_CTRL_SELECT, A_MASK},
	{PSP2_CTRL_START,  RET_MASK},
	{PSP2_CTRL_UP,     UP_MASK},
	{PSP2_CTRL_DOWN,   DOWN_MASK},
	{PSP2_CTRL_LEFT,   LEFT_MASK},
	{PSP2_CTRL_RIGHT,  RIGHT_MASK},
};

int
joy_remap(char key_ascii, int key_remap)
{
	return 0;
}

long
proc_evts()
{
	int i;
	sceCtrlPeekBufferPositive(0, &pad, 1);

	key_bitmap = 0;

	for (i = 0; i < sizeof(key_map)/sizeof(*key_map); i++) {
		if (pad.buttons & key_map[i].vita) {
			key_bitmap |= key_map[i].gb;
		}
	}

	return 0;
}