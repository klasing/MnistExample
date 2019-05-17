#include <iostream>

#include "paragraph_d_6_1.cpp"
#include "paragraph_d_6_2.cpp"
#include "paragraph_d_6_3.cpp"
#include "paragraph_d_6_4.cpp"
#include "paragraph_d_6_5.cpp"
#include "paragraph_d_6_6.cpp"
#include "paragraph_d_6_7.cpp"
#include "paragraph_d_6_8.cpp"
#include "paragraph_d_6_9.cpp"
#include "paragraph_d_6_10.cpp"
#include "paragraph_d_6_11.cpp"

using namespace std;
inline void chapter_d_6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.6 <ratio> header" << endl;
		cout << "==================" << endl;
		cout << " 1) D.6.1 std::ratio class template" << endl;
		cout << " 2) D.6.2 std::ratio_add template alias" << endl;
		cout << " 3) D.6.3 std::ratio_subtract template alias" << endl;
		cout << " 4) D.6.4 std::ratio_multiply template alias" << endl;
		cout << " 5) D.6.5 std::ratio_devide template alias" << endl;
		cout << " 6) D.6.6 std::ratio_equal class template" << endl;
		cout << " 7) D.6.7 std::ratio_not_equal class template" << endl;
		cout << " 8) D.6.8 std::ratio_less class template" << endl;
		cout << " 9) D.6.9 std::ratio_greater class template" << endl;
		cout << "10) D.6.10 std::ratio_less_equal class template" << endl;
		cout << "11) D.6.11 std::ratio_greater_equal class template" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_6_1();
			break;
		case 2:
			paragraph_d_6_2();
			break;
		case 3:
			paragraph_d_6_3();
			break;
		case 4:
			paragraph_d_6_4();
			break;
		case 5:
			paragraph_d_6_5();
			break;
		case 6:
			paragraph_d_6_6();
			break;
		case 7:
			paragraph_d_6_7();
			break;
		case 8:
			paragraph_d_6_8();
			break;
		case 9:
			paragraph_d_6_9();
			break;
		case 10:
			paragraph_d_6_10();
			break;
		case 11:
			paragraph_d_6_11();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
}
