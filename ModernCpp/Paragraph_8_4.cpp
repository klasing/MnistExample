#include "pch.h"

//#include "SubParagraph_8_4_1.cpp"
//#include "SubParagraph_8_4_2.cpp"
//#include "SubParagraph_8_4_3.cpp"
//#include "SubParagraph_8_4_4.cpp"
//#include "SubParagraph_8_4_5.cpp"
//#include "SubParagraph_8_4_6.cpp"

inline void paragraph_8_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Inheritance for Polymorphism" << endl;
		cout << "============================" << endl;
		cout << " 1) Return of the Spreadsheet" << endl;
		cout << " 2) Designing the Polymorphic Spreadsheet Cell" << endl;
		cout << " 3) The Spreadsheet Cell Base Class" << endl;
		cout << " 4) The Individual Subclasses" << endl;
		cout << " 5) Leveraging Polymorphism" << endl;
		cout << " 6) Future Considerations" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_8_4_1();
			break;
		case 2:
			//subParagraph_8_4_2();
			break;
		case 3:
			//subParagraph_8_4_3();
			break;
		case 4:
			//subParagraph_8_4_4();
			break;
		case 5:
			//subParagraph_8_4_5();
			break;
		case 6:
			//subParagraph_8_4_6();
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
