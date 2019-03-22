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
//////*                     tuple_print_helper
//////****************************************************************************
////template<int n, typename TupleType>
////struct tuple_print_helper {
////	tuple_print_helper(TupleType t) {
////		tuple_print_helper<n - 1, TupleType> tp(t);
////		cout << get<n-1>(t) << endl;
////	}
////};
////
////template<typename TupleType>
////struct tuple_print_helper<0, TupleType> {
////	tuple_print_helper(TupleType t) {}
////};
////
//////****************************************************************************
//////*                     tuple_print
//////****************************************************************************
////template<typename T>
////inline void tuple_print(T t) {
////
////	OutputDebugString(L"tuple_print()\n");
////
////	tuple_print_helper<tuple_size<T>::value, T> tph(t);
////}
////
//////****************************************************************************
//////*                     my_tuple
//////****************************************************************************
////// it remains a mystery why the keyword: inline has to be added
////inline VOID my_tuple(HANDLE hStdin, DWORD fdwSaveOldMode) {
////
////	OutputDebugString(L"my_tuple()\n");
////
////	const USHORT MAX_CHOICEBUF = 32;
////	char choiceBuffer[MAX_CHOICEBUF];
////
////	BOOL bProceed = TRUE, bValid = FALSE;
////	USHORT iChoiceMenu = 0;
////
////	// show the menu until the user leaves
////	while (bProceed) {
////		cout << "    Tuple" << endl;
////		cout << "    =====" << endl;
////		cout << " 1) Example" << endl;
////		cout << " 2) typeid() and tuple size" << endl;
////		cout << " 3) make_tuple() utility" << endl;
////		cout << " 4) container in a tuple, tie() utility, tuple_cat() utility, printing tuples" << endl;
////		cout << "Enter the number of a subject, or enter a zero to return to the main menu: ";
////
////		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
////		bValid = getNumber(choiceBuffer, iChoiceMenu);
////
////		typedef tuple<int, string, bool> MyTuple;
////		MyTuple t1(16, "Test", true);
////		if (bValid)
////			// the user has entered a valid number for the menu
////			switch (iChoiceMenu) {
////			case 1: {
////				cout << endl;
////
////				cout << "typedef tuple<int, string, bool> MyTuple;" << endl;
////				cout << "MyTuple t1(16, \"Test\", true);" << endl;
////				cout << "t1 = (" << get<0>(t1) << ", " << get<1>(t1).c_str() << ", " << get<2>(t1) << ")" << endl;
////
////				cout << endl;
////				break;
////			} // eof case 1
////			case 2: {
////				cout << endl;
////
////				cout << "\"type of get<1>(t1) = \" << typeid(get<1>(t1)).name()" << endl;
////				cout << "type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;
////				cout << "tuple_size<MyTuple>::value" << endl;
////				cout << "tuple size = " << tuple_size<MyTuple>::value << endl;
////
////				cout << endl;
////				break;
////			} // eof case 1
////			case 3: {
////				cout << endl;
////
////				double d = 3.14;
////				string str1 = "Test";
////				auto t2 = make_tuple(16, ref(d), ref(str1), cref(str1));
////				// multiply the second tuple element by 2
////				get<1>(t2) *= 2;
////				cout << "auto t2 = make_tuple(16, ref(d), ref(str1), cref(str1));" << endl;
////				cout << get<0>(t2) << ", " << get<1>(t2) << ", " << get<2>(t2).c_str() << ", " << get<3>(t2).c_str() << endl;
////
////				cout << endl;
////				break;
////			} // eof case 3
////			case 4: {
////				cout << endl;
////
////				// container in a tuple
////				tuple<string, vector<int>> t3("test", { 1, 2, 3, 4 });
////
////				// tie() utility
////				string str1 = "";
////				vector<int> vec;
////				tie(str1, vec) = t3;
////				cout << "str1: " << str1.c_str() << ", ";
////				cout << "vec: ";
////				for (auto ite : vec) {
////					cout << ite << ", ";
////				}
////				cout << endl;
////
////				// tuple_cat() utility
////				auto cT = tuple_cat(t1, t3);
////				cout << "cT = (" << get<0>(cT) << ", " << get<1>(cT).c_str() << ", " << get<2>(cT) << ", ";
////				cout << get<3>(cT).c_str() << ", ";
////				for (auto ite : get<4>(cT)) {
////					cout << ite << ", ";
////				}
////				cout << ")" << endl;
////
////				// printing tuples
////				// it seems that make_tuple() must be used, to have this working
////				auto t4 = make_tuple(167, "Testing", false, 2.3);
////				tuple_print(t4);
////
////				cout << endl;
////				break;
////			} // eof case 4
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