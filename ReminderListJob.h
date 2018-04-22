#pragma once
#include "CommandJob.h"
class ReminderListJob : public CommandJob {
public:
	ReminderListJob();

	virtual bool OnCommand(const Command& cmd);

};