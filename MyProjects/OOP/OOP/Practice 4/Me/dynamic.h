#pragma once
#include "domain.h"


typedef Concert TElement;
class Vector
{
private:
	TElement * elems;
	int len;
	int cap;
public:
	Vector();
	Vector(const Vector& v);
	~Vector();

	Vector& operator=(const Vector& v);
	TElement& operator[](int pos);

	void add(const TElement& e);
	void del(int pos);
	int getLenght() { return len; };
	TElement* getAll();
private:
	void resize();
};