#pragma once
#include "programmer.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
class ProgrammerRepo
{
private:
	std::vector<T> elems;
	std::string filename;
public:
	ProgrammerRepo(std::string f) :filename{ f } { this->readFromFile(); }
	ProgrammerRepo() :filename{ "" } {}
	~ProgrammerRepo() {}

	void readFromFile();

	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }

	T operator[](int pos) { return elems[pos]; }

	ProgrammerRepo<T>& operator=(ProgrammerRepo<T>& p);
};

template<typename T>
inline void ProgrammerRepo<T>::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		return;

	while (getline(file, i))
	{
		std::vector<std::string> v;
		std::stringstream line(i);
		while (getline(line, t, ','))
			v.push_back(t);
		int id;
		string name;
		id = stoi(v[0]);
		name = v[1];
		Programmer m{ id,name };
		this->elems.push_back(m);
	}
	file.close();
}

template<typename T>
inline ProgrammerRepo<T>& ProgrammerRepo<T>::operator=(ProgrammerRepo<T>& p)
{
	this->elems = p.elems;
	this->filename = p.filename;
	return *this;
}