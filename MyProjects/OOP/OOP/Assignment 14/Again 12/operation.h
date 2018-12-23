#pragma once
#include <vector>
#include <string>
#include "movie.h"
#include "repository.h"

class OperationElement
{
private:
	Movie movie;
	Movie movieUpdate;
	std::string operation;
public:
	OperationElement(Movie m, Movie mo, std::string o) :movie{ m }, movieUpdate{ mo }, operation{ o } {}
	~OperationElement() {}
	Movie getMovie() { return movie; }
	std::string getOperation() { return operation; }
	Movie getMovieUpdate() { return movieUpdate; }
	void setMovie(Movie m) { movie = m; }
	void setMovieUpdate(Movie m) { movieUpdate = m; }
	void setOperation(std::string o) { operation = o; }
};

class Operation
{
protected:
	std::vector<OperationElement> operation{};
	Repository repo;
public:
	Operation(Repository r) :repo{ r } { }
	~Operation() {}
	
	
	virtual void execute() = 0;
	
	
	void push(OperationElement o);
	OperationElement pop();
	OperationElement get() { return operation[operation.size() - 1]; }
	OperationElement operator[](int pos) { return operation[pos]; }
	int len() { return operation.size(); }
	Repository getRepo() { return repo; }
	void addRepo(Movie m) { repo.add(m); }
	void delRepo(int pos) { repo.del(pos); }
	void updateRepo(std::string ot, std::string nt, std::string g, int y, int l, std::string tr) { repo.update(ot, nt, g, y, l, tr); }
	void setE(std::vector<Movie> r) { repo.setElems(r); }
};