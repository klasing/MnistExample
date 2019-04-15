#include "pch.h"

#include <queue>

inline void subParagraph_13_3_2() {
	cout << "Comparison Function Objects" << endl;
	cout << "---------------------------" << endl;

	priority_queue<int> myQueue;
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(2);
	myQueue.push(1);
	cout << "-> ";
	while (!myQueue.empty()) {
		cout << myQueue.top() << " ";
		myQueue.pop();
	}
	cout << endl;

	priority_queue<int, vector<int>, greater<int>> myQueue_;
	myQueue_.push(3);
	myQueue_.push(4);
	myQueue_.push(2);
	myQueue_.push(1);
	cout << "-> ";
	while (!myQueue_.empty()) {
		cout << myQueue_.top() << " ";
		myQueue_.pop();
	}
	cout << endl;
}