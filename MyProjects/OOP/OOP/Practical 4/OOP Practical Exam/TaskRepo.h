#pragma once
#include <string>
#include <vector>
#include "task.h"
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
class TaskRepo
{
private:
	std::vector<T> elems;
	std::string filename;
public:
	TaskRepo(std::string f) :filename{ f } { this->readFromFile();  this->sortMe(); }
	TaskRepo() :filename{ "" } {}
	~TaskRepo() {}

	void writeToFile();
	void readFromFile();

	void sortMe();

	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }

	void add(T e) { elems.push_back(e); }
	//Deletes an element from the given position from the vector 'elems'
	//in: int pos, the position of the element
	//out: the element from position pos was deleted
	void del(int pos) { elems.erase(elems.begin() + pos); }

	T operator[](int pos) { return elems[pos]; }
	TaskRepo<T>& operator=(TaskRepo<T>& p);
	
	void setThisProgress(int pos) { elems[pos].setProgress(); }
	void setThisID(int pos, int id) { elems[pos].setID(id); }
	void setThisClosed(int pos) { elems[pos].setClosed(); }
};

template<typename T>
inline void TaskRepo<T>::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		return;

	for (int i = 0;i < this->elems.size();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

template<typename T>
inline void TaskRepo<T>::readFromFile()
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
		int id, stat;
		id = stoi(v[2]);
		stat = stoi(v[1]);
		string desc = v[0];
		Task m{ desc,stat,id };
		this->elems.push_back(m);
	}
	file.close();
}

template<typename T>
inline void TaskRepo<T>::sortMe()
{
	int i, j, min_idx;


	for (i = 0; i < this->getLenght() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < this->getLenght(); j++)
			if (this->elems[j].getIntStat() < this->elems[min_idx].getIntStat())
				min_idx = j;

		T a1 = this->elems[min_idx];
		this->elems[min_idx] = this->elems[i];
		this->elems[i] = a1;
	}
}

template<typename T>
inline TaskRepo<T>& TaskRepo<T>::operator=(TaskRepo<T>& p)
{
	this->elems = p.elems;
	this->filename = p.filename;
	return *this;
}
