#pragma once
#include "domain.h"

class Sportsman : public Student {
private:
	std::string sport;
public:
	Sportsman(std::string _sport, int _id, std::string _name, int _age) :Student{ _id,_name,_age }, sport{ _sport } {}
	std::string getSport() { return sport; }
	void setString(std::string sport) { this->sport = sport; }
	std::string overString() override;
};