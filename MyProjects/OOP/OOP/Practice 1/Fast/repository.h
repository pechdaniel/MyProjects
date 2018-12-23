#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>

template <typename T>
class Repository {
private:
	std::vector<T> elems{};
public:
	Repository() {}
	std::vector<T> getAll() { return elems; }
	int getLenght() { return this->elems.size(); }
	T operator[](int pos) { return elems[pos]; }
	void add(T s);
	void del(int pos);
	void update(int id, std::string name, int age);
};