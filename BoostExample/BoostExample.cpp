// BoostExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// build from the Visual Studio IDE
// right-click BoostExample in the Solution Explorer pane and select Properties
// from the resulting pop-up menu
// in Configuration Properties -> C/C++ -> General -> Additional Include Directories,
// enter the path to the Boost root directory, for example
// C:/Program Files/boost/boost_1_69_0
// in Configuration Properties -> C/C++ -> Precompiled Headers, 
// change Use Precompiled Headers(/Yu) to Not Using Precompiled Headers

#include "pch.h"
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

//#include <boost/thread/shared_mutex.hpp>

int main()
{
    //std::cout << "Hello World!\n"; 
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " ");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
