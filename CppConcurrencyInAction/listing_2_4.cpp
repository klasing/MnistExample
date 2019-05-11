// Listing 2.4
// Detaching a thread to handle other documents
#pragma once
#include <iostream>
#include <string>
#include <thread>

using namespace std;
namespace ns_listing_2_4 {
	enum command_type {
		open_new_document,
		manipulate__document,
		close_document
	};
	struct user_command {
		command_type type = command_type::close_document;
	};
	inline void open_document_and_display_gui(const string& filename) {
		cout << "-> [listing 2.4] " << filename << " opened in GUI" << endl;
	}
	inline user_command get_user_input() {
		user_command cmd{ close_document };
		int iChar;
		cout << "-> [listing 2.4] 1) open new document" << endl;
		cout << "-> [listing 2.4] 2) manipulate document" << endl;
		cout << "-> [listing 2.4] 3) close document" << endl;
		cout << "-> [listing 2.4] enter a command ";
		cin >> iChar;
		cmd.type = static_cast<command_type>(iChar - 1);
		return cmd;
	}
	inline const string get_filename_from_user() {
		return "another file name";
	}
	inline void process_user_input(user_command cmd, bool& done_editing,
		string const& filename) {
		if (cmd.type == manipulate__document)
			cout << "-> [listing 2.4] manipulating " << filename << endl;
		if (cmd.type == close_document) {
			cout << "-> [listing 2.4] closing " << filename << endl;
			done_editing = true;
		}
	}
	inline void edit_document(string const& filename) {
		open_document_and_display_gui(filename);
		bool done_editing = false;
		while (!done_editing) {
			user_command cmd = get_user_input();
			if (cmd.type == open_new_document) {
				string const new_name = get_filename_from_user();
				thread t(edit_document, new_name);
				t.detach();
			}
			else
				process_user_input(cmd, done_editing, filename);
		}
	}
}
