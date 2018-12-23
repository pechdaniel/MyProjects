#pragma once
#include <iostream>

class Concert
{
private:
	std::string band;
	int likes;
public:
	Concert();

	Concert(const std::string band,const int likes);

	std::string getBand() { return band; };

	int getLikes() { return likes; };
};