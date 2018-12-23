#pragma once
#include "domain.h"
#include <iostream>

typedef Movie TElement;

class Vector
{
private:
	TElement * elems;
	int len;
	int cap;
public:
	/*
	Constructor for the dynamic vector
	*/
	Vector(int cap = 10);
	/*
	Second constructor for the dynamic vector
	*/
	Vector(const Vector& v);
	/*
	Destructor for the dynamic vector
	*/
	~Vector();
	/*
	Overwrites the = operator for the dynamic vector
	*/
	Vector& operator=(const Vector& v);
	/*
	Overwrites the + operator for the dynamic vector
	*/
	friend Vector & operator+(Vector& v, const Movie & m);
	friend Vector & operator+(const Movie & m, Vector& v);
	/*
	Adds a movie to the dynamic vector
	*/
	void add(const TElement& e);
	/*
	Deletes a movie from the dynamic vector, by position
	*/
	void del(int pos);
	/*
	Returns the lenght of the lenght of the dynamic vector
	*/
	int getLenght() const;

	Movie get(int pos);
	/*
	Returns the elements of the dynamic vector
	*/
	TElement* getAll() const;

	void incLikes(int pos);
private:
	/*
	Resizes the vector, doubleing it's capacity
	*/
	void resize(int times = 2);
};