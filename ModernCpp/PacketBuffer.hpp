#pragma once

#include <queue>

template <typename T>
class PacketBuffer {
public:
	// If maxSize is 0, the size is unlimited, because creating
	// a buffer of size 0 makes little sense. Otherwise only
	// maxSize packets are allowed in the buffer at any one time.
	PacketBuffer(size_t maxSize = 0) : mMaxSize(maxSize) {}
	// Stores a packet in the buffer.
	// Returns false if the packet has been discarded because
	// there is no more space in the buffer, true otherwise.
	bool bufferPacket(const T& packet) {
		if (mMaxSize > 0 && mPackets.size() == mMaxSize)
			// No more space. Drop the packet.
			return false;
		mPackets.push(packet);
		return true;
	}
	// Returns the next packet. Throws out_of_range
	// if the buffer is empty.
	T getNextPacket() throw(std::out_of_range) {
		if (mPackets.empty())
			throw std::out_of_range("Buffer is empty");
		// Retrieve the head element
		T temp = mPackets.front();
		// pop the head element
		mPackets.pop();
		// return the head element
		return temp;
	}
protected:
	std::queue<T> mPackets;
	int mMaxSize;
};