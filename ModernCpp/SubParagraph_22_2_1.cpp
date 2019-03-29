#include "pch.h"

#include <vector>
#include <thread>
#include <functional>
#include <atomic>

inline void func_22_2_1_a(int& counter) {
	for (int i = 0; i < 10000; ++i)
		++counter;
}

inline int main_22_2_1_a() {
	int counter = 0;
	vector<thread> threads;

	for (int i = 0; i < 10; ++i)
		threads.push_back(thread(func_22_2_1_a, ref(counter)));

	for (auto& t : threads)
		t.join();

	cout << "-> Result = " << counter << endl;

	return 0;
}

inline void func_22_2_1_b(atomic<int>& counter) {
	for (int i = 0; i < 10000; ++i)
		++counter;
}

inline int main_22_2_1_b() {
	atomic<int> counter(0);
	vector<thread> threads;

	for (int i = 0; i < 10; ++i)
		threads.push_back(thread(func_22_2_1_b, ref(counter)));

	for (auto& t : threads)
		t.join();

	cout << "-> Result = " << counter << endl;

	return 0;
}

inline void subParagraph_22_2_1() {
	cout << "Atomic Type Example" << endl;
	cout << "-------------------" << endl;

	// this function does not deliver the expected behavior
	// the result is always 100.000
	// no race condition is observed, even with a numbe of
	// 1000 concurrent threads
	main_22_2_1_a();
	main_22_2_1_b();
}