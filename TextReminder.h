#pragma once
#include "Reminder.h"
#include <iostream>
#include <string>
class TextReminder : public Reminder {
	std::string textToShow;
public:
	TextReminder(std::string text);

	virtual void OnDone(std::chrono::duration<double> timeElapsed);

	virtual std::string GetDescription();
};