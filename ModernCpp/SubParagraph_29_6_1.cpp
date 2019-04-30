#include "pch.h"

#include <string>

class Paragraph_29_6_1 {
public:
	Paragraph_29_6_1(const string& initialText) : mText(initialText) {}
	virtual string getHTML() const { return mText; }
protected:
	string mText;
};

class BoldParagraph_29_6_1 : public Paragraph_29_6_1 {
public:
	BoldParagraph_29_6_1(const Paragraph_29_6_1& inParagraph) : 
		Paragraph_29_6_1(""), mWrapped(inParagraph) {}
	virtual string getHTML() const { 
		return "<B>" + mWrapped.getHTML() + "</B>";
	}
protected:
	const Paragraph_29_6_1& mWrapped;
};

class ItalicParagraph_29_6_1 : public Paragraph_29_6_1 {
public:
	ItalicParagraph_29_6_1(const Paragraph_29_6_1& inParagraph) :
		Paragraph_29_6_1(""), mWrapped(inParagraph) {}
	virtual string getHTML() const {
		return "<I>" + mWrapped.getHTML() + "</I>";
	}
protected:
	const Paragraph_29_6_1& mWrapped;
};

inline void subParagraph_29_6_1() {
	cout << "Example: Defining Styles in Web Pages" << endl;
	cout << "-------------------------------------" << endl;

	Paragraph_29_6_1 p("A party? For me? thanks!");
	// Bold
	cout << BoldParagraph_29_6_1(p).getHTML() << endl;
	// Bold and Italic
	cout << ItalicParagraph_29_6_1(BoldParagraph_29_6_1(p)).getHTML() << endl;
	// the same style twice in a row gives:
	// the compiler is using the build-in copy constructor for BoldParagraph!
	cout << BoldParagraph_29_6_1(BoldParagraph_29_6_1(p)).getHTML() << endl;
}