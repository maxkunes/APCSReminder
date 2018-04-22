#include <algorithm>
#include "CommandProcessor.h"

int CommandProcessor::commandCount = 0;

CommandProcessor::CommandProcessor()
{
	rawCommands.clear();
	parsedCommands.clear();
	commandJobs.clear();
	commandCount = 0;
}

void CommandProcessor::AddJobForCommand(std::unique_ptr<CommandJob>& job)
{
	commandJobs.insert(std::make_pair(job->GetCommandName(), std::move(job)));
}


bool CommandProcessor::ProcessCommand(const std::string& rawCmd)
{

	auto findInString = [&](const std::string& haystack, char toFind, const size_t startIndex = 0) {
		if (startIndex < 0 || startIndex > haystack.size() + 1)
			return std::string::npos;

		for (size_t i = startIndex; i < haystack.size(); i++) {
			if (haystack[i] == toFind)
				return (size_t)i;
		}

		return std::string::npos;
	};

	auto getSubstringString = [&](const std::string& haystack, size_t start, size_t end) {
		if (start < 0)
			throw std::invalid_argument("start");

		if (end > haystack.size() + 1)
			throw std::invalid_argument("end");

		std::string resultString = "";

		for (size_t i = start; i < end; i++) {
			resultString += haystack[i];
		}

		return resultString;
	};


	if (rawCmd.empty()) // Command string is empty
		return false;

	auto dashChar = findInString(rawCmd,'-', 0);


	if (dashChar == std::string::npos)
		return false; // Could not find the beginning '-'

	auto nameEndingChar = findInString(rawCmd, ' ', dashChar);

	if (nameEndingChar == std::string::npos)
		return false;

	rawCommands.push_back(rawCmd);

	Command newCmd;
	newCmd.commandTitle = getSubstringString(rawCmd, dashChar + 1, nameEndingChar);
	std::transform(newCmd.commandTitle.begin(), newCmd.commandTitle.end(), newCmd.commandTitle.begin(), ::tolower); // Convert the name to lowercase as the spec defines.
	newCmd.commandId = commandCount; // Give command a unique identifier 
	commandCount++; // Increase command count.

	auto argSearchIndex = nameEndingChar + 1; // Search for args where we found the name.

	while ((argSearchIndex = findInString(rawCmd, '$', argSearchIndex)) != std::string::npos) {
	
		// Found another argument

		auto argEnd = findInString(rawCmd, ' ', argSearchIndex);

		if (argEnd == std::string::npos) {
			argEnd = rawCmd.size(); // If we can't find the separating space, this argument is the last characters in the string.
		}

		auto argStart = argSearchIndex + 1; // Go past the $ prefix.

		auto argument = rawCmd.substr(argStart, argEnd - argStart); // Grab only the argument out of the text, without the $

		newCmd.commandArgs.push_back(argument); // Add the argument to the array

		argSearchIndex = argStart; // Next iteration start searching after this argument.
	}

	return ProcessCommand(newCmd); // Pass parsed command to the actual method that executes the commands function.
}

bool CommandProcessor::ProcessCommand(const Command & cmd)
{
	if (commandJobs.count(cmd.commandTitle) == 0)
		return false; // Could not find a job that matches the target command title.

	auto& cmdJob = commandJobs[cmd.commandTitle];

	return cmdJob->OnCommand(cmd);
}

