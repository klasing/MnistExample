#include "pch.h"
//#pragma once
//
//#include "pch.h"
////#pragma once
////
////#include "pch.h"
////
////#include "waitForUserEvent.cpp"
////#include "getNumber.cpp"
////
//////****************************************************************************
//////*                     geometricMean
//////****************************************************************************
////inline double geometricMean(const vector<int>& nums) {
////
////	OutputDebugString(L"geometricMean()\n");
////
////	// calculates the factorial of elements in nums ( nums! )
////	double mult = accumulate(nums.begin(), nums.end(), 1, 
////		multiplies<int>());
////
////	return pow(mult, 1.0 / nums.size());
////}
////
//////****************************************************************************
//////*                     function_object
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline VOID function_object(HANDLE hStdin, DWORD fdwSaveOldMode) {
////
////	OutputDebugString(L"function_object()\n");
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the menu until the user leaves
////	while (bProceed) {
////		cout << "    Function object" << endl;
////		cout << "    ===============" << endl;
////		cout << " 1) Arithmic function object" << endl;
////		cout << " 2) Comparison function object" << endl;
////		cout << " 3) Logical function object" << endl;
////		cout << " 4) Bitwise function object" << endl;
////		cout << " 5) Function object adapter" << endl;
////		cout << "Enter the number of a subject, or enter a zero to return to the main menu: ";
////
////		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
////		bValid = getNumber(choiceBuffer, iChoiceMenu);
////
////		if (bValid)
////			// the user has entered a valid number for the menu
////			switch (iChoiceMenu) {
////			case 1: {
////				cout << endl;
////
////				vector<int> vec = { 1, 2, 3, 4, 5 };
////				cout << geometricMean(vec) << endl;
////
////				cout << endl;
////				break;
////			} // eof case 1
////			case 2: {
////				cout << endl;
////
////				// modify the template for the container to establish a 'greater than' behaviour
////				// sort elements in ascending (instead of descending) order
////				cout << "priority_queue<int, vector<int>, greater<int>> myQueue;" << endl;
////				priority_queue<int, vector<int>, greater<int>> myQueue;
////				myQueue.push(3);
////				myQueue.push(4);
////				myQueue.push(2);
////				myQueue.push(1);
////				while (!myQueue.empty()) {
////					cout << myQueue.top() << " ";
////					myQueue.pop();
////				}
////
////				cout << endl;
////				break;
////			} // eof case 1
////			case 0:
////				// the user wants to leave the subject
////				bProceed = FALSE;
////				break;
////			default:
////				// the input, given by the user, is not an available option
////				cout << "The entered number is not recognized, please try again." << endl;
////			} // eof switch
////	}
////}