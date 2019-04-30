#include "pch.h"

#include <vector>
#include <string>
#include <fstream>

// Definition of a singleton logger class, implemented with static methods.
class Logger_29_2_2 {
public:
	static const string kLogLevelDebug;
	static const string kLogLevelInfo;
	static const string kLogLevelError;
	// Logs a single message at the given log level
	static void log(const string& inMessage,
		const string& inLogLevel) {
		if (!sInitialized)
			init();
		// Print the message and flush the stream with endl.
		sOutputStream << inLogLevel << ": " << inMessage << endl;
	}
	// Logs a vector of messages at the given log level
	static void log(const vector<string>& inMessages,
		const string& inLogLevel) {
		for (size_t i = 0; i < inMessages.size(); i++)
			log(inMessages[i], inLogLevel);
	}
	// Closes the log file
	static void teardown() {
		if (sInitialized) {
			sOutputStream.close();
			sInitialized = false;
		}
	}
protected:
	static void init() {
		if (!sInitialized) {
			sOutputStream.open(kLogFileName, ios_base::app);
			if (!sOutputStream.good())
				throw runtime_error("Unable to initialize the Logger!");
			sInitialized = true;
		}
	}
	static const char* const kLogFileName;
	static bool sInitialized;
	static ofstream sOutputStream;
private:
	Logger_29_2_2() {}
};

// Definition of a true singleton logger class
class Logger_29_2_2_a {
public:
	static const string kLogLevelDebug;
	static const string kLogLevelInfo;
	static const string kLogLevelError;
};

inline void subParagraph_29_2_2() {
	cout << "Implementation of a Singleton" << endl;
	cout << "-----------------------------" << endl;

	cout << "a) Static Class Singleton" << endl;
	// stating my own log messages
	Logger_29_2_2::log("Initializing Logger", Logger_29_2_2::kLogLevelInfo);
	Logger_29_2_2::log("Ready for logging", Logger_29_2_2::kLogLevelDebug);
	vector<string> messages;
	messages.push_back("First info");
	messages.push_back("Second info");
	messages.push_back("Third info");
	Logger_29_2_2::log(messages, Logger_29_2_2::kLogLevelInfo);
	Logger_29_2_2::log("Logger shutting down", Logger_29_2_2::kLogLevelDebug);
	Logger_29_2_2::teardown();
	cout << "b) Access-Controlled Singleton" << endl;
}