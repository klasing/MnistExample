#pragma once

#include "pch.h"
//#pragma once
//
//#include "pch.h"
//
////****************************************************************************
////*                     prototype
////****************************************************************************
//VOID ErrorExit(LPSTR, HANDLE, DWORD);
//VOID process_key_event(KEY_EVENT_RECORD, char[], USHORT&, BOOL&);
//
////****************************************************************************
////*                     waitForUserEvent
////****************************************************************************
//// it remains a mystery why the keyword: inline has to be added
//inline VOID waitForUserEvent(HANDLE hStdin, DWORD fdwSaveOldMode,
//	char choiceBuffer[]) {
//
//	OutputDebugString(L"waitForUserEvent()\n");
//
//	const USHORT MAX_BUF = 32;
//	char* pszBuffer = new char[MAX_BUF];
//
//	const USHORT NOF_INPUT_RECORD = 1;
//	INPUT_RECORD irInBuf[NOF_INPUT_RECORD];
//	DWORD cNumRead;
//	BOOL bRead = TRUE;
//
//	USHORT iChoiceBufferIndex = 0;
//
//	while (bRead) {
//		// wait for an event
//		if (!ReadConsoleInput(hStdin, irInBuf, NOF_INPUT_RECORD, &cNumRead)) {
//			sprintf_s(pszBuffer, MAX_BUF, "%s", "ReadConsoleInput");
//			ErrorExit(pszBuffer, hStdin, fdwSaveOldMode);
//		}
//
//		switch (irInBuf[0].EventType) {
//		case KEY_EVENT:
//			// keyboard input
//			process_key_event(irInBuf[0].Event.KeyEvent, choiceBuffer, 
//				iChoiceBufferIndex, bRead);
//			break;
//		case FOCUS_EVENT:
//			// disregard focus event
//			break;
//		} // eof switch
//	}
//
//	// terminate the choice buffer with a trailing zero,
//	// to facilitate the conversion to a string
//	choiceBuffer[iChoiceBufferIndex] = '\0';
//}
//
////****************************************************************************
////*                     process_key_event
////****************************************************************************
//// it remains a mystery why the keyword: inline has to be added
//inline VOID process_key_event(KEY_EVENT_RECORD ker, char choiceBuffer[],
//	USHORT& iChoiceBufferIndex, BOOL& bRead) {
//
//	OutputDebugString(L"process_key_event()\n");
//
//	BOOL bStateShiftKey = FALSE, bStateCtrlKey = FALSE, bStateNumlockKey = FALSE;
//
//	if (ker.bKeyDown) {
//		OutputDebugString(L"key pressed\n");
//
//		if (ker.wVirtualKeyCode == 8 && ker.wVirtualScanCode == 14) {
//			OutputDebugString(L"Backspace key pressed\n");
//			if (iChoiceBufferIndex == 0)
//				return;
//			else {
//				cout << "\b \b";
//				--iChoiceBufferIndex;
//			}
//			return;
//		}
//		if (ker.wVirtualKeyCode == 13 && ker.wVirtualScanCode == 28) {
//			switch (ker.dwControlKeyState) {
//			case 0:
//				OutputDebugString(L"Enter key pressed\n");
//				break;
//			case 256:
//				OutputDebugString(L"Enter key numpad pressed\n");
//				break;
//			case 288:
//				OutputDebugString(L"Enter key numpad pressed, with numlock\n");
//				break;
//			} // eof switch
//			return;
//		}
//		if (ker.wVirtualKeyCode == 16 && ker.wVirtualScanCode == 42) {
//			OutputDebugString(L"Shift key pressed\n");
//			// shift state is true until the shift key is released
//			bStateShiftKey = TRUE;
//			return;
//		}
//		if (ker.wVirtualKeyCode == 17 && ker.wVirtualScanCode == 29) {
//			OutputDebugString(L"Ctrl key pressed\n");
//			// shift state is true until the shift key is released
//			bStateCtrlKey = TRUE;
//			return;
//		}
//		if (ker.wVirtualKeyCode == 32 && ker.wVirtualScanCode == 57) {
//			OutputDebugString(L"Space bar pressed\n");
//			return;
//		}
//		if (ker.wVirtualKeyCode == 144 && ker.wVirtualScanCode == 69) {
//			switch (ker.dwControlKeyState) {
//			case 256:
//				OutputDebugString(L"Numlock off\n");
//				bStateNumlockKey = FALSE;
//				break;
//			case 288:
//				OutputDebugString(L"Numlock on\n");
//				bStateNumlockKey = TRUE;
//				break;
//			} // eof switch
//			return;
//		}
//
//		OutputDebugString(L"ASCII char pressed\n");
//		char c;
//		if (bStateShiftKey)
//			c = toupper(ker.uChar.AsciiChar);
//		else
//			c = ker.uChar.AsciiChar;
//		// store the ASCII char into the choice buffer
//		choiceBuffer[iChoiceBufferIndex++] = c;
//		// print the ASCII char to standard output
//		fprintf(stdout, "%c", c);
//	}
//	else {
//		OutputDebugString(L"key released\n");
//
//		if (ker.wVirtualKeyCode == 13 && ker.wVirtualScanCode == 28) {
//			switch (ker.dwControlKeyState) {
//			case 0:
//				cout << endl;
//				break;
//			case 256:
//				cout << endl;
//				break;
//			} // eof switch
//
//			bRead = FALSE;
//			return;
//		}
//		if (ker.wVirtualKeyCode == 16 && ker.wVirtualScanCode == 42) {
//			// shift key is released, shift state is false
//			bStateShiftKey = FALSE;
//			return;
//		}
//		if (ker.wVirtualKeyCode == 17 && ker.wVirtualScanCode == 29) {
//			// ctrl key is released, shift state is false
//			bStateCtrlKey = FALSE;
//			return;
//		}
//	}
//
//}
