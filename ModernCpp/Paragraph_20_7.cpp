#include "pch.h"

//#include "SubParagraph_20_7_1.cpp"
//#include "SubParagraph_20_7_2.cpp"
//#include "SubParagraph_20_7_3.cpp"
//#include "SubParagraph_20_7_4.cpp"
//#include "SubParagraph_20_7_5.cpp"

inline void paragraph_20_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Metaprogramming" << endl;
		cout << "===============" << endl;
		cout << " 1) Factorial at Compile Time" << endl;
		cout << " 2) Loop Unrolling" << endl;
		cout << " 3) Printing Tuples" << endl;
		cout << " 4) Type Traits" << endl;
		cout << " 5) Conclusion" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_7_1();
			break;
		case 2:
			//subParagraph_20_7_2();
			break;
		case 3:
			//subParagraph_20_7_3();
			break;
		case 4:
			//subParagraph_20_7_4();
			break;
		case 5:
			//subParagraph_20_7_5();
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
