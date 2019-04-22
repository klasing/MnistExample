#include "pch.h"

#include <map>
#include <string>
#include <list>

class BuddyList {
public:
	BuddyList() {}
	// Adds buddy as a friend of name
	void addBuddy(const string& name, const string& buddy) {
		// Make sure this buddy isn't already there. We don't want
		// to insert an identical copy of the key/value pair.
		if (!isBuddy(name, buddy))
			// Using C++11 initializer_list
			mBuddies.insert({ name, buddy });
	}
	// Removes buddy as a friend of name
	void removeBuddy(const string& name, const string& buddy) {
		// Obtain the beginning and end of this range of elements with
		// key 'name'.
		auto start = mBuddies.lower_bound(name);
		auto end = mBuddies.upper_bound(name);
		// Iterate through the elements with key 'name' looking
		// for a value 'buddy'
		for (; start != end; ++start)
			if (start->second == buddy) {
				// We found a match! Remove it from the map.
				mBuddies.erase(start);
				break;
			}
	}
	// Returns true if buddy is a friend of name, false otherwise.
	bool isBuddy(const string& name, const string& buddy) const {
		// Obtain the beginning and end of this range of elements with
		// key 'name'.
		auto start = mBuddies.lower_bound(name);
		auto end = mBuddies.upper_bound(name);
		// Iterate through the elements with key 'name' looking
		// for a value 'buddy'. If there are no elements with key 'name',
		// start equals end, so loop body doesn't execute.
		for (; start != end; ++start)
			if (start->second == buddy) {
				// We found a match!
				return true;
			}
		// No matches
		return false;
	}
	// Retrieves a list of all the friends of name
	list<string> getBuddies(const string& name) const {
		// Obtain the pair of iterators marking the range containing
		// elements with key 'name'
		auto its = mBuddies.equal_range(name);
		// Create a list with all names in the range (all buddies of name).
		list<string> buddies;
		for (; its.first != its.second; ++its.first)
			buddies.push_back(its.first->second);
		return buddies;
	}
protected:
	multimap<string, string> mBuddies;
};

inline void subParagraph_12_4_3() {
	cout << "multimap" << endl;
	cout << "--------" << endl;

	cout << "a) multimap Example: Buddy Lists" << endl;
	BuddyList buddies;
	buddies.addBuddy("Harry Potter", "Ron Weasley");
	buddies.addBuddy("Harry Potter", "Hermione Granger");
	buddies.addBuddy("Harry Potter", "Hagrid");
	buddies.addBuddy("Harry Potter", "Drace Malfoy");
	// That's not right! Remove Draco.
	buddies.removeBuddy("Harry Potter", "Drace Malfoy");

	buddies.addBuddy("Hagrid", "Harry Potter");
	buddies.addBuddy("Hagrid", "Ron Weasley");
	buddies.addBuddy("Hagrid", "Hermione Granger");

	auto harryBuds = buddies.getBuddies("Harry Potter");
	cout << "-> Harry's friends: " << endl;
	for (auto& name : harryBuds)
		cout << "-> \t" << name << endl;

}