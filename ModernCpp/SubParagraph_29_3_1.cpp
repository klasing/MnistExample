#include "pch.h"

#include <memory>
#include <vector>

class Car_29_3_1 {
public:
	virtual void info() = 0;
};

class Ford_29_3_1 : public Car_29_3_1 {
public:
	virtual void info() { cout << "-> Ford" << endl; }
};

class Toyota_29_3_1 : public Car_29_3_1 {
public:
	virtual void info() { cout << "-> Toyota" << endl; }
};

class CarFactory_29_3_1 {
public:
	CarFactory_29_3_1() : mNumCarsInProduction(0) {}
	Car_29_3_1* requestCar() { 
		mNumCarsInProduction++;
		return createCar();
	}
	int getNumCarsInProduction() const {
		return mNumCarsInProduction;
	}
protected:
	virtual Car_29_3_1* createCar() = 0;
private:
	int mNumCarsInProduction;
};

class FordFactory_29_3_1 : public CarFactory_29_3_1 {
protected:
	virtual Car_29_3_1* createCar() { 
		return new Ford_29_3_1;
	}
};

class ToyotaFactory_29_3_1 : public CarFactory_29_3_1 {
protected:
	virtual Car_29_3_1* createCar() { 
		return new Toyota_29_3_1;
	}
};

inline shared_ptr<CarFactory_29_3_1> getLeastBusyFactory(
	const vector<shared_ptr<CarFactory_29_3_1>>& inFactories) {
	if (inFactories.size() == 0)
		return nullptr;
	shared_ptr<CarFactory_29_3_1> bestSoFar = inFactories[0];
	for (size_t i = 1; i < inFactories.size(); i++)
		if (inFactories[i]->getNumCarsInProduction() <
			bestSoFar->getNumCarsInProduction())
			bestSoFar = inFactories[i];
	return bestSoFar;
}

inline void subParagraph_29_3_1() {
	cout << "Example: A Car Factory Simulation" << endl;
	cout << "---------------------------------" << endl;

	ToyotaFactory_29_3_1 myFactory;
	Car_29_3_1* myCar = myFactory.requestCar();

	vector<shared_ptr<CarFactory_29_3_1>> factories;
	// Create 3 Ford factories and 1 Toyota factory.
	auto factory1 = make_shared<FordFactory_29_3_1>();
	auto factory2 = make_shared<FordFactory_29_3_1>();
	auto factory3 = make_shared<FordFactory_29_3_1>();
	auto factory4 = make_shared<ToyotaFactory_29_3_1>();
	// To get more interesting results, preorder some cars.
	factory1->requestCar();
	factory1->requestCar();
	factory2->requestCar();
	factory4->requestCar();
	// Add the factories to a vector
	factories.push_back(factory1);
	factories.push_back(factory2);
	factories.push_back(factory3);
	factories.push_back(factory4);
	// Build 10 cars from the least busy factory.
	for (size_t i = 0; i < 10; i++) {
		shared_ptr<CarFactory_29_3_1> currentFactory = getLeastBusyFactory(factories);
		shared_ptr<Car_29_3_1> theCar(currentFactory->requestCar());
		theCar->info();
	}
}