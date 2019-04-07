#include "pch.h"

#include <regex>
#include <string>

inline void subParagraph_14_3_6() {
	cout << "regex_token_iterator" << endl;
	cout << "--------------------" << endl;

	cout << "a) regex_token_iterator Examples" << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	regex reg("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
	while (true) {
		cout << "-> Enter a date (year/month/day) (q=quit): ";
		string str = "";
		if (!getline(cin, str) || str == "q")
			break;
		// specify capture group
		vector<int> vec = { 2, 3 };
		const sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), reg, vec);
			iter != end; ++iter)
			cout << "-> \"" << *iter << "\"" << endl;
	}

	regex reg_("\\s*[,;]+\\s*");
	while (true) {
		cout << "-> Enter a string to split on ',' and ';' (q=quit):";
		string str = "";
		if (!getline(cin, str) || str == "q")
			break;
		const sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), reg_, -1);
			iter != end; ++iter)
			cout << "-> \"" << *iter << "\"" << endl;
	}
}
//#include "pch.h"
//
//#include <string>
//#include <regex>
//
//inline void example_14_3_6_a() {
//	regex reg("[\\w]+");
//
//	// ignore all leftover characters on the line of input
//	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	while (true) {
//		cout << "-> Enter a string to split (q=quit): ";
//		string str;
//		//if (!getline(cin, str) || str == "q")
//		cin >> str;
//		if (str == "q")
//			break;
//
//		const sregex_token_iterator end;
//		for (sregex_token_iterator iter(str.begin(), str.end(), reg);
//			iter != end; ++iter)
//			cout << "-> " << *iter << endl;
//	}
//}
//
//inline void example_14_3_6_b() {
//	regex reg("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
//
//	// ignore all leftover characters on the line of input
//	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	while (true){
//		cout << "-> Enter a date (year/month/day) (q=quit): ";
//		string str;
//		//if (!getline(cin, str) || str == "q")
//		cin >> str;
//		if (str == "q")
//			break;
//
//		vector<int> vec = { 2, 3 };
//		const sregex_token_iterator end;
//		for (sregex_token_iterator iter(str.begin(), str.end(), reg, vec);
//			iter != end; ++iter)
//			cout << "-> " << *iter << endl;
//	}
//}
//
//inline void example_14_3_6_c() {
//	regex reg("\\s*[,;]+\\s*");
//
//	// ignore all leftover characters on the line of input
//	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	while (true) {
//		cout << "-> Enter a string to split on ',' and ';' (q=quit): ";
//		string str;
//		//if (!getline(cin, str) || str == "q")
//		cin >> str;
//		if (str == "q")
//			break;
//
//		const sregex_token_iterator end;
//		for (sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
//			iter != end; ++iter)
//			cout << "-> " << *iter << endl;
//	}
//}
//
//inline void subParagraph_14_3_6() {
//	cout << "regex_token_iterator" << endl;
//	cout << "--------------------" << endl;
//
//	example_14_3_6_a();
//	example_14_3_6_b();
//	example_14_3_6_c();
//}