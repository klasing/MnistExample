#include "pch.h"

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class FileError_10_3_3 : public runtime_error {
public:
	FileError_10_3_3(const string& fileIn)
		: runtime_error(""), mFile(fileIn) {}
	virtual const char* what() const noexcept {
		return mMsg.c_str();
	}
	string getFileName() {
		return mFile;
	}
protected:
	string mFile, mMsg;
};

class FileOpenError_10_3_3 : public FileError_10_3_3 {
public:
	FileOpenError_10_3_3(const string& fileNameIn) 
		: FileError_10_3_3(fileNameIn) {
		mMsg = "Unable to open " + fileNameIn;
	}
};

class FileReadError_10_3_3 : public FileError_10_3_3 {
public:
	FileReadError_10_3_3(const string& fileNameIn, int lineNumIn) 
		: FileError_10_3_3(fileNameIn), mLineNum(lineNumIn) {
		ostringstream ostr;
		ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
		mMsg = ostr.str();
	}
	int getLineNum() {
		return mLineNum;
	}
protected:
	int mLineNum;
};

inline void readIntegerFile_10_3_3(const string& fileName, vector<int>& dest) 
	throw(FileOpenError_10_3_3, FileReadError_10_3_3) {
	ifstream istr;
	int temp;
	string line;
	int lineNumber = 0;
	istr.open(fileName.c_str());
	if (istr.fail())
		// We failed to open the file: throw an exception.
		throw FileOpenError_10_3_3(fileName);
	while (!istr.eof()) {
		// Read one line from the file.
		getline(istr, line);
		lineNumber++;
		// Create a string stream out of the line.
		istringstream lineStream(line);
		// Read the integers one by one and add them to the vector.
		while (lineStream >> temp)
			dest.push_back(temp);
		if (!lineStream.eof()) {
			// Some other error. Close the file and throw an exception.
			istr.close();
			throw FileReadError_10_3_3(fileName, lineNumber);
		}
	}
	istr.close();
}

inline void subParagraph_10_3_3() {
	cout << "Writing Your Own Exception Classes" << endl;
	cout << "----------------------------------" << endl;

	vector<int> myInts;
	const string fileName = "IntegerFile.txt";
	try {
		readIntegerFile_10_3_3(fileName, myInts);
	}
	catch (const FileError_10_3_3 & e) {
		cerr << "-> " << e.what() << endl;
	}

	cout << "-> ";
	for (size_t i = 0; i < myInts.size(); i++)
		cout << myInts[i] << " ";
	cout << endl;
}