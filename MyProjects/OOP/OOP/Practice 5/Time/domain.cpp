#include "domain.h"
#include <sstream>
#include <string>

using namespace std;

std::string Task::toString()
{
	stringstream buff;
	buff << "Description: " << this->description << ",  Duration: " << this->duration << ",  Priority: " << this->priority;
	return buff.str();
}

std::string Task::stri()
{
	stringstream buff;
	buff << this->description << ',' << this->duration << ',' << this->priority;
	return buff.str();
}
