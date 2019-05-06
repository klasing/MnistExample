#include <iostream>

#include "chapter_4_1.cpp"
#include "chapter_4_2.cpp"
#include "chapter_4_3.cpp"
#include "chapter_4_4.cpp"
#include "chapter_4_5.cpp"
#include "chapter_4_6.cpp"
#include "chapter_4_7.cpp"
#include "chapter_4_8.cpp"
#include "chapter_4_9.cpp"
#include "chapter_4_10.cpp"
#include "chapter_4_11.cpp"
#include "chapter_4_12.cpp"

using namespace std;
inline void part4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Behavioral Patterns" << endl;
		cout << "===================" << endl;
		cout << " 1) Chain of Responsibility" << endl;
		cout << " 2) Command" << endl;
		cout << " 3) Interpreter" << endl;
		cout << " 4) Iterator" << endl;
		cout << " 5) Mediator" << endl;
		cout << " 6) Memento" << endl;
		cout << " 7) Observer" << endl;
		cout << " 8) State" << endl;
		cout << " 9) Strategy" << endl;
		cout << "10) Template Method" << endl;
		cout << "11) Visitor" << endl;
		cout << "12) Model-View-Controller (MVC)" << endl;
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
		case 6:
			chapter_4_6();
			break;
		case 7:
			chapter_4_7();
			break;
		case 8:
			chapter_4_8();
			break;
		case 9:
			chapter_4_9();
			break;
		case 10:
			chapter_4_10();
			break;
		case 11:
			chapter_4_11();
			break;
		case 12:
			chapter_4_12();
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