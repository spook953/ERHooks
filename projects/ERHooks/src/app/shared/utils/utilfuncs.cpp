#include "utilfuncs.hpp"

std::string Utils::ToLower(std::string_view str)
{
	std::string result{ str };

	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });

	return result;
}