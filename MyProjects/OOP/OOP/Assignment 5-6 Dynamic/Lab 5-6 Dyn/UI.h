#pragma once
#include "controller.h"

class UI
{
private:
	Controller controller;
public:
	UI(const Controller& c) :controller(c) {}

	void start();
private:
	static void printMenu();
	static void printRepo();
	static void printList();

	void addMovieToRepo();
	void delMovieFromRepo();
	void updateMovieInRepo();
	void printAllMovies();
	void printAllMoviesR(Vector v);
	void printAllMoviesList();

	void addMovieToList();
};