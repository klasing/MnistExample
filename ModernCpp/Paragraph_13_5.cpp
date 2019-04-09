#include "pch.h"

#include "SubParagraph_13_5_1.cpp"
#include "SubParagraph_13_5_2.cpp"
#include "SubParagraph_13_5_3.cpp"
#include "SubParagraph_13_5_4.cpp"

inline void paragraph_13_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Algorithm Example: Auditing Voter Registrations" << endl;
		cout << "===============================================" << endl;
		cout << " 1) The Voter Registration Audit Problem Statement" << endl;
		cout << " 2) The auditVoterRolls Function" << endl;
		cout << " 3) The getDuplicates Function" << endl;
		cout << " 4) Testing the auditVoterRolls Function" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_13_5_1();
			break;
		case 2:
			subParagraph_13_5_2();
			break;
		case 3:
			subParagraph_13_5_3();
			break;
		case 4:
			subParagraph_13_5_4();
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
