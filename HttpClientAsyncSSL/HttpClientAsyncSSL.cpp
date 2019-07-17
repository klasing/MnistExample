// HttpClientAsyncSSL.cpp
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "http_client_async_ssl.cpp"

using namespace std;
//****************************************************************************
//*                     accessdata
//****************************************************************************
struct accessdata {
	string ip_address = "";
	string port_number = "";
	string http_version = "";
	string user_email_address = "";
	string user_password = "";
};

//****************************************************************************
//*                     global
//****************************************************************************
accessdata access_data;

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
//*                     get_connect_params_from_user
//****************************************************************************
void get_connect_params_from_user(
	string& ip_address,
	string& port_number,
	string& http_version,
	accessdata& access_data)
{
	const string HDR_IP_ADDRESS   = "IP Address";
	const string HDR_PORT_NUMBER  = "Port";
	const string HDR_HTTP_VERSION = "Http Version";

	//int width_header = HDR_HTTP_VERSION.length() + 3;
	int width_header = HDR_IP_ADDRESS.length();
	if (width_header < HDR_PORT_NUMBER.length())
		width_header = HDR_PORT_NUMBER.length();
	if (width_header < HDR_HTTP_VERSION.length())
		width_header = HDR_HTTP_VERSION.length();
	width_header += 3;
	//int width_value = ip_address.length();
	int width_value = ip_address.length();
	if (width_value < port_number.length())
		width_value = port_number.length();
	if (width_value < http_version.length())
		width_value = http_version.length();

	ip_address = get_input_from_user(
		HDR_IP_ADDRESS,
		width_header,
		ip_address,
		width_value
	);
	port_number = get_input_from_user(
		HDR_PORT_NUMBER,
		width_header,
		port_number,
		width_value
	);
	http_version = get_input_from_user(
		HDR_HTTP_VERSION,
		width_header,
		http_version,
		width_value
	);

	access_data.ip_address = ip_address;
	access_data.port_number = port_number;
	access_data.http_version = http_version;
}

//****************************************************************************
//*                     show_request_example
//****************************************************************************
void show_request_example(
	const string& access_mode,
	// the access_payload
	const string& post_request_urlencoded_string)
{
	string post_request = "";
	post_request =
		string("POST") +
		" " +
		access_mode +
		" " +
		"HTTP/1.0\r\n" +
		"Host: 192.168.178.14\r\n" +
		"User-Agent: " + BOOST_BEAST_VERSION_STRING + "\r\n" +
		"Content-Type: application/x-www-form-urlencoded\r\n" +
		"Content-Length: " + to_string(post_request_urlencoded_string.length()) + "\r\n" +
		"\r\n" +
		post_request_urlencoded_string + "\r\n" +
		"\r\n" +
		"\r\n";
	cout << post_request;
}

//****************************************************************************
//*                     get_user_access_params
//****************************************************************************
void get_user_access_params(
	const string& target,
	string& user_email_address,
	string& user_password,
	string& access_payload,
	accessdata& access_data)
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
	//show_request_example(
	//	target,
	//	access_payload);

	// place user_email_address and user_password
	// in a struct, so this data can be used elsewhere
	access_data.user_email_address = user_email_address;
	access_data.user_password = user_password;
}

//****************************************************************************
//*                     get_access_params_from_user
//****************************************************************************
void get_access_params_from_user(
	string& target,
	string& user_email_address,
	string& user_password,
	string& access_payload,
	accessdata& access_data)
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
				access_payload,
				access_data);
			bProceed = false;
			break;
		case 2:
			target = "/register";
			get_user_access_params(
				target,
				user_email_address,
				user_password,
				access_payload,
				access_data);
			bProceed = false;
			break;
		case 3:
			target = "/reset_password";
			get_user_access_params(
				target,
				user_email_address,
				user_password,
				access_payload,
				access_data);
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
	const string& target,
	const string& version)
{
	char cmd[] = "http-client-async-ssl";
	char* mode = const_cast<char*>(request_mode.c_str());
	char* payload = const_cast<char*>(access_payload.c_str());
	char* host = const_cast<char*>(ip_address.c_str());
	char* port = const_cast<char*>(port_number.c_str());
	char* target_ = const_cast<char*>(target.c_str());
	char* version_ = const_cast<char*>(version.c_str());;

	int argc = 6;
	char* argv[] = { cmd, mode, payload, host, port, target_, version_ };
	ns_http_client_async_ssl::http_client_async_ssl(argc, argv);
}

//****************************************************************************
//*                     get_confirmation_code
//****************************************************************************
void get_confirmation_code() {
	string confirmation_code;

	cout << "Enter the code received by email: ";
	cin >> confirmation_code;

	string request_mode = "access";
	string access_payload = 
		"email=" +
		access_data.user_email_address +
		"&password=" +
		access_data.user_password +
		"&code=" +
		confirmation_code;
	string ip_address = access_data.ip_address;		// "192.168.178.14";
	string port_number = access_data.port_number;	// "8080";
	string target = "/register_confirm";
	string http_version = access_data.http_version;	// "1.0";

	do_request(
		request_mode,
		access_payload,
		ip_address,
		port_number,
		target,
		http_version);
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

	// it's messy, but has to be for now
	access_data.ip_address = ip_address;
	access_data.port_number = port_number;
	access_data.http_version = http_version;

	bool bProceed = true;
	int iChar;

	while (bProceed) {
		cout << "Asynchronous HTTP Client SSL" << endl;
		cout << "============================" << endl;
		cout << " 1) Connect" << endl;
		cout << " 2) Access" << endl;
		cout << " 3) Download" << endl;
		cout << " 4) Upload" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;
		// get rid of the new line character, to ensure the buffer sanity
		cin.get();

		switch (iChar) {
		case 1:
			get_connect_params_from_user(
				ip_address,
				port_number,
				http_version,
				access_data
			);
			break;
		case 2:
			get_access_params_from_user(
				target,
				user_email_address,
				user_password,
				access_payload,
				access_data
			);
			request_mode = "access";
			do_request(
				request_mode,
				access_payload,
				ip_address, 
				port_number, 
				target, 
				http_version);
			break;
		case 3:
			break;
		case 4:
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

	return 0;
}

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
//}
