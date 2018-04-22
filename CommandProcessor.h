#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Command.h"
#include "CommandJob.h"
class CommandWork {
	std::string commandTitle;
};

class CommandProcessor {
private:
	std::vector<std::string> rawCommands;
	std::vector<Command> parsedCommands;
	std::map<std::string, std::unique_ptr<CommandJob>> commandJobs; // Map of key std::string representing the commandname of the job and the value being the job that the command should execute
	static int commandCount;

public:
	CommandProcessor();

	void AddJobForCommand(std::unique_ptr<CommandJob>& job);


	// Processes an incoming command. If the method fails to parse the command or the command is unknown, this will return false indicating failure, else return true
	bool ProcessCommand(const std::string& rawCmd);

	bool ProcessCommand(const Command& cmd);

};