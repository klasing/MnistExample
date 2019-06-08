// BoostLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1) Configuration Properties C / C++ General
//    Additional Include Directories : C:\Program Files\boost\boost_1_70_0
//    Precompiled Header : Not Using Precompiled Headers
// 2) Configuration Properties Linker General
//    Additional Include Directories : C:\Program Files\boost\boost_1_70_0\stage\lib


#include <iostream>
#include <string>

//#include "example_1_1.cpp"
//#include "example_1_2.cpp"
//#include "example_1_3.cpp"
//#include "example_1_4.cpp"
//#include "example_1_5.cpp"
//#include "example_1_6.cpp"
//#include "example_1_7.cpp"
//#include "example_1_8.cpp"
//#include "example_1_9.cpp"
//#include "example_2_1.cpp"
//#include "example_2_2.cpp"
//#include "example_2_3.cpp"
//#include "exercise_2_1_starter.cpp"
//#include "exercise_2_1.cpp"
//#include "example_3_1.cpp"
//#include "example_3_2.cpp"
//#include "example_3_3.cpp"
//#include "exercise_3_1.cpp"
//#include "example_4_1.cpp"
//#include "example_4_2.cpp"
//#include "example_4_3.cpp"
//#include "example_4_4.cpp"
//#include "example_4_5.cpp"
//#include "example_4_6.cpp"
//#include "example_5_1.cpp"
//#include "example_5_2.cpp"
//#include "example_5_3.cpp"
//#include "example_5_4.cpp"
//#include "example_5_5.cpp"
//#include "example_5_6.cpp"
//#include "example_5_7.cpp"
//#include "example_5_8.cpp"
//#include "example_5_9.cpp"
//#include "example_5_10.cpp"
//#include "example_5_11.cpp"
//#include "example_5_12.cpp"
//#include "exercise_5_1.cpp"
//#include "example_6_1.cpp"
//#include "example_6_2.cpp"
//#include "example_7_1.cpp"
//#include "example_7_2.cpp"
//#include "example_7_3.cpp"
//#include "example_7_4.cpp"
//#include "example_7_5.cpp"
//#include "example_7_6.cpp"
//#include "example_7_7.cpp"
//#include "example_7_8.cpp"
//#include "example_7_9.cpp"
//#include "example_8_1.cpp"
//#include "example_8_2.cpp"
//#include "example_8_3.cpp"
//#include "example_8_4.cpp"
//#include "example_8_5.cpp"
//#include "example_8_6.cpp"
//#include "example_8_7.cpp"
//#include "example_8_8.cpp"
//#include "example_32_1.cpp"
//#include "example_32_2.cpp"
//#include "example_32_3.cpp"
//#include "example_32_4.cpp"
//#include "example_32_5.cpp"
//#include "example_32_6.cpp"
//#include "example_http_client_sync.cpp"
#include "example_websocket_client_sync.cpp"
//
//// used in exercise_2_1_starter.cpp
//const string ns_exercise_2_1_starter::muuuh = "Muuuh!";
//const string ns_exercise_2_1_starter::oiink = "Oiiink";

// used in example_32_5
//io_service ns_example_32_5::ioservice;
//tcp::resolver ns_example_32_5::resolv{ ns_example_32_5::ioservice };
//tcp::socket ns_example_32_5::tcp_socket{ ns_example_32_5::ioservice };
//array<char, 4096> ns_example_32_5::bytes;

// used in example_32_6
//io_service ns_example_32_6::ioservice;
//tcp::endpoint ns_example_32_6::tcp_endpoint{ tcp::v4(), 2014 };
//tcp::acceptor ns_example_32_6::tcp_acceptor{ ns_example_32_6::ioservice,
//	ns_example_32_6::tcp_endpoint };
//tcp::socket ns_example_32_6::tcp_socket{ ns_example_32_6::ioservice };
//string ns_example_32_6::data;

int main() {
    std::cout << "Hello World!\n";

	//ns_example_1_1::example_1_1();
	//ns_example_1_2::example_1_2();
	//ns_example_1_3::example_1_3();
	//ns_example_1_4::example_1_4();
	//ns_example_1_5::example_1_5();
	//ns_example_1_6::example_1_6();
	//ns_example_1_7::example_1_7();
	//ns_example_1_8::example_1_8();
	//ns_example_1_9::example_1_9(); // has issues
	//ns_example_2_1::example_2_1();
	//ns_example_2_2::example_2_2();
	//ns_example_2_3::example_2_3();
	//ns_exercise_2_1_starter::exercise_2_1_starter();
	//ns_exercise_2_1::exercise_2_1();
	//ns_example_3_1::example_3_1();
	//ns_example_3_2::example_3_2();
	//ns_example_3_3::example_3_3();
	//ns_exercise_3_1::exercise_3_1();
	//_example_4_1::example_4_1();
	//ns_example_4_2::example_4_2();
	//ns_example_4_3::example_4_3();
	//ns_example_4_4::example_4_4();
	//ns_example_4_5::example_4_5();
	//ns_example_4_6::example_4_6();
	//ns_example_5_1::example_5_1();
	//ns_example_5_2::example_5_2();
	//ns_example_5_3::example_5_3();
	//ns_example_5_4::example_5_4();
	//ns_example_5_5::example_5_5();
	//ns_example_5_6::example_5_6();
	//ns_example_5_7::example_5_7();
	//ns_example_5_8::example_5_8();
	//ns_example_5_9::example_5_9();
	//ns_example_5_10::example_5_10();
	//ns_example_5_11::example_5_11();
	//ns_example_5_12::example_5_12(); // has issues
	//ns_exercise_5_1::exercise_5_1(); // has issues
	//ns_example_6_1::example_6_1();
	//ns_example_6_2::example_6_2();
	//ns_example_7_1::example_7_1();
	//ns_example_7_2::example_7_2();
	//ns_example_7_3::example_7_3();
	//ns_example_7_4::example_7_4();
	//ns_example_7_5::example_7_5();
	//ns_example_7_6::example_7_6();
	//ns_example_7_7::example_7_7();
	//ns_example_7_8::example_7_8();
	//ns_example_7_9::example_7_9();
	//ns_example_8_1::example_8_1();
	//ns_example_8_2::example_8_2();
	//ns_example_8_3::example_8_3();
	// this example does not output what was suggested
	//ns_example_8_4::example_8_4();
	//ns_example_8_5::example_8_5();
	//ns_example_8_6::example_8_6();
	//ns_example_8_7::example_8_7();
	//ns_example_8_8::example_8_8();
	//ns_example_32_1::example_32_1();
	//ns_example_32_2::example_32_2();
	//ns_example_32_3::example_32_3();
	//ns_example_32_4::example_32_4();
	//ns_example_32_5::example_32_5();
	//ns_example_32_6::example_32_6();
	//char cmd[] = "http-client-sync";
	//char host[] = "www.example.com";
	//char port[] = "80";
	//char target[] = "/";
	//char* argv[] = { cmd, host , port, target };
	//ns_example_http_client_sync::example_http_client_sync(
	//	4, argv);
	char cmd[] = "websocket-client-sync";
	char host[] = "echo.websocket.org";
	char port[] = "80";
	char text[] = "\"Hello, world!\"";
	char* argv[] = { cmd, host , port, text };
	ns_example_websocket_client_sync::example_websocket_client_sync(
		4, argv);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
