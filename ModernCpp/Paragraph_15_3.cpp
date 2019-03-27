#include "pch.h"

#include <fstream>

#include "SubParagraph_15_3_1.cpp"
#include "SubParagraph_15_3_2.cpp"

inline int main_15_3(int argc, char* argv[]) {
	ofstream outFile("test");

	if (!outFile.good()) {
		cerr << "-> Error while opening output file!" << endl;
		return -1;
	}
	outFile << "There were " << argc << " arguments to this program." << endl;
	outFile << "They are:" << endl;
	for (int i = 0; i < argc; i++)
		outFile << argv[i] << endl;

	return 0;
}

inline void paragraph_15_3() {
	char arg_1[6], arg_2[6], arg_3[6];
	strcpy_s(arg_1, 6, "arg 1");
	strcpy_s(arg_2, 6, "arg 2");
	strcpy_s(arg_3, 6, "arg 3");
	char* paChar[] = { arg_1, arg_2, arg_3 };
	main_15_3(3, paChar);

	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "File Streams" << endl;
		cout << "============" << endl;
		cout << " 1) Jumping around with seek() and tell()" << endl;
		cout << " 2) Linking Streams Together" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_15_3_1();
			break;
		case 2:
			subParagraph_15_3_2();
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
