/* Facade is one of the easiest patterns I think... And this is a very simple example.

Imagine you set up a smart house where everything is on remote. So turn the lights on you push
lights on button - And same for TV,
AC, Alarm, Music, etc...

When you leave a house you would need to push a 100 buttons to make sure everything is off and are
good to go which could be little
annoying if you are lazy like me
so I defined a Facade for leaving and coming back. (Facade functions represent buttons...) So when
I come and leave I just make one
call and it takes care of everything...
*/

#include <string>
#include <iostream>

using namespace std;

class Alarm_3_5 {
public:
	void alarmOn() { cout << "-> Alarm is on and house is secured" << endl; }
	void alarmOff() { cout << "-> Alarm is off and you can go into the house" << endl; }
};

class Ac_3_5 {
public:
	void acOn() { cout << "-> Ac is on" << endl; }
	void acOff() { cout << "-> Ac is off" << endl; }
};

class Tv_3_5 {
public:
	void tvOn() { cout << "-> Tv is on" << endl; }
	void tvOff() { cout << "-> Tv is off" << endl; }
};

class HouseFacade_3_5 {
	Alarm_3_5 alarm;
	Ac_3_5 ac;
	Tv_3_5 tv;
public:
	HouseFacade_3_5() {}
	void goToWork() {
		ac.acOff();
		tv.tvOff();
		alarm.alarmOn();
	}
	void comeHome() {
		alarm.alarmOff();
		ac.acOn();
		tv.tvOn();
	}
};

inline void chapter_3_5() {
	cout << "Facade" << endl;
	cout << "------" << endl;

	HouseFacade_3_5 hf;
	// Rather than calling 100 different on and off functions thanks to facade I only have 2
	// functions...
	hf.goToWork();
	hf.comeHome();

}