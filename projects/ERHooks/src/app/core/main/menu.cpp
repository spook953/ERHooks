#include "menu.hpp"

void Menu::AttributeEditor()
{
	er::ChrGameData *const chr_data{ er::GetGameDataMan() ? er::GetGameDataMan()->m_chr_data() : nullptr };

	if (!chr_data) {
		return;
	}

	if (ImGui::InputInt("level", &chr_data->m_stats().m_level(), 1, 1)) {
		chr_data->m_stats().m_level() = std::clamp(chr_data->m_stats().m_level(), 1, 713);
	}

	ImGui::Separator();

	int temp_scadu{ static_cast<int>(chr_data->m_stats().m_scadutree_blessing()) };

	if (ImGui::InputInt("scadutree blessing", &temp_scadu, 1, 1)) {
		chr_data->m_stats().m_scadutree_blessing() = static_cast<int8_t>(std::clamp(temp_scadu, 0, 20));
	}

	int temp_spirit{ static_cast<int>(chr_data->m_stats().m_revered_spirit_ash_blessing()) };

	if (ImGui::InputInt("revered spirit ash blessing", &temp_spirit, 1, 1)) {
		chr_data->m_stats().m_revered_spirit_ash_blessing() = static_cast<int8_t>(std::clamp(temp_spirit, 0, 20));
	}

	ImGui::Separator();

	if (ImGui::InputInt("vigor", &chr_data->m_stats().m_vigor(), 1, 1)) {
		chr_data->m_stats().m_vigor() = std::clamp(chr_data->m_stats().m_vigor(), 1, 99);
	}

	if (ImGui::InputInt("mind", &chr_data->m_stats().m_mind(), 1, 1)) {
		chr_data->m_stats().m_mind() = std::clamp(chr_data->m_stats().m_mind(), 1, 99);
	}

	if (ImGui::InputInt("endurance", &chr_data->m_stats().m_endurance(), 1, 1)) {
		chr_data->m_stats().m_endurance() = std::clamp(chr_data->m_stats().m_endurance(), 1, 99);
	}

	if (ImGui::InputInt("strength", &chr_data->m_stats().m_strength(), 1, 1)) {
		chr_data->m_stats().m_strength() = std::clamp(chr_data->m_stats().m_strength(), 1, 99);
	}

	if (ImGui::InputInt("dexterity", &chr_data->m_stats().m_dexterity(), 1, 1)) {
		chr_data->m_stats().m_dexterity() = std::clamp(chr_data->m_stats().m_dexterity(), 1, 99);
	}

	if (ImGui::InputInt("intelligence", &chr_data->m_stats().m_intelligence(), 1, 1)) {
		chr_data->m_stats().m_intelligence() = std::clamp(chr_data->m_stats().m_intelligence(), 1, 99);
	}

	if (ImGui::InputInt("faith", &chr_data->m_stats().m_faith(), 1, 1)) {
		chr_data->m_stats().m_faith() = std::clamp(chr_data->m_stats().m_faith(), 1, 99);
	}

	if (ImGui::InputInt("arcane", &chr_data->m_stats().m_arcane(), 1, 1)) {
		chr_data->m_stats().m_arcane() = std::clamp(chr_data->m_stats().m_arcane(), 1, 99);
	}
}

void Menu::ItemSpawner(const er::ItemType item_type, const er::items::item_map_t &items)
{
	er::MapItemMan *const map_item_man{ er::GetMapItemMan() };

	if (!map_item_man) {
		return;
	}

	const int index{ static_cast<int>(item_type) };

	static char filters[5][128]{};
	{
		ImGui::PushItemWidth(-1.0f);
		ImGui::InputTextWithHint("##filter", "filter", filters[index], IM_ARRAYSIZE(filters[index]));
		ImGui::PopItemWidth();
	}

	static std::unordered_map<std::uint32_t, std::int32_t> quantity[5]{};
	static std::unordered_map<std::uint32_t, bool> open[5]{};
	
	const std::string filter{ Utils::ToLower(filters[index]) };

	if (ImGui::BeginTable("item_table", 2, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV))
	{
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("id", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_DefaultSort, 50.0f);
		ImGui::TableSetupColumn("name");
		ImGui::TableHeadersRow();

		for (const auto &[id, name] : items)
		{
			if (!filter.empty() && !Utils::ToLower(name).contains(filter)) {
				continue;
			}

			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text("%u", id);
			ImGui::TableSetColumnIndex(1);

			ImGui::PushID(id);

			ImGui::Selectable(name.c_str());

			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				ImGui::OpenPopup(name.c_str());

				quantity[index][id] = 1;
				open[index][id] = true;
			}
			
			ImGui::SetNextWindowSize({ 200.0f, 0.0f });

			if (ImGui::BeginPopupModal(name.c_str(), &open[index][id], ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
			{
				ImGui::PushItemWidth(-1.0f);

				if (ImGui::InputInt("##quantity", &quantity[index][id])) {
					quantity[index][id] = std::clamp(quantity[index][id], 1, 999);
				}

				ImGui::PopItemWidth();
				
				ImGui::Separator();

				if (ImGui::Button("add to inventory", { ImGui::GetContentRegionAvail().x, 0.0f }))
				{
					map_item_man->GiveItem(item_type, id, quantity[index][id]);

					open[index][id] = false;
				}
				
				ImGui::EndPopup();
			}

			ImGui::PopID();
		}

		ImGui::EndTable();
	}
}

void Menu::EventFlagEditor(const er::event_flags::event_flag_map_t &flags, char *const filter_input, const event_flag_edit_data_t &data)
{
	er::EventFlagMan *const event_flags{ er::GetEventFlagMan() };

	if (!event_flags) {
		return;
	}

	static bool confirm_unlock{};
	static bool confirm_lock{};

	const ImVec2 button_w{ (ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.x) * 0.5f, 0.0f };

	if (ImGui::Button(data.all_on.c_str(), button_w)) {
		ImGui::OpenPopup("are you sure?###confirm_unlock");
		confirm_unlock = true;
	}

	ImGui::SameLine();

	if (ImGui::Button(data.all_off.c_str(), button_w)) {
		ImGui::OpenPopup("are you sure?###confirm_lock");
		confirm_lock = true;
	}

	auto ConfirmPopup = [](const char *const popup_name, bool *const open_flag, const std::function<void()> &on_confirm)
	{
		ImGui::SetNextWindowSize({ 200.0f, 0.0f });

		const std::string name{ std::string{ "are you sure?###" } + popup_name };

		if (ImGui::BeginPopupModal(name.c_str(), open_flag))
		{
			const ImVec2 button_w{ (ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.x) * 0.5f, 0.0f };

			if (ImGui::Button("yes", button_w)) {
				on_confirm();
				*open_flag = false;
			}

			ImGui::SameLine();

			if (ImGui::Button("no", button_w)) {
				*open_flag = false;
			}

			ImGui::EndPopup();
		}
	};

	ConfirmPopup("confirm_unlock", &confirm_unlock, [&]()
	{
		for (const auto &[id, name] : flags) {
			event_flags->SetFlag(id, true);
		}
	});

	ConfirmPopup("confirm_lock", &confirm_lock, [&]()
	{
		for (const auto &[id, name] : flags) {
			event_flags->SetFlag(id, false);
		}
	});

	ImGui::PushItemWidth(-1.0f);
	ImGui::InputTextWithHint("##filter", "filter", filter_input, 50);
	ImGui::PopItemWidth();

	const std::string filter{ Utils::ToLower(filter_input) };

	if (ImGui::BeginTable("flag_table", 2, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV))
	{
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("name", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_DefaultSort, 350.0f);
		ImGui::TableSetupColumn("state");
		ImGui::TableHeadersRow();

		for (const auto &[id, name] : flags)
		{
			if (!filter.empty() && !Utils::ToLower(name).contains(filter)) {
				continue;
			}

			const bool is_set{ event_flags->GetFlag(id) };

			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(1);
			ImGui::Text("%s", is_set ? data.flag_on.c_str() : data.flag_off.c_str());
			ImGui::TableSetColumnIndex(0);

			ImGui::PushID(id);		
			ImGui::Selectable(name.c_str());
			ImGui::PopID();

			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
				event_flags->SetFlag(id, !is_set);
			}
		}

		ImGui::EndTable();
	}
}

void Menu::PlayerMisc()
{
	er::GameDataMan *const game_data{ er::GetGameDataMan() };

	if (!game_data) {
		return;
	}

	er::ChrGameData *const chr_data{ game_data->m_chr_data() };

	if (!chr_data) {
		return;
	}

	// great rune
	{
		static const char *rune_names[]
		{
			"No Great Rune",
			"Godrick's Great Rune",
			"Rykard's Great Rune",
			"Radahn's Great Rune",
			"Morgott's Great Rune",
			"Mohg's Great Rune",
			"Malenia's Great Rune"
		};

		static uint32_t rune_vals[]{
			0x00000000, 0xB00000BF, 0xB00000C2, 0xB00000C0, 0xB00000C1, 0xB00000C3, 0xB00000C4
		};

		static int item_selected_idx{};
		
		for (int n{}; n < IM_ARRAYSIZE(rune_vals); n++)
		{
			if (rune_vals[n] == chr_data->m_great_rune()) {
				item_selected_idx = n;
				break;
			}
		}

		ImGui::SetNextItemWidth(150.0f);

		if (ImGui::BeginCombo("##great_rune_combo", rune_names[item_selected_idx]))
		{
			for (int n{}; n < IM_ARRAYSIZE(rune_names); n++)
			{
				const bool is_selected{ item_selected_idx == n };

				if (ImGui::Selectable(rune_names[n], is_selected)) {
					item_selected_idx = n;
					chr_data->m_great_rune() = rune_vals[item_selected_idx];
				}

				if (is_selected) {
					ImGui::SetItemDefaultFocus();
				}
			}

			ImGui::EndCombo();
		}

		ImGui::SameLine();

		ImGui::Checkbox("rune arc active", &chr_data->m_rune_arc_active());

		ImGui::Separator();
	}
}

void Menu::PlayerTab()
{
	if (!ImGui::BeginTabBar("player_tabs")) {
		return;
	}

	if (ImGui::BeginTabItem("attributes")) {
		AttributeEditor();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("misc")) {
		PlayerMisc();
		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();
}

void Menu::ItemsTab()
{
	if (!ImGui::BeginTabBar("items_tabs")) {
		return;
	}

	if (ImGui::BeginTabItem("weapons")) {
		ItemSpawner(er::ItemType::Weapon, er::items::GetWeaponMap());
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("armor")) {
		ItemSpawner(er::ItemType::Protector, er::items::GetProtectorMap());
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("talismans")) {
		ItemSpawner(er::ItemType::Accessory, er::items::GetAccessoryMap());
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("ashes of war")) {
		ItemSpawner(er::ItemType::Gem, er::items::GetGemMap());
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("other")) {
		ItemSpawner(er::ItemType::Good, er::items::GetGoodsMap());
		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();
}

void Menu::ProgressionTab()
{
	er::EventFlagMan *const event_flags{ er::GetEventFlagMan() };

	if (!event_flags) {
		return;
	}

	if (!ImGui::BeginTabBar("progression_tabs")) {
		return;
	}

	if (ImGui::BeginTabItem("sites of grace")) {
		static char filter[128]{};
		EventFlagEditor(er::event_flags::GetGraceMap(), filter, { "unlocked", "locked", "unlock all", "lock all" });
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("map pieces")) {
		static char filter[128]{};
		EventFlagEditor(er::event_flags::GetMapPieceMap(), filter, { "unlocked", "locked", "unlock all", "lock all" });
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("cookbooks")) {
		static char filter[128]{};
		EventFlagEditor(er::event_flags::GetCookBookMap(), filter, { "unlocked", "locked", "unlock all", "lock all" });
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("affinities")) {
		static char filter[128]{};
		EventFlagEditor(er::event_flags::GetAffinitiesMap(), filter, { "unlocked", "locked", "unlock all", "lock all" });
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("bosses"))
	{
		// special handling for the flower that spawns afer Malenia's defeat

		const bool malenia_pre{ event_flags->GetFlag(er::event_flags::special::GetMaleniaDefeatedFlag()) };

		static char filter[128]{};

		EventFlagEditor(er::event_flags::GetBossDefeatedMap(), filter, { "dead", "alive", "kill all", "revive all" });

		const bool malenia_cur{ event_flags->GetFlag(er::event_flags::special::GetMaleniaDefeatedFlag()) };

		if (malenia_cur != malenia_pre) {
			event_flags->SetFlag(er::event_flags::special::GetMaleniaFlowerFlag(), malenia_cur);
		}

		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();
}

void Menu::MainWindow()
{
	if (!ImGui::BeginTabBar("main_tabs")) {
		return;
	}

	if (ImGui::BeginTabItem("player")) {
		PlayerTab();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("items")) {
		ItemsTab();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("progression")) {
		ProgressionTab();
		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();
}

void Menu::Run()
{
	if (Input::GetKey(VK_INSERT).pressed) {
		is_open = !is_open;
	}

	ImGui::GetIO().MouseDrawCursor = is_open;

	if (!is_open) {
		return;
	}

	if (!er::InGame())
	{
		ImGui::OpenPopup("ERHooks");

		ImGui::SetNextWindowSize({ 200.0f, 0.0f });

		if (ImGui::BeginPopupModal("ERHooks", &is_open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			ImGui::Text("you must be in game to use the menu");

			ImGui::EndPopup();
		}

		return;
	}

	ImGui::SetNextWindowSize({ 550.0f, 400.0f });

	if (ImGui::Begin("ERHooks", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
	{
		MainWindow();

		ImGui::End();
	}
}