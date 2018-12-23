#include "task.h"
#include <sstream>
#include <string>

using namespace std;

std::string Task::toString()
{
	stringstream buff;
	buff << "Description: " << description << ",  Status: " << status;
	return buff.str();
}

std::string Task::toString1()
{
	stringstream buff;
	buff << "Description: " << description << ",  Status: " << status << ",  ProgrammerName: " << progName;
	return buff.str();
}

std::string Task::stri()
{
	stringstream buff;
	buff<<description << "," << stat << "," << programmerid<<","<<progName;
	return buff.str();
}
