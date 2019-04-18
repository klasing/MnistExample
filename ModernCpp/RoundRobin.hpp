#pragma once

#include <vector>

// Class template RoundRobin
// Provides simple round-robin semantics for a list of elements.
template <typename T>
class RoundRobin {
public:
	// Client can give a hint as to the number of expected elements for
	// increased efficiency.
	RoundRobin(int numExpected = 0) {
		// If the client gave a guideline, reserve that much space.
		mElems.reserve(numExpected);
		// Initialize mCurElem even though it isn't used until
		// there's at least one element.
		mCurElem = mElems.begin();
	}

	virtual ~RoundRobin() {
		// nothing to de here -- the vector will delete all the elements
	}

	// Appends elem to the end of the list. May be called
	// between calls to  getNext().
	void add(const T& elem) {
		// Even though we add the element at the end, the vector could
		// reallocate and invalidate the iterator with the push_back call.
		// Take advantage of the random access iterator features to save our
		// spot.
		int pos = mCurElem - mElems.begin();
		// add the element
		mElems.push_back(elem);
		// Reset our iterator to make sure it is valid.
		mCurElem = mElems.begin() + pos;
	}

	// Removes the first (and only the first) element
	// in the list that is equal (with operator==) to elem.
	// May be called between calls to getNext().
	void remove(const T& elem) {
		for (auto it = mElems.begin(); it != mElems.end(); ++it)
			if (*it == elem) {
				// Removing an element will invalidate our mCurElem iterator if
				// it refers to an element past the point of the removal.
				// Take advantage of the random access features of the iterator
				// to track the position of the current element after removal.
				int newPos;
				// if current iterator is before or at the one we're removing,
				// the new position is the same as before.
				if (mCurElem <= it)
					newPos = mCurElem - mElems.begin();
				else
					// otherwise, it's one less than before
					newPos = mCurElem - mElems.begin() - 1;
				// erase the element (and ignore the return value)
				mElems.erase(it);
				// Now reset our iterator to make sure it is valid.
				mCurElem = mElems.begin() + newPos;
				// If we were pointing to the last element and it was removed,
				// we need to loop back to the first.
				if (mCurElem == mElems.end())
					mCurElem = mElems.begin();
				return;
			}
	}
	// Returns the next element in the list, starting with the first,
	// and cycling back to the first when the end of the list is
	// reached, taking into account elements that are added or removed.
	T& getNext() throw(out_of_range) {
		// First make sure there are any elements.
		if (mElems.empty())
			throw out_of_range("No elements in the list");
		// retrieve a reference to return
		T& retVal = *mCurElem;
		// Increment the iterator modulo the number of elements
		++mCurElem;
		if (mCurElem == mElems.end())
			mCurElem = mElems.begin();
		// return the reference
		return retVal;
	}
protected:
	vector<T> mElems;
	typename vector<T>::iterator mCurElem;
private:
	// Prevent assignment and pass by value
	RoundRobin(const RoundRobin& src);
	RoundRobin& operator=(const RoundRobin& rhs) {
		// not according to text in book
		return *this;
	}
};