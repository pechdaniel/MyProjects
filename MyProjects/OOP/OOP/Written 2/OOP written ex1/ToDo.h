#pragma once
#include <string>
#include <iterator>
#include <sstream>

class Activity
{
private:
	std::string what;
	std::string time;
public:
	Activity() :what{ "" }, time{ "" } {}
	Activity(std::string w, std::string t) :what{ w }, time{ t } {}
	~Activity() {}

	std::string getWhat() { return what; }
	std::string getTime() { return time; }

	friend std::ostream& operator<<(std::ostream& o, Activity& a);
};

std::ostream& operator<<(std::ostream& o, Activity& a);

template <typename T>
class ToDo
{
private:
	T * elems;
	int cap;
	int len;
public:
	ToDo(int c, int l) :len{ l }, cap{ c } { elems = new T[c]; }
	ToDo() :len{ 0 }, cap{ 10 } { elems = new T[10]; }
	~ToDo() { delete[] elems; }

	ToDo& operator+=(T e);

	void reversePrint(std::ostream& s);

	class iterator :public std::iterator<std::forward_iterator_tag, T>
	{
	private:
		T * ptr;
	public:
		iterator(T* p) :ptr{ p } {}
		iterator operator++() { this->ptr++; return this->ptr; }
		iterator operator++(int) { iterator i{ this->ptr }; this->ptr++; return i; }
		bool operator!=(const iterator& it) { return this->ptr != it.ptr; }
		bool operator==(const iterator& it) { return this->ptr == it.ptr; }
		T& operator*() { return *this->ptr; }
		T& operator->() { return this->ptr; }
	};
	iterator begin()
	{
		return iterator{ this->elems };
	}
	iterator end()
	{
		return iterator(this->elems + this->len);
	}
};

template<typename T>
inline ToDo<T> & ToDo<T>::operator+=(T e)
{
	if (len == cap)
		return *this;
	elems[len] = e;
	len++;
	return *this;
}

template<typename T>
inline void ToDo<T>::reversePrint(std::ostream& s)
{
	for (int i = len - 1;i >= 0l;i--)
		s << elems[i] << " ";
	s << "\n";
}
