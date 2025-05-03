#include "memutils.hpp"

std::vector<uint8_t> MemUtils::IDAPatToBytes(std::string_view pat)
{
	if (pat.empty()) {
		return {};
	}

	std::vector<uint8_t> bytes{};

	char *const start{ const_cast<char *>(pat.data()) };
	char *const end{ const_cast<char *>(pat.data()) + pat.length() };

	for (char *current{ start }; current < end; ++current)
	{
		if (*current == '?')
		{
			current++;

			if (*current == '?') {
				current++;
			}

			bytes.push_back(-1);
		}

		else {
			bytes.push_back(static_cast<uint8_t>(strtoul(current, &current, 16)));
		}
	}

	return bytes;
}

bool MemUtils::GetModInfo(std::string_view mod_name, MODULEINFO &mod_info)
{
	const HMODULE hmod{ GetModuleHandleA(mod_name.data()) };

	if (!hmod) {
		return false;
	}

	return K32GetModuleInformation(GetCurrentProcess(), hmod, &mod_info, sizeof(MODULEINFO));
}

MemAddr MemUtils::GetExport(std::string_view mod_name, std::string_view exp_name)
{
	const HMODULE mod{ GetModuleHandleA(mod_name.data()) };

	if (!mod) {
		return 0;
	}

	return reinterpret_cast<uintptr_t>(GetProcAddress(mod, exp_name.data()));
}

MemAddr MemUtils::GetVirtual(void *const vtable, const size_t vidx)
{
	return reinterpret_cast<uintptr_t>((*static_cast<void ***>(vtable))[vidx]);
}

MemAddr MemUtils::FindPatRange(const uintptr_t start, const size_t size, std::string_view pat)
{
	if (!start || !size || pat.empty()) {
		return 0;
	}

	const uint8_t *const scan_data{ reinterpret_cast<const uint8_t *>(start) };
	const std::vector<uint8_t> pattern_bytes{ IDAPatToBytes(pat) };

	for (size_t n{}; n <= size - pattern_bytes.size(); n++)
	{
		bool seq_found{ true };

		for (size_t j{}; j < pattern_bytes.size(); j++)
		{
			if (scan_data[n + j] != pattern_bytes[j] && pattern_bytes[j] != static_cast<uint8_t>(-1)) {
				seq_found = false;
				break;
			}
		}

		if (seq_found) {
			return start + n;
		}
	}

	return 0;
}

MemAddr MemUtils::FindPatMod(std::string_view mod_name, std::string_view pat)
{
	if (mod_name.empty() || pat.empty()) {
		return 0;
	}

	MODULEINFO mod_info{};

	if (!GetModInfo(mod_name, mod_info)) {
		return 0;
	}

	return FindPatRange(reinterpret_cast<uintptr_t>(mod_info.lpBaseOfDll), mod_info.SizeOfImage, pat);
}