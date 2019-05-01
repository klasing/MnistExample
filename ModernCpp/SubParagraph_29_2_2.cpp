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
	// Returns a reference to the singleton Logger object
	static Logger_29_2_2_a& instance() { return sInstance; }
	// Logs a single message at the given log level
	void log(const string& inMessage,
		const string& inLogLevel) {
		mOutputStream << inLogLevel << ": " << inMessage << endl;
	}
	// Logs a vector of messages at the given log level
	void log(const vector<string>& inMessages,
		const string& inLogLevel) {
		for (size_t i = 0; i < inMessages.size(); i++)
			log(inMessages[i], inLogLevel);
	}
protected:
	// Static variable for the one-and-only instance
	static Logger_29_2_2_a sInstance;
	// Constant for the filename
	static const char* const kLogFileName;
	// Data member for the output stream
	ofstream mOutputStream;
private:
	Logger_29_2_2_a() {
		mOutputStream.open(kLogFileName, ios_base::app);
		if (!mOutputStream.good())
			throw runtime_error("Unable to initialize the Logger!");
	}
	virtual ~Logger_29_2_2_a() { mOutputStream.close(); }
};

inline void subParagraph_29_2_2() {
	cout << "Implementation of a Singleton" << endl;
	cout << "-----------------------------" << endl;

	cout << "a) Static Class Singleton" << endl;
	// OUTPUT GOES INTO FILE
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
	// OUTPUT GOES INTO FILE
	// logger usage given in the book, slightly modified
	Logger_29_2_2_a& logger_instance = Logger_29_2_2_a::instance();
	logger_instance.log("test message", Logger_29_2_2_a::kLogLevelDebug);
	vector<string> items = { "item1", "item2" };
	logger_instance.log(items, Logger_29_2_2_a::kLogLevelError);
}