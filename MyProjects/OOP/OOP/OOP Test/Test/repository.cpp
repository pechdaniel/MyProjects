#include "repository.h"
#include <iostream>

int Repository::addPlayer(TElement& e)
{
	for (int i;i < this->players.getLenght();i++)
		if (this->players.get(i).getName() == e.getName())
			return 0;
	this->players.add(e);
}

void Repository::sortList()
{
	TElement m;
	int p;
	for (int i = 0; i < this->players.getLenght()-1; i++)
	{
		p = i;
		for (int j = i + 1; j < this->players.getLenght(); j++)
			if (this->players.get(j).getGoals() < this->players.get(p).getGoals())
				p = j;
		m = this->players.get(p);
		this->players.getAll()[p] = this->players.get(i);
		this->players.getAll()[i] = m;
	}
}

int Repository::total(const std::string country)
{
	int sum = 0;
	for (int i = 0;i < this->players.getLenght();i++)
		if (this->players.getAll()[i].getNationality() == country)
			sum += this->players.get(i).getGoals();
	return sum;
}

