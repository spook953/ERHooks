#include "boss_tracker.hpp"

void BossTracker::DrawProgress(const er::bosses::boss_map_t &data, std::string_view name)
{
	auto TextOutlined = [&](std::string_view str)
	{
		const ImVec2 og_cursor_pos{ ImGui::GetCursorPos() };

		ImGui::SetCursorPos({ og_cursor_pos.x + 1.0f, og_cursor_pos.y + 1.0f });
		ImGui::TextColored({ 0.0f, 0.0f, 0.0f, 0.9f }, str.data());

		ImGui::SetCursorPos(og_cursor_pos);
		ImGui::TextUnformatted(str.data());
	};

	er::EventFlagMan *const event_flags{ er::GetEventFlagMan() };

	if (!event_flags) {
		return;
	}

	size_t sum{};
	size_t sum_defeated{};

	for (const auto &entry : data)
	{
		sum += entry.second.size();

		for (const auto &boss : entry.second)
		{
			if (event_flags->GetFlag(boss.first)) {
				sum_defeated++;
			}
		}
	}

	const float bar_w{ std::min(ImGui::GetIO().DisplaySize.x * 0.125f, 210.0f) };

	TextOutlined(std::format("{} ( {} / {} )", name.data(), sum_defeated, sum));

	ImGui::ProgressBar(static_cast<float>(sum_defeated) / static_cast<float>(sum), { bar_w, 5.0f });

	for (const auto &entry : data)
	{
		const size_t total{ entry.second.size() };

		size_t defeated{};

		for (const auto &boss : entry.second)
		{
			if (event_flags->GetFlag(boss.first)) {
				defeated++;
			}
		}

		TextOutlined(std::format("{} ( {} / {} )", entry.first, defeated, total));

		const ImVec2 text_min{ ImGui::GetItemRectMin() };
		const ImVec2 text_max{ ImGui::GetItemRectMax() };

		ImGui::ProgressBar(static_cast<float>(defeated) / static_cast<float>(total), { bar_w, 5.0f });

		const ImVec2 bar_min{ ImGui::GetItemRectMin() };
		const ImVec2 bar_max{ ImGui::GetItemRectMax() };

		const ImVec2 hover_min{ ImVec2(std::min(text_min.x, bar_min.x), text_min.y) };
		const ImVec2 hover_max{ ImVec2(std::max(text_max.x, bar_max.x), bar_max.y) };

		if (ImGui::IsMouseHoveringRect(hover_min, hover_max) && ImGui::IsWindowHovered())
		{
			ImGui::BeginTooltip();

			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 2.0f, 2.0f });

			if (ImGui::BeginTable(entry.first.c_str(), 2, ImGuiTableFlags_BordersInnerH))
			{
				for (const auto &boss : entry.second)
				{
					const bool defeated{ event_flags->GetFlag(boss.first) };

					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					ImGui::TextUnformatted(boss.second.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::PushStyleColor(ImGuiCol_Text, defeated ? ImColor{ 106, 176, 76 }.Value : ImColor{ 235, 77, 75 }.Value);
					ImGui::TextUnformatted(defeated ? "Dead" : "Alive");
					ImGui::PopStyleColor();
				}

				ImGui::EndTable();
			}

			ImGui::PopStyleVar();

			ImGui::EndTooltip();
		}
	}
}

void BossTracker::Run()
{
	if (!er::InGame() || !Menu::IsOpen() || !vars::show_boss_tracker) {
		return;
	}

	ImGui::SetNextWindowPos({ ImGui::GetIO().DisplaySize.x * 0.68f, 0.0f });

	if (ImGui::Begin("boss_tracker_base", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground))
	{
		DrawProgress(er::bosses::GetBaseBosses(), "Base Game");

		ImGui::End();
	}

	ImGui::SetNextWindowPos({ ImGui::GetIO().DisplaySize.x * 0.8f, 0.0f });

	if (ImGui::Begin("boss_tracker_dlc", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground))
	{
		DrawProgress(er::bosses::GetDLCBosses(), "DLC");

		ImGui::End();
	}
}