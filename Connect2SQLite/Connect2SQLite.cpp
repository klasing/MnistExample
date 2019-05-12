// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
// Rewritten with menu and function
#include "CppSQLite3.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
static int callback(void* data, int argc, char** argv, char** aszColName) {
	fprintf(stderr, "%s: ", (const char*)data);

	for (int i = 0; i < argc; i++)
		printf("%s - %s\n", aszColName[i], argv[i] ? argv[i] : "NULL");
	printf("\n");
	return 0;
}

void execute(sqlite3* db, const string& sql, const string& msg) {
	char* pszErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, msg.c_str());
}

void dropTable(sqlite3* db) {
	string sql;

	/* Create SQL statement */
	sql = "DROP TABLE COMPANY;";

	execute(db, sql, "Table dropped successfully\n");
}

void createTable(sqlite3* db) {
	string sql;

	/* Create SQL statement */
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

	/* Create SQL statement */
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

	/* Create SQL statement */
	sql = "SELECT * FROM  COMPANY;";

	execute(db, sql, "Operation done successfully\n");
}

void updateRecord(sqlite3* db) {
	string sql;

	/* Create merged SQL statement */
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
		
	/* Open database */
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
	/* Close database */
	sqlite3_close(db);
	fprintf(stderr, "Closed database successfully\n");
}
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
