#include "controller.h"
#include "repoException.h"

int Controller::findByTitle(std::string title)
{
	for (int i = 0;i < this->repo.getLenght();i++)
		if (this->repo[i].getTitle() == title)
			return i;
	return -1;
}

bool Controller::add(Movie m)
{
	if (this->findByTitle(m.getTitle()) != -1)
	{
		throw FoundException();
		return false;
	}
	this->repo.add(m);
	return true;
}

bool Controller::del(std::string title)
{
	int pos = this->findByTitle(title);
	if (pos < 0 || pos >= this->repo.getLenght())
	{
		throw NoMovieFoundException();
		return false;
	}
	this->repo.del(pos);
	return true;
}

bool Controller::addList(Movie m)
{
	int pos = this->list.findByTitle(m.getTitle());
	if (pos != -1)
	{
		throw FoundException();
		return false;
	}
	this->list.add(m);
	return true;
}

bool Controller::delList(std::string title)
{
	int k = this->list.findByTitle(title);
	if (k == -1)
	{
		throw NoMovieFoundException();
		return false;
	}
	this->list.del(k);
	return true;
}

bool Controller::update(std::string oTitle, std::string nTitle, std::string genre, int year, int likes, std::string trailer)
{
	int pos = this->findByTitle(oTitle);
	if (pos < 0 || pos >= this->repo.getLenght())
		return false;
	this->repo.update(oTitle, nTitle, genre, year, likes, trailer);
	return true;
}

void Controller::operator=(Controller c)
{
	for (int i = this->repo.getLenght() - 1;i >= 0;i--)
		this->repo.del(i);
	for (int i = this->list.getLenght() - 1;i >= 0;i--)
		this->list.del(i);
	for (int i = 0;i < c.repo.getLenght();i++)
		this->repo.add(c.getAll()[i]);
	for (int i = 0;i < c.list.getLenght();i++)
		this->list.add(c.getList()[i]);
}

std::vector<Movie> Controller::filterByGenre(std::string genre)
{
	int ok = 0;
	std::vector<Movie> e{};
	if (genre == "empty")
		ok = 1;
	for (int i = 0;i < this->getAll().getLenght();i++)
	{
		if (ok == 0)
		{
			Movie m = this->getAll()[i];
			if (m.getGenre() == genre)
				e.push_back(m);
		}
		else
			e.push_back(this->getAll()[i]);
	}
	return e;
}

void Controller::displayHTML()
{
	this->html.displayHTML();
}
