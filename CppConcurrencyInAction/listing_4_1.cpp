// Listing 4.1
// Waiting for data to process with a std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;
namespace ns_listing_4_1 {
	struct data_chunk {
		int piece_of_data;
	};

	extern std::mutex mut;
	extern std::queue<data_chunk> data_queue; //(1)
	extern std::condition_variable data_cond;
	extern int nPrepare;
	extern int nProcess;
	extern const int NCHUNK;

	inline bool more_data_to_prepare() {
		nPrepare++;
		return (nPrepare >= NCHUNK ? false : true);
	}

	inline data_chunk prepare_data() {
		cout << "-> prepare_data()" << endl;
		data_chunk aChunk;
		aChunk.piece_of_data = -1;
		return aChunk;
	}

	inline void data_preparation_thread() {
		while (more_data_to_prepare()) {
			data_chunk const data = prepare_data();
			lock_guard<mutex> lk(mut);
			data_queue.push(data); // (2)
			data_cond.notify_one(); // (3)
		}
	}

	inline bool is_last_chunk(const data_chunk& data) {
		nProcess++;
		return (nPrepare >= NCHUNK ? true : false);
	}

	inline void process(data_chunk& data) {
		cout << "-> process()" << endl;
		data.piece_of_data = 0;
	}

	inline void data_processing_thread() {
		while (true) {
			unique_lock<mutex> lk(mut); // (4)
			data_cond.wait(
				lk, [] { return !data_queue.empty(); }); // (5)
			data_chunk data = data_queue.front();
			data_queue.pop();
			lk.unlock(); // (6)
			process(data);
			if (is_last_chunk(data))
				break;
		}
	}

	inline void listing_4_1() {
		data_chunk myCunk;
		thread prepareThread(data_preparation_thread);
		thread processThread(data_processing_thread);
		prepareThread.join();
		processThread.join();

	}
}