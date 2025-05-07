#pragma once

#include "elden_ring/elden_ring_event_flags.hpp"
#include "elden_ring/elden_ring_items.hpp"

namespace er
{
	GameDataMan *GetGameDataMan();
	MapItemMan *GetMapItemMan();
	EventFlagMan *GetEventFlagMan();
	WorldChrMan *GetWorldChrMan();
	ChrModules *GetLocalModules();
	CameraMatrix *GetCameraMatrix();
	bool InGame();
}