#include "pch.h"

#include <string>

// the example in the book is poorly designed
// the following code is an example that at least works
class Player_29_4_1 {
public:
	virtual string getName() = 0;
	// Sends an instant message to the player over the nerwork and
	// returns the reply as a string. Network connectivity is required.
	virtual string sendInstantMessage(const string& inMessage) {
		return "yes";
	}
};

class PlayerProxy_29_4_1 : public Player_29_4_1 {
public:
	virtual string getName() {
		return "John Doe";
	}
	virtual string sendInstantMessage(const string& inMessage) {
		//return "-> The player could not be contacted.";
		// or
		bool hasNetworkConnectivity = false;
		if (hasNetworkConnectivity)
			return Player_29_4_1::sendInstantMessage(inMessage);
		else
			return "The player could not be contacted.";
	}
};

inline bool informWinner(Player_29_4_1* inPlayer) {
	string result = inPlayer->sendInstantMessage("You have won! Play again?");
	cout << "-> " << result << endl;
	if (result == "yes") {
		cout << "-> " << inPlayer->getName() << " wants to play again" << endl;
		return true;
	}
	else {
		// The player said no, or is ofline.
		cout << "-> " << inPlayer->getName() << " does not want to play again" << endl;
		return false;

	}
}

inline void subParagraph_29_4_1() {
	cout << "Example: Hiding Network Connectivity Issues" << endl;
	cout << "-------------------------------------------" << endl;

	Player_29_4_1* pPlayer = new PlayerProxy_29_4_1();
	informWinner(pPlayer);
	delete pPlayer;
	pPlayer = nullptr;
}