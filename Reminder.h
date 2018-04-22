#pragma once
#include <chrono>
#include <iostream>
class Reminder {
	std::chrono::time_point<std::chrono::steady_clock> startTime, endTime;
	bool running;
public:
	
	Reminder();

	std::chrono::duration<double> GetTimeLeft();

	void Start(std::chrono::nanoseconds timeTillDone);

	void Stop(bool didWholeTimeElapse);

	bool IsRunning();

	std::chrono::time_point<std::chrono::steady_clock> GetStartTime();

	std::chrono::time_point<std::chrono::steady_clock> GetEndTime();

	std::string ConvertTimeToString(std::chrono::time_point<std::chrono::steady_clock> t);

	virtual void OnDone(std::chrono::duration<double> timeElapsed) = 0;

	virtual std::string GetDescription() = 0;
};