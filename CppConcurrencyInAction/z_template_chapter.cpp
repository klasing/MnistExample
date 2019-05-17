#include <iostream>

//#include "paragraph_x_y_n.cpp"

using namespace std;
inline void chapter_x_n() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "..." << endl;
		cout << "===" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//paragraph_x_y_n();
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
