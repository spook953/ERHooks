#pragma once

#include "elden_ring/elden_ring_graces.hpp"
#include "elden_ring/elden_ring_items.hpp"

namespace er
{
	inline GameDataMan *GetGameDataMan() {
		return bin::GameDataMan.As<GameDataMan *>();
	}

	inline MapItemMan *GetMapItemMan() {
		return MemAddr{ bin::MapItemMan }.Deref().As<MapItemMan *>();
	}

	inline EventFlagMan *GetEventFlagMan() {
		return bin::EventFlagMan.As<EventFlagMan *>();
	}

	inline bool InGame()
	{
		// todo : use some actual flag to check this

		return GetMapItemMan() != nullptr;
	}
}