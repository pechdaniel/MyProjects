#pragma once
#include "Controller.h"

class UI {
private:
	Controller contro;
public:
	UI(Controller c) :contro{ c }{}
	void printMenu();
	void printRepo();
	Pilot readPilot();
	void start();
};