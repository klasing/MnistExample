#include <iostream>

#include "paragraph_d_5_1.cpp"
#include "paragraph_d_5_2.cpp"
#include "paragraph_d_5_3.cpp"
#include "paragraph_d_5_4.cpp"
#include "paragraph_d_5_5.cpp"
#include "paragraph_d_5_6.cpp"
#include "paragraph_d_5_7.cpp"
#include "paragraph_d_5_8.cpp"
#include "paragraph_d_5_9.cpp"
#include "paragraph_d_5_10.cpp"

using namespace std;
inline void chapter_d_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.5 <mutex> header" << endl;
		cout << "==================" << endl;
		cout << " 1) D.5.1 std::mutex class" << endl;
		cout << " 2) D.5.2 std::recursive mutex class" << endl;
		cout << " 3) D.5.3 std::timed_mutex class" << endl;
		cout << " 4) D.5.4 std::recursive_timed_mutex class" << endl;
		cout << " 5) D.5.5 std::lock_guard class template" << endl;
		cout << " 6) D.5.6 std::unique_lock class template" << endl;
		cout << " 7) D.5.7 std::lock function template" << endl;
		cout << " 8) D.5.8 std::try_lock function template" << endl;
		cout << " 9) D.5.9 std::once_flag class" << endl;
		cout << "10) D.5.10 std::call_once function template" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_5_1();
			break;
		case 2:
			paragraph_d_5_2();
			break;
		case 3:
			paragraph_d_5_3();
			break;
		case 4:
			paragraph_d_5_4();
			break;
		case 5:
			paragraph_d_5_5();
			break;
		case 6:
			paragraph_d_5_6();
			break;
		case 7:
			paragraph_d_5_7();
			break;
		case 8:
			paragraph_d_5_8();
			break;
		case 9:
			paragraph_d_5_9();
			break;
		case 10:
			paragraph_d_5_10();
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
