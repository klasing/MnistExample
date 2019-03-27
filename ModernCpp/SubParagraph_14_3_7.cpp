#include "pch.h"

#include <string>
#include <regex>

inline void example_14_3_7_a() {
	const string str("<body><h1>Header</h1><p>Some text</p></body>");
	regex r("<h1>(.*)</h1><p>(.*)</p>");
	const string format("H1=$1 and P=$2");

	string result = regex_replace(str, r, format);

	cout << "-> Original string: " << str << endl;
	cout << "-> New string:      " << result << endl;
}

inline void example_14_3_7_b() {
	const string str("<body><h1>Header</h1><p>Some text</p></body>");
	regex r("<h1>(.*)</h1><p>(.*)</p>");
	const string format("H1=$1 and P=$2");

	string result = regex_replace(str, r, format,
		regex_constants::format_no_copy);

	cout << "-> Original string: " << str << endl;
	cout << "-> New string:      " << result << endl;
}

inline void example_14_3_7_c() {
	regex reg("([\\w]+)");
	const string format("$1\n");

	// ignore all leftover characters on the line of input
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (true) {
		cout << "-> Enter a string to split over multiple lines (q=quit): ";
		string str;
		//if (!getline(cin, str) || str == "q")
		cin >> str;
		if (str == "q")
			break;

		cout << "-> " << regex_replace(str, reg, format,
			regex_constants::format_no_copy);
	}
}

inline void subParagraph_14_3_7() {
	cout << "regex_replace()" << endl;
	cout << "---------------" << endl;

	example_14_3_7_a();
	example_14_3_7_b();
	example_14_3_7_c();
}