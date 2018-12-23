#include "repository.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void Repository::add(Vegetable v)
{
	this->elems.push_back(v);
	this->writeToFile();
}

void Repository::Add(Vegetable v)
{
	for (int i = 0;i < this->elems.size();i++)
		if (this->elems[i].getFamily() == v.getFamily())
			return;
	this->elems.push_back(v);
}

void Repository::del(int pos)
{
	this->elems.erase(this->elems.begin() + pos);
	this->writeToFile();
}

void Repository::sort()
{
	int i, j, min_idx;

	
	for (i = 0; i < this->getLenght()-1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
			if (this->elems[j].getFamily() < this->elems[min_idx].getFamily())
				min_idx = j;
		
		Vegetable a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

std::vector<Vegetable> Repository::filter(std::string family)
{
	vector<Vegetable> v{};
	for (auto i : this->elems)
	{
		if (i.getFamily() == family)
			v.push_back(i);
	}
	return v;
}

void Repository::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		return;

	for (int i = 0;i < this->getLenght();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

void Repository::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		return;

	while (getline(file, i))
	{
		std::vector<string> v;
		std::stringstream line(i);
		while (getline(line, t, ';'))
			v.push_back(t);
		string f, n, p;
		f = v[0];
		n = v[1];
		p = v[2];
		stringstream aici(p);
		vector<string> y{};
		while (getline(aici, t, ','))
			y.push_back(t);
		Vegetable m{ f,n,y};
		this->elems.push_back(m);
	}
	file.close();
}
