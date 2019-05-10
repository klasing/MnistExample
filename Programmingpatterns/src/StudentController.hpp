#pragma once

#include <string>
#include "Student.hpp"

using namespace std;
namespace ejemplo_mvc {
	class StudentController {
	public:
		StudentController(Student model) {
			// TODO Auto-generated constructor stub
			this->model = model;
		}
		virtual ~StudentController() {
			// TODO Auto-generated destructor stub
		}

		void setStudentName(string name) {
			model.setName(name);
		}
		string getStudentName() {
			return model.getName();
		}

		void setStudentRollNo(string r) {
			model.setNollNo(r);
		}
		string getStudentRollNo() {
			return model.getNollNo();
		}
	private:
		Student model;
	};
}
