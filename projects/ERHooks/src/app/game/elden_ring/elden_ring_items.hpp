#pragma once

#include "elden_ring_types.hpp"

namespace er::items
{
	using item_map_t = std::map<std::uint32_t, std::string>;

	const item_map_t &GetWeaponMap();
	const item_map_t &GetProtectorMap();
	const item_map_t &GetAccessoryMap();
	const item_map_t &GetGoodsMap();
	const item_map_t &GetGemMap();
}