#include "log.hpp"

void Log::EnableVirtualTerminal()
{
	static bool enabled{};

	if (enabled) {
		return;
	}

	const HANDLE out_h{ GetStdHandle(STD_OUTPUT_HANDLE) };

	if (out_h == INVALID_HANDLE_VALUE) {
		return;
	}

	DWORD mode{};

	if (!GetConsoleMode(out_h, &mode)) {
		return;
	}

	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	SetConsoleMode(out_h, mode);

	enabled = true;
}

void Log::AllocCon(std::string_view name)
{
	AllocConsole();
	SetConsoleTitleA(name.data());

	static FILE *fp{};

	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	std::cout.clear();
	std::cerr.clear();
	std::cin.clear();

	std::ios::sync_with_stdio();
}

void Log::FreeCon(const bool close_window)
{
	const HWND hwnd{ GetConsoleWindow() };

	FreeConsole();

	if (close_window && hwnd != 0) {
		PostMessageA(hwnd, WM_CLOSE, 0, 0);
	}
}