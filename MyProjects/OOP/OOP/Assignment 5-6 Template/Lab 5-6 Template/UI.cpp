#include "UI.h"
#include <string>

using namespace std;

void UI::start()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Please enter the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				UI::printRepo();
				int commandRepo{ 0 };
				do
				{
					cout << "Input your command: ";
					cin >> commandRepo;
					cin.ignore();
				} while (commandRepo < 0 || commandRepo > 4);
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
					break;

				case 2:
					this->delMovieFromRepo();
					break;

				case 3:
					this->updateMovieInRepo();
					break;

				case 4:
					this->printAllMovies();

				}
			}
		}

		if (command == 2)
		{
			while (true)
			{
				UI::printList();
				int commandWatchList{ 0 };
				do
				{
					cout << "Input your command: ";
					cin >> commandWatchList;
					cin.ignore();
				} while (commandWatchList < 0 || commandWatchList > 4);
				cout << endl;
				if (commandWatchList == 0)
					break;
				{
					if (commandWatchList == 1)
					{
						this->addMovieToList();
					}
					if (commandWatchList == 2)
					{
						cout << "Type the genre that you want to filter (empty if not specified): ";
						string k;
						cin >> k;
						Repository re = this->controller.getGenreRepo(k);
						printAllMoviesR(re.getMovies());
						string maybe;
						re.setCurrentM();
						re.nextM();
						int stp = 0;
						while (true)
						{
							for (int i = 0;i < re.getMovies().getLenght();i++)
							{
								cout << "Do you want to watch the next trailer (type 'yes' or 'no')? ";
								cin >> maybe;
								if (maybe == "yes")
									re.nextM();
								else
								{
									stp = 1;
									break;
								}

							}
							if (stp == 1)
								break;
						}
					}
					if (commandWatchList == 3)
					{
						string ttl;
						cout << "Type the name of the movie that you want to delete: ";
						cin >> ttl;
						int okk1 = this->controller.getRepo().findP(ttl);
						this->controller.delL(ttl);
						if (okk1 != -1)
						{
							cout << "Would you like to rate this movie ('yes' or 'no')?";
							string mby;
							cin >> mby;
							if (mby == "yes")
								this->controller.incLike(okk1);
						}
						else
							cout << "The movie was not found!" << endl;
					}
					if (commandWatchList == 4)
					{
						this->printAllMoviesList();
					}
				}
			}
		}
	}
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - You the admin or nah, if not why are you here?" << endl;
	cout << "2 - User menu, blah, boooring." << endl;
	cout << "0 - You wouldn't dare." << endl;
}

void UI::printRepo()
{
	cout << endl << "Possible things to happen on this beautiful day: " << endl;
	cout << "\t 1 - Add movie, come on, I know you want to." << endl;
	cout << "\t 2 - Remove movie, man, why would you do that?" << endl;
	cout << "\t 3 - Update movie, why didn't you like the first one??" << endl;
	cout << "\t 4 - Display all, can't you choose just one?" << endl;
	cout << "\t 0 - That's a no no!" << endl;
}

void UI::printList()
{
	cout << endl << "Possible activities that you would like to do on this day: " << endl;
	cout << "\t 1 - Add movie, what, where, when?" << endl;
	cout << "\t 2 - Sort by genre, well, if you really want to..." << endl;
	cout << "\t 3 - Delete a movie, muhahahha" << endl;
	cout << "\t 4 - Display all movies, why though?" << endl;
	cout << "\t 0 - Don't make me call you something bad" << endl;
}

void UI::addMovieToRepo()
{
	cout << "Enter the title:";
	string title;
	getline(cin, title);
	cout << "Enter the genre:";
	string genre;
	getline(cin, genre);
	int year = 0;
	cout << "Enter the year:";
	cin >> year;
	int likes = 0;
	cout << "Enter the likes:";
	cin >> likes;
	cin.ignore();
	cout << "Trailer:";
	string link;
	getline(cin, link);

	bool ok = this->controller.addMovieToRepo(title, genre, year, likes, link);
	if (ok)
		cout << "The movie was succesfully added!\n";
	else
		cout << "Error! The movie is already in the list!\n";
	return;
}

void UI::delMovieFromRepo()
{
	cout << "Enter the title of the movie that you want removed: ";
	string title;
	getline(cin, title);
	bool ok = this->controller.delMovieFromRepo(title);
	if (ok)
		cout << "The movie was successfully removed!\n";
	else
		cout << "Error! No movie was found with the given title!";
	return;
}

void UI::updateMovieInRepo()
{
	cout << "Enter the name of the movie that you want updated: ";
	string title;
	getline(cin, title);
	cout << "Enter a new name for the movie: ";
	string newTitle;
	getline(cin, newTitle);
	cout << "Enter the genre for the movie: ";
	string newGenre;
	getline(cin, newGenre);
	int newYear = 0;
	cout << "Enter the year for the movie: ";
	cin >> newYear;
	cin.ignore();
	int newLikes = 0;
	cout << "Enter the likes for the movie: ";
	cin >> newLikes;
	cin.ignore();
	cout << "Enter the link for the movie: ";
	string newLink;
	getline(cin, newLink);
	bool ok = this->controller.updateMovieToRepo(title, newTitle, newGenre, newYear, newLikes, newLink);
	if (ok)
		cout << "The movie was successfully updated!\n";
	else
		cout << "Error! No movie was found with the given title!";
	return;
}

void UI::printAllMovies()
{
	Vector<Movie> v = this->controller.getRepo().getMovies();
	Movie* mov = v.getAll();
	if (mov == NULL)
		return;
	if (v.getLenght() == 0)
	{
		cout << "There are no movies in the repository!" << endl;
		return;
	}
	for (int i = 0; i < v.getLenght(); i++) {
		Movie m = mov[i];
		cout << "Title: " << m.getTitle() << endl;
		cout << "Genre: " << m.getGenre() << endl;
		cout << "Year: " << m.getYear() << endl;
		cout << "Likes: " << m.getLikes() << endl;
		cout << "Link: " << m.getTrailer() << endl;
		cout << endl;
	}
}

void UI::printAllMoviesList()
{
	Vector<Movie> v = this->controller.getList().getM();
	Movie* mov = v.getAll();
	if (mov == NULL)
		return;
	if (v.getLenght() == 0)
	{
		cout << "There are no movies in the repository!" << endl;
		return;
	}
	for (int i = 0; i < v.getLenght(); i++) {
		Movie m = mov[i];
		cout << "Title: " << m.getTitle() << endl;
		cout << "Genre: " << m.getGenre() << endl;
		cout << "Year: " << m.getYear() << endl;
		cout << "Likes: " << m.getLikes() << endl;
		cout << "Link: " << m.getTrailer() << endl;
		cout << endl;
	}
}

void UI::printAllMoviesR(Vector<Movie> v)
{
	Movie* mov = v.getAll();
	if (mov == NULL)
		return;
	if (v.getLenght() == 0)
	{
		cout << "There are no movies in the repository!" << endl;
		return;
	}
	for (int i = 0; i < v.getLenght(); i++) {
		Movie m = mov[i];
		cout << "Title: " << m.getTitle() << endl;
		cout << "Genre: " << m.getGenre() << endl;
		cout << "Year: " << m.getYear() << endl;
		cout << "Likes: " << m.getLikes() << endl;
		cout << "Link: " << m.getTrailer() << endl;
		cout << endl;
	}
}

void UI::addMovieToList()
{
	cout << "Please enter the title: ";
	string title;
	getline(cin, title);

	Movie m = this->controller.getRepo().findByTitle(title);
	if (m.getTitle() == "")
	{
		cout << "There are no movies of that title in the repository!" << endl;
		return;
	}
	this->controller.addMovieToList(m);
}
