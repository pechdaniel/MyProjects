#pragma once
#include <string>
#include <vector>
#include "task.h"
#include <sstream>
#include <fstream>
#include <exception>

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
	//Deletes an element from position 'pos'
	//in: int pos, the position
	//out: the element on position pos was deleted
	void del(int pos) { elems.erase(elems.begin() + pos); }

	T operator[](int pos) { return elems[pos]; }
	TaskRepo<T>& operator=(TaskRepo<T>& p);
	
	void setThisProgress(int pos);
	void setThisID(int pos, int id, std::string n) { elems[pos].setID(id); elems[pos].setProgName(n); }
	//Sets the status of an element from the position 'pos' to 'closed'
	//in: int pos, the position of the element
	//out: the status of an element from the position 'pos' has been set to 'closed'
	void setThisClosed(int pos);
	//Sets the status of an element from the position 'pos' to 'in progress' and the programmerID of the task to be the 'id'
	//in: int pos, int id, the position of the element and the new id
	//out: the status of an element from the position 'pos' has been set to 'in progress' and the programmerID is 'id'
	void updateStatusProgress(int pos, int id);
};

class Exception :public exception
{
private:
	string mess;
public:
	Exception(string m) :mess{ m },exception(m.c_str()) {}
	std::string what() { return mess; }
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
		string progn = v[3];
		Task m{ desc,stat,id,progn};
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

template<typename T>
inline void TaskRepo<T>::setThisProgress(int pos)
{
	if (elems[pos].getIntStat() == -1)
	{
		elems[pos].setProgress();
	}
	else
		throw Exception{ "Task status is not 'open'!" };
}

template<typename T>
inline void TaskRepo<T>::setThisClosed(int pos)
{
	if (elems[pos].getIntStat() == 0)
	{
		elems[pos].setClosed();
	}
	else
		throw Exception{ "Task status is not 'in progress' or you are not the one who started the task!" };
}

template<typename T>
inline void TaskRepo<T>::updateStatusProgress(int pos, int id)
{
	this->setThisProgress(pos);
	this->setThisID(pos, id,"name");
}
