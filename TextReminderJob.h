#pragma once

#pragma once
#include "CommandJob.h"
class TextReminderJob : public CommandJob {
public:
	TextReminderJob();

	virtual bool OnCommand(const Command& cmd);

};