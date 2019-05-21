#include <iostream>

#include "paragraph_4_2_1.cpp"
#include "paragraph_4_2_2.cpp"
#include "paragraph_4_2_3.cpp"
#include "paragraph_4_2_4.cpp"
#include "paragraph_4_2_5.cpp"

using namespace std;
inline void chapter_4_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "4.2 Waiting for one-off events with futures" << endl;
		cout << "===========================================" << endl;
		cout << " 1) Returning values from background tasks" << endl;
		cout << " 2) Associate a task with a future" << endl;
		cout << " 3) Making (std::)promises" << endl;
		cout << " 4) Saving an exception for the future" << endl;
		cout << " 5) Waiting from multiple threads" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_4_2_1();
			break;
		case 2:
			paragraph_4_2_2();
			break;
		case 3:
			paragraph_4_2_3();
			break;
		case 4:
			paragraph_4_2_4();
			break;
		case 5:
			paragraph_4_2_5();
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
