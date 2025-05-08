#pragma once

struct Settings
{
	static inline bool disable_chromatic_aberration{ false };
	static inline bool disable_vignette{ false };
	static inline bool no_clip{ false };
	static inline float no_clip_speed{ 0.1f };
	static inline bool no_death{ false };
	static inline bool cam_dist_override_active{ false };
	static inline float cam_dist_override_val{ 5.0f };
	static inline bool cam_smooth_override_active{ false };
	static inline float cam_smooth_override_val{ 0.5f };
	static inline bool cam_fov_override_active{ false };
	static inline float cam_fov_override_val{ 60.0f };
};