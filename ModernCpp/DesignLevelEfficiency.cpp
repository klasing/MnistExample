#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "object_pool.h"
//#include "user_request.h"
//
////****************************************************************************
////*                     obtainUserRequest
////****************************************************************************
//inline shared_ptr<UserRequest> obtainUserRequest(ObjectPool<UserRequest>& pool) {
//
//	OutputDebugString(L"obtainUserRequest()\n");
//
//	// Obtain a UserRequest object from the pool.
//	auto request = pool.aquireObject();
//	// Populate the request with user input. (not shown)
//
//	return request;
//}
//
////****************************************************************************
////*                     processUserRequest
////****************************************************************************
//inline void processUserRequest(ObjectPool<UserRequest>& pool,
//	shared_ptr<UserRequest> req) {
//
//	OutputDebugString(L"processUserRequest()\n");
//
//	// Process the request. (not shown)
//	// Return the request to the pool.
//	pool.releaseObject(req);
//}
//
////****************************************************************************
////*                     designLevelEfficiency
////****************************************************************************
//// function must be inline
//inline void designLevelEfficiency() {
//	OutputDebugString(L"designLevelEfficiency()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Design-level Efficiency" << endl;
//		cout << "=======================" << endl;
//		cout << " 1) Cache as much as possible" << endl;
//		cout << " 2) Use Object pools" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1: {
//			cout << "Cache as much as possible" << endl;
//			cout << "=========================" << endl;
//
//			break;
//		} // eof case 1
//		case 2: {
//			cout << "Use Object pools" << endl;
//			cout << "================" << endl;
//
//			ObjectPool<UserRequest> requestPool(10);
//			cout << "Loop starting." << endl;
//			for (size_t i = 0; i < 100; ++i) {
//				auto req = obtainUserRequest(requestPool);
//				processUserRequest(requestPool, req);
//			}
//			cout << "Loop finished." << endl;
//
//			break;
//		} // eof case 2
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}