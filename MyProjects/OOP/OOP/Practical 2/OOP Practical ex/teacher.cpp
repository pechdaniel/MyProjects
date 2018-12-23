#include "teacher.h"
#include <sstream>
#include <string>

using namespace std;

std::string Teacher::toString()
{
	int i = 0;
	stringstream buff;
	buff << "Name: " << name << ",  Groups: ";
	for (i = 0; i < groups.size() - 1; i++)
		buff << groups[i] << ", ";
	buff << groups[i];
	return buff.str();
}
