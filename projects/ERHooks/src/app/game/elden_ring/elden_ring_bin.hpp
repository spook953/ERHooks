#pragma once

#include "../../sdk/sdk.hpp"

MAKE_ADDR
(
	er::bin,

	CDXGISwapChain,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 0D ? ? ? ? 48 85 C9 74 17 B8 ? ? ? ? 89 44 24 20 80 B9 ? ? ? ? ?"
	)

	.Rip(3).Deref().Offset(0x90).Deref().Offset(0x30).Deref().Offset(0x60).Deref().Offset(0x110).Deref().Offset(0x8).Deref().Offset(0x10).Deref()
);

MAKE_ADDR
(
	er::bin,

	CD3D12CommandQueue,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 0D ? ? ? ? 0F 57 D2 66 0F 6E 44 24 ? 0F 57 C9 0F 5B C0"
	)

	.Rip(3).Deref().Offset(0x8).Deref().Offset(0x8).Deref()
);

MAKE_ADDR
(
	er::bin,

	WndProc,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 89 5C 24 ? 4C 89 4C 24 ? 4C 89 44 24 ? 89 54 24 10 55 48 8B EC"
	)
);

MAKE_ADDR
(
	er::bin,

	KeyboardDevice_UpdateInput,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"40 53 48 83 EC 20 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9 74 5C 80 BB ? ? ? ? ?"
	)
);

MAKE_ADDR
(
	er::bin,

	MouseDevice_UpdateInput,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"40 53 48 83 EC 20 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9 75 08 32 C0 48 83 C4 20 5B C3 80 BB ? ? ? ? ?"
	)
);

MAKE_ADDR
(
	er::bin,

	GameDataMan,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 05 ? ? ? ? C6 80 ? ? ? ? ? 80 BF ? ? ? ? ?"
	)

	.Rip(3).Deref()
);

MAKE_ADDR
(
	er::bin,

	MapItemMan,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 0D ? ? ? ? 45 33 C9 4C 8B C3 41 8D 51 04"
	)

	.Rip(3)
);

MAKE_ADDR
(
	er::bin,

	MapItemMan_GiveItem,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"E8 ? ? ? ? 83 7D 98 00 74 68"
	)

	.Rip(1)
);


MAKE_ADDR
(
	er::bin,

	EventFlagMan,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 1D ? ? ? ? 49 8B F0 48 8B F9"
	)

	.Rip(3).Deref()
);

MAKE_ADDR
(
	er::bin,

	EventFlagMan_SetFlag,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 89 5C 24 ? 44 8B 49 1C"
	)
);

MAKE_ADDR
(
	er::bin,

	EventFlagMan_GetFlag,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"44 8B 41 1C 44 8B DA"
	)
);

MAKE_ADDR
(
	er::bin,

	PostProcessFunc,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"E8 ? ? ? ? 4D 8D B7 ? ? ? ? 49 8B CE"
	)

	.Rip(1)
);

MAKE_ADDR
(
	er::bin,

	WorldChrMan,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"48 8B 0D ? ? ? ? 48 85 C9 74 62 48 8B 89 ? ? ? ? 48 85 C9 74 56"
	)

	.Rip(3)
);

MAKE_ADDR
(
	er::bin,

	CameraMatrix,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"B9 ? ? ? ? 48 23 C1 48 3D ? ? ? ? 75 47 48 8B 0D ? ? ? ? 48 85 C9 75 2E"
	)

	.Offset(16).Rip(3)
);

MAKE_ADDR
(
	er::bin,

	UpdatePhysicsFunc,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"E8 ? ? ? ? 48 8D 4B 10 E8 ? ? ? ? EB 6E"
	)

	.Rip(1)
);

MAKE_ADDR
(
	er::bin,

	ChrDeathFunc,

	MemUtils::FindPatMod(
		"eldenring.exe",
		"E8 ? ? ? ? 84 C0 75 68 48 8B 0B"
	)

	.Rip(1)
);