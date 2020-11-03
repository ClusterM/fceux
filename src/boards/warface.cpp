/* FCE Ultra - NES/Famicom Emulator
*
* Copyright notice for this file:
*  Copyright (C) 2020 Cluster
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "mapinc.h"

static uint8 prg_bank = 0;
static uint8 chr_bank = 0;

static void WARFACE_Sync(void) {
	setprg16(0x8000, prg_bank);
	setprg16(0xC000, ~0);

	if (chr_bank & 0x80)
	{
		if (scanline < 64)
			setchr4(0x0000, (chr_bank & 0x1C) | 0);
		else if (scanline < 128)
			setchr4(0x0000, (chr_bank & 0x1C) | 1);
		else if (scanline < 192)
			setchr4(0x0000, (chr_bank & 0x1C) | 2);
		else
			setchr4(0x0000, (chr_bank & 0x1C) | 3);
	}
	else {
		setchr4(0x0000, chr_bank & 0x1F);
	}
	setchr4(0x1000, ~0);
}

static DECLFW(WARFACE_WRITE) {
	if ((A & 1) == 0)
	{
		prg_bank = V;
	}
	else {
		chr_bank = V;
	}

	WARFACE_Sync();
}

static void WARFACE_ScanlineCounter(void) {
	WARFACE_Sync();
}

static void WARFACE_Reset(void) {	
	WARFACE_Sync();
}

static void WARFACE_Power(void) {
	SetReadHandler(0x8000, 0xFFFF, CartBR);
	SetWriteHandler(0x6000, 0x7FFF, WARFACE_WRITE);
	GameHBIRQHook = WARFACE_ScanlineCounter;
	WARFACE_Reset();
}

static void WARFACE_Restore(int version) {
	WARFACE_Sync();
}

void WARFACE_Init(CartInfo *info) {
	AddExState(&prg_bank, sizeof(prg_bank), 0, "PRGL");
	AddExState(&chr_bank, sizeof(chr_bank), 0, "CHRL");
	info->Power = WARFACE_Power;
	info->Reset = WARFACE_Reset;
	GameStateRestore = WARFACE_Restore;
}
