#include "Reminder.h"
#include <ctime>
#include <iomanip>
Reminder::Reminder()
{
	running = false;
}

void Reminder::Start(std::chrono::nanoseconds timeTillDone)
{
	running = true;
	startTime = std::chrono::steady_clock::now();
	endTime = startTime + timeTillDone;
}

void Reminder::Stop(bool didWholeTimeElapse)
{
	running = false;

	if (!didWholeTimeElapse)
		return;
	else {
		this->OnDone(endTime - startTime);
	}
}

bool Reminder::IsRunning()
{
	return running;
}

std::chrono::time_point<std::chrono::steady_clock> Reminder::GetStartTime()
{
	return startTime;
}

std::chrono::time_point<std::chrono::steady_clock> Reminder::GetEndTime()
{
	return endTime;
}



time_t steady_clock_to_time_t(std::chrono::steady_clock::time_point t)
{
	return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() + std::chrono::duration_cast<std::chrono::system_clock::duration>(t - std::chrono::steady_clock::now()));
}

std::string Reminder::ConvertTimeToString(std::chrono::time_point<std::chrono::steady_clock> t)
{
	std::time_t time = steady_clock_to_time_t(t);
	std::tm timetm = *std::localtime(&time);
	return std::string(std::ctime(&time));
}


std::chrono::duration<double> Reminder::GetTimeLeft()
{
	return endTime - std::chrono::steady_clock::now();
}
