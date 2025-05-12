#pragma once

#include "../../game/game.hpp"

struct Settings final
{
	static void Save();
	static void Load();
};

MAKE_VAR(boss_tracker_active, true);

MAKE_VAR(disable_chromatic_aberration, false);
MAKE_VAR(disable_vignette, false);
MAKE_VAR(no_clip, false);
MAKE_VAR(no_clip_speed, 0.1f);
MAKE_VAR(no_death, false);
MAKE_VAR(cam_dist_override_active, false);
MAKE_VAR(cam_dist_override_val, 5.0f);
MAKE_VAR(cam_smooth_override_active, false);
MAKE_VAR(cam_smooth_override_val, 0.5f);
MAKE_VAR(cam_fov_override_active, false);
MAKE_VAR(cam_fov_override_val, 60.0f);