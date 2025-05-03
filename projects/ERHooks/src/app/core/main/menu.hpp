#pragma once

#include "input.hpp"
#include "renderer.hpp"

class Menu final
{
private:
	static inline bool is_open{};

public:
	static bool IsOpen() { return is_open; }

private:
	static void AttributeEditor();
	static void ItemSpawner(const er::ItemType item_type, const er::items::item_map_t &items);

private:
	static void PlayerTab();
	static void ItemsTab();

private:
	static void MainWindow();

public:
	static void Run();
};