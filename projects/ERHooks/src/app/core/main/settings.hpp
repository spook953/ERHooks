#pragma once

struct Settings
{
	static inline bool disable_chromatic_aberration{ false };
	static inline bool disable_vignette{ false };
	static inline bool no_clip{ false };
	static inline float no_clip_speed{ 0.1f };
	static inline bool no_death{ false };
};