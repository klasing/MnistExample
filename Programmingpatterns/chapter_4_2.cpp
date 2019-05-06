#include <iostream>

using namespace std;
/*the Command interface*/
class Command_4_2 {
public:
	virtual void execute() = 0;
};

/*Receiver class*/
class Light_4_2 {
public:
	Light_4_2() {}
	void turnOn() { cout << "-> The light is on" << endl; }
	void turnOff() { cout << "-> The light is off" << endl; }
};

/*the Command for turning on the light*/
class FlipUpCommand_4_2 : public Command_4_2 {
public:
	FlipUpCommand_4_2(Light_4_2& light) : theLight(light) {}
	virtual void execute() { theLight.turnOn(); }
private:
	Light_4_2& theLight;
};

/*the Command for turning off the light*/
class FlipDownCommand_4_2 : public Command_4_2 {
public:
	FlipDownCommand_4_2(Light_4_2& light) : theLight(light) {}
	virtual void execute() { theLight.turnOff(); }
private:
	Light_4_2& theLight;
};

class Switch_4_2 {
public:
	Switch_4_2(Command_4_2& flipUpCmd, Command_4_2& flipDownCmd)
		: flipUpCommand(flipUpCmd), flipDownCommand(flipDownCmd) {}
	void flipUp() { flipUpCommand.execute(); }
	void flipDown() { flipDownCommand.execute(); }
private:
	Command_4_2& flipUpCommand;
	Command_4_2& flipDownCommand;
};

inline void chapter_4_2() {
	cout << "Command" << endl;
	cout << "-------" << endl;

	Light_4_2 lamp;
	FlipUpCommand_4_2 switchUp(lamp);
	FlipDownCommand_4_2 switchDown(lamp);

	Switch_4_2 s(switchUp, switchDown);
	s.flipUp();
	s.flipDown();
}