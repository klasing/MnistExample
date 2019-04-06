#include "pch.h"

#include "SubParagraph_8_6_1.cpp"
#include "SubParagraph_8_6_2.cpp"
#include "SubParagraph_8_6_3.cpp"
#include "SubParagraph_8_6_4.cpp"
#include "SubParagraph_8_6_5.cpp"
#include "SubParagraph_8_6_6.cpp"
#include "SubParagraph_8_6_7.cpp"
#include "SubParagraph_8_6_8.cpp"

inline void paragraph_8_6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Interesting and Obscure Inheritance Issues" << endl;
		cout << "==========================================" << endl;
		cout << " 1) Changing the Overriden Method's Characteristics" << endl;
		cout << " 2) Inherited Constructors" << endl;
		cout << " 3) Special Cases In Overriding Methods" << endl;
		cout << " 4) Copy Constructor and the Equals Operator in Subclasses" << endl;
		cout << " 5) The Truth about Virtual" << endl;
		cout << " 6) Run Time Type Facilities" << endl;
		cout << " 7) Non-Public Inheritance" << endl;
		cout << " 8) Virtual Base Classes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_8_6_1();
			break;
		case 2:
			subParagraph_8_6_2();
			break;
		case 3:
			subParagraph_8_6_3();
			break;
		case 4:
			subParagraph_8_6_4();
			break;
		case 5:
			subParagraph_8_6_5();
			break;
		case 6:
			subParagraph_8_6_6();
			break;
		case 7:
			subParagraph_8_6_7();
			break;
		case 8:
			subParagraph_8_6_8();
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
