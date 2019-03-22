#include "pch.h"
//#pragma once
//
//#include "pch.h"
////#pragma once
////
////#include "pch.h"
////
//////****************************************************************************
//////*                     getNumberT
//////****************************************************************************
////template<typename T>
////// it remains a mystery why the keyword: inline has to be added
////inline BOOL getNumberT(const char choiceBuffer[], T& number) {
////	OutputDebugString(L"getNumber()\n");
////
////	const USHORT MAX_BUF = 32;
////	char* pszBuffer = new char[MAX_BUF];
////	string strLine = choiceBuffer;
////
////	if (strLine.length() == 0)
////		// no input is given
////		return FALSE;
////
////	if (typeid(number) == typeid(USHORT)) {
////		int iVal = atoi(strLine.c_str());
////		// parenthesis are necessary
////		if (iVal > (numeric_limits<USHORT>::max)()) {
////			// parenthesis are necessary
////			sprintf_s(pszBuffer, MAX_BUF, "input > %d", (numeric_limits<USHORT>::max)());
////			throw range_error(pszBuffer);
////		}
////		if (iVal < 0)
////			throw range_error("input can't be negative");
////
////		number = iVal;
////		return TRUE;
////	}
////
////	return FALSE;
////}
//////****************************************************************************
//////*                     getNumber
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline BOOL getNumber(const char choiceBuffer[], USHORT& iChoiceMenu) {
////	OutputDebugString(L"getNumber()\n");
////
////	BOOL bValid = FALSE;
////
////	try {
////		// try to get a valid value from the user input
////		bValid = getNumberT<USHORT>(choiceBuffer, iChoiceMenu);
////	}
////	catch (exception& e) {
////		// the value, given by the user, is out of range
////		// for a <USHORT> type
////		cout << typeid(e).name() << ": " << e.what() << endl;
////	}
////
////	return bValid;
////}
