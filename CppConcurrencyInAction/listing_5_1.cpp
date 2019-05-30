// Listing 5.1
// Implementation of a spinlock mutex using std::atomic_flag
#include <atomic>

using namespace std;
namespace ns_listing_5_1 {
	class spinlock_mutex {
		//atomic_flag flag;
		atomic_flag flag = ATOMIC_FLAG_INIT;
	public:
		//spinlock_mutex() : flag(ATOMIC_FLAG_INIT) {}
		spinlock_mutex() {}
		void lock() {
			while (flag.test_and_set(memory_order_acquire));
		}
		void unlock() {
			flag.clear(memory_order_release);
		}
	};

	inline void listing_5_1() {

	}
}