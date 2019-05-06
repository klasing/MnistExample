#include <iostream>

#include "chapter_2_1.cpp"
#include "chapter_2_2.cpp"
#include "chapter_2_3.cpp"
#include "chapter_2_4.cpp"
#include "chapter_2_5.cpp"

using namespace std;
inline void part2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Creational Patterns" << endl;
		cout << "===================" << endl;
		cout << " 1) Builder" << endl;
		cout << " 2) Factory" << endl;
		cout << " 3) Abstract Factory" << endl;
		cout << " 4) Prototype" << endl;
		cout << " 5) Singleton" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_2_1();
			break;
		case 2:
			chapter_2_2();
			break;
		case 3:
			chapter_2_3();
			break;
		case 4:
			chapter_2_4();
			break;
		case 5:
			chapter_2_5();
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