#include "repoException.h"

RepoException::RepoException() :exception{}, message{ "" }
{
}

RepoException::RepoException(const std::string & msg) : message{ msg }
{
}

const char * RepoException::what()
{
	return this->message.c_str();
}

const char * FoundException::what()
{
	return "There cannot be 2 movies with the same title!\n";
}

const char * NoMovieFoundException::what()
{
	return "There is no movie with that title!\n";
}

FileExceptionF::FileExceptionF(const std::string & msg) :message{ msg }
{
}

const char * FileExceptionF::what()
{
	return this->message.c_str();
}
