#include "teacher.h"
#include <string>
#include <sstream>

using namespace std;

std::string Teacher::toString()
{
	int i;
	stringstream buff;
	buff << "Name: " << name << ";  Groups: ";
	for (i = 0;i < groups.size() - 1;i++)
		buff << groups[i] << ", ";
	buff << groups[i];
	return buff.str();
}

std::string Teacher::stri()
{
	return std::string();
}
