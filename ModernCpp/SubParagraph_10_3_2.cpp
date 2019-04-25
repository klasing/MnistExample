#include "pch.h"

#include <vector>

// prototype
inline void readIntegerFile(const string& fileName, vector<int>& dest)
throw(invalid_argument, runtime_error);

inline void subParagraph_10_3_2() {
	cout << "Catching Exceptions in a Class Hierarchy" << endl;
	cout << "----------------------------------------" << endl;

	vector<int> myInts;
	const string fileName = "AIntegerFile.txt";
	try {
		readIntegerFile(fileName, myInts);
	}
	catch (const exception& e) {
		cerr << "-> " << e.what() << endl;
	}
}