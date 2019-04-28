#include "pch.h"

#include <initializer_list>

class MyDistance {
public:
	MyDistance(double i) : m(i) {}
	friend MyDistance operator+ (const MyDistance& a, const MyDistance& b) {
		return MyDistance(a.m + b.m);
	}
	friend MyDistance operator- (const MyDistance& a, const MyDistance& b) {
		return MyDistance(a.m - b.m);
	}
	friend MyDistance operator* (double m, const MyDistance& a) {
		return MyDistance(m * a.m);
	}
	friend MyDistance operator/ (const MyDistance& a, int n) {
		return MyDistance(a.m / n);
	}
	friend ostream& operator<< (ostream& out, const MyDistance& myDist) {
		out << myDist.m << " m";
		return out;
	}
private:
	double m;
};

inline MyDistance operator"" _km(long double km) {
	return MyDistance(1000 * km);
}
inline MyDistance operator"" _m(long double m) {
	return MyDistance(m);
}
inline MyDistance operator"" _dm(long double dm) {
	return MyDistance(dm / 10.);
}
inline MyDistance operator"" _cm(long double cm) {
	return MyDistance(cm / 100.);
}

inline MyDistance getAverageDistance(initializer_list<MyDistance> inList) {
	auto sum = MyDistance{ 0. };
	for (auto i : inList)
		sum = sum + i;
	return sum / inList.size();
}

inline void subParagraph_9_5_8_ad1() {
	cout << "User Defined Literals, by Rainier Grimm:" << endl;
	cout << "http://www.modernescpp.com/index.php/user-defined-literals" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "-> 1.0 km: " << 1.0_km << endl;
	cout << "-> 1.0 m: " << 1.0_m << endl;
	cout << "-> 1.0 dm: " << 1.0_dm << endl;
	cout << "-> 1.0 cm: " << 1.0_cm << endl;

	cout << "-> 1.0 km + 2.0 dm + 3.0 dm + 4.0 cm: "
		<< 1.0_km + 2.0_dm + 3.0_dm + 4.0_cm << endl;

	auto work = 63.0_km;
	auto workPerday = 2 * work;
	auto abbreviationToWork = 5400.0_m;
	auto workout = 2 * 1600.0_m;
	auto shopping = 2 * 1200.0_m;

	auto distPerWeek1 = 4 * workPerday - 3 * abbreviationToWork + workout + shopping;
	auto distPerWeek2 = 4 * workPerday - 3 * abbreviationToWork + 2 * workout;
	auto distPerWeek3 = 4 * workout + 2 * shopping;
	auto distPerWeek4 = 5 * workout + shopping;

	cout << "-> distPerWeek1: " << distPerWeek1 << endl;

	auto averageDistance = getAverageDistance({distPerWeek1, distPerWeek2, distPerWeek3, distPerWeek4});
	cout << "=> averageDistance: " << averageDistance << endl;
}