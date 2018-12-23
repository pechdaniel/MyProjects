#pragma once
#include "repository.h"
#include <iostream>

class Controller
{
private:
	Repository repo;
public:
	Controller(const Repository& r) :repo{ r } {}

	Repository getRepo()const { return repo; };

	int addRepo(TElement& e);

	void sortRepo();

	int totalGoals(const std::string country);
};