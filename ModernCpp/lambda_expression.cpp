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
//////*                     multiplyBy2Lambda
//////****************************************************************************
////inline function<int(void)> multiplyBy2Lambda(int x) {
////
////	OutputDebugString(L"multiplyBy2Lambda()\n");
////
////	//return[=]()->int {return 2 * x; };
////	// empty parameter list and return type can be omitted
////	return[=]{return 2 * x; };
////}
////
//////****************************************************************************
//////*                     testCallback
//////****************************************************************************
////inline void testCallback(const vector<int>& vec, 
////	const function<bool(int)>& callback) {
////
////	OutputDebugString(L"testCallback()\n");
////
////	for (auto i : vec) {
////		// call callback, if it returns false the iteration stops
////		if (!callback(i))
////			break;
////		// callback did not stop the iteration, so print the value
////		cout << i << " ";
////	}
////	cout << endl;
////
////}
////
//////****************************************************************************
//////*                     lambda_expression
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline VOID lambda_expression(HANDLE hStdin, DWORD fdwSaveOldMode) {
////
////	OutputDebugString(L"lambda_expression()\n");
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the menu until the user leaves
////	while (bProceed) {
////		cout << "    Lambda expression" << endl;
////		cout << "    ==================" << endl;
////		cout << " 1) Syntax" << endl;
////		cout << " 2) Example" << endl;
////		cout << " 3) Lambda expression as return type" << endl;
////		cout << " 4) Lambda expression as parameter" << endl;
////		cout << " 5) count_if()" << endl;
////		cout << " 6) generate()" << endl;
////		cout << " 7) for_each()" << endl;
////		cout << "Enter the number of a subject, or enter a zero to return to the main menu: ";
////
////		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
////		bValid = getNumber(choiceBuffer, iChoiceMenu);
////
////		if (bValid)
////			// the user has entered a valid number for the menu
////			switch (iChoiceMenu) {
////			case 1:
////				cout << endl;
////
////				cout << "Syntax" << endl;
////				cout << "[capture_block][parameters] mutable exception_specification -> return_type {body}" << endl;
////
////				cout << endl;
////				break;
////			case 2: {
////				cout << endl;
////
////				cout << "Example" << endl;
////				cout << "[] {cout << \"hello from lambda\" << endl; }();" << endl;
////				[] {cout << "hello from lambda" << endl; }();
////				cout << endl;
////
////				cout << "string result = [](const string str) {return \"hello from lambda \" + str; }(\"second lambda\");" << endl;
////				//string result = [](const string str) -> string {return "hello from lambda " + str; }("second lambda");
////				// return type can be omitted
////				string result = [](const string str) {return "hello from lambda " + str; }("second lambda");
////				cout << result.c_str() << endl;
////				cout << endl;
////
////				// lambda expression via a function pointer
////				cout << "auto fn = [](const string& str) {return \"hello from \" + str; };" << endl;
////				auto fn = [](const string& str) {return "hello from " + str; };
////				cout << fn("call 1").c_str() << endl;
////				cout << fn("call 2").c_str() << endl;
////				cout << endl;
////
////				cout << endl;
////				break;
////			} // eof case 2
////			case 3: {
////				cout << endl;
////
////				//function<int(void)> fn = multiplyBy2Lambda(5);
////				// the function type declaration can be replaced by the keyword auto
////				auto fn = multiplyBy2Lambda(5);
////				cout << "auto fn = multiplyBy2Lambda(5);" << endl;
////				cout << fn() << endl;
////
////				cout << endl;
////				break;
////			} // eof case 3
////			case 4: {
////				cout << endl;
////
////				vector<int> vec(10);
////				int index = 0;
////				generate(vec.begin(), vec.end(), [&index] {return ++index; });
////				cout << "testCallback(vec, [](int i) {return i < 6; });" << endl;
////				for_each(vec.begin(), vec.end(), [](int i) {cout << i << " "; });
////				cout << endl;
////				testCallback(vec, [](int i) {return i < 6; });
////
////				cout << endl;
////				break;
////			} // eof case 4
////			case 5: {
////				cout << endl;
////
////				vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
////				int value = 3;
////				int cntLambdaCalled = 0;
////				int cnt = count_if(vec.cbegin(), vec.cend(),
////					[=, &cntLambdaCalled](int i) {++cntLambdaCalled; return i > value; });
////				cout << "int cnt = count_if(vec.cbegin(), vec.cend(), [=, &cntLambdaCalled](int i)" << endl;
////				cout << "          {++cntLambdaCalled; return i > value; });" << endl;
////				cout << "the lambda expression was called " << cntLambdaCalled << " times" << endl;
////				cout << "found: " << cnt << " values > " << value << endl;
////
////				cout << endl;
////				break;
////			} // eof case 5
////			case 6: {
////				cout << endl;
////
////				vector<int> vec(10);
////				int value = 1;
////				generate(vec.begin(), vec.end(), [&value] {value *= 2; return value; });
////				cout << "generate(vec.begin(), vec.end(), [&value] {value *= 2; return value; });" << endl;
////				for (auto i : vec)
////					cout << i << " ";
////
////				cout << endl;
////				break;
////			} // eof case 6
////			case 7: {
////				cout << endl;
////
////				vector<int> vec = { 11, 22, 33, 44 };
////				int index = 0;
////				cout << "for_each(vec.begin(), vec.end(), [&index](int i)" << endl;
////				cout << "  {cout << \"value \" << (index++) << \": \" << i << endl; });" << endl;
////				for_each(vec.begin(), vec.end(),
////					[&index](int i) {cout << "value " << (index++) << ": " << i << endl; });
////
////				cout << endl;
////				break;
////			} // eof case 7
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
