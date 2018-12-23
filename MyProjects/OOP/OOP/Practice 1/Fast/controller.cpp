#include "controller.h"

template <typename T>
bool Controller<T>::add(T s)
{
	if (this->findByID(s.getID()) == -1)
	{
		this->repo.add(s);
		return true;
	}
	return false;
}

template <typename T>
bool Controller<T>::del(int id)
{
	int k = this->findByID(id);
	if (k == -1)
		return false;
	this->repo.del(k);
	return true;
}

template <typename T>
bool Controller<T>::update(int id, std::string name, int age)
{
	int k = this->findByID(id);
	if (k == -1)
		return false;
	this->repo.update(id, name, age);
	return true;
}

template <typename T>
int Controller<T>::findByID(int id)
{
	for (int i = 0;i < this->repo.getLenght();i++)
	{
		if (this->repo[i].getID() == id)
			return i;
	}
	return -1;
}
