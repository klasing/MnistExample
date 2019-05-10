#pragma once

#include <iostream>
#include "Model_.hpp"

// View is responsible to present data to the users
class View_ {
public:
	View_(const Model_& model_) : model_(model_) {}
	void Render() {
		cout << "-> Model Data = " << model_.Data() << endl;
	}
private:
	Model_ model_;
};