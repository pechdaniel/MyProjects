#pragma once
#include <string>

class Programmer
{
private:
	int id;
	std::string name;
public:
	Programmer() :id{}, name{ "" } {}
	Programmer(int id, std::string name) :id{ id }, name{ name } {}
	~Programmer() {}

	int getID() { return id; }
	std::string getName() { return name; }

	std::string toString();
	std::string stri();
};