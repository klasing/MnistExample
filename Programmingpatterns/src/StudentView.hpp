#pragma once

#include <iostream>
#include <string>
#include "Student.hpp"

using namespace std;
namespace ejemplo_mvc {
	class StudentView {
	public:
		StudentView() {}
		virtual ~StudentView() {}
		void printStudentDetails(Student s) {
			cout << "-> Student:" << endl;
			cout << "-> Name: " << s.getName() << endl;
			cout << "-> Roll No: " << s.getNollNo() << endl;
		}
	};
}
