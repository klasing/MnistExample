#include "pch.h"

#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>

typedef map<string, list<string>> VotersMap;
typedef pair<const string, list<string>> DistrictPair;

// getDuplicates
//
// Returns a set of all names that appear in more than one list in
// the map.
inline set<string> getDuplicates(const VotersMap& votersByDistrict) {
	// Collect all the names from all the lists into one big list
	list<string> allNames;
	for (auto& district : votersByDistrict)
		allNames.insert(allNames.end(), district.second.begin(),
			district.second.end());

	// sort the list -- use the list version, not the general algorithm
	// because the list version is faster
	allNames.sort();

	// Now it's sorted, all duplicate names will be next to each other.
	// Use adjacent_find() to find instances of two or more identical names
	// next to each other.
	// Loop until adjacent_find() returns the end iterator.
	set<string> duplicates;
	for (auto lit = allNames.cbegin(); lit != allNames.cend(); ++lit) {
		lit = adjacent_find(lit, allNames.cend());
		if (lit == allNames.cend())
			break;
		duplicates.insert(*lit);
	}
	return duplicates;
}

// getDuplicates, the more compact version
//
// Returns a set of all names that appear in more than one list in
// the map.
//inline set<string> getDuplicates(const VotersMap& votersByDistrict) {
//	set<string> allNames;
//	set<string> duplicates;
//	for (auto& district : votersByDistrict)
//		for (auto& name : district.second)
//			duplicates.insert(name);
//
//	return duplicates;
//}

// Expects a map of string/list<string> pairs keyed on district names
// and containing lists of all the registered voters in those districts.
// Removes from each list any name on the convictedFelons list and
// any name that is found on any other list.
inline void auditVoterRolls(VotersMap& votersByDistrict,
	const list<string>& convictedFelons) {
	// get all the duplicate names
	set<string> toRemove = getDuplicates(votersByDistrict);

	// combine the duplicates and convicted felons -- we want
	// to remove names on both lists from all voter rolls
	toRemove.insert(convictedFelons.cbegin(), convictedFelons.cend());

	// Now remove all the names we need to remove using
	// nested  lambda espressions and the remove-erase-idiom
	for_each(votersByDistrict.begin(), votersByDistrict.end(),
		[&toRemove](DistrictPair& district) {
		auto it = remove_if(district.second.begin(),
			district.second.end(), [&](const string& name) {
			return (toRemove.count(name) > 0);
		});
		district.second.erase(it, district.second.end());
	});
}

inline void subParagraph_13_5_1() {
	cout << "The Voter Registration Audit Problem Statement" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "a) The auditVoterRolls Fuction" << endl;
	cout << "b) The getDuplicates Function" << endl;
	cout << "c) Testing the auditVoterRolls Function" << endl;
	// Initialize map using uniform initialization
	VotersMap voters = {
		{"Orange", {"Amy Aardvark", "Bob Buffalo",
			"Charles Cat", "Dwayne Dog"}},
		{"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo",
			"Amy Aardvark"}},
		{"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}
		};
	list<string> felons = { "Bob Buffalo", "Charles Cat" };

	// local lambda expresion to print a district
	auto printDistrict = [](const DistrictPair& district) {
		cout << "-> " << district.first << ":";
		for (auto& str : district.second)
			cout << " {" << str << "}";
		cout << endl;
	};

	cout << "-> Before Audit:" << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;

	auditVoterRolls(voters, felons);

	cout << "-> After Audit:" << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;
}