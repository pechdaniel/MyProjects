#pragma once
#include "controller.h"

template <typename T>
class UI {
private:
	Controller<T> contro;
public:
	UI<T>(Controller<T> c) :contro{ c } {}
	void printMenu();
	void printStudent(T s);
	void printRepo();
	void start();
};