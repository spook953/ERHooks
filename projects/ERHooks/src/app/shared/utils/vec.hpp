#pragma once

class vec2_t final
{
public:
	float x{};
	float y{};

public:
	vec2_t(const float x = 0.0f, const float y = 0.0f)
		: x(x), y(y) {}

public:
	vec2_t operator+(const vec2_t &v) const { return { x + v.x, y + v.y }; }
	vec2_t operator-(const vec2_t &v) const { return { x - v.x, y - v.y }; }
	vec2_t operator*(const float s) const { return { x * s, y * s }; }
	vec2_t operator*(const vec2_t &v) const { return { x * v.x, y * v.y }; }
	vec2_t operator/(const float s) const { return { x / s, y / s }; }

public:
	vec2_t &operator+=(const vec2_t &v) { x += v.x; y += v.y; return *this; }
	vec2_t &operator-=(const vec2_t &v) { x -= v.x; y -= v.y; return *this; }
	vec2_t &operator*=(const float s) { x *= s; y *= s; return *this; }
	vec2_t &operator/=(const float s) { x /= s; y /= s; return *this; }
};

class vec3_t final
{
public:
	float x{};
	float y{};
	float z{};

public:
	vec3_t(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f)
		: x(x), y(y), z(z) {}

public:
	vec3_t operator+(const vec3_t &v) const { return { x + v.x, y + v.y, z + v.z }; }
	vec3_t operator-(const vec3_t &v) const { return { x - v.x, y - v.y, z - v.z }; }
	vec3_t operator*(const float s) const { return { x * s, y * s, z * s }; }
	vec3_t operator*(const vec3_t &v) const { return { x * v.x, y * v.y, z * v.z }; }
	vec3_t operator/(const float s) const { return { x / s, y / s, z / s }; }

public:
	vec3_t &operator+=(const vec3_t &v) { x += v.x; y += v.y; z += v.z; return *this; }
	vec3_t &operator-=(const vec3_t &v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	vec3_t &operator*=(const float s) { x *= s; y *= s; z *= s; return *this; }
	vec3_t &operator/=(const float s) { x /= s; y /= s; z /= s; return *this; }
};