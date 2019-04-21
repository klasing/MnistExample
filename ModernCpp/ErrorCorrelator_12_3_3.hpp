#pragma once

#include <stack>
#include "Error_12_3_2.hpp"

// Simple ErrorCorrelator class that returns highest priority errors first.
class ErrorCorrelator_12_3_3 {
public:
	ErrorCorrelator_12_3_3() {}
	// Add an error to be correlated.
	void addError(const Error_12_3_2& error) {
		mErrors.push(error);
	}
	// Retrieve the next error to be processed.
	Error_12_3_2 getError() throw(std::out_of_range) {
		// If there are no more errors, throw an exception.
		if (mErrors.empty())
			throw std::out_of_range("No elements!");
		// Save the top element
		Error_12_3_2 top = mErrors.top();
		// Remove the top element.
		mErrors.pop();
		// Return the saved element.
		return top;
	}
protected:
	std::stack<Error_12_3_2> mErrors;
};