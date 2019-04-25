#include "pch.h"

#include <exception>
#include <string>

class MyException_10_3_4 : public exception, public nested_exception {
public:
	MyException_10_3_4(const char* msg) : mMsg(msg) {}
	virtual ~MyException_10_3_4() noexcept {}
	virtual const char* what() const noexcept {
		return mMsg.c_str();
	}
protected:
	string mMsg;
};

inline void doSomething_10_3_4() {
	try {
		throw runtime_error("Throwing a runtime_error exception");
	}
	catch (const runtime_error & e) {
		cout << "-> " << __func__ << " caught a runtime_error" << endl;
		cout << "-> " << __func__ << " throwing MyException" << endl;
		throw_with_nested(
			MyException_10_3_4("MyException with nested runtime_error"));
	}
}

inline void subParagraph_10_3_4() {
	cout << "Nested Exceptions" << endl;
	cout << "-----------------" << endl;

	try {
		doSomething_10_3_4();
	}
	catch (const MyException_10_3_4 & e) {
		cout << "-> " << __func__ << " caught MyException: " << e.what()
			<< endl;
		//const nested_exception* pNested =
		//	dynamic_cast<const nested_exception*>(&e);
		//if (pNested) {
		//	try {
		//		pNested->rethrow_nested();
		//	}
		//	catch (const runtime_error & e) {
		//		// Handle nested exception
		//		cout << " Nested exception: " << e.what()
		//			<< endl;
		//	}
		//}
		// no dynamic_cast needed
		try {
			rethrow_if_nested(e);
		}
		catch (const runtime_error & e) {
			// Handle nested exception
			cout << " Nested exception: " << e.what()
				<< endl;
		}
	}
}
