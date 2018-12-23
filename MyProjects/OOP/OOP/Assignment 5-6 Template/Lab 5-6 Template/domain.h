#pragma once
#include <iostream>


class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;
public:
	Movie();

	Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer);
	
	std::string getTitle() const { return title; }

	std::string getGenre() const { return genre; }

	int getYear() const { return year; }

	int getLikes() const { return likes; }

	std::string getTrailer() const { return trailer; }

	void video();

	void incL() { likes++; };
};