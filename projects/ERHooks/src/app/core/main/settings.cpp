#include "settings.hpp"

void Settings::Save()
{
	std::ofstream file{ "ERHooks.ini" };

	if (!file.is_open()) {
		return;
	}

	ini::IniFile ini_file{};

	auto &settings{ ini_file["settings"] };

	for (Var *const var : Instances<Var>::Get())
	{
		const size_t type{ var->GetType() };

		if (type == typeid(int).hash_code()) {
			settings[var->GetName()] = var->As<int>();
		}

		else if (type == typeid(float).hash_code()) {
			settings[var->GetName()] = var->As<float>();
		}

		else if (type == typeid(bool).hash_code()) {
			settings[var->GetName()] = var->As<bool>();
		}
	}

	ini_file.encode(file);
}

void Settings::Load()
{
	std::ifstream file{ "ERHooks.ini" };

	if (!file.is_open()) {
		return;
	}

	const auto settings{ ini::IniFile{ file }["settings"] };
	
	for (Var *const var : Instances<Var>::Get())
	{
		if (!settings.contains(var->GetName())) {
			continue;
		}
		
		const size_t type{ var->GetType() };

		if (type == typeid(int).hash_code()) {
			var->As<int>() = settings.at(var->GetName()).as<int>();
		}

		else if (type == typeid(float).hash_code()) {
			var->As<float>() = settings.at(var->GetName()).as<float>();
		}

		else if (type == typeid(bool).hash_code()) {
			var->As<bool>() = settings.at(var->GetName()).as<bool>();
		}
	}
}