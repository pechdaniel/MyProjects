#pragma once
#include "StarRepo.h"
#include "AstroRepo.h"
#include <exception>

class Controller
{
private:
	StarRepo& stars;
	AstroRepo& astros;
public:
	Controller(StarRepo& s, AstroRepo& a) :stars{ s }, astros{ a } {}
	~Controller() {}

	// Adds a new star to the stars repository
	// in: Star s, is the star that is added
	// out: 's' has been added to the stars repository
	void addStar(Star s);
	// Filters the star repository by a given word by returning the filtered vector
	// in: word, the sequence that needs to be found
	// out: returns the filtered vector
	std::vector<Star> search(std::string word);

	std::vector<Star> filter(std::string co) { return stars.filter(co); }

	void save() { stars.writeToFile(); }
	StarRepo getStars() { return stars; }
};

class Exception :public std::exception
{
private:
	std::string mess;
public:
	Exception(std::string m) :mess{ m }, exception(m.c_str()) {}
	std::string what() { return mess; }
};