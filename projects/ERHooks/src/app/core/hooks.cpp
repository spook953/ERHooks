#include "hooks.hpp"

MAKE_HOOK(
	CDXGISwapChain_Present,
	MemUtils::GetVirtual(er::bin::CDXGISwapChain.As<IDXGISwapChain *>(), 8).Get(),
	HRESULT,
	IDXGISwapChain *thisptr, UINT SyncInterval, UINT Flags)
{
	Input::Start();

	if (Renderer::Start())
	{
		Menu::Run();

		Renderer::End();
	}

	Input::End();

	return CALL_ORIGINAL(thisptr, SyncInterval, Flags);
}

MAKE_HOOK(
	CDXGISwapChain_ResizeBuffers,
	MemUtils::GetVirtual(er::bin::CDXGISwapChain.As<IDXGISwapChain *>(), 13).Get(),
	HRESULT,
	IDXGISwapChain *thisptr, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	Renderer::Unload();

	const HRESULT result{ CALL_ORIGINAL(thisptr, BufferCount, Width, Height, NewFormat, SwapChainFlags) };

	Renderer::Load();

	return result;
}

MAKE_HOOK(
	WndProc,
	er::bin::WndProc.Get(),
	LRESULT,
	HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	Input::WndProc(Msg, wParam, lParam);

	if (Menu::IsOpen()) {
		ImGui_ImplWin32_WndProcHandler(hWnd, Msg, wParam, lParam);
		return 1;
	}

	return CALL_ORIGINAL(hWnd, Msg, wParam, lParam);
}

MAKE_HOOK(
	User32_SetCursorPos,
	MemUtils::GetExport("User32.dll", "SetCursorPos").Get(),
	BOOL,
	int X, int Y)
{
	if (Menu::IsOpen()) {
		return 0;
	}

	return CALL_ORIGINAL(X, Y);
}

MAKE_HOOK(
	User32_GetCursorPos,
	MemUtils::GetExport("User32.dll", "GetCursorPos").Get(),
	BOOL,
	LPPOINT lpPoint)
{
	if (Menu::IsOpen() && lpPoint)
	{
		const BOOL result{ CALL_ORIGINAL(lpPoint) };

		lpPoint->x = 0;
		lpPoint->y = 0;

		return result;
	}

	return CALL_ORIGINAL(lpPoint);
}

MAKE_HOOK(
	KeyboardDevice_UpdateInput,
	er::bin::KeyboardDevice_UpdateInput.Get(),
	bool,
	er::KeyboardDevice *thisptr)
{
	if (Menu::IsOpen()) {
		thisptr->ResetInput();
		return true;
	}

	return CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	MouseDevice_UpdateInput,
	er::bin::MouseDevice_UpdateInput.Get(),
	bool,
	er::MouseDevice *thisptr)
{
	static bool menu_was_open{};

	if (Menu::IsOpen())
	{
		menu_was_open = true;

		thisptr->ResetInput();
		thisptr->m_move_delta() = {};

		return true;
	}

	const bool result{ CALL_ORIGINAL(thisptr) };

	if (menu_was_open)
	{
		menu_was_open = false;

		thisptr->m_move_delta() = {};
	}
	
	return result;
}