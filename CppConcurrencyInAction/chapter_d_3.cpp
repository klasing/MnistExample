#include <iostream>

#include "paragraph_d_3_1.cpp"
#include "paragraph_d_3_2.cpp"
#include "paragraph_d_3_3.cpp"
#include "paragraph_d_3_4.cpp"
#include "paragraph_d_3_5.cpp"
#include "paragraph_d_3_6.cpp"
#include "paragraph_d_3_7.cpp"
#include "paragraph_d_3_8.cpp"
#include "paragraph_d_3_9.cpp"
#include "paragraph_d_3_10.cpp"

using namespace std;
inline void chapter_d_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "D.3 <atomic> header" << endl;
		cout << "===================" << endl;
		cout << " 1) D.3.1 std::atomic_xxx typedefs" << endl;
		cout << " 2) D.3.2 std::ATOMIC_xxx_LOCK_FREE macros" << endl;
		cout << " 3) D.3.3 std::ATOMIC_VAR_INIT macro" << endl;
		cout << " 4) D.3.4 std::memory_order enumeration" << endl;
		cout << " 5) D.3.5 std::atomic_thread_fence function" << endl;
		cout << " 6) D.3.6 std::atomic_signal_fence function" << endl;
		cout << " 7) D.3.7 std::atomic_flag class" << endl;
		cout << " 8) D.3.8 std::atomic class template" << endl;
		cout << " 9) D.3.9 Specializations of the std::atomic template" << endl;
		cout << "10) D.3.10 std::atomic<integral-type> specializations" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_d_3_1();
			break;
		case 2:
			paragraph_d_3_2();
			break;
		case 3:
			paragraph_d_3_3();
			break;
		case 4:
			paragraph_d_3_4();
			break;
		case 5:
			paragraph_d_3_5();
			break;
		case 6:
			paragraph_d_3_6();
			break;
		case 7:
			paragraph_d_3_7();
			break;
		case 8:
			paragraph_d_3_8();
			break;
		case 9:
			paragraph_d_3_9();
			break;
		case 10:
			paragraph_d_3_10();
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
