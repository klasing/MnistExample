#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define NUMBER_OF_SAME_TYPE_CHARS 3;

using namespace std;
// won't work with my compiler
/* Actual flyweight objects class (declaration) */
//class FlyweightCharacter_3_6;

// the data is taken out of the abstract builder,
// into a separate class,to make the example work
class FlyweightCharacterStore_3_6 {
public:
	// lets imagine that sizes may be of floating point types
	static vector<float> fontSizes;
	// font names may be of variable length (lets take 6 bytes is average)
	static vector<string> fontNames;
	static void setFontsAndNames() {
		fontSizes[0] = 1.0;
		fontSizes[1] = 1.5;
		fontSizes[2] = 2.0;

		fontNames[0] = "first_font";
		fontNames[1] = "second_font";
		fontNames[2] = "third_font";
	}
};

class FlyweightCharacter_3_6 {
	// index instead of actual font size
	unsigned short fontSizeIndex;
	// index instead of font name
	unsigned short fontNameIndex;
	unsigned short positionInStream;
public:
	FlyweightCharacter_3_6(
		unsigned short inFontSizeIndex,
		unsigned short inFontNameIndex,
		unsigned short inPositionInStream) :
		fontSizeIndex(inFontSizeIndex),
		fontNameIndex(inFontNameIndex),
		positionInStream(inPositionInStream) {}
	void print() {
		cout << "-> Font Size: " << setw(3)
			<< FlyweightCharacterStore_3_6::fontSizes[fontSizeIndex]
			<< ", font Name: " << setw(11)
			<< FlyweightCharacterStore_3_6::fontNames[fontNameIndex]
			<< ", character stream position: "
			<< positionInStream
			<< endl;
	}
};

/*
FlyweightCharacterAbstractBuilder is a class holding the properties which are shared by
many objects (NOT ENTIRELY TRUE). So instead of keeping these properties in those objects
we keep them externally, making objects flyweight. See more details in the comments of the
main function.
*/
class FlyweightCharacterAbstractBuilder_3_6 {
	FlyweightCharacterAbstractBuilder_3_6() {}
	~FlyweightCharacterAbstractBuilder_3_6() {}
public:
	static FlyweightCharacter_3_6 createFlyweightCharacter(
		unsigned short fontSizeIndex,
		unsigned short fontNameIndex,
		unsigned short positionInStream) {
		FlyweightCharacter_3_6 fc(fontSizeIndex, fontNameIndex, positionInStream);
		return fc;
	}
};

inline void chapter_3_6() {
	cout << "Flyweight" << endl;
	cout << "---------" << endl;

	vector<FlyweightCharacter_3_6> chars;

	FlyweightCharacterStore_3_6::setFontsAndNames();
	unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;

	for (unsigned short i = 0; i < limit; i++) {
		chars.push_back(FlyweightCharacterAbstractBuilder_3_6::createFlyweightCharacter(0, 0, i));
		chars.push_back(FlyweightCharacterAbstractBuilder_3_6::createFlyweightCharacter(1, 1, i + 1 * limit));
		chars.push_back(FlyweightCharacterAbstractBuilder_3_6::createFlyweightCharacter(2, 2, i + 2 * limit));
	}
/*
Each char stores links to its fontName and fontSize so what we get is:

each object instead of allocating 6 bytes (convention above) for string
and 4 bytes for float allocates 2 bytes for fontNameIndex and fontSizeIndex.

That means for each char we save 6 + 4 - 2 - 2 = 6 bytes.
Now imagine we have NUMBER_OF_SAME_TYPE_CHARS = 1000 i.e. with our code
we will have 3 groups of chars with 1000 chars in each group which will save
3 * 1000 * 6 - (3 * 6 + 3 * 4) = 17970 saved bytes.

3 * 6 + 3 * 4 is a number of bytes allocated by FlyweightCharacterAbstractBuilder
(ACTUALLY FlyweightCharacterStore).

So the idea of the pattern is to move properties shared by many objects to some
external container. The objects in that case don't store the data themselves they
stpre only links to the data which saves memory and make the objects lighter.
The data size of properties stored externally may be significant which will save REALLY
huge amount of memory and will make each object super light in comparison to its
counterpart. That's where the name of the patters comes from: flyweight (i.e. very light).
*/
	for (unsigned short i = 0; i < chars.size(); i++)
		chars[i].print();

}