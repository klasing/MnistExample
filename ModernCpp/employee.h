//#pragma once
//
//#include "pch.h"
//
//namespace Records {
//	const int kDefaultStartingSalary = 30000;
//
//	class Employee {
//	public:
//		Employee() : mFirstName(""), mLastName(""),
//			mEmployeeNumber(-1), mSalary(kDefaultStartingSalary),
//			bHired(false) {
//		}
//		void promote(int inRaiseAmount = 1000) {
//			setSalary(getSalary() + inRaiseAmount);
//		}
//		void demote(int inDemeritAmount = 1000) {
//			setSalary(getSalary() - inDemeritAmount);
//		}
//		void hire() {
//			// Hires or rehisres the employee
//			bHired = true;
//		}
//		void fire() {
//			// Dismisses the employee
//			bHired = false;
//		}
//		void display() const {
//			// Outputs employee info to console
//			cout << "Employee: " << getLastName().c_str() << ", " << getFirstName().c_str() << endl;
//			cout << "--------------------------" << endl;
//			cout << ((bHired) ? "Current Employee" : "Former Employee") << endl;
//			cout << "Employee number: " << getEmployeeNumber() << endl;
//			cout << "Salary: $" << getSalary() << endl;
//			cout << endl;
//		}
//		// Accessors and setters
//		void setFirstName(string inFirstName) {
//			mFirstName = inFirstName;
//		}
//		string getFirstName() const {
//			return mFirstName;
//		}
//		void setLastName(string inLastName) {
//			mLastName = inLastName;
//		}
//		string getLastName() const {
//			return mLastName;
//		}
//
//		void setEmployeeNumber(int inEmployeeNumber) {
//			mEmployeeNumber = inEmployeeNumber;
//		}
//
//		int getEmployeeNumber() const {
//			return mEmployeeNumber;
//		}
//
//		void setSalary(int inNewSalary) {
//			mSalary = inNewSalary;
//		}
//
//		int getSalary() const {
//			return mSalary;
//		}
//
//		bool getIsHired() const {
//			return bHired;
//		}
//
//	protected:
//		string mFirstName;
//		string mLastName;
//		int mEmployeeNumber;
//		int mSalary;
//		bool bHired;
//	};
//}
