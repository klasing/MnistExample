// avoid HandlerForLogin: class type redefinition
#pragma once
class HandlerForLogin {
public:
	void handle_login(
		const std::string& user_email_address,
		const std::string& user_password,
		std::shared_ptr<Connect2SQLite> pSqlite,
		std::string& response_payload)
	{
		// check for registered user_email_address
		if (pSqlite->selectFromTable_(
			"user_email_address",
			user_email_address) == 0)
			;
		else {
			response_payload += "email address is unknown, try again.";
			return;
		}
		// check for correct user_password
		if (pSqlite->selectFromTable_(
			"user_email_address",
			user_email_address,
			"user_password",
			user_password) == 0)
		{
			response_payload += "succeeded.";
			return;
		}
		else {
			response_payload += "password is incorrect.";
			return;
		}
	}
};
//////////////////////////////////////////////////////////////////////////////
//// avoid HandlerForLogin: class type redefinition
//#pragma once
//
//#include <string>
//
//using namespace std;
////****************************************************************************
////*                     prototype
////****************************************************************************
//class Connect2SQLite;
//class HandlerForLogin {
//	int rc = 0;
//public:
//	int handle_login(
//		const string& user_email_address,
//		const string& user_password,
//		Connect2SQLite& oSqlite
//	) {
//		// check for registered user_email_address
//		if (rc = oSqlite.selectFromTable(
//			"user_email_address",
//			user_email_address) == -1) {
//			cout << "Email address is unknown, try again." << endl;
//			return rc;
//		}
//		// check for correct user_password
//		if (rc = oSqlite.selectFromTable(
//			"user_email_address",
//			user_email_address,
//			"user_password",
//			user_password) == -1) {
//			cout << "Password is incorrect." << endl;
//			return rc;
//		}
//
//		return rc;
//	}
//};
