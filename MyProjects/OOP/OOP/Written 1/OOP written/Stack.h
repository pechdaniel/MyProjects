#pragma once
#include <string>
#include <exception>
#include <assert.h>
#include <vector>

template <typename T>
class Stack
{
private:
	int cap;
	int len;
	T* st;
public:
	Stack(int c){
		len = 0;
		cap = c;
		st = new T[c];
	}
	~Stack() { delete[] this->st; }
	Stack& operator+(const T& s)
	{
		if (len == cap)
			//throw exception("Stack is full!");
		this->st[this->len] = s;
		this->len++;
		return *this;
	}
	T pop()
	{
		len--;
		return st[len];
	}
	int getMaxCapacity() { return cap; }
	Stack& operator=(const Stack& s)
	{
		for (int i = 0;i < s.cap;i++)
			this->st[i] = s.st[i];
		return *this;
	}
	T operator[](int pos) { return st[pos]; }
};
void testStack()
{
	Stack<std::string> s{ 2 };
	assert(s.getMaxCapacity() == 2);
	try {
		s = s + "examination";
		s = s + "oop";
		s = s + "test";
	}
	catch (std::exception& e) {
		assert(strcmp(e.what(), "Stack is full!") == 0);
	}
	assert(s.pop() == "test");
	assert(s.pop() == "oop");
}
