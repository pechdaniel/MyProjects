#pragma once
#include <string>

class Star
{
private:
	std::string name;
	std::string constellation;
	double luminosity;
	double temperature;
public:
	Star() :name{ "" }, constellation{ "" }, luminosity{}, temperature{} { }
	Star(std::string n, std::string c, double l, double t) :name{ n }, constellation{ c }, luminosity{ l }, temperature{ t } { }
	~Star() {}

	std::string getName() { return name; }
	std::string getConste() { return constellation; }
	double getLumi() { return luminosity; }
	double getTemp() { return temperature; }

	std::string toString();
	std::string stri();
};