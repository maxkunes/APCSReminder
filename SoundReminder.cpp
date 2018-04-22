#include "SoundReminder.h"
#include <windows.h>
#include <sstream>
SoundReminder::SoundReminder()
{
}

void SoundReminder::OnDone(std::chrono::duration<double> timeElapsed)
{
	Beep(523, 500);
}

std::string SoundReminder::GetDescription()
{
	std::stringstream stream;

	stream << "SoundReminder was started on " << ConvertTimeToString(GetStartTime()) << " and will end on " << ConvertTimeToString(GetEndTime()) << ".";

	return stream.str();
}

