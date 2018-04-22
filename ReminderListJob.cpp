#include "ReminderListJob.h"
#include "ReminderSystem.h"
#include "SoundReminder.h"
ReminderListJob::ReminderListJob() : CommandJob::CommandJob("ListReminders")
{

}

bool ReminderListJob::OnCommand(const Command & cmd)
{
	if (cmd.commandArgs.size() > 0)
		return false;

	auto& reminderList = pReminderSystem->GetReminders();

	for (auto& reminder : reminderList) {
		std::cout << reminder->GetDescription() << std::endl;
	}

	return true;
}
