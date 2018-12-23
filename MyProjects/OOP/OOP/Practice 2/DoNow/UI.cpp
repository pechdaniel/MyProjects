#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << "1. Add" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Update" << endl;
}

void UI::printRepo()
{
	Repository r = this->contro.getRepo();
	for (auto i : r.getAll())
		cout << "ID: " << i.getID() << " Name: " << i.getName() << " Age: " << i.getAge() << " Flights: " << i.getFlights() << endl;
}

Pilot UI::readPilot()
{
	string name;
	int age, flights, id;
	cout << "Name, Age, Flights, ID:" << endl;
	cin >> name >> age >> flights >> id;
	Pilot p{ name,age,flights,id };
	return p;
}

void UI::start()
{
	int command;
	while (true)
	{
		UI::printMenu();
		cout << "command: ";
		cin >> command;
		if (command == 0)
			break;
		while (true)
		{
			if (command == 1)
			{
				Pilot p=UI::readPilot();
				this->contro.add(p);
				break;
			}
			if (command == 2)
			{
				int pos;
				cout << "id: ";
				cin >> pos;
				this->contro.del(pos);
			}
			if (command == 3)
			{
				cout << "id: name: age: flights: " << endl;
				int age, flights,id;
				string name;
				cin >> id >> name >> age >> flights;
				this->contro.update(id, name, age, flights);
			}
			if (command == 4)
			{
				if (this->contro.getRepo().getLenght() == 0)
				{
					cout << "nem" << endl;
					break;
				}
				UI::printRepo();
				break;
			}
			break;
		}
		cout << endl;
	}
}
