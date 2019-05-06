#include <iostream>

using namespace std;

// Abstract Target
class Hindu_3_1 {
public:
	virtual ~Hindu_3_1() = default;
	virtual void performsHinduRitual() const = 0;
};

// Concrete Target
class HinduFemale_3_1 : public Hindu_3_1 {
public:
	virtual void performsHinduRitual() const override {
		cout << "-> Hindu girl performs Hindu ritual." << endl;
	}
};

// Abstract Adaptee
class Muslim_3_1 {
public:
	virtual ~Muslim_3_1() = default;
	virtual void performsMuslimRitual() const = 0;
};

// Concrete Adaptee
class MuslimFemale_3_1 : public Muslim_3_1 {
public:
	virtual void performsMuslimRitual() const override {
		cout << "-> Muslim girl performs Muslim ritual." << endl;
	}
};

class HinduRitual_3_1 {
public:
	void carryOutRitual(Hindu_3_1* hindu) {
		cout << "-> On with the Hindu rituals!" << endl;
		hindu->performsHinduRitual();
	}
};

// Adapter
class HinduAdapter_3_1 : public Hindu_3_1 {
private:
	Muslim_3_1* muslim;
public:
	HinduAdapter_3_1(Muslim_3_1* m) : muslim(m) {}
	virtual void performsHinduRitual() const override {
		muslim->performsMuslimRitual();
	}
};

inline void chapter_3_1() {
	cout << "Adapter" << endl;
	cout << "-------" << endl;

	// Client code
	HinduFemale_3_1* hinduGirl = new HinduFemale_3_1;
	MuslimFemale_3_1* muslimGirl = new MuslimFemale_3_1;
	HinduRitual_3_1 hinduRitual;
	// Will not compile of course since the parameter must be of type Hindu_3_1*
	//hinduRitual.carryOutRitual(muslimGirl);
	// muslimGirl has adapted to become a Hindu!
	HinduAdapter_3_1* adaptedMuslim = new HinduAdapter_3_1(muslimGirl);

	hinduRitual.carryOutRitual(hinduGirl);
	// So now muslimGirl, in the form of adaptedMuslim, participates in the hinduRitual!
	// Note that muslimGirl is carrying out her own type of ritual in hinduRitual though.
	hinduRitual.carryOutRitual(adaptedMuslim);

	// adpatedMuslim is not needed anymore
	delete adaptedMuslim;
	// muslimGirl is not needed anymore
	delete muslimGirl;
	// hinduGirl is not neede anymore, too
	delete hinduGirl;
}