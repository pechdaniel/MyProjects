#pragma once
#include "repository.h"
#include "teacher.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class TeacherRepo :public Repository<T>
{
public:
	TeacherRepo(std::string filename) :Repository<T>(filename) { this->readFromFile(); }
	TeacherRepo() :Repository<T>() {}
	~TeacherRepo() {}

	void writeToFile() override {}
	void readFromFile() override;

	void sorted() override;

	int findByID(int id) override {}
	void setGrade(int pos, int gr) override {}
	std::vector<T> getByGroups(std::vector<int> gr) override {}
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

template<typename T>
inline void TeacherRepo<T>::sorted()
{
}