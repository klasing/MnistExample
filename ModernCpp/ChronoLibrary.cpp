#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//
////****************************************************************************
////*                     chronoLibrary
////****************************************************************************
//// function must be inline
//inline void chronoLibrary() {
//	OutputDebugString(L"chronoLibrary()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "The Chrono library" << endl;
//		cout << "==================" << endl;
//		cout << " 1) Duration" << endl;
//		cout << " 2) Clock" << endl;
//		cout << " 3) Time point" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Duration" << endl;
//			cout << "========" << endl;
//			break;
//		case 2: {
//			cout << "Clock" << endl;
//			cout << "=====" << endl;
//
//			// get the current time as a time_point
//			// use the correct namespace!
//			chrono::system_clock::time_point tpoint = chrono::system_clock::now();
//			// convert to a time_t
//			time_t tt = chrono::system_clock::to_time_t(tpoint);
//			// convert to local time
//			// Project -> ModernCpp Properties... -> Configuration Properties ->
//			// C/C++ -> Preprocessor
//			// Edit into Preprocessor definitions: _CRT_SECURE_NO_WARNINGS
//			tm* t = localtime(&tt);
//			// write the time to the console
//			cout << "Current local time: " << put_time(t, "%H:%M:%S") << endl;
//
//			// time the duration for the execution of a piece of code
//			// get the start time
//			auto start = chrono::system_clock::now();
//			// execute the code you want to time
//			double d = 0.;
//			for (int i = 0; i < 1e6; i++)
//				d += sqrt(sin(i) * cos(i));
//			// get the end time and calculate the difference
//			auto end = chrono::system_clock::now();
//			auto diff = end - start;
//			// convert the difference into milliseconds and print this
//			// on the console
//			cout << "Execution took: " << chrono::duration<double, milli>(diff).count() << "ms" << endl;
//
//			break;
//		} // eof case 2
//		case 3: {
//			cout << "Time point" << endl;
//			cout << "==========" << endl;
//
//			// create a time_point representing the epoch
//			// of the associatted steady clock
//			chrono::time_point<chrono::steady_clock> tp1;
//			// add 10 minutes to the time_point
//			tp1 += chrono::minutes(10);
//			// store the duration between epoch and time_point
//			auto d1 = tp1.time_since_epoch();
//			// convert the duration to seconds and write the result to the console
//			chrono::duration<double> d2(d1);
//			cout << "10 minutes duration after epoch is: " << d2.count() << " seconds" << endl;
//
//			break;
//		} // eof case 3
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