#pragma once
#include <vector>

template <typename T>
class Repository
{
private:
	std::vector<T> elems;
	std::string filename;
public:
	Repository(std::string filename) :filename{ filename } {}
	Repository() : filename{ "" } {}
	~Repository() {}

	virtual void writeToFile() {}
	virtual void readFromFile() {}

	virtual void sorted() {}

	void add(T e);
	void del(int pos);
	
	std::vector<T> getAll() { return elems; }
	int getLenght() { return elems.size(); }
	T get(int pos) { return elems[pos]; }
	T operator[](int pos) { return elems[pos]; }
	void setElems(std::vector<T> v) { elems = v; }
	virtual int findByID(int id) { return 0; }
	virtual void setGrade(int pos, int gr) {}
	virtual std::vector<T> getByGroups(std::vector<int> gr) { return elems; }
};

template<typename T>
inline void Repository<T>::add(T e)
{
	elems.push_back(e);
}

template<typename T>
inline void Repository<T>::del(int pos)
{
	elems.erase(elems.begin() + pos);
}
