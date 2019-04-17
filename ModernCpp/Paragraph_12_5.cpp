#include "pch.h"

#include "SubParagraph_12_5_1.cpp"
#include "SubParagraph_12_5_2.cpp"
#include "SubParagraph_12_5_3.cpp"
#include "SubParagraph_12_5_4.cpp"
#include "SubParagraph_12_5_5.cpp"

inline void paragraph_12_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Unordered Associative Containers/Hash Tables" << endl;
		cout << "============================================" << endl;
		cout << " 1) Hash Functions" << endl;
		cout << " 2) unordered_map" << endl;
		cout << " 3) unordered_map Example: Phone Book" << endl;
		cout << " 4) unordered_multimap" << endl;
		cout << " 5) unordered_set/unordered_multiset" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_12_5_1();
			break;
		case 2:
			subParagraph_12_5_2();
			break;
		case 3:
			subParagraph_12_5_3();
			break;
		case 4:
			subParagraph_12_5_4();
			break;
		case 5:
			subParagraph_12_5_5();
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
