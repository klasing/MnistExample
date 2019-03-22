#include "pch.h"

//#include "SubParagraph_11_2_1.cpp"
//#include "SubParagraph_11_2_2.cpp"
//#include "SubParagraph_11_2_3.cpp"
//#include "SubParagraph_11_2_4.cpp"
//#include "SubParagraph_11_2_5.cpp"
//#include "SubParagraph_11_2_6.cpp"
//#include "SubParagraph_11_2_7.cpp"
//#include "SubParagraph_11_2_8.cpp"
//#include "SubParagraph_11_2_9.cpp"
//#include "SubParagraph_11_2_10.cpp"
//#include "SubParagraph_11_2_11.cpp"
//#include "SubParagraph_11_2_12.cpp"
//#include "SubParagraph_11_2_13.cpp"
//#include "SubParagraph_11_2_14.cpp"

inline void paragraph_11_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overview of the C++ Standard Library" << endl;
		cout << "====================================" << endl;
		cout << " 1) Strings" << endl;
		cout << " 2) I/O Streams" << endl;
		cout << " 3) Localization" << endl;
		cout << " 4) Smart Pointers" << endl;
		cout << " 5) Exceptions" << endl;
		cout << " 6) Mathematical Utilities" << endl;
		cout << " 7) Time Utilities" << endl;
		cout << " 8) Random Numbers" << endl;
		cout << " 9) Compile-Time Rational Arithmetic" << endl;
		cout << " 10) Tuples" << endl;
		cout << " 11) Regular Expressions" << endl;
		cout << " 12) The Standard Template Library" << endl;
		cout << " 13) STL Algorithms" << endl;
		cout << " 14) What's Missing from the STL" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_11_2_1();
			break;
		case 2:
			//subParagraph_11_2_2();
			break;
		case 3:
			//subParagraph_11_2_3();
			break;
		case 4:
			//subParagraph_11_2_4();
			break;
		case 5:
			//subParagraph_11_2_5();
			break;
		case 6:
			//subParagraph_11_2_6();
			break;
		case 7:
			//subParagraph_11_2_7();
			break;
		case 8:
			//subParagraph_11_2_8();
			break;
		case 9:
			//subParagraph_11_2_9();
			break;
		case 10:
			//subParagraph_11_2_10();
			break;
		case 11:
			//subParagraph_11_2_11();
			break;
		case 12:
			//subParagraph_11_2_12();
			break;
		case 13:
			//subParagraph_11_2_13();
			break;
		case 14:
			//subParagraph_11_2_14();
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
