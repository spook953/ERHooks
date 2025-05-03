#include "process.hpp"

Process::~Process()
{
	m_process_id = 0;

	if (m_process_h) {
		CloseHandle(m_process_h);
	}
}

bool Process::Initialize(std::string_view proc_name)
{
	return FindProcess(proc_name, &m_process_id);
}

bool Process::Open()
{
	return (m_process_h = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_process_id)) != 0;
}

bool Process::LoadDLL(std::string_view dll_name) const
{
	char dll_path[MAX_PATH]{ '\0' };

	const DWORD path_len{ GetFullPathNameA(dll_name.data(), MAX_PATH, dll_path, nullptr) };

	if (path_len == 0) {
		return false;
	}

	const HMODULE k32_mod{ GetModuleHandleA("KERNEL32.DLL") };

	if (k32_mod == 0) {
		return false;
	}

	const FARPROC loadlib_addr{ GetProcAddress(k32_mod, "LoadLibraryA") };

	if (loadlib_addr == 0) {
		return false;
	}

	LPVOID dll_path_loc{ VirtualAllocEx(m_process_h, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE) };

	if (dll_path_loc == 0) {
		return false;
	}

	DWORD old_prot{};

	if (VirtualProtectEx(m_process_h, dll_path_loc, path_len, PAGE_EXECUTE_READWRITE, &old_prot) == 0) {
		return false;
	}

	if (WriteProcessMemory(m_process_h, dll_path_loc, dll_path, path_len, nullptr) == 0) {
		return false;
	}

	if (VirtualProtectEx(m_process_h, dll_path_loc, path_len, old_prot, &old_prot) == 0) {
		return false;
	}

	const HANDLE remote_thread{ CreateRemoteThread(m_process_h, 0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(loadlib_addr), dll_path_loc, 0, 0) };

	if (remote_thread == 0) {
		return false;
	}

	CloseHandle(remote_thread);

	return true;
}

bool Process::FindModule(std::string_view mod_name) const
{
	if (m_process_id == 0) {
		return false;
	}

	const HANDLE snap_h{ CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_process_id) };

	if (!snap_h) {
		return false;
	}

	MODULEENTRY32 mod_entry{ .dwSize = sizeof(MODULEENTRY32) };

	for (Module32First(snap_h, &mod_entry); Module32Next(snap_h, &mod_entry);)
	{
		if (std::string_view{ mod_entry.szModule }.compare(mod_name) != 0) {
			continue;
		}

		return true;
	}

	CloseHandle(snap_h);

	return false;
}

bool Process::FindProcess(std::string_view proc_name, DWORD *const proc_id)
{
	const HANDLE snap_h{ CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) };

	if (!snap_h) {
		return false;
	}

	PROCESSENTRY32 proc_entry{ .dwSize = sizeof(PROCESSENTRY32) };

	for (Process32First(snap_h, &proc_entry); Process32Next(snap_h, &proc_entry);)
	{
		if (std::string_view{ proc_entry.szExeFile }.compare(proc_name) != 0) {
			continue;
		}

		if (proc_id) {
			*proc_id = proc_entry.th32ProcessID;
		}

		return true;
	}

	CloseHandle(snap_h);

	return false;
}