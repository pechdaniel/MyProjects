#include "tests.h"
#include <assert.h>

void TestAddDyn()
{
	Vector v{};
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	v.add(m);
	assert(v.get(0).getTitle()== "Film");
	assert(v.get(0).getGenre() == "awesome");
	assert(v.get(0).getYear() == 2018);
	assert(v.get(0).getLikes() == 20000);
}

void TestAddRepo()
{
	Repository r{};
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m);
	assert(r.getMovies().get(0).getYear() == 2018);
	assert(r.getMovies().get(0).getLikes() == 20000);
}

void TestDelRepo()
{
	Repository r{};
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m);
	assert(r.getMovies().get(0).getYear() == 2018);
	assert(r.getMovies().get(0).getLikes() == 20000);
	r.addMovie(m);
	r.getMovies().del(0);
	assert(r.getMovies().getLenght() == 1);
}

void TestUpdateRepo()
{
	Repository r{};
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m1);
	assert(r.getMovies().get(0).getYear() == 2018);
	assert(r.getMovies().get(0).getLikes() == 20000);
	r.updateMovie("Film", "Film", "awesome", 2018, 20000, "more");
}

void TestAddController()
{
	Repository r{};
	Controller c{ r };
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies().get(0).getYear() == 2018);
	assert(c.getRepo().getMovies().get(0).getLikes() == 20000);
}

void TestDelController()
{
	Repository r{};
	Controller c{ r };
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies().get(0).getYear() == 2018);
	assert(c.getRepo().getMovies().get(0).getLikes() == 20000);
	c.delMovieFromRepo("Film");
}

void TestUpdateController()
{
	Repository r{};
	Controller c{ r };
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	Movie m2{ "Film","awesome",2018,20000,"more" };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies().get(0).getYear() == 2018);
	assert(c.getRepo().getMovies().get(0).getLikes() == 20000);
	c.updateMovieToRepo("Film", "Film", "awesome", 2018, 20000, "more");
}

void Test::Tests()
{
	Test::TestController();
	Test::TestRepo();
}

void Test::TestRepo()
{
	TestAddDyn();
	TestAddRepo();
	TestDelRepo();
	TestUpdateRepo();
}

void Test::TestController()
{
	TestAddController();
	TestDelController();
	TestUpdateController();
}