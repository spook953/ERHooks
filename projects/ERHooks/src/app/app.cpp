#include "app.hpp"

bool App::LoadAddresses()
{
	bool had_err{};

	for (Addr *const addr : Instances<Addr>::Get())
	{
		if (addr->Init()) {
			Log::Oke("found '{}' at {:X}", addr->GetName(), addr->GetAddr().Get());
			continue;
		}

		Log::Err("failed to find '{}'", addr->GetName());

		had_err = true;
	}

	return !had_err;
}

bool App::LoadHooks()
{
	if (MH_Initialize() != MH_OK) {
		return false;
	}

	bool had_err{};

	for (Hook *const hook : Instances<Hook>::Get())
	{
		if (hook->Init()) {
			Log::Oke("hooked '{}' {:X} -> {:X}", hook->GetName(), hook->GetSrcFn().Get(), hook->GetDstFn().Get());
			continue;
		}

		Log::Err("failed to create hook '{}'", hook->GetName());

		had_err = true;
	}

	if (!had_err)
	{
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			return false;
		}
	}

	return !had_err;
}

bool App::Load()
{
	Log::AllocCon("ERHooks");

	if (!LoadAddresses()) {
		Log::Err("failed to load addresses");
		return false;
	}

	if (!Renderer::Load()) {
		Log::Err("failed to load renderer");
		return false;
	}

	if (!LoadHooks()) {
		Log::Err("failed to load hooks");
		return false;
	}

	Log::Oke("loaded!");

	return true;
}

void App::Unload()
{
	bool had_err{};

	if (MH_Uninitialize() != MH_OK) {
		Log::Err("failed to unload hooks");
		had_err = true;
	}

	if (!Renderer::Unload()) {
		Log::Err("failed to unload renderer");
		had_err = true;
	}
	
	Log::FreeCon(!had_err);
}