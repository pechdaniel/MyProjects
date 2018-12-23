#pragma once
#include "Repository.h"

class Controller {
private:
	Repository repo;
public:
	Controller(const Repository& r) :repo{ r } {}
	Repository getRepo() { return repo; }
	int findByName(std::string name);
	int findbyID(int id);
	bool add(Pilot p);
	bool del(int id);
	bool update(int id, std::string name, int age, int flights);
};