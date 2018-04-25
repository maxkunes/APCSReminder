#include "ReminderSystem.h"
#include <thread>
#include <chrono>
ReminderSystem::ReminderSystem()
{
	reminders.clear();
}

void ReminderSystem::AddReminder(std::unique_ptr<Reminder>& reminder, std::chrono::nanoseconds timeTillDone)
{
	reminder->Start(timeTillDone);
	reminders.push_back(std::move(reminder));
}

void ReminderSystem::Start()
{
	std::thread tickThread(&ReminderSystem::Tick, this);
	tickThread.detach();
}

std::vector<std::unique_ptr<Reminder>>& ReminderSystem::GetReminders()
{
	return reminders;
}

void ReminderSystem::Tick()
{
	while (true) {

		for (auto& reminder : reminders) {
			if (reminder->IsRunning()) {
				if (reminder->GetTimeLeft().count() <= 0) {
					reminder->Stop(true); // Alert reminder that it should trigger. Also mark the reminder as not running.
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(1)); // Maximum timer accuracy of 1 second.
	}
}


ReminderSystem* pReminderSystem;