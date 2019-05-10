#pragma once

#include <iostream>
#include <string>
#include "Student.hpp"

using namespace std;
namespace ejemplo_mvc {
	class StudentViewTwo {
	public:
		StudentViewTwo() {}
		virtual ~StudentViewTwo() {}
		void printStudentDetails(Student s) {
			cout << "-> ESTUDIANTE:" << endl;
			cout << "-> NOMBRE: " << s.getName() << endl;
			cout << "-> NÚMERO: " << s.getNollNo() << endl;
		}
	};
}
