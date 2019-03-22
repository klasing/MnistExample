#include "pch.h"

//#include "SubParagraph_14_3_1.cpp"
//#include "SubParagraph_14_3_2.cpp"
//#include "SubParagraph_14_3_3.cpp"
//#include "SubParagraph_14_3_4.cpp"
//#include "SubParagraph_14_3_5.cpp"
//#include "SubParagraph_14_3_6.cpp"
//#include "SubParagraph_14_3_7.cpp"

inline void paragraph_14_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Regular Expressions" << endl;
		cout << "===================" << endl;
		cout << " 1) ECMAScript Syntax" << endl;
		cout << " 2) The regex Library" << endl;
		cout << " 3) regex_match()" << endl;
		cout << " 4) regex_search()" << endl;
		cout << " 5) regex_iterator" << endl;
		cout << " 6) regex_token_iterator" << endl;
		cout << " 7) regex_replace()" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_14_3_1();
			break;
		case 2:
			//subParagraph_14_3_2();
			break;
		case 3:
			//subParagraph_14_3_3();
			break;
		case 4:
			//subParagraph_14_3_4();
			break;
		case 5:
			//subParagraph_14_3_5();
			break;
		case 6:
			//subParagraph_14_3_6();
			break;
		case 7:
			//subParagraph_14_3_7();
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
