#include <iostream>

#include "paragraph_6_3_1.cpp"
#include "paragraph_6_3_2.cpp"

using namespace std;
inline void chapter_6_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "6.3 Designing more complex lock-based data structures" << endl;
		cout << "=====================================================" << endl;
		cout << " 1) Writing a thread-safe lookup table using locks" << endl;
		cout << " 2) Writing a thread-safe list using locks" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_6_3_1();
			break;
		case 2:
			paragraph_6_3_2();
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