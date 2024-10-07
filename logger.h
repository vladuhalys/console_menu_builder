#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

#ifndef LOGGER_H
#define LOGGER_H

enum Colors
{
	Default = 7,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Pink = 5,
	Yellow = 6,
	White = 7,
	BrightBlue = 9,
	BrightGreen = 10,
	BrightCyan = 11,
	BrightRed = 12,
	BrightPink = 13,
	BrightYellow = 14,
	BrightWhite = 15
};

struct Logger
{
	static bool is_print_logs;
	static const unsigned short _debug = 10;
	static const unsigned short _info = 11;
	static const unsigned short _error = 12;
	static const unsigned short _warning = 14;
	static const unsigned short _default = 7;

	static void debug(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _debug);
			cout << "DEBUG: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}

	static void info(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _info);
			cout << "INFO: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void error(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _error);
			cout << "ERROR: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void warning(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _warning);
			cout << "WARNING: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}

	}

	static void log(string message, Colors color)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			cout << "LOG: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
};

#endif
