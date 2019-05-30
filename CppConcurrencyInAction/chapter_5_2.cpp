#include <iostream>

#include "paragraph_5_2_1.cpp"
#include "paragraph_5_2_2.cpp"
#include "paragraph_5_2_3.cpp"
#include "paragraph_5_2_4.cpp"
#include "paragraph_5_2_5.cpp"
#include "paragraph_5_2_6.cpp"
#include "paragraph_5_2_7.cpp"

using namespace std;
inline void chapter_5_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "5.2 Atomic operations and types in C++" << endl;
		cout << "======================================" << endl;
		cout << " 1) The standard atomic types" << endl;
		cout << " 2) Operations on std::atomic_flag" << endl;
		cout << " 3) Operations on std::atomic<bool>" << endl;
		cout << " 4) Operations on std::atomic<T*>: pointer arithmetic" << endl;
		cout << " 5) Operations on standard atomic integral types" << endl;
		cout << " 6) The std::atomic<> primary class template" << endl;
		cout << " 7) Free functions for atomic operations" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_5_2_1();
			break;
		case 2:
			paragraph_5_2_2();
			break;
		case 3:
			paragraph_5_2_3();
			break;
		case 4:
			paragraph_5_2_4();
			break;
		case 5:
			paragraph_5_2_5();
			break;
		case 6:
			paragraph_5_2_6();
			break;
		case 7:
			paragraph_5_2_7();
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
