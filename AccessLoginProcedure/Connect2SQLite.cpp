//#include <iostream>
//#include <string>
//#include <tuple>
//
//#include "CppSQLite3.h"
//
//using namespace std;
//namespace ns_connect_to_sqlite {
//	typedef void(*MessageHandler)(const string&);
//
//	typedef tuple<string, string> tuple_user_data;
//	//tuple_user_data user_data_in_db(
//	//	user_email_address,
//	//	user_password);
//
//	//***************************************************************************
//	//*                 Model
//	//***************************************************************************
//	class Model {
//		sqlite3* db = nullptr;
//		MessageHandler messageHandler = nullptr;
//		string sql;
//		static int highestKeyValue;
//	public:
//		static const string NAME_DB;
//	public:
//		void setHandler(MessageHandler messageHandler) {
//			this->messageHandler = messageHandler;
//		}
//
//		bool openDb() {
//			bool success = false;
//			string message = "";
//
//			int rc = sqlite3_open(Model::NAME_DB.c_str(), &db);
//			if (rc) {
//				// error opening the database
//				success = false;
//				message = "open "
//					+ Model::NAME_DB
//					+ " failed: "
//					+ *sqlite3_errmsg(db);
//			}
//			else {
//				// database is successfully opened
//				success = true;
//				message = "open: "
//					+ Model::NAME_DB
//					+ " succeeded";
//			}
//			messageHandler(message);
//			// this has to happen only once! 
//			createTable();
//			
//			return success;
//		}
//
//		// this has to happen only once!
//		// TODO user_password must be an encoded text!
//		void createTable() {
//			sql = R"~(
//				CREATE TABLE IF NOT EXISTS user_access_login_data(
//				  id                 INTEGER PRIMARY KEY,
//				  user_email_address text NOT NULL,
//				  user_password      text NOT NULL
//				);
//			)~";
//			execute("Table created successfully");
//			// insert a default user
//			string key = to_string(Model::highestKeyValue);
//			sql = "INSERT INTO user_access_login_data( \
//				id, user_email_address, user_password) VALUES("
//				+ key + ", "
//				+ "'guest'" + ", "
//				+ "'anonymous'"
//				+ ");";
//			execute("Record inserted successfully");
//		}
//
//		void closeDb() const {
//			sqlite3_close(db);
//			messageHandler("close " + Model::NAME_DB);
//		}
//	private:
//		void execute(const string& msg) {
//			char* pszErrMsg = 0;
//			int rc;
//			const char* data = "callback function called";
//
//			rc = sqlite3_exec(
//				db,
//				sql.c_str(),
//				callback,
//				(void*)data,
//				&pszErrMsg);
//
//			if (rc != SQLITE_OK) {
//				messageHandler("SQL error: " + static_cast<string>(pszErrMsg));
//				sqlite3_free(pszErrMsg);
//			}
//			else
//				messageHandler(msg.c_str());
//		}
//
//		static int 
//			callback(
//				void* data,
//				int argc,
//				char** argv,
//				char** aszColName)
//		{
//			string colName = *aszColName;
//			if (colName == "max(ID)")
//				Model::highestKeyValue = stoi(argv[0]);
//			return 0;
//		}
//	};
//	//***************************************************************************
//	//*                 View
//	//***************************************************************************
//	class View {
//	public:
//		static void messageChange(const string& newMessage) {
//			cout << newMessage << endl;
//		}
//	};
//	//***************************************************************************
//	//*                 Controller
//	//***************************************************************************
//	class Controller {
//	private:
//		Model model;
//		View view;
//	public:
//		Controller(const Model& model, const View& view) 
//			: model(model), view(view) 
//		{}
//		bool onLoad() {
//			return model.openDb();
//			// this has to happen only once!
//			model.createTable();
//		}
//		void closeDb() { model.closeDb(); }
//	};
//}