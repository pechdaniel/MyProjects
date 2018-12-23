#pragma once
#include <string>

class Movie {
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;
public:
	Movie() :title{ "" }, genre{ "" }, year{}, likes{}, trailer{ "" } {}
	Movie(std::string title, std::string genre, int year, int likes, std::string trailer) :title{ title }, genre{ genre }, year{ year }, likes{ likes }, trailer{ trailer } {}
	~Movie() {}
	std::string getTitle() { return title; }
	std::string getGenre() { return genre; }
	int getYear() { return year; }
	int getLikes() { return likes; }
	std::string getTrailer() { return trailer; }
	void setTitle(std::string title);
	void setGenre(std::string genre);
	void setYear(int year);
	void setLikes(int likes);
	void setTrailer(std::string trailer);
	std::string toString();
	std::string stri();

	bool operator==(Movie m) { return (title == m.title && genre == m.genre && year == m.year && likes == m.likes && trailer == m.trailer); }
	void operator=(Movie m);
	void incLikes() { likes++; }

	void watch();
};