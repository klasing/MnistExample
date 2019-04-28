#include "pch.h"

#include "Part1.cpp"
#include "Part2.cpp"
#include "Part3.cpp"
#include "Part4.cpp"

#include <mutex>

//****************************************************************************
//*                     global
//****************************************************************************
// used in SubParagraph_9_7_1.cpp
bool debug_9_7_1 = false;
mutex Counter_22_4_4_a::mMutex;
timed_mutex Counter_22_4_4_b::mTimedMutex;
// used in SpreadsheetImpl.hpp
int SpreadsheetImpl::sCounter = 0;
// used in SubParagraph_24_4_3.cpp
int NothingEx::sNumAllocations = 0;
int NothingEx::sNumDeletions = 0;
// for use in SubParagraph_9_3_4.cpp
inline void ThirdPartyLibraryMethod(char* str) { /* omitted */ }

int main() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Professional C++, 2nd Edition" << endl;
		cout << "=============================" << endl;
		cout << " 1) Part I,   Introduction to Professional C++" << endl;
		cout << " 2) Part II,  C++ Coding the Professional Way" << endl;
		cout << " 3) Part III, Mastering Advanced Features of C++" << endl;
		cout << " 4) Part IV,  C++ Software Engineering" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			part1();
			break;
		case 2:
			part2();
			break;
		case 3:
			part3();
			break;
		case 4:
			part4();
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

	return 0;
}
////#include "pch.h"
////
////#include "Part1.cpp"
////#include "Part2.cpp"
////#include "Part3.cpp"
////#include "Part4.cpp"
////
//////****************************************************************************
//////*                     global
//////****************************************************************************
////// used in MutualExclusion.cpp
////mutex CounterNonInterleaved::mMutex;
////timed_mutex CounterTimedLock::mTimedMutex;
////
//////****************************************************************************
//////*                     main
//////****************************************************************************
////int main() {
////	OutputDebugString(L"main()\n");
////
////	bool bProceed = true;
////
////	// show the menu until the user terminates
////	while (bProceed) {
////		cout << "Professional C++, 2nd Edition" << endl;
////		cout << "=============================" << endl;
////		cout << " 1) Part I,   Introduction to Professional C++" << endl;
////		cout << " 2) Part II,  C++ Coding the Professional Way" << endl;
////		cout << " 3) Part III, Mastering Advanced Features of C++" << endl;
////		cout << " 4) Part IV,  C++ Software Engineering" << endl;
////		cout << "Enter the number of a part, or enter a zero to quit: ";
////
////		int iChar = getchar() - 48;
////		// get rid of enter
////		getchar();
////
////		switch (iChar) {
////		case 1:
////			part1();
////			break;
////		case 2:
////			part2();
////			break;
////		case 3:
////			part3();
////			break;
////		case 4:
////			part4();
////			break;
////		case 0:
////			// the user wants to terminate the program
////			bProceed = false;
////			break;
////		default:
////			// the input, given by the user, is not an available option
////			cout << "The entered number is not recognized, please try again." << endl;
////		} // eof switch
////		cout << endl;
////	}
////
////	// terminate the program
////	return 0;
////}
//
//////* Tools -> Options -> Debugging -> General ->
//////* Automatic close the console when debugging stops
////
////#include "pch.h"
////
////#include "waitForUserEvent.cpp"
////#include "getNumber.cpp"
////#include "max_pool.cpp"
////#include "regular_expression.cpp"
////#include "lambda_expression.cpp"
////#include "function_object.cpp"
////#include "my_tuple.cpp"
////#include "auto_decltype.cpp"
////
//////****************************************************************************
//////*                     prototype
//////****************************************************************************
////VOID ErrorExit(LPSTR, HANDLE, DWORD);
////
//////****************************************************************************
//////*                     main
//////****************************************************************************
////int main() {
////	OutputDebugString(L"main()\n");
////
////	const USHORT MAX_BUF = 32;
////	char* pszBuffer = new char[MAX_BUF];
////
////	DWORD fdwSaveOldMode = 0;
////
////	// get the standard input handle
////	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
////	if (hStdin == INVALID_HANDLE_VALUE) {
////		sprintf_s(pszBuffer, MAX_BUF, "%s", "GetStdHandle");
////		ErrorExit(pszBuffer, hStdin, fdwSaveOldMode);
////	}
////
////	// save the current input mode, to be restored on exit
////	if (!GetConsoleMode(hStdin, &fdwSaveOldMode)) {
////		sprintf_s(pszBuffer, MAX_BUF, "%s", "GetConsoleMode");
////		ErrorExit(pszBuffer, hStdin, fdwSaveOldMode);
////	}
////
////	// disable Ctrl-C event
////	SetConsoleCtrlHandler(NULL, TRUE);
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the main menu until the user terminates
////	while (bProceed) {
////		cout << "    Modern C++" << endl;
////		cout << "    ==========" << endl;
////		cout << " 1) Maxpool" << endl;
////		cout << " 2) Regular expression" << endl;
////		cout << " 3) Lambda expression" << endl;
////		cout << " 4) Function object (functor)" << endl;
////		cout << " 5) Tuple" << endl;
////		cout << " 6) auto and decltype" << endl;
////		cout << "Enter the number of a subject, or enter a zero to quit: ";
////
////		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
////		bValid = getNumber(choiceBuffer, iChoiceMenu);
////
////		if (bValid)
////			// the user has entered a valid number for the menu
////			switch (iChoiceMenu) { 
////			case 1:
////				max_pool(hStdin, fdwSaveOldMode);
////				break;
////			case 2:
////				regular_expression(hStdin, fdwSaveOldMode);
////				break;
////			case 3:
////				lambda_expression(hStdin, fdwSaveOldMode);
////				break;
////			case 4:
////				function_object(hStdin, fdwSaveOldMode);
////				break;
////			case 5:
////				my_tuple(hStdin, fdwSaveOldMode);
////				break;
////			case 6:
////				auto_decltype(hStdin, fdwSaveOldMode);
////				break;
////			case 0:
////				// the user wants to terminate the program
////				bProceed = FALSE;
////				break;
////			default:
////				// the input, given by the user, is not an available option
////				cout << "The entered number is not recognized, please try again." << endl;
////			} // eof switch
////	}
////
////	// restore input mode on exit
////	SetConsoleMode(hStdin, fdwSaveOldMode);
////
////	// terminate the program
////	return 0;
////}
////
//////****************************************************************************
//////*                     ErrorExit
//////****************************************************************************
////VOID ErrorExit(LPSTR lpszMessage, HANDLE hStdin, DWORD fdwSaveOldMode) {
////	OutputDebugString(L"ErrorExit()\n");
////
////	fprintf(stderr, "%s\n", lpszMessage);
////
////	// restore input on exit
////	SetConsoleMode(hStdin, fdwSaveOldMode);
////
////	ExitProcess(0);
////}
