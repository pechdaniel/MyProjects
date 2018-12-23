#pragma once
#include "Domain.h"
#include <vector>
#include <algorithm>

using namespace std;

class Repository {
private:
	vector<Pilot> elems{};
public:
	Repository() {};
	vector<Pilot> getAll() {
		return elems;
	}
	Pilot& operator[](int pos) { return elems[pos]; };
	void add(Pilot p);
	void del(int pos);
	void update(int id, string name, int age, int flights);
	int getLenght() { return elems.size(); }
};