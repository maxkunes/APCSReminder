#pragma once
#include <iostream>
#include <vector>
/* Basic command format :

The command name is case insensitive as all command names internally and externally are converted to lowercase.
Arguments are prefixed by a single dollar sign '$'.
Every section of the command are separated by atleast one space character ' '.

-CommandName $arg0 $arg1 $arg2 $arg3 $arg(n)...

*/

class Command {
public:
	std::string commandTitle;
	std::vector <std::string> commandArgs;
	int commandId;
	Command();
};