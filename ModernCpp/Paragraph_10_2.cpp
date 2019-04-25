#include "pch.h"

#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include <stdexcept>

#include "SubParagraph_10_2_1.cpp"
#include "SubParagraph_10_2_2.cpp"
#include "SubParagraph_10_2_3.cpp"
#include "SubParagraph_10_2_4.cpp"
#include "SubParagraph_10_2_5.cpp"

inline void readIntegerFile(const string& fileName, vector<int>& dest) 
	throw(invalid_argument, runtime_error) {
	string error;
	ifstream istr;
	int temp;
	istr.open(fileName.c_str());
	if (istr.fail())
		// We failed to open the file: throw an exception.
		//throw exception();
		//throw 5;
		//throw "Unable to open file";
		// We failed to open the file: throw an exception.
		error = "Unable to open file " + fileName;
		throw invalid_argument(error);
	// Read the integers one by one and add them to the vector.
	while (istr >> temp)
		dest.push_back(temp);
	if (istr.eof())
		// We reached the end-of-file.
		istr.close();
	else {
		// Some other error. Throw an exception.
		istr.close();
		//throw exception();
		error = "Unable to read file " + fileName;
		throw runtime_error(error);
	}
}

inline void paragraph_10_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	vector<int> myInts;
	//const string fileName =  "IntegerFile.txt";
	// triggers an exception, because the file name is non existing
	const string fileName = "AIntegerFile.txt";
	try {
		readIntegerFile(fileName, myInts);
	}
	//catch (const exception& e) {
	////catch (int e) {
	////catch (const char* e) {
	//	//cerr << "-> Unable to open file " << fileName << endl;
	//	//cerr << e << endl;
	//	cerr << "-> Unable either to open or to read " << fileName << endl;
	//}
	catch (const invalid_argument& e) {
		cerr << "-> Unable to open file " << fileName << endl;
	}
	catch (const runtime_error& e) {
		cerr << "-> Error reading file " << fileName << endl;
	}
	catch (...) {
		// Handle all other exceptions
	}

	cout << "-> ";
	for (size_t i = 0; i < myInts.size(); i++)
		cout << myInts[i] << " ";
	cout << endl;

	while (bProceed) {
		cout << "Exception Mechanics" << endl;
		cout << "===================" << endl;
		cout << " 1) Throwing and Catching Exceptions" << endl;
		cout << " 2) Exception Types" << endl;
		cout << " 3) Throwing and Catching Multiple Exceptions" << endl;
		cout << " 4) Uncaught Exceptions" << endl;
		cout << " 5) Throw List" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_10_2_1();
			break;
		case 2:
			subParagraph_10_2_2();
			break;
		case 3:
			subParagraph_10_2_3();
			break;
		case 4:
			subParagraph_10_2_4();
			break;
		case 5:
			subParagraph_10_2_5();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
}
