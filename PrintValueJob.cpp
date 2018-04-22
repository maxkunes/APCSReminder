#include "stdafx.h"
#include "PrintValueJob.h"
#include <iostream>
#include <string>
PrintValueJob::PrintValueJob() : CommandJob::CommandJob("PrintArgs")
{
	
}

bool PrintValueJob::OnCommand(const Command & cmd)
{
	if (cmd.commandArgs.empty())
		return false;

	for(auto& arg : cmd.commandArgs) {
		std::cout << arg << std::endl;
	}

	return true;
}
