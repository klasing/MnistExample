#pragma once

#include "pch.h"

class Request_22_3_4 {
public:
	Request_22_3_4(int id) : mId(id) {}
	void process() {
		cout << "-> Processing request " << mId << endl;
	}
protected:
	int mId;
};
