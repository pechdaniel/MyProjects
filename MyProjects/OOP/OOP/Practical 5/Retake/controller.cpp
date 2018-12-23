#include "controller.h"

using namespace std;

void Controller::addStar(Star s)
{
	for (auto i : stars.getAll())
		if (i.getName() == s.getName())
			throw Exception("There is a star with the same name in the repository!");
	stars.add(s);
}

std::vector<Star> Controller::search(std::string word)
{
	vector<Star> v{};
	for (auto i : stars.getAll())
		if (i.getName().find(word) != std::string::npos || i.getTemp() != std::string::npos)
			v.push_back(i);
	return v;
}
