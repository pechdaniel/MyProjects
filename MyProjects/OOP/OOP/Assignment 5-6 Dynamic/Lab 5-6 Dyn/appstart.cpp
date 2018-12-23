#include "domain.h"
#include "UI.h"
#include "Windows.h"
#include <crtdbg.h>
#include "tests.h"

using namespace std;

int main()
{
	{
		Test::Tests();
		system("color 0D");
		Repository repo{};
		Movie m1{ "DeadPool", "Comedy", 2016, 1234, "https://www.youtube.com/watch?v=Xithigfg7dA" };
		Movie m2{ "The Greatest Showman", "Drama", 2017, 312, "https://www.youtube.com/watch?v=AXCTMGYUg9A" };
		Movie m3{ "Me Before You", "Romance", 2016, 3534, "https://www.youtube.com/watch?v=Eh993__rOxA" };
		Movie m4{ "The Wolf Of Wall Street", "Comedy", 2013, 43432, "https://www.youtube.com/watch?v=iszwuX1AK6A" };
		Movie m5{ "The Silence of the Lambs", "Thriller", 1991, 324, "https://www.youtube.com/watch?v=RuX2MQeb8UM" };

		repo.addMovie(m1);
		repo.addMovie(m2);
		repo.addMovie(m3);
		repo.addMovie(m4);
		repo.addMovie(m5);

		Controller controller{ repo };
		UI ui{ controller };
		ui.start();
	}
	_CrtDumpMemoryLeaks();

	return 0;

}
