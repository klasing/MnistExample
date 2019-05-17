#include <iostream>

#include "paragraph_d_1_1.cpp"
#include "paragraph_d_1_2.cpp"
#include "paragraph_d_1_3.cpp"
#include "paragraph_d_1_4.cpp"
#include "paragraph_d_1_5.cpp"

using namespace std;
inline void chapter_d_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.1 The <chrono> header" << endl;
		cout << "=======================" << endl;
		cout << " 1) D.1.1 std::chrono::duration class template" << endl;
		cout << " 2) D.1.2 std::chrono::time_point class template" << endl;
		cout << " 3) D.1.3 std::chrono::system_clock class template" << endl;
		cout << " 4) D.1.4 std::chrono::steady_clock class template" << endl;
		cout << " 5) D.1.5 std::chrono::high_resolution_clock class template" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_1_1();
			break;
		case 2:
			paragraph_d_1_2();
			break;
		case 3:
			paragraph_d_1_3();
			break;
		case 4:
			paragraph_d_1_4();
			break;
		case 5:
			paragraph_d_1_5();
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
