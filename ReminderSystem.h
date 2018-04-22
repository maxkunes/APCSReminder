#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include "Reminder.h"
class ReminderSystem {
	std::vector<std::unique_ptr<Reminder>> reminders;

public:

	ReminderSystem();

	void AddReminder(std::unique_ptr<Reminder>& reminder, std::chrono::nanoseconds timeTillDone);

	void Tick();

	void Start();

	std::vector<std::unique_ptr<Reminder>>& GetReminders();
};

extern ReminderSystem* pReminderSystem;