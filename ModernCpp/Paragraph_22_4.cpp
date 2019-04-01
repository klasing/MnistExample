#include "pch.h"

#include "SubParagraph_22_4_1.cpp"
#include "SubParagraph_22_4_2.cpp"
#include "SubParagraph_22_4_3.cpp"
#include "SubParagraph_22_4_4.cpp"

inline void paragraph_22_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Mutual Exclusion" << endl;
		cout << "================" << endl;
		cout << " 1) Mutex Classes" << endl;
		cout << " 2) Locks" << endl;
		cout << " 3) std::call_once" << endl;
		cout << " 4) Mutex Usage Examples" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_22_4_1();
			break;
		case 2:
			subParagraph_22_4_2();
			break;
		case 3:
			subParagraph_22_4_3();
			break;
		case 4:
			subParagraph_22_4_4();
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
