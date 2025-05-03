#include "app.hpp"

bool App::Run()
{
	static constexpr std::string_view process_name{ "eldenring.exe" };
	static constexpr std::string_view module_name{ "ERHooks.dll" };

	Process proc{};

	if (!proc.Initialize(process_name))
	{
		Log::Msg("waiting for '{}'", process_name);

		for (; !proc.Initialize(process_name);) {
			continue;
		}
	}

	if (!proc.Open()) {
		Log::Err("failed to open process for '{}'", process_name);
		return false;
	}

	if (proc.FindModule(module_name)) {
		Log::Wrn("'{}' already loaded", module_name);
		return false;
	}

	if (!proc.LoadDLL(module_name)) {
		Log::Err("failed to load '{}'", module_name);
		return false;
	}

	return true;
}