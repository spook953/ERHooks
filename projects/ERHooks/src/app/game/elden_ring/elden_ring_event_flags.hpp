#pragma once

#include "elden_ring_types.hpp"

namespace er::event_flags
{
	using event_flag_map_t = std::map<uint32_t, std::string>;

	const event_flag_map_t &GetGraceMap();
	const event_flag_map_t &GetMapPieceMap();
	const event_flag_map_t &GetCookBookMap();
}