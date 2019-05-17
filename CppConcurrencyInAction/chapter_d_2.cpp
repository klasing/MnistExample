#include <iostream>

#include "paragraph_d_2_1.cpp"
#include "paragraph_d_2_2.cpp"

using namespace std;
inline void chapter_d_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.2 <condition_variable> header" << endl;
		cout << "===============================" << endl;
		cout << " 1) D.2.1 std::condition_variable class" << endl;
		cout << " 2) D.2.2 std::condition_variable_any class" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_2_1();
			break;
		case 2:
			paragraph_d_2_2();
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
