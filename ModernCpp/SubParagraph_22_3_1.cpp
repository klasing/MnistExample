#include "pch.h"

#include <thread>

inline void counter_22_3_1(int id, int numIterations) {
	for (int i = 0; i < numIterations; ++i) {
		cout << "-> Counter " << id << " has value ";
		cout << i << endl;
	}
}

inline int main_22_3_1() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	thread t1(counter_22_3_1, 1, 6);
	thread t2(counter_22_3_1, 2, 4);
	t1.join();
	t2.join();

	return 0;
}

inline void subParagraph_22_3_1() {
	cout << "Thread with Function Pointer" << endl;
	cout << "----------------------------" << endl;

	main_22_3_1();
}