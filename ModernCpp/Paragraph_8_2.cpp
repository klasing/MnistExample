#include "pch.h"

#include "SubParagraph_8_2_1.cpp"
#include "SubParagraph_8_2_2.cpp"
#include "SubParagraph_8_2_3.cpp"

inline void paragraph_8_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Inheritance for Reuse" << endl;
		cout << "=====================" << endl;
		cout << " 1) The WeatherPrediction Class" << endl;
		cout << " 2) Adding Functionality in a Subclass" << endl;
		cout << " 3) Replacing Functionality in a Subclass" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_8_2_1();
			break;
		case 2:
			subParagraph_8_2_2();
			break;
		case 3:
			subParagraph_8_2_3();
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
