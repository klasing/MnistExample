#include <iostream>

#include "chapter_d_1.cpp";
#include "chapter_d_2.cpp";
#include "chapter_d_3.cpp";
#include "chapter_d_4.cpp";
#include "chapter_d_5.cpp";
#include "chapter_d_6.cpp";
#include "chapter_d_7.cpp";

using namespace std;
inline void partD() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C++ Thread Library reference" << endl;
		cout << "============================" << endl;
		cout << " 1) D.1 The <chrono> header" << endl;
		cout << " 2) D.2 <condition_variable> header" << endl;
		cout << " 3) D.3 <atomic> header" << endl;
		cout << " 4) D.4 <future> header" << endl;
		cout << " 5) D.5 <mutex> header" << endl;
		cout << " 6) D.6 <ratio> header" << endl;
		cout << " 7) D.7 <thread> header" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter_d_1();
			break;
		case 2:
			chapter_d_2();
			break;
		case 3:
			chapter_d_3();
			break;
		case 4:
			chapter_d_4();
			break;
		case 5:
			chapter_d_5();
			break;
		case 6:
			chapter_d_6();
			break;
		case 7:
			chapter_d_7();
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
