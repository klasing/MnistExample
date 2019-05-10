// design patterns in Java
// https://www.tutorialspoint.com/design_pattern/index.htm
// example found at:
// https://github.com/javism/MVC-Example
#include <iostream>
#include "src/StudentController.hpp"
#include "src/Student.hpp"
#include "src/StudentView.hpp"
#include "src/StudentViewTwo.hpp"

#include "src/Model_.hpp"
#include "src/View_.hpp"
#include "src/Controller_.hpp"
#include "src/common_.h"

using namespace std;
using namespace ejemplo_mvc;

inline Student retrieveStudentFromDatabase() {
	Student s;
	s.setName("Pepito");
	s.setNollNo("10");
	return s;
}

inline void DataChange_(string data) {
	cout << "-> Data Changes: " << data << endl;
}

inline void chapter_4_12() {
	// C++ version of: 
	// c
	cout << "Model-View-Controller (MVC)" << endl;
	cout << "---------------------------" << endl;

	// Recover student from database, actually the Controller should do this
	Student model = retrieveStudentFromDatabase();

	// Create the view to print the student details
	StudentView view = StudentView();
	// http://en.cppreference.com/w/cpp/language/lambda
	Connection c1 = model.connect([&](const Student& mo) {
		view.printStudentDetails(mo);
	});

	// Add a second view to the model
	StudentViewTwo viewTwo = StudentViewTwo();

	Connection c2 = model.connect([&](const Student & mo) {
		viewTwo.printStudentDetails(mo);
	});

	StudentController controller = StudentController(model);

	// Update data
	cout << "-> --- Actualizamos el modelo (y la vista es notificada) ---" << endl;
	controller.setStudentName("Juanito");
	cout << "-> --- Actualizamos el modelo (y la vista es notificada) ---" << endl;
	controller.setStudentName("Pepito");

	// Remove one of the views
	model.disconnect(c1);
	cout << "-> --- Actualizamos el modelo (y la vista es notificada) ---" << endl;
	controller.setStudentName("Nuevo");

	// a second example is found at:
	// https://helloacm.com/model-view-controller-explained-in-c/
	Model_ model_("Model");
	View_ view_(model_);
	// register the data-change event
	model_.RegisterDataChangeHandler(&DataChange_);
	// binds model and view
	Controller_ controller_(model_, view_);
	// when application starts or button is clicked or form is shown...
	controller_.OnLoad();
	// this should trigger View to render
	model_.SetData("Changes");
}