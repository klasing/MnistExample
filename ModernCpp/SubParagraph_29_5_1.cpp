#include "pch.h"

#include <string>

class Logger_29_5_1 {
public:
	static const string kLogLevelDebug;
	static const string kLogLevelInfo;
	static const string kLogLevelError;
	Logger_29_5_1() { cout << "-> Logger constructor" << endl; }
	void log(const string& level, const string& str) {
		cout << "-> " << level << ": " << str << endl;
	}
};

class NewLoggerInterface_29_5_1 {
public:
	virtual void log(const string& str) = 0;
};

class NewLoggerAdapter_29_5_1 : public NewLoggerInterface_29_5_1, private Logger_29_5_1 {
public:
	NewLoggerAdapter_29_5_1() {
		cout << "-> NewLoggerAdapter constructor" << endl;
	}
	virtual void log(const string& str) {
		Logger_29_5_1::log(Logger_29_5_1::kLogLevelInfo, str);
	}
};

inline void subParagraph_29_5_1() {
	cout << "Example: Adapting a Logger Class" << endl;
	cout << "--------------------------------" << endl;

	NewLoggerAdapter_29_5_1 logger;
	logger.log("Testing the logger.");
}