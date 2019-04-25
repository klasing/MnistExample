#include "pch.h"

#include <vector>

// prototype
inline void readIntegerFile(const string& fileName, vector<int>& dest)
throw(invalid_argument, runtime_error);

inline void subParagraph_10_3_1() {
	cout << "The Standard Exception Hierarchy" << endl;
	cout << "--------------------------------" << endl;

	vector<int> myInts;
	const string fileName = "AIntegerFile.txt";
	try {
		readIntegerFile(fileName, myInts);
	}
	catch (const invalid_argument& e) {
		cerr << "-> " << e.what() << endl;
	}
	catch (const runtime_error& e) {
		cerr << "-> " << e.what() << endl;
	}

}