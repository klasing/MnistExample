#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Our abstract base class
class Car_3_4 {
protected:
	string _str;
public:
	Car_3_4() { _str = "Unknown Car"; }
	virtual string getDescription() { return _str; }
	virtual double getCost() = 0;
	virtual ~Car_3_4() { cout << "-> ~Car()\n"; }
};

// Decorator Base class
class OptionsDecorator_3_4 : public Car_3_4 {
public:
	virtual string getDescription() = 0;
	virtual ~OptionsDecorator_3_4() { cout << "-> ~OptionsDecorator()\n"; }
};

class CarModel1_3_4 : public Car_3_4 {
public:
	CarModel1_3_4() { _str = "CarModel1_3_4"; }
	virtual double getCost() { return 31000.23; }
	~CarModel1_3_4() { cout << "-> ~CarModel1()\n"; }
};

class Navigation_3_4 : public OptionsDecorator_3_4 {
	Car_3_4* _b;
public:
	Navigation_3_4(Car_3_4* b) { _b = b; }
	string getDescription() { return _b->getDescription() + ", Navigation"; }
	double getCost() { return 300.56 + _b->getCost(); }
	~Navigation_3_4() {
		cout << "-> ~Navigation()\n";
		delete _b;
	}
};

class PremiumSoundSystem_3_4 : public OptionsDecorator_3_4 {
	Car_3_4* _b;
public:
	PremiumSoundSystem_3_4(Car_3_4* b) { _b = b; }
	string getDescription() { return _b->getDescription() + ", PremiumSoundSystem"; }
	double getCost() { return 0.30 + _b->getCost(); }
	~PremiumSoundSystem_3_4() {
		cout << "-> ~PremiumSoundSystem()\n";
		delete _b;
	}
};

class ManualTransmission_3_4 : public OptionsDecorator_3_4 {
	Car_3_4* _b;
public:
	ManualTransmission_3_4(Car_3_4* b) { _b = b; }
	string getDescription() { return _b->getDescription() + ", ManualTransmission"; }
	double getCost() { return 0.30 + _b->getCost(); }
	~ManualTransmission_3_4() {
		cout << "-> ~ManualTransmission()\n";
		delete _b;
	}
};

// example two
class Interface_3_4 {
public:
	virtual ~Interface_3_4() {}
	virtual void write(string&) = 0;
};

class Core_3_4 : public Interface_3_4 {
public:
	virtual ~Core_3_4() { cout << "-> Core destructor called.\n"; }
	// Do nothing
	virtual void write(string&) override {}
};

class Decorator_3_4 : public Interface_3_4 {
private:
	unique_ptr<Interface_3_4> interf;
public:
	Decorator_3_4(unique_ptr<Interface_3_4> c) { interf = move(c); }
	virtual void write(string& text) override { interf->write(text); }
};

class MessengerWithSalutation_3_4 : public Decorator_3_4 {
private:
	string salutation;
public:
	MessengerWithSalutation_3_4(unique_ptr<Interface_3_4> c, const string& str) :
		Decorator_3_4(move(c)), salutation(str) {}
	~MessengerWithSalutation_3_4() { cout << "-> Messenger destructor called.\n"; }
	virtual void write(string& text) override {
		text = salutation + "\n\n-> " + text;
		Decorator_3_4::write(text);
	}
};

class MessengerWithValediction_3_4 : public Decorator_3_4 {
private:
	string valediction;
public:
	MessengerWithValediction_3_4(unique_ptr<Interface_3_4> c, const string& str) :
		Decorator_3_4(move(c)), valediction(str) {}
	~MessengerWithValediction_3_4() { cout << "-> MessengerWithValediction destructor called.\n"; }
	virtual void write(string& text) override {
		Decorator_3_4::write(text);
		text += "\n\n-> " + valediction;
	}
};

inline void chapter_3_4() {
	cout << "Decorator" << endl;
	cout << "---------" << endl;

	// Create our Car that we want to buy
	Car_3_4* b = new CarModel1_3_4();

	cout << "-> Base model of " << b->getDescription() << " costs $" << b->getCost() << "\n";

	// Who wants base model. Let's add some more features.

	b = new Navigation_3_4(b);
	cout << "-> " << b->getDescription() << " will cost you $" << b->getCost() << "\n";
	b = new PremiumSoundSystem_3_4(b);
	b = new ManualTransmission_3_4(b);
	cout << "-> " << b->getDescription() << " will cost you $" << b->getCost() << "\n";

	// WARNING! Here we leak the CarModel1, Navigation and PremiumsoundSystem objects!
	// Either we delete them explicitly or rewrite the Decorators to take
	// ownership and delete their Cars when destroyed.
	delete b;

	// exampe two
	const string salutation = "Greetings,";
	const string valediction = "Sincerly, Andy";
	string message1 = "This message is not decorated.";
	string message2 = "This message is decorated with a salutation.";
	string message3 = "This message is decorated with a valediction.";
	string message4 = "This message is decorated with a salutation and a valediction.";

	unique_ptr<Interface_3_4> messenger1 = make_unique<Core_3_4>();
	unique_ptr<Interface_3_4> messenger2 = make_unique<MessengerWithSalutation_3_4>(make_unique<Core_3_4>(), salutation);
	unique_ptr<Interface_3_4> messenger3 = make_unique<MessengerWithValediction_3_4>(make_unique<Core_3_4>(), valediction);
	unique_ptr<Interface_3_4> messenger4 = make_unique<MessengerWithValediction_3_4>(make_unique<MessengerWithSalutation_3_4>
		(make_unique<Core_3_4>(), salutation), valediction);

	messenger1->write(message1);
	cout << "-> " << message1 << '\n';
	cout << "\n-> ------------------------------\n\n";

	messenger2->write(message2);
	cout << "-> " << message2 << '\n';
	cout << "\n-> ------------------------------\n\n";

	messenger3->write(message3);
	cout << "-> " << message3 << '\n';
	cout << "\n-> ------------------------------\n\n";

	messenger4->write(message4);
	cout << "-> " << message4 << '\n';
	cout << "\n-> ------------------------------\n\n";
}