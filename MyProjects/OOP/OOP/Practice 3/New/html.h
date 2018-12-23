#pragma once
#include "repository.h"

class HTML {
private:
	Repository repo;
	std::string filename;
public:
	HTML(Repository r) :repo{ r }, filename{ "HTMLfile.html" } { this->writeToFile(); }
	~HTML() {}
	void setRepo(Repository r);
	void writeToFile();
	void displayHTML();
};