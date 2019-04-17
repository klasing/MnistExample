#include "pch.h"

#include "SubParagraph_12_2_1.cpp"
#include "SubParagraph_12_2_2.cpp"
#include "SubParagraph_12_2_3.cpp"
#include "SubParagraph_12_2_4.cpp"
#include "SubParagraph_12_2_5.cpp"
#include "SubParagraph_12_2_6.cpp"

inline void paragraph_12_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Sequential Containers" << endl;
		cout << "=====================" << endl;
		cout << " 1) vector" << endl;
		cout << " 2) The vector<bool> Specialization" << endl;
		cout << " 3) dequeue" << endl;
		cout << " 4) list" << endl;
		cout << " 5) array" << endl;
		cout << " 6) forward_list" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_12_2_1();
			break;
		case 2:
			subParagraph_12_2_2();
			break;
		case 3:
			subParagraph_12_2_3();
			break;
		case 4:
			subParagraph_12_2_4();
			break;
		case 5:
			subParagraph_12_2_5();
			break;
		case 6:
			subParagraph_12_2_6();
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
