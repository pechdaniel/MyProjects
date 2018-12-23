#pragma once
#include <iostream>


class Player
{
private:
	std::string name;
	std::string nationality;
	std::string team;
	int goals;
public:
	std::string getName() { return name; };
	std::string getNationality() { return nationality; };
	std::string getTeam() { return team; };
	int getGoals() { return goals; };

};