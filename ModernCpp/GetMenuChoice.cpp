#include "pch.h"
//// directive must be stated
//#pragma once
//
//#include "pch.h"
//
////****************************************************************************
////*                     getMenuChoice
////****************************************************************************
//// function must be inline
//inline int getMenuChoice() {
//	OutputDebugString(L"getMenuChoice()\n");
//
//	// first character given by the user
//	int nChoice = getchar() - 48;
//	// second character given by the user
//	int iChar = getchar();
//	if (iChar != '\n') {
//		nChoice *= 10 + (iChar - 48);
//		// get rid of enter
//		getchar();
//	}
//
//	return nChoice;
//}