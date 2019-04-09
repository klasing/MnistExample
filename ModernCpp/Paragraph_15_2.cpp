#include "pch.h"

#include <sstream>
#include "Muffin.hpp"

inline void example1() {
	cout << "-> Enter tokens. Control+D (Unix) or Control+Z (Windows) to end" << endl;
	ostringstream outStream;

	while (cin) {
		string nextToken;
		cout << "-> Next token: ";
		cin >> nextToken;
		if (nextToken == "done")
			break;
		outStream << nextToken << " ";
	}
	cout << "-> The end result is: " << outStream.str() << endl;
}

inline Muffin createMuffin(istringstream& inStream) {
	Muffin muffin;
	// Assume data is properly formatted:
	// Description size chips
	string description;
	int size;
	bool hasChips;

	// Read all three values. Note that chips is represented
	// by the strings "true" and "false"
	inStream >> description >> size >> boolalpha >> hasChips;
	muffin.setSize(size);
	muffin.setDescription(description);
	muffin.setHasChocolateChips(hasChips);

	return muffin;
}

inline void paragraph_15_2() {
	cout << "String Streams" << endl;
	cout << "--------------" << endl;

	example1();
	// marshalling an object
	Muffin myMuffin;
	istringstream myStream("Special_muffin 6 true");
	myMuffin = createMuffin(myStream);
	cout << "-> Muffin is: ";
	myMuffin.output();
	cout << endl;
}