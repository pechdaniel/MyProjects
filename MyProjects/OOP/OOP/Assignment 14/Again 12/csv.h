#pragma once
#include "repository.h"
#include "watchFile.h"

class CSV :public MovieFile {
public:
	CSV() :MovieFile{} { this->filename = this->getFile(); }
	void writeToFile() override;
	void display() override;
};

//class CSV1 {
//private:
//	Repository repo;
//	std::string filename;
//public:
//	CSV() :repo{}, filename{ "" } {}
//	CSV(Repository repo, std::string filename) :repo{ repo }, filename{ filename } { this->readFromFile(); }
//	~CSV() {}
//	void writeToFile();
//	void readFromFile();
//	Repository getRepo() { return repo; }
//};