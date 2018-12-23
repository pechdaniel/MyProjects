#pragma once
#include "repository.h"
#include "list.h"


class Controller
{
private:
	Repository repo;
	List list;
public:
	/*
	Constructor for the controller
	initializes the controller
	*/
	Controller(const Repository& r) : repo{ r } {}
	/*
	Returns the repository from the controller
	out: repo
	*/
	Repository getRepo()const { return repo; }
	/*
	Returns the list from WatchList for the user
	out: list
	*/
	List getList() const { return list; }
	/*
	Adds a movie to the controller
	in: title, genre, year, likes, trailer
	out: return true if the movie was added, false otherwise
	*/
	bool addMovieToRepo(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& trailer);
	/*
	Deletes a movie by title from the controller
	in: title
	out: return true if the movie was deleted, false otherwise
	*/
	bool delMovieFromRepo(const std::string& title);
	/*
	Updates a movie in the controller
	in: old title, new title, new genre, new year, new likes, new trailer
	out: return true if the movie was updated, false otherwiese
	*/
	bool updateMovieToRepo(std::string oldTitle, std::string title, std::string genre, int year, int likes, std::string trailer);
	/*
	Adds a movie to the watch list
	in: movie
	out: adds the movie to the watch list
	*/
	void addMovieToList(const Movie& m);
	/*
	Adds a movie by genre to the watch list
	in: genre
	out: adds the movie to the watch list
	*/
	void addMovieByGenre(const std::string& genre);
	Repository getGenreRepo(const std::string genre);
	/*
	Plays the trailers for the movies
	*/
	void startList();
	/*
	Jumps to the next movie trailer
	*/
	void nextMovieList();

	void delL(const std::string& title);

	void incLike(int pos);
};