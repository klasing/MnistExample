// Listing 3.13
// Protecting a data structure with a boost::shared_mutex
#include <iostream>
#include <map>
#include <string>
#include <mutex>
//#include <boost/thread/shared_mutex.hpp>

using namespace std;
namespace ns_listing_3_13 {
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
*/