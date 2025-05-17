#pragma once

#include "menu.hpp"

class Status final
{
private:
	static inline std::vector<std::string> status_strs{};

public:
	static void Run();
};