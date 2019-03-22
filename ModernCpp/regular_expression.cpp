#pragma once

#include "pch.h"
//#pragma once
//
//#include "pch.h"
//
//#include "waitForUserEvent.cpp"
//#include "getNumber.cpp"
//
////****************************************************************************
////*                     regular_expression
////****************************************************************************
//// it remains a mystery why the keyword: inline has to be added
//inline VOID regular_expression(HANDLE hStdin, DWORD fdwSaveOldMode) {
//
//	OutputDebugString(L"regular_expression()\n");
//
//	const USHORT MAX_CHOICEBUF = 32;
//	char choiceBuffer[MAX_CHOICEBUF];
//
//	BOOL bProceed = TRUE, bValid = FALSE;
//	USHORT iChoiceMenu = 0;
//
//	// show the menu until the user leaves
//	while (bProceed) {
//		cout << "    Regular expression" << endl;
//		cout << "    ==================" << endl;
//		cout << " 1) Special character" << endl;
//		cout << " 2) Regex library" << endl;
//		cout << "Enter the number of a subject, or enter a zero to return to the main menu: ";
//
//		waitForUserEvent(hStdin, fdwSaveOldMode, choiceBuffer);
//		bValid = getNumber(choiceBuffer, iChoiceMenu);
//
//		if (bValid)
//			// the user has entered a valid number for the menu
//			switch (iChoiceMenu) {
//			case 1:
//				cout << endl;
//
//				cout << "^ $ \\ , * + ? ( ) [ ] { }" << endl;
//				cout << "Anchor: ^ $" << endl;
//				cout << "Wildcard: ." << endl;
//				cout << "Repetition" << endl;
//				cout << " * zero or more times" << endl;
//				cout << " + one or more times" << endl;
//				cout << " ? zero or one time" << endl;
//				cout << " {...} bounded repeat" << endl;
//				cout << " a ? behind the repetition makes it non-greedy" << endl;
//				cout << "Alternation: | (an \"or\" relationship)" << endl;
//				cout << "Grouping: ( )" << endl;
//				cout << " can be used for: back references and replace operations" << endl;
//				cout << "Precedence:" << endl;
//				cout << " Elements: like a are the basic building blocks of a regular expression" << endl;
//				cout << " Quantifiers: like +, *, ? and {...} bind tightly to the element on the left" << endl;
//				cout << " Concatenation: like ab+c binds after quantifiers" << endl;
//				cout << " Alternations: like | binds at last" << endl;
//				cout << " Parenthesis can be used to change the precedence. But they also create" << endl;
//				cout << " sub-expression or capture group." << endl;
//				cout << " By using (?:...), no additional capture group is created." << endl;
//				cout << "Character set matches" << endl;
//				cout << " [abc] matches a or b or c" << endl;
//				cout << " [a-z] range specification, matches all lowercase letters from a to z" << endl;
//				cout << "Character classes: [:name:] where name is one of the following classes" << endl;
//				cout << " alnum  lowercase letters, uppercase letters, and digits" << endl;
//				cout << " alpha  lowercase letters, and uppercase letters" << endl;
//				cout << " blank  space or tab characters" << endl;
//				cout << " cntrl  file format escape characters like new lines form feeds, and so on" << endl;
//				cout << "        (\\f, \\n, \\r, \\t and \\v)" << endl;
//				cout << " digit  digits" << endl;
//				cout << " graph  lowercase letters, uppercase letters, digits, and punctuation characters" << endl;
//				cout << " lower  lowercase letters" << endl;
//				cout << " print  lowercase letters, uppercase letters, digits, punctuation characters," << endl;
//				cout << "        and space characters" << endl;
//				cout << " punct  punctuation characters" << endl;
//				cout << " space  space characters" << endl;
//				cout << " upper  uppercase letters" << endl;
//				cout << " xdigit digits and a-f and A-F" << endl;
//				cout << " d      same as digit" << endl;
//				cout << " s      same as space" << endl;
//				cout << " w      same as alnum" << endl;
//				cout << "Character classes are used within character sets," << endl;
//				cout << "for example [[:alpha:]]* means [a-zA-Z]*" << endl;
//				cout << "Escape notation:" << endl;
//				cout << " \d     [[:d:]]" << endl;
//				cout << " \D     [^[:d:]]" << endl;
//				cout << " \s     [[:s:]]" << endl;
//				cout << " \S     [^[:s:]]" << endl;
//				cout << " \w     [[:w:]]" << endl;
//				cout << " \W     [^[:w:]]" << endl;
//				cout << "Word boundary:" << endl;
//				cout << " \b matches a word boundary" << endl;
//				cout << " \B matches anything except a word boundary" << endl;
//				cout << "Back references" << endl;
//				cout << "TODO" << endl;
//
//				cout << endl;
//				break;
//			case 2:
//				//TODO
//				break;
//			case 0:
//				// the user wants to leave the subject
//				bProceed = FALSE;
//				break;
//			default:
//				// the input, given by the user, is not an available option
//				cout << "The entered number is not recognized, please try again." << endl;
//			} // eof switch
//	}
//}
