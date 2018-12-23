#include "dynamic.h"

Vector::Vector(int cap)
{
	this->len = 0;
	this->cap = cap;
	this->elems = new TElement[cap];
}

Vector::Vector(const Vector & v)
{
	this->len = v.len;
	this->cap = v.cap;
	this->elems = new TElement[this->cap];
	for (int i = 0;i < this->len;i++)
	{
		this->elems[i] = v.elems[i];
	}
}

Vector::~Vector()
{
	delete[] this->elems;
}

Vector & Vector::operator=(const Vector & v)
{
	if (this == &v)
		return *this;

	this->len = v.len;
	this->cap = v.cap;

	delete[] this->elems;
	this->elems = new TElement[this->cap];
	for (int i = 0;i < this->len;i++)
		this->elems[i] = v.elems[i];

	return *this;
}

TElement & Vector::operator[](int pos)
{
	return this->elems[pos];
}



void Vector::add(const TElement & e)
{
	if (this->len == this->cap)
		this->resize();
	this->elems[this->len] = e;
	this->len++;
}

int Vector::getLenght() const
{
	return this->len;
}

Player Vector::get(int pos)
{
	if (pos < 0 || pos >= this->getLenght())
		return Player{};
	return this->elems[pos];
}

TElement * Vector::getAll() const
{
	return this->elems;
}

void Vector::resize(int times)
{
	this->cap *= static_cast<int>(times);

	TElement* e = new TElement[this->cap];
	for (int i = 0;i < this->len;i++)
		e[i] = this->elems[i];

	delete[] this->elems;
	this->elems = e;
}
