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
//*                     Connect2SQLite
//****************************************************************************
class Connect2SQLite {
	const int DATA_MAX = 128;
	sqlite3* db = nullptr;
	int rc = -1;
	string sql = "";
	char* data = new char[DATA_MAX];
	char* pszErrMsg = 0;
	vector<tuple_user_data> vector_user_data;
	int* pHighestKeyValue = new int(0);
public:
	int openDb() {
		// open database
		rc = sqlite3_open("http_server_async_ssl.db", &db);
		if (rc) {
			cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
			return EXIT_FAILURE;
		}
		else
			;// cout << "Database opened successfully." << endl;

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
			;// cout << "Table closed successfully." << endl;

		// clean up
		delete[] data;
		delete pHighestKeyValue;

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
		// no data will be returned from this SQL execution
		return execute(sql, nullptr);
	}
	int insertDefaultUser() {
		// insert into table
		sql =
			"INSERT INTO user_access_login_data(id, user_email_address, user_password) " \
			"VALUES (1, 'guest@example.com', 'anonymous');";
		strcpy_s(data, DATA_MAX, "insert default user");
		// no data will be returned from this SQL execution
		return execute(sql, nullptr);
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
		rc = execute(sql, &vector_user_data);
		if (vector_user_data.size() == 0) {
			//cout << "no data found in database" << endl;
			rc = -1;
		}
		else
			//show_data_in_vector();

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
		rc = execute(sql, &vector_user_data);
		if (vector_user_data.size() == 0) {
			//cout << "no data found in database" << endl;
			rc = -1;
		}
		else
			;// show_data_in_vector();

		return rc;
	}
	int insertRegisterUser(
		const string& user_email_address,
		const string& user_password
	)
	{
		sql = "SELECT max(ID) FROM user_access_login_data;";
		strcpy_s(data, DATA_MAX, "find max(ID)");
		// no data will be returned from this SQL execution
		// set the ariable that hold the highest key
		// for the callback
		rc = execute(sql, pHighestKeyValue);
		string key = to_string(++(*pHighestKeyValue));
		//cout << "max(ID): " << key << endl;

		// insert into table
		sql = string("INSERT INTO user_access_login_data(")
			+ "id, user_email_address, user_password) VALUES ("
			+ key
			+ ", '"
			+ user_email_address
			+ "', '"
			+ user_password
			+ "');";
		strcpy_s(data, DATA_MAX, "insert register user");
		// no data will be returned from this SQL execution
		return execute(sql, nullptr);

		return rc;
	}
	int updateUserPassword(
		const string& user_email_address,
		const string& user_password
	) {
		//sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;";
		sql = string("UPDATE user_access_login_data SET user_password = ")
			+ "'"
			+ user_password
			+ "'"
			+ " WHERE user_email_address = " 
			+ "'"
			+ user_email_address
			+ "'"
			+ ";";
		strcpy_s(data, DATA_MAX, "reset password");
		// no data will be returned from this SQL execution
		return execute(sql, nullptr);

		return rc;
	}
	private:
	// returns the description of a SQL execution
	const char* get_data() const { 
		return data;
	}
	int execute(const string& sql, const void* data) {
		// start every callback sequence with an empty vector
		vector_user_data.clear();
		int rc = sqlite3_exec(
			db,
			sql.c_str(),
			callback,
			(void*)data,
			&pszErrMsg
		);
		if (rc != SQLITE_OK) {
			cout << "SQL error: " << pszErrMsg << endl;
			sqlite3_free(pszErrMsg);
			return rc;
		}
		else
			// a description of the performed SQL execution
			;// cout << get_data() << endl;

		return rc;
	}
	static int
		callback(
			void* data,
			int argc,
			char** argv,
			char** aszColName)
	{
		string colName = *aszColName;
		if (colName == "max(ID)") {
			*(static_cast<int*>(data)) = stoi(argv[0]);
			return 0;
		}
		// store database tuple into a C++ tuple
		tuple_user_data new_tuple_user_data(
			static_cast<string>(argv[0]),
			static_cast<string>(argv[1]),
			static_cast<string>(argv[2])
		);
		// store C++ tuple into a vector
		static_cast<vector<tuple_user_data>*>(data)->
			push_back(new_tuple_user_data);
		return EXIT_SUCCESS;
	}
	void show_data_in_vector() {
		for (auto it = vector_user_data.begin();
			it < vector_user_data.end(); ++it) {
			tuple_user_data new_tuple_user_data = *it;
			cout << "ID.........: " << get<0>(new_tuple_user_data) << endl;
			cout << "Email......: " << get<1>(new_tuple_user_data) << endl;
			cout << "Password...: " << get<2>(new_tuple_user_data) << endl;
		}
	}
};
