#pragma once

#include <functional>

class SumAndProd : public std::unary_function<int, void> {
public:
	SumAndProd() : sum(0), prod(1) {}
	void operator() (int elem) {
		sum += elem;
		prod *= elem;
	}
	// make sum and prod public for easy access
	int sum;
	int prod;
};