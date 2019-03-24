#include "pch.h"

#include <regex>

inline void example1() {
	const string str("<body><h1>Header</h1><p>Some text</p></body>");
	regex r("<h1>(.*)</h1><p>(.*)</p>");
	const string format("H1=$1 and P=$2");

	string result = regex_replace(str, r, format);

	cout << "-> Original string: " << str << endl;
	cout << "-> New string:      " << result << endl;
}

inline void example2() {
	const string str("<body><h1>Header</h1><p>Some text</p></body>");
	regex r("<h1>(.*)</h1><p>(.*)</p>");
	const string format("H1=$1 and P=$2");

	string result = regex_replace(str, r, format,
		regex_constants::format_no_copy);

	cout << "-> Original string: " << str << endl;
	cout << "-> New string:      " << result << endl;
}

inline void example3() {
	regex reg("([\\w]+)");
	const string format("$1\n");

	while (true) {
		cout << "-> Enter a string to split over multiple lines (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q")
			break;

		cout << "-> " << regex_replace(str, reg, format,
			regex_constants::format_no_copy) << endl;
	}
}

inline void subParagraph_14_3_7() {
	cout << "regex_replace()" << endl;
	cout << "---------------" << endl;

	example1();
	example2();
	example3();
}