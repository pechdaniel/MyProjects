#include <iostream>
#include "UI.h"
#include "Controller.h"
#include "Repository.h"

using namespace std;

int main() {
	{
		Repository r{};
		Controller c{ r };
		UI u{ c };
		u.start();
	}
	return 0;
}