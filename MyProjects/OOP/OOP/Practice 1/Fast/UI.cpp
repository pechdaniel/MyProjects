#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

template <typename T>
void UI<T>::printMenu()
{
	cout << "0. Exit" << endl;
	cout << "1. Add" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Update" << endl;
	cout << "4. Print" << endl;
}

template <typename T>
void UI<T>::printStudent(T s)
{
	cout << "ID: " << s.getID() << ",  Name: " << s.getName() << ",  Age: " << s.getAge();
}

template <typename T>
void UI<T>::printRepo()
{
	if (this->contro.getAll().getLenght() == 0)
	{
		cout << "Empty";
		return;
	}
	for (auto i : this->contro.getAll().getAll())
	{
		cout<<i.overString();
		cout << endl;
	}
}

template <typename T>
void UI<T>::start()
{
	while (true)
	{
		int command;
		UI<T>::printMenu();
		cout << "command: ";
		cin >> command;
		if (command == 0)
			break;
		while (true)
		{
			if (command == 1)
			{
				int id, age;
				string name;
				cout << "ID: Name: Age:";
				cin >> id>> name>> age;
				T s{ id,name,age };
				if (this->contro.add(s) == false)
					cout << "Nope";
				else
					cout << "Ok";
				break;
			}
			if (command == 2)
			{
				int id;
				cout << "ID: ";
				cin >> id;
				if (this->contro.del(id) == false)
					cout << "Nope";
				else
					cout << "Ok";
				break;
			}
			if (command == 3)
			{
				int id, age;
				string name;
				cout << "ID: Name: Age:";
				cin >> id>> name>> age;
				if (this->contro.update(id, name, age) == false)
					cout << "Nope";
				else
					cout << "Ok";
				break;
			}
			if (command == 4)
			{
				UI<T>::printRepo();
				break;
			}
			break;
		}
		cout << '\n';
	}
}
