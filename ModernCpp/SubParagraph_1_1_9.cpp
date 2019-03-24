#include "pch.h"

inline void aFunction() {
	cout << "-> " << __func__ << "()" << endl;
}

inline void subParagraph_1_1_9() {
	cout << "Functions" << endl;
	cout << "---------" << endl;

	aFunction();
}