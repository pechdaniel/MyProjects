#pragma once
#include <string>

class Task
{
private:
	std::string description;
	int duration;
	int priority;
public:
	Task() :description{ "" }, duration{  }, priority{  } {}
	Task(std::string des, int dur, int prio) :description{ des }, duration{ dur }, priority{ prio } {}
	~Task() {}
	std::string getDescription() { return description; }
	int getDuration() { return duration; }
	int getPriority() { return priority; }

	std::string toString();
	std::string stri();
};