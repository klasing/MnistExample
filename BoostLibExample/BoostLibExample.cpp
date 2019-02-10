// BoostLibExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// start a MS_DOS box
// change directory to: C:\Program Files\boost\boost_1_69_0>
// run: bootstrap
// run: .\b2
// this takes forever, but eventualy the following output appears
//
//The Boost C++ Libraries were successfully built!
//
//The following directory should be added to compiler include paths :
//
//C:\Program Files\boost\boost_1_69_0
//
//	The following directory should be added to linker library paths :
//
//C:\Program Files\boost\boost_1_69_0\stage\lib
//
// in your project
// right-click BoostLibExample in the Solution Explorer pane and select Properties
// from the resulting pop-up menu
// in Configuration Properties -> Linker -> Additional Library Directories,
// enter the path to the libraries
// C:\Program Files\boost\boost_1_69_0\stage\lib

#include "pch.h"
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    //std::cout << "Hello World!\n"; 
	std::string line;
	boost::regex pat("^Subject: (Re: |Aw: )*(.*)");

	while (std::cin)
	{
		std::getline(std::cin, line);
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat))
			std::cout << matches[2] << std::endl;
	}
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
