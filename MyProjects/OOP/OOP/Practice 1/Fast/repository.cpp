#include "repository.h"

template <typename T>
void Repository<T>::add(T s)
{
	this->elems.push_back(s);
}

template <typename T>
void Repository<T>::del(int pos)
{
	this->elems.erase(elems.begin() + pos);
}

template <typename T>
void Repository<T>::update(int id, std::string name, int age)
{
	for (int i=0;i<this->elems.size();i++)
	{
		if (this->elems[i].getID() == id)
		{
			this->elems[i].setAge(age);
			this->elems[i].setName(name);
		}
	}
}
