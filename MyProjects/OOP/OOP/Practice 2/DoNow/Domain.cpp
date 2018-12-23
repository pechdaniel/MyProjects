#include "Domain.h"

Pilot::Pilot() :name(""), age(), flights(), id() {}

Pilot::Pilot(const std::string name, const int age, const int flights,const int id)
{
	this->name = name;
	this->age = age;
	this->flights = flights;
	this->id = id;
}
