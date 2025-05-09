#pragma once

#include "imgui/imgui_impl_win32.hpp"
#include "imgui/imgui_impl_dx12.hpp"
#include "imgui/imgui_freetype.hpp"

#include "inifile-cpp/inicpp.hpp"
#include "minhook/minhook.hpp"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);