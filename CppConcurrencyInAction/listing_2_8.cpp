// Listing 2.8
// A naive parallel version of std::accumulate
#include <iostream>
#include <numeric>
#include <iterator>

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

	}
}