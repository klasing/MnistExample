#include "pch.h"

#include <algorithm>
#include <string>
#include "myIsDigit.hpp"

inline bool isNumber_(const string& str) {
	auto end = str.end();
	auto it = find_if(str.begin(), end, not1(myIsDigit()));
	return (it == end);
}

inline void subParagraph_13_3_6() {
	cout << "Writing Your Own Function Objects" << endl;
	cout << "---------------------------------" << endl;

	string str("12345");
	cout << "-> " << str << ((isNumber_(str)) ? " is a number" : " is not a number") << endl;
}