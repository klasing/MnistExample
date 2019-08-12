#include <iomanip>
#include <conio.h>
#include <ctime>
#include <sstream>

#include "http_client_async.cpp"

//****************************************************************************
//*                     global
//****************************************************************************
typedef struct STRUCT_ACCESSDATA
{
	std::string mode = "";
	std::string user_email_address = "";
	std::string user_password = "";
	std::string payload = "";
	std::string file_name_on_server = "";
	std::string file_name_on_client = "";
	std::string target = "";
	std::string host = "";
	std::string port = "";
	std::string version = "";
	bool logged_in = false;
} ACCESSDATA, * PACCESSDATA;
ACCESSDATA g_access_data;

//****************************************************************************
//*                     prototype
//****************************************************************************
void do_transfer(const ACCESSDATA&);

//****************************************************************************
//*                     get_string_from_user
//****************************************************************************
bool get_string_from_user(
	std::string& input_from_user,
	const bool& echo_character)
{
	char substitute_character = '*';
	char ch = '\0';

	while ((ch = _getch()) != 13) {
		if (ch == 27) {
			std::cout << std::endl;
			// escape character entered
			return true;
		}

		if (echo_character)
			std::cout << ch;
		else
			std::cout << substitute_character;

		input_from_user += ch;
	}
	std::cout << std::endl;
	// no escape character entered
	return false;
}

//****************************************************************************
//*                     get_input_from_user
//****************************************************************************
std::string get_input_from_user(
	const std::string& hdr,
	const int& width_header,
	const std::string& val,
	const int& width_value,
	bool& escape_given,
	const bool& echo_character = true)
{
	std::string substitute_for_user_password = "";
	substitute_for_user_password.insert(0, val.length(), '*');

	std::string input_from_user = "";

	std::cout << std::setw(width_header)
		<< std::setiosflags(std::ios_base::left)
		<< std::setfill('.')
		<< hdr
		<< std::setw(width_value)
		<< std::setiosflags(std::ios_base::right)
		<< std::setfill('.')
		<< ((echo_character) ? val : substitute_for_user_password)
		<< ": ";
	std::cout.unsetf(std::ios::adjustfield);

	escape_given =
		get_string_from_user(input_from_user, echo_character);

	return input_from_user.length() > 0 ? input_from_user : val;
}

//****************************************************************************
//*                     get_connect_params_from_user
//****************************************************************************
bool get_connect_params_from_user(ACCESSDATA& access_data)
{
	const std::string HDR_HOST = "Host";
	const std::string HDR_PORT = "Port";
	const std::string HDR_VERSION = "Version";

	int width_header = (HDR_HOST > HDR_PORT)
		? HDR_HOST.length()
		: (HDR_PORT > HDR_VERSION)
		? HDR_PORT.length()
		: HDR_VERSION.length();
	width_header += 3;

	int width_value = (access_data.host.length() > access_data.port.length())
		? access_data.host.length()
		: (access_data.port.length() > access_data.version.length())
		? access_data.port.length()
		: access_data.version.length();

	bool escape_given;
	access_data.host = get_input_from_user(
		HDR_HOST,
		width_header,
		access_data.host,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	access_data.port = get_input_from_user(
		HDR_PORT,
		width_header,
		access_data.port,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	access_data.version = get_input_from_user(
		HDR_VERSION,
		width_header,
		access_data.version,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	return true;
}

//****************************************************************************
//*                     get_access_params_from_user
//****************************************************************************
bool get_access_params_from_user(ACCESSDATA& access_data)
{
	const std::string HDR_USER_EMAIL_ADDRESS = "Email";
	const std::string HDR_USER_PASSWORD = "Password";

	int width_header =
		(HDR_USER_EMAIL_ADDRESS.length() > HDR_USER_PASSWORD.length())
		? HDR_USER_EMAIL_ADDRESS.length()
		: HDR_USER_PASSWORD.length();
	width_header += 3;

	int width_value = (access_data.user_email_address.length() > access_data.user_password.length())
		? access_data.user_email_address.length()
		: access_data.user_password.length();

	bool escape_given;
	access_data.user_email_address = get_input_from_user(
		HDR_USER_EMAIL_ADDRESS,
		width_header,
		access_data.user_email_address,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	access_data.user_password = get_input_from_user(
		HDR_USER_PASSWORD,
		width_header,
		access_data.user_password,
		width_value,
		escape_given,
		false // do not echo character
	);
	if (escape_given)
		return false;

	access_data.payload =
		"user_email_address=" +
		access_data.user_email_address +
		"&user_password=" +
		access_data.user_password;

	return true;
}

//****************************************************************************
//*                     get_user_access_params
//****************************************************************************
bool get_user_access_params(ACCESSDATA& access_data)
{
	bool bProceed = true;
	int iChar;

	while (bProceed) {
		std::cout << "Access\n";
		std::cout << "======\n";
		std::cout << " 1) Login\n";
		std::cout << " 2) Register\n";
		std::cout << " 3) Forgot password\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";

		std::cin >> iChar;
		// get rid of the new line character, to ensure the buffer sanity
		std::cin.get();

		switch (iChar) {
		case 1:
			access_data.target = "/login";
			if (get_access_params_from_user(g_access_data))
				do_transfer(g_access_data);
			break;
		case 2:
			access_data.target = "/register";
			if (get_access_params_from_user(g_access_data))
				do_transfer(g_access_data);
			break;
		case 3:
			access_data.target = "/reset_password";
			if (get_access_params_from_user(g_access_data))
				do_transfer(g_access_data);
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
	return true;
}

//****************************************************************************
//*                     get_file_names_from_user
//****************************************************************************
bool get_file_names_from_user(ACCESSDATA& access_data)
{
	std::string HDR_FILE_NAME_ON_SERVER = "";
	std::string HDR_FILE_NAME_ON_CLIENT = "";

	if (access_data.mode == "download") {
		HDR_FILE_NAME_ON_SERVER = "Target (server)";
		HDR_FILE_NAME_ON_CLIENT = "Destination (client)";
	}
	if (access_data.mode == "upload") {
		HDR_FILE_NAME_ON_SERVER = "Destination (server)";
		HDR_FILE_NAME_ON_CLIENT = "Target (client)";
	}

	int width_header = (HDR_FILE_NAME_ON_SERVER.length()
		>= HDR_FILE_NAME_ON_CLIENT.length())
		? HDR_FILE_NAME_ON_SERVER.length()
		: HDR_FILE_NAME_ON_CLIENT.length();
	width_header += 3;

	int width_value = (access_data.file_name_on_server.length()
		>= access_data.file_name_on_client.length())
		? access_data.file_name_on_server.length()
		: access_data.file_name_on_client.length();

	bool escape_given;
	access_data.file_name_on_server = get_input_from_user(
		HDR_FILE_NAME_ON_SERVER,
		width_header,
		access_data.file_name_on_server,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	access_data.file_name_on_client = get_input_from_user(
		HDR_FILE_NAME_ON_CLIENT,
		width_header,
		access_data.file_name_on_client,
		width_value,
		escape_given
	);
	if (escape_given)
		return false;

	return true;
}

//****************************************************************************
//*                     do_transfer
//****************************************************************************
void do_transfer(const ACCESSDATA& access_data)
{
	std::cout << "do_transfer()\n";

	char cmd[] = "http-client-async";
	char* mode = const_cast<char*>(access_data.mode.c_str());
	char* user_email_address = const_cast<char*>(access_data.user_email_address.c_str());
	char* user_password = const_cast<char*>(access_data.user_password.c_str());
	char* payload = const_cast<char*>(access_data.payload.c_str());
	char* file_name_on_server = const_cast<char*>(access_data.file_name_on_server.c_str());
	char* file_name_on_client = const_cast<char*>(access_data.file_name_on_client.c_str());
	char* target = const_cast<char*>(access_data.target.c_str());
	char* host = const_cast<char*>(access_data.host.c_str());
	char* port = const_cast<char*>(access_data.port.c_str());
	char* version = const_cast<char*>(access_data.version.c_str());

	int argc = 11;
	char* argv[] = {
		cmd,
		mode,
		user_email_address,
		user_password,
		payload,
		file_name_on_server,
		file_name_on_client,
		target,
		host,
		port,
		version
	};
	http_client_async(argc, argv);
}

//****************************************************************************
//*                     set_loggd_in
//****************************************************************************
void set_logged_in(const bool& logged_in)
{
	g_access_data.logged_in = logged_in;
}

//****************************************************************************
//*                     get_confirmation_code
//****************************************************************************
void get_confirmation_code()
{
	std::string confirmation_code;

	std::cout << "Enter the code received by email: ";
	std::cin >> confirmation_code;

	g_access_data.mode = "access";
	g_access_data.target += "_confirm";
	g_access_data.payload =
		"user_email_address=" +
		g_access_data.user_email_address +
		"&user_password=" +
		g_access_data.user_password +
		"&confirmation_code=" +
		confirmation_code;

	do_transfer(g_access_data);
}

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	const std::string MODE = "download";
	const std::string USER_EMAIL_ADDRESS = "guest@example.com";
	const std::string USER_PASSWORD = "anonymous";
	const std::string PAYLOAD = "";
	const std::string FILE_NAME_ON_SERVER = "";
	const std::string FILE_NAME_ON_CLIENT = "index.html";
	const std::string TARGET = "/";
	const std::string HOST = "192.168.178.14";
	const std::string PORT = "8080";
	const std::string VERSION = "1.1";

	g_access_data.mode = MODE;
	g_access_data.user_email_address = USER_EMAIL_ADDRESS;
	g_access_data.user_password = USER_PASSWORD;
	g_access_data.payload = PAYLOAD;
	g_access_data.file_name_on_server = FILE_NAME_ON_SERVER;
	g_access_data.file_name_on_client = FILE_NAME_ON_CLIENT;
	g_access_data.target = TARGET;
	g_access_data.host = HOST;
	g_access_data.port = PORT;
	g_access_data.version = VERSION;

	// testing for a connection, by sending a TRACE message
	g_access_data.mode = "trace";
	do_transfer(g_access_data);

	bool bProceed = true;
	int iChar;

	while (bProceed) {
		std::cout << "HTTP Client Async\n";
		std::cout << "=================\n";
		std::cout << " 1) Connect\n";
		std::cout << " 2) Access\n";
		std::cout << " 3) Download\n";
		std::cout << " 4) Upload\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";

		std::cin >> iChar;
		// get rid of the new line character, to ensure the buffer sanity
		std::cin.get();

		switch (iChar) {
		case 1:
			get_connect_params_from_user(g_access_data);
			break;
		case 2:
			g_access_data.mode = "access";
			get_user_access_params(g_access_data);
			// reset target
			g_access_data.target = TARGET;
			break;
		case 3:
			if (!g_access_data.logged_in) {
				std::cout << "please login first\n";
				break;
			}
			g_access_data.mode = "download";
			if (get_file_names_from_user(g_access_data))
				do_transfer(g_access_data);
			break;
		case 4:
			if (!g_access_data.logged_in) {
				std::cout << "please login first\n";
				break;
			}
			g_access_data.mode = "upload";
			if (get_file_names_from_user(g_access_data))
				do_transfer(g_access_data);
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
	return EXIT_SUCCESS;
}