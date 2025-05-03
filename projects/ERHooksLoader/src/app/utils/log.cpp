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