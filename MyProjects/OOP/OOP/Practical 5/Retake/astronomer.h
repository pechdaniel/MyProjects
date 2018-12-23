#pragma once

#include <string>

class Astronomer
{
private:
	std::string name;
	std::string constellation;
public:
	Astronomer() :name{ "" }, constellation{ "" } {}
	Astronomer(std::string n, std::string c) :name{ n }, constellation{ c } {}
	~Astronomer() {}

	std::string getName() { return name; }
	std::string getConste(){ return constellation; }

	std::string toString();
	std::string stri();
};