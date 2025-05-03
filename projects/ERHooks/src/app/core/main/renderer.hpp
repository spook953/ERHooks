#pragma once

#include "../../game/game.hpp"

class Renderer final
{
private:
	struct FrameContext final
	{
		ID3D12CommandAllocator *cmd_alloc{};
		ID3D12Resource *main_rt_rsrc{};
		D3D12_CPU_DESCRIPTOR_HANDLE main_rt_desc{};
	};

private:
	static inline HWND output_wnd{};
	static inline UINT frame_buf_count{};
	static inline std::vector<FrameContext> frame_ctx{};
	static inline ID3D12DescriptorHeap *srv_desc_heap{};
	static inline ID3D12DescriptorHeap *rtv_desc_heap{};
	static inline ID3D12GraphicsCommandList *cmd_list{};

private:
	static inline bool initialized{};

private:
	static void SetupImGuiStyle();

public:
	static bool Load();
	static bool Unload();

public:
	static bool Start();
	static void End();
};