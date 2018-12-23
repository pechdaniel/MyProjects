#include "StarRepo.h"
#include <fstream>
#include <sstream>

using namespace std;

void StarRepo::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		return;

	while (getline(file, i))
	{
		std::vector<string> v;
		std::stringstream line(i);
		while (getline(line, t, ','))
			v.push_back(t);
		string f, n;
		double p, lo;
		f = v[0];
		n = v[1];
		p = stod(v[2]);
		lo = stod(v[3]);
		Star m{ f,n,p,lo };
		this->elems.push_back(m);
	}
	file.close();
}

void StarRepo::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		return;

	for (int i = 0;i < this->getLenght();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

std::vector<Star> StarRepo::filter(std::string co)
{
	std::vector<Star> s;
	for (auto i : elems)
		if (i.getConste() == co)
			s.push_back(i);
	return s;
}
