#pragma once

#include "elden_ring_types.hpp"

namespace er::event_flags
{
	using event_flag_map_t = std::map<uint32_t, std::string>;

	const event_flag_map_t &GetGraceMap();
	const event_flag_map_t &GetMapPieceMap();
	const event_flag_map_t &GetCookBookMap();
	const event_flag_map_t &GetAffinitiesMap();

	namespace special
	{
		inline uint32_t GetMaleniaFlowerFlag() { return 9120; }
		inline uint32_t GetMaleniaDefeatedFlag() { return 15000800; }
	}
}