#pragma once
#include "repository.h"
#include "student.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class StudentRepo :public Repository<T>
{
public:
	StudentRepo(std::string filename) :Repository<T>(filename) { this->readFromFile(); this->sorted(); }
	StudentRepo() :Repository<T>() {}
	~StudentRepo() {}

	void writeToFile() override;
	void readFromFile() override;

	void sorted() override;

	void setGrade(int pos, double gr) { elems[pos].setGrade(gr); }
	std::vector<T> getByGroups(std::vector<int> gr);

	int findByID(int id) override
	{
		for (int i = 0;this->elems.size();i++)
			if (i.getID() == id)
				return i;
		return -1;
	}
};

template<typename T>
inline void StudentRepo<T>::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		return;

	for (int i = 0;i < this->elems.size();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

template<typename T>
inline void StudentRepo<T>::readFromFile()
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
		int id, group;
		std::string name, teacher;
		double grade;
		id = stoi(v[0]);
		name = v[1];
		group = stoi(v[2]);
		grade = stod(v[3]);
		teacher = v[4];
		Student m{ id,name,group,grade,teacher };
		this->elems.push_back(m);
	}
	file.close();
}

template <typename T>
bool cmp(const T & e1, const T & e2) {
	if (e1.group != e2.group)
		return (e1.group < e2.group);
	return (e1.name < e2.name);
}

template<typename T>
inline void StudentRepo<T>::sorted()
{
	sort(this->elems.begin(), this->elems.end(), cmp);
}

template<typename T>
inline std::vector<T> StudentRepo<T>::getByGroups(std::vector<int> gr)
{
	std::vector<T> vec;
	for (auto i : elems)
		for (auto j : gr)
			if (i.getGroup() == j)
			{
				vec.push_back(i);
				break;
			}
	return vec;
}
