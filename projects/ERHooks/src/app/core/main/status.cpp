#include "status.hpp"

void Status::Run()
{
	if (!er::InGame() || !vars::show_status) {
		return;
	}

	er::GameDataMan *const game_data{ er::GetGameDataMan() };

	if (!game_data) {
		return;
	}

	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	auto TextOutlined = [&](const ImVec2 &pos, std::string_view str)
	{
		const ImColor clr_txt{ ImGui::GetStyleColorVec4(ImGuiCol_Text) };
		const ImColor clr_outline{ ImVec4{ 0.0f, 0.0f, 0.0f, 0.9f } };

		dl->AddText({ pos.x + 1.0f, pos.y + 1.0f }, clr_outline, str.data());
		dl->AddText(pos, clr_txt, str.data());
	};

	const uint32_t play_time{ game_data->m_play_time_ms() / 1000 };

	status_strs.push_back(std::format("ng+ : {}", game_data->m_journey_nr()));
	status_strs.push_back(std::format("igt : {:02}:{:02}:{:02}", play_time / 3600, (play_time % 3600) / 60, play_time % 60));
	status_strs.push_back(std::format("deaths : {}", game_data->m_death_count()));

	for (size_t n{}; n < status_strs.size(); n++)
	{
		const ImVec2 pos{ 2.0f, ImGui::GetIO().DisplaySize.y - (15.0f * static_cast<float>(status_strs.size())) };

		TextOutlined({ pos.x, pos.y + (15.0f * static_cast<float>(n)) }, status_strs[n]);
	}

	status_strs.clear();
}