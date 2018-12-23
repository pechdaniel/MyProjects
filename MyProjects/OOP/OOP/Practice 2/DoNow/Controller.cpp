#include "Controller.h"
#include <iostream>

int Controller::findByName(std::string name)
{
	for (int i = 0;i < this->repo.getLenght();i++)
		if (this->repo[i].getName() == name)
			return i;
	return -1;
}

int Controller::findbyID(const int id)
{
	for (int i = 0;i < this->repo.getLenght();i++)
	{
		if (this->repo[i].getID() == id)
		{
			return i;
		}
	}
	return -1;
}

bool Controller::add(Pilot p)
{
	if (this->findbyID(p.getID()) == -1)
	{
		this->repo.add(p);
		return true;
	}
	return false;
}

bool Controller::del(int id)
{
	if (this->findbyID(id) == -1)
	{
		return false;
	}
	this->repo.del(this->findbyID(id));
	return true;
}

bool Controller::update(int id, std::string name, int age, int flights)
{
	int k = this->findbyID(id);
	if (k == -1)
		return false;
	this->repo.update(id, name, age, flights);
	return true;
}
