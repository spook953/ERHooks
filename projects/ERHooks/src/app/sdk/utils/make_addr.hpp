#pragma once

#include "../../shared/shared.hpp"

class Addr final : public Instance<Addr>
{
private:
	MemAddr *m_ptr{};

private:
	std::string m_name{};
	std::function<MemAddr()> m_addr_fn{};

public:
	Addr(MemAddr *const ptr, std::string_view name, const std::function<MemAddr()> &addr_fn)
		: m_ptr(ptr), m_name(name), m_addr_fn(addr_fn), Instance(this) {}

public:
	MemAddr GetAddr() const { return !m_ptr ? MemAddr{} : *m_ptr; }
	std::string GetName() const { return m_name; }

public:
	bool Init() { return m_ptr && (*m_ptr = m_addr_fn()); }
};

#define MAKE_ADDR(scope, name, addr_fn) \
namespace scope { inline MemAddr name{}; } \
namespace make_addr { inline Addr name{ &scope::name, #name, []() { return addr_fn; } }; }