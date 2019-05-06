#include <atlstr.h>
#include <assert.h>

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

/** Record is the base Prototype */
class Record_2_4 {
public:
	virtual ~Record_2_4() {}
	virtual void print() = 0;
	virtual unique_ptr<Record_2_4> clone() = 0;
};

/** CarRecord is a Concrete Prototype */
class CarRecord_2_4 : public Record_2_4 {
private:
	string m_carName;
	int m_ID;

public:
	CarRecord_2_4(string carName, int ID) : m_carName(carName), m_ID(ID) {}
	void print() override {
		cout << "-> Car Record" << endl
			<< "-> Name  : " << m_carName << endl
			<< "-> Number: " << m_ID << endl << endl;
	}
	unique_ptr<Record_2_4> clone() override {
		return make_unique<CarRecord_2_4>(*this);
	}
};

/** BikeRecord is the Concrete Prototype */
class BikeRecord_2_4 : public Record_2_4 {
private:
	string m_bikeName;
	int m_ID;
public:
	BikeRecord_2_4(string bikeName, int ID) : m_bikeName(bikeName), m_ID(ID) {}
	void print() override {
		cout << "-> Bike Record" << endl
			<< "-> Name  : " << m_bikeName << endl
			<< "-> Number: " << m_ID << endl << endl;
	}
	unique_ptr<Record_2_4> clone() override {
		return make_unique<BikeRecord_2_4>(*this);
	}
};

/** PersonRecord is the Concrete Prototype */
class PersonRecord_2_4 : public Record_2_4 {
private:
	string m_personName;
	int m_age;
public:
	PersonRecord_2_4(string personName, int age) : m_personName(personName), m_age(age) {}
	void print() override {
		cout << "-> Person Record" << endl
			<< "-> Name  : " << m_personName << endl
			<< "-> Age   : " << m_age << endl << endl;
	}
	unique_ptr<Record_2_4> clone() override {
		return make_unique<PersonRecord_2_4>(*this);
	}
};

/** Opaque record type, avoids exposing concrete implementations */
enum RecordType_2_4 {
	CAR,
	BIKE,
	PERSON
};

/** RecordFactory is the client */
class RecordFactory_2_4 {
private:
	unordered_map<RecordType_2_4, unique_ptr<Record_2_4>, hash<int> > m_records;

public:
	RecordFactory_2_4() {
		m_records[CAR] = make_unique<CarRecord_2_4>("Ferrari", 5050);
		m_records[BIKE] = make_unique<BikeRecord_2_4>("Yamaha", 2525);
		m_records[PERSON] = make_unique<PersonRecord_2_4>("Tom", 25);
	}

	unique_ptr<Record_2_4> createRecord(RecordType_2_4 recordType) {
		return m_records[recordType]->clone();
	}
};

// second example
class CPrototypeMonster_2_4 {
protected:
	CString _name;
public:
//	CPrototypeMonster_2_4() {}
//	CPrototypeMonster_2_4(const CPrototypeMonster_2_4& copy);
	virtual ~CPrototypeMonster_2_4() {}

	// This forces every derived class to provide an override for this function.
	virtual CPrototypeMonster_2_4* Clone() const = 0;
	void Name(CString name) {
		_name = name;
	}
	CString Name() const { return _name; }
	virtual void print() = 0;
};

class CGreenMonster_2_4 : public CPrototypeMonster_2_4 {
protected:
	int _numberOfArms;
	double _slimeAvailable;
public:
//	CGreenMonster_2_4() {}
//	CGreenMonster_2_4(const CGreenMonster_2_4& copy);
//	~CGreenMonster_2_4();

	virtual CPrototypeMonster_2_4* Clone() const {
		return new CGreenMonster_2_4(*this);
	}
	void print() override {
		wcout << "-> Created GreenMonster " << (const wchar_t*)Name()
			<< " NumberOfArms: " << _numberOfArms 
			<< " SlimeAvailable: " << _slimeAvailable << endl;
	}
	void NumberOfArms(int numberOfArms) { _numberOfArms = numberOfArms; }
	void SlimeAvailable(double slimeAvailable) { _slimeAvailable = slimeAvailable; }

	int NumberOfArms() const { return _numberOfArms; }
	double SlimeAvailable() const { return _slimeAvailable; }
};

class CPurpleMonster_2_4 : public CPrototypeMonster_2_4 {
protected:
	int _intensityOfBadBreath;
	double _lengthOfWhiplikeAntenna;
public:
//	CPurpleMonster_2_4() {}
//	CPurpleMonster_2_4(const CPurpleMonster_2_4& copy);
//	~CPurpleMonster_2_4();

	virtual CPrototypeMonster_2_4* Clone() const {
		return new CPurpleMonster_2_4(*this);
	}
	void print() override {
		wcout << "-> Created PurpleMonster " << (const wchar_t*)Name() 
			<< " IntensityOfBadBreath: " << _intensityOfBadBreath
			<< " LengthOfWhiplikeAntenna: " << _lengthOfWhiplikeAntenna << endl;
	}
	void IntensityOfBadBreath(int intensityOfBadBreath) {
		_intensityOfBadBreath = intensityOfBadBreath;
	}
	void LengthOfWhiplikeAntenna(double lengthOfWhiplikeAntenna) {
		_lengthOfWhiplikeAntenna = lengthOfWhiplikeAntenna;
	}

	int IntensityOfBadBreath() const { return _intensityOfBadBreath; }
	double LengthOfWhiplikeAntenna() const { return _lengthOfWhiplikeAntenna; }
};

class CBellyMonster_2_4 : public CPrototypeMonster_2_4 {
protected:
	double _roomAvailableInBelly;
public:
//	CBellyMonster_2_4() {}
//	CBellyMonster_2_4(const CBellyMonster_2_4& copy);
//	~CBellyMonster_2_4();

	virtual CPrototypeMonster_2_4* Clone() const {
		return new CBellyMonster_2_4(*this);
	}
	void print() override {
		wcout << "-> Created BellyMonster " << (const wchar_t*)Name() 
			<< " RoomAvailableInBelly: " << _roomAvailableInBelly << endl;
	}

	void RoomAvailableInBelly(double roomAvailableInBelly) { _roomAvailableInBelly = roomAvailableInBelly; }
	double RoomAvailableInBelly() const { return _roomAvailableInBelly; }
};

inline void DoSomeStuffWithAMonster(const CPrototypeMonster_2_4* originalMonster) {
	CPrototypeMonster_2_4* newMonster = originalMonster->Clone();
	assert(newMonster);

	newMonster->Name(_T("MyOwnMonster"));
	// Add code doing all sorts of cool stuff with the monster.
	//wcout << "-> Created " << (const wchar_t*)newMonster->Name() << endl;
	newMonster->print();
	delete newMonster;
}

inline void chapter_2_4() {
	cout << "Prototype" << endl;
	cout << "---------" << endl;

	RecordFactory_2_4 recordFactory;

	auto record = recordFactory.createRecord(CAR);
	record->print();

	record = recordFactory.createRecord(BIKE);
	record->print();

	record = recordFactory.createRecord(PERSON);
	record->print();

	// second example
	CGreenMonster_2_4* originalGreenMonster = new CGreenMonster_2_4();
	originalGreenMonster->NumberOfArms(18);
	originalGreenMonster->SlimeAvailable(.56);
	DoSomeStuffWithAMonster(originalGreenMonster);

	CPurpleMonster_2_4* originalPurpleMonster = new CPurpleMonster_2_4();
	originalPurpleMonster->IntensityOfBadBreath(56);
	originalPurpleMonster->LengthOfWhiplikeAntenna(3.2);
	DoSomeStuffWithAMonster(originalPurpleMonster);

	CBellyMonster_2_4* originalBellyMonster = new CBellyMonster_2_4();
	originalBellyMonster->RoomAvailableInBelly(24.9);
	DoSomeStuffWithAMonster(originalBellyMonster);

	delete originalGreenMonster;
	originalGreenMonster = nullptr;

	delete originalPurpleMonster;
	originalPurpleMonster = nullptr;

	delete originalBellyMonster;
	originalBellyMonster = nullptr;
}