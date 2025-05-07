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
class TempSet final
{
private:
	T &var{};
	T og_val{};

public:
	TempSet(T &var, const T new_val) : var(var), og_val(var) {
		var = new_val;
	}

	~TempSet() {
		var = og_val;
	}
};

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)

#define TEMP_SET(var, val) const auto CONCATENATE(tmp_set_, __LINE__){ TempSet(var, val) }
#define TEMP_SET_SELF(var) const auto CONCATENATE(backup_set_, __LINE__){ TempSet(var, var) }