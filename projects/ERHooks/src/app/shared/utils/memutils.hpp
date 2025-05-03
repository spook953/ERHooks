#pragma once

#include <Windows.h>
#include <Psapi.h>

#include <string>
#include <vector>

#include "memaddr.hpp"

class MemUtils final
{
private:
	static std::vector<uint8_t> IDAPatToBytes(std::string_view pat);

public:
	static bool GetModInfo(std::string_view mod_name, MODULEINFO &mod_info);

public:
	static MemAddr GetExport(std::string_view mod_name, std::string_view exp_name);
	static MemAddr GetVirtual(void *const vtable, const size_t vidx);
	static MemAddr FindPatRange(const uintptr_t start, const size_t size, std::string_view pat);
	static MemAddr FindPatMod(std::string_view mod_name, std::string_view pat);
};