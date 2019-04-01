#include "pch.h"

#include <thread>
#include <functional>
#include "Data_22_4_3.hpp"

inline int main_22_4_3() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	Data_22_4_3 d;
	thread t1(ref(d));
	thread t2(ref(d));
	thread t3(ref(d));
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

inline void subParagraph_22_4_3() {
	cout << "std::call_once" << endl;
	cout << "--------------" << endl;

	main_22_4_3();
}