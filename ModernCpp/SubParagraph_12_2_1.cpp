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
	for (size_t i = 0; i < 10; i++) {
		double temp;
		cout << "-> Enter score " << i + 1 << "(-1 to stop): ";
		cin >> temp;
		if (temp == -1)
			break;
		doubleVector_ex.push_back(temp);
		if (temp < max_ex)
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

	cout << "e) Copying and Assigning vectors" << endl;
	cout << "f) Comparing vectors" << endl;
	cout << "g) vector Iterators" << endl;
	cout << "h) Accessing Fields of Object Elements" << endl;
	cout << "   h.1) const_iterator" << endl;
	cout << "   h.2) Iterator Safety" << endl;
	cout << "   h.3) Other Iterator Operations" << endl;
	cout << "   h.4) Iterators versus Indexing" << endl;
	cout << "i) Adding and Removing Elements" << endl;

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