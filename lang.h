#include "console_key_logs.h"

#ifndef LANG_H
#define LANG_H

#define ss_pair pair<string, string>


class LangModel
{
private:
	map<string, string> * _language_couple;
public:
	LangModel()
	{
		_language_couple = new map<string, string>();
	}
	void add(string key, string value)
	{
		_language_couple->insert(pair<string, string>(key, value));
	}
	string get(string key)
	{
		return _language_couple->at(key);
	}
	~LangModel()
	{
		_language_couple->clear();
		delete _language_couple;
	}
};

class LangManager
{
private:
	vector<string> * _languages;
	LangModel * _lang_model;
public:
	LangManager()
	{
		_languages = new vector<string>();
		_lang_model = new LangModel();
	}
	void add_language(string lang)
	{
		_languages->push_back(lang);
	}
	void add(string lang, ss_pair pair)
	{
		_lang_model->add(lang + "." + pair.first, pair.second);
	}
	string get(string lang, string key)
	{
		return _lang_model->get(lang + "." + key);
	}
	~LangManager()
	{
		_languages->clear();
		delete _languages;
		delete _lang_model;
	}
};


class ILanguageTool abstract
{
public:
	virtual void init() = 0;
	virtual void create() {}
	virtual void destroy() = 0;
};

class LanguageTool : public ILanguageTool
{
	LangManager * _lang_manager = nullptr;
public:
	const string eng = "en";
	const string ukr = "ua";
	void init() override
	{
		_lang_manager = new LangManager();
	}


	void create() override
	{
		
		//Lang init
		_lang_manager->add_language(eng);
		_lang_manager->add_language(ukr);

		//Eng
		_lang_manager->add(eng, ss_pair(ConsoleKeyLogs::console_created, "Console is created"));
		_lang_manager->add(eng, ss_pair(ConsoleKeyLogs::console_destroyed, "Console is destroyed"));
		_lang_manager->add(eng, ss_pair(ConsoleKeyLogs::console_change_lang, "Console is changed language"));


		//Ukr
		_lang_manager->add(ukr, ss_pair(ConsoleKeyLogs::console_created, "Косноль створена"));
		_lang_manager->add(ukr, ss_pair(ConsoleKeyLogs::console_destroyed, "Консоль знищена"));
		_lang_manager->add(ukr, ss_pair(ConsoleKeyLogs::console_change_lang, "Консоль змінила мову"));
	}

	void set_tr(string key, string value1, string value2)
	{
		_lang_manager->add(eng, ss_pair(key, value1));
		_lang_manager->add(ukr, ss_pair(key, value2));
	}

	string tr(string lang, string key)
	{
		return _lang_manager->get(lang, key);
	}

	
	void destroy() override
	{
		if(_lang_manager != nullptr)
			delete _lang_manager;
	}
};


#endif // !LANG_H

