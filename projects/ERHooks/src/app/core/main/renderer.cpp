#include "renderer.hpp"

void Renderer::SetupImGuiStyle()
{
	ImGuiStyle &style{ ImGui::GetStyle() };
	ImGuiIO &io{ ImGui::GetIO() };

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.6000000238418579f;
	style.WindowPadding = ImVec2(8.0f, 8.0f);
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(4.0f, 3.0f);
	style.FrameRounding = 0.0f;
	style.FrameBorderSize = 1.0f;
	style.ItemSpacing = ImVec2(8.0f, 4.0f);
	style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
	style.CellPadding = ImVec2(4.0f, 2.0f);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 7.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 0.0f;
	style.TabBorderSize = 1.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
	style.SeparatorTextBorderSize = 1.0f;

	style.Colors[ImGuiCol_Text] = ImVec4(0.7843137254901961f, 0.7843137254901961f, 0.7843137254901961f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1764705926179886f, 0.1764705926179886f, 0.1764705926179886f, 1.0f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1764705926179886f, 0.1764705926179886f, 0.1764705926179886f, 1.0f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 1.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2745098173618317f, 0.2745098173618317f, 0.2745098173618317f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.3529411764705882f, 0.3529411764705882f, 0.3529411764705882f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 1.0f, 1.0f, 0.3910000026226044f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.192156862745098f, 0.192156862745098f, 0.192156862745098f, 1.0f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.0f, 1.0f, 1.0f, 0.25f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.6700000166893005f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.1450980392156863f, 0.1450980392156863f, 0.1450980392156863f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3490196168422699f, 0.3490196168422699f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.5843137502670288f, 0.5843137502670288f, 0.5843137502670288f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3529411764705882f, 0.3529411764705882f, 0.3529411764705882f, 1.0f);

	ImFontConfig cfg{};
	{
		cfg.OversampleH = 1;
		cfg.OversampleV = 1;
		cfg.GlyphOffset = { 1, 0 };
		cfg.PixelSnapH = true;
		cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_Monochrome | ImGuiFreeTypeBuilderFlags_MonoHinting;
	}

	io.FontDefault = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 13.0f, &cfg);
}

bool Renderer::Load()
{
	if (initialized) {
		return true;
	}

	IDXGISwapChain *const swap_chain{ er::bin::CDXGISwapChain.As<IDXGISwapChain *>() };

	if (!swap_chain) {
		return false;
	}

	ID3D12CommandQueue *const cmd_queue{ er::bin::CD3D12CommandQueue.As<ID3D12CommandQueue *>() };

	if (!cmd_queue) {
		return false;
	}

	ID3D12Device *device{};

	if (swap_chain->GetDevice(__uuidof(ID3D12Device), reinterpret_cast<void **>(&device)) != S_OK) {
		return false;
	}

	DXGI_SWAP_CHAIN_DESC sc_desc{};
	{
		swap_chain->GetDesc(&sc_desc);

		output_wnd = sc_desc.OutputWindow;
		frame_buf_count = sc_desc.BufferCount;

		frame_ctx.clear();
		frame_ctx.resize(frame_buf_count);
	}

	D3D12_DESCRIPTOR_HEAP_DESC srv_desc{};
	{
		srv_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
		srv_desc.NumDescriptors = frame_buf_count;
		srv_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

		if (device->CreateDescriptorHeap(&srv_desc, IID_PPV_ARGS(&srv_desc_heap)) != S_OK) {
			return false;
		}
	}

	D3D12_DESCRIPTOR_HEAP_DESC rtv_desc{};
	{
		rtv_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtv_desc.NumDescriptors = frame_buf_count;
		rtv_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		rtv_desc.NodeMask = 1;

		if (device->CreateDescriptorHeap(&rtv_desc, IID_PPV_ARGS(&rtv_desc_heap)) != S_OK) {
			return false;
		}

		const UINT desc_size{ device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV) };

		D3D12_CPU_DESCRIPTOR_HANDLE rtv_handle{ rtv_desc_heap->GetCPUDescriptorHandleForHeapStart() };

		for (UINT n{}; n < frame_buf_count; n++) {
			frame_ctx[n].main_rt_desc = rtv_handle;
			swap_chain->GetBuffer(n, IID_PPV_ARGS(&frame_ctx[n].main_rt_rsrc));
			device->CreateRenderTargetView(frame_ctx[n].main_rt_rsrc, nullptr, rtv_handle);
			rtv_handle.ptr += desc_size;
		}
	}

	for (size_t n{}; n < frame_buf_count; n++)
	{
		if (device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&frame_ctx[n].cmd_alloc)) != S_OK) {
			return false;
		}
	}

	if (device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, frame_ctx[0].cmd_alloc, 0, IID_PPV_ARGS(&cmd_list)) != S_OK) {
		return false;
	}

	if (cmd_list->Close() != S_OK) {
		return false;
	}

	if (!ImGui::CreateContext()) {
		return false;
	}

	ImGui::GetIO().IniFilename = nullptr;
	ImGui::GetIO().LogFilename = nullptr;

	if (!ImGui_ImplWin32_Init(output_wnd)) {
		return false;
	}

	if (!ImGui_ImplDX12_Init(
		device,
		frame_buf_count,
		DXGI_FORMAT_R8G8B8A8_UNORM,
		srv_desc_heap,
		srv_desc_heap->GetCPUDescriptorHandleForHeapStart(),
		srv_desc_heap->GetGPUDescriptorHandleForHeapStart())) {
		return false;
	}

	SetupImGuiStyle();

	initialized = true;

	return true;
}

bool Renderer::Unload()
{
	if (!initialized) {
		return true;
	}

	ImGui_ImplDX12_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();

	output_wnd = 0;
	frame_buf_count = 0;

	for (FrameContext &fc : frame_ctx)
	{
		if (fc.cmd_alloc) {
			fc.cmd_alloc->Release();
			fc.cmd_alloc = nullptr;
		}

		if (fc.main_rt_rsrc) {
			fc.main_rt_rsrc->Release();
			fc.main_rt_rsrc = nullptr;
		}

		fc.main_rt_desc = {};
	}

	frame_ctx.clear();

	if (srv_desc_heap) {
		srv_desc_heap->Release();
		srv_desc_heap = nullptr;
	}

	if (rtv_desc_heap) {
		rtv_desc_heap->Release();
		rtv_desc_heap = nullptr;
	}

	if (cmd_list) {
		cmd_list->Release();
		cmd_list = nullptr;
	}

	initialized = false;

	return true;
}

bool Renderer::Start()
{
	if (!initialized) {
		return false;
	}

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX12_NewFrame();

	ImGui::NewFrame();

	return true;
}

void Renderer::End()
{
	if (!initialized) {
		return;
	}

	IDXGISwapChain3 *const swap_chain{ er::bin::CDXGISwapChain.As<IDXGISwapChain3 *>() };

	if (!swap_chain) {
		return;
	}

	ID3D12CommandQueue *const cmd_queue{ er::bin::CD3D12CommandQueue.As<ID3D12CommandQueue *>() };

	if (!cmd_queue) {
		return;
	}

	FrameContext &cur_frame_ctx{ frame_ctx[swap_chain->GetCurrentBackBufferIndex()] };

	cur_frame_ctx.cmd_alloc->Reset();

	D3D12_RESOURCE_BARRIER barrier{};
	{
		barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
		barrier.Transition.pResource = cur_frame_ctx.main_rt_rsrc;
		barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
		barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
		barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
	}

	cmd_list->Reset(cur_frame_ctx.cmd_alloc, nullptr);
	cmd_list->ResourceBarrier(1, &barrier);
	cmd_list->OMSetRenderTargets(1, &cur_frame_ctx.main_rt_desc, 0, nullptr);
	cmd_list->SetDescriptorHeaps(1, &srv_desc_heap);

	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmd_list);

	barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
	barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;

	cmd_list->ResourceBarrier(1, &barrier);
	cmd_list->Close();

	cmd_queue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList **>(&cmd_list));
}