#include <stdexcept>
#include <iostream>
#include <memory>

using namespace std;
class Computer_2_3 {
public:
	virtual void Run() = 0;
	virtual void Stop() = 0;
	/* without this, you do not call Laptop or Desktop destructor in this example! */
	virtual ~Computer_2_3() {}
	virtual string toString() = 0;
};

class Laptop_2_3 : public Computer_2_3 {
public:
	void Run() override { mHibernating = false; }
	void Stop() override { mHibernating = true; }
	/* because we have virtual functions, we need virtual destructor */
	virtual ~Laptop_2_3() {}
	string toString() {
		return ((mHibernating) ? "hibernating" : "up and running");
	}
private:
	// Whether or not the machine is hibernating
	bool mHibernating;
};

class Desktop_2_3 : public Computer_2_3 {
public:
	void Run() override { mOn = true; }
	void Stop() override { mOn = false; }
	virtual ~Desktop_2_3() {}
	string toString() {
		return ((mOn) ? "on" : "off");
	}
private:
	// Whether or not the machine has been turned on
	bool mOn;
};

class ComputerFactory_2_3 {
public:
	static Computer_2_3* NewComputer(const string& description) {
		if (description == "laptop")
			return new Laptop_2_3;
		if (description == "desktop")
			return new Desktop_2_3;
		return nullptr;
	}
};

// second example
class Pizza_2_3 {
public:
	virtual int getPrice() const = 0;
	/* without this, no destructor for derived Pizza's will be callend. */
	virtual ~Pizza_2_3() {}
};

class HamAndMushroomPizza_2_3 : public Pizza_2_3 {
public:
	virtual int getPrice() const { return 850; }
	virtual ~HamAndMushroomPizza_2_3() {}
};

class DeluxePizza_2_3 : public Pizza_2_3 {
public:
	virtual int getPrice() const { return 1050; }
	virtual ~DeluxePizza_2_3() {}
};

class HawaiianPizza_2_3 : public Pizza_2_3 {
public:
	virtual int getPrice() const { return 1150; }
	virtual ~HawaiianPizza_2_3() {}
};

class PizzaFactory_2_3 {
public:
	enum PizzaType {
		HamMushroom,
		Deluxe,
		Hawaiian
	};

	static unique_ptr<Pizza_2_3> createPizza(PizzaType pizzaType) {
		switch (pizzaType) {
		case HamMushroom: return make_unique<HamAndMushroomPizza_2_3>();
		case Deluxe: return make_unique<DeluxePizza_2_3>();
		case Hawaiian: return make_unique<HawaiianPizza_2_3>();
		}
		throw "invallid pizza type.";
	}
};

/*
 * Create all avaiable pizzas and print their prices
*/
inline void pizza_information(PizzaFactory_2_3::PizzaType pizzatype) {
	unique_ptr<Pizza_2_3> pizza = PizzaFactory_2_3::createPizza(pizzatype);
	cout << "-> Price of " << pizzatype << " is " << pizza->getPrice() << endl;
}

inline void chapter_2_3() {
	cout << "Abstract Factory" << endl;
	cout << "----------------" << endl;

	Computer_2_3* pLaptop = ComputerFactory_2_3::NewComputer("laptop");
	Computer_2_3* pDesktop = ComputerFactory_2_3::NewComputer("desktop");
	pLaptop->Run();
	pDesktop->Run();
	cout << "-> Laptop is " << pLaptop->toString() << endl;
	cout << "-> Desktop is " << pDesktop->toString() << endl;
	pLaptop->Stop();
	pDesktop->Stop();
	cout << "-> Laptop is " << pLaptop->toString() << endl;
	cout << "-> Desktop is " << pDesktop->toString() << endl;
	delete pLaptop;
	pLaptop = nullptr;
	delete pDesktop;
	pDesktop = nullptr;

	// second example
	pizza_information(PizzaFactory_2_3::HamMushroom);
	pizza_information(PizzaFactory_2_3::Deluxe);
	pizza_information(PizzaFactory_2_3::Hawaiian);
}