#include "logger.h"

#ifndef CKL_H
#define CKL_H

class ConsoleKeyLogs
{
public:
	static const string console_created;
	static const string console_destroyed;
	static const string console_change_lang;
};

const string ConsoleKeyLogs::console_created = "console_created";
const string ConsoleKeyLogs::console_destroyed = "console_destroyed";
const string ConsoleKeyLogs::console_change_lang = "console_change_lang";

#endif