#include "pch.h"

#include <string>

inline void getReservationData() {
	string guestName;
	int partySize;
	cout << "-> Name and number of guests: ";
	cin >> guestName >> partySize;
	cout << "-> Thank you, " << guestName << "." << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
}

inline string readName(istream& inStream) {
	string name;
	cout << "-> Enter a name (Enter+^Z=quit): ";
	while (inStream.good()) {
		int next = inStream.get();
		if (next == EOF)
			break;
		// Implicitly convert to a char and append.
		name += next;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return name;
}

inline void getReservationData_() {
	string guestName;
	int partySize;
	// Read letters until we find a non-letter
	char ch;
	cout << "-> Name and number of guests: ";
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
	cout << "-> Thank you, '" << guestName 
		<< "', party of " << partySize << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

inline void getReservationData_ex() {
	string guestName;
	int partySize = 0;
	// Read letters until we find a non-letter
	char ch;
	cout << "-> Name and number of guests: ";
	cin >> noskipws;
	while (true) {
		// 'peek' at next character
		ch = cin.peek();
		if (!cin.good())
			break;
		if (isdigit(ch))
			// next character will be a digit, so stop the loop
			break;
		// next character will be a non-digit, so read it
		cin >> ch;
		guestName += ch;
	}
	// Read partysize
	cin >> partySize;
	cout << "-> Thank you, '" << guestName
		<< "', party of " << partySize << endl;
	if (partySize > 10)
		cout << "-> An extra gratuity will apply." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

inline int handlingError() {
	cout << "Enter numbers on separate lines to add. "
		<< "Use Control+D to finish (Control+Z in Windows)." << endl;
	int sum = 0;
	if (!cin.good()) {
		cerr << "Standard input is in a bad state!" << endl;
		return 1;
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
	return 0;
}

inline void subParagraph_15_1_4() {
	cout << "Input with Streams" << endl;
	cout << "------------------" << endl;

	cout << "a) Input Basics" << endl;
	string userInput;
	cin >> userInput;
	cout << "-> User input was " << userInput << endl;
	int userInput_;
	cin >> userInput_;
	cout << "-> User input was " << userInput_ << endl;
	getReservationData();
	cout << "b) Input Methods" << endl;
	cout << "   b.1) get()" << endl;
	string str = readName(cin);
	cout << "-> " << str << endl;
	cout << "   b.2) unget()" << endl;
	getReservationData_();
	cout << "   b.3) putback()" << endl;
	cout << "   b.4) peek()" << endl;
	getReservationData_ex();
	cout << "   b.5) getline()" << endl;
	cout << "-> Enter a string ";
	string myString;
	getline(cin, myString);
	cout << "-> " << myString << endl;
	cout << "c) Handling Input Errors" << endl;
	// does not work like it should
	//handlingError();
	cout << "d) Input Manipulators" << endl;
}
