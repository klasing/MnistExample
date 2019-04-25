#include "pch.h"

#include <string>
#include <fstream>

// prototype
inline void funcOne_10_4_2() throw(exception);
inline void funcTwo_10_4_2() throw(exception);

inline void subParagraph_10_4_2() {
	cout << "Catch, Cleanup, and Rethrow" << endl;
	cout << "---------------------------" << endl;

	try {
		funcOne_10_4_2();
	}
	catch (const exception & e) {
		cerr << "-> " << "Exception caught!" << endl;
	}
}

inline void funcOne_10_4_2() throw(exception) {
	string str1;
	string* str2 = new string();
	try {
		funcTwo_10_4_2();
	}
	catch (...) {
		delete str2;
		// Rethrow the exception.
		throw;
	}
	delete str2;
}

inline void funcTwo_10_4_2() throw(exception) {
	ifstream istr;
	istr.open("filename");
	throw exception();
	istr.close();
}
