#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "handle_user_access.hpp"

using namespace std;
// forward declaration
namespace ns_http_client_async_ssl {
	// prototype
	inline void transcieve(const string&);
}
namespace ns_http_server_async_ssl {
	inline void transcieve(
		const string payload,
		const string target)
	{
		cout << payload << " " << target << endl;

		std:string response_payload =
			ns_handle_user_access::handle_user_access(
				target,
				payload);
		string response = string("HTTP/1.1 200 OK\n")
			+ "Server: Boost.Beast/248\n"
			+ "Content-Type: text/html\n"
			+ "Content-Length: 15\n"
			+ "\n"
			+ response_payload;
		ns_http_client_async_ssl::transcieve(response);
	}
}

namespace ns_http_client_async_ssl {
	inline void transcieve(const string& message) {
		cout << message;
	}

	inline void run(
		char const* mode,
		char const* payload,
		char const* host,
		char const* port,
		char const* target,
		int version)
	{
		ns_http_server_async_ssl::transcieve(
			payload,
			target
		);
	}

	inline int http_client_async_ssl(int argc, char* argv[]) {
		auto const mode = argv[1];
		auto const payload = argv[2];
		auto const host = argv[3];
		auto const port = argv[4];
		auto const target = argv[5];
		int version = argc == 7 && !std::strcmp("1.0", argv[6]) ? 10 : 11;

		run(
			mode,
			payload,
			host,
			port,
			target,
			version);

		return EXIT_SUCCESS;
	}
}

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
	const string& target,
	string& user_email_address,
	string& user_password,
	string& access_payload)
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

	access_payload =
		"email=" +
		user_email_address +
		"&password=" +
		user_password;
}
	
//****************************************************************************
//*                     get_access_params_from_user
//****************************************************************************
void get_access_params_from_user(
	string& target,
	string& user_email_address,
	string& user_password,
	string& access_payload)
{
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
			target = "/login";
			get_user_access_params(
				target,
				user_email_address,
				user_password,
				access_payload);
			bProceed = false;
			break;
		case 2:
			target = "/register";
			get_user_access_params(
				target,
				user_email_address,
				user_password,
				access_payload);
			bProceed = false;
			break;
		case 3:
			target = "/reset_password";
			get_user_access_params(
				target,
				user_email_address,
				user_password,
				access_payload);
			bProceed = false;
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
//*                     do_request
//****************************************************************************
void do_request(
	const string& request_mode,
	const string& access_payload,
	const string& ip_address,
	const string& port_number,
	const string& target_,
	const string& version_)
{
	char cmd[] = "http-client-async-ssl";
	char* mode = const_cast<char*>(request_mode.c_str());
	char* payload = const_cast<char*>(access_payload.c_str());
	char* host = const_cast<char*>(ip_address.c_str());
	char* port = const_cast<char*>(port_number.c_str());
	char* target = const_cast<char*>(target_.c_str());
	char* version = const_cast<char*>(version_.c_str());;

	int argc = 6;
	char* argv[] = { cmd, mode, payload, host, port, target, version };
	ns_http_client_async_ssl::http_client_async_ssl(argc, argv);
}

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	const string IP_ADDRESS = "192.168.178.14";
	const string PORT_NUMBER = "8080";
	const string TARGET = "login";
	const string HTTP_VERSION = "1.0";
	const string USER_EMAIL_ADDRESS = "guest@example.com";
	const string USER_PASSWORD = "anonymous";

	string ip_address = IP_ADDRESS;
	string port_number = PORT_NUMBER;
	string target = TARGET;
	string http_version = HTTP_VERSION;
	string user_email_address = USER_EMAIL_ADDRESS;
	string user_password = USER_PASSWORD;
	string request_mode = "access";
	string access_payload = "";

	get_access_params_from_user(
		target,
		user_email_address,
		user_password,
		access_payload
	);
	request_mode = "access";
	do_request(
		request_mode,
		access_payload,
		ip_address,
		port_number,
		target,
		http_version);

	return EXIT_SUCCESS;
}
