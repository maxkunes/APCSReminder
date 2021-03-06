#include "CommandProcessor.h"
#include "PrintValueJob.h"
#include "ReminderSystem.h"
#include "TextReminder.h"
#include "SoundReminder.h"
#include "TextReminderJob.h"
#include "SoundReminderJob.h"
#include "ReminderListJob.h"
int main()
{

	/*
	First we need to instantiate the command processor so it can start processing commands of the format described in the file Command.h
	*/
	CommandProcessor cmdProcessor; 


	std::unique_ptr<CommandJob> soundReminderJob = std::make_unique<SoundReminderJob>();
	cmdProcessor.AddJobForCommand(soundReminderJob);

	std::unique_ptr<CommandJob> reminderListJob = std::make_unique<ReminderListJob>();
	cmdProcessor.AddJobForCommand(reminderListJob);

	std::unique_ptr<CommandJob> textReminderJob = std::make_unique<TextReminderJob>();
	cmdProcessor.AddJobForCommand(textReminderJob);

	pReminderSystem = new ReminderSystem();
	pReminderSystem->Start();

	std::cout << "You can set your reminders by typing below..." << std::endl;

	while (true) {
		std::string in;
		std::cin.ignore();
		std::getline(std::cin, in);
		in = "-" + in;

		if (!cmdProcessor.ProcessCommand(in))
			std::cout << "Failed to process command : " << in << std::endl;
	}



	getchar();
    return 0;
}

