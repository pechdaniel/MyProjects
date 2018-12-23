#pragma once

#include "astronomer.h"
#include <vector>

class AstroRepo
{
private:
	std::vector<Astronomer> elems;
	std::string filename;
public:
	AstroRepo() :filename{ "" } {}
	AstroRepo(std::string n) :filename{ n } { this->readFromFile(); }
	~AstroRepo() {}

	void readFromFile();

	void add(Astronomer e) { elems.push_back(e); }

	std::vector<Astronomer> getAll() { return elems; }
	int getLenght() { return elems.size(); }

	Astronomer operator[](int pos) { return elems[pos]; }
};