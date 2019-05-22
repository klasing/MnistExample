// Listing 4.4
// Extracting push() and wait_and_pop() from listing 4.1
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;
namespace ns_listing_4_4 {
	template <typename T>
	class threadsafe_queue {
	private:
		mutex mut;
		queue<T> data_queue;
		condition_variable data_cond;
	public:
		void push(T new_value) {
			lock_guard<mutex> lk(mut);
			data_queue.push(new_value);
			data_cond.notify_one();
		}
		void wait_and_pop(T& value) {
			unique_lock<mutex> lk(mut);

		}
	};
}