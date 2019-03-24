#include "pch.h"

namespace hello_world {
	inline int helloWorld() {
		std::cout << "-> Hello World" << std::endl;
		return 0;
	}
}

inline void subParagraph_1_1_2() {
	cout << "Namespaces" << endl;
	cout << "----------" << endl;

	hello_world::helloWorld();
}