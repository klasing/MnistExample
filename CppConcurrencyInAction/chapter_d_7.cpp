#include <iostream>

#include "paragraph_d_7_1.cpp"
#include "paragraph_d_7_2.cpp"

using namespace std;
inline void chapter_d_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.7 <thread> header" << endl;
		cout << "===================" << endl;
		cout << " 1) D.7.1 std::thread class" << endl;
		cout << " 2) D.7.2 Namespace this_thread" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_7_1();
			break;
		case 2:
			paragraph_d_7_2();
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
