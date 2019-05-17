
// SQlite prepared statement, look at:
// https://stackoverflow.com/questions/31745465/how-to-prepare-sql-statements-and-bind-parameters#
// command line interface (CLI) for SQLite, look at:
// https://sqlite.org/cli.html
// http://www.sqlitetutorial.net/sqlite-commands/
// Rewritten for a templated dataChange() method in the View object
// method is now named dataChangeEx()

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "CppSQLite3.h"

using namespace std;

typedef void(*MessageHandler)(const string&);

typedef string key, name, age, address, salary;
typedef tuple<key, name, age, address, salary> tuple_company;
typedef void(*DataHandler)(vector<tuple_company>&);

typedef string contact_id, first_name, last_name, email, phone, group_id, name;
typedef tuple<contact_id, first_name, last_name, email, phone, group_id, name> tuple_contact;
typedef void(*DataHandlerContact)(vector<tuple_contact>&);

//****************************************************************************
//*                     Model
//****************************************************************************
class Model {
public:
	void setHandler(MessageHandler messageHandler, DataHandler dataHandler,
		DataHandlerContact dataHandlerContact) {
		this->messageHandler = messageHandler;
		this->dataHandler = dataHandler;
		this->dataHandlerContact = dataHandlerContact;
	}
	//const string& getNameDb() const { return Model::NAME_DB; }

	bool openDB() {
		bool success;
		string message;

		int rc = sqlite3_open(Model::NAME_DB.c_str(), &db);
		if (rc) {
			// error opening the database
			success = false;
			message = "open " + Model::NAME_DB + " failed: " + *sqlite3_errmsg(db);
		}
		else {
			// database is sucessfully opened
			success = true;
			message = "open " + Model::NAME_DB + " succeeded";
		}
		messageHandler(message);
		return success;
	}

	void closeDB() const {
		sqlite3_close(db);
		messageHandler("close " + Model::NAME_DB);
	}
	void dropTable() {
		if (Model::NAME_DB == "company.db") {
			sql = "DROP TABLE COMPANY;";
			execute("Table dropped successfully");
		}
		if (Model::NAME_DB == "contact.db") {
			sql = "DROP TABLE CONTACTS;";
			execute("Table dropped successfully");
			sql = "DROP TABLE GROUPS;";
			execute("Table dropped successfully");
			sql = "DROP TABLE CONTACT_GROUPS;";
			execute("Table dropped successfully");
		}

	}
	void createTable() {
		if (Model::NAME_DB == "company.db") {
			sql = "CREATE TABLE COMPANY(" \
				"ID      INT PRIMARY KEY NOT NULL," \
				"NAME    TEXT            NOT NULL," \
				"AGE     INT             NOT NULL," \
				"ADDRESS CHAR(50)," \
				"SALARY  REAL);";
			execute("Table created successfully");
		}
		if (Model::NAME_DB == "contact.db") {
			sql = R"~(CREATE TABLE contacts(
				contact_id INTEGER PRIMARY KEY,
				first_name TEXT NOT NULL,
				last_name  TEXT NOT NULL,
				email text NOT NULL UNIQUE,
				phone text NOT NULL UNIQUE
				);)~";
			execute("Table created successfully");
			sql = R"~(CREATE TABLE groups(
				group_id integer PRIMARY KEY,
				name     text NOT NULL
				);)~";
			execute("Table created successfully");
			sql = R"~(CREATE TABLE contact_groups(
				contact_id integer,
				group_id integer,
				PRIMARY KEY (contact_id, group_id),
				FOREIGN KEY (contact_id) REFERENCES contacts (contact_id)
				ON DELETE CASCADE ON UPDATE NO ACTION,
				FOREIGN KEY (group_id) REFERENCES groups (group_id)
				ON DELETE CASCADE ON UPDATE NO ACTION
				);)~";
			execute("Table created successfully");
		}
	}
	void createRecord() {
		if (Model::NAME_DB == "company.db") {
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
		if (Model::NAME_DB == "contact.db") {
			sql = R"~(INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1001, 'Paul', 'Blake', 'paul.blake@wemail.com', '1234567890');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1011, 'Allen', 'Wood', 'allen_wood@mail4me.com', '9876543210');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1013, 'Teddy', 'Hammersmith', 't.hammersmith@hotmail.us', '6513013229');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1021, 'Mark', 'Gold', 'markgold@provider.dk', '6379981234');)~";
			execute("Records created successfully");
			sql = R"~(INSERT INTO groups(group_id, name) 
				VALUES(10, 'Friend');
				INSERT INTO groups(group_id, name) 
				VALUES(30, 'Family');
				INSERT INTO groups(group_id, name) 
				VALUES(70, 'Acquaintance');)~";
			execute("Records created successfully");
			sql = R"~(INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1001, 10);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1001, 30);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1011, 10);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1013, 30);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1021, 70);)~";
			execute("Records created successfully");
		}
	}
	void readRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "SELECT * FROM COMPANY;";
			// callback method is called for each record
			execute("Operation done successfully");
			dataHandler(returnData);
		}
		if (Model::NAME_DB == "contact.db") {
			//sql = R"~(SELECT * FROM CONTACTS;)~";
			sql = R"~(SELECT c.*, g.* FROM contacts c
				JOIN contact_groups cg ON cg.contact_id = c.contact_id
				JOIN groups g ON cg.group_id = g.group_id;)~";
			// callback method is called for each record
			execute("Operation done successfully");
			dataHandlerContact(returnDataContact);
		}
	}
	void updateRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;";
			execute("Operation done successfully");
		}
		if (Model::NAME_DB == "contact.db") {
		}
	}
	void deleteRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "DELETE FROM COMPANY WHERE ID = 2;";
			execute("Operation done successfully");
		}
		if (Model::NAME_DB == "contact.db") {
		}
	}
private:
	void execute(const string & msg) {
		char* pszErrMsg = 0;
		int rc;
		const char* data = "Callback function called";

		// clear vector preceding callback
		returnData.clear();
		returnDataContact.clear();

		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

		if (rc != SQLITE_OK) {
			messageHandler("SQL error: " + static_cast<string>(pszErrMsg));
			sqlite3_free(pszErrMsg);
		}
		else
			messageHandler(msg.c_str());
	}
	static int callback(void* data, int argc, char** argv, char** aszColName) {
		if (Model::NAME_DB == "company.db") {
			tuple_company newTuple(static_cast<string>(argv[0]),
				static_cast<string>(argv[1]),
				static_cast<string>(argv[2]),
				static_cast<string>(argv[3]),
				static_cast<string>(argv[4]));
			Model::returnData.push_back(newTuple);
		}
		if (Model::NAME_DB == "contact.db") {
			tuple_contact newTuple(static_cast<string>(argv[0]),
				static_cast<string>(argv[1]),
				static_cast<string>(argv[2]),
				static_cast<string>(argv[3]),
				static_cast<string>(argv[4]),
				static_cast<string>(argv[5]),
				static_cast<string>(argv[6]));
			Model::returnDataContact.push_back(newTuple);
		}
		return 0;
	}
public:
	//static const string NAME_DB;
	static string NAME_DB;
private:
	MessageHandler messageHandler = nullptr;
	DataHandler dataHandler = nullptr;
	DataHandlerContact dataHandlerContact = nullptr;
	sqlite3* db;
	string sql;
	static vector<tuple_company> returnData;
	static vector<tuple_contact> returnDataContact;
};
//const string Model::NAME_DB = "company.db";
//const string Model::NAME_DB = "contact.db";
string Model::NAME_DB = "";
vector<tuple_company> Model::returnData;
vector<tuple_contact> Model::returnDataContact;

//****************************************************************************
//*                     View
//****************************************************************************
class View {
public:
	static void messageChange(const string& newMessage) {
		cout << newMessage << endl;
	}
	//static void dataChange(vector<tuple_company>& newData) {
	//	for (auto it = newData.begin(); it < newData.end(); ++it) {
	//		tuple_company newTuple = *it;
	//		cout << "ID........: " << get<0>(newTuple) << endl;
	//		cout << "Name......: " << get<1>(newTuple) << endl;
	//		cout << "Age.......: " << get<2>(newTuple) << endl;
	//		cout << "Address...: " << get<3>(newTuple) << endl;
	//		cout << "Salary....: " << get<4>(newTuple) << endl;
	//		cout << endl;
	//	}
	//}
	//static void dataChangeContact(vector<tuple_contact>& newData) {
	//	for (auto it = newData.begin(); it < newData.end(); ++it) {
	//		tuple_contact newTuple = *it;
	//		cout << "ID...........: " << get<0>(newTuple) << endl;
	//		cout << "First name...: " << get<1>(newTuple) << endl;
	//		cout << "Last name....: " << get<2>(newTuple) << endl;
	//		cout << "email........: " << get<3>(newTuple) << endl;
	//		cout << "phone........: " << get<4>(newTuple) << endl;
	//		cout << "Group ID.....: " << get<5>(newTuple) << endl;
	//		cout << "Group........: " << get<6>(newTuple) << endl;
	//		cout << endl;
	//	}
	//}
	template <typename T>
	static void dataChangeEx(vector<T>& newData) {
		if (typeid(newData) == typeid(vector<tuple_company>)) {
			for (auto it = newData.begin(); it < newData.end(); ++it) {
				tuple_company newTuple = *it;
				cout << "ID........: " << get<0>(newTuple) << endl;
				cout << "Name......: " << get<1>(newTuple) << endl;
				cout << "Age.......: " << get<2>(newTuple) << endl;
				cout << "Address...: " << get<3>(newTuple) << endl;
				cout << "Salary....: " << get<4>(newTuple) << endl;
				cout << endl;
			}
			return;
		}
		if (typeid(newData) == typeid(vector<tuple_contact>)) {
			for (auto it = newData.begin(); it < newData.end(); ++it) {
				tuple_contact newTuple = *it;
				cout << "ID...........: " << get<0>(newTuple) << endl;
				cout << "First name...: " << get<1>(newTuple) << endl;
				cout << "Last name....: " << get<2>(newTuple) << endl;
				cout << "email........: " << get<3>(newTuple) << endl;
				cout << "phone........: " << get<4>(newTuple) << endl;
				cout << "Group ID.....: " << get<5>(newTuple) << endl;
				cout << "Group........: " << get<6>(newTuple) << endl;
				cout << endl;
			}
			return;
		}
	}
	bool menuSchemaRequest(Model& model) {
		int iChar;
		bool bProceed = true;
		bool bContinueApp = true;

		while (bProceed) {
			cout << "SQLite schema" << endl;
			cout << "=============" << endl;
			cout << " 1) Company" << endl;
			cout << " 2) Contact" << endl;
			cout << "Enter the number of a subject, or enter a zero to quit: ";
			cin >> iChar;

			switch (iChar) {
			case 1:
				Model::NAME_DB = "company.db";
				bProceed = false;
				bContinueApp = true;
				break;
			case 2:
				Model::NAME_DB = "contact.db";
				bProceed = false;
				bContinueApp = true;
				break;
			case 0:
				// the user wants to quit
				bProceed = false;
				bContinueApp = false;
				break;
			default:
				// the input, given by the user, is not an available option
				cout << "The entered number is not recognized, please try again." << endl;
			} // eof switch
		}
		return bContinueApp;
	}
	void menuUserRequest(Model& model) {
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

//****************************************************************************
//*                     Controller
//****************************************************************************
class Controller {
public:
	Controller(const Model& model, const View& view) :
		model(model), view(view) {}
	bool processSchemaRequest() {
		return view.menuSchemaRequest(model);
	}
	bool onLoad() {
		return model.openDB();
	}
	void processUserRequest() {
		view.menuUserRequest(model);
	}
private:
	Model model;
	View view;
};

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	Model model;
	View view;
	//model.setHandler(&View::messageChange, &View::dataChange,
	//	&View::dataChangeContact);
	model.setHandler(&View::messageChange, &View::dataChangeEx,
		&View::dataChangeEx);
	Controller controller(model, view);

	if (!controller.processSchemaRequest())
		// user wants to quit
		return 0;

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
// Look at, for the contact database construction:
// http://www.sqlitetutorial.net/sqlite-create-table/
//  1 - Rewritten to access the contact batabase
//  2 - Using raw string for declaring sql statement
//  3 - Rewritten to let user choose schema

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "CppSQLite3.h"

using namespace std;

typedef void(*MessageHandler)(const string&);

typedef string key, name, age, address, salary;
typedef tuple<key, name, age, address, salary> tuple_company;
typedef void(*DataHandler)(vector<tuple_company>&);

typedef string contact_id, first_name, last_name, email, phone, group_id, name;
typedef tuple<contact_id, first_name, last_name, email, phone, group_id, name> tuple_contact;
typedef void(*DataHandlerContact)(vector<tuple_contact>&);


//****************************************************************************
//*                     Model
//****************************************************************************
class Model {
public:
	void setHandler(MessageHandler messageHandler, DataHandler dataHandler,
		DataHandlerContact dataHandlerContact) {
		this->messageHandler = messageHandler;
		this->dataHandler = dataHandler;
		this->dataHandlerContact = dataHandlerContact;
	}
	//const string& getNameDb() const { return Model::NAME_DB; }

	bool openDB() {
		bool success;
		string message;

		int rc = sqlite3_open(Model::NAME_DB.c_str(), &db);
		if (rc) {
			// error opening the database
			success = false;
			message = "open " + Model::NAME_DB + " failed: " + *sqlite3_errmsg(db);
		}
		else {
			// database is sucessfully opened
			success = true;
			message = "open " + Model::NAME_DB + " succeeded";
		}
		messageHandler(message);
		return success;
	}

	void closeDB() const {
		sqlite3_close(db);
		messageHandler("close " + Model::NAME_DB);
	}
	void dropTable() {
		if (Model::NAME_DB == "company.db") {
			sql = "DROP TABLE COMPANY;";
			execute("Table dropped successfully");
		}
		if (Model::NAME_DB == "contact.db") {
			sql = "DROP TABLE CONTACTS;";
			execute("Table dropped successfully");
			sql = "DROP TABLE GROUPS;";
			execute("Table dropped successfully");
			sql = "DROP TABLE CONTACT_GROUPS;";
			execute("Table dropped successfully");
		}
		
	}
	void createTable() {
		if (Model::NAME_DB == "company.db") {
			sql = "CREATE TABLE COMPANY(" \
				"ID      INT PRIMARY KEY NOT NULL," \
				"NAME    TEXT            NOT NULL," \
				"AGE     INT             NOT NULL," \
				"ADDRESS CHAR(50)," \
				"SALARY  REAL);";
			execute("Table created successfully");
		}
		if (Model::NAME_DB == "contact.db") {
			sql = R"~(CREATE TABLE contacts(
				contact_id INTEGER PRIMARY KEY,
				first_name TEXT NOT NULL,
				last_name  TEXT NOT NULL,
				email text NOT NULL UNIQUE,
				phone text NOT NULL UNIQUE
				);)~";
			execute("Table created successfully");
			sql = R"~(CREATE TABLE groups(
				group_id integer PRIMARY KEY,
				name     text NOT NULL
				);)~";
			execute("Table created successfully");
			sql = R"~(CREATE TABLE contact_groups(
				contact_id integer,
				group_id integer,
				PRIMARY KEY (contact_id, group_id),
				FOREIGN KEY (contact_id) REFERENCES contacts (contact_id)
				ON DELETE CASCADE ON UPDATE NO ACTION,
				FOREIGN KEY (group_id) REFERENCES groups (group_id)
				ON DELETE CASCADE ON UPDATE NO ACTION
				);)~";
			execute("Table created successfully");
		}
	}
	void createRecord() {
		if (Model::NAME_DB == "company.db") {
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
		if (Model::NAME_DB == "contact.db") {
			sql = R"~(INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1001, 'Paul', 'Blake', 'paul.blake@wemail.com', '1234567890');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1011, 'Allen', 'Wood', 'allen_wood@mail4me.com', '9876543210');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1013, 'Teddy', 'Hammersmith', 't.hammersmith@hotmail.us', '6513013229');
				INSERT INTO contacts(contact_id, first_name, last_name, email, phone) 
				VALUES(1021, 'Mark', 'Gold', 'markgold@provider.dk', '6379981234');)~";
			execute("Records created successfully");
			sql = R"~(INSERT INTO groups(group_id, name) 
				VALUES(10, 'Friend');
				INSERT INTO groups(group_id, name) 
				VALUES(30, 'Family');
				INSERT INTO groups(group_id, name) 
				VALUES(70, 'Acquaintance');)~";
			execute("Records created successfully");
			sql = R"~(INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1001, 10);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1001, 30);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1011, 10);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1013, 30);
				INSERT INTO contact_groups(contact_id, group_id) 
				VALUES(1021, 70);)~";
			execute("Records created successfully");
		}
	}
	void readRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "SELECT * FROM COMPANY;";
			// callback method is called for each record
			execute("Operation done successfully");
			dataHandler(returnData);
		}
		if (Model::NAME_DB == "contact.db") {
			//sql = R"~(SELECT * FROM CONTACTS;)~";
			sql = R"~(SELECT c.*, g.* FROM contacts c
				JOIN contact_groups cg ON cg.contact_id = c.contact_id
				JOIN groups g ON cg.group_id = g.group_id;)~";
			// callback method is called for each record
			execute("Operation done successfully");
			dataHandlerContact(returnDataContact);
		}
	}
	void updateRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "UPDATE COMPANY SET SALARY = 25000.00 WHERE ID = 1;";
			execute("Operation done successfully");
		}
		if (Model::NAME_DB == "contact.db") {
		}
	}
	void deleteRecord() {
		if (Model::NAME_DB == "company.db") {
			sql = "DELETE FROM COMPANY WHERE ID = 2;";
			execute("Operation done successfully");
		}
		if (Model::NAME_DB == "contact.db") {
		}
	}
private:
	void execute(const string & msg) {
		char* pszErrMsg = 0;
		int rc;
		const char* data = "Callback function called";

		// clear vector preceding callback
		returnData.clear();
		returnDataContact.clear();

		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

		if (rc != SQLITE_OK) {
			messageHandler("SQL error: " + static_cast<string>(pszErrMsg));
			sqlite3_free(pszErrMsg);
		}
		else
			messageHandler(msg.c_str());
	}
	static int callback(void* data, int argc, char** argv, char** aszColName) {
		if (Model::NAME_DB == "company.db") {
			tuple_company newTuple(static_cast<string>(argv[0]),
				static_cast<string>(argv[1]),
				static_cast<string>(argv[2]),
				static_cast<string>(argv[3]),
				static_cast<string>(argv[4]));
			Model::returnData.push_back(newTuple);
		}
		if (Model::NAME_DB == "contact.db") {
			tuple_contact newTuple(static_cast<string>(argv[0]),
				static_cast<string>(argv[1]),
				static_cast<string>(argv[2]),
				static_cast<string>(argv[3]),
				static_cast<string>(argv[4]),
				static_cast<string>(argv[5]),
				static_cast<string>(argv[6]));
			Model::returnDataContact.push_back(newTuple);
		}
		return 0;
	}
public:
	//static const string NAME_DB;
	static string NAME_DB;
private:
	MessageHandler messageHandler = nullptr;
	DataHandler dataHandler = nullptr;
	DataHandlerContact dataHandlerContact = nullptr;
	sqlite3* db;
	string sql;
	static vector<tuple_company> returnData;
	static vector<tuple_contact> returnDataContact;
};
//const string Model::NAME_DB = "company.db";
//const string Model::NAME_DB = "contact.db";
string Model::NAME_DB = "";
vector<tuple_company> Model::returnData;
vector<tuple_contact> Model::returnDataContact;

//****************************************************************************
//*                     View
//****************************************************************************
class View {
public:
	static void messageChange(const string& newMessage) {
		cout << newMessage << endl;
	}
	static void dataChange(vector<tuple_company>& newData) {
		for (auto it = newData.begin(); it < newData.end(); ++it) {
			tuple_company newTuple = *it;
			cout << "ID........: " << get<0>(newTuple) << endl;
			cout << "Name......: " << get<1>(newTuple) << endl;
			cout << "Age.......: " << get<2>(newTuple) << endl;
			cout << "Address...: " << get<3>(newTuple) << endl;
			cout << "Salary....: " << get<4>(newTuple) << endl;
			cout << endl;
		}
	}
	static void dataChangeContact(vector<tuple_contact>& newData) {
		for (auto it = newData.begin(); it < newData.end(); ++it) {
			tuple_contact newTuple = *it;
			cout << "ID...........: " << get<0>(newTuple) << endl;
			cout << "First name...: " << get<1>(newTuple) << endl;
			cout << "Last name....: " << get<2>(newTuple) << endl;
			cout << "email........: " << get<3>(newTuple) << endl;
			cout << "phone........: " << get<4>(newTuple) << endl;
			cout << "Group ID.....: " << get<5>(newTuple) << endl;
			cout << "Group........: " << get<6>(newTuple) << endl;
			cout << endl;
		}
	}
	bool menuSchemaRequest(Model& model) {
		int iChar;
		bool bProceed = true;
		bool bContinueApp = true;

		while (bProceed) {
			cout << "SQLite schema" << endl;
			cout << "=============" << endl;
			cout << " 1) Company" << endl;
			cout << " 2) Contact" << endl;
			cout << "Enter the number of a subject, or enter a zero to quit: ";
			cin >> iChar;

			switch (iChar) {
			case 1:
				Model::NAME_DB = "company.db";
				bProceed = false;
				bContinueApp = true;
				break;
			case 2:
				Model::NAME_DB = "contact.db";
				bProceed = false;
				bContinueApp = true;
				break;
			case 0:
				// the user wants to quit
				bProceed = false;
				bContinueApp = false;
				break;
			default:
				// the input, given by the user, is not an available option
				cout << "The entered number is not recognized, please try again." << endl;
			} // eof switch
		}
		return bContinueApp;
	}
	void menuUserRequest(Model& model) {
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

//****************************************************************************
//*                     Controller
//****************************************************************************
class Controller {
public:
	Controller(const Model& model, const View& view) :
		model(model), view(view) {}
	bool processSchemaRequest() {
		return view.menuSchemaRequest(model);
	}
	bool onLoad() {
		return model.openDB();
	}
	void processUserRequest() {
		view.menuUserRequest(model);
	}
private:
	Model model;
	View view;
};

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	Model model;
	View view;
	model.setHandler(&View::messageChange, &View::dataChange,
		&View::dataChangeContact);
	Controller controller(model, view);

	if (!controller.processSchemaRequest())
		// user wants to quit
		return 0;

	if (controller.onLoad()) {
		// database is sucessfully opened
		controller.processUserRequest();
	}
}
*/
//////////////////////////////////////////////////////////////////////////////
/*
// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
//  1 - Rewritten using tuple instead of Plain-Old-C-Object (POCO)

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "CppSQLite3.h"

using namespace std;

typedef void(*MessageHandler)(const string&);

typedef string key, name, age, address, salary;
typedef tuple<key, name, age, address, salary> tuple_company;
typedef void(*DataHandler)(vector<tuple_company>&);

//****************************************************************************
//*                     Model
//****************************************************************************
class Model {
public:
	void setHandler(MessageHandler messageHandler, DataHandler dataHandler) {
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
		sql = "SELECT * FROM COMPANY;";
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

		// clear vector preceding callback
		returnData.clear();

		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &pszErrMsg);

		if (rc != SQLITE_OK) {
			messageHandler("SQL error: " + static_cast<string>(pszErrMsg));
			sqlite3_free(pszErrMsg);
		}
		else
			messageHandler(msg.c_str());
	}
	static int callback(void* data, int argc, char** argv, char** aszColName) {
		tuple_company newTuple(static_cast<string>(argv[0]),
			static_cast<string>(argv[1]),
			static_cast<string>(argv[2]),
			static_cast<string>(argv[3]),
			static_cast<string>(argv[4]));
		Model::returnData.push_back(newTuple);
		return 0;
	}
private:
	const string NAME_DB = "test.db";
	MessageHandler messageHandler = nullptr;
	DataHandler dataHandler = nullptr;
	sqlite3* db;
	string sql;
	static vector<tuple_company> returnData; 
};
vector<tuple_company> Model::returnData;

//****************************************************************************
//*                     View
//****************************************************************************
class View {
public:
	static void messageChange(const string& newMessage) {
		cout << newMessage << endl;
	}
	static void dataChange(vector<tuple_company>& newData) {
		for (auto it = newData.begin(); it < newData.end(); ++it) {
			tuple_company newTuple = *it;
			cout << "ID........: " << get<0>(newTuple) << endl;
			cout << "Name......: " << get<1>(newTuple) << endl;
			cout << "Age.......: " << get<2>(newTuple) << endl;
			cout << "Address...: " << get<3>(newTuple) << endl;
			cout << "Salary....: " << get<4>(newTuple) << endl;
			cout << endl;
		}
	}
	void menuUserRequest(Model& model) {
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

//****************************************************************************
//*                     Controller
//****************************************************************************
class Controller {
public:
	Controller(const Model& model, const View& view) :
		model(model), view(view) {}
	bool onLoad() {
		return model.openDB();
	}
	void processUserRequest() {
		view.menuUserRequest(model);
	}
private:
	Model model;
	View view;
};

//****************************************************************************
//*                     main
//****************************************************************************
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
*/
//////////////////////////////////////////////////////////////////////////////
//NO GOOD
// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
//  1 - Rewritten to allow for multiple schemata, 
//      i.d. more than one database file name
//  2 - Rewritten using tuple instead of Plain-Old-C-Object (POCO)
/*
#include <iostream>
#include <string>
#include <tuple>

#include "CppSQLite3.h"

using namespace std;
namespace sqlite_v10 {
	//***************************************************************************
	//*                 typedef  
	//***************************************************************************
	typedef enum {NONE = 0, COMPANY = 1, CONTACT = 2} enum_schema;

	typedef string key, name, age, address, salary;
	typedef tuple<key, name, age, address, salary> tuple_company;

	typedef string group_id, name;
	typedef tuple<group_id, name> tuple_groups;

	typedef string contact_id, group_id;
	typedef tuple<contact_id, group_id> tuple_contact_groups;

	typedef string contact_id, first_name, last_name, email, phone;
	typedef tuple<contact_id, first_name, last_name, email, phone> tuple_contacts;

	typedef void(*MessageHandler)(const string&);
	typedef void(*DataHandler)(void*);

	//***************************************************************************
	//*                 Model   
	//***************************************************************************
	class Model {
	public:
		virtual void setHandler(MessageHandler, DataHandler) = 0;
		virtual bool openDB() = 0;
	protected:
		//static sqlite3* db;
	};
	//sqlite3* db;

	//***************************************************************************
	//*                 ModelCompany   
	//***************************************************************************
	class ModelCompany : public Model {
	public:
		static void setHandler(MessageHandler inMessageHandler, 
			DataHandler inDataHandler) {
			messageHandler = inMessageHandler;
			dataHandler = inDataHandler;
		}
		bool openDB() {//static bool openDB() {
			bool success;
			string message;

			int rc = sqlite3_open(NAME_DB.c_str(), &dbCompany);
			if (rc) {
				// error opening the database
				success = false;
				message = "open " + NAME_DB + " failed: " + *sqlite3_errmsg(dbCompany);
			}
			else {
				// database is sucessfully opened
				success = true;
				message = "open " + NAME_DB + " succeeded";
			}
			messageHandler(message);
			return success;
		}
	private:
		static MessageHandler messageHandler;
		static DataHandler dataHandler;
		static const string NAME_DB;
		sqlite3* dbCompany; //static sqlite3* dbCompany;
	};
	MessageHandler ModelCompany::messageHandler = nullptr;
	DataHandler ModelCompany::dataHandler = nullptr;
	const string ModelCompany::NAME_DB = "company.db";
	//sqlite3* dbCompany;

	//***************************************************************************
	//*                 ModelContact   
	//***************************************************************************
	class ModelContact : public Model {
	public:
		static void setHandler(MessageHandler inMessageHandler,
			DataHandler inDataHandler) {
			messageHandler = inMessageHandler;
			dataHandler = inDataHandler;
		}
		static bool openDB() {
			bool success;
			string message;

			int rc = sqlite3_open(NAME_DB.c_str(), &dbContact);
			if (rc) {
				// error opening the database
				success = false;
				message = "open " + NAME_DB + " failed: " + *sqlite3_errmsg(dbContact);
			}
			else {
				// database is sucessfully opened
				success = true;
				message = "open " + NAME_DB + " succeeded";
			}
			messageHandler(message);
			return success;
		}
	private:
		static MessageHandler messageHandler;
		static DataHandler dataHandler;
		static const string NAME_DB;
		static sqlite3* dbContact;
	};
	MessageHandler ModelContact::messageHandler = nullptr;
	DataHandler ModelContact::dataHandler = nullptr;
	const string ModelContact::NAME_DB = "contact.db";
	sqlite3* dbContact;

	//***************************************************************************
	//*                 View   
	//***************************************************************************
	class View {
	public:
		virtual void messageChange(const string&) = 0;
		virtual void dataChange(void*) = 0;
		static enum_schema menuUserSchema() {
			bool bProceed = true;
			int iChar;

			while (bProceed) {
				cout << "SQLite schema" << endl;
				cout << "=============" << endl;
				cout << " 1) Company" << endl;
				cout << " 2) Contacts" << endl;
				cout << "Enter the number of a subject, or enter a zero to quit: ";

				cin >> iChar;

				switch (iChar) {
				case 1:
					return COMPANY;
				case 2:
					return CONTACT;
				case 0:
					return NONE;
				default:
					// the input, given by the user, is not an available option
					cout << "The entered number is not recognized, please try again." << endl;
					break;
				} // eof switch
			}
		}
	};

	//***************************************************************************
	//*                 ViewCompany   
	//***************************************************************************
	class ViewCompany : public View {
	public:
		static void messageChange(const string& newMessage) {}
		static void dataChange(void* newdata) {}
	};

	//***************************************************************************
	//*                 ViewContact   
	//***************************************************************************
	class ViewContact : public View {
	public:
		static void messageChange(const string& newMessage) {}
		static void dataChange(void* newdata) {}
	};

	//***************************************************************************
	//*                 Controller   
	//***************************************************************************
	class Controller {
	public:
		static void processUserSchema() {
			schema = View::menuUserSchema();
		}
		static enum_schema schema;
		virtual bool onLoad() = 0;
	};
	enum_schema Controller::schema = NONE;

	//***************************************************************************
	//*                 ControllerCompany   
	//***************************************************************************
	class ControllerCompany : Controller {
	public:
		static bool onLoad() {
			return ModelCompany::openDB();
		}
	};

	//***************************************************************************
	//*                 ControllerContact   
	//***************************************************************************
	class ControllerContact : Controller {
	public:
		static bool onLoad() {
			return ModelContact::openDB();
		}
	};
}
//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	using namespace sqlite_v10;
	// register the handler method
	ModelCompany::setHandler(&ViewCompany::messageChange,
		&ViewCompany::dataChange);
	ModelContact::setHandler(&ViewContact::messageChange,
		&ViewContact::dataChange);

	// let the user choose the schema
	Controller::processUserSchema();
	if (Controller::schema == NONE)
		return 0;

	if (Controller::schema == COMPANY)
		if (ControllerCompany::onLoad())
			// database is sucessfully opened
			;
	if (Controller::schema == CONTACT)
		if (ControllerContact::onLoad())
			// database is sucessfully opened
			;
}
*/
//////////////////////////////////////////////////////////////////////////////
/*
// Look at:
// https://stackoverflow.com/questions/51422188/vs-2017-c-cannot-open-source-file-sqlite3-h
// After installing:
// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
//  1 - Rewritten using a Model-View-Controller pattern
//  2 - Rewritten using function pointers for conveying
//      messages from controller to view, and
//      records from controller to view
#include <iostream>
#include <string>
#include <vector>

#include "CppSQLite3.h"

using namespace std;
//****************************************************************************
//*                     CompanyRecord
//****************************************************************************
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

//****************************************************************************
//*                     Model
//****************************************************************************
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
		// d.c. don't forget to supply the backslash character here
		sql = "CREATE TABLE COMPANY(" \
			"ID      INT PRIMARY KEY NOT NULL," \
			"NAME    TEXT            NOT NULL," \
			"AGE     INT             NOT NULL," \
			"ADDRESS CHAR(50)," \
			"SALARY  REAL);";
		execute("Table created successfully");
	}
	void createRecord() {
		// d.c. don't forget to supply the backslash character here
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
		sql = "SELECT * FROM COMPANY;";
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

		// clear vector preceding callback
		returnData.clear();

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

//****************************************************************************
//*                     View
//****************************************************************************
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
	void menuUserRequest(Model& model) {
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

//****************************************************************************
//*                     Controller
//****************************************************************************
class Controller {
public:
	Controller(const Model& model, const View& view) :
		model(model), view(view) {}
	bool onLoad() {
		return model.openDB();
	}
	void processUserRequest() {
		view.menuUserRequest(model);
	}
private:
	Model model;
	View view;
};

//****************************************************************************
//*                     main
//****************************************************************************
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
*/
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
