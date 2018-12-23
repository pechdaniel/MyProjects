#include "UI.h"
#include <iostream>

using namespace std;


void UI::printMenu()
{
	cout << "The menu is:" << endl;
	cout << "1. add a player to the list" << endl;
	cout << "2. print all players" << endl;
	cout << "3. total goals from a country" << endl;
}



void UI::start()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Please enter the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		while (true)
		{
			if(command==1)

		}
	}
}

void UI::printRepo()
{
	Vector v = this->controller.getRepo().getPlayers();
	Player* p = v.getAll();
	if (p == NULL)
		return;
	if (v.getLenght() == 0)
	{
		cout << "There are no players in the repository!" << endl;
		return;
	}
	for (int i = 0; i < v.getLenght(); i++) {
		Player m = p[i];
		cout << "Name: " << m.getName();
		cout << ", Nationality: " << m.getNationality();
		cout << ", Team: " << m.getTeam();
		cout << ", Goals: " << m.getGoals();
		cout << endl;
	}
}

void UI::addMovieToRepo()
{
	
}
