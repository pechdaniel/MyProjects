#pragma once
#include "repository.h"

template <typename T>
class Controller {
private:
	Repository<T> repo;
public:
	Controller(Repository<T> r) :repo{ r } {}
	bool add(T s);
	bool del(int id);
	bool update(int id, std::string name, int age);
	int findByID(int id);
	Repository<T> getAll() { return repo; }
};