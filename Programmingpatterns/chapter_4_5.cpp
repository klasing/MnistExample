#include <iostream>
#include <string>
#include <list>

using namespace std;

// this example will not work, because of this declaration
// the compiler generates error:
// C2027 use of undefined type 'MediatorInterface'
class MediatorInterface;
// the error is gone by moving the MediatorInterface class 

class ColleaqueInterface {
	string name;
public:
	ColleaqueInterface(const string& newName) : name(newName) {}
	string getName() const { return name; }
	virtual void sendMessage(const MediatorInterface&, const string&) const = 0;
	virtual void receiveMessage(const ColleaqueInterface*, const string&) const = 0;
};

class MediatorInterface {
private:
	list<ColleaqueInterface*> colleaqueList;
public:
	const list<ColleaqueInterface*>& getColleaqueList() const { return colleaqueList; }
	virtual void distributeMessage(const ColleaqueInterface*, const string&) const = 0;
	virtual void registerColleque(ColleaqueInterface* colleaque) {
		colleaqueList.emplace_back(colleaque);
	}
};

class Colleaque : public ColleaqueInterface {
public:
	using ColleaqueInterface::ColleaqueInterface;
	virtual void sendMessage(const MediatorInterface& mediator, const string& message) const override {
		mediator.distributeMessage(this, message);
	}
private:
	virtual void receiveMessage(const ColleaqueInterface* sender, const string& message) const override {
		cout << "-> " << getName() << " received the message from " << sender->getName() << ": "
			<< message << endl;
	}
};

//class MediatorInterface {
//private:
//	list<ColleaqueInterface*> colleaqueList;
//public:
//	const list<ColleaqueInterface*>& getColleaqueList() const { return colleaqueList; }
//	virtual void distributeMessage(const ColleaqueInterface*, const string&) const = 0;
//	virtual void registerColleque(ColleaqueInterface* colleaque) {
//		colleaqueList.emplace_back(colleaque);
//	}
//};

class Mediator : public MediatorInterface {
	virtual void distributeMessage(const ColleaqueInterface* sender, const string& message) const override {
		for (const ColleaqueInterface* x : getColleaqueList())
			// Do not send the message back to the sender
			x->receiveMessage(sender, message);
	}
};
inline void chapter_4_5() {
	cout << "Mediator" << endl;
	cout << "--------" << endl;

	Colleaque* bob = new Colleaque("Bob");
	Colleaque* sam = new Colleaque("Sam");
	Colleaque* frank = new Colleaque("Frank");
	Colleaque* tom = new Colleaque("Tom");
	Colleaque* staff[] = {bob, sam, frank, tom};
	Mediator mediatorStaff, mediatorSamsBuddies;
	for (Colleaque* x : staff)
		mediatorStaff.registerColleque(x);
	bob->sendMessage(mediatorStaff, "I'm quitting this job!");
	mediatorSamsBuddies.registerColleque(frank);
	mediatorSamsBuddies.registerColleque(tom);
	// Sam's buddies only
	sam->sendMessage(mediatorSamsBuddies, "Hooray! He's gone! Let's go for a drink, guys!");
}