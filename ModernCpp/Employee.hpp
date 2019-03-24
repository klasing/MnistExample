#pragma once

// Employee.h
#include <string>

#include <iostream>
using namespace std;

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Employee {
	public:
		Employee() 
			: mFirstName("")
			, mLastName("")
			, mEmployeeNumber(-1)
			, mSalary(kDefaultStartingSalary)
			, bHired(false)
		{}
		void promote(int inRaiseAmount = 1000) {
			setSalary(getSalary() + inRaiseAmount);
		}
		void demote(int inDemeritAmount = 1000) {
			setSalary(getSalary() - inDemeritAmount);
		}
		void hire() {
			// Hires or rehires the employee
			bHired = true;
		}
		void fire() {
			// Dismisses the employee
			bHired = false;
		}
		void display() const {
			// Outputs the employee info to console
			cout << "-> Employee: " << getLastName() << ", " << getFirstName() << endl;
			cout << "-> --------------------------" << endl;
			cout << (bHired ? "-> Current Employee" : "-> Former Employee") << endl;
			cout << "-> Employee Number: " << getEmployeeNumber() << endl;
			cout << "-> Salary: $" << getSalary() << endl;
			cout << "" << endl;
		}
		// Accessors and setters
		void setFirstName(std::string inFirstName) {
			mFirstName = inFirstName;
		}
		std::string getFirstName() const {
			return mFirstName;
		}
		void setLastName(std::string inLastName) {
			mLastName = inLastName;
		}
		std::string getLastName() const {
			return mLastName;
		}
		void setEmployeeNumber(int inEmployeeNumber) {
			mEmployeeNumber = inEmployeeNumber;
		}
		int getEmployeeNumber() const {
			return mEmployeeNumber;
		}
		void setSalary(int inNewSalary) {
			mSalary = inNewSalary;
		}
		int getSalary() const {
			return mSalary;
		}
		bool getIsHired() const {
			return bHired;
		}
	protected:
		std::string mFirstName;
		std::string mLastName;
		int         mEmployeeNumber;
		int         mSalary;
		bool        bHired;
	};
}
