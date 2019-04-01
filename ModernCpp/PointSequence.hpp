#pragma once

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <vector>

class PointSequence {
public:
	PointSequence(std::initializer_list<double> args) {
		if (args.size() % 2 != 0)
			throw std::invalid_argument("initializer_list should "
				"contain even number of elements.");
		for (auto iter = args.begin(); iter != args.end(); ++iter)
			mVecPoints.push_back(*iter);
	}
	void dumpPoints() const {
		for (auto citer = mVecPoints.cbegin();
			citer != mVecPoints.cend(); citer += 2)

			std::cout << "-> (" << *citer << ", " << *(citer + 1) << ")" 
				<< std::endl;
	}
protected:
	std::vector<double> mVecPoints;
};