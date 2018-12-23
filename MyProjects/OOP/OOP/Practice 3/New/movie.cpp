#include "movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <sstream>

void Movie::setTitle(std::string title)
{
	this->title = title;
}

void Movie::setGenre(std::string genre)
{
	this->genre = genre;
}

void Movie::setYear(int year)
{
	this->year = year;
}

void Movie::setLikes(int likes)
{
	this->likes = likes;
}

void Movie::setTrailer(std::string trailer)
{
	this->trailer = trailer;
}

std::string Movie::toString()
{
	std::stringstream buff;
	buff << "Title: " << this->getTitle() << '\n' << "Genre: " << this->getGenre() << '\n' << "Year: " << this->getYear() << '\n' << "Likes: " << this->getLikes() << '\n' << "Trailer: " << this->getTrailer();
	return buff.str();
}

std::string Movie::stri()
{
	std::stringstream buff;
	buff << this->getTitle() << ',' << this->getGenre() << ',' << this->getYear() << ',' << this->getLikes() << ',' << this->getTrailer();
	return buff.str();
}

void Movie::operator=(Movie m)
{
	this->title = m.title;
	this->genre = m.genre;
	this->year = m.year;
	this->likes = m.likes;
	this->trailer = m.trailer;
}

void Movie::watch()
{
	ShellExecute(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}
