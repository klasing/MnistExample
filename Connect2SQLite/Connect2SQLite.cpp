// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
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

int main() {
	sqlite3* db;
	char* pszErrMsg = 0;
	int rc;
	//char* sql;
	string sql;
	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
		fprintf(stderr, "Opened database successfully\n");

	// drop table ***************************************************************
	/* Create SQL statement */
	sql = "DROP TABLE COMPANY;";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Table dropped successfully\n");

	// create table *************************************************************
	/* Create SQL statement */
	sql = "CREATE TABLE COMPANY(" \
		"ID      INT PRIMARY KEY NOT NULL," \
		"NAME    TEXT            NOT NULL," \
		"AGE     INT             NOT NULL," \
		"ADDRESS CHAR(50)," \
		"SALARY  REAL);";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Table created successfully\n");

	// create *******************************************************************
	/* Create SQL statement */
	sql = "INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (1, 'Paul', 32, 'California', 20000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (2, 'Allen', 25, 'Texas', 15000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (3, 'Teddy', 23, 'Norway', 20000.00);" \
		"INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY) " \
		"VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Records created successfully\n");

	// read *********************************************************************
	/* Create SQL statement */
	sql = "SELECT * FROM  COMPANY;";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Operation done successfully\n");

	// update *******************************************************************
	/* Create merged SQL statement */
	sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;" \
		"SELECT * FROM  COMPANY;";

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Operation done successfully\n");

	// delete *******************************************************************
	/* Create merged SQL statement */
	sql = "DELETE FROM COMPANY WHERE ID = 2;" \
		"SELECT * FROM  COMPANY;";

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", pszErrMsg);
		sqlite3_free(pszErrMsg);
	}
	else
		fprintf(stdout, "Operation done successfully\n");

	sqlite3_close(db);
}
