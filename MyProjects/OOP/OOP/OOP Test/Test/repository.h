#pragma once
#include "dynamic.h"
#include <iostream>

class Repository
{
private:
	Vector players;
public:
	int addPlayer(TElement& e);
	void sortList();
	int total(const std::string country);
	Vector& getPlayers() {
		return players;
	};
};