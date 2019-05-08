// Programmingpatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

#include <iostream>

#include "part1.cpp"
#include "part2.cpp"
#include "part3.cpp"
#include "part4.cpp"

using namespace std;

// global
// used in chapter_2_5.cpp
Mutex_2_5 Singleton_2_5::mutex;
// used in chapter_3_6.cpp
vector<float> FlyweightCharacterStore_3_6::fontSizes(3);
vector<string> FlyweightCharacterStore_3_6::fontNames(3);
// used in chapter_4_6.cpp
const string NAME = "Object";
vector<Command*> Command::commandList;
vector<Memento*> Command::mementoList;
int Command::numCommands = 0;
int Command::maxCommands = 0;
// used in chapter_4_8.cpp
using namespace ns_chapter_4_8;
shared_ptr<StandingState> FighterState::standing(new StandingState);
shared_ptr<DivingState> FighterState::diving(new DivingState);

int main() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C++ Programming: Code patterns design" << endl;
		cout << "=====================================" << endl;
		cout << " 1) Programming Patterns" << endl;
		cout << " 2) Creational Patterns" << endl;
		cout << " 3) Structural Patterns" << endl;
		cout << " 4) Behavioral Patterns" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			part1();
			break;
		case 2:
			part2();
			break;
		case 3:
			part3();
			break;
		case 4:
			part4();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
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
