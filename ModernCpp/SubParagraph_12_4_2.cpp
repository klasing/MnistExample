#include "pch.h"

#include <map>

using namespace std;

class Data_12_4_2 {
public:
	Data_12_4_2(int val = 0) { mVal = val; }
	int getVal() const { return mVal; }
	void setVal(int val) { mVal = val; }
protected:
	int mVal;
};

inline void func_12_4_2(const map<int, int>& m) {
	// Error
	//cout << "-> " << m[1] << endl;
	// Use the find() method instead
	auto iter = m.find(1);
	if (iter != m.end())
		cout << "-> " << iter->second << endl;
}

class BankAccount {
public:
	BankAccount(int acctNum, const string& name)
		: mAcctNum(acctNum), mClientName(name) {}
	void setAcctNum(int acctNum) { mAcctNum = acctNum; }
	int getAcctNum() const { return mAcctNum; }
	void setClientName(const string& name) { mClientName = name; }
	string getClientName() const { return mClientName; }
protected:
	int mAcctNum;
	string mClientName;
};

class BankDB {
public:
	BankDB() {}
	// Adds act to the bank database. If an account exists already
	// with that number, the new account is not added. Returns true
	// if the account is added, false if it's not.
	bool addAccount(const BankAccount& acct) {
		// Do the actual insert, using the account number as the key
		auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));
		// Return the bool field of the pair specifying success or failure
		return res.second;
	}
	// Removes the account acctNum from the daabase.
	void deleteAccount(int acctNum) {
		mAccounts.erase(acctNum);
	}
	// Returns a reference to the account represented
	// by its number or the client name.
	// Throws out_of_range if the account is not found.
	BankAccount& findAccount(int acctNum) throw(out_of_range) {
		// Finding an element via its key can be done with find()
		auto it = mAccounts.find(acctNum);
		if (it == mAccounts.end())
			throw out_of_range("No account with that number.");
		// Remember that iterators into maps refer to pairs of key/value
		return it->second;
	}
	BankAccount& findAccount(const string& name)
		throw(out_of_range) {
		// Finding an element by a non-key attribute requires a linear
		// search through the elements.
		for (auto& p : mAccounts)
			if (p.second.getClientName() == name)
				// found it!
				return p.second;
		throw out_of_range("No account with that name.");
	}
	// Adds all the accounts from db to this database.
	// Deletes all the accounts from db.
	void mergeDatabase(BankDB& db) {
		// Just insert copies of all the accounts in the old db
		// to the new one.
		mAccounts.insert(db.mAccounts.begin(), db.mAccounts.end());
		// Now delete all the accounts in the old one.
		db.mAccounts.clear();
	}
protected:
	map<int, BankAccount> mAccounts;
};

inline void subParagraph_12_4_2() {
	cout << "map" << endl;
	cout << "---" << endl;

	cout << "a) Constructing maps" << endl;
	map<int, Data_12_4_2> dataMap;
	map<string, int> m = {
		{"Marc G.", 123},
		{"Zulija N.", 456},
		{"John D.", 369}
	};
	cout << "b) Inserting Elements" << endl;
	cout << "   b.1) The insert() Method" << endl;
	map<int, Data_12_4_2> dataMap_b1;
	// Using c++11 initializer_list
	auto ret = dataMap_b1.insert({ 1, Data_12_4_2(4) });
	if (ret.second)
		cout << "-> Insert succeeded!" << endl;
	else
		cout << "-> Insert failed!" << endl;
	ret = dataMap_b1.insert(make_pair(1, Data_12_4_2(6)));
	if (ret.second)
		cout << "-> Insert succeeded!" << endl;
	else
		cout << "-> Insert failed!" << endl;
	cout << "   b.2) operator[]" << endl;
	map<int, Data_12_4_2> dataMap_b2;
	dataMap_b2[1] = Data_12_4_2(4);
	// Replaces the element with key 1
	dataMap_b2[1] = Data_12_4_2(6);
	cout << "   b.3) map Iterators" << endl;
	map<int, Data_12_4_2> dataMap_b3;
	dataMap_b3[1] = Data_12_4_2(4);
	// Replaces the element with key 1
	dataMap_b3[1] = Data_12_4_2(6);
	//for (auto iter = dataMap_b3.cbegin(); iter != dataMap_b3.cend(); ++iter)
	//	//cout << "-> " << iter->second.getVal() << endl;
	//	// more elaborate writing
	//	cout << "-> " << (*iter).second.getVal() << endl;
	// more elegantly with a C++11 range-based for loop
	//for (auto& p : dataMap_b3)
	//	cout << "-> " << p.second.getVal() << endl;
	// or, if the preceding C++11 vesions are not supported
	for (map<int, Data_12_4_2>::const_iterator iter = dataMap_b3.begin();
		iter != dataMap_b3.end(); ++iter)
		cout << "-> " << iter->second.getVal() << endl;
	cout << "c) Looking Up Elements" << endl;
	map<int, Data_12_4_2> dataMap_c;
	dataMap_c[1] = Data_12_4_2(4);
	dataMap_c[1] = Data_12_4_2(6);
	//dataMap_c[1].setVal(100);
	// not using operator[]
	//auto it = dataMap_c.find(1);
	//if (it != dataMap_c.end())
	//	it->second.setVal(100);
	// not using the auto keyword
	map<int, Data_12_4_2>::iterator it = dataMap_c.find(1);
	if (it != dataMap_c.end())
		it->second.setVal(100);
	cout << "d) Removing Elements" << endl;
	map<int, Data_12_4_2> dataMap_d;
	dataMap_d[1] = Data_12_4_2(4);
	cout << "-> There are " << dataMap_d.count(1) << " elements with key 1" << endl;
	dataMap_d.erase(1);
	cout << "-> There are " << dataMap_d.count(1) << " elements with key 1" << endl;
	cout << "e) map Example: Bank Account" << endl;
	BankDB db;
	db.addAccount(BankAccount(100, "Nicolas Solter"));
	db.addAccount(BankAccount(200, "Scott Kleper"));
	try {
		auto acct = db.findAccount(100);
		cout << "-> Found account 100" << endl;
		acct.setClientName("Nicholas A Solter");
		auto acct2 = db.findAccount("Scott Kleper");
		cout << "-> Found account of Scott Kleper" << endl;
		auto acct3 = db.findAccount(1000);
	}
	catch (const out_of_range&) {
		cout << "-> Unable to find account" << endl;
	}
}