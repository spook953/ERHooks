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

	auto to_lower = [](const std::string &str) {
		std::string result{ str };
		std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
		return result;
	};

	const int index{ static_cast<int>(item_type) };

	static char filters[5][128]{};
	{
		ImGui::PushItemWidth(-1.0f);
		ImGui::InputTextWithHint("##filter", "filter", filters[index], IM_ARRAYSIZE(filters[index]));
		ImGui::PopItemWidth();
	}

	static std::unordered_map<std::uint32_t, std::int32_t> quantity[5]{};
	static std::unordered_map<std::uint32_t, bool> open[5]{};
	
	const std::string filter{ to_lower(filters[index]) };

	if (ImGui::BeginTable("item_table", 2, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV))
	{
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("id", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_DefaultSort, 50.0f);
		ImGui::TableSetupColumn("name");
		ImGui::TableHeadersRow();

		for (const auto &[id, name] : items)
		{
			if (!filter.empty() && !to_lower(name).contains(filter)) {
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

void Menu::PlayerTab()
{
	if (!ImGui::BeginTabBar("player_tabs")) {
		return;
	}

	if (ImGui::BeginTabItem("attributes")) {
		AttributeEditor();
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