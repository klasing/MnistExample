#include "pch.h"

#include "Paragraph_1_1.cpp"
#include "Paragraph_1_2.cpp"
#include "Paragraph_1_3.cpp"
#include "Paragraph_1_4.cpp"
#include "Paragraph_1_5.cpp"
#include "Paragraph_1_6.cpp"

inline void chapter1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 1, A Crash Course in C++" << endl;
		cout << "================================" << endl;
		cout << " 1) The Basics of C++" << endl;
		cout << " 2) Diving Deeper into C++" << endl;
		cout << " 3) C++ as an Object-Oriented Language" << endl;
		cout << " 4) The Standard Library" << endl;
		cout << " 5) Your First Useful C++ Program" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_1_1();
			break;
		case 2:
			paragraph_1_2();
			break;
		case 3:
			paragraph_1_3();
			break;
		case 4:
			paragraph_1_4();
			break;
		case 5:
			paragraph_1_5();
			break;
		case 6:
			paragraph_1_6();
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
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "BasicsOfCpp.cpp"
//#include "DivingDeeperIntoCpp.cpp"
//
//#include "employee.h"
//#include "database.h"
//
////****************************************************************************
////*                     testEmployeeClass
////****************************************************************************
//inline void testEmployeeClass() {
//	cout << "Testing the Employee class." << endl;
//
//	using namespace Records;
//	Employee emp;
//	emp.setFirstName("Marni");
//	emp.setLastName("Kleper");
//	emp.setEmployeeNumber(71);
//	emp.setSalary(50000);
//	emp.promote();
//	emp.promote(50);
//	emp.hire();
//	emp.display();
//}
//
////****************************************************************************
////*                     testDatabaseClass
////****************************************************************************
//inline void testDatabaseClass() {
//	cout << "Testing the Database class." << endl;
//
//	using namespace Records;
//	Database myDB;
//	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
//	emp1.fire();
//	Employee& emp2 = myDB.addEmployee("Scott", "Kleper");
//	emp2.setSalary(100000);
//	Employee& emp3 = myDB.addEmployee("Nick", "Solter");
//	emp3.setSalary(10000);
//	emp3.promote();
//	cout << "all employees: " << endl;
//	cout << endl;
//	myDB.displayAll();
//	cout << endl;
//	cout << "current employees: " << endl;
//	cout << endl;
//	myDB.displayCurrent();
//	cout << endl;
//	cout << "former employees: " << endl;
//	cout << endl;
//	myDB.displayFormer();
//}
//
////****************************************************************************
////*                     displayMenu
////****************************************************************************
//inline int displayMenu() {
//	int selection;
//
//	cout << endl;
//	cout << "Employee Database" << endl;
//	cout << "-----------------" << endl;
//	cout << "1) Hire a new employee" << endl;
//	cout << "2) Fire an employee" << endl;
//	cout << "3) Promote an employee" << endl;
//	cout << "4) List all employees" << endl;
//	cout << "5) List all current employees" << endl;
//	cout << "6) List all previous employees" << endl;
//	cout << "0) Quit" << endl;
//	cout << endl;
//	cout << "--->" << endl;
//	cin >> selection;
//	
//	return selection;
//}
//
////****************************************************************************
////*                     doHire
////****************************************************************************
//inline void doHire(Records::Database& inDB) {
//	string firstName;
//	string lastName;
//
//	cout << "First name? ";
//	cin >> firstName;
//	cout << "Last name? ";
//	cin >> lastName;
//
//	try {
//		inDB.addEmployee(firstName, lastName);
//	}
//	catch (const exception&) {
//		cerr << "Unable to add a new employee!" << endl;
//	}
//}
//
////****************************************************************************
////*                     doFire
////****************************************************************************
//inline void doFire(Records::Database& inDB) {
//	int employeeNumber;
//
//	cout << "Employee number? ";
//	cin >> employeeNumber;
//
//	try {
//		Records::Employee& emp = inDB.getEmployee(employeeNumber);
//		emp.fire();
//		cout << "Employee " << employeeNumber << " terminated." << endl;
//	}
//	catch (const exception&) {
//		cerr << "Unable to terminate employee!" << endl;
//	}
//}
//
////****************************************************************************
////*                     doPromote
////****************************************************************************
//inline void doPromote(Records::Database& inDB) {
//	int employeeNumber;
//	int raiseAmount;
//
//	cout << "Employee number? ";
//	cin >> employeeNumber;
//	cout << "How much of a raise? ";
//	cin >> raiseAmount;
//
//	try {
//		Records::Employee& emp = inDB.getEmployee(employeeNumber);
//		emp.promote(raiseAmount);
//	}
//	catch (const exception&) {
//		cerr << "Unable to promote employee!" << endl;
//	}
//}
//
////****************************************************************************
////*                     userInterface
////****************************************************************************
//inline void userInterface() {
//
//	using namespace Records;
//	Database employeeDB;
//	bool done = false;
//
//	while (!done) {
//		int selection = displayMenu();
//
//		switch (selection) {
//		case 1:
//			doHire(employeeDB);
//			break;
//		case 2:
//			doFire(employeeDB);
//			break;
//		case 3:
//			doPromote(employeeDB);
//			break;
//		case 4:
//			employeeDB.displayAll();
//			break;
//		case 5:
//			employeeDB.displayCurrent();
//			break;
//		case 6:
//			employeeDB.displayFormer();
//			break;
//		case 0:
//			done = true;
//			break;
//		default:
//			cerr << "Unknown command." << endl;
//		} // eof switch
//	}
//}
//
////****************************************************************************
////*                     chapter1
////****************************************************************************
//// function must be inline
//inline void chapter1() {
//	OutputDebugString(L"chapter1()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Chapter 1: A Crash Course in C++" << endl;
//		cout << "================================" << endl;
//		cout << " 1) The Basics of C++" << endl;
//		cout << " 2) Diving deeper into C++" << endl;
//		cout << " 3) C++ as an Object-Oriented language" << endl;
//		cout << " 4) The Standard Library" << endl;
//		cout << " 5) Your first usefull C++ program" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			basicsOfCpp();
//			break;
//		case 2:
//			divingDeeperIntoCpp();
//			break;
//		case 3:
//			cout << "C++ as an Object-Oriented language" << endl;
//			cout << "==================================" << endl;
//
//			cout << "Declaring a class" << endl;
//			cout << "a) Declaration: header file" << endl;
//			cout << "b) Definition: source file" << endl;
//			cout << "Object instance" << endl;
//			cout << "a) Stack based: MyClass myClass;" << endl;
//			cout << "b) Heap based:" << endl;
//			cout << "   MyClass* pMyClass = new MyClass();" << endl;
//			cout << "   delete pMyClass;" << endl;
//			cout << "   shared_ptr<MyClass> myClass(new MyClass());" << endl;
//			cout << "   deleted automatically" << endl;
//
//			break;
//		case 4:
//			cout << "The Standard Library" << endl;
//			cout << "====================" << endl;
//
//			break;
//		case 5:
//			cout << "Your first usefull C++ program" << endl;
//			cout << "==============================" << endl;
//
//			cout << "An employee record system" << endl;
//			cout << "Functionality:" << endl;
//			cout << "* add employee" << endl;
//			cout << "* fire employee" << endl;
//			cout << "* promote employee" << endl;
//			cout << "* view all employees, past and present" << endl;
//			cout << "* view all current employees" << endl;
//			cout << "* view all former employees" << endl;
//			cout << "Parts of the system:" << endl;
//			cout << "* Employee class" << endl;
//			cout << "* Database class" << endl;
//			cout << "* UserInterface class" << endl;
//
//			testEmployeeClass();
//			testDatabaseClass();
//
//			userInterface();
//
//			break;
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}