#include <iostream>
#include <iterator>
#include <vector>
#include <set>

using namespace std;
/*****************************************************************************/
/* Iterator.h                                                                */
/*****************************************************************************/
template<class T, class U>
class Iterator {
public:
	typedef typename vector<T>::iterator iter_type;
	Iterator(U* pData) : m_pData(pData) {
		m_it = m_pData->m_data.begin();
	}
	void first() { m_it = m_pData->m_data.begin(); }
	void next() { m_it++; }
	bool isDone() { return (m_it == m_pData->m_data.end()); }
	iter_type current() { return m_it; }
private:
	U* m_pData;
	iter_type m_it;
};

template<class T, class U, class A>
class setIterator {
public:
	typedef typename set<T, U>::iterator iter_type;

	setIterator(A* pData) : m_pData(pData) {
		m_it = m_pData->m_data.begin();
	}
	void first() { m_it = m_pData->m_data.begin(); }
	void next() { m_it++; }
	bool isDone() { return (m_it == m_pData->m_data.end()); }
	iter_type current() { return m_it; }
private:
	A* m_pData;
	iter_type m_it;
};
/*****************************************************************************/
/* Aggregate.h                                                                */
/*****************************************************************************/
template<class T>
class aggregate {
	friend class Iterator<T, aggregate>;
public:
	void add(T a) { m_data.push_back(a); }
	Iterator<T, aggregate>* create_iterator() {
		return new Iterator<T, aggregate>(this);
	}
private:
	vector<T> m_data;
};

template<class T, class U>
class aggregateSet {
	friend class setIterator<T, U, aggregateSet>;
public:
	void add(T a) { m_data.insert(a); }
	setIterator<T, U, aggregateSet>* create_iterator() {
		return new setIterator<T, U, aggregateSet>(this);
	}
	void print() {
		copy(m_data.begin(), m_data.end(), ostream_iterator<T>(cout, "\n"));
	}
private:
	set<T, U> m_data;
};
/*****************************************************************************/
/* Iterator Test.cpp                                                               */
/*****************************************************************************/
class Money {
public:
	Money(int a = 0) : m_data(a) {}
	void SetMoney(int a) { m_data = a; }
	int GetMoney() { return m_data; }
private:
	int m_data;
};

class Name {
public:
	Name(string name) : m_name(name) {}
	const string& GetName() const { return m_name; }
	friend ostream& operator<<(ostream& out, Name name) {
		out << name.GetName();
		return out;
	}
private:
	string m_name;
};

struct Nameless {
	bool operator() (const Name& lhs, const Name& rhs) const {
		return (lhs.GetName() < rhs.GetName());
	}
};
inline void chapter_4_4() {
	cout << "Iterator" << endl;
	cout << "--------" << endl;

	//sample 1
	cout << "-> ____________Iterator with int____________________________________" << endl;
	aggregate<int> agg;

	for (int i = 0; i < 10; i++)
		agg.add(i);

	Iterator<int, aggregate<int>>* it = agg.create_iterator();
	for (it->first(); !it->isDone(); it->next())
		cout << "-> " << *it->current() << endl;

	//sample 2
	aggregate<Money> agg2;
	Money a(100), b(1000), c(10000);
	agg2.add(a);
	agg2.add(b);
	agg2.add(c);

	cout << "-> ____________Iterator with Class Money____________________________" << endl;
	Iterator<Money, aggregate<Money>>* it2 = agg2.create_iterator();
	for (it2->first(); !it2->isDone(); it2->next())
		cout << "-> " << it2->current()->GetMoney() << endl;

	//sample 3
	cout << "-> ____________Iterator with Class Name_____________________________" << endl;

	aggregateSet<Name, Nameless> aset;
	aset.add(Name("Qmt"));
	aset.add(Name("Bmt"));
	aset.add(Name("Cmt"));
	aset.add(Name("Amt"));

	setIterator<Name, Nameless, aggregateSet<Name, Nameless>>* it3 = aset.create_iterator();
	for (it3->first(); !it3->isDone(); it3->next())
		cout << "-> " << (*it3->current()) << endl;
}