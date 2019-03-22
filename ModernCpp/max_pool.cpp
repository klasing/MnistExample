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
////#include "maxpool.h"
////
//////****************************************************************************
//////*                     max_pool
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline VOID max_pool(HANDLE hStdin, DWORD fdwSaveOldMode) {
////
////	OutputDebugString(L"max_pool()\n");
////
////	// construct a Maxpool object instance
////	Maxpool maxpool;
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the menu until the user leaves
////	while (bProceed) {
////		cout << "    Maxpool" << endl;
////		cout << "    =======" << endl;
////		cout << " 1) Feed forward" << endl;
////		cout << " 2) Back propagate" << endl;
////		cout << "Enter the number of a subject, or enter a zero to return to the main menu: ";
////
////		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
////		bValid = getNumber(choiceBuffer, iChoiceMenu);
////
////		if (bValid)
////			// the user has entered a valid number for the menu
////			switch (iChoiceMenu) {
////			case 1:
////				maxpool.feedForward();
////				break;
////			case 2:
////				maxpool.backPropagate();
////				break;
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
