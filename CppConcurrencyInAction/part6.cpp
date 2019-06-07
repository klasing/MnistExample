#include <iostream>

#include "chapter_6_1.cpp"
#include "chapter_6_2.cpp"
#include "chapter_6_3.cpp"
#include "chapter_6_4.cpp"

using namespace std;
inline void part6() {
	bool bProceed = true;
	int iChar;

	while (bProceed) {
		cout << "6) Designing lock-based concurrent data structures" << endl;
		cout << "==================================================" << endl;
		cout << " 1) What does it mean to design for concurrency?" << endl;
		cout << " 2) Lock-based concurrent data structures" << endl;
		cout << " 3) Designing more complex lock-based data structures" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_6_1();
			break;
		case 2:
			chapter_6_2();
			break;
		case 3:
			chapter_6_3();
			break;
		case 4:
			chapter_6_4();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof swtich
	}
}