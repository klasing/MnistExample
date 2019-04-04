#include "pch.h"

#include <string>

class Book {
public:
	virtual string getDescription() { return "Book"; }
	virtual int getHeight() { return 120; }
};

class Paperback : public Book {
public:
	virtual string getDescription() {
		return "Paberback " + __super::getDescription();
	}
};

class Romance : public Paperback {
public:
	virtual string getDescription() {
		return "Romance " + __super::getDescription();
	}
	virtual int getHeight() { return __super::getHeight() / 2; }
};

class Technical : public Book {
public:
	virtual string getDescription() {
		return "Technical " + __super::getDescription();
	}
};

inline int main_8_3_3() {
	Romance novel;
	Book book;

	// Outputs "Romance Paperback Book"
	cout << "-> " << novel.getDescription() << endl;
	// Outputs "Book"
	cout << "-> " << book.getDescription() << endl;
	// outputs "60"
	cout << "-> " << novel.getHeight() << endl;
	// Outputs "120"
	cout << "-> " << book.getHeight() << endl;

	return 0;
}

inline void subParagraph_8_3_3() {
	cout << "Referring to Parent Names" << endl;
	cout << "-------------------------" << endl;

	main_8_3_3();
}