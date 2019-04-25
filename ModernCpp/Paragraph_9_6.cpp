#include "pch.h"

//#ifndef  __LOGGER__
//#define __LOGGER__
//#include "Preferences.h"
//class Logger_9_6 {
//public:
//	static void setPreferences(const Preferences& inPrefs) {}
//	static void logError(const char* inError) {}
//};
//#endif // ! __LOGGER__

// or, by using the #pragma once directive
//#pragma once
//#include "Preferences.h"
//class Logger_9_6 {
//public:
//	static void setPreferences(const Preferences& inPrefs) {}
//	static void logError(const char* inError) {}
//};

#ifndef  __LOGGER__
#define __LOGGER__
// forward declaration
class Preferences;
class Logger_9_6 {
public:
	static void setPreferences(const Preferences& inPrefs) {}
	static void logError(const char* inError) {}
};
#endif // ! __LOGGER__

inline void paragraph_9_6() {
	cout << "Header Files" << endl;
	cout << "------------" << endl;
}