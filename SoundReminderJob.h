#pragma once
#include "CommandJob.h"
class SoundReminderJob : public CommandJob {
public:
	SoundReminderJob();

	virtual bool OnCommand(const Command& cmd);

};