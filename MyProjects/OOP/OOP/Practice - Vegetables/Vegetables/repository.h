#pragma once
#include "vegetable.h"
#include <string>

class Repository {
private:
	std::vector<Vegetable> elems{};
	std::string filename;
public:
	Repository() :filename{ "" } {}
	Repository(std::string file) :filename{ file } { this->readFromFile(); }
	~Repository() {}
	int getLenght() { return elems.size(); }
	std::vector<Vegetable> getAll() { return elems; }

	void add(Vegetable v);
	void Add(Vegetable v);
	void del(int pos);

	/*
	Sorts the elements from the repository in alphabetical order, by the family of the elements.
	*/
	void sort();
	/*
	Returns a vector only with elements that contain a given family.
	*/
	std::vector<Vegetable> filter(std::string family);

	Vegetable operator[](int pos) { return this->elems[pos]; }
	void setElems(std::vector<Vegetable> r) { this->elems = r; }

	void writeToFile();
	void readFromFile();
};