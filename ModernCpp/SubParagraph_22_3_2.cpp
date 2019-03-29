#include "pch.h"

#include <thread>
#include "Counter_22_3_2.hpp"

inline int main_22_3_2() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	// Using C++11 initialization syntax
	thread t1{ Counter_22_3_2(1, 20) };
	// Using named variable
	Counter_22_3_2 c(2, 12);
	thread t2(c);
	// Using tempory
	thread t3(Counter_22_3_2(3, 10));

	// wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

inline void subParagraph_22_3_2() {
	cout << "Thread with Function Object" << endl;
	cout << "---------------------------" << endl;

	main_22_3_2();
}