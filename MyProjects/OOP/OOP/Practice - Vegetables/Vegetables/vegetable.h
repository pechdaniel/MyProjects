#pragma once
#include <vector>
#include <string>

class Vegetable {
private:
	std::string family;
	std::string name;
	std::vector<std::string> parts{};
public:
	Vegetable() :family{ "" }, name{ "" } {}
	Vegetable( std::string fam,std::string nam, std::vector<std::string> par ) : family{ fam }, name{ nam }, parts{ par } {}
	~Vegetable() {}

	std::string getFamily() { return family; }
	std::string getName() { return name; }
	std::vector<std::string> getParts() { return parts; }

	std::string toString();
	std::string stri();
};