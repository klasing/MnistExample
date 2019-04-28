#include "pch.h"

class Demo_9_4 {
public:
	static int get() { return 5; }
};
inline int get() { return 10; }
namespace NS {
	inline int get() { return 20; }
};

inline void paragraph_9_4() {
	cout << "Scope Resolution" << endl;
	cout << "----------------" << endl;

	Demo_9_4* pd = new Demo_9_4();
	Demo_9_4 d;
	cout << "-> " << pd->get() << endl;
	cout << "-> " << d.get() << endl;
	cout << "-> " << NS::get() << endl;
	cout << "-> " << Demo_9_4::get() << endl;
	cout << "-> " << ::get() << endl;
	// this is an error, if the namspace is unnamed
	cout << "-> " << get() << endl;
}