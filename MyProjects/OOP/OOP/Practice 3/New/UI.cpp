#include "UI.h"
#include <iostream>
#include "repoException.h"
#include <string>

using namespace std;

void UI::printMenuAdmin()
{
	cout << "1. Add a movie." << endl;
	cout << "2. Delete a movie." << endl;
	cout << "3. Update a movie." << endl;
	cout << "4. Print the movies" << endl;
	cout << "0. Exit" << endl;
}

void UI::printMenuUser()
{
	cout << "1. See the movies with a given genre." << endl;
	cout << "2. Delete a movie." << endl;
	cout << "3. Print the watch list." << endl;
	cout << "4. Display in the selected way." << endl;
	cout << "0. Exit" << endl;
}

void UI::displayFile()
{
	if (this->option == 1)
		this->contro.displayCSV();
	else
		if (this->option == 2)
			this->contro.displayHTML();
}

void UI::start()
{
	while (1)
	{
		int startup;
		cout << "1. Admin menu." << endl;
		cout << "2. User menu." << endl;
		cout << "0. Exit" << endl;
		cout << "command: ";
		cin >> startup;
		if (startup == 0)
			break;
		if(startup==1)
			while (1)
			{
				this->printMenuAdmin();
				int command;
				cout << "Enter the command: ";
				cin >> command;
				if (command == 0)
					break;
				if (command == 1)
				{
					try{
					string t, g, tr;
					int y, l;
					cout << "Title: ";
					cin >> t;
					cout << "Genre: ";
					cin >> g;
					cout << "Year: ";
					cin >> y;
					cout << "Likes: ";
					cin >> l;
					cout << "Trailer: ";
					cin >> tr;
					Movie m{ t,g,y,l,tr };
					bool k = this->contro.add(m);
					if (k == true)
						cout << "Movie successfully added!" << endl;
					else
						cout << "Movie could not be added!" << endl;
					}
					catch (FoundException e)
					{
						cout << e.what();
					}
				}
				if (command == 2)
				{
					try {
						cout << "Movie title: ";
						string t,h;
						cin.clear();
						getline(cin, h);
						getline(cin, t);
						bool k = this->contro.del(t);
						if (k == true)
							cout << "Movie was successfully deleted!" << endl;
						else
							cout << "Movie could not be deleted!" << endl;
					}
					catch (NoMovieFoundException e)
					{
						cout << e.what();
					}
				}
				if (command == 3)
				{
					string ot, nt, g, tr;
					int y, l;
					cout << "Old title: ";
					cin >> ot;
					cout << "New title: ";
					cin >> nt;
					cout << "Genre: ";
					cin >> g;
					cout << "Year: ";
					cin >> y;
					cout << "Lieks: ";
					cin >> l;
					cout << "Trailer: ";
					cin >> tr;
					bool k = this->contro.update(ot, nt, g, y, l, tr);
					if (k == true)
						cout << "Movie was successfully updated!" << endl;
					else
						cout << "Movie could not be updated!" << endl;
				}
				if (command == 4)
				{
					if (this->contro.getAll().getLenght() == 0)
						cout << "No movies in the list!" << endl;
					else
						cout << this->contro.getAll().toString();
				}
				cout << endl;
			}
		if (startup == 2)
			while (1)
			{
				this->printMenuUser();
				int command;
				cout << "Enter the command: ";
				cin >> command;
				if (command == 0)
					break;
				if (command == 1)
				{
					try {
						string genre;
						cout << "Genre ('empty' to get all): ";
						cin >> genre;
						Repository r{};
						r.setElems(this->contro.filterByGenre(genre));
						while (1)
						{
							cout << r.next();
							cout << endl << "Add the movie to the watch list? (yes or no): ";
							string s;
							cin >> s;
							if (s == "yes")
							{
								try {
									bool k = this->contro.addList(r[r.getCurrent() - 1]);
									if (k == true)
										cout << "Movie added!" << endl;
									else
										cout << "Movie could not be added!" << endl;
								}
								catch (FoundException e)
								{
									cout << e.what();
								}
							}
							cout << "next (yes or no): ";
							cin >> s;
							if (s == "no")
								break;
						}
					}
					catch (FileExceptionF e)
					{
						cout << e.what();
					}
				}
				if (command == 2)
				{
					try{
					string t,h;
					cout << "Title: ";
					cin.clear();
					getline(cin, h);
					getline(cin, t);
					bool k = this->contro.delList(t);
					if (k == true)
					{
						string s;
						cout << "Would you like to rate this movie? (yes or no): ";
						cin >> s;
						if (s == "yes")
							this->contro.incLikes(this->contro.findByTitle(t));
						cout << "Movie successfully deleted!" << endl;
					}
					else
						cout << "Movie could not be deleted!" << endl;
					}
					catch (NoMovieFoundException e)
					{
						cout << e.what();
					}
				}
				if (command == 3)
				{
					if (this->contro.getList().getLenght() == 0)
						cout << "No movies in the watch list!" << endl;
					else
						cout << this->contro.getList().toString();
				}
				if (command == 4)
				{
					this->contro.saveFile();
					this->displayFile();
				}
				cout << endl;
			}
		cout << endl;
	}
}
