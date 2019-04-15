#pragma once

#include <functional>
#include <cctype>

class myIsDigit : public unary_function<char, bool> {
public:
	bool operator() (char c) const { return ::isdigit(c); }
};

