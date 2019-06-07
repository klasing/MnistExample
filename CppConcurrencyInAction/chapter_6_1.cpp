#include <iostream>

#include "paragraph_6_1_1.cpp"

using namespace std;
inline void chapter_6_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "6.1 What does it mean to design for concurrency?" << endl;
		cout << "================================================" << endl;
		cout << " 1) Guidelines for designing data structures for concurrency" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_6_1_1();
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