#include "pch.h"

#include <string>
#include "RoundRobin.hpp"

// Simple Process class
class Process {
public:
	// Constructor accepting the name of the process.
	Process(const string& name) : mName(name) {}
	// Implementation of doWorkDuringTimeSlice would let the process
	// perform its work for the duration of a time slice.
	// Actual implementation omtitted.
	void doWorkDuringTimeSlice() {
		cout << "-> Process " << mName
			<< " performing work during time slice." << endl;
	}
	// Needed for the RoundRobin::remove method to work.
	bool operator==(const Process& rhs) {
		return mName == rhs.mName;
	}
protected:
	string mName;
};

// Simple round-robin based process scheduler.
class Scheduler {
public:
	// Constructor takes a vector of processes.
	Scheduler(const vector<Process>& processes) {
		// Add the processes
		for (auto& process : processes)
			rr.add(process);
	}
	// Selects the next process using a round-robin scheduling
	// algorithm and allows it to perform some work during
	// this time slice.
	void scheduleTimeSlice() {
		try {
			rr.getNext().doWorkDuringTimeSlice();
		}
		catch (const out_of_range&) {
			cerr << "-> No more processes to schedule." << endl;
		}
	}
	// Removes the given process from the list of processes.
	void removeProcess(const Process& process) {
		rr.remove(process);
	}
protected:
	RoundRobin<Process> rr;
};

class Element {
public:
	Element() {}
	virtual ~Element() {}
};

template <typename T>
inline void printVector(const vector<T>& vec) {
	cout << "-> ";
	for (auto iter = vec.cbegin();
		iter != vec.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

inline void subParagraph_12_2_1() {
	cout << "vector" << endl;
	cout << "------" << endl;

	cout << "a) vector Overview" << endl;
	cout << "b) Fixed-Length vectors" << endl;
	// Create a vector of 10 doubles
	vector<double> doubleVector(10);
	// Initialize max to smallest number
	double max = numeric_limits<double>::lowest();
	for (size_t i = 0; i < 10; i++)
		doubleVector[i] = .0;
	for (size_t i = 0; i < 10; i++) {
		cout << "-> Enter score " << i + 1 << ": ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max)
			max = doubleVector[i];
	}
	max /= 100.0;
	cout << "-> ";
	for (size_t i = 0; i < 10; i++) {
		doubleVector[i] /= max;
		cout << doubleVector[i] << " ";
	}
	cout << endl;
	cout << "   b.1) Specifying an Initial Element Value" << endl;
	// 10 doubles of value 0.0
	vector<double> doubleVector_(10, .0);
	// Initialize max to smallest number
	double max_ = numeric_limits<double>::lowest();
	// No need to initialize each element: the constructor did it for you
	//for (size_t i = 0; i < 10; i++)
	//	doubleVector_[i] = .0;
	for (size_t i = 0; i < 10; i++) {
		cout << "-> Enter score " << i + 1 << ": ";
		cin >> doubleVector_[i];
		if (doubleVector_[i] > max_)
			max_ = doubleVector_[i];
	}
	max_ /= 100.0;
	cout << "-> ";
	for (size_t i = 0; i < 10; i++) {
		doubleVector_[i] /= max_;
		cout << doubleVector_[i] << " ";
	}
	cout << endl;
	cout << "   b.2) Other vector Element Access Methods" << endl;
	cout << "c) Dynamic-Length vectors" << endl;
	// Create a vector with zero elements
	vector<double> doubleVector_ex;
	// Initialize max to smallest number
	double max_ex = numeric_limits<double>::lowest();
	for (size_t i = 0; true; i++) {
		double temp;
		cout << "-> Enter score " << i + 1 << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1)
			break;
		doubleVector_ex.push_back(temp);
		if (temp > max_ex)
			max_ex = temp;
	}	
	max_ex /= 100.0;
	cout << "-> ";
	for (size_t i = 0; i < doubleVector_ex.size(); i++) {
		doubleVector_ex[i] /= max_ex;
		cout << doubleVector_ex[i] << " ";
	}
	cout << endl;
	cout << "d) vector Details" << endl;
	cout << "   d.1) Constructors and Destructors" << endl;
	// Creates a vector of ints with zero elements
	vector<int> intVector_1;
	// Creates vector of 10 ints with value 100
	vector<int> intVector_2(10, 100);
	vector<string> stringVector(10, "hello");
	vector<Element> elementVector;
	vector<int> intVector_3({ 1,2,3,4,5,6 });
	vector<int> intVector_4 = { 1,2,3,4,5,6 };
	vector<Element>* elementVector_1 = new vector<Element>(10);
	delete elementVector_1;
	shared_ptr<vector<Element>> elementVector_2(new vector<Element>(10));
	cout << "e) Copying and Assigning vectors" << endl;
	vector<int> intVector_5(10, 0);
	// Other code . . .
	intVector_5.assign(5, 100);
	intVector_5.assign({ 1, 2, 3, 4 });
	vector<int> vectorOne(10, 0);
	vector<int> vectorTwo(5, 100);
	vectorOne.swap(vectorTwo);
	// vectorOne now has 5 elements with the value 100.
	// vectorTwo now has 10 elements with the value 0.
	cout << "f) Comparing vectors" << endl;
	vector<int> vectorOne_(10, 0);
	vector<int> vectorTwo_(10, 0);
	if (vectorOne_ == vectorTwo_)
		cout << "-> equal!" << endl;
	else
		cout << "-> not equal!" << endl;
	vectorOne_[3] = 50;
	if (vectorOne_ < vectorTwo_)
		cout << "-> vectorOne is less than vectorTwo" << endl;
	else
		cout << "-> vectorOne is not less than vectorTwo" << endl;


	cout << "g) vector Iterators" << endl;
	vector<double> doubleVector_g;
	// Initialize max to smallest number
	double max_g = numeric_limits<double>::lowest();
	for (size_t i = 0; true; i++) {
		double temp;
		cout << "-> Enter score " << i + 1 << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1)
			break;
		doubleVector_g.push_back(temp);
		if (temp > max_g)
			max_g = temp;
	}
	max_g /= 100.0;
	//cout << "-> ";
	//for (vector<double>::iterator iter = doubleVector_g.begin();
	//	iter != doubleVector_g.end(); ++iter) {
	//	*iter /= max_g;
	//	cout << *iter << " ";
	//}
	//cout << "-> ";
	//for (auto iter = doubleVector_g.begin();
	//	iter != doubleVector_g.end(); ++iter) {
	//	*iter /= max_g;
	//	cout << *iter << " ";
	//}
	cout << "-> ";
	for (auto& d : doubleVector_g) {
		d /= max_g;
		cout << d << " ";
	}
	cout << endl;
	cout << "h) Accessing Fields of Object Elements" << endl;
	vector<string> stringVector_h(10, "hello");
	for (auto& str : stringVector_h)
		str.append(" there");
	cout << "   h.1) const_iterator" << endl;
	vector<string> stringVector_h1(10, "hello");
	for (auto iter = stringVector_h1.cbegin();
		iter != stringVector_h1.cend(); ++iter)
		cout << "-> " << *iter << endl;
	cout << "   h.2) Iterator Safety" << endl;
	vector<int> intVector_h2;
	auto it = intVector_h2.end();
	// BUG! it doesn't refer to a valid element.
	//*it = 10;
	vector<int> vectorOne_h2(10);
	vector<int> vectorTwo_h2(10);
	// Fill in the vectors..
	// BUG! Infinite loop
	//for (auto it = vectorTwo.begin(); it != vectorOne.end(); ++it)
		// loop body
	cout << "   h.3) Other Iterator Operations" << endl;
	vector<int> intVector_h3(10, 0);
	auto it_ = intVector_h3.begin();
	it_ += 5;
	--it_;
	*it_ = 4;
	cout << "   h.4) Iterators versus Indexing" << endl;
	cout << "i) Adding and Removing Elements" << endl;
	vector<int> vectorOne_i = { 1,2,3,5 };
	vector<int> vectorTwo_i;
	// Oops, we forgot to add 4. Insert it in the correct place.
	vectorOne_i.insert(vectorOne_i.begin() + 3, 4);
	// Add elements 6 through 10 to vectorTwo
	for (int i = 6; i <= 10; i++)
		vectorTwo_i.push_back(i);
	printVector(vectorOne_i);
	printVector(vectorTwo_i);
	// Add all the elements from vectorTwo to the end of vectorOne.
	vectorOne_i.insert(vectorOne_i.end(), vectorTwo_i.begin(), vectorTwo_i.end());
	printVector(vectorOne_i);
	// Now erase the numbers 2 through 5 in vectorOne
	vectorOne_i.erase(vectorOne_i.begin() + 1, vectorOne_i.begin() + 5);
	printVector(vectorOne_i);
	// Clear vectorTwo entirely.
	vectorTwo_i.clear();
	// And add 10 copies of the value 100
	vectorTwo_i.insert(vectorTwo_i.begin(), 10, 100);
	// Decide we only want 9 elements.
	vectorTwo_i.pop_back();
	printVector(vectorTwo_i);
	cout << "   i.1) Algorithmic Complexity and Iterator Invalidation" << endl;
	cout << "j) The vector Memory Allocation Scheme" << endl;
	cout << "   j.1) Size and Capacity" << endl;
	cout << "   j.1) Reserving Capacity" << endl;
	cout << "k) vector Example: A Round-Robin Class" << endl;
	vector<Process> processes = { Process("1"), Process("2"), Process("3") };
	Scheduler sched(processes);
	for (int i = 0; i < 4; ++i)
		sched.scheduleTimeSlice();
	sched.removeProcess(processes[1]);
	cout << "-> Removed second process" << endl;
	for (int i = 0; i < 4; ++i)
		sched.scheduleTimeSlice();
}