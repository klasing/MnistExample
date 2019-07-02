// HttpClientAsyncSSL.cpp
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;
//****************************************************************************
//*                     get_string_from_user
//****************************************************************************
void get_string_from_user(
	string& input_from_user, const bool& echo_character = true)
{
	char substitute_character = '*';
	char ch = '\0';

	while ((ch = _getch()) != 13) {
		if (echo_character) cout << ch; else cout << substitute_character;
		input_from_user += ch;
	}
	cout << endl;
}

//****************************************************************************
//*                     get_input_from_user
//****************************************************************************
string get_input_from_user(
	const string& hdr,
	const int& width_header,
	const string& val,
	const int& width_value,
	const bool& echo_character = true)
{
	string substitute_user_password = "";
	substitute_user_password.insert(0, val.length(), '*');
	string input_from_user = "";

	cout
		<< setw(width_header)
		<< setiosflags(ios_base::left)
		<< setfill('.')
		<< hdr
		<< setw(width_value)
		<< setiosflags(ios_base::right)
		<< setfill('.')
		<< ((echo_character) ? val : substitute_user_password)
		<< ": ";
	cout.unsetf(ios::adjustfield);

	get_string_from_user(input_from_user, echo_character);

	return input_from_user.length() > 0 ? input_from_user : val;
}
//****************************************************************************
//*                     get_user_access_params
//****************************************************************************
void get_user_access_params(
	string& user_email_address,
	string& user_password)
{
	const string HDR_USER_EMAIL_ADDRESS = "Email";
	const string HDR_USER_PASSWORD = "Password";

	int width_header =
		(HDR_USER_EMAIL_ADDRESS.length() > HDR_USER_PASSWORD.length()) ?
		HDR_USER_EMAIL_ADDRESS.length() :
		HDR_USER_PASSWORD.length();
	width_header += 3;
	int width_value = (user_email_address.length()) > user_password.length() ?
		user_email_address.length() :
		user_password.length();

	user_email_address = get_input_from_user(
		HDR_USER_EMAIL_ADDRESS,
		width_header,
		user_email_address,
		width_value,
		true
	);

	user_password = get_input_from_user(
		HDR_USER_PASSWORD,
		width_header,
		user_password,
		width_value,
		false
	);
}

//****************************************************************************
//*                     get_user_access_params
//****************************************************************************
void show_request_example(
	const string& access_mode,
	const string& user_email_address,
	const string& user_password)
{
	string post_request_urlencoded_string = "";
	post_request_urlencoded_string =
		"email=" +
		user_email_address +
		"&password=" +
		user_password;
	//cout << post_request_urlencoded_string << endl;

	string post_request = "";
	post_request =
		string("POST /") +
		access_mode +
		" " +
		"HTTP/1.0\r\n" +
		"Host: 192.168.178.14\r\n" +
		"User-Agent: Boost.Beast/248\r\n" +
		"Content-Type: application/x-www-form-urlencoded\r\n" +
		"Content-Length: " + to_string(post_request_urlencoded_string.length()) + "\r\n" +
		"\r\n" +
		post_request_urlencoded_string + "\r\n" +
		"\r\n" +
		"\r\n";
	cout << post_request;
}

//****************************************************************************
//*                     user_access_to_server
//****************************************************************************
void user_access_to_server() {
	string user_email_address = "guest@example.com";
	string user_password = "anonymous";

	bool bProceed = true;
	int iChar = -1;

	while (bProceed) {
		cout << "Access" << endl;
		cout << "------" << endl;
		cout << " 1) Login" << endl;
		cout << " 2) Register" << endl;
		cout << " 3) Forgot password" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;
		// get rid of the new line character, to ensure the buffer sanity
		cin.get();

		switch (iChar) {
		case 1:
			get_user_access_params(user_email_address, user_password);
			show_request_example(
				"login", 
				user_email_address, 
				user_password);
			break;
		case 2:
			get_user_access_params(user_email_address, user_password);
			show_request_example(
				"register",
				user_email_address,
				user_password);
			break;
		case 3:
			get_user_access_params(user_email_address, user_password);
			show_request_example(
				"reset_password",
				user_email_address,
				user_password);
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
			break;
		} // eof switch
	}
}

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	user_access_to_server();
	return 0;
}

//// HttpClientAsyncSSL.cpp
//#include <iostream>
//#include <conio.h>
//#include <string>
//
//using namespace std;
//int main() {
//	string user_email_address = "";
//	string user_password = "";
//	string input_from_user = "";
//	char ch = '\0';
//
//	cout << "Email......: ";
//	getline(cin, input_from_user, '\n');
//	user_email_address = input_from_user;
//
//	input_from_user = "";
//	cout << "Password...: ";
//	while ((ch = _getch()) != 13) {
//		cout << '*';
//		input_from_user += ch;
//	}
//	cout << endl;
//	user_password = input_from_user;
//
//	cout << "Email address: " << user_email_address << ", Password: " << user_password << endl;
//
//	string post_request_urlencoded_string = "";
//	post_request_urlencoded_string =
//		"email=" +
//		user_email_address +
//		"&password=" +
//		user_password;
//	cout << post_request_urlencoded_string << endl;
//
//	string post_request = "";
//	post_request =
//		string("POST /login HTTP/1.0\r\n") +
//		"Host: 192.168.178.14\r\n" +
//		"User-Agent: Boost.Beast/248\r\n" +
//		"Content-Type: application/x-www-form-urlencoded\r\n" +
//		"Content-Length: " + to_string(post_request_urlencoded_string.length()) + "\r\n" +
//		"\r\n" +
//		post_request_urlencoded_string +
//		"\r\n" +
//		"\r\n";
//	cout << post_request;
//}
//// HttpClientAsyncSSL.cpp
//#include <iostream>
//
//#include "http_client_async_ssl.cpp"
//
//int main()
//{
//	std::cout << "Http Client Async SSL" << std::endl;
//	std::cout << "=====================" << std::endl;
//
//	char cmd[] = "http-client-async-ssl";
//	char host[] = /*"127.0.0.1";*/ "192.168.178.14";
//	char port[] = "8080";// "443";
//	char target[] = "/index.html";
//	char version[] = "1.0";
//	char* argv[] = { cmd, host , port, target, version };
//	int argc = 5;
//	ns_http_client_async_ssl::http_client_async_ssl(argc, argv);
//
//	int iChar;
//	std::cin >> iChar;
//}
