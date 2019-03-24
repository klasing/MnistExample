#pragma once

#include <string>

class AirlineTicket {
public:
	AirlineTicket() {
		// Initialize data members
		bHasEliteSuperRewardsStatus = false;
		mPassengerName = "Unknown Passenger";
		mNumberOfMiles = 0;
	}
	~AirlineTicket() {
		// Nothing to do in terms of cleanup
	}
	int calculatePriceInDollars() const {
		if (getHasEliteSuperRewardsStatus()) {
			// Elite Super Rewards customers fly for free!
			return 0;
		}
		// The cost of the ticket is the number of miles times
		// 0.1. Real airlines probably have a more complicated formula!
		return static_cast<int>(getNumberOfMiles() * 0.1);
	}
	std::string getPassengerName() const {
		return mPassengerName;
	}
	void setPassengerName(std::string inName) {
		mPassengerName = inName;
	}
	int getNumberOfMiles() const {
		return mNumberOfMiles;
	}
	void setNumberOfMiles(int inMiles) {
		mNumberOfMiles = inMiles;
	}
	bool getHasEliteSuperRewardsStatus() const {
		return bHasEliteSuperRewardsStatus;
	}
	void setHasEliteSuperRewardsStatus(bool inStatus) {
		bHasEliteSuperRewardsStatus = inStatus;
	}
protected:
	std::string mPassengerName;
	int mNumberOfMiles;
	bool bHasEliteSuperRewardsStatus;
};
