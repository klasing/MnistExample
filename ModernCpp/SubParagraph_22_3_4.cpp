#include "pch.h"

#include <thread>
#include "Request_22_3_4.hpp"

inline int main_22_3_4() {
	// Make sure cout is thread-safe
	cout.sync_with_stdio;

	Request_22_3_4 req(100);
	thread t(&Request_22_3_4::process, &req);
	t.join();

	return 0;
}

inline void subParagraph_22_3_4() {
	cout << "Thread with Member Function" << endl;
	cout << "---------------------------" << endl;

	main_22_3_4();
}