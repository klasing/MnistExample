#include <string>

using namespace std;
//****************************************************************************
//*                     prototype
//****************************************************************************
inline string generate_random_string();
class Connect2SQLite;
class HandlerForRegister {
	int rc = -1;
public:
	int handle_register(
		const string& user_email_address,
		const string& user_password,
		Connect2SQLite& oSqlite
	) {
		// check for registered user_email_address
		if (rc = oSqlite.selectFromTable(
			"user_email_address",
			user_email_address) == 0) {
			cout << "Email address is already registered, try a different email address." << endl;
			return rc;
		}
		// generate random string
		string generated_code = generate_random_string();
		string message_with_code = "code " + generated_code;
		string code_received_from_user;

		// send generated string from klasingsmtp@gmail.com
		// to user_email_address of register user
		smtp_client(
			"klasingsmtp@gmail.com",
			user_email_address,
			"klasingsmtp@gmail.com",
			user_email_address,
			"no subject",
			message_with_code);

		cout << "Enter the code received by email: ";
		cin >> code_received_from_user;

		// verify code given by user with generated string
		if (code_received_from_user == generated_code)
			oSqlite.insertRegisterUser(
				user_email_address,
				user_password
			);

		return 0;
	}
};