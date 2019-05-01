#include "pch.h"

#include <fstream>
#include <vector>
#include <string>
#include <mutex>
//#include <thread>
//#include <chrono>

// Definition of a multithreaded safe singleton logger class
class Logger_29_2_4 {
public:
	static const string kLogLevelDebug;
	static const string kLogLevelInfo;
	static const string kLogLevelError;
	// Returns a reference to the singleton Logger object
	static Logger_29_2_4& instance() {
		static Cleanup cleanup;
		lock_guard<mutex> guard(sMutex);
		if (pInstance == nullptr)
			pInstance = new Logger_29_2_4();
		return *pInstance;
	}
	// Logs a single message at the given log level
	void log(const string& inMessage,
		const string& inLogLevel) {
		lock_guard<mutex> guard(sMutex);
		logHelper(inMessage, inLogLevel);
	}
	// Logs a vector of messages at the given log level
	void log(const vector<string>& inMessages,
		const string& inLogLevel) {
		lock_guard<mutex> guard(sMutex);
		for (size_t i = 0; i < inMessages.size(); i++)
			logHelper(inMessages[i], inLogLevel);
	}
protected:
	// Static variable for the one-and-only instance
	static Logger_29_2_4* pInstance;
	// Constant for the filename
	static const char* const kLogFileName;
	// Data member for the output stream
	ofstream mOutputStream;
	// Embedded class to make sure the single Logger
	// instance gets deleted on program shutdown.
	friend class Cleanup;
	class Cleanup {
	public:
		~Cleanup() {
			lock_guard<mutex> guard(Logger_29_2_4::sMutex);
			delete Logger_29_2_4::pInstance;
			Logger_29_2_4::pInstance = nullptr;
		}
	};
	// Logs message. The thread should own a lock on sMutex
	// before calling this function.
	void logHelper(const string& inMessage,
		const string& inLogLevel) {
		mOutputStream << inLogLevel << ": " << inMessage << endl;
	}
private:
	Logger_29_2_4() {
		mOutputStream.open(kLogFileName, ios_base::app);
		if (!mOutputStream.good())
			throw runtime_error("Unable to intialize the Logger!");
	}
	virtual ~Logger_29_2_4() {
		mOutputStream.close();
	}
	Logger_29_2_4(const Logger_29_2_4&) {}
	Logger_29_2_4& operator=(const Logger_29_2_4&) {}
	static mutex sMutex;
};

inline void subParagraph_29_2_4() {
	cout << "Singletons and Multithreading" << endl;
	cout << "-----------------------------" << endl;

	// messages from main thread
	Logger_29_2_4& logger_instance = Logger_29_2_4::instance();
	logger_instance.log("THREAD main: test message", Logger_29_2_4::kLogLevelDebug);
	vector<string> items = { "THREAD main: item1", "THREAD main: item2" };
	logger_instance.log(items, Logger_29_2_4::kLogLevelError);
	// messages from background thread
	// background thread constructed with lambda
	thread t1([]() {
		Logger_29_2_4& logger_instance = Logger_29_2_4::instance();
		logger_instance.log("THREAD t1: test message", Logger_29_2_4::kLogLevelDebug);
		vector<string> items = { "THREAD t1: item1", "THREAD t1: item2" };
		logger_instance.log(items, Logger_29_2_4::kLogLevelError);
		//const std::chrono::milliseconds duration(25);
		//std::this_thread::sleep_for(duration);
	});
	// messages from another background thread
	// background thread constructed with lambda
	thread t2([]() {
		Logger_29_2_4& logger_instance = Logger_29_2_4::instance();
		logger_instance.log("THREAD t2: test message", Logger_29_2_4::kLogLevelDebug);
		vector<string> items = { "THREAD t2: item1", "THREAD t2: item2" };
		logger_instance.log(items, Logger_29_2_4::kLogLevelError);

	});
	t1.join();
	t2.join();
}