#pragma once

#include <Windows.h>
#include <TlHelp32.h>

#include <string>

class Process final
{
private:
	DWORD m_process_id{};
	HANDLE m_process_h{};

public:
	~Process();

public:
	bool Initialize(std::string_view proc_name);
	bool Open();
	bool LoadDLL(std::string_view dll_name) const;
	bool FindModule(std::string_view mod_name) const;

private:
	static bool FindProcess(std::string_view proc_name, DWORD *const proc_id);
};