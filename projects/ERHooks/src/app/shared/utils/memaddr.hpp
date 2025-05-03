#pragma once

#include <compare>
#include <vector>

class MemAddr final
{
private:
	uintptr_t m_addr{};

public:
	MemAddr() = default;
	MemAddr(const uintptr_t addr) { m_addr = addr; }
	MemAddr(const int32_t addr) { m_addr = addr; }
	MemAddr(void *const addr) { m_addr = reinterpret_cast<uintptr_t>(addr); }

public:
	MemAddr &operator=(const MemAddr &other)
	{
		if (this != &other) {
			m_addr = other.m_addr;
		}

		return *this;
	}

	MemAddr operator+(const MemAddr &other) const
	{
		return { m_addr + other.m_addr };
	}

	MemAddr operator-(const MemAddr &other) const
	{
		return { m_addr - other.m_addr };
	}

	std::strong_ordering operator<=>(const MemAddr &other) const
	{
		return m_addr <=> other.m_addr;
	}

	bool operator==(const MemAddr &other) const
	{
		return m_addr == other.m_addr;
	}

	operator bool() const
	{
		return m_addr > 0;
	}

public:
	uintptr_t Get() const { return m_addr; }
	void Set(const uintptr_t addr) { m_addr = addr; }

public:
	MemAddr Offset(const size_t offset);
	MemAddr Deref(size_t count = 1);
	MemAddr Rip(const size_t offset = 1);

public:
	template <typename T>
	T As() {
		return reinterpret_cast<T>(m_addr);
	}

	template <typename T, typename... Args>
	T Call(Args... args) const {
		return reinterpret_cast<T(__fastcall *)(Args...)>(m_addr)(args...);
	}
};