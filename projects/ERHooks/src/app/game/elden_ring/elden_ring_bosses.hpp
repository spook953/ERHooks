#pragma once

#include "elden_ring_types.hpp"

namespace er::bosses
{
	using boss_map_t = std::vector<std::pair<std::string, std::vector<std::pair<uint32_t, std::string>>>>;

	const boss_map_t &GetBaseBosses();
	const boss_map_t &GetDLCBosses();
}