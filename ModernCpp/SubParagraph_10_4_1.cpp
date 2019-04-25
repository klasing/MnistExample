#include "pch.h"

#include <string>
#include <fstream>
#include <memory>

// prototype
inline void funcOne_10_4_1() throw(exception);
inline void funcTwo_10_4_1() throw(exception);

inline void subParagraph_10_4_1() {
	cout << "Use Smart Pointers" << endl;
	cout << "------------------" << endl;

	try {
		funcOne_10_4_1();
	}
	catch (const exception & e) {
		cerr << "-> " << "Exception caught!" << endl;
	}
}

inline void funcOne_10_4_1() throw(exception) {
	string str1;
	unique_ptr<string> str2(new string("hello"));
	funcTwo_10_4_1();
}

inline void funcTwo_10_4_1() throw(exception) {
	ifstream istr;
	istr.open("filename");
	throw exception();
	istr.close();
}
