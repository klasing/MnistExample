#include "pch.h"

#include "Paragraph_22_1.cpp"
#include "Paragraph_22_2.cpp"
#include "Paragraph_22_3.cpp"
#include "Paragraph_22_4.cpp"
#include "Paragraph_22_5.cpp"
#include "Paragraph_22_6.cpp"
#include "Paragraph_22_7.cpp"
#include "Paragraph_22_8.cpp"
#include "Paragraph_22_9.cpp"
#include "Paragraph_22_10.cpp"

inline void chapter22() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 22, Multithreaded Programming with C++" << endl;
		cout << "==============================================" << endl;
		cout << " 1) Introduction" << endl;
		cout << " 2) Atomic Operations Library" << endl;
		cout << " 3) Threads" << endl;
		cout << " 4) Mutual Exclusion" << endl;
		cout << " 5) Condition Variables" << endl;
		cout << " 6) Futures" << endl;
		cout << " 7) Example: Multithreaded Logger Class" << endl;
		cout << " 8) Thread Pools" << endl;
		cout << " 9) Threading Design and Best Practices" << endl;
		cout << "10) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_22_1();
			break;
		case 2:
			paragraph_22_2();
			break;
		case 3:
			paragraph_22_3();
			break;
		case 4:
			paragraph_22_4();
			break;
		case 5:
			paragraph_22_5();
			break;
		case 6:
			paragraph_22_6();
			break;
		case 7:
			paragraph_22_7();
			break;
		case 8:
			paragraph_22_8();
			break;
		case 9:
			paragraph_22_9();
			break;
		case 10:
			paragraph_22_10();
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
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "Threads.cpp"
//#include "MutualExclusion.cpp"
//
////****************************************************************************
////*                     chapter22
////****************************************************************************
//// function must be inline
//inline void chapter22() {
//	OutputDebugString(L"chapter22()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Multithreaded programming with C++" << endl;
//		cout << "==================================" << endl;
//		cout << " 1) Introduction" << endl;
//		cout << " 2) Atomic operations library" << endl;
//		cout << " 3) Threads" << endl;
//		cout << " 4) Mutual exclusion" << endl;
//		cout << " 5) Condition variables" << endl;
//		cout << " 6) Futures" << endl;
//		cout << " 7) Example: Multithreaded logger class" << endl;
//		cout << " 8) Thread pools" << endl;
//		cout << " 9) Threading design and best practices" << endl;
//		cout << "10) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Introduction" << endl;
//			cout << "============" << endl;
//
//			cout << "Race conditions and deadlocks" << endl;
//
//			break;
//		case 2:
//			cout << "Atomic operations library" << endl;
//			cout << "=========================" << endl;
//
//			break;
//		case 3:
//			threads();
//
//			break;
//		case 4:
//			mutualExclusion();
//
//			break;
//		case 5:
//			cout << "Condition variables" << endl;
//			cout << "===================" << endl;
//
//			cout << "std::condition_variable" << endl;
//			cout << "std::condition_variable_any" << endl;
//			cout << "methods: notify_one(), notify_all()," << endl;
//			cout << "  wait(unique_lock<mutex>& lk)," << endl;
//			cout << "  wait_for(unique_lock<mutex>& lk," << endl;
//			cout << "    const chrono::duration<Rep, Period>& rel_time)" << endl;
//			cout << "  wait_until(unique_lock<mutex>& lk," << endl;
//			cout << "    const chrono::time_point<Clock, Duration>& abs_time)" << endl;
//
//			break;
//		case 6:
//			cout << "Futures" << endl;
//			cout << "=======" << endl;
//
//			cout << "std::promise" << endl;
//			cout << "std::future" << endl;
//			cout << "std::packaged_task" << endl;
//			cout << "" << endl;
//
//			break;
//		case 7:
//			cout << "Example: Multithreaded logger class" << endl;
//			cout << "===================================" << endl;
//
//			break;
//		case 8:
//			cout << "Thread pools" << endl;
//			cout << "============" << endl;
//
//			break;
//		case 9:
//			cout << "Threading design and best practices" << endl;
//			cout << "===================================" << endl;
//
//			break;
//		case 10:
//			cout << "Summary" << endl;
//			cout << "=======" << endl;
//
//			break;
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}