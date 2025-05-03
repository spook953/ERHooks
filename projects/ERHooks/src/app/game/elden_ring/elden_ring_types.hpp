#pragma once

#include "elden_ring_bin.hpp"

namespace er
{
	enum class ItemType : uint8_t
	{
		Weapon,
		Protector,
		Accessory,
		Good,
		Gem
	};

	constexpr uint32_t item_type_hex[5]
	{
		0x00000000, // Weapon
		0x10000000, // Protector
		0x20000000, // Accessory
		0x40000000, // Good
		0x80000000  // Gem
	};
}

namespace er
{
	class DLUserInputDevice
	{
	public:

	};

	class DLUserInputDeviceImpl : public DLUserInputDevice
	{
	public:
		void ResetInput() {
			MemUtils::GetVirtual(this, 43).Call<void *>(this); // ret void * ?
		}
	};

	class KeyboardDevice final : public DLUserInputDeviceImpl
	{
	public:

	};

	class MouseDevice final : public DLUserInputDeviceImpl
	{
	public:
		MAKE_MEMBER(vec3_t, m_move_delta, 2048);
	};

	class ChrStats
	{
	public:
		MAKE_MEMBER(int32_t, m_vigor, 0);
		MAKE_MEMBER(int32_t, m_mind, 4);
		MAKE_MEMBER(int32_t, m_endurance, 8);
		MAKE_MEMBER(int32_t, m_strength, 12);
		MAKE_MEMBER(int32_t, m_dexterity, 16);
		MAKE_MEMBER(int32_t, m_intelligence, 20);
		MAKE_MEMBER(int32_t, m_faith, 24);
		MAKE_MEMBER(int32_t, m_arcane, 28);
		MAKE_MEMBER(int32_t, m_level, 44);
		MAKE_MEMBER(int8_t, m_scadutree_blessing, 192);
		MAKE_MEMBER(int8_t, m_revered_spirit_ash_blessing, 193);
	};

	class ChrGameData
	{
	public:
		MAKE_MEMBER(ChrStats, m_stats, 60);
	};

	class GameDataMan
	{
	public:
		MAKE_MEMBER(ChrGameData *, m_chr_data, 8);
	};

	class MapItemMan
	{
	public:
		void GiveItem(const ItemType type, const uint32_t id, const uint32_t quantity)
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

			const item_t item {
				.item_id = id | item_type_hex[static_cast<int>(type)],
				.quantity = static_cast<int32_t>(quantity)
			};

			const uint8_t tmp[100]{};

			bin::MapItemMan_GiveItem.Call<void>(this, &item, tmp, 0);
		}
	};
}