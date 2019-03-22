#include "pch.h"

//#include "SubParagraph_27_5_1.cpp"
//#include "SubParagraph_27_5_2.cpp"
//#include "SubParagraph_27_5_3.cpp"
//#include "SubParagraph_27_5_4.cpp"
//#include "SubParagraph_27_5_5.cpp"
//#include "SubParagraph_27_5_6.cpp"
//#include "SubParagraph_27_5_7.cpp"

inline void paragraph_27_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Debugging Techniques" << endl;
		cout << "====================" << endl;
		cout << " 1) Reproducing Bugs" << endl;
		cout << " 2) Debugging Reproducible Bugs" << endl;
		cout << " 3) Debugging Nonreproducible Bugs" << endl;
		cout << " 4) Debugging Memory Problems" << endl;
		cout << " 5) Debugging Multithreaded Programs" << endl;
		cout << " 6) Debugging Example: Article Citations" << endl;
		cout << " 7) Lessons from the Article Citations Example" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_27_5_1();
			break;
		case 2:
			//subParagraph_27_5_2();
			break;
		case 3:
			//subParagraph_27_5_3();
			break;
		case 4:
			//subParagraph_27_5_4();
			break;
		case 5:
			//subParagraph_27_5_5();
			break;
		case 6:
			//subParagraph_27_5_6();
			break;
		case 7:
			//subParagraph_27_5_7();
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
