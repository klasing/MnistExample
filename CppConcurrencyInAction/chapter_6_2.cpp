#include <iostream>

#include "paragraph_6_2_1.cpp"
#include "paragraph_6_2_2.cpp"
#include "paragraph_6_2_3.cpp"

using namespace std;
inline void chapter_6_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "6.2 Lock-based concurrent data structures" << endl;
		cout << "=========================================" << endl;
		cout << " 1) A thread-safe stack using locks" << endl;
		cout << " 2) A thread-safe queue using locks and condition variables" << endl;
		cout << " 3) A thread-safe queue using fine-grained locks and condition variables" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_6_2_1();
			break;
		case 2:
			paragraph_6_2_2();
			break;
		case 3:
			paragraph_6_2_3();
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