// Listing 3.13
// Protecting a data structure with a boost::shared_mutex
#include <iostream>
#include <map>
#include <string>
#include <mutex>

#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>

using namespace std;
namespace ns_listing_3_13 {
	class dns_entry {
	};

	class dns_cache {
		map<string, dns_entry> entries;
		mutable boost::shared_mutex entry_mutex;
	public:
		dns_entry find_entry(string const& domain) const {
			boost::shared_lock<boost::shared_mutex> lk(entry_mutex);
			map<string, dns_entry>::const_iterator const it =
				entries.find(domain);
			return (it == entries.end()) ? dns_entry() : it->second;
		}
		void update_or_add_entry(string const& domain,
			dns_entry const& dns_details) {
			lock_guard<boost::shared_mutex> lk(entry_mutex);
			entries[domain] = dns_details;

		}
	};
	inline void listing_3_13() {
		dns_cache dnsCache;
	}
}

/*
Reported as a problem
Environment
-----------
MS Visual Studio Community 2019 - 00435-60000-00000-A312
Boost 1_70_0

Errors
------
E2524 the argument to a feature-test macro must be a simple identifier
File: config.hpp (file from boost)
Line 51: #if __has_cpp_attribute(clang::require_constant_initialization)

LINK : fatal error LNK1104: cannot open file 'libboost_thread-vc142-mt-gd-x32-1_70.lib'

SOLVED: by setting the path to boost for the linker
Select project
Right click -> properties
In the [project] Property Pages:
Configuration Properties -> Linker -> General
Edit the Additional Library Directories by adding:
C:\Program Files\boost\boost_1_69_0\stage\lib
*/