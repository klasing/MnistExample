#include <iostream>

#include "chapter_3_1.cpp"
#include "chapter_3_2.cpp"
#include "chapter_3_3.cpp"
#include "chapter_3_4.cpp"

using namespace std;
inline void part3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "3 Sharing data between threads" << endl;
		cout << "==============================" << endl;
		cout << " 1) Problems with sharing data between threads" << endl;
		cout << " 2) Protecting shared data with mutexes" << endl;
		cout << " 3) Alternative facilities for protecting shared data" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_3_1();
			break;
		case 2:
			chapter_3_2();
			break;
		case 3:
			chapter_3_3();
			break;
		case 4:
			chapter_3_4();
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
