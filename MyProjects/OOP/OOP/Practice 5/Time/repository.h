#pragma once
#pragma once
#include "domain.h"
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
	T operator[](int pos) { return this->elems[pos]; }

	void add(T e) { this->elems.push_back(e); }

	//Sorts the elements from the repository in alphabetical order, by their family name.
	void sort();
	//Returns an integer that represents the overall duration of tasks with a given priority
	int calculateDuration(int prio);

	void writeToFile();
	void readFromFile();
};

template<typename T>
inline void Repository<T>::sort()
{
	int i, j, min_idx;


	for (i = 0; i < this->getLenght() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
			if (this->elems[j].getPriority() < this->elems[min_idx].getPriority())
				min_idx = j;

		T a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

template<typename T>
inline int Repository<T>::calculateDuration(int prio)
{
	int ok=0;
	for (auto i : this->elems)
	{
		if (i.getPriority() == prio)
			ok = ok + i.getDuration();
	}
	return ok;
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
		while (getline(line, t, ','))
			v.push_back(t);
		string f, n, p;
		f = v[0];
		n = v[1];
		p = v[2];
		int ok1, ok2;
		ok1 = stoi(n);
		ok2 = stoi(p);
		Task m{ f,ok1,ok2 };
		this->elems.push_back(m);
	}
	file.close();
}