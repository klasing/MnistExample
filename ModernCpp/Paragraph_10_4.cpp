#include "pch.h"

#include <string>
#include <fstream>

#include "SubParagraph_10_4_1.cpp"
#include "SubParagraph_10_4_2.cpp"

// prototype
inline void funcOne_10_4() throw(exception);
inline void funcTwo_10_4() throw(exception);

inline void paragraph_10_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	try {
		funcOne_10_4();
	}
	catch (const exception & e) {
		cerr << "-> " << "Exception caught!" << endl;
	}

	while (bProceed) {
		cout << "Stack Unwinding and Cleanup" << endl;
		cout << "===========================" << endl;
		cout << " 1) Use Smart Pointers" << endl;
		cout << " 2) Catch, Cleanup, and Rethrow" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_10_4_1();
			break;
		case 2:
			subParagraph_10_4_2();
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

inline void funcOne_10_4() throw(exception) {
	string str1;
	string* str2 = new string();
	funcTwo_10_4();
	// here a memory leak appears, because an exception is thrown 
	// in funcTwo_10_4()
	delete str2;
}

inline void funcTwo_10_4() throw(exception) {
	ifstream istr;
	istr.open("filename");
	throw exception();
	istr.close();
}

