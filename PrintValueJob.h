#pragma once
#include "CommandJob.h"
class PrintValueJob : public CommandJob {
public:
	PrintValueJob();

	virtual bool OnCommand(const Command& cmd);

};