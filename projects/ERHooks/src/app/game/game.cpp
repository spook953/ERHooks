#include "game.hpp"

er::GameDataMan *er::GetGameDataMan()
{
	return bin::GameDataMan.As<GameDataMan *>();
}

er::MapItemMan *er::GetMapItemMan()
{
	return MemAddr{ bin::MapItemMan }.Deref().As<MapItemMan *>();
}

er::EventFlagMan *er::GetEventFlagMan()
{
	return bin::EventFlagMan.As<EventFlagMan *>();
}

er::WorldChrMan *er::GetWorldChrMan()
{
	return MemAddr{ bin::WorldChrMan }.Deref().As<WorldChrMan *>();
}

er::ChrModules *er::GetLocalModules()
{
	WorldChrMan *const world_chr_man{ er::GetWorldChrMan() };

	if (!world_chr_man) {
		return nullptr;
	}

	LocalPlayerIns *const local_player{ world_chr_man->m_local_player() };

	if (!local_player) {
		return nullptr;
	}

	PlayerIns *const player_ins{ local_player->m_player() };

	if (!player_ins) {
		return nullptr;
	}

	return player_ins->m_modules();
}

er::CameraMatrix *er::GetCameraMatrix()
{
	MemAddr addr{ MemAddr{ bin::CameraMatrix }.Deref() };

	if (!addr) {
		return nullptr;
	}

	addr = addr.Offset(0x1ECE0).Deref();

	if (!addr) {
		return nullptr;
	}

	addr = addr.Offset(0x60).Deref();

	if (!addr) {
		return nullptr;
	}

	return addr.As<CameraMatrix *>();
}

bool er::InGame()
{
	// todo : use some actual flag to check this 

	return GetMapItemMan() != nullptr;
}