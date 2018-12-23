#include "star.h"
#include <sstream>

using namespace std;

std::string Star::toString()
{
	stringstream buff;
	buff << "Name: " << name << ",  Constellation: " << constellation << ",  Luminosity: " << luminosity << ",  Temperature: " << temperature;
	return buff.str();
}

std::string Star::stri()
{
	stringstream buff;
	buff << name << "," << constellation << "," << luminosity << "," << temperature;
	return buff.str();
}