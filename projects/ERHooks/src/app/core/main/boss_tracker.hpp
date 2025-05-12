#pragma once

#include "menu.hpp"

class BossTracker final
{
private:
	static void DrawProgress(const er::bosses::boss_map_t &data, std::string_view name);

public:
	static void Run();
};