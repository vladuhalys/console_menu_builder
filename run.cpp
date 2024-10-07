#include "console.h"

int main()
{
	Console * console = new Console(LoggerState::Active, LanguageUse::English);
	console->text_set("hello", "Hello, World!", "Привіт світ!");
	console->text_set("bye", "Goodbye, World!", "Допобачення світ!");

	do
	{
		cout << "Eng - 0, ukr - 1 ->";
		int lang;
		cin >> lang;
		console->change_lang((LanguageUse)lang);
		console->text_get("hello");
		console->text_get("bye");
		system("pause");
	} while (true);
	delete console;
}