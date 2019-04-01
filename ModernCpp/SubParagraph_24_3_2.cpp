#include "pch.h"

#include "ObjectPool.hpp"
#include "UserRequest.hpp"

inline shared_ptr<UserRequest> obtainUserRequest(ObjectPool<UserRequest>& pool) {
	// Obtain a UserRequest object from the pool.
	auto request = pool.aquireObject();
	// Populate the request with user input. (not shown)
	request->setDescription("User input");
	return request;
}

inline void processUserRequest(ObjectPool<UserRequest>& pool,
	shared_ptr<UserRequest> req) {
	// Process the request. (not shown)
	cout << "-> " << req->getDescription() << endl;
	// Return the request to the pool.
	pool.releaseObject(req);
}

inline int main_24_3_2() {
	ObjectPool<UserRequest> requestPool(10);
	cout << "-> Loop starting." << endl;
	for (size_t i = 0; i < 100; ++i) {
		auto req = obtainUserRequest(requestPool);
		processUserRequest(requestPool, req);
	}
	cout << "-> Loop finished." << endl;

	return 0;
}

inline void subParagraph_24_3_2() {
	cout << "Use Object Pools" << endl;
	cout << "----------------" << endl;

	main_24_3_2();
}