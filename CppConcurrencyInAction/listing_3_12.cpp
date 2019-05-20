// Listing 3.12
// Thread-safe lazy initialization of a class member using std::call_once
#include <mutex>

using namespace std;
namespace ns_listing_3_12 {
	typedef char* data_packet;
	class connection_info {

	};
	class connection_handle {
	public:
		void send_data(data_packet const& data) {}
		data_packet receive_data() { return nullptr; }
	};
	class connectionManager {
	public:
		connection_handle open(connection_info) {
			connection_handle connection;
			return connection;
		}
	};
	class X {
	private:
		connection_info connection_details;
		connection_handle connection;
		once_flag connection_init_flag;

		connectionManager connection_manager;
		void open_connection() {
			connection = connection_manager.open(connection_details);
		}
	public:
		X(connection_info const& connection_details_) :
			connection_details(connection_details_)
		{}
		void send_data(data_packet const& data) {
			call_once(connection_init_flag, &X::open_connection, this);
			connection.send_data(data);
		}
		data_packet receive_data() {
			call_once(connection_init_flag, &X::open_connection, this);
			return connection.receive_data();
		}
	};
	inline void listing_3_12() {
		connection_info connection_details;
		X x(connection_details);
		data_packet dp = nullptr;
		x.send_data(dp);
		dp = x.receive_data();
	}
}
//typedef int connection_info;
//typedef int connection_handle;
//
//struct data_packet {};
//class connection_handle {
//public:
//	void send_data(data_packet) {}
//	data_packet receive_data() { return data; }
//};
//
//class X {
//private:
//	connection_info connection_details;
//	connection_handle connection;
//	once_flag connection_init_flag;
//
//	void open_connection() {
//		connection = connection_manager.open(connection_details);
//	}
//public:
//	X(connection_info const& connection_details_) :
//		connection_details(connection_details_)
//	{}
//	void send_data(data_packet const& data) {
//		call_once(connection_init_flag, &X::open_connection, this);
//		connection.send_data(data);
//	}
//	data_packet receive_data() {
//		call_once(connection_init_flag, &X::open_connection, this);
//		return connection.receive_data();
//	}
//};

