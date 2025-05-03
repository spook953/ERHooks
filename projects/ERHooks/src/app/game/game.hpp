#pragma once

#include "elden_ring/elden_ring_items.hpp"
#include "elden_ring/elden_ring_types.hpp"

namespace er
{
	inline GameDataMan *GetGameDataMan() {
		return bin::GameDataMan.As<GameDataMan *>();
	}

	inline MapItemMan *GetMapItemMan() {
		return MemAddr{ bin::MapItemMan }.Deref().As<MapItemMan *>();
	}

	inline bool InGame()
	{
		// todo : use some actual flag to check this

		return GetMapItemMan() != nullptr;
	}
}