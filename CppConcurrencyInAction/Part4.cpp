#include <iostream>

#include "chapter_4_1.cpp"
#include "chapter_4_2.cpp"
#include "chapter_4_3.cpp"
#include "chapter_4_4.cpp"
#include "chapter_4_5.cpp"

using namespace std;
inline void part4() {
	bool bProceed = true;
	int iChar;

	while (bProceed) {
		cout << "4 Synchronizing concurrent operations" << endl;
		cout << "=====================================" << endl;
		cout << " 1) Waiting for an event or other condition" << endl;
		cout << " 2) Waiting for one-off events with futures" << endl;
		cout << " 3) Waiting with a time limit" << endl;
		cout << " 4) Using synchronization of operations to simplify code" << endl;
		cout << " 5) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_4_1();
			break;
		case 2:
			chapter_4_2();
			break;
		case 3:
			chapter_4_3();
			break;
		case 4:
			chapter_4_4();
			break;
		case 5:
			chapter_4_5();
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