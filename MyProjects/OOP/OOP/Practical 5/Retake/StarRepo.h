#pragma once

#include "star.h"
#include <vector>


class StarRepo
{
private:
	std::vector<Star> elems;
	std::string filename;
public:
	StarRepo() :filename{ "" } {}
	StarRepo(std::string n) :filename{ n } { this->readFromFile(); }
	~StarRepo() {}

	void readFromFile();
	void writeToFile();

	void add(Star e) { elems.push_back(e); }

	std::vector<Star> filter(std::string co);

	std::vector<Star> getAll() { return elems; }
	int getLenght() { return elems.size(); }


	Star operator[](int pos) { return elems[pos]; }

};