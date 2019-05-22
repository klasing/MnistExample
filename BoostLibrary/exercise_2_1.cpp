// Exercise 2 1
#include <iostream>
#include <string>

using namespace std;
namespace ns_exercise_2_1 {
	class animal {
	public:
		animal(const string& inName, const int& inLegs,
			const bool& in_has_tail) :
			name(inName), legs(inLegs), has_tail(in_has_tail) {}
		string toString() const {
			return "name " + name + 
				", legs " + to_string(legs) +
				", has tail " + (has_tail ? "yes" : "no");
		}
	private:
		string name;
		int legs;
		bool has_tail;
	};
	inline void exercise_2_1() {
		animal snake("rattlesnake", 0, false);
		animal bird("trush", 2, true); // trush (ENG) = lijster (NL)
		animal mammal("dog", 4, true);
		animal insect("fly", 6, false);
		animal spider("tarantula", 8, false);
		animal diplopoda("millipede", 742, false);

		cout << "-> " << snake.toString() << endl;
	}
}