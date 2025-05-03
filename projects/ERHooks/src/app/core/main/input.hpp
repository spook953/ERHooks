#pragma once

#include "../../game/game.hpp"

class Input final
{
private:
	class Key
	{
	public:
		bool pressed{};
		bool held{};
		bool released{};
	};

	class Wheel
	{
	public:
		bool up{};
		bool down{};
	};

	enum KeyState
	{
		NONE,
		PRESSED,
		HELD,
		RELEASED
	};

private:
	static inline bool key_states[256]{};
	static inline KeyState key_kstates[256]{};
	static inline int mouse_wheel_delta_cached{};
	static inline int mouse_wheel_delta{};
	static inline int mouse_pos_x{};
	static inline int mouse_pos_y{};
	static inline char key_char{};

public:
	static Key GetKey(const size_t key);
	static char GetChar();
	static Wheel GetMouseWheel();

public:
	static void WndProc(const UINT msg, const WPARAM wparam, const LPARAM lparam);

public:
	static void Start();
	static void End();
};