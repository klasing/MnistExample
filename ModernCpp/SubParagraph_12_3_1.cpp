#include "pch.h"

#include <queue>
#include "PacketBuffer.hpp"

class IPPacket {
public:
	IPPacket(int id) : mID(id) {}
	int getID() const { return mID; }
protected:
	int mID;
};

inline void subParagraph_12_3_1() {
	cout << "queue" << endl;
	cout << "-----" << endl;

	cout << "a) queue Operations" << endl;
	cout << "b) queue Example: A Network Packet Buffer" << endl;
	PacketBuffer<IPPacket> ipPackets(3);
	// Add 4 packets
	for (int i = 1; i <= 4; ++i) {
		if (!ipPackets.bufferPacket(IPPacket(i)))
			cout << "-> Packet " << i << " dropped (queue is full)." << endl;
	}
	while (true)
		try {
		IPPacket packet = ipPackets.getNextPacket();
		cout << "-> Processing packet " << packet.getID() << endl;
	}
	catch (const out_of_range&) {
		cout << "-> Queue is empty." << endl;
		break;
	}
}