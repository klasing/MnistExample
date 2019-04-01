#include "pch.h"

#include <thread>
#include <mutex>
#include "Counter_22_4_4_a.hpp"
#include "Counter_22_4_4_b.hpp"


inline int main_22_4_4_a() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	// Using C++11 initialization syntax
	thread t1(Counter_22_4_4_a(1, 20));
	// Using named variable
	Counter_22_4_4_a c(2, 12);
	thread t2(c);
	// Using tempory
	thread t3(Counter_22_4_4_a(3, 10));

	// Wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

inline int main_22_4_4_b() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	// Using C++11 initialization syntax
	thread t1(Counter_22_4_4_b(1, 20));
	// Using named variable
	Counter_22_4_4_b c(2, 12);
	thread t2(c);
	// Using tempory
	thread t3(Counter_22_4_4_b(3, 10));

	// Wait for threads to finish
	// when a time delay is inserted to let fail aquiring a lock
	// and the program is not waiting for the threads to finish
	// (by commenting out the following three statements)
	// the program calls abort()
	// this needs FURTHER INVESTIGATION
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

inline int main_22_4_4_c() {
	return 0;
}

inline void subParagraph_22_4_4() {
	cout << "Mutex Usage Examples" << endl;
	cout << "--------------------" << endl;

	cout << "Thread-Safe writing to Streams" << endl;
	main_22_4_4_a();
	cout << "Using Timed Locks" << endl;
	main_22_4_4_b();
	cout << "Double Checked Locking" << endl;
	main_22_4_4_c();
}