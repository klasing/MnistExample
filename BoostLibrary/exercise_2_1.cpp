// Exercise 2 1
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/assign/list_inserter.hpp>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;
namespace ns_exercise_2_1 {
	class animal {
	public:
		animal(const string& inName, const int& inLegs,
			const bool& in_has_tail) :
			name(inName), legs(inLegs), has_tail(in_has_tail) {}
		friend bool operator<(const animal&, const animal&);
		string toString() const {
			return "name " + name +
				", legs " + to_string(legs) +
				", has tail " + (has_tail ? "yes" : "no");
		}
		animal* do_clone() const {
			return new animal(*this);
		}
	private:
		string name;
		int legs;
		bool has_tail;
	};
	inline bool operator<(const animal& lhs, const animal& rhs) {
		return lhs.legs < rhs.legs;
	}

	inline void exercise_2_1() {

		boost::ptr_vector<animal> vec;
		boost::void_ptr_indirect_fun<less<animal>, animal> cast_fun;

		// a) storing object pointer
		//boost::assign::push_back(vec)(new animal("millipede", 742, false))
		//	(new animal("tarantula", 8, false))
		//	(new animal("fly", 6, false))
		//	(new animal("dog", 4, true))
		//	(new animal("trush", 2, true))
		//	(new animal("rattlesnake", 0, false));

		// b) storing object pointer from cloned object
		animal diplopoda("millipede", 742, false);
		animal spider("tarantula", 8, false);
		animal insect("fly", 6, false);
		animal mammal("dog", 4, true);
		animal bird("trush", 2, true); // trush (ENG) = lijster (NL)
		animal snake("rattlesnake", 0, false);
		boost::assign::push_back(vec)(diplopoda.do_clone())
			(spider.do_clone())
			(insect.do_clone())
			(mammal.do_clone())
			(bird.do_clone())
			(snake.do_clone());

		sort(vec.begin().base(), vec.end().base(), cast_fun);

		for (auto it = vec.cbegin(); it != vec.cend(); ++it)
			cout << "-> " << (*it).toString() << endl;
	}
}
