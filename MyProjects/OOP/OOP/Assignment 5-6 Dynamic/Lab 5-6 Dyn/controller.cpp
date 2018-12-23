#include "controller.h"

using namespace std;

bool Controller::addMovieToRepo(const string & title, const string & genre, const int year, const int likes, const string & trailer)
{
	Movie m{ title,genre,year,likes,trailer };
	return this->repo.addMovie(m);
}

bool Controller::delMovieFromRepo(const string & title)
{
	return this->repo.delMovie(title);
}

bool Controller::updateMovieToRepo(string oldTitle, string title, string genre, int year, int likes, string trailer)
{
	return this->repo.updateMovie(oldTitle, title, genre, year, likes, trailer);
}

void Controller::addMovieToList(const Movie & m)
{
	this->list.add(m);
}

void Controller::addMovieByGenre(const string & genre)
{
	Vector v = this->repo.getMovies();
	Movie* mo = v.getAll();
	for (int i = 0;i < v.getLenght();i++)
	{
		Movie m = mo[i];
		if (m.getGenre() == genre)
			this->list.add(m);
	}
}

Repository Controller::getGenreRepo(const std::string genre)
{
	Repository r{};
	if (genre == "empty")
		return this->repo;
	for (int i = 0;i < this->repo.getMovies().getLenght();i++)
		if (this->repo.getMovies().get(i).getGenre()==genre)
			r.addMovie(this->repo.getMovies().get(i));
	return r;
}

void Controller::startList()
{
	this->list.watch();
}

void Controller::nextMovieList()
{
	this->list.next();
}

void Controller::delL(const std::string & title)
{
	this->list.del(title);
}

void Controller::incLike(int pos)
{
	this->repo.incLikesMovie(pos);
}
