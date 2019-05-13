// Listing 2.8
// A naive parallel version of std::accumulate
#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <vector>
#include <thread>
#include <functional>

using namespace std;
namespace ns_listing_2_8 {
	template<typename Iterator, typename T>
	struct accumulate_block {
		void operator() (Iterator first, Iterator last, T& result) {
			result = accumulate(first, last, result);
		}
	};
	template<typename Iterator, typename T>
	inline T parallel_accumulate(Iterator first, Iterator last, T& init) {
		unsigned long const length = distance(first, last);

		if (!length)
			return init; // [1]

		unsigned long const min_per_thread = 4;// 25;
		unsigned long const max_threads =
			(length + min_per_thread - 1) / min_per_thread; // [2]

		unsigned long const hardware_threads =
			thread::hardware_concurrency();
		cout << "-> [listing 2.8] hardware_threads: " << hardware_threads << endl;

		unsigned long const num_threads = // [3]
			min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
		cout << "-> [listing 2.8] num_threads: " << num_threads << endl;

		unsigned long const block_size = length / num_threads; // [4]
		cout << "-> [listing 2.8] block_size: " << block_size << endl;

		vector<T> results(num_threads);
		vector<thread> threads(num_threads - 1); // [5]

		Iterator block_start = first;
		for (unsigned long i = 0; i < (num_threads - 1); ++i) {
			Iterator block_end = block_start;
			advance(block_end, block_size); // [6]
			threads[i] = thread( // [7]
				accumulate_block<Iterator, T>(),
				block_start, block_end, ref(results[i]));
			block_start = block_end; // [8]
		}
		accumulate_block<Iterator, T>() (
			block_start, last, results[num_threads - 1]); // [9]
		for_each(threads.begin(), threads.end(),
			mem_fn(&thread::join)); // [10]
		return accumulate(results.begin(), results.end(), init); // [11]
	}
	inline void f() {
		int init = 10;
		int nof_element = 16;
		int numbers[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		int result = parallel_accumulate(numbers, numbers + nof_element, init);
		cout << "-> [listing 2.8] result: " << result << endl;
	}
}