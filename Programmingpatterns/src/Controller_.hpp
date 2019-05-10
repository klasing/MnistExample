#pragma once
#include "Model_.hpp"
#include "View_.hpp"

// Controller combines Model and View
class Controller_ {
public:
	Controller_(const Model_& model_, const View_& view_) :
		model_(model_), view_(view_) {}
	// when application starts
	void OnLoad() {
		view_.Render();
	}
private:
	Model_ model_;
	View_ view_;
};