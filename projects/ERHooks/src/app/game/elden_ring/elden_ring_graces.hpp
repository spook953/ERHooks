#pragma once

#include "elden_ring_types.hpp"

namespace er::graces
{
	using grace_map_t = std::map<uint32_t, std::string>;

	const grace_map_t &GetGraceMap();
}