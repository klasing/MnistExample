#include <iostream>

using namespace std;

class Handler_4_1 {
protected:
	Handler_4_1* next;
public:
	Handler_4_1() { next = NULL; }
	virtual ~Handler_4_1() {}
	void setNextHandler(Handler_4_1* nextInLine) {
		next = nextInLine;
	}
	virtual void request(int value) = 0;
};

class SpecialHandler_4_1 : public Handler_4_1 {
private:
	int myLimit;
	int myId;
public:
	SpecialHandler_4_1(int limit, int id) {
		myLimit = limit;
		myId = id;
	}
	~SpecialHandler_4_1() {}
	void request(int value) {
		if (value < myLimit)
			cout << "-> Handler " << myId << " handled the request with a limit of " << myLimit << endl;
		else
			if (next != NULL)
				next->request(value);
			else
				cout << "-> Sorry, I am the last handler (" << myId
					<< ") and I can't handle the request." << endl;
	}
};
inline void chapter_4_1() {
	cout << "Chain of Responsibility" << endl;
	cout << "-----------------------" << endl;

	Handler_4_1* h1 = new SpecialHandler_4_1(10, 1);
	Handler_4_1* h2 = new SpecialHandler_4_1(20, 2);
	Handler_4_1* h3 = new SpecialHandler_4_1(30, 3);

	h1->setNextHandler(h2);
	h2->setNextHandler(h3);

	h1->request(18);
	h1->request(40);

	delete(h1);
	delete(h2);
	delete(h3);
}