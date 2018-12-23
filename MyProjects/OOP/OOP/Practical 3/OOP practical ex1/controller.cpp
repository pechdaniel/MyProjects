#include "controller.h"

std::vector<std::string> Controller::getTeachersNames()
{
	std::vector<std::string> vec;
	for (auto i : teachers.getAll())
		vec.push_back(i.getName());
	return vec;
}

std::vector<int> Controller::getTeacherGroups(std::string name)
{
	for (auto i : teachers.getAll())
	{
		if (i.getName() == name)
			return i.getGroups();
	}
}

int Controller::getValidID()
{
	bool ok = false;
	int myID = 0;
	while (ok == false)
	{
		ok = true;
		int k = 0;
		for (auto i : students.getAll())
			if (i.getID() == myID)
			{
				myID++;
				k++;
			}
		if (k != 0)
			ok = false;
	}
	return myID;
}
