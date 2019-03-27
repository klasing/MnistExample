#include "pch.h"

#include <fstream>

inline bool changeNumberForId(const string& inFileName, int inID,
	const string& inNewNumber) {

	fstream ioData(inFileName.c_str());
	if (!ioData) {
		cerr << "Error while opening file " << inFileName.c_str() << endl;
		return false;
	}

	// Loop until the end of file
	while (ioData.good()) {
		int id;
		string number;

		// Read the next ID.
		ioData >> id;

		// Check to see if the current record position is the one being changed.
		if (id == inID) {
			// Seek to the current read position
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << inNewNumber.c_str();
			break;
		}

		// Read the current number to advance the  stream.
		ioData << number.c_str();
	}

	return true;
}

inline void paragraph_15_4() {
	cout << "Bidirectional I/O" << endl;
	cout << "-----------------" << endl;

	changeNumberForId("Map_Id_Phonenumber.txt", 164, "416-555-0164");
}