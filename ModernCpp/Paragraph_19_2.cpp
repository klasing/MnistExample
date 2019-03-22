#include "pch.h"

//#include "SubParagraph_19_2_1.cpp"
//#include "SubParagraph_19_2_2.cpp"
//#include "SubParagraph_19_2_3.cpp"
//#include "SubParagraph_19_2_4.cpp"
//#include "SubParagraph_19_2_5.cpp"
//#include "SubParagraph_19_2_6.cpp"
//#include "SubParagraph_19_2_7.cpp"
//#include "SubParagraph_19_2_8.cpp"
//#include "SubParagraph_19_2_9.cpp"
//#include "SubParagraph_19_2_10.cpp"

inline void paragraph_19_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Class Templates" << endl;
		cout << "===============" << endl;
		cout << " 1) Writing a Class Template" << endl;
		cout << " 2) How the Compiler Processes Templates" << endl;
		cout << " 3) Distributing Template Code between Files" << endl;
		cout << " 4) Template parameters" << endl;
		cout << " 5) Method Templates" << endl;
		cout << " 6) Template Class Specialization" << endl;
		cout << " 7) Subclassing Template Classes" << endl;
		cout << " 8) Inheritance versus Specialization" << endl;
		cout << " 9) Template Aliases" << endl;
		cout << "10) Alternative Function Syntax" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_19_2_1();
			break;
		case 2:
			//subParagraph_19_2_2();
			break;
		case 3:
			//subParagraph_19_2_3();
			break;
		case 4:
			//subParagraph_19_2_4();
			break;
		case 5:
			//subParagraph_19_2_5();
			break;
		case 6:
			//subParagraph_19_2_6();
			break;
		case 7:
			//subParagraph_19_2_7();
			break;
		case 8:
			//subParagraph_19_2_8();
			break;
		case 9:
			//subParagraph_19_2_9();
			break;
		case 10:
			//subParagraph_19_2_10();
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
