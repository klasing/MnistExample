#pragma once

#include <string>
#include "common_.h"

using namespace std;
// Model is responsible for data get and set
class Model_ {
public:
	// default constructor
	Model_() {}
	Model_(const string& inData) {
		SetData(inData);
	}
	string Data() { return data; }
	void SetData(const string& inData) {
		data = inData;
		// data change callback event
		if (event != nullptr)
			event(data);
	}
	// register the event when data changes
	void RegisterDataChangeHandler(DataChangeHandler handler) {
		event = handler;
	}
private:
	string data = "";
	DataChangeHandler event = nullptr;
};