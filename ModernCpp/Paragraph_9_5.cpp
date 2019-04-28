#include "pch.h"

#include "SubParagraph_9_5_1.cpp"
#include "SubParagraph_9_5_2.cpp"
#include "SubParagraph_9_5_3.cpp"
#include "SubParagraph_9_5_4.cpp"
#include "SubParagraph_9_5_5.cpp"
#include "SubParagraph_9_5_6.cpp"
#include "SubParagraph_9_5_7.cpp"
#include "SubParagraph_9_5_8.cpp"
#include "SubParagraph_9_5_8_ad1.cpp"

inline void paragraph_9_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C++11" << endl;
		cout << "=====" << endl;
		cout << " 1) Uniform Initialization" << endl;
		cout << " 2) Alternative Function Syntax" << endl;
		cout << " 3) Null Pointer Constant" << endl;
		cout << " 4) Angle Brackets" << endl;
		cout << " 5) Initializer Lists" << endl;
		cout << " 6) Explicit Conversion Operators" << endl;
		cout << " 7) Attributes" << endl;
		cout << " 8) User Defined Literals" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_9_5_1();
			break;
		case 2:
			subParagraph_9_5_2();
			break;
		case 3:
			subParagraph_9_5_3();
			break;
		case 4:
			subParagraph_9_5_4();
			break;
		case 5:
			subParagraph_9_5_5();
			break;
		case 6:
			subParagraph_9_5_6();
			break;
		case 7:
			subParagraph_9_5_7();
			break;
		case 8:
			subParagraph_9_5_8();
			// extra stuff about User Defined Literal (UDL)
			subParagraph_9_5_8_ad1();
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
