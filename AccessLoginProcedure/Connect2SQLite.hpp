#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <memory>

#include "CppSQLite3.h"

using namespace std;
//****************************************************************************
//*                     typedef
//****************************************************************************
typedef string id, user_email_address, user_password;
typedef tuple<id, user_email_address, user_password> tuple_user_data;
//****************************************************************************
//*                     intf_sqlite
//****************************************************************************
class Connect2SQLite {
	const int DATA_MAX = 128;

	sqlite3* db = nullptr;
	int rc = -1;
	string sql = "";
	char* data = new char[DATA_MAX];
	char* pszErrMsg = 0;
public:
	static vector<tuple_user_data> vector_user_data;
public:
	int openDb() {
		// open database
		rc = sqlite3_open("http_server_async_ssl.db", &db);
		if (rc) {
			cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
			return EXIT_FAILURE;
		}
		else
			cout << "Database opened successfully." << endl;

		return EXIT_SUCCESS;
	}
	int closeDb() {
		// close database
		rc = sqlite3_close(db);
		if (rc) {
			cout << "Error closing database: " << sqlite3_errmsg(db) << endl;
			return EXIT_FAILURE;
		}
		else
			cout << "Table closed successfully." << endl;

		// clean up
		delete[] data;
		return EXIT_SUCCESS;
	}
	int createTable() {
		// create table
		sql =
			"CREATE TABLE IF NOT EXISTS user_access_login_data(" \
			"id                 INT PRIMARY KEY NOT NULL," \
			"user_email_address TEXT NOT NULL UNIQUE," \
			"user_password      TEXT NOT NULL" \
			");";
		strcpy_s(data, DATA_MAX, "create table");
		return execute(sql, data);
	}
	int insertDefaultUser() {
		// insert into table
		sql =
			"INSERT INTO user_access_login_data(id, user_email_address, user_password) " \
			"VALUES (1, 'guest@example.com', 'anonymous');";
		strcpy_s(data, DATA_MAX, "insert default user");
		return execute(sql, data);
	}
	int selectFromTable(const string& colName, const string& value) {
		// select from table
		sql = string("SELECT * FROM user_access_login_data ")
			+ "WHERE "
			+ colName
			+ " = "
			+ "'" + value + "'"
			+ ";";
		strcpy_s(data, DATA_MAX, "select from table");
		rc = execute(sql, data);
		if (Connect2SQLite::vector_user_data.size() == 0)
			cout << "no data found in database" << endl;
		else
			show_data_in_vector();

		return rc;
	}
	int selectFromTable(
		const string& user_email_address, const string& user_email_address_value,
		const string& user_password, const string& user_password_value)
	{
		// select from table
		sql = string("SELECT * FROM user_access_login_data ")
			+ "WHERE "
			+ user_email_address
			+ " = "
			+ "'" + user_email_address_value + "'"
			+ " AND "
			+ user_password
			+ " = "
			+ "'" + user_password_value + "'"
			+ ";";
		strcpy_s(data, DATA_MAX, "select from table");
		rc = execute(sql, data);
		if (Connect2SQLite::vector_user_data.size() == 0)
			cout << "no data found in database" << endl;
		else
			show_data_in_vector();

		return rc;
	}
private:
	int execute(const string& sql, const void* data) {
		// start every callback sequence with an empty vector
		vector_user_data.clear();
		int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);
		if (rc != SQLITE_OK) {
			cout << "SQL error: " << pszErrMsg << endl;
			sqlite3_free(pszErrMsg);
			return rc;
		}
		else
			cout << (const char*)data << endl;

		return rc;
	}
	static int
		callback(
			void* data,
			int argc,
			char** argv,
			char** aszColName)
	{
		// store database tuple into a C++ tuple
		tuple_user_data new_tuple_user_data(
			static_cast<string>(argv[0]),
			static_cast<string>(argv[1]),
			static_cast<string>(argv[2])
		);
		// store C++ tuple into a vector
		Connect2SQLite::vector_user_data.push_back(new_tuple_user_data);

		return EXIT_SUCCESS;
	}
	void show_data_in_vector() {
		for (auto it = Connect2SQLite::vector_user_data.begin();
			it < Connect2SQLite::vector_user_data.end(); ++it) {
			tuple_user_data new_tuple_user_data = *it;
			cout << "ID.........: " << get<0>(new_tuple_user_data) << endl;
			cout << "Email......: " << get<1>(new_tuple_user_data) << endl;
			cout << "Password...: " << get<2>(new_tuple_user_data) << endl;
		}
	}
};
vector<tuple_user_data> Connect2SQLite::vector_user_data;

