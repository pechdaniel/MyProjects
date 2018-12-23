#include "tests.h"
#include <iostream>
#include <cassert>

using namespace std;

void Tests::testSearch() {
	SortedBag<int> bag{ ">" };

	bag.insert(5);
	bag.insert(10);
	bag.insert(3);
	bag.insert(4);
	bag.insert(1);
	bag.insert(11);
	assert(bag.search(5) == true);
	assert(bag.search(4) == true);
	assert(bag.search(2) == false);
	assert(bag.search(1) == true);
	assert(bag.search(12) == false);
}

void Tests::testRemove() {

	SortedBag<int> bag{ ">" };

	bag.insert(5);
	bag.insert(10);
	bag.insert(3);
	bag.insert(4);
	bag.insert(1);
	bag.insert(11);
	assert(bag.remove(5) == true);
	assert(bag.remove(123) == false);
	assert(bag.remove(12) == false);
	assert(bag.remove(1) == true);
	assert(bag.remove(11) == true);
}

void Tests::testSize() {

	SortedBag<int> bag{ ">" };

	bag.insert(5);
	bag.insert(10);
	bag.insert(3);
	bag.insert(4);
	bag.insert(1);
	bag.insert(11);
	assert(bag.size() == 6);
	assert(bag.remove(5) == true);
	assert(bag.size() == 5);
	assert(bag.remove(10) == true);
	assert(bag.remove(3) == true);
	assert(bag.remove(4) == true);
	assert(bag.size() == 2);
}

void Tests::testIterator()
{
	SortedBag<int> bag{ ">" };

	bag.insert(5);
	bag.insert(10);
	bag.insert(3);
	bag.insert(4);
	bag.insert(1);
	bag.insert(11);
	Iterator<int> it = bag.iterator();
	it.next();
	assert(it.getValue()==3);
	int k = 0;
	while (k < bag.size() - 1)
	{
		k++;
		it.next();
	}
	if (it.isValid() == NULL)
		k++;
}

void Tests::testAll() {
	testSearch();
	testRemove();
	testSize();
	testIterator();
}