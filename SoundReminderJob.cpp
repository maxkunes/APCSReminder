#include "SoundReminderJob.h"
#include "ReminderSystem.h"
#include "SoundReminder.h"
SoundReminderJob::SoundReminderJob() : CommandJob::CommandJob("AddSoundReminder")
{

}

bool SoundReminderJob::OnCommand(const Command & cmd)
{
	if (cmd.commandArgs.size() < 2)
		return false;

	auto timeScale = cmd.commandArgs[0];
	auto timeAmmount = atoi(cmd.commandArgs[1].c_str());

	std::unique_ptr<Reminder> soundRemind = std::make_unique<SoundReminder>();

	if (timeScale == "seconds") {
		pReminderSystem->AddReminder(soundRemind, std::chrono::seconds(timeAmmount));
	}
	else if (timeScale == "minutes") {
		pReminderSystem->AddReminder(soundRemind, std::chrono::minutes(timeAmmount));

	}
	else if (timeScale == "hours") {
		pReminderSystem->AddReminder(soundRemind, std::chrono::hours(timeAmmount));

	} 
	else if (timeScale == "days") {
		pReminderSystem->AddReminder(soundRemind, std::chrono::hours(24) * timeAmmount);

	}
	else {
		return false;
	}
	
	std::cout << "Added a new SoundReminder that will go off in " << timeAmmount << " " <<  timeScale << "!" << std::endl;

	return true;
}
