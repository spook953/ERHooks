#pragma once

#include <Windows.h>

#include <iostream>
#include <format>

class Log final
{
private:
	static void EnableVirtualTerminal();

public:
	template<typename... Args>
	static void Msg(std::format_string<Args...> fmt, Args &&...args) {
		EnableVirtualTerminal();
		std::cout << "\033[37m" << "[~] " << std::format(fmt, std::forward<Args>(args)...) << "\033[0m" << '\n';
	}

	template<typename... Args>
	static void Oke(std::format_string<Args...> fmt, Args &&... args) {
		EnableVirtualTerminal();
		std::cout << "\033[92m" << "[+] " << std::format(fmt, std::forward<Args>(args)...) << "\033[0m" << '\n';
	}

	template<typename... Args>
	static void Wrn(std::format_string<Args...> fmt, Args &&... args) {
		EnableVirtualTerminal();
		std::cout << "\033[93m" << "[!] " << std::format(fmt, std::forward<Args>(args)...) << "\033[0m" << '\n';
	}

	template<typename... Args>
	static void Err(std::format_string<Args...> fmt, Args &&... args) {
		EnableVirtualTerminal();
		std::cout << "\033[91m" << "[-] " << std::format(fmt, std::forward<Args>(args)...) << "\033[0m" << '\n';
	}
};