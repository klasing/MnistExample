#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "data.h"
//#include "counter_noninterleaved.h"
//#include "counter_timedlock.h"
//
////****************************************************************************
////*                     mutualExclusion
////****************************************************************************
//// function must be inline
//inline void mutualExclusion() {
//	OutputDebugString(L"mutualExclusion()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Mutual exclusion" << endl;
//		cout << "================" << endl;
//		cout << " 1) Mutex classes" << endl;
//		cout << " 2) Locks" << endl;
//		cout << " 3) std::call_once" << endl;
//		cout << " 4) Mutex usage examples" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Mutex classes" << endl;
//			cout << "=============" << endl;
//
//			cout << "Non-timed mutex classes" << endl;
//			cout << "a) std::mutex" << endl;
//			cout << "b) std::recursive_mutex" << endl;
//			cout << "   methods: lock(), try_lock(), unlock()" << endl;
//			cout << "Timed mutex classes" << endl;
//			cout << "a) std::timed_mutex" << endl;
//			cout << "b) std::recursive_timed_mutex" << endl;
//			cout << "   methods: lock(), try_lock(), unlock()," << endl;
//			cout << "   try_lock_for(rel_time)" << endl;
//			cout << "   try_lock_until(abs_time)" << endl;
//
//			break;
//		case 2: {
//			cout << "Locks" << endl;
//			cout << "=====" << endl;
//
//			cout << "a) std::lock_guard" << endl;
//			cout << "b) std::unique_lock" << endl;
//			cout << "   constructors:" << endl;
//			cout << "   explicit unique_lock(mutex_type& m);" << endl;
//			cout << "   unique_lock(mutex_type& m, defer_lock_t) noexcept;" << endl;
//			cout << "   unique_lock(mutex_type& m, defer_lock_t);" << endl;
//			cout << "   unique_lock(mutex_type& m, adopt_lock_t);" << endl;
//			cout << "   template<class clock, class Duration>" << endl;
//			cout << "   unique_lock(mutext_type& m, const chrono::time_point<Clock, Duration>& abs_time);" << endl;
//			cout << "   template<class Clock, class Duration>" << endl;
//			cout << "   unique_lock(mutext_type& m, const chrono::time_point<Clock, Duration>& abs_time);" << endl;
//			cout << "   template<class Rep, class Period>" << endl;
//			cout << "   unique_lock(mutext_type& m, const chrono::duration<Rep, Period>& rel_time);" << endl;
//			cout << "   methods: lock(), try_lock(), try_lock_for()" << endl;
//			cout << "   try_lock_until()" << endl;
//			cout << "   owns_lock()" << endl;
//			cout << "Variadic template functions for locking" << endl;
//			cout << "template<class L1, class L2, class... L3>" << endl;
//			cout << "void lock(L1&, L2&, L3&...);" << endl;
//			cout << "template<class L1, class L2, class... L3>" << endl;
//			cout << "void try_lock(L1&, L2&, L3&...);" << endl;
//
//			break;
//		} // eof case 2
//		case 3: {
//			cout << "std::call_once" << endl;
//			cout << "==============" << endl;
//
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			Data d;
//			thread t1{ ref(d) };
//			thread t2{ ref(d) };
//			thread t3{ ref(d) };
//			t1.join();
//			t2.join();
//			t3.join();
//
//			break;
//		} // eof case 3
//		case 4: {
//			cout << "Mutex usage examples" << endl;
//			cout << "====================" << endl;
//
//			// make sure cout is thread-safe
//			cout.sync_with_stdio(true);
//
//			cout << "Thread-safe writing to streams" << endl;
//			// using a global variable declared in ModernCpp.cpp
//			thread t1{ CounterNonInterleaved(1, 20) };
//			thread t2{ CounterNonInterleaved(2, 24) };
//			t1.join();
//			t2.join();
//
//			cout << "Using timed locks" << endl;
//			// using a global variable declared in ModernCpp.cpp
//			thread t3{ CounterTimedLock(1, 20) };
//			thread t4{ CounterTimedLock(2, 24) };
//			t3.join();
//			t4.join();
//
//			cout << "Using double checked locking" << endl;
//			cout << "TODO problem with global declarations" << endl;
//
//			break;
//		} // eof case 4
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