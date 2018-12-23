#pragma once
#include "vegetable.h"
#include <sstream>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

template <typename T>
class Repository
{
private:
	std::vector<T> elems{};
	std::string filename;
public:
	Repository() :filename{ "" } {}
	Repository(std::string file) :filename{ file } { this->readFromFile(); }
	Repository(std::string file, std::vector<T> el) :filename{ file }, elems{ el } { this->readFromFile(); }
	~Repository() {}

	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }
	void add(T e) { this->elems.push_back(e); this->writeToFile(); }
	void Add(T e) { this->elems.push_back(e); }
	void del(int pos) { this->elems.erase(this->elems.begin() + pos); this->writeToFile(); }
	void Del(int pos) { this->elems.erase(this->elems.begin() + pos); }
	vector<T> getOnly();
	T operator[](int pos) { return this->elems[pos]; }

	//Sorts the elements from the repository in alphabetical order, by their family name.
	void sort();
	//Returns all the elements that are part of a given family
	std::vector<T> filter(std::string family);

	void writeToFile();
	void readFromFile();
};

template<typename T>
inline vector<T> Repository<T>::getOnly()
{
	vector<T> el{};
	for (int i = 0;i < this->elems.size();i++)
	{
		int ok = 1;
		for (int j = 0;j < el.size();j++)
			if (el[j].getFamily() == this->elems[i].getFamily())
			{
				ok = 0;
				break;
			}
		if (ok == 1)
			el.push_back(this->elems[i]);
	}
	return el;
}

template<typename T>
inline void Repository<T>::sort()
{
	int i, j, min_idx;


	for (i = 0; i < this->getLenght() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
			if (this->elems[j].getFamily() < this->elems[min_idx].getFamily())
				min_idx = j;

		T a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

template<typename T>
inline std::vector<T> Repository<T>::filter(std::string family)
{
	vector<T> v{};
	for (auto i : this->elems)
	{
		if (i.getFamily() == family)
			v.push_back(i);
	}
	return v;
}

template<typename T>
inline void Repository<T>::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		return;

	for (int i = 0;i < this->getLenght();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

template<typename T>
inline void Repository<T>::readFromFile()
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
		Vegetable m{ f,n,y };
		this->elems.push_back(m);
	}
	file.close();
}