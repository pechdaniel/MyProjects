#include "dynamic.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
	int cap = 2;
	this->cap = cap;
	this->len = 0;
	this->elems = new TElement[cap];
}

Vector::Vector(const Vector& v)
{
	this->len = v.len;
	this->cap = v.cap;
	this->elems = new TElement[this->cap];
	for (int i=0;i < this->len;i++)
	{
		this->elems[i] = v.elems[i];
	}
}

Vector::~Vector()
{
	delete[] this->elems;
}

Vector& Vector::operator=(const Vector& v)
{
	this->len = v.len;
	this->cap = v.cap;
	this->elems = new TElement[this->cap];
	for (int i = 0;i < this->len;i++)
	{
		this->elems[i] = v.elems[i];
	}
	return *this;
}

TElement& Vector::operator[](int pos)
{
	return this->elems[pos];
}

void Vector::add(const TElement& e)
{
	if (this->len == this->cap)
		this->resize();
	this->elems[len] = e;
	this->len++;
}

void Vector::del(int pos)
{
	TElement* e = new TElement[this->cap];
	int k = 0;
	for(int i=0;i<this->len;i++)
		if (i != pos)
		{
			e[k] = this->elems[i];
			k++;
		}
	delete[] this->elems;
	this->elems = e;
	this->len--;
}

void Vector::resize()
{
	int t = 2;
	this->cap *= static_cast<int>(t);
	TElement* e = new TElement[this->cap];
	for (int i = 0;i < this->len;i++)
		e[i] = this->elems[i];
	delete[] this->elems;
	this->elems = e;
}

TElement* Vector::getAll()
{
	return this->elems;
}