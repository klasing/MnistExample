// http_client_async_ssl.hpp
// Taken from:
// https://www.boost.org/doc/libs/1_70_0/libs/beast/example/http/client/async-ssl/http_client_async_ssl.cpp
#define _WIN32_WINNT 0x0601

#include "root_certificates.hpp"

#include <boost/beast/core.hpp>
#include <iostream>

namespace ns_http_client_async_ssl {
	//***************************************************************************
	//*                    http_client_async_ssl
	//***************************************************************************
	inline int http_client_async_ssl(int argc, char* argv[]) {
		std::cout << "http_client_async_ssl()" << std::endl;
		return EXIT_SUCCESS;
	}
}