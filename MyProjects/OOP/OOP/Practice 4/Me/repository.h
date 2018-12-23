#pragma once
#include "dynamic.h"
#include <iostream>

class Repository
{
private:
	Vector concerts;
public:
	Repository() {}
	int addConcert(const Concert& c);
	int delConcert(const std::string& band);
	int updateConcert(const std::string& oldBand, const std::string& newBand, int likes);
	Concert findByBand(const std::string& band);
	int find(const Concert& c);
	Vector getConcerts();
};