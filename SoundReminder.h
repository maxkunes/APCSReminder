#pragma once
#include "Reminder.h"
#include <iostream>
#include <string>
class SoundReminder : public Reminder {
public:
	SoundReminder();

	virtual void OnDone(std::chrono::duration<double> timeElapsed);

	virtual std::string GetDescription();
};