#include "memaddr.hpp"

MemAddr MemAddr::Offset(const size_t offset)
{
	if (!m_addr || offset == 0) {
		return *this;
	}

	m_addr += offset;

	return *this;
}

MemAddr MemAddr::Deref(size_t count)
{
	while (m_addr && count > 0)
	{
		m_addr = *reinterpret_cast<uintptr_t *>(m_addr);

		if (!m_addr) {
			return *this;
		}

		count--;
	}

	return *this;
}

MemAddr MemAddr::Rip(const size_t offset)
{
	if (!m_addr || !offset) {
		return *this;
	}

	uintptr_t base{ m_addr + offset };

	base += 4ull + *reinterpret_cast<int32_t *>(base);

	m_addr = base;

	return *this;
}