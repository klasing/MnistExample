#include "pch.h"

#include <set>
#include <list>
#include <string>

class AccessList {
public:
	// Default constructor
	AccessList() {}
	// Constructor to support C++11 uniform initialization.
	AccessList(const initializer_list<string>& initList) {
		for (auto& user : initList)
			addUser(user);
	}
	// Adds the user to the permissions list.
	void addUser(const string& user) {
		mAllowed.insert(user);
	}
	// Removes the user from the permissions list.
	void removeUser(const string& user) {
		mAllowed.erase(user);
	}
	// Returns true if the user is in the permissions list.
	bool isAllowed(const string& user) const {
		return (mAllowed.count(user) == 1);
	}
	// Returns a list of all users who have permissions.
	list<string> getAllUsers() const {
		list<string> users;
		users.insert(users.end(), mAllowed.begin(), mAllowed.end());
		return users;
	}
protected:
	set<string> mAllowed;
};

inline void subParagraph_12_4_4() {
	cout << "set" << endl;
	cout << "---" << endl;

	cout << "a) set Example: Access Control List" << endl;
	AccessList fileX = { "nsolter", "klep", "baduser" };
	fileX.removeUser("baduser");
	if (fileX.isAllowed("nsolter"))
		cout << "-> nsolter has permissions" << endl;
	if (fileX.isAllowed("baduser"))
		cout << "-> baduser has permissions" << endl;
	auto users = fileX.getAllUsers();
	cout << "-> ";
	for (auto& user : users)
		cout << user << " ";
	cout << endl;
}