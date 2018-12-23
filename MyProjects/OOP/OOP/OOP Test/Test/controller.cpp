#include "repository.h"
#include <iostream>
#include "controller.h"

int Controller::addRepo(TElement & e)
{
	return this->repo.addPlayer(e);
}

void Controller::sortRepo()
{
	this->repo.sortList();
}

int Controller::totalGoals(const std::string country)
{
	return this->repo.total(country);
}
