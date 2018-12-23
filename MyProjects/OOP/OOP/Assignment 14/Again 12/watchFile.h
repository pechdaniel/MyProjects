#pragma once
#include "repository.h"

class MovieFile :public Repository {
protected:
	std::string filename;
public:
	MovieFile() :Repository{}, filename(""){}
	virtual ~MovieFile() {}

	void setFilename(std::string filename);
	virtual void writeToFile() = 0;
	virtual void display() = 0;
};