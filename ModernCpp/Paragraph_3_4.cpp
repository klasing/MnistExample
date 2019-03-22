#include "pch.h"

//#include "SubParagraph_3_4_1.cpp"
//#include "SubParagraph_3_4_2.cpp"
//#include "SubParagraph_3_4_3.cpp"
//#include "SubParagraph_3_4_4.cpp"
//#include "SubParagraph_3_4_5.cpp"
//#include "SubParagraph_3_4_6.cpp"
//#include "SubParagraph_3_4_7.cpp"

inline void paragraph_3_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Object Relationships" << endl;
		cout << "====================" << endl;
		cout << " 1) The Has-A Relationship" << endl;
		cout << " 2) The Is-A Relationship (Inheritance)" << endl;
		cout << " 3) The Fine Line between Has-A and Is-A" << endl;
		cout << " 4) The Not-A Relationship" << endl;
		cout << " 5) Hierarchies" << endl;
		cout << " 6) Multiple Inheritance" << endl;
		cout << " 7) Mix-in Classes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_3_4_1();
			break;
		case 2:
			//subParagraph_3_4_2();
			break;
		case 3:
			//subParagraph_3_4_3();
			break;
		case 4:
			//subParagraph_3_4_4();
			break;
		case 5:
			//subParagraph_3_4_5();
			break;
		case 6:
			//subParagraph_3_4_6();
			break;
		case 7:
			//subParagraph_3_4_7();
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
