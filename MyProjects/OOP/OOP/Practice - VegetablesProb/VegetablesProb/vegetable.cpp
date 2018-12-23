#include "vegetable.h"
#include <sstream>

using namespace std;

std::string Vegetable::toString()
{
	stringstream buff;
	int i;
	buff << "Family: " << this->family << ";  Name: " << this->name << ";  Parts: ";
	for (i = 0;i<this->parts.size() - 1;i++)
		buff << this->parts[i] << ", ";
	buff << this->parts[i];
	return buff.str();
}

std::string Vegetable::stri()
{
	stringstream buff;
	int i;
	buff << this->family << ';' << this->name << ';';
	for (i = 0;i<this->parts.size() - 1;i++)
		buff << this->parts[i] << ',';
	buff << this->parts[i];
	return buff.str();
}
