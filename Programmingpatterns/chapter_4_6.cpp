#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
extern const string NAME;
template<typename T>
inline string toString(const T& t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

class Memento;
class Object {
public:
	Object(int newValue) : value(newValue), name(NAME + toString(value)),
		decimal((float)value / 100) {}
	void doubleValue() { 
		value *= 2;
		name = NAME + toString(value);
		decimal = (float)value / 100;
	}
	void increaseByOne() { 
		value++;
		name = NAME + toString(value);
		decimal = (float)value / 100;
	}
	int getValue() const { return value; }
	string getName() const { return name; }
	double getDecimal() const { return decimal; }
	Memento* createMemento() const;
	void reinstateMemento(Memento* mem);
private:
	int value;
	string name;
	double decimal;
	// and suppose there are loads of other data members 
};

class Memento {
public:
	Memento(const Object& obj) : object(obj) {}
	// want a snapshot of Object itself because of its many data members
	Object snapshot() const { return object; }
private:
	Object object;
};

inline Memento* Object::createMemento() const {
	return new Memento(*this);
}

inline void Object::reinstateMemento(Memento* mem) {
	*this = mem->snapshot();
}
class Command {
	typedef void (Object::* Action)();
public:
	Command(Object* newReceiver, Action newAction) 
		: receiver(newReceiver), action(newAction) {}
	virtual void execute() {
		if (mementoList.size() < numCommands + 1)
			mementoList.resize(numCommands + 1);
		mementoList[numCommands] = receiver->createMemento();
		if (commandList.size() < numCommands + 1)
			commandList.resize(numCommands + 1);
		// saves the last command
		commandList[numCommands] = this;
		if (numCommands > maxCommands)
			maxCommands = numCommands;
		numCommands++;
		// perform the actual command
		(receiver->*action)();
	}
	static void undo() {
		if (numCommands == 0) {
			cout << "-> There is nothing to undo at this point." << endl;
			return;
		}
		commandList[numCommands - 1]->receiver->reinstateMemento(mementoList[numCommands - 1]);
		numCommands--;
	}
	static void redo() {
		if (numCommands > maxCommands) {
			cout << "-> There is nothing to redo at this point." << endl;
			return;
		}
		Command* commandRedo = commandList[numCommands];
		(commandRedo->receiver->*(commandRedo->action))();
		numCommands++;
	}
private:
	Object* receiver;
	Action action;
	static vector<Command*> commandList;
	static vector<Memento*> mementoList;
	static int numCommands;
	static int maxCommands;
};

inline void chapter_4_6() {
	cout << "Memento" << endl;
	cout << "-------" << endl;

	int i;
	cout << "-> Please enter an integer: ";
	cin >> i;
	Object* object = new Object(i);
	cout << "-> value: " << object->getValue() << " name: "
		<< object->getName() << " decimal: " 
		<< object->getDecimal() << endl;

	Command* commands[3];
	commands[1] = new Command(object, &Object::doubleValue);
	commands[2] = new Command(object, &Object::increaseByOne);

	bool bProceed = true;
	while (bProceed) {
		cout << "-> 1) Double" << endl;
		cout << "-> 2) Increase by one" << endl;
		cout << "-> 3) Undo" << endl;
		cout << "-> 4) Redo" << endl;
		cout << "-> Enter the number of a subject, or enter a zero to quit: ";

		cin >> i;

		switch (i) {
		case 1:
		case 2:
			commands[i]->execute();
			break;
		case 3:
			// undo
			Command::undo();
			break;
		case 4:
			// redo
			Command::redo();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch

		cout << "-> value: " << object->getValue() << " name: "
			<< object->getName() << " decimal: "
			<< object->getDecimal() << endl;
	}
}

