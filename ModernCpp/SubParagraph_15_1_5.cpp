#include "pch.h"

#include "Muffin.hpp"

inline void subParagraph_15_1_5() {
	cout << "Input and Output with Objects" << endl;
	cout << "-----------------------------" << endl;
	// a poor example for outputting objects
	Muffin myMuffin;
	myMuffin.setDescription("regular muffin");
	myMuffin.setSize(3);
	myMuffin.setHasChocolateChips(true);
	printf("-> The muffin is ");
	myMuffin.output();
	printf(" -- yummy!\n");
}