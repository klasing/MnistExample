#include "pch.h"

#include "SubParagraph_2_5_1.cpp"
#include "SubParagraph_2_5_2.cpp"
#include "SubParagraph_2_5_3.cpp"
#include "SubParagraph_2_5_4.cpp"
#include "SubParagraph_2_5_5.cpp"
#include "SubParagraph_2_5_6.cpp"

inline void paragraph_2_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Reusing Code" << endl;
		cout << "============" << endl;
		cout << " 1) A Note on Terminology" << endl;
		cout << " 2) Deciding Whether or Not to Reuse Code" << endl;
		cout << " 3) Strategies for Reusing Code" << endl;
		cout << " 4) Bundling Third-Party Applications" << endl;
		cout << " 5) Open-Source Libraries" << endl;
		cout << " 6) The C++ Standard Library" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_2_5_1();
			break;
		case 2:
			subParagraph_2_5_2();
			break;
		case 3:
			subParagraph_2_5_3();
			break;
		case 4:
			subParagraph_2_5_4();
			break;
		case 5:
			subParagraph_2_5_5();
			break;
		case 6:
			subParagraph_2_5_6();
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
