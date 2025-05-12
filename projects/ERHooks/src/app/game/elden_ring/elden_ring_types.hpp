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

	class DLUserInputDevice
	{
	public:

	};

	class DLUserInputDeviceImpl : public DLUserInputDevice
	{
	public:
		void ResetInput();
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
		MAKE_MEMBER(int32_t, m_runes, 108);
		MAKE_MEMBER(bool, m_rune_arc_active, 255);
		MAKE_MEMBER(uint32_t, m_great_rune, 1472);
	};

	class GameDataMan
	{
	public:
		MAKE_MEMBER(ChrGameData *, m_chr_data, 8);
		MAKE_MEMBER(uint32_t, m_death_count, 148);
		MAKE_MEMBER(uint32_t, m_play_time_ms, 160);
		MAKE_MEMBER(int32_t, m_journey_nr, 288);
	};

	class MapItemMan
	{
	public:
		void GiveItem(const ItemType type, const uint32_t id, const uint32_t quantity);
	};

	class EventFlagMan
	{
	public:
		void SetFlag(const uint32_t flag, const bool val);
		bool GetFlag(const uint32_t flag);
	};

	class CSCharData
	{
	public:
		MAKE_MEMBER(int, m_flags, 411);
	};

	class CSChrPhysicsModule
	{
	public:
		MAKE_MEMBER(vec3_t, m_pos, 112);
		MAKE_MEMBER(bool, m_on_ground, 146);
	};

	class CSChrFallModule
	{
	public:
		MAKE_MEMBER(float, m_fall_timer, 24);
	};

	class ChrModules
	{
	public:
		MAKE_MEMBER(CSCharData *, m_char_data, 0);
		MAKE_MEMBER(CSChrPhysicsModule *, m_char_physics, 104);
		MAKE_MEMBER(CSChrFallModule *, m_fall, 112);
	};

	class PlayerIns
	{
	public:
		MAKE_MEMBER(ChrModules *, m_modules, 400);
	};

	class LocalPlayerIns
	{
	public:
		MAKE_MEMBER(PlayerIns *, m_player, 0);
	};

	class WorldChrMan
	{
	public:
		MAKE_MEMBER(LocalPlayerIns *, m_local_player, 69368);
	};

	class CameraMatrix
	{
	public:
		MAKE_MEMBER(vec3_t, m_angles, 348);
	};
}