#include "astronomer.h"
#include <sstream>

using namespace std;

std::string Astronomer::toString()
{
	stringstream buff;
	buff << "Name: " << name << ",  Constellation: " << constellation;
	return buff.str();
}

std::string Astronomer::stri()
{
	stringstream buff;
	buff << name << "," << constellation;
	return buff.str();
}
