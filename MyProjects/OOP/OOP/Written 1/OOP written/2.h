#pragma once
#include <iostream>
class B
{
public:
	B() { std::cout << "B{}"; }
	virtual void print() {
		std::cout <<
			"B";
	}
	virtual ~B() { std::cout << "~B()"; }
};
class D : public B
{
public:
	D() { std::cout << "D{}"; }
	void print() override {
		std::cout <<
			"D";
	}
	~D() override { std::cout << "~D()"; }
};

class Person
{
public:
	Person() { std::cout << "Person{}"; }
	virtual void print() = 0;
	void no(){}
	~Person() {
		std::cout <<
			"~Person()";
	}
};
class Student : public Person
{
public:
	Student() {
		std::cout << "Student{}";
	}
	void print() override {
		std::cout <<
			"Student";
	}
	~Student() {
		std::cout <<
			"~Student()";
	}
};

class E
{
public:
	E() { std::cout << "E{}"; }
	virtual ~E() { std::cout << "~E()"; }
};
class DE : public E
{
public:
	static int n;
	DE() { n++; }
};
int DE::n = 0;
int fct2(int x)
{
	if (x < 0)
	{
		throw E{};
		std::cout << "number less than 0" << std::endl;
	}
	else if (x == 0)
	{
		throw DE{};
		std::cout << "number equal to 0"
			<< std::endl;
	}
	return x % 10;
}