#pragma once
#include <vector>
#include <string>
#include "teacher.h"
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
class TeacherRepo
{
private:
	std::vector<T> elems;
	std::string filename;
public:
	TeacherRepo(std::string filename) :filename{ filename } { this->readFromFile(); }
	TeacherRepo() :filename{ "" } {}
	~TeacherRepo() {}

	void readFromFile();

	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }

	T operator[](int pos) { return elems[pos]; }
	void setElems(std::vector<T> v) { elems = v; }

	void add(T e) { elems.push_back(e); }
	void del(int pos) { elems.erase(elems.begin() + pos); }
};

template<typename T>
inline void TeacherRepo<T>::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		return;

	while (getline(file, i))
	{
		std::vector<std::string> v;
		std::stringstream line(i);
		while (getline(line, t, ';'))
			v.push_back(t);
		std::string f, p;
		f = v[0];
		p = v[1];
		std::stringstream aici(p);
		std::vector<int> y{};
		while (getline(aici, t, ','))
			y.push_back(stoi(t));
		Teacher m{ f,y };
		this->elems.push_back(m);
	}
	file.close();
}
