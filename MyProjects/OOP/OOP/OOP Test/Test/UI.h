#pragma once
#include "controller.h"

class UI
{
private:
	Controller controller;
public:
	UI(const Controller& c) :controller(c) {}

	void start();
	void printRepo();
	void addMovieToRepo();
private:
	static void printMenu();	
};