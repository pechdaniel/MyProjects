#include "vegetable.h"
#include <sstream>
#include <string>

using namespace std;

std::string Vegetable::toString()
{
	stringstream buff;
	int i;
	buff << "Family: " << this->getFamily() << ";  Name: " << this->getName() << ";  Parts: ";
	for (i = 0;i < this->parts.size()-1;i++)
		buff << this->parts[i] << ", ";
	buff << this->parts[i];
	return buff.str();
}

std::string Vegetable::stri()
{
	stringstream buff;
	int i;
	buff << this->getFamily() << ';' << this->getName() << ';';
	for (i = 0;i < this->parts.size()-1;i++)
		buff << this->parts[i] << ',';
	buff << this->parts[i];
	return buff.str();
}
