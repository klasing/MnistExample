#include <iostream>

#include "paragraph_3_2_1.cpp"
#include "paragraph_3_2_2.cpp"
#include "paragraph_3_2_3.cpp"
#include "paragraph_3_2_4.cpp"
#include "paragraph_3_2_5.cpp"
#include "paragraph_3_2_6.cpp"
#include "paragraph_3_2_7.cpp"
#include "paragraph_3_2_8.cpp"

using namespace std;
inline void chapter_3_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "3.2 Protecting shared data with mutexes" << endl;
		cout << "=======================================" << endl;
		cout << " 1) Using mutexes in C++" << endl;
		cout << " 2) Structuring code for protecting shared data" << endl;
		cout << " 3) Spotting race conditions inherent in interfaces" << endl;
		cout << " 4) Deadlock: the problem and a solution" << endl;
		cout << " 5) Further guidelines for avoiding deadlock" << endl;
		cout << " 6) Flexible locking with std::unique_lock" << endl;
		cout << " 7) Transferring mutex ownership between scopes" << endl;
		cout << " 8) Locking at the appropriate granularity" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_3_2_1();
			break;
		case 2:
			paragraph_3_2_2();
			break;
		case 3:
			paragraph_3_2_3();
			break;
		case 4:
			paragraph_3_2_4();
			break;
		case 5:
			paragraph_3_2_5();
			break;
		case 6:
			paragraph_3_2_6();
			break;
		case 7:
			paragraph_3_2_7();
			break;
		case 8:
			paragraph_3_2_8();
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
