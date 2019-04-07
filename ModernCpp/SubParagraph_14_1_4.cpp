#include "pch.h"

#include <string>

inline void subParagraph_14_1_4() {
	cout << "Raw String Literals" << endl;
	cout << "-------------------" << endl;

	string str = R"~(-> Line 1
-> line "2" \t (and)
-> end)~";
	cout << str << endl;
	str = R"-(-> The characters )" are embedded in this string)-";
	cout << str << endl;
}