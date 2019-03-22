//#pragma once
//
//#include "pch.h"
//
//class Maxpool {
//public:
//	Maxpool();
//	VOID feedForward();
//	VOID backPropagate();
//private:
//	double getHighestValue(const unsigned&, const unsigned&);
//	VOID showInput();
//	VOID showOutput();
//	VOID showMaxpoolIndexBuffer();
//
//	static const unsigned IMAGE_SIZE = 6;
//	static const unsigned STRIDE = 2;
//	static const unsigned MAXPOOL_SIZE = IMAGE_SIZE / STRIDE;
//
//	vector<vector<double>> vInput;
//	vector<vector<double>> vOutput;
//	vector<pair<int, int>> vMaxpoolIndexBuffer;
//
//	const unsigned MAX_BUF = 128;
//	char* pszBuffer = new char[MAX_BUF];
//};
