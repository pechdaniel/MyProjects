#pragma once
#include <iterator>


template <typename T>
class Vector
{
private:
	T * elems;
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
	//friend Vector & operator+(Vector& v, const Movie & m);
	//friend Vector & operator+(const Movie & m, Vector& v);
	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);
	/*
	Adds a movie to the dynamic vector
	*/
	void add(const T& e);
	/*
	Deletes a movie from the dynamic vector, by position
	*/
	void del(int pos);
	/*
	Returns the lenght of the lenght of the dynamic vector
	*/
	int getLenght() const;
	T* getAll() const;
	void incLikes(int pos);

	/*
	Resizes the vector, doubleing it's capacity
	*/
	void resize(int times = 2);
public:
	class iterator : public std::iterator<std::forward_iterator_tag, T>
	{
	private:
		T * ptr;
	public:
		iterator(T* p) : ptr{ p } { }
		iterator operator++() { this->ptr++; return *this; }
		iterator operator++(int) { iterator i = *this; this->ptr++; return i; }
		T& operator*() { return *this->ptr; }
		T* operator->() { return this->ptr; }
		bool operator!=(const iterator& it) { return this->ptr != it.ptr; }
		bool operator==(const iterator& it) { return this->ptr == it.ptr; }
	};
	iterator begin()
	{
		return iterator{ this->elems };
	}

	iterator end()
	{
		return iterator{ this->elems + this->size };
	}
};

template <typename T>
Vector<T>::Vector(int cap)
{
	this->len = 0;
	this->cap = cap;
	this->elems = new T[cap];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	this->len = v.len;
	this->cap = v.cap;
	this->elems = new T[this->cap];
	for (int i = 0;i < this->len;i++)
	{
		this->elems[i] = v.elems[i];
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] this->elems;
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
	if (this == &v)
		return *this;

	this->len = v.len;
	this->cap = v.cap;

	delete[] this->elems;
	this->elems = new T[this->cap];
	for (int i = 0;i < this->len;i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename T>
T& Vector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void Vector<T>::add(const T& e)
{
	if (this->len == this->cap)
		this->resize();
	this->elems[this->len] = e;
	this->len++;
}

template <typename T>
void Vector<T>::del(int pos)
{
	T* e = new T[this->cap];
	int k = 0;
	for (int i = 0;i<this->len;i++)
		if (i != pos)
		{
			e[i] = this->elems[i];
			k++;
		}
	delete[] this->elems;
	this->elems = e;
	this->len--;
}

template <typename T>
void Vector<T>::resize(int times)
{
	this->cap *= static_cast<int>(times);

	T* e = new T[this->cap];
	for (int i = 0;i < this->len;i++)
		e[i] = this->elems[i];

	delete[] this->elems;
	this->elems = e;
}
/*
//template <typename T>
//Vector<T> & operator+(Vector<T> & v, const Movie & m)
//{
//	if (v.len == v.cap)
//		v.resize();
//	v.elems[v.len] = m;
//	v.len++;
//	return v;
//}
//
//template <typename T>
//Vector<T> & operator+(const Movie & m, Vector<T> & v)
//{
//	if (v.len == v.cap)
//		v.resize();
//	v.elems[v.len] = m;
//	v.len++;
//	return v;
//}
*/
template <typename T>
int Vector<T>::getLenght() const
{
	return this->len;
}

template <typename T>
T * Vector<T>::getAll() const
{
	return this->elems;
}

template <typename T>
void Vector<T>::incLikes(int pos)
{
	this->elems[pos].incL();
}