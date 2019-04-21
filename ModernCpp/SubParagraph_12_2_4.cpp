#include "pch.h"

#include <vector>
#include <list>
#include <string>

// courseStudents is a vector of lists, one for each course. The lists
// contain the students enrolled in those courses. They are not sorted.
//
// droppedStudents is a list of students who failed to pay their
// tuition and so were dropped from their courses.
//
// The function returns a list of every enrolled (non-dropped) student in
// all the courses.
inline list <string> 
getTotalEnrollment(const vector<list<string>>& courseStudents,
	const list<string>& droppedStudents) {
	list<string> allStudents;
	// Concatenate all the course lists onto the master list
	for (auto& lst : courseStudents)
		allStudents.insert(allStudents.end(), lst.begin(), lst.end());
	// alternative for when the compiler does not support range-based for loops
	//for (vector<list<string> >::const_iterator it = courseStudents.begin();
	//	it != courseStudents.end(); ++it)
	//	allStudents.insert(allStudents.end(), (*it).begin(), (*it).end());
	// Sort the master list
	allStudents.sort();
	// Remove duplicate student names (those who are in multiple courses).
	allStudents.unique();
	// Remove students who are on the dropped list.
	// Iterate through the drop list, calling remove on the
	// master list for each student in the dropped list.
	for (auto& str : droppedStudents)
		allStudents.remove(str);
	// alternative for when the compiler does not support range-based for loops
	//for (list<string>::const_iterator it = droppedStudents.begin();
	//	it != droppedStudents.end(); ++it)
	//	allStudents.remove(*it);
	// done!
	return allStudents;
}

inline void subParagraph_12_2_4() {
	cout << "list" << endl;
	cout << "----" << endl;

	list<string> lst = { "String 1", "String 2", "String 3" };
	cout << "a) Accessing Elements" << endl;
	cout << "   a.1) Iterators" << endl;
	cout << "b) Adding and Removing Elements" << endl;
	cout << "   b.1) list Size" << endl;
	cout << "c) Special list Operations" << endl;
	cout << "   c.1) Splicing" << endl;
	list<string> dictionary, bWords;
	// Add the a words.
	dictionary.push_back("aardvark");
	dictionary.push_back("ambulance");
	// Add the c words.
	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");
	// Create another list, of the b words.
	bWords.push_back("bathos");
	bWords.push_back("balderdash");
	// splice the b words into the main dictionary.
	if (bWords.size() > 0) {
		// Get an iterator to the last b word.
		auto iterLastB = --(bWords.cend());
		// Iterate up to the spot where we want to insert bs.
		list<string>::iterator it;
		for (it = dictionary.begin(); it != dictionary.end(); ++it)
			if (*it > *iterLastB)
				break;
		// Add in the bWords. This action removes the elements from bWords.
		dictionary.splice(it, bWords);
	}
	// print out the dictionary
	for (auto it = dictionary.cbegin(); it != dictionary.cend(); ++it)
		cout << "-> " << *it << endl;

	cout << "   c.2) More Efficient Versions of Algorithms" << endl;
	cout << "d) list Example: Determining Enrollment" << endl;
}