#include "pch.h"

#include <regex>
#include <string>

inline void subParagraph_14_3_3() {
	cout << "regex_match()" << endl;
	cout << "-------------" << endl;

	cout << "a) regex_match() Example" << endl;
	//regex r("^\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])$");
	//while (true) {
	//	cout << "-> Enter a date (year/month/day) (q=quit): ";
	//	string str = "";
	//	if (!getline(cin, str) || str == "q")
	//		break;
	//	if (regex_match(str, r))
	//		cout << "-> Valid date." << endl;
	//	else
	//		cout << "-> Invalid date!" << endl;
	//}
	// ^\\d{4}: any combination of four digits at the beginning of the string
	// (?:0?[1-9]|1[0-2])
	// no capture group: (?:...)
	// 0?[1-9]: optional 0, followed by any number from 1 to 9
	// 1[0-2]: 1 followed by any number from 0 to 2
	// (?:0?[1-9]|[1-2][0-9]|3[0-1])
	// [1-2][0-9]: any number between 10 and 29
	// 3[0-1]: will match 30 or 31 and nothing else

	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	regex r("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
	while (true) {
		cout << "-> Enter a date (year/month/day) (q=quit): ";
		string str = "";
		if (!getline(cin, str) || str == "q")
			break;
		smatch m;
		if (regex_match(str, m, r)) {
			int year = atoi(m[1].str().c_str());
			int month = atoi(m[2].str().c_str());
			int day = atoi(m[3].str().c_str());
			cout << "-> Valid date: Year=" << year
				<< ", month=" << month
				<< ", day=" << day << endl;
		} 
		else
			cout << "-> Invalid date!" << endl;
	}
}