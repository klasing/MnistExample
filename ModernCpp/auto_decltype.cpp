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
////#include "wrapper.h"
////#include "factorial.h"
////#include "loop.h"
////
//////****************************************************************************
//////*                     DoAddition2
//////****************************************************************************
////template<typename T1, typename T2>
////auto DoAddition2(const T1& t1, const T2& t2) -> decltype(t1 + t2) {
////	return t1 + t2;
////}
////
//////****************************************************************************
//////*                     handleValue
//////****************************************************************************
////inline void handleValue(int value) { cout << "Integer: " << value << endl; }
////inline void handleValue(double value) { cout << "Double: " << value << endl; }
////inline void handleValue(const char* value) { cout << "String: " << value << endl; }
////
//////****************************************************************************
//////*                     processValues
//////****************************************************************************
////// base case
////template<typename T>
////void processValuesRValueRefs(T&& arg) {
////	handleValue(arg);
////}
////
////template<typename T1, typename... Tn>
////void processValuesRValueRefs(T1&& arg1, Tn&&... args) {
////	processValuesRValueRefs(arg1);
////	processValuesRValueRefs(args...);
////}
////
//////****************************************************************************
//////*                     DoWork
//////****************************************************************************
////inline void DoWork(int i) {
////	cout << "DoWork(" << i << ")" << endl;
////}
////
//////****************************************************************************
//////*                     DoWork2
//////****************************************************************************
////inline double DoWork2(string str, int i) {
////	cout << "DoWork2(" << str << ", " << i << ")" << endl;
////	return 0.0;
////}
////
//////****************************************************************************
//////*                     loopFunc
//////****************************************************************************
////template<int i, typename FuncType>
////void loopFunc(FuncType f) {
////	Loop<i, FuncType>::Do(f);
////}
////
//////****************************************************************************
//////*                     auto_decltype
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline VOID auto_decltype(HANDLE hStdin, DWORD fdwSaveOldMode) {
////
////	OutputDebugString(L"auto_decltype()\n");
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the menu until the user leaves
////	while (bProceed) {
////		cout << "    Auto, Decltype" << endl;
////		cout << "    ==============" << endl;
////		cout << " 1) Alternative function syntax" << endl;
////		cout << " 2) decltype()" << endl;
////		cout << " 3) Variadic templates" << endl;
////		cout << " 4) Metaprogramming" << endl;
////		cout << " 5) Loop unrolling" << endl;
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
////				cout << "auto func(int i) -> int {" << endl;
////				cout << "    return i + 2;" << endl;
////				cout << "}" << endl;
////
////				cout << endl;
////				break;
////			} // eof case 1
////			case 2: {
////				cout << endl;
////
////				MyInt i(4);
////				MyString str("5");
////				auto d = DoAddition2(i, str);
////				auto e = DoAddition2(str, i);
////				// requires an operator<< overloading for the two classes
////				cout << "d: " << d << " e: " << e << endl;
////
////				cout << endl;
////				break;
////			} // eof case 2
////			case 3: {
////				cout << endl;
////
////				cout << "processValuesRValueRefs(1, 2, 3.56, \"test\", 1.1f);" << endl;
////				processValuesRValueRefs(1, 2, 3.56, "test", 1.1f);
////
////				cout << endl;
////				break;
////			} // eof case 3
////			case 4: {
////				cout << endl;
////
////				// metaprogramming
////				cout << "Factorial<12>::val" << endl;
////				cout << Factorial<12>::val << endl;
////
////				cout << endl;
////				break;
////			} // eof case 4
////			case 5: {
////				cout << endl;
////
////				//cout << "Loop<3, function<void(int)>>::Do(DoWork);" << endl;
////				cout << "Loop<3, decltype(DoWork)>::Do(DoWork);" << endl;
////				Loop<3, decltype(DoWork)>::Do(DoWork);
////
////				cout << "auto a = bind(DoWork2, \"TestStr\", placeholders::_1);" << endl;
////				cout << "Loop <2, decltype(a)>::Do(a);" << endl;
////				auto a = bind(DoWork2, "TestStr", placeholders::_1);
////				Loop<2, decltype(a)>::Do(a);
////
////				cout << "loopFunc<2>(bind(DoWork2, \"TestStr\", placeholders::_1));" << endl;
////				loopFunc<2>(bind(DoWork2, "TestStr", placeholders::_1));
////
////				cout << endl;
////				break;
////			} // eof case 5
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