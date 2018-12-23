#pragma once
#pragma once
#include "domain.h"
#include <iostream>

typedef Player TElement;

class Vector
{
private:
	TElement * elems;
	int len;
	int cap;
public:
	Vector(int cap = 10);
	Vector(const Vector& v);
	~Vector();

	Vector& operator=(const Vector& v);

	TElement& operator[](int pos);

	void add(const TElement& e);
	int getLenght() const;

	Player get(int pos);
	TElement* getAll() const;
private:
	void resize(int times = 2);
};










