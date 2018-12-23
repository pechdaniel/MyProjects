#pragma once
#include <string>
#include <vector>
#include "student.h"
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

template <typename T>
class StudentRepo
{
private:
	std::vector<T> elems;
	std::string filename;
public:
	StudentRepo(std::string filename) :filename{ filename } { this->readFromFile(); this->sortMe(); }
	StudentRepo() :filename{ "" } {}
	~StudentRepo() {}

	void writeToFile();
	void readFromFile();

	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }
	
	T operator[](int pos) { return elems[pos]; }
	void setElems(std::vector<T> v) { elems = v; }
	//Sets the grade of the student from the given position to be equal to gr
	void gradeStudent(int pos, double gr) { elems[pos].setGrade(gr); }
	//Sets the teacher name for the student, used after giving a grade
	void setTeacher(int pos, std::string name);
	int findByID(int id);

	void sortOne();
	void sortTwo();
	void sortMe();
	std::vector<T> getByGroups(std::vector<int> gr);

	//Adds a new element to the repository
	void add(T e) { elems.push_back(e); }
	//Deletes the element on the given position
	void del(int pos) { elems.erase(elems.begin() + pos); }
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
inline void StudentRepo<T>::setTeacher(int pos, std::string name)
{
	elems[pos].setTeacher(name);
}

template<typename T>
inline int StudentRepo<T>::findByID(int id)
{
	for (int i = 0;i < elems.size();i++)
		if (elems[i].getID() == id)
			return i;
	return -1;
}

template<typename T>
inline void StudentRepo<T>::sortOne()
{
	int i, j, min_idx;


	for (i = 0; i < this->getLenght() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
			if (this->elems[j].getGroup() < this->elems[min_idx].getGroup())
				min_idx = j;

		T a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

template<typename T>
inline void StudentRepo<T>::sortTwo()
{
	int i, j, min_idx;


	for (i = 0; i < this->getLenght() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
		if(this->elems[j].getGroup()== this->elems[min_idx].getGroup()) 
		{
			if (this->elems[j].getName() < this->elems[min_idx].getName())
				min_idx = j;
		}

		T a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

template<typename T>
inline void StudentRepo<T>::sortMe()
{
	this->sortOne();
	this->sortTwo();
}

template<typename T>
inline std::vector<T> StudentRepo<T>::getByGroups(std::vector<int> gr)
{
	std::vector<T> go;
	for (auto i : elems)
		for (auto j : gr)
			if (i.getGroup() == j)
				go.push_back(i);
	return go;
}