#include "pch.h"

#include "Employee.hpp"

using namespace Records;
inline void employeeTest() {
	cout << "-> Testing the Employee class." << endl;
	Employee emp;
	emp.setFirstName("Marni");
	emp.setLastName("Kleper");
	emp.setEmployeeNumber(71);
	emp.setSalary(50000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();
}

inline void subParagraph_1_5_2() {
	cout << "The Employee Class" << endl;
	cout << "------------------" << endl;

	employeeTest();
}