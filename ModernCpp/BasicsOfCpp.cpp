#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "foo.h"
//
////****************************************************************************
////*                     basicsOfCpp
////****************************************************************************
//// function must be inline
//inline void basicsOfCpp() {
//	OutputDebugString(L"basicsOfCpp()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "The Basics of C++" << endl;
//		cout << "=================" << endl;
//		cout << " 1) The Obligatory Hello World" << endl;
//		cout << " 2) Namespaces" << endl;
//		cout << " 3) Variables" << endl;
//		cout << " 4) Operators" << endl;
//		cout << " 5) Types" << endl;
//		cout << " 6) Conditionals" << endl;
//		cout << " 7) Loops" << endl;
//		cout << " 8) Arrays" << endl;
//		cout << " 9) Functions" << endl;
//		cout << "10) Those are the Basics" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "The Obligatory Hello World" << endl;
//			cout << "==========================" << endl;
//
//			cout << "Hello, World!" << endl;
//
//			cout << "a) Comments" << endl;
//			cout << "b) Preprocessor directives" << endl;
//			cout << "c) The main() function" << endl;
//			cout << "d) I/O streams" << endl;
//			cout << endl;
//			
//			cout << "Comments" << endl;
//			cout << "// a comment" << endl;
//			cout << "/* a comment ..." << endl;
//			cout << "   ..." << endl;
//			cout << "*/" << endl;
//			cout << endl;
//			cout << "Preprocessor directives" << endl;
//			cout << "Preprocessor -> Compiler -> Linker" << endl;
//			cout << "#include [file]" << endl;
//			cout << "#define [key] [value]" << endl;
//			cout << "#ifdef [key]" << endl;
//			cout << "#ifndef [key]" << endl;
//			cout << "#endif" << endl;
//			cout << "#pragma [xyz]" << endl;
//			cout << endl;
//			cout << "int main()" << endl;
//			cout << "int main(int argc, char* argv[])" << endl;
//			cout << endl;
//			cout << "I/O streams" << endl;
//			cout << "std::cin, std::cout, std::cerr" << endl;
//			cout << "operators: >>, <<" << endl;
//			cout << "escape characters:" << endl;
//			cout << "\n new line" << endl;
//			cout << "\b carriage return" << endl;
//			cout << "\t tab" << endl;
//			cout << "\\ backslash character" << endl;
//			cout << "\" quotation mark" << endl;
//
//			break;
//		case 2:
//			cout << "Namespaces" << endl;
//			cout << "==========" << endl;
//
//			mycode::foo();
//
//			break;
//		case 3:
//			cout << "Variables" << endl;
//			cout << "=========" << endl;
//			break;
//		case 4:
//			cout << "Operators" << endl;
//			cout << "=========" << endl;
//			break;
//		case 5:
//			cout << "Types" << endl;
//			cout << "=====" << endl;
//			break;
//		case 6:
//			cout << "Conditionals" << endl;
//			cout << "============" << endl;
//			break;
//		case 7:
//			cout << "Loops" << endl;
//			cout << "=====" << endl;
//			break;
//		case 8:
//			cout << "Arrays" << endl;
//			cout << "======" << endl;
//			break;
//		case 9:
//			cout << "Functions" << endl;
//			cout << "=========" << endl;
//			break;
//		case 10:
//			cout << "Those are the Basics" << endl;
//			cout << "====================" << endl;
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