#include "elden_ring_types.hpp"

void er::DLUserInputDeviceImpl::ResetInput()
{
	MemUtils::GetVirtual(this, 43).Call<void *>(this);
}

void er::MapItemMan::GiveItem(const ItemType type, const uint32_t id, const uint32_t quantity)
{
	// shoutouts to the guys @ ?ServerName?

	struct item_t
	{
		int32_t count{ 1 };
		uint32_t item_id{};
		int32_t quantity{};
		int32_t unk{ -1 };
		int32_t gem_id{ -1 };
	};

	constexpr uint32_t item_type[5]
	{
		0x00000000, // Weapon
		0x10000000, // Protector
		0x20000000, // Accessory
		0x40000000, // Good
		0x80000000  // Gem
	};

	const item_t item{
		.item_id = id | item_type[static_cast<int>(type)],
		.quantity = static_cast<int32_t>(quantity)
	};

	const uint8_t tmp[100]{};

	bin::MapItemMan_GiveItem.Call<void>(this, &item, tmp, 0);
}

void er::EventFlagMan::SetFlag(const uint32_t flag, const bool val)
{
	bin::EventFlagMan_SetFlag.Call<uint32_t>(this, flag, val ? 1 : 0);
}

bool er::EventFlagMan::GetFlag(const uint32_t flag)
{
	return bin::EventFlagMan_GetFlag.Call<uint32_t>(this, flag) != 0;
}