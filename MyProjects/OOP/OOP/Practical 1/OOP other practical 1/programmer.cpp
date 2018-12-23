#include "programmer.h"
#include <string>
#include <sstream>

using namespace std;

std::string Programmer::toString()
{
	stringstream buff;
	buff << "ID: " << id << ",  Name: " << name;
	return buff.str();
}

std::string Programmer::stri()
{
	stringstream buff;
	buff << id << "," << name;
	return buff.str();
}
