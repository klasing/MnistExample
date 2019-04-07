#include "pch.h"

#include <regex>
#include <string>

inline void subParagraph_14_3_4() {
	cout << "regex_search()" << endl;
	cout << "--------------" << endl;

	cout << "a) regex_search() Example" << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	regex r("//\\s*(.+)");
	while (true) {
		cout << "-> Enter a string (q=quit): ";
		string str = "";
		if (!getline(cin, str) || str == "q")
			break;
		smatch m;
		if (regex_match(str, m, r)) {
			int year = atoi(m[1].str().c_str());
			int month = atoi(m[2].str().c_str());
			int day = atoi(m[3].str().c_str());
			cout << "-> Found comment '" << m[1] << "'" << endl;
		}
		else
			cout << "-> No comment found!" << endl;
	}
}