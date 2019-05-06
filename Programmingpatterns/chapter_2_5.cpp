#include <iostream>
#include <string>
#include <memory>

using namespace std;
class StringSingleton_2_5 {
public:
	// Some accessor functions for the class, itself.
	string GetString() const { return mString; }
	void SetString(const string& newStr) { mString = newStr; }

	// The magic function, which allows access to the class from anywhere
	// To get the value of the instance of the class, call:
	//     StringSingleton_2_5::Instance().getString();
	static StringSingleton_2_5& Instance() {
		// This line only runs once, thus creating the only instance in existence
		//static auto_ptr<StringSingleton_2_5> instance(new StringSingleton_2_5);
		// auto_ptr is deprecated, unique_ptr is used instead
		static unique_ptr<StringSingleton_2_5> instance(new StringSingleton_2_5);
		// dereferencing the variable here, saves the caller from having to use
		// the arrow operator,and removes temptation to try and delete the
		// returned instance.
		// always returns the same instance
		return *instance;
	}

	~StringSingleton_2_5() {}
private:
	// We need to make some given functions private to finish the definition of the singleton.
	// default constructor available only to members or friends of this class
	StringSingleton_2_5() {}

	// Note that the next two function are not given bodies, thus any attempt
	// to call them implicitly will return compiler errors. This prevents 
	// accidental copying of the only instance of the class.
	// disallow copy constructor
	StringSingleton_2_5(const StringSingleton_2_5& old) = delete;
	// disallow assignment operator
	const StringSingleton_2_5& operator= (const StringSingleton_2_5& old) = delete;

	// Note that although this should be allowed,
	// some compilers may not implement private destructors.
	// This prevents others from deleting our one sigle instance, 
	// which was otherwise created on the heap.
	//~StringSingleton_2_5() {}
private:
	// private data for an instance of this class
	string mString;
};

// example two
/* Place holder for thread synchronization mutex */
class Mutex_2_5 {
	// placeholder for code to create, use, and free a mutex */
};

/* Place holder for thread synchronization Lock */
class Lock_2_5 {
public:
	Lock_2_5(Mutex_2_5& m) : mutex(m) {
		/* placeholder code to aquire the mutex*/
	}
	~Lock_2_5() {
		/* placeholder code to release the mutex*/
	}
private:
	Mutex_2_5& mutex;
};

class Singleton_2_5 {
public:
	static Singleton_2_5* GetInstance() {
		Lock_2_5 lock(mutex);

		cout << "-> Get Instance" << endl;

		// Initialized during first access
		static Singleton_2_5 inst(1);

		return &inst;
	}
	int a;
	~Singleton_2_5() { cout << "-> In Destructor" << endl; }
private:
	Singleton_2_5(int _a) : a(_a) { cout << "-> In Constructor" << endl; }

	static Mutex_2_5 mutex;

	// Not defined, to prevent copying
	Singleton_2_5(const Singleton_2_5&) = delete;
	Singleton_2_5& operator= (const Singleton_2_5& other) = delete;
};

inline void chapter_2_5() {
	cout << "Singleton" << endl;
	cout << "---------" << endl;

	StringSingleton_2_5::Instance().SetString("singleton");
	cout << "-> " << StringSingleton_2_5::Instance().GetString() << endl;

	// example two
	Singleton_2_5* singleton = Singleton_2_5::GetInstance();
	cout << "-> The value of singleton: " << singleton->a << endl;
}