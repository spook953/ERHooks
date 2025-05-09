#pragma once

#include "../../shared/shared.hpp"

class Var final : public Instance<Var>
{
private:
	std::string m_name{};
	void *m_ptr{};
	size_t m_type{};

public:
	Var(std::string_view name, void *const ptr, const size_t type)
		: m_name(name), m_ptr(ptr), m_type(type), Instance(this) {}

public:
	std::string GetName() const { return m_name; }
	size_t GetType() const { return m_type; }

public:
	template <typename T>
	T &As() { return *reinterpret_cast<T *>(m_ptr); }
};

#define MAKE_VAR(name, val) \
namespace vars { inline auto name{ val }; } \
namespace make_var { inline Var name{ #name, &vars::name, typeid(vars::name).hash_code() }; }