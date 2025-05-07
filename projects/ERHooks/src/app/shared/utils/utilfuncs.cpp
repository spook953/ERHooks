#include "utilfuncs.hpp"

std::string Utils::ToLower(std::string_view str)
{
	std::string result{ str };

	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });

	return result;
}

float Utils::DegToRad(const float deg)
{
	return deg * (3.14159265f / 180.0f);
}

float Utils::RadToDeg(const float rad)
{
	return rad * (180.0f / 3.14159265f);
}

void Utils::Normalize(vec3_t &v)
{
	const float length{ sqrtf(v.x * v.x + v.y * v.y + v.z * v.z) };

	if (length > 0.00001f) {
		v /= length;
	}
}

void Utils::AngleVectors(const vec3_t &angles, vec3_t *const forward, vec3_t *const right, vec3_t *const up)
{
	const float cp{ cosf(angles.y) };
	const float sp{ sinf(angles.y) };
	const float cy{ cosf(angles.x) };
	const float sy{ sinf(angles.x) };

	vec3_t f{ cp * sy, -sp, cp * cy };

	Normalize(f);

	const vec3_t r{ -cy, 0.0f, sy };
	const vec3_t u{ f.y * r.z - f.z * r.y, f.z * r.x - f.x * r.z, f.x * r.y - f.y * r.x };

	if (forward) { *forward = f; }
	if (right) { *right = r; }
	if (up) { *up = u; }
}