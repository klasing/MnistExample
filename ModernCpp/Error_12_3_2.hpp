#pragma once

#include <string>

// Sample Error class with just a priority and a string error description.
class Error_12_3_2 {
public:
	Error_12_3_2(int priority, const std::string& errMsg)
		: mPriority(priority), mError(errMsg) {}
	int getPriority() const { return mPriority; }
	std::string getErrorString() const { return mError; }
	friend bool operator<(const Error_12_3_2& lhs, const Error_12_3_2& rhs) {
		return (lhs.mPriority < rhs.mPriority);
	}
	// See Chapter 18 for details on implementing operator<<
	friend std::ostream& operator<<(std::ostream& os,
		const Error_12_3_2& err) {
		os << err.mError << " (priority " << err.mPriority << ")";
		return os;
	}
protected:
	int mPriority;
	std::string mError;
};
