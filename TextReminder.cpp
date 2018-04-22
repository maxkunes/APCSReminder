#include "TextReminder.h"
#include <sstream>
#include <windows.h>
TextReminder::TextReminder(std::string text) : Reminder()
{
	textToShow = text;
}

void TextReminder::OnDone(std::chrono::duration<double> timeElapsed)
{
	///std::cout << textToShow << std::endl;
	MessageBoxA(NULL, textToShow.c_str(), "Text Reminder", NULL);
}

std::string TextReminder::GetDescription()
{
	std::stringstream stream;

	stream << "TextReminder with message " << "'" + textToShow << "' was started on " << ConvertTimeToString(GetStartTime()) << " and will end on " << ConvertTimeToString(GetEndTime()) << ".";

	return stream.str();
}
