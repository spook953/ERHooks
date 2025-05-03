#pragma once

#include "core/hooks.hpp"

class App final
{
private:
	static bool LoadAddresses();
	static bool LoadHooks();

public:
	static bool Load();
	static void Unload();
};