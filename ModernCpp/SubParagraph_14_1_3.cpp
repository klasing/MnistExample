#include "pch.h"

#include <string>

inline void subParagraph_14_1_3() {
	cout << "The C++ string Class" << endl;
	cout << "--------------------" << endl;

	cout << "a) What Was Wrong with C-Style String?" << endl;
	cout << "b) Using the string Class" << endl;
	string A("abc");
	string B("def");
	string C;
	C = A + B;
	cout << "-> " << C << endl;
	string myString = "hello";
	myString += ", there";
	string myOtherString = myString;
	if (myString == myOtherString)
		myOtherString[0] = 'H';
	cout << "-> " << myString << endl;
	cout << "-> " << myOtherString << endl;
	cout << "c) Numeric conversions (C++11)" << endl;
	const string s = "1234";
	int i = stoi(s);
	cout << "-> " << i << endl;
}