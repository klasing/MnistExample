#pragma once

#include <string>

class UserRequest {
public:
	UserRequest() {}
	virtual ~UserRequest() {}
	// Methods to populate the request with specific information.
	// Methods to retrieve the request data.
	// (not shown)
	void setDescription(const std::string& inDesc) {
		mDesc = inDesc;
	}
	std::string getDescription() const {
		return mDesc;
	}
protected:
	// Data members (not shown)
	std::string mDesc;
};
