#include "pch.h"

//#include "SubParagraph_29_2_1.cpp"
//#include "SubParagraph_29_2_2.cpp"
//#include "SubParagraph_29_2_3.cpp"
//#include "SubParagraph_29_2_4.cpp"

inline void paragraph_29_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "The Singleton Pattern" << endl;
		cout << "=====================" << endl;
		cout << " 1) Example: A Logging Mechanism" << endl;
		cout << " 2) Implemantation of a Singleton" << endl;
		cout << " 3) Using a Singleton" << endl;
		cout << " 4) Singletons and Multithreading" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_29_2_1();
			break;
		case 2:
			//subParagraph_29_2_2();
			break;
		case 3:
			//subParagraph_29_2_3();
			break;
		case 4:
			//subParagraph_29_2_4();
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
