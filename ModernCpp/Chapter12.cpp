#include "pch.h"

#include "Paragraph_12_1.cpp"
#include "Paragraph_12_2.cpp"
#include "Paragraph_12_3.cpp"
#include "Paragraph_12_4.cpp"
#include "Paragraph_12_5.cpp"
#include "Paragraph_12_6.cpp"
#include "Paragraph_12_7.cpp"

inline void chapter12() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 12, Understanding Containers and Iterators" << endl;
		cout << "==================================================" << endl;
		cout << " 1) Containers Overview" << endl;
		cout << " 2) Sequential Containers" << endl;
		cout << " 3) Container Adapters" << endl;
		cout << " 4) Associative Containers" << endl;
		cout << " 5) Unordered Associative Containers/Hash Tables" << endl;
		cout << " 6) Other Containers" << endl;
		cout << " 7) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_12_1();
			break;
		case 2:
			paragraph_12_2();
			break;
		case 3:
			paragraph_12_3();
			break;
		case 4:
			paragraph_12_4();
			break;
		case 5:
			paragraph_12_5();
			break;
		case 6:
			paragraph_12_6();
			break;
		case 7:
			paragraph_12_7();
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
