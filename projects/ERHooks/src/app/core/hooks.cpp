#include "hooks.hpp"

#define DUMP_EVENT_FLAGS FALSE

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
		BossTracker::Run();
		Status::Run();

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

#if DUMP_EVENT_FLAGS == TRUE

MAKE_HOOK(
	SetEventFlag,
	er::bin::EventFlagMan_SetFlag.Get(),
	unsigned int,
	void *thisptr, unsigned int flag, int val)
{
	static std::unordered_set<unsigned int> flags{};

	if (!flags.contains(flag)) {
		flags.insert(flag);
		Log::Wrn("set {} to {}", flag, val);
	}

	return CALL_ORIGINAL(thisptr, flag, val);
}

#endif

MAKE_HOOK(
	PostProcessFunc,
	er::bin::PostProcessFunc.Get(),
	void,
	__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6,
	__int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, char a13, int a14)
{
	AUTO_RESTORE(*reinterpret_cast<int *>(a1 + 216));
	AUTO_RESTORE(*reinterpret_cast<int *>(a1 + 272));

	if (vars::disable_chromatic_aberration) {
		*reinterpret_cast<int *>(a1 + 216) = 0;
	}

	if (vars::disable_vignette) {
		*reinterpret_cast<int *>(a1 + 272) = INT_MAX;
	}

	CALL_ORIGINAL(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}

MAKE_HOOK(
	UpdatePhysicsFunc,
	er::bin::UpdatePhysicsFunc.Get(),
	void,
	void *thisptr)
{
	auto NoClip = [&]()
	{
		if (!vars::no_clip) {
			return false;
		}

		er::ChrModules *const modules{ er::GetLocalModules() };

		if (!modules) {
			return false;
		}

		er::CSChrPhysicsModule *const physics{ modules->m_char_physics() };

		if (!physics || physics != thisptr) {
			return false;
		}

		er::CSChrFallModule *const fall{ modules->m_fall() };

		if (!fall) {
			return false;
		}

		er::CameraMatrix *const cam{ er::GetCameraMatrix() };

		if (!cam) {
			return false;
		}

		physics->m_on_ground() = true;
		fall->m_fall_timer() = 0.0f;

		if (!Menu::IsOpen())
		{
			vec3_t forward{};
			vec3_t right{};

			Utils::AngleVectors(cam->m_angles(), &forward, &right);

			const float speed{ vars::no_clip_speed * (Input::GetKey(VK_SHIFT).held ? 5.0f : 1.0f) };

			if (Input::GetKey('W').held) { physics->m_pos() += forward * speed; }
			if (Input::GetKey('A').held) { physics->m_pos() += right * speed; }
			if (Input::GetKey('S').held) { physics->m_pos() -= forward * speed; }
			if (Input::GetKey('D').held) { physics->m_pos() -= right * speed; }

			if (Input::GetKey(VK_SPACE).held) { physics->m_pos().y += speed; }
			if (Input::GetKey(VK_CONTROL).held) { physics->m_pos().y -= speed; }
		}

		return true;
	};

	if (NoClip()) {
		return;
	}

	CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	ChrDeathFunc,
	er::bin::ChrDeathFunc.Get(),
	bool,
	void *thisptr)
{
	auto NoDeath = [&]()
	{
		if (!vars::no_death) {
			return false;
		}

		er::ChrModules *const modules{ er::GetLocalModules() };

		if (!modules) {
			return false;
		}

		er::CSCharData *const char_data{ modules->m_char_data() };

		if (!char_data) {
			return false;
		}

		return char_data == thisptr;
	};

	if (NoDeath()) {
		return true;
	}

	return CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	CamUpdateFunc,
	er::bin::CamUpdateFunc.Get(),
	void,
	__int64 a1)
{
	if (vars::cam_dist_override_active) {
		*reinterpret_cast<float *>(a1 + 440) = vars::cam_dist_override_val;
	}

	CALL_ORIGINAL(a1);

	if (vars::cam_fov_override_active) {
		*reinterpret_cast<float *>(a1 + 80) = Utils::DegToRad(vars::cam_fov_override_val);
	}
}

MAKE_HOOK(
	CamTrackFunc,
	er::bin::CamTrackFunc.Get(),
	void *,
	__int64 a1, __int64 a2, __int64 a3, __m128 *a4)
{
	AUTO_RESTORE(*reinterpret_cast<float *>(a1 + 460));

	if (vars::cam_smooth_override_active) {
		*reinterpret_cast<float *>(a1 + 460) = vars::cam_smooth_override_val;
	}

	if (vars::no_clip) {
		*reinterpret_cast<float *>(a1 + 460) = 1.0f;
	}

	return CALL_ORIGINAL(a1, a2, a3, a4);
}

// triggers death effects?
//MAKE_HOOK(
//	IDFK,
//	MemUtils::FindPatMod("eldenring.exe", "48 83 EC 28 44 0F B6 4A ?").Get(),
//	void,
//	__int64 a1, __int64 a2)
//{
//	static std::unordered_set<void *> calls{};
//
//	if (!calls.contains(_ReturnAddress())) {
//		calls.insert(_ReturnAddress());
//		Log::Wrn("called from : {:X}", (uintptr_t)_ReturnAddress());
//	}
//
//	return;
//}