#include "pch.h"

#include <utility>

inline void subParagraph_12_4_1() {
	cout << "The pair Utility Class" << endl;
	cout << "----------------------" << endl;

	// Two-argument constructor and default constructor
	std::pair<string, int> myPair("hello", 5);
	std::pair<string, int> myOtherPair;
	// Can assign directly to first and second
	myOtherPair.first = "hello";
	myOtherPair.second = 6;
	// Copy constructor
	pair<string, int> myThirdPair(myOtherPair);
	// operator<
	if (myPair < myOtherPair)
		cout << "-> myPair is less than myOtherPair" << endl;
	else
		cout << "-> myPair is greater than or equal to myOtherPair" << endl;
	// operator==
	if (myOtherPair == myThirdPair)
		cout << "-> myOtherPair is equal to myThirdPair" << endl;
	else
		cout << "-> myOtherPair is not equal to myThirdPair" << endl;
	// make_pair
	pair<int, int> aPair = make_pair(5, 10);
	auto aSecondPair = make_pair(5, 10);
}