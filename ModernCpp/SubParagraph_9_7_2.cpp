#include "pch.h"

// No semicolon after the macro definition!
#define SQUARE(x) ((x) * (x))

inline void subParagraph_9_7_2() {
	cout << "Preprocessor Macros" << endl;
	cout << "-------------------" << endl;

	cout << "-> " << SQUARE(5) << endl;
}