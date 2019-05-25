// Exercise 3.1
#include <boost/scope_exit.hpp>
#include <string>
#include <memory>
#include <cstdio>
#include <iostream>

using namespace std;
namespace ns_exercise_3_1 {
	struct CloseFile {
		void operator()(FILE* file) {
			cout << "-> closing file" << endl;
			fclose(file);
		}
	};

	//inline void write_to_file(const string& s) {
	//	unique_ptr<FILE, CloseFile> file{
	//		fopen("hello-world.txt", "a")};
	//	fprintf(file.get(), s.c_str());
	//}
	// the exercise is to replace the code above,
	// with a BOOST_SCOPE_EXIT macro
	inline void write_to_file(const string& s, const int& length) {
		FILE* pFile = new FILE();
		BOOST_SCOPE_EXIT(&pFile) {
			fclose(pFile);
		} BOOST_SCOPE_EXIT_END
			pFile =	fopen("hello-world.txt", "a");
		fwrite(s.c_str(), sizeof(char), length, pFile);
	}

	inline void exercise_3_1() {
		write_to_file("HELLO, ", 7);
		write_to_file("WORLD!", 6);
	}
}