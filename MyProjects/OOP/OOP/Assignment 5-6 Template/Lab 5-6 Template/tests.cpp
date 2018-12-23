#include "tests.h"
#include <assert.h>

void TestAddDyn()
{
	Vector<Movie> v;
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	v.add(m);
	assert(v[0].getTitle()== "Film");
	assert(v[0].getGenre() == "awesome");
	assert(v[0].getYear() == 2018);
	assert(v[0].getLikes() == 20000);
}

void TestAddRepo()
{
	Repository r{};
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m);
	assert(r.getMovies()[0].getYear()== 2018);
	assert(r.getMovies()[0].getLikes() == 20000);
}

void TestDelRepo()
{
	Repository r{};
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m);
	assert(r.getMovies()[0].getYear() == 2018);
	assert(r.getMovies()[0].getLikes() == 20000);
	r.addMovie(m);
	r.getMovies().del(0);
	assert(r.getMovies().getLenght() == 1);
}

void TestUpdateRepo()
{
	Repository r{};
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m1);
	assert(r.getMovies()[0].getYear() == 2018);
	assert(r.getMovies()[0].getLikes() == 20000);
	r.updateMovie("Film", "Film", "awesome", 2018, 20000, "more");
}

void TestFindByTitleRepo()
{
	Repository r{};
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m1);
	assert(r.getMovies()[0].getYear() == 2018);
	assert(r.getMovies()[0].getLikes() == 20000);
	assert(r.findByTitle("Film").getTitle() == "Film");
	assert(r.findByTitle("Film").getYear() == 2018);
	assert(r.findByTitle("Film").getLikes() == 20000);
}

void TestFindByGenreRepo()
{
	Repository r{};
	r.nextM();
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	r.addMovie(m1);
	assert(r.getMovies()[0].getYear() == 2018);
	assert(r.getMovies()[0].getLikes() == 20000);
	assert(r.findByGenre("awesome").getTitle() == "Film");
	assert(r.findByGenre("awesome").getYear() == 2018);
	assert(r.findByGenre("awesome").getLikes() == 20000);
	Movie ji = Movie{};
	r.incLikesMovie(0);
	int fd = r.findP("kdaem");
	r.setCurrentM();
}

void TestAddController()
{
	Repository r{};
	Controller c{ r };
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies()[0].getYear() == 2018);
	assert(c.getRepo().getMovies()[0].getLikes() == 20000);
}

void TestDelController()
{
	Repository r{};
	Controller c{ r };
	Movie m{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies()[0].getYear() == 2018);
	assert(c.getRepo().getMovies()[0].getLikes() == 20000);
	c.delMovieFromRepo("Film");
	Vector<Movie> ve{};
	ve.resize();
	m=r.getMovies()[0];
}

void TestUpdateController()
{
	Repository r{};
	Controller c{ r };
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	Movie m2{ "Film","awesome",2018,20000,"more" };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	assert(c.getRepo().getMovies()[0].getYear() == 2018);
	assert(c.getRepo().getMovies()[0].getLikes() == 20000);
	c.updateMovieToRepo("Film", "Film", "awesome", 2018, 20000, "more");
}

void TestListController()
{
	Repository r{};
	Controller c{ r };
	Movie m1{ "Film","awesome",2018,20000,"t.h.i.s.i.s.a.w.e.s.o.m.e." };
	Movie m2{ "Film","awesome",2018,20000,"more" };
	c.addMovieToRepo("Film", "awesome", 2018, 20000, "t.h.i.s.i.s.a.w.e.s.o.m.e.");
	c.getList();
	c.getRepo();
	c.nextMovieList();
	c.startList();
	assert(c.getRepo().getMovies()[0].getYear() == 2018);
	assert(c.getRepo().getMovies()[0].getLikes() == 20000);
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
	TestFindByGenreRepo();
	TestFindByTitleRepo();
}

void Test::TestController()
{
	TestAddController();
	TestDelController();
	TestUpdateController();
	TestListController();
}