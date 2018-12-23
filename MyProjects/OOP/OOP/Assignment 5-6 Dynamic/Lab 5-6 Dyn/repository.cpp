#include "repository.h"
#include <assert.h>
#include <string>

using namespace std;

bool Repository::addMovie(const Movie & m)
{
	Movie* mo = this->movie.getAll();
	for (int i = 0;i < this->movie.getLenght();i++)
		if (mo[i].getTitle() == m.getTitle())
		{
			return false;
		}
	this->movie =m+ this->movie;
	return true;
}

bool Repository::delMovie(const string & title)
{
	Movie* mo = this->movie.getAll();
	for (int i = 0;i < this->movie.getLenght();i++)
		if (mo[i].getTitle() == title)
		{
			this->movie.del(i);
			return true;
		}
	return false;
}

bool Repository::updateMovie(const string & oldTitle, const string & title, const string & genre, const int year, const int likes, const string & trailer)
{
	Movie m = findByTitle(oldTitle);
	if (m.getTitle() == "")
		return false;
	delMovie(oldTitle);
	Movie mov{ title,genre,year,likes,trailer };
	addMovie(mov);
	return true;
}

Movie Repository::findByGenre(const string & genre)
{
	Movie* m = this->movie.getAll();
	if (m == NULL)
		return Movie{};

	for (int i = 0;i < this->movie.getLenght();i++)
	{
		Movie mo = m[i];
		if (mo.getGenre() == genre)
			return mo;
	}
	return Movie{};
}

Movie Repository::findByTitle(const string & title)
{
	Movie* mov = this->movie.getAll();
	if (mov == NULL)
		return Movie{};

	for (int i = 0; i < this->movie.getLenght(); i++) {
		Movie m = mov[i];
		if (m.getTitle() == title)
			return m;
	}
	return Movie{};
}

void Repository::nextM()
{
	if (this->current == this->movie.getLenght())
		this->current = 0;
	if (this->movie.getLenght() == 0)
		return;
	Movie m = this->getCurrentM();
	m.video();
	this->current++;
}

int Repository::findP(const std::string & title)
{
	for (int i = 0;i < this->movie.getLenght();i++)
		if (this->movie.get(i).getTitle() == title)
			return i;
	return -1;
}

void Repository::incLikesMovie(int pos)
{
	this->movie.incLikes(pos);
}
