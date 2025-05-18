#pragma once

#include <algorithm>
#include <string>

#include "vec.hpp"

class Utils
{
public:
	static std::string ToLower(std::string_view str);

public:
	static float DegToRad(const float deg);
	static float RadToDeg(const float rad);
	static void Normalize(vec3_t &v);
	static void AngleVectors(const vec3_t &angles, vec3_t *const forward, vec3_t *const right = nullptr, vec3_t *const up = nullptr);
};

template <typename T>
class AutoRestore final
{
private:
	T &var{};
	T og_val{};

public:
	AutoRestore(T &var) : var(var), og_val(var) {}
	AutoRestore(T &var, const T new_val) : var(var), og_val(std::exchange(var, new_val)) {}

public:
	~AutoRestore() {
		var = og_val;
	}
};

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)

#define AUTO_RESTORE(var) const AutoRestore CONCATENATE(auto_restore_, __LINE__){ var }
#define AUTO_RESTORE_SET(var, val) const AutoRestore CONCATENATE(auto_restore_, __LINE__){ var, val }