#include <iostream>

#include "chapter_5_1.cpp"
#include "chapter_5_2.cpp"
#include "chapter_5_3.cpp"
#include "chapter_5_4.cpp"

using namespace std;
inline void part5() {
	bool bProceed = true;
	int iChar;

	while (bProceed) {
		cout << "5 The C++ memory model and operations on atomic types" << endl;
		cout << "=====================================================" << endl;
		cout << " 1) Memory model basics" << endl;
		cout << " 2) Atomic operations and types in C++" << endl;
		cout << " 3) Sychronizing operations and enforcing ordering" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_5_1();
			break;
		case 2:
			chapter_5_2();
			break;
		case 3:
			chapter_5_3();
			break;
		case 4:
			chapter_5_4();
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