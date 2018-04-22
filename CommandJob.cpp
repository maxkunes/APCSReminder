#include "CommandJob.h"
#include <algorithm>
CommandJob::CommandJob(const std::string name)
{
	commandName = name;
	std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::tolower); // convert command name to lowercase
}

const std::string& CommandJob::GetCommandName()
{
	return commandName;
}

