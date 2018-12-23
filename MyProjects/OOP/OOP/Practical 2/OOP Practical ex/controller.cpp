#include "controller.h"

void Controller::addStudent(Student s)
{
	this->students->add(s);
}

int Controller::findByID(int id)
{
	for (int i = 0;i < this->students->getLenght();i++)
		if (this->students->get(i).getID() == id)
			return i;
	return -1;
}

void Controller::delStudent(int pos)
{
	this->students->del(pos);
}
