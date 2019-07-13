#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <random>

#include "SmtpClient.cpp"
#include "Connect2SQLite.hpp"
#include "HandlerForLogin.hpp"
#include "HandlerForRegister.hpp"
#include "HandlerForResetPassword.hpp"

using namespace std;
//****************************************************************************
//*                     generate_random_string
//****************************************************************************
inline string
generate_random_string()
{
	const int RANDOM_CHARACTER_MAX = 16;
	string random_string = "";
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(65, 90);
	for (int i = 0; i < RANDOM_CHARACTER_MAX; i++)
		random_string += dist(eng);
	return random_string;
}
//****************************************************************************
//*                     get_string_from_user
//****************************************************************************
void get_string_from_user(
	string& input_from_user,
	const bool& echo_character = true)
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
//*                     get_access_params_from_user
//****************************************************************************
void get_access_params_from_user(
	string& target,
	string& user_email_address,
	string& user_password,
	Connect2SQLite& oSqlite)
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
		case 1: {
			target = "/login";
			get_user_access_params(
				user_email_address,
				user_password);
			HandlerForLogin handlerForLogin;
			if (handlerForLogin.handle_login(
				user_email_address,
				user_password,
				oSqlite) == 0)
				cout << "login succeeded" << endl;
			bProceed = false;
			break;
		} // case 1
		case 2: {
			target = "/register";
			get_user_access_params(
				user_email_address,
				user_password);
			HandlerForRegister handlerForRegister;
			if (handlerForRegister.handle_register(
				user_email_address,
				user_password,
				oSqlite) == 0)
				cout << "register successfull" << endl;
			bProceed = false;
			break;
		} // case 2
		case 3: {
			target = "/reset_password";
			get_user_access_params(
				user_email_address,
				user_password);
			// a user can't reset the password of the default user
			if (user_email_address == "guest@example.com") {
				cout << "You can not reset the password from the default user" << endl;
				return;
			}
			HandlerForResetPassword handlerForResetPassword;
			if (handlerForResetPassword.handle_reset_password(
				user_email_address,
				user_password,
				oSqlite) == 0)
				cout << "reset password succeeded" << endl;
			bProceed = false;
			break;
		} // case 3
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
// testing for login
// testing register user
// testing for reset password
int main() {
	Connect2SQLite oSqlite;
	// open database
	oSqlite.openDb();

	const string TARGET = "login";
	const string USER_EMAIL_ADDRESS = "guest@example.com";
	const string USER_PASSWORD = "anonymous";

	string target = TARGET;
	string user_email_address = USER_EMAIL_ADDRESS;
	string user_password = USER_PASSWORD;

	get_access_params_from_user(
		target,
		user_email_address,
		user_password,
		oSqlite
	);

	// close database
	oSqlite.closeDb();

	return EXIT_SUCCESS;
}

//****************************************************************************
//*                     main
//****************************************************************************
// testing register user
//int main() {
//	Connect2SQLite oSqlite;
//	// open database
//	oSqlite.openDb();
//
//	const string TARGET = "login";
//	const string USER_EMAIL_ADDRESS = "guest@example.com";
//	const string USER_PASSWORD = "anonymous";
//
//	string target = TARGET;
//	string user_email_address = USER_EMAIL_ADDRESS;
//	string user_password = USER_PASSWORD;
//
//	get_access_params_from_user(
//		target,
//		user_email_address,
//		user_password,
//		oSqlite
//	);
//
//	// close database
//	oSqlite.closeDb();
//
//	return EXIT_SUCCESS;
//}

//****************************************************************************
//*                     main
//****************************************************************************
// #include "Connect2SQLite.hpp"

// testing the SQLite database
//int main() {
//  Connect2SQLite oSqlite;
//
//  oSqlite.openDb();
//  oSqlite.createTable();
//  oSqlite.insertDefaultUser();
//
//  oSqlite.selectFromTable("user_email_address", "guest@example.com");
//  // will fail, user not present
//  oSqlite.selectFromTable("user_email_address", "klasing1159@gmail.com");
//
//  oSqlite.selectFromTable(
//      "user_email_address", "guest@example.com",
//      "user_password", "anonymous");
//  // will fail, incorrect password for the given user
//  oSqlite.selectFromTable(
//      "user_email_address", "guest@example.com",
//      "user_password", "wrong password");
//
//  // testing max(ID), retrieving the highest key value from the database
//  oSqlite.insertRegisterUser(
//	  "klasing1159@gmail.com",
//	  "boost"
//  );
//  oSqlite.selectFromTable("user_email_address", "klasing1159@gmail.com");
//
//  oSqlite.closeDb();
//
//  return EXIT_SUCCESS;
//}
