#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//
////****************************************************************************
////*                     perfectScore
////****************************************************************************
////inline bool perfectScore(int num) {
////	OutputDebugString(L"perfectScore()\n");
////
////	return (num >= 100);
////}
//
////****************************************************************************
////*                     arithmetricMean
////****************************************************************************
//inline double arithmetricMean(const vector<int>& nums) {
//	OutputDebugString(L"arithmetricMean()\n");
//
//	double sum = accumulate(nums.begin(), nums.end(), 0);
//	return sum / nums.size();
//}
//
////****************************************************************************
////*                     product
////****************************************************************************
////int product(int num1, int num2) {
////	OutputDebugString(L"product()\n");
////
////	return num1 * num2;
////}
//
////****************************************************************************
////*                     geometricMean
////****************************************************************************
////double geometricMean(const vector<int>& nums) {
////	OutputDebugString(L"geometricMean()\n");
////
////	double mult = accumulate(nums.begin(), nums.end(), 1, product);
////	return pow(mult, 1. / nums.size());
////}
//
////****************************************************************************
////*                     geometricMeanLambda
////****************************************************************************
//inline double geometricMeanLambda(const vector<int>& nums) {
//	OutputDebugString(L"geometricMeanLambda()\n");
//
//	double mult = accumulate(nums.begin(), nums.end(), 1,
//		[](int num1, int num2) { return num1 * num2; });
//	return pow(mult, 1. / nums.size());
//}
//
////****************************************************************************
////*                     overviewOfAlgorithms
////****************************************************************************
//// function must be inline
//inline void overviewOfAlgorithms() {
//	OutputDebugString(L"overviewOfAlgorithms()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Overview of Algorithms" << endl;
//		cout << "======================" << endl;
//		cout << " 1) The find and find_if algorithms" << endl;
//		cout << " 2) The accumulate algorithms" << endl;
//		cout << " 3) C++11 Move semantics with algorithms" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1: {
//			cout << "The find and find_if algorithms" << endl;
//			cout << "===============================" << endl;
//
//			int num;
//			vector<int> myVector;
//			while (true) {
//				//cout << "Enter a number to add (0 to stop): ";
//				cout << "Enter a test score to add (0 to stop): ";
//				cin >> num;
//				if (num == 0)
//					break;
//				myVector.push_back(num);
//			}
//			//while (true) {
//			//	cout << "Enter a number to lookup (0 to stop): ";
//			//	cin >> num;
//			//	if (num == 0)
//			//		break;
//				auto end = myVector.end();
//				//auto it = find(myVector.begin(), end, num);
//				//auto it = find_if(myVector.begin(), end, perfectScore);
//				auto it = find_if(myVector.begin(), end, [](int i) {
//					return i >= 100; });
//				if (it == end)
//					//cout << "Could not find " << num << endl;
//					cout << "No perfect scores" << num << endl;
//				else
//					//cout << "Found " << *it << endl;
//					cout << "Found a \"perfect\" score of " << *it << endl;
//			//}
//
//			break;
//		} // eof case 1
//		case 2: {
//			cout << "The accumulate algorithms" << endl;
//			cout << "=========================" << endl;
//
//			vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//			cout << "arithmetric mean: " << arithmetricMean(vec) << endl;
//			cout << "geometric mean: " << geometricMeanLambda(vec) << endl;
//
//			break;
//		} // eof case 2
//		case 3:
//			cout << "C++11 Move semantics with algorithms" << endl;
//			cout << "====================================" << endl;
//
//			break;
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