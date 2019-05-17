// Listing A.3
// A class with a trivial default constructor

using namespace std;
namespace ns_listing_A_3 {
	class CX {
	private:
		int a;
		int b;
	public:
		CX() = default;
		//CX(int a_, int b_) : a(a_), b(b_) {}
		constexpr CX(int a_, int b_) : a(a_), b(b_) {}
		//int get_a() const { return a; }
		constexpr int get_a() const { return a; }
		//int get_b() const { return b; }
		constexpr int get_b() const { return b; }
		//int foo() const { return a + b; }
		constexpr int foo() const { return a + b; }
	};
	inline constexpr CX create_cx() {
		return CX();
	}
	inline constexpr CX clone(CX val) {
		return val;
	}
	// by making CX methods constexpr, more complex
	// constexpr functions are possible
	inline constexpr CX make_cx(int a) {
		return CX(a, 1);
	}
	inline constexpr CX half_double(CX old) {
		return CX(old.get_a() / 2, old.get_b() * 2);
	}
	inline constexpr int foo_squared(CX val) {
		//return square(val.foo());
		return (val.foo() * val.foo());
	}
}