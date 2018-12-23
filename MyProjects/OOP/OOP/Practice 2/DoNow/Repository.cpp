#include "Repository.h"

void Repository::add(Pilot p)
{
	this->elems.push_back(p);
}

void Repository::del(int pos)
{
	if (pos < 0 || pos >= elems.size())
		return;
	this->elems.erase(elems.begin() + pos);
}

void Repository::update(int id, string name, int age, int flights)
{
	for (int i=0;i<elems.size();i++)
		if (elems[i].getID() == id)
		{
			elems[i].setAge(age);
			elems[i].setName(name);
			elems[i].setFlights(flights);
			break;
		}
}
