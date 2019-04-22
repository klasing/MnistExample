#include "pch.h"

#include <unordered_map>
#include <string>

template<class T>
inline void printMap(const T& m) {
	for (auto& p : m)
		cout << "-> " << p.first << "(Phone: " << p.second << ")" << endl;
	cout << "-> -------" << endl;
}

inline void subParagraph_12_5_3() {
	cout << "unordered_map Example: Phone Book" << endl;
	cout << "---------------------------------" << endl;

	// Create a hash table.
	unordered_map<string, string> um;
	um.insert({
		{"Marc G.", "123-456789"},
		{"Zulija N.", "987-654321"},
		{"Scott K.", "654-987321"},
		});
	printMap(um);
	// Add/remove some phone numbers.
	um.insert(make_pair("John D.", "321-987654"));
	um["John G."] = "963-258147";
	um["Freddy K."] = "999-256256";
	um.erase("Freddy K.");
	printMap(um);
	// Find the bucket index for a specific key.
	int bucket = um.bucket("Marc G.");
	cout << "-> Marc G. is in bucket " << bucket
		<< " wich contains the following "
		<< um.bucket_size(bucket) << " elements:" << endl;
	// Get begin and end iterators for the elements in this bucket.
	// 'auto' is being used here. The compiler will derive the type
	// of both iterators as
	// unordered_map<string, string>::const_local_iterator
	auto liter = um.cbegin(bucket);
	auto literEnd = um.cend(bucket);
	while (liter != literEnd) {
		cout << "-> \t" << liter->first << "(Phone: "
			<< liter->second << ")" << endl;
		++liter;
	}
	cout << "-> -------" << endl;
	// Print some statistics about the hash table
	cout << "-> There are " << um.bucket_count() << " buckets." << endl;
	cout << "-> Average number of elements in a bucket is "
		<< um.load_factor() << endl;
}