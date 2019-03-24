#include "pch.h"

#include "Database.hpp"

using namespace Records;
inline void subParagraph_1_5_3() {
	cout << "The Database Class" << endl;
	cout << "------------------" << endl;

	Database myDB;
	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
	emp1.fire();
	Employee& emp2 = myDB.addEmployee("Scott", "Kleper");
	emp2.setSalary(100000);
	Employee& emp3 = myDB.addEmployee("Nick", "Solter");
	emp3.setSalary(10000);
	emp3.promote();
	cout << "-> all employees:" << endl;
	myDB.displayAll();
	cout << "-> current employees:" << endl;
	myDB.displayCurrent();
	cout << "-> former employees:" << endl;
	myDB.displayFormer();
}