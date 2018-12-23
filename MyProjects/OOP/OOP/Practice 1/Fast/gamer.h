#pragma once
#include "domain.h"

class Gamer :public Student {
private:
	std::string game;
public:
	Gamer(std::string _game, int _id, std::string _name, int _age) :Student{ _id,_name,_age }, game{ _game } {}
	std::string getGame() { return game; }
	void setGame(std::string game) { this->game = game; }
	std::string overString() override;
};