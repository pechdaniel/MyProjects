#include "domain.h"
#include <sstream>

using namespace std;

void Student::setName(std::string name)
{
	this->name = name;
}

void Student::setAge(int age)
{
	this->age = age;
}

std::string Student::overString()
{
	stringstream ohYeah;
	ohYeah << "Aiesta are numele " << this->getName() << " cu ID " << this->getID() << " si varsta de " << this->getAge();
	return ohYeah.str();
}
