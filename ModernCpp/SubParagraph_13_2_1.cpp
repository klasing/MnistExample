#include "pch.h"

#include <string>

inline void subParagraph_13_2_1() {
	cout << "Syntax" << endl;
	cout << "------" << endl;

	[] { cout << "-> Hello from Lambda" << endl; }();
	//string result = [](const string& str) -> string { return "Hello from "
	//	+ str; }("second Lambda");
	// or even shorter
	string result = [](const string& str){ return "Hello from "
		+ str; }("second Lambda");
	cout << "-> Result: " << result << endl;
	auto fn = [](const string& str) { return "-> Hello from " + str; };
	cout << fn("call 1") << endl;
	cout << fn("call 2") << endl;
}