#include <iostream>

#include "paragraph_d_4_1.cpp"
#include "paragraph_d_4_2.cpp"
#include "paragraph_d_4_3.cpp"
#include "paragraph_d_4_4.cpp"
#include "paragraph_d_4_5.cpp"

using namespace std;
inline void chapter_d_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.4 <future> header" << endl;
		cout << "===================" << endl;
		cout << " 1) D.4.1 std::future class template" << endl;
		cout << " 2) D.4.2 std::shared_future class template" << endl;
		cout << " 3) D.4.3 std::packaged_task class template" << endl;
		cout << " 4) D.4.4 std::promise class template" << endl;
		cout << " 5) D.4.5 std::async function template" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_4_1();
			break;
		case 2:
			paragraph_d_4_2();
			break;
		case 3:
			paragraph_d_4_3();
			break;
		case 4:
			paragraph_d_4_4();
			break;
		case 5:
			paragraph_d_4_5();
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
