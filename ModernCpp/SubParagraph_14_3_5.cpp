#include "pch.h"

#include <regex>
#include <string>

inline void subParagraph_14_3_5() {
	cout << "regex_iterator" << endl;
	cout << "--------------" << endl;

	cout << "a) regex_iterator() Example" << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	regex reg("[\\w]+");
	while (true) {
		cout << "-> Enter a string to split (q=quit): ";
		string str = "";
		if (!getline(cin, str) || str == "q")
			break;
		const sregex_iterator end;
		for (sregex_iterator it(str.begin(), str.end(), reg); it != end; ++it)
			cout << "-> \"" << (*it)[0] << "\"" << endl;
	}
}