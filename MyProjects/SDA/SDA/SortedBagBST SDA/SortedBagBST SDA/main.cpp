#include <iostream>
#include <string>
#include "node.h"
#include "bst.h"
#include "iterator.h"
#include "tests.h"

using namespace std;

void printMenu()
{
	cout << "> Select a command: \n";
	cout << "     1. Insert a value \n";
	cout << "     2. Search if a value exists \n";
	cout << "     3. Remove a value \n";
	cout << "     4. Print inorder traversal \n";
	cout << "     0. Exit \n";
}

bool validInput(string command)
{
	int c;
	c = stoi(command);
	if (c < 0 || c>4)
	{
		cout << "> Invalid input! \n";
		return false;
	}
	return true;
}

void start()
{
	Tests tes;
	tes.testAll();

	SortedBag<int> bag{ ">" };
	bag.insert(5);
	bag.insert(10);
	bag.insert(11);
	bag.insert(7);
	bag.insert(3);
	bag.insert(1);
	bag.insert(4);
	bag.insert(8);
	/*
				 5
			   /   \
		      /     \
		     /       \
            3         10
           / \       /  \
		  /   \     /    \
		 1     4   7      11
		            \
					 \
					  8
	*/

	while (true)
	{
		printMenu();
		string command;
		cout << "> ";
		cin >> command;
		while (!validInput(command))
		{
			cout << "> ";
			cin >> command;
		}	
		if (command == "0")
		{
			break;
		}
		else if (command == "1")
		{
			int in;
			cout << "> Type the value: ";
			cin >> in;
			bag.insert(in);
			cout << "> Element successfully added!\n";
		}
		else if (command == "2")
		{
			int in;
			cout << "> Type the value: ";
			cin >> in;
			if (bag.search(in) == true)
				cout << "> Element was found!\n";
			else
				cout << "> Element was not found!\n";
		}
		else if (command == "3")
		{
			int in;
			cout << "> Type the value to be removed: ";
			cin >> in;
			bool ms = bag.remove(in);
			if (ms == false)
				cout << "> Value not found! \n";
			else
				cout << "> Value deleted! \n";
		}
		else if (command == "4")
		{
			if (bag.size() != 0)
			{
				Iterator<int> it = bag.iterator();
				if (bag.size() == 1)
				{
					cout << "Value: " << it.getValue() << endl;
				}
				else {
					int ok1 = 0;
					while (ok1<bag.size()) {
						ok1++;
						cout << "Value: " << it.getValue() << endl;
						it.next();
					}
					cout << "There is a total of " << bag.size() << " elements. \n";
				}
			}
			else
				cout << "> No elements in the bag! \n";
		}
	}
}

int main()
{
	start();
	return 0;
}