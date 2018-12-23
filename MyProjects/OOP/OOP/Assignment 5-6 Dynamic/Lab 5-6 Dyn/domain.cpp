#include "domain.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;
Movie::Movie() : title(""), genre(""), year(), likes(), trailer("") {}

Movie::Movie(const string & title, const string & genre, const int & year, const int & likes, const string & trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

void Movie::video()
{
	ShellExecute(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}
