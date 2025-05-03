#pragma once

#include "../../shared/shared.hpp"

#define MAKE_MEMBER(type, name, offset) \
type &name() { return *reinterpret_cast<type *>(reinterpret_cast<uintptr_t>(this) + offset); }