//#pragma once
//
//#include "pch.h"
//#include <string>
//
//// forward class declarations
//class MyInt;
//class MyString;
//
//class MyInt {
//public:
//	MyInt(int i) : m_i(i) {}
//	MyInt operator+(const MyString& rhs) const;
//	int getInt() const { return m_i; }
//	friend ostream& operator<<(ostream&, const MyInt&);
//protected:
//	int m_i;
//};
//
//class MyString {
//public:
//	MyString(string str) : m_str(str) {}
//	MyString operator+(const MyInt& rhs) const;
//	const string& getString() const { return m_str; }
//	friend ostream& operator<<(ostream&, const MyString&);
//protected:
//	string m_str;
//};
//
//// it remains a mystery why the keyword: inline has to be added
//inline MyInt MyInt::operator+(const MyString& rhs) const {
//	return m_i + stoi(rhs.getString());
//}
//
//inline ostream& operator<<(ostream& os, const MyInt& myint) {
//	os << myint.m_i;
//	return os;
//}
//
//// it remains a mystery why the keyword: inline has to be added
//inline MyString MyString::operator+(const MyInt& rhs) const {
//	string str = m_str;
//	str.append(to_string(rhs.getInt()));
//	return str;
//}
//
//inline ostream& operator<<(ostream& os, const MyString& mystring) {
//	os << mystring.m_str;
//	return os;
//}
