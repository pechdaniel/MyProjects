#pragma once
#include "dynamic.h"


class Repository
{
private:
	Vector movie;
	int current;
public:
	/*
	Constructor for repository
	*/
	Repository() {}
	/*
	Adds a movie to the repository
	in: the movie
	out: return true if the movie was added, false otherwise
	*/
	bool addMovie(const Movie& m);
	/*
	Deletes a movie from the repository by its position
	in: index
	out: return true if the movie was deleted, false otherwise
	*/
	bool delMovie(const std::string& title);
	/*
	Updates a movie with new stats
	in: old title, new title, new genre, new year, new likes, new trailer
	out: return true if the movie was updated, false otherwise
	*/
	bool updateMovie(const std::string& oldTitle, const std::string& title, const std::string& genre, const int year, const int likes, const std::string& trailer);
	/*
	Returns the movies with a given genre
	in: genre
	out: returns the movies that have the given genre
	*/
	Movie findByGenre(const std::string& genre);
	/*
	Returns the movie that has a specific title
	in: title
	out: return movie with the title [title]
	*/
	Movie findByTitle(const std::string& title);
	/*
	Returns all the movies from the repository
	out: return all movies
	*/
	Vector getMovies()const { return movie; }

	Movie getCurrentM() { return movie.get(current); };

	void setCurrentM() { current = 0; };

	void nextM();

	int findP(const std::string& title);

	void incLikesMovie(int pos);
};