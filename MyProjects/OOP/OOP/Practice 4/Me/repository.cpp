#include "repository.h"
#include <iostream>

using namespace std;

int Repository::addConcert(const Concert& c)
{
	if (this->find(c) != -1)
		return 0;
	this->concerts.add(c);
	return 1;
}

int Repository::delConcert(const string& band)
{
	Concert* co = this->concerts.getAll();
	for(int i=0;i<this->concerts.getLenght();i++)
		if (co[i].getBand() == band)
		{
			this->concerts.del(i);
			return 1;
		}
	return 0;
}

int Repository::updateConcert(const string& oldBand, const string& newBand, const int likes)
{
	Concert c = findByBand(oldBand);
	if (c.getBand() == "")
		return 0;
	delConcert(oldBand);
	Concert co{ newBand,likes };
	addConcert(co);
	return 1;
}

Concert Repository::findByBand(const string& band)
{
	if (this->concerts.getAll() == NULL)
		return Concert{};

	for (int i = 0;i < this->concerts.getLenght();i++)
		if (this->concerts.getAll()[i].getBand() == band)
			return this->concerts.getAll()[i];
	return Concert{};
}