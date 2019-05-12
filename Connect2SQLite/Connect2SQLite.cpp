#include <iostream>
#include <string>
#include <vector>

#include "CppSQLite3.h"

using namespace std;
class CompanyRecord {
public:
	void setId(const string& id) { this->id = id; }
	const string& getId() const { return id; }
	void setName(const string& name) { this->name = name; }
	const string& getName() const { return name; }
	void setAge(const string& age) { this->age = age; }
	const string& getAge() const { return age; }
	void setAddress(const string& address) { this->address = address; }
	const string& getAddress() const { return address; }
	void setSalary(const string& salary) { this->salary = salary; }
	const string& getSalary() const { return salary; }
private:
	string id, name, age, address, salary;
};

typedef void(*MessageHandler)(const string&);
typedef void(*DataHandler)(vector<CompanyRecord>&);

class Model {
public:
	void setHandler(MessageHandler messageHandler,
		DataHandler dataHandler) {
		this->messageHandler = messageHandler;
		this->dataHandler = dataHandler;
	}

	bool openDB() {
		bool success;
		string message;

		int rc = sqlite3_open(NAME_DB.c_str(), &db);
		if (rc) {
			// error opening the database
			success = false;
			message = "open " + NAME_DB + " failed: " + *sqlite3_errmsg(db);
		}
		else {
			// database is sucessfully opened
			success = true;
			message = "open " + NAME_DB + " succeeded";
		}
		messageHandler(message);
		return success;
	}
	void closeDB() const {
		sqlite3_close(db);
		messageHandler("close " + NAME_DB);
	}
	void dropTable() {
		sql = "DROP TABLE COMPANY;";
		execute("Table dropped successfully");
	}
	void createTable() {
		sql = "CREATE TABLE COMPANY(" \
			"ID      INT PRIMARY KEY NOT NULL," \
			"NAME    TEXT            NOT NULL," \
			"AGE     INT             NOT NULL," \
			"ADDRESS CHAR(50)," \
			"SALARY  REAL);";
		execute("Table created successfully");
	}
	void createRecord() {
		sql = "INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
			"VALUES (1, 'Paul', 32, 'California', 20000.00);" \
			"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
			"VALUES (2, 'Allen', 25, 'Texas', 15000.00);" \
			"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
			"VALUES (3, 'Teddy', 23, 'Norway', 20000.00);" \
			"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
			"VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";
		execute("Records created successfully");
	}
	void readRecord() {
		sql = "SELECT * FROM  COMPANY;";
		// callback method is called for each record
		execute("Operation done successfully");
		dataHandler(returnData);
	}
	void updateRecord() {
		sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;";
		execute("Operation done successfully");
	}
	void deleteRecord() {
		sql = "DELETE FROM COMPANY WHERE ID = 2;";
		execute("Operation done successfully");
	}
private:
	void execute(const string& msg) {
		char* pszErrMsg = 0;
		int rc;
		const char* data = "Callback function called";

		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

		if (rc != SQLITE_OK) {
			messageHandler("SQL error: " + static_cast<string>(pszErrMsg));
			sqlite3_free(pszErrMsg);
		}
		else
			messageHandler(msg.c_str());
	}
	static int callback(void* data, int argc, char** argv, char** aszColName) {
		CompanyRecord companyRecord;
		companyRecord.setId(static_cast<string>(argv[0]));
		companyRecord.setName(static_cast<string>(argv[1]));
		companyRecord.setAge(static_cast<string>(argv[2]));
		companyRecord.setAddress(static_cast<string>(argv[3]));
		companyRecord.setSalary(static_cast<string>(argv[4]));
		Model::returnData.push_back(companyRecord);
		return 0;
	}
private:
	const string NAME_DB = "test.db";
	MessageHandler messageHandler = nullptr;
	DataHandler dataHandler = nullptr;
	sqlite3* db;
	string sql;
	static vector<CompanyRecord> returnData;
};

vector<CompanyRecord> Model::returnData;

class View {
public:
	static void messageChange(const string& newMessage) {
		cout << newMessage << endl;
	}
	static void dataChange(vector<CompanyRecord>& newData) {
		for (auto it = newData.begin(); it < newData.end(); ++it) {
			cout << "ID........: " << it->getId() << endl;
			cout << "Name......: " << it->getName() << endl;
			cout << "Age.......: " << it->getAge() << endl;
			cout << "Address...: " << it->getAddress() << endl;
			cout << "Salary....: " << it->getSalary() << endl;
			cout << endl;
		}
	}
	void menuUserInput(Model& model) {
		int iChar;
		bool bProceed = true;

		while (bProceed) {
			cout << "SQLite database" << endl;
			cout << "===============" << endl;
			cout << " 1) Drop table" << endl;
			cout << " 2) Create table" << endl;
			cout << " 3) Create Record" << endl;
			cout << " 4) Read record" << endl;
			cout << " 5) Update record" << endl;
			cout << " 6) Delete record" << endl;
			cout << "Enter the number of a subject, or enter a zero to quit: ";

			cin >> iChar;

			switch (iChar) {
			case 1:
				model.dropTable();
				break;
			case 2:
				model.createTable();
				break;
			case 3:
				model.createRecord();
				break;
			case 4:
				model.readRecord();
				break;
			case 5:
				model.updateRecord();
				break;
			case 6:
				model.deleteRecord();
				break;
			case 0:
				model.closeDB();
				bProceed = false;
				break;
			default:
				// the input, given by the user, is not an available option
				cout << "The entered number is not recognized, please try again." << endl;
			} // eof switch
		}
	}
};

class Controller {
public:
	Controller(const Model& model, const View& view) :
		model(model), view(view) {}
	bool onLoad() {
		return model.openDB();
	}
	void processUserRequest() {
		view.menuUserInput(model);
	}
private:
	Model model;
	View view;
};

int main() {
	Model model;
	View view;
	model.setHandler(&View::messageChange, &View::dataChange);
	Controller controller(model, view);

	if (controller.onLoad()) {
		// database is sucessfully opened
		controller.processUserRequest();
	}
}
//////////////////////////////////////////////////////////////////////////////
/*
// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
//  1 - Rewritten with menu and function
//  2 - Rewritten SQLite callback function inside the class Company
#include "CppSQLite3.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
//static int callback(void* data, int argc, char** argv, char** aszColName) {
//	fprintf(stderr, "%s: ", (const char*)data);
//
//	for (int i = 0; i < argc; i++)
//		printf("%s - %s\n", aszColName[i], argv[i] ? argv[i] : "NULL");
//	printf("\n");
//	return 0;
//}

class Company {
public:
	static int callback(void* data, int argc, char** argv, char** aszColName) {
		fprintf(stderr, "%s: ", (const char*)data);

		for (int i = 0; i < argc; i++)
			printf("%s - %s\n", aszColName[i], argv[i] ? argv[i] : "NULL");
		printf("\n");
		return 0;
	}
};

void execute(sqlite3* db, const string& sql, const string& msg) {
	char* pszErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	//rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);
	rc = sqlite3_exec(db, sql.c_str(), Company::callback, (void*)data, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, msg.c_str());
}

void dropTable(sqlite3* db) {
	string sql;

	// Create SQL statement
	sql = "DROP TABLE COMPANY;";

	execute(db, sql, "Table dropped successfully\n");
}

void createTable(sqlite3* db) {
	string sql;

	// Create SQL statement
	sql = "CREATE TABLE COMPANY(" \
		"ID      INT PRIMARY KEY NOT NULL," \
		"NAME    TEXT            NOT NULL," \
		"AGE     INT             NOT NULL," \
		"ADDRESS CHAR(50)," \
		"SALARY  REAL);";

	execute(db, sql, "Table created successfully\n");
}

void createRecord(sqlite3* db) {
	string sql;

	// Create SQL statement
	sql = "INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (1, 'Paul', 32, 'California', 20000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (2, 'Allen', 25, 'Texas', 15000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (3, 'Teddy', 23, 'Norway', 20000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";

	execute(db, sql, "Records created successfully\n");
}

void readRecord(sqlite3* db) {
	string sql;

	// Create SQL statement
	sql = "SELECT * FROM  COMPANY;";

	execute(db, sql, "Operation done successfully\n");
}

void updateRecord(sqlite3* db) {
	string sql;

	// Create merged SQL statement
	sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;" \
		"SELECT * FROM  COMPANY;";

	execute(db, sql, "Operation done successfully\n");
}

void deleteRecord(sqlite3* db) {
	string sql;

	sql = "DELETE FROM COMPANY WHERE ID = 2;" \
		"SELECT * FROM  COMPANY;";

	execute(db, sql, "Operation done successfully\n");
}

int main() {
	sqlite3* db;
	int rc;
		
	// Open database
	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
		fprintf(stderr, "Opened database successfully\n");

	bool bProceed = true;
	int iChar;

	while (bProceed) {
		cout << "SQLite database" << endl;
		cout << "===============" << endl;
		cout << " 1) Drop table" << endl;
		cout << " 2) Create table" << endl;
		cout << " 3) Create record" << endl;
		cout << " 4) Read record" << endl;
		cout << " 5) Update record" << endl;
		cout << " 6) Delete record" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			dropTable(db);
			break;
		case 2:
			createTable(db);
			break;
		case 3:
			createRecord(db);
			break;
		case 4:
			readRecord(db);
			break;
		case 5:
			updateRecord(db);
			break;
		case 6:
			deleteRecord(db);
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
	// Close database
	sqlite3_close(db);
	fprintf(stderr, "Closed database successfully\n");
}
*/
//////////////////////////////////////////////////////////////////////////////
// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
// Protoype
//#include "CppSQLite3.h"
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//
//using namespace std;
//static int callback(void* data, int argc, char** argv, char** aszColName) {
//	fprintf(stderr, "%s: ", (const char*)data);
//
//	for (int i = 0; i < argc; i++)
//		printf("%s - %s\n", aszColName[i], argv[i] ? argv[i] : "NULL");
//	printf("\n");
//	return 0;
//}
//
//int main() {
//	sqlite3* db;
//	char* pszErrMsg = 0;
//	int rc;
//	//char* sql;
//	string sql;
//	const char* data = "Callback function called";
//
//	/* Open database */
//	rc = sqlite3_open("test.db", &db);
//
//	if (rc) {
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		return 0;
//	}
//	else
//		fprintf(stderr, "Opened database successfully\n");
//
//	// drop table ***************************************************************
//	/* Create SQL statement */
//	sql = "DROP TABLE COMPANY;";
//
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Table dropped successfully\n");
//
//	// create table *************************************************************
//	/* Create SQL statement */
//	sql = "CREATE TABLE COMPANY(" \
//		"ID      INT PRIMARY KEY NOT NULL," \
//		"NAME    TEXT            NOT NULL," \
//		"AGE     INT             NOT NULL," \
//		"ADDRESS CHAR(50)," \
//		"SALARY  REAL);";
//
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Table created successfully\n");
//
//	// create *******************************************************************
//	/* Create SQL statement */
//	sql = "INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
//		"VALUES (1, 'Paul', 32, 'California', 20000.00);" \
//		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
//		"VALUES (2, 'Allen', 25, 'Texas', 15000.00);" \
//		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
//		"VALUES (3, 'Teddy', 23, 'Norway', 20000.00);" \
//		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
//		"VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";
//
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Records created successfully\n");
//
//	// read *********************************************************************
//	/* Create SQL statement */
//	sql = "SELECT * FROM  COMPANY;";
//
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Operation done successfully\n");
//
//	// update *******************************************************************
//	/* Create merged SQL statement */
//	sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;" \
//		"SELECT * FROM  COMPANY;";
//
//	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Operation done successfully\n");
//
//	// delete *******************************************************************
//	/* Create merged SQL statement */
//	sql = "DELETE FROM COMPANY WHERE ID = 2;" \
//		"SELECT * FROM  COMPANY;";
//
//	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
//		sqlite3_free(pszErrMsg);
//	}
//	else
//		fprintf(stdout, "Operation done successfully\n");
//
//	sqlite3_close(db);
//}
