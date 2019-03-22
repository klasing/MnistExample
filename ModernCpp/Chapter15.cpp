#include "pch.h"

//#include Paragraph_15_1.cpp
//#include Paragraph_15_2.cpp
//#include Paragraph_15_3.cpp
//#include Paragraph_15_4.cpp
//#include Paragraph_15_5.cpp

inline void chapter15() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 15, Demystifying C++ I/O" << endl;
		cout << "================================" << endl;
		cout << " 1) Using Streams" << endl;
		cout << " 2) String Streams" << endl;
		cout << " 3) File Streams" << endl;
		cout << " 4) Bidirectional I/O" << endl;
		cout << " 5) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//paragraph_15_1();
			break;
		case 2:
			//paragraph_15_2();
			break;
		case 3:
			//paragraph_15_3();
			break;
		case 4:
			//paragraph_15_4();
			break;
		case 5:
			//paragraph_15_5();
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
