#include "CommandProcessor.h"
#include "PrintValueJob.h"
int main()
{
	CommandProcessor cmdProcessor;

	std::unique_ptr<CommandJob> printJob = std::make_unique<PrintValueJob>();
	cmdProcessor.AddJobForCommand(printJob);

	if (!cmdProcessor.ProcessCommand("-PrintArgs $test0 $test1"))
		std::cout << "Failed to process command...\r\n";


	getchar();
    return 0;
}

