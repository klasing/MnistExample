#include "pch.h"

//#include "SubParagraph_25_2_1.cpp"
//#include "SubParagraph_25_2_2.cpp"
//#include "SubParagraph_25_2_3.cpp"
//#include "SubParagraph_25_2_4.cpp"
//#include "SubParagraph_25_2_5.cpp"
//#include "SubParagraph_25_2_6.cpp"
//#include "SubParagraph_25_2_7.cpp"

inline void paragraph_25_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Cross-Language Development" << endl;
		cout << "==========================" << endl;
		cout << " 1) Mixing C and C++" << endl;
		cout << " 2) Shifting Paradigms" << endl;
		cout << " 3) Linking with C Code" << endl;
		cout << " 4) Mixing C# with C++" << endl;
		cout << " 5) Mixing Java and C++ with JNI" << endl;
		cout << " 6) Mixing C++ with Perl and Shell Scripts" << endl;
		cout << " 7) Mixing C++ with Assembly Code" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_25_2_1();
			break;
		case 2:
			//subParagraph_25_2_2();
			break;
		case 3:
			//subParagraph_25_2_3();
			break;
		case 4:
			//subParagraph_25_2_4();
			break;
		case 5:
			//subParagraph_25_2_5();
			break;
		case 6:
			//subParagraph_25_2_6();
			break;
		case 7:
			//subParagraph_25_2_7();
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
