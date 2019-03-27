#include "pch.h"

#include <fstream>

inline void subParagraph_15_3_2() {
	cout << "Linking Streams Together" << endl;
	cout << "------------------------" << endl;

	ifstream inFile("input.txt");
	ofstream outFile("output.txt");

	// Set up a link between inFile and outFile.
	inFile.tie(&outFile);

	// Output some text to outFile. Normally, this would
	// not flush because std::endl was not sent.
	outFile << "Hello there!";

	// outFile has NOT been flushed.
	// Read some text from inFile. This will trigger flush()
	// on outFile.
	char nextToken[32];//string nextToken;
	inFile >> nextToken;
	// outFile HAS been flushed.
}