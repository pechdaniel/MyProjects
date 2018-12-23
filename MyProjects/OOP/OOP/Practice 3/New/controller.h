#pragma once
#include "repository.h"
#include "html.h"

class Controller {
private:
	Repository repo;
	Repository list;
	HTML html;
public:
	Controller(Repository repo, Repository list) :repo{ repo }, list{ list }, html{ list } {}
	~Controller() {}
	Repository getAll() { return repo; }
	Repository getList() { return list; }
	int findByTitle(std::string title);

	bool add(Movie m);
	bool del(std::string title);
	bool addList(Movie m);
	bool delList(std::string title);
	bool update(std::string oTitle, std::string nTitle, std::string genre, int year, int likes, std::string trailer);
	void incLikes(int pos) { repo.incLikes(pos); }
	void operator=(Controller c);
	void saveFile() { html.setRepo(this->getList()); }

	std::vector<Movie> filterByGenre(std::string genre);
	void displayCSV() { list.displayCSV(); }
	void displayHTML();
};