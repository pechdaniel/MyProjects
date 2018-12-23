#include "list.h"

List::List()
{
	this->current = 0;
}

void List::add(const Movie & m)
{
	this->movie.add(m);
}

Movie List::getCurrent()
{
	if (this->current == this->movie.getLenght())
		this->current = 0;
	Movie* m = this->movie.getAll();
	if (m != NULL)
		return m[this->current];
	return Movie{};
}

void List::watch()
{
	if (this->movie.getLenght() == 0)
		return;
	this->current = 0;
	Movie m = this->getCurrent();
	m.video();
}

void List::next()
{
	if (this->movie.getLenght() == 0)
		return;
	this->current++;
	Movie m = this->getCurrent();
	m.video();
}

bool List::empty()
{
	return this->movie.getLenght() == 0;
}

int List::del(const std::string & title)
{
	for(int i=0;i<this->movie.getLenght();i++)
		if (this->movie.get(i).getTitle() == title)
		{
			this->movie.del(i);
			return 1;
		}
	return -1;
}
