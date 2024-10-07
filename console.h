#include "lang.h"

enum LoggerState
{
	Active = 1,
	NotActive = 0
};

enum LanguageUse
{
	English = 0,
	Ukrainian = 1
};

bool Logger::is_print_logs = true;

class Console
{
private:
	bool _logger_is_active;
	LanguageTool*  tool = nullptr;
	string _current_lang;

	void on_init_call()
	{
		tool = new LanguageTool();
		tool->init();
		tool->create();
	}
public:
	Console(LoggerState logger_state, LanguageUse lang_use)
	{
		(logger_state == LoggerState::Active) ? Logger::is_print_logs = true : Logger::is_print_logs = false;
		(lang_use == LanguageUse::English) ? _current_lang = "en" : _current_lang = "ua";
		on_init_call();
		Logger::info(tool->tr(_current_lang, ConsoleKeyLogs::console_created));
	}

	void text_get(string key)
	{
		Logger::log(tool->tr(_current_lang, key), Colors::BrightBlue);
	}
	void text_set(string key, string text_eng, string text_ukr)
	{
		tool->set_tr(key, text_eng, text_ukr);
	}

	void change_lang(LanguageUse lang_use)
	{
		Logger::log(tool->tr(_current_lang, ConsoleKeyLogs::console_change_lang), Colors::BrightBlue);
		(lang_use == LanguageUse::English) ? _current_lang = "en" : _current_lang = "ua";
		if (lang_use == LanguageUse::Ukrainian)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
		}
		else
		{
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
		}
	}

	~Console()
	{
		Logger::log(tool->tr(_current_lang, ConsoleKeyLogs::console_destroyed), Colors::Red);
		tool->destroy();
		delete tool;
	}
};
