#include "pch.h"

#include "ErrorCorrelator_12_3_2.hpp"

inline void subParagraph_12_3_2() {
	cout << "priority_queue" << endl;
	cout << "--------------" << endl;

	cout << "a) priority_queue Operations" << endl;
	cout << "b) priority_queue Example: An Error Correlator" << endl;
	ErrorCorrelator_12_3_2 ec;
	ec.addError(Error_12_3_2(3, "Unable to read file"));
	ec.addError(Error_12_3_2(1, "Incorrect entry from user"));
	ec.addError(Error_12_3_2(10, "Unable to allocate memory!"));
	while (true) {
		try {
			Error_12_3_2 e = ec.getError();
			cout << "-> " << e << endl;
		}
		catch (const std::out_of_range&) {
			cout << "-> Finished processing errors" << endl;
			break;
		}
	}
}