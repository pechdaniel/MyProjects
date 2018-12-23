#include "UI.h"
#include "controller.h"
#include "repository.h"
#include "domain.h"
#include "sportsman.h"
#include "gamer.h"
#include <iostream>

using namespace std;

int main() {
	{
		Student s{ 1,"Jambon",15 };
		Sportsman s1{ "inot",2,"Artemis",18 };
		Gamer g{ "minecraft",3,"Iulius",15 };
		cout<<s.overString();
		cout << endl << s1.overString();
		cout << endl << g.overString() << endl;
		system("pause");
		//Repository<Student> r{};
		//Controller<Student> c{ r };
		//UI<Student> ui{ c };
		//ui.start();
	}
	return 0;
}