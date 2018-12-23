#pragma once
#include "controller.h"
#include "csv.h"
#include "html.h"

class UI {
private:
	Controller contro;
	//CSV csv;
	//HTML html;
	int option;
public:
	UI(Controller c, int opt) :contro{ c }, option{ opt } {}
	~UI() {}
	void printMenuAdmin();
	void printMenuUser();
	void displayFile();
	//void saveFile() { html.setContro(this->contro); }
	void start();
};