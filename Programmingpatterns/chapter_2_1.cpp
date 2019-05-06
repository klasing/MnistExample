#include <iostream>
#include <string>
#include <memory>

using namespace std;
// "Product"
class Pizza_2_1 {
public:
	void setDough(const string& dough) { m_dough = dough; }
	void setSauce(const string& sauce) { m_sauce = sauce; }
	void setTopping(const string& topping) { m_topping = topping; }
	void open() const {
		cout << "-> Pizza with " << m_dough << " dough, " << m_sauce
			<< " sauce and " << m_topping << " topping. Mmm." << endl;
	}
private:
	string m_dough;
	string m_sauce;
	string m_topping;
};

// "Abstract Builder"
class PizzaBuilder_2_1 {
public:
	virtual ~PizzaBuilder_2_1() {}
	Pizza_2_1* getPizza() { return m_pizza.release(); }
	void createNewPizzaProduct() { m_pizza = make_unique<Pizza_2_1>(); }
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
protected:
	unique_ptr<Pizza_2_1> m_pizza;
};

class HawaiianPizzaBuilder_2_1 : public PizzaBuilder_2_1 {
public:
	virtual ~HawaiianPizzaBuilder_2_1() {}
	virtual void buildDough() { m_pizza->setDough("cross"); };
	virtual void buildSauce() { m_pizza ->setSauce("mild"); };
	virtual void buildTopping() { m_pizza->setTopping("ham+pinapple"); };
};

class SpicyPizzaBuilder_2_1 : public PizzaBuilder_2_1 {
public:
	virtual ~SpicyPizzaBuilder_2_1() {}
	virtual void buildDough() { m_pizza->setDough("pan baked"); };
	virtual void buildSauce() { m_pizza->setSauce("hot"); };
	virtual void buildTopping() { m_pizza->setTopping("pepperoni+salami"); };
};

class Cook_2_1 {
public:
	void openPizza() {
		m_pizzaBuilder->getPizza()->open();
	}
	void makePizza(PizzaBuilder_2_1* pb) {
		m_pizzaBuilder = pb;
		m_pizzaBuilder->createNewPizzaProduct();
		m_pizzaBuilder->buildDough();
		m_pizzaBuilder->buildSauce();
		m_pizzaBuilder->buildTopping();
	}
private:
	PizzaBuilder_2_1* m_pizzaBuilder;
};

inline void chapter_2_1() {
	cout << "Builder" << endl;
	cout << "-------" << endl;

	Cook_2_1 cook;
	HawaiianPizzaBuilder_2_1 hawaiianPizzaBuilder;
	SpicyPizzaBuilder_2_1 spicyPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();

	cook.makePizza(&spicyPizzaBuilder);
	cook.openPizza();
}