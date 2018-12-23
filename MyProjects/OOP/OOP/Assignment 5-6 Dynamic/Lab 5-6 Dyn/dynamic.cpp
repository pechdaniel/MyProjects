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



void Vector::add(const TElement & e)
{
	if (this->len == this->cap)
		this->resize();
	this->elems[this->len] = e;
	this->len++;
}

void Vector::del(int pos)
{
	TElement* e = new TElement[this->cap];
	int k = 0;
	for(int i=0;i<this->len;i++)
		if (i != pos)
		{
			e[i] = this->elems[i];
			k++;
		}
	delete[] this->elems;
	this->elems = e;
	this->len--;
}

int Vector::getLenght() const
{
	return this->len;
}

Movie Vector::get(int pos)
{
	if (pos < 0 || pos >= this->getLenght())
		return Movie{};
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

void Vector::incLikes(int pos)
{
	this->elems[pos].incL();
}

Vector & operator+(Vector & v, const Movie & m)
{
	if (v.len == v.cap)
		v.resize();
	v.elems[v.len] = m;
	v.len++;
	return v;
}

Vector & operator+(const Movie & m, Vector & v)
{
	if (v.len == v.cap)
		v.resize();
	v.elems[v.len] = m;
	v.len++;
	return v;
}
