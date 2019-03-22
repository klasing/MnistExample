#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "counter.h"
//#include "request.h"
//
////****************************************************************************
////*                     counter
////****************************************************************************
//inline void counter(int id, int numIterations) {
//	OutputDebugString(L"counter()\n");
//
//	for (int i = 0; i < numIterations; ++i) {
//		cout << "Counter " << id << " has value ";
//		cout << i << endl;
//	}
//}
//
////****************************************************************************
////*                     doSomeWork
////****************************************************************************
//#pragma warning( disable : 4290 )
//inline void doSomeWork() throw(runtime_error) {
//	OutputDebugString(L"doSomeWork()\n");
//
//	for (int i = 0; i < 5; ++i)
//		cout << i << endl;
//
//	cout << "Thread throwing a runtime_error exception..." << endl;
//	throw runtime_error("Exception from thread");
//}
//
////****************************************************************************
////*                     threadFunc
////****************************************************************************
//inline void threadFunc(exception_ptr& err) {
//	OutputDebugString(L"threadFunc()\n");
//
//	try {
//		doSomeWork();
//	}
//	catch (...) {
//		cout << "Thread caught exception, returning exception..." << endl;
//		err = current_exception();
//	}
//
//}
//
////****************************************************************************
////*                     doWorkInThread
////****************************************************************************
//#pragma warning( disable : 4290 )
//inline void doWorkInThread() throw(runtime_error) {
//	OutputDebugString(L"doWorkInThread()\n");
//
//	exception_ptr error;
//	// launch background thread
//	thread t{ threadFunc, ref(error) };
//	// wait for the thread to finish
//	t.join();
//	// see if the thread has thrown any exception
//	if (error) {
//		cout << "Main thread received exception, rethrowing it..." << endl;
//		rethrow_exception(error);
//	} else
//		cout << "Main thread did not receive any exception." << endl;
//}
//
////****************************************************************************
////*                     threads
////****************************************************************************
//// function must be inline
//inline void threads() {
//	OutputDebugString(L"threads()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Threads" << endl;
//		cout << "=======" << endl;
//		cout << " 1) Thread with function pointer" << endl;
//		cout << " 2) Thread with function object" << endl;
//		cout << " 3) Thread with lambda" << endl;
//		cout << " 4) Thread with member function" << endl;
//		cout << " 5) Thread with member function" << endl;
//		cout << " 6) Cancelling threads" << endl;
//		cout << " 7) Retrieving results from threads" << endl;
//		cout << " 8) Copying and rethrowing exceptions" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1: {
//			cout << "Thread with function pointer" << endl;
//			cout << "============================" << endl;
//
//			cout << "UI will be blocked for the duration of the running threads" << endl;
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			thread t1(counter, 1, 6);
//			thread t2(counter, 2, 4);
//			// this will block the UI
//			t1.join();
//			t2.join();
//
//			break;
//		} // eof case 1
//		case 2: {
//			cout << "Thread with function object" << endl;
//			cout << "===========================" << endl;
//
//			cout << "UI will be blocked for the duration of the running threads" << endl;
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			// Using C++11 initialization syntax
//			thread t1{ Counter(1, 20) };
//
//			// Using named variable
//			Counter c(2, 12);
//			thread t2(c);
//
//			// Using tempory, this will only work because the constructor 
//			// of the Counter object has parameters
//			thread t3(Counter(3, 10));
//
//			// Wait for threads to finish
//			t1.join();
//			t2.join();
//			t3.join();
//
//			break;
//		} // eof case 2
//		case 3: {
//			cout << "Thread with lambda" << endl;
//			cout << "==================" << endl;
//
//			cout << "UI will be blocked for the duration of the running threads" << endl;
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			thread t1([](int id, int numIterations) {
//				for (int i = 0; i < numIterations; ++i) {
//					cout << "Counter " << id << " has value ";
//					cout << i << endl;
//				}
//			}, 1, 5);
//			t1.join();
//
//			break;
//		} // eof case 3
//		case 4: {
//			cout << "Thread with member function" << endl;
//			cout << "===========================" << endl;
//
//			cout << "UI will be blocked for the duration of the running threads" << endl;
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			Request req(100);
//			thread t{ &Request::process, &req };
//
//			t.join();
//
//			break;
//		} // eof case 4
//		case 5: {
//			cout << "Thread local storage" << endl;
//			cout << "====================" << endl;
//
//			cout << "Each thread will have its own unique copy of n." << endl;
//			cout << "thread_local int n;" << endl;
//
//			break;
//		} // eof case 5
//		case 6: {
//			cout << "Cancelling threads" << endl;
//			cout << "==================" << endl;
//
//			cout << "Use condition variables for cancelling threads." << endl;
//
//			break;
//		} // eof case 6
//		case 7: {
//			cout << "Retrieving results from threads" << endl;
//			cout << "===============================" << endl;
//
//			cout << "Use futures for retrieving results from threads." << endl;
//
//			break;
//		} // eof case 7
//		case 8: {
//			cout << "Copying and rethrowing exceptions" << endl;
//			cout << "=================================" << endl;
//
//			cout << "Handle exceptions across threads" << endl;
//			cout << "exception_ptr current_exception() noexcept;" << endl;
//			cout << endl;
//			cout << "Rethrow the exception, referenced by exception_ptr" << endl;
//			cout << "[[noreturn]] void rethrow_exception(exception_ptr p);" << endl;
//			cout << endl;
//			cout << "Create an exception_ptr object that refers to a copy of the given object" << endl;
//			cout << "template<class E> exception_ptr make_exception_ptr(E e) noexcept;" << endl;
//			cout << "This is basically a shorthand for:" << endl;
//			cout << "try {" << endl;
//			cout << "	throw e;" << endl;
//			cout << "} catch(...) {" << endl;
//			cout << "	return current_exception();" << endl;
//			cout << "}" << endl;
//
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//			try {
//				doWorkInThread();
//			}
//			catch (const exception& e) {
//				cout << "Main function caught: " << e.what() << endl;
//			}
//
//			break;
//		} // eof case 8
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}