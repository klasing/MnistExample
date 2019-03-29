#include "pch.h"

#include <thread>

inline int main_22_3_3() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio(true);

	thread t1([](int id, int numIterations) {
		for (int i = 0; i < numIterations; ++i) {
			cout << "-> Counter " << id << " has value ";
			cout << i << endl;
		}
	}, 1, 5);
	t1.join();

	return 0;
}

inline void subParagraph_22_3_3() {
	cout << "Thread with Lambda" << endl;
	cout << "------------------" << endl;

	main_22_3_3();
}