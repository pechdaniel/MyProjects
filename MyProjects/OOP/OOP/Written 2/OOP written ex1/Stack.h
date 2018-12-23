#pragma once
#include <string>
#include <exception>
#include <sstream>

template <typename T>
class Stack
{
private:
	int cap;
	int len;
	T* elems;
public:
	Stack(int c);
	~Stack();

	int getMaxCapacity() { return cap; }

	Stack& operator=(T* v);
	T* operator+(T e);

	T pop();
};

template<typename T>
inline Stack<T>::Stack(int c)
{
	len = 0;
	cap = c;
	elems = new T[c];
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] elems;
}

template<typename T>
inline Stack<T> & Stack<T>::operator=(T * v)
{
	this->elems = v;
	return *this;
}

template<typename T>
inline T * Stack<T>::operator+(T e)
{
	if (len == cap)
	{
		std::stringstream errMsg;
		errMsg << "Stack is full!";
		throw std::exception(errMsg.str().c_str());
	}
	this->elems[len] = e;
	len++;
	return this->elems;
}

template<typename T>
inline T Stack<T>::pop()
{
	len--;
	return elems[len];
}

