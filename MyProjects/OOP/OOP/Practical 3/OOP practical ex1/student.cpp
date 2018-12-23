#include "student.h"
#include <string>
#include <sstream>

using namespace std;

std::string Student::toString()
{
	stringstream buff;
	buff << "ID: " << id << ",  Name: " << name << ",  Group: " << group << ",  Grade: " << grade << ",  Teacher: " << teacher;
	return buff.str();
}

std::string Student::stri()
{
	stringstream buff;
	buff << id << ',' << name << ',' << group << ',' << grade << ',' << teacher;
	return buff.str();
}
