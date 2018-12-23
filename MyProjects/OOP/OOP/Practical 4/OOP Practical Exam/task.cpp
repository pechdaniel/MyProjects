#include "task.h"
#include <string>
#include <sstream>

using namespace std;

std::string Task::toString()
{
	stringstream buff;
	buff << "Description: " << description << ",  Status: " << status << ",  ProgrammerID: " << programmerid;
	return buff.str();
}

std::string Task::stri()
{
	stringstream buff;
	buff << description << "," << status << "," << programmerid;
	return buff.str();
}
