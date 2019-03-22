#include "pch.h"
//#pragma once
//
//#include "pch.h"
////#include "pch.h"
////
////#include "maxpool.h"
////
////Maxpool::Maxpool() {
////	OutputDebugString(L"<<constructor>> Maxpool()\n");
////
////	// get a seed for random number production
////	srand((unsigned)time(0));
////
////	// initialize the input vector
////	for (unsigned i = 0; i < IMAGE_SIZE; i++) {
////		vector<double> t;
////		for (unsigned j = 0; j < IMAGE_SIZE; j++)
////			t.push_back((rand() % 0xFF) / 25.5 - 5.);
////		vInput.push_back(t);
////	}
////
////}
////
////VOID Maxpool::feedForward() {
////	OutputDebugString(L".feedForward()\n");
////
////	showInput();
////
////	for (unsigned i = 0; i < IMAGE_SIZE; i += STRIDE) {
////		vector<double> t;
////		for (unsigned j = 0; j < IMAGE_SIZE; j += STRIDE)
////			t.push_back(getHighestValue(i, j));
////		vOutput.push_back(t);
////	}
////
////	showMaxpoolIndexBuffer();
////	showOutput();
////}
////
////double Maxpool::getHighestValue(const unsigned& i, const unsigned& j) {
////	OutputDebugString(L".getHighestValue()\n");
////
////	pair<unsigned, unsigned> pairIndex;
////	unsigned rowIdxHighest, colIdxHighest;
////
////	double highest_value = -DBL_MAX;
////
////	if (vInput[i][j] > highest_value) {
////		highest_value = vInput[i][j];
////		rowIdxHighest = i;
////		colIdxHighest = j;
////	}
////
////	if (vInput[i][j + 1] > highest_value) {
////		highest_value = vInput[i][j + 1];
////		rowIdxHighest = i;
////		colIdxHighest = j + 1;
////	}
////	if (vInput[i + 1][j] > highest_value) {
////		highest_value = vInput[i + 1][j];
////		rowIdxHighest = i + 1;
////		colIdxHighest = j;
////	}
////	if (vInput[i + 1][j + 1] > highest_value) {
////		highest_value = vInput[i + 1][j + 1];
////		rowIdxHighest = i + 1;
////		colIdxHighest = j + 1;
////	}
////
////	// save index
////	pairIndex.first = rowIdxHighest;
////	pairIndex.second = colIdxHighest;
////	vMaxpoolIndexBuffer.push_back(pairIndex);
////
////	return highest_value;
////}
////
////VOID Maxpool::backPropagate() {
////	OutputDebugString(L".backPropagate()\n");
////
////	for (unsigned i = 0; i < vMaxpoolIndexBuffer.size(); i++)
////		vInput[vMaxpoolIndexBuffer[i].first][vMaxpoolIndexBuffer[i].second] 
////			= 0.;
////
////	showInput();
////}
////
////VOID Maxpool::showInput() {
////	OutputDebugString(L".showInput()\n");
////
////	for (unsigned i = 0; i < IMAGE_SIZE; i++) {
////		for (unsigned j = 0; j < IMAGE_SIZE; j++) {
////			sprintf_s(pszBuffer, MAX_BUF, "\xB3 %+1.3f ", vInput[i][j]);
////			cout << pszBuffer;
////		}
////		cout << "\xB3 \n";
////	}
////	cout << "\n";
////}
////
////VOID Maxpool::showOutput() {
////	OutputDebugString(L".showOutput()\n");
////
////	for (unsigned i = 0; i < MAXPOOL_SIZE; i++) {
////		for (unsigned j = 0; j < MAXPOOL_SIZE; j++) {
////			sprintf_s(pszBuffer, MAX_BUF, "\xB3 %+1.3f ", vOutput[i][j]);
////			cout << pszBuffer;
////		}
////		cout << "\xB3 \n";
////	}
////	cout << "\n";
////}
////
////VOID Maxpool::showMaxpoolIndexBuffer() {
////	OutputDebugString(L".showMaxpoolIndexBuffer()\n");
////
////	for (unsigned i = 0; i < vMaxpoolIndexBuffer.size(); i++) {
////		sprintf_s(pszBuffer, MAX_BUF, "\xB3 %d %d ", 
////			vMaxpoolIndexBuffer[i].first, vMaxpoolIndexBuffer[i].second);
////		cout << pszBuffer;
////		// start next row on a new line
////		if ((i % 3) == 2) cout << "\xB3 \n";
////	}
////	cout << "\n";
////}
////
