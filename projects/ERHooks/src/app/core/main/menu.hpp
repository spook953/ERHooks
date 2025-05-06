#pragma once

#include "input.hpp"
#include "renderer.hpp"
#include "settings.hpp"

class Menu final
{
private:
	static inline bool is_open{};

public:
	static bool IsOpen() { return is_open; }

private:
	struct event_flag_edit_data_t final
	{
		std::string flag_on{};
		std::string flag_off{};
		std::string all_on{};
		std::string all_off{};
	};

private:
	static void AttributeEditor();
	static void ItemSpawner(const er::ItemType item_type, const er::items::item_map_t &items);
	static void EventFlagEditor(const er::event_flags::event_flag_map_t &flags, char *const filter_input, const event_flag_edit_data_t &data);
	static void PlayerMisc();

private:
	static void PlayerTab();
	static void ItemsTab();
	static void ProgressionTab();
	static void GameTab();

private:
	static void MainWindow();

public:
	static void Run();
};