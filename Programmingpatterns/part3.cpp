#include <iostream>

#include "chapter_3_1.cpp"
#include "chapter_3_2.cpp"
#include "chapter_3_3.cpp"
#include "chapter_3_4.cpp"
#include "chapter_3_5.cpp"
#include "chapter_3_6.cpp"
#include "chapter_3_7.cpp"
#include "chapter_3_8.cpp"
#include "chapter_3_9.cpp"

using namespace std;
inline void part3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Structural Patterns" << endl;
		cout << "===================" << endl;
		cout << " 1) Adapter" << endl;
		cout << " 2) Bridge" << endl;
		cout << " 3) Composite" << endl;
		cout << " 4) Decorator" << endl;
		cout << " 5) Facade" << endl;
		cout << " 6) Flyweight" << endl;
		cout << " 7) Proxy" << endl;
		cout << " 8) Curiously Recurring Template" << endl;
		cout << " 9) Interface-based Programming (IBP)" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_3_1();
			break;
		case 2:
			chapter_3_2();
			break;
		case 3:
			chapter_3_3();
			break;
		case 4:
			chapter_3_4();
			break;
		case 5:
			chapter_3_5();
			break;
		case 6:
			chapter_3_6();
			break;
		case 7:
			chapter_3_7();
			break;
		case 8:
			chapter_3_8();
			break;
		case 9:
			chapter_3_9();
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