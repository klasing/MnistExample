#include "pch.h"

#include <string>

inline void example_15_1_4_a() {
	string userInput;
	cin >> userInput;
	cout << "-> User input was " << userInput.c_str() << endl;
}

inline void example_15_1_4_b() {
	int userInput;
	cin >> userInput;
	cout << "-> User input was " << userInput << endl;
}

inline void getReservationData() {
	string guestName;
	int partySize;

	cout << "-> Name and number of guests: ";
	cin >> guestName >> partySize;

	cout << "-> Thank you, " << guestName << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
}

//inline string readName(istream& inStream) {
//	string name;
//
//	while (inStream.good()) {
//		int next = inStream.get();
//		if (next == EOF)
//			break;
//		// implicitly convert to a char and append
//		name += next;
//	}
//	return name;
//}

//inline string readName(istream& inStream) {
//	string name;
//	char next;
//
//	while (inStream.get(next)) {
//		name += next;
//	}
//	return name;
//}
inline void getReservationData_1() {
	string guestName;
	int partySize;

	// Read letters until we find a non-letter
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "-> unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	// Read partysize
	cin >> partySize;
	cout << "-> Thank you " << guestName
		<< " party of " << partySize << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
}

inline void getReservationData_2() {
	string guestName;
	int partySize = 0;

	// Read letters until we find a non-letter
	char ch;
	cin >> noskipws;
	while (true) {
		// 'peek' at next character
		ch = cin.peek();
		if (!cin.good())
			break;
		if (isdigit(ch))
			// nest character will be a digit, so stop the loop
			break;
		// next character will ge a non-digit, so read it
		cin >> ch;
		guestName += ch;
	}
	// Read partysize
	cin >> partySize;
	cout << "-> Thank you " << guestName
		<< " party of " << partySize << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
}

inline void handlingError() {
	cout << "Enter numbers on separate lines to add. "
		<< "Use Control+D to finish (Control+Z in Windows)." << endl;
	int sum = 0;
	if (!cin.good()) {
		cerr << "Standard input is in a bad state!" << endl;
	}
	int number;
	while (true) {
		cin >> number;
		if (cin.good())
			sum += number;
		else if (cin.eof())
			// Reached end of file
			break;
		else {
			// Error!
			// Clear the error state.
			cin.clear();
			string badToken;
			// Consume the bad input
			cin >> badToken;
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}
	cout << "The sum is " << sum << endl;
}

inline void subParagraph_15_1_4() {
	cout << "Input with Streams" << endl;
	cout << "------------------" << endl;

	cout << "Input Basics" << endl;
	example_15_1_4_a();
	example_15_1_4_b();
	getReservationData();
	cout << "Input Methods" << endl;
	//string name = readName(cin);
	//cout << "-> Name is: " << name << endl;
	getReservationData_1();
	getReservationData_2();
	cout << "Handling Input Errors" << endl;
	handlingError();
	cout << "Input Manipulators" << endl;
}