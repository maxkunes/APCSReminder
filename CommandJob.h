#pragma once
#include <iostream>
#include <functional>
#include "Command.h"

class CommandJob {
	std::string commandName;
public:
	CommandJob(const std::string name);

	const std::string& GetCommandName();

	virtual bool OnCommand(const Command& cmd) = 0;
};