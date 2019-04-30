#include "pch.h"

#include <vector>
#include <map>

class Listener_29_8_1 {
public:
	virtual void handleMessage(int inMessage) = 0;
};

class EventRegistry_29_8_1 {
public:
	static void registerListener(int inMessage, Listener_29_8_1* inListener) {
		// Chapter 12 explains std::map. Note that if you specify a key
		// using [] to access it, and there is not yet an entry in the map for
		// that key, a new entry is created.
		sListenerMap[inMessage].push_back(inListener);
	}
	static void handleMessage(int inMessage) {
		// Check to see if the message ha *any* listeners. This check is required
		// because otherwise, accessing sListenerMap[inMessage] would create
		// a new entry when it's not yet in the map. See Chapter 12.
		if (sListenerMap.find(inMessage) == sListenerMap.end())
			return;
		for (auto iter = sListenerMap[inMessage].begin();
			iter != sListenerMap[inMessage].end(); ++iter)
			(*iter)->handleMessage(inMessage);
	}
//protected:
	static map<int, vector<Listener_29_8_1*>> sListenerMap;
};

class TestListener_29_8_1 : public Listener_29_8_1 {
public:
	TestListener_29_8_1() :
		bMessage0Received(false),
		bUnknownMessageReceived(false)
	{
		// Subscribe to event 0.
		EventRegistry_29_8_1::registerListener(0, this);
	}
	void handleMessage(int inMessage) {
		switch (inMessage) {
		case 0:
			bMessage0Received = true;
			break;
		default:
			bUnknownMessageReceived = true;
			break;
		}
	}
	bool bMessage0Received;
	bool bUnknownMessageReceived;
};

inline void subParagraph_29_8_1() {
	cout << "Example: Event Handling" << endl;
	cout << "-----------------------" << endl;

	TestListener_29_8_1 tl;
	EventRegistry_29_8_1::handleMessage(0);
	EventRegistry_29_8_1::handleMessage(1);
	EventRegistry_29_8_1::handleMessage(2);
	if (!tl.bMessage0Received)
		cout << "-> TEST FAILED: Message 0 was not received" << endl;
	else if (tl.bUnknownMessageReceived)
		cout << "-> TEST FAILED: TestListener received unknown message" << endl;
	else
		cout << "-> TEST PASSED" << endl;

}