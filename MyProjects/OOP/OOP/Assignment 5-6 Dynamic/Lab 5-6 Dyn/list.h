#pragma once
#include "dynamic.h"

class List
{
private:
	Vector movie;
	int current;
public:
	/*
	Constructor for the watch list
	*/
	List();
	/*
	Adds a movie to the watch list
	*/
	void add(const Movie& m);
	/*
	Returns the current movie
	out: current
	*/
	Movie getCurrent();
	/*
	Plays the trailer for the current movie
	*/
	void watch();
	/*
	Jumps to the next movie from the watch list
	*/
	void next();
	/*
	Checks if the watch list is empty
	out: return true if the watch list is empty, false otherwise
	*/
	bool empty();

	int del(const std::string& title);

	Vector getM() { return movie; };
};