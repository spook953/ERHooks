#include "app/app.hpp"

static void MainThread(LPVOID param)
{
	App::Load();

	while (!GetAsyncKeyState(VK_F11)) {
		Sleep(50);
	}

	App::Unload();

	Sleep(250);

	FreeLibraryAndExitThread(reinterpret_cast<HINSTANCE>(param), EXIT_SUCCESS);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason != DLL_PROCESS_ATTACH) {
		return TRUE;
	}

	const HANDLE main_thread{ CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hinstDLL, 0, 0) };

	if (main_thread == 0) {
		return FALSE;
	}

	CloseHandle(main_thread);

	return TRUE;
}