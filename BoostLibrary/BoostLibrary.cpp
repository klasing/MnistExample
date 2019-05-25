// BoostLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1) Configuration Properties C / C++ General
//    Additional Include Directories : C:\Program Files\boost\boost_1_70_0
//    Precompiled Header : Not Using Precompiled Headers
// 2) Configuration Properties Linker General
//    Additional Include Directories : C:\Program Files\boost\boost_1_70_0\stage\lib

#include <iostream>
#include <string>

#include "example_1_1.cpp"
#include "example_1_2.cpp"
#include "example_1_3.cpp"
#include "example_1_4.cpp"
#include "example_1_5.cpp"
#include "example_1_6.cpp"
#include "example_1_7.cpp"
#include "example_1_8.cpp"
#include "example_1_9.cpp"
#include "example_2_1.cpp"
#include "example_2_2.cpp"
#include "example_2_3.cpp"
#include "exercise_2_1_starter.cpp"
#include "exercise_2_1.cpp"
#include "example_3_1.cpp"
#include "example_3_2.cpp"
#include "example_3_3.cpp"
#include "exercise_3_1.cpp"

// used in exercise_2_1_starter.cpp
const string ns_exercise_2_1_starter::muuuh = "Muuuh!";
const string ns_exercise_2_1_starter::oiink = "Oiiink";

int main()
{
    std::cout << "Hello World!\n";

	ns_example_1_1::example_1_1();
	ns_example_1_2::example_1_2();
	ns_example_1_3::example_1_3();
	ns_example_1_4::example_1_4();
	ns_example_1_5::example_1_5();
	ns_example_1_6::example_1_6();
	ns_example_1_7::example_1_7();
	ns_example_1_8::example_1_8();
	ns_example_1_9::example_1_9(); // has issues
	ns_example_2_1::example_2_1();
	ns_example_2_2::example_2_2();
	ns_example_2_3::example_2_3();
	ns_exercise_2_1_starter::exercise_2_1_starter();
	ns_exercise_2_1::exercise_2_1();
	ns_example_3_1::example_3_1();
	ns_example_3_2::example_3_2();
	ns_example_3_3::example_3_3();
	ns_exercise_3_1::exercise_3_1();
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
