#pragma once
#include "repository.h"

class RepoException : public std::exception
{
protected:
	std::string message;

public:
	RepoException();

	RepoException(const std::string& msg);

	virtual ~RepoException() {}

	virtual const char* what();

};

class FoundException : public RepoException
{
public:
	const char* what();
};

class NoMovieFoundException : public RepoException
{
public:
	const char* what();
};

class FileExceptionF : public std::exception
{
protected:
	std::string message;

public:

	FileExceptionF(const std::string& msg);

	virtual const char* what();
};