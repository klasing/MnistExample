#include "pch.h"

#include "AirlineTicket.hpp"

inline void subParagraph_1_3_1() {
	cout << "Declaring a Class" << endl;
	cout << "-----------------" << endl;

	// Stack-based AirlineTicket
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	int cost = myTicket.calculatePriceInDollars();
	cout << "-> This ticket will cost $" << cost << endl;

	// heap-based AirlineTicket with smart pointer
	shared_ptr<AirlineTicket> myTicket2(new AirlineTicket());
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	int cost2 = myTicket2->calculatePriceInDollars();
	cout << "-> This other ticket will cost $" << cost2 << endl;
	// No need to delete myTicket2, happens automatically

	// heap-base AirlineTicket without smart pointer
	AirlineTicket* myTicket3 = new AirlineTicket();
	// ... Use ticket 3
	// delete the heap object
	delete myTicket3;
}