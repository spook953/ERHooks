#pragma once

#include "../../shared/shared.hpp"

class Hook final : public Instance<Hook>
{
private:
	std::string m_name{};
	std::function<bool()> m_init_fn{};

private:
	void *m_og_fn{};
	void *m_src_fn{};
	void *m_dst_fn{};

public:
	Hook(std::string_view name, const std::function<bool()> &init_fn)
		: m_name(name), m_init_fn(init_fn), Instance(this) {
	}

public:
	bool Create(void *const src, void *const dst)
	{
		if (MH_CreateHook(src, dst, &m_og_fn) != MH_OK) {
			return false;
		}

		m_src_fn = src;
		m_dst_fn = dst;

		return true;
	}

public:
	std::string GetName() const { return m_name; }

public:
	MemAddr GetSrcFn() const { return m_src_fn; }
	MemAddr GetDstFn() const { return m_dst_fn; }

public:
	bool Init() const { return m_init_fn(); }

public:
	template <typename T>
	inline T Call() const { return reinterpret_cast<T>(m_og_fn); }
};

#define MAKE_HOOK(name, address, type, ...) \
namespace make_hook::name \
{\
	bool Init(); \
	inline Hook hook{ #name, Init }; \
	using fn = type(__fastcall *)(__VA_ARGS__); \
	type __fastcall Func(__VA_ARGS__); \
}\
bool make_hook::name::Init() { return hook.Create(reinterpret_cast<void *>(address), reinterpret_cast<void *>(Func)); } \
type __fastcall make_hook::name::Func(__VA_ARGS__)

#define CALL_ORIGINAL hook.Call<fn>()