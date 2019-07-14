//#pragma once
// handle_user_access.hpp
// 1) login
//    1.1) login is ok, if
//         user_email_address is on file and
//         user_password is correct
//    1.2) login is NOT ok, if
//         1.2.1) user_email_address is NOT on file
//                a user can register himself with the menu option: register
//         1.2.2) user_password is NOT correct
//                a user can try again or
//                can use the menu option: forgot password
// 2) register
//    2.1) registration can be performed, if
//         user_email_address is NOT on filem then
//         the user_email_address/user_password will be written to file
//    2,2) registration can NOT be performed, if
//         user_email_address is on file, then
//         a user can use a different email address
//    a confirmation code will be send via email
//    the registration can be completed,
//    when the user has correctly entered the confirmation code
// 3) forgot password
//    a password reset can be performed, if
//    user_email_address is on file, then
//    a confirmation code will be send via email
//    the password reset can be completed,
//    when the user has correctly entered the confirmation code
//#include <iostream>
//#include <tuple>
//#include <time.h>
//#include <random>
//
//using namespace std;
//namespace ns_handle_user_access {
//	inline void 
//		generate_random_string()
//	{
//		string random_string = "";
//		mt19937 eng(static_cast<unsigned long>(time(nullptr)));
//		uniform_int_distribution<int> dist(65, 90);
//		for (int i = 0; i < 32; i++)
//			random_string += dist(eng);
//		cout << random_string << endl;
//	}
//
//	inline string 
//		handle_user_access(
//			const string& target,
//			const string& payload)
//	{
//		cout << "handle_user_access()" << endl;
//		cout << "-> POST message received" << endl;
//
//		// filter user_email_address
//		size_t sBegin, sEnd, sLength, sTemp;
//		sTemp = 0;
//		sBegin = payload.find_first_of("=", sTemp);
//		sEnd = (payload.find("&", sBegin) != std::string::npos) ?
//			(payload.find("&", sBegin) - 1) :
//			payload.length() - 1;
//		sLength = sEnd - sBegin;
//		sBegin++;
//		std::string user_email_address = payload.substr(sBegin, sLength);
//		// filter user_password
//		sTemp = sEnd;
//		sBegin = payload.find_first_of("=", sTemp);
//		sEnd = (payload.find("&", sBegin) != std::string::npos) ?
//			(payload.find("&", sBegin) - 1) :
//			payload.length() - 1;
//		sLength = sEnd - sBegin;
//		sBegin++;
//		std::string user_password = payload.substr(sBegin, sLength);
//
//		std::cout << user_email_address << " " << user_password << std::endl;
//		typedef tuple<string, string> tuple_user_data;
//		tuple_user_data user_data_on_file(
//			user_email_address,
//			user_password);
//
//		// see what kind of access is requested
//		if (target == "/login")
//			;
//		if (target == "/register")
//			generate_random_string();
//		if (target == "/reset_password")
//			;
//
//		std::string response_payload = target;
//		response_payload.erase(0, 1);
//		response_payload += " succeeded";
//
//		return response_payload;
//	}
//}