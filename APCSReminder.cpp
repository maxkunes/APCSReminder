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
	//CommandProcessor cmdProcessor;

	//std::unique_ptr<CommandJob> printJob = std::make_unique<PrintValueJob>();
	//cmdProcessor.AddJobForCommand(printJob);

	//if (!cmdProcessor.ProcessCommand("-PrintArgs $test0 $test1"))
		//std::cout << "Failed to process command...\r\n";

	

	//std::unique_ptr<Reminder> textRemind = std::make_unique<TextReminder>("Hello, I have finished");
	//std::unique_ptr<Reminder> soundRemind = std::make_unique<SoundReminder>();


	//pReminderSystem->AddReminder(soundRemind, std::chrono::milliseconds(5000));
	//pReminderSystem->AddReminder(textRemind, std::chrono::milliseconds(5000));
	//pReminderSystem->Start();

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

