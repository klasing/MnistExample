#include <string>

using namespace std;
//****************************************************************************
//*                     prototype
//****************************************************************************
class Connect2SQLite;
class HandlerForLogin {
public:
	int handle_login(
		const string& user_email_address,
		const string& user_password,
		Connect2SQLite& oSqlite
	) {
		return 0;
	}
};
