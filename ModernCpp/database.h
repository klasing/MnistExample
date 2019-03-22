//#pragma once
//
//#include "pch.h"
//#include "employee.h"
//
//namespace Records {
//	const int kFirstEmployeeNumber = 1000;
//
//	class Database {
//	public:
//		Database() {
//			mNextEmployeeNumber = kFirstEmployeeNumber;
//		}
//		~Database() {}
//		Employee& addEmployee(string inFirstName, string inLastName) {
//			Employee theEmployee;
//			theEmployee.setFirstName(inFirstName);
//			theEmployee.setLastName(inLastName);
//			theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
//			theEmployee.hire();
//			mEmployees.push_back(theEmployee);
//			return mEmployees[mEmployees.size() - 1];
//		}
//		Employee& getEmployee(int inEmployeeNumber) {
//			for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
//				if (iter->getEmployeeNumber() == inEmployeeNumber)
//					return *iter;
//			}
//
//			cerr << "No employee with number " << inEmployeeNumber << endl;
//			throw exception();
//		}
//		void displayAll() const {
//			for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
//				iter->display();
//			}
//		}
//		void displayCurrent() const {
//			for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
//				if (iter->getIsHired())
//					iter->display();
//			}
//		}
//		void displayFormer() const {
//			for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
//				if (!iter->getIsHired())
//					iter->display();
//			}
//		}
//
//	protected:
//		vector<Employee> mEmployees;
//		int mNextEmployeeNumber;
//	};
//}
