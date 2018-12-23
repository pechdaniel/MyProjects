#include "UI.h"
#include "controller.h"
#include "repository.h"
#include <crtdbg.h>
#include "csv.h"
#include "watchFile.h"
#include <iostream>

using namespace std;

int main()
{
	{
		Repository a{ "All.txt" };
		Repository l{ "List.txt" };
		/*
		Movie m1{ "DeadPool", "Comedy", 2016, 1234, "https://www.youtube.com/watch?v=Xithigfg7dA" };
		Movie m2{ "The Greatest Showman", "Drama", 2017, 312, "https://www.youtube.com/watch?v=AXCTMGYUg9A" };
		Movie m3{ "Me Before You", "Romance", 2016, 3534, "https://www.youtube.com/watch?v=Eh993__rOxA" };
		Movie m4{ "The Wolf Of Wall Street", "Comedy", 2013, 43432, "https://www.youtube.com/watch?v=iszwuX1AK6A" };
		Movie m5{ "The Silence of the Lambs", "Thriller", 1991, 324, "https://www.youtube.com/watch?v=RuX2MQeb8UM" };
		a.add(m2);
		a.add(m3);
		a.add(m4);
		a.add(m5);
		a.add(m1);
		*/
		Controller c{ a,l };
		while (1)
		{
			int opt;
			cout << "Input the way that you want to store the data:" << endl;
			cout << "\t1. CSV file." << endl;
			cout << "\t2. HTML file." << endl;
			cout << "\t0. Exit" << endl << "option: ";
			cin >> opt;
			if (opt == 0)
			{
				break;
				// I'll sing the night into the morning
				// I'll sing my fear into Your praise
				// I'll sing my soul into Your presence
				// Whenever I say Your Name
				// Let the devil know not today
			}
			cout << endl << endl;
			UI ui{ c ,opt };
			ui.start();
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}