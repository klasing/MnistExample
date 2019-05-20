#include <iostream>

#include "paragraph_3_3_1.cpp"
#include "paragraph_3_3_2.cpp"
#include "paragraph_3_3_3.cpp"

using namespace std;
inline void chapter_3_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "3.3 Alternative fecilities for protecting shared data" << endl;
		cout << "=====================================================" << endl;
		cout << " 1) Protecting shared data during initialization" << endl;
		cout << " 2) Protecting rarely updated data structures" << endl;
		cout << " 3) Recursive locking" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_3_3_1();
			break;
		case 2:
			paragraph_3_3_2();
			break;
		case 3:
			paragraph_3_3_3();
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
