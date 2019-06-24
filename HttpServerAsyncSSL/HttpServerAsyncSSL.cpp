// HttpServerAsyncSSL.cpp
#include <iostream>

#include "http_server_async_ssl.cpp"

int main()
{
    std::cout << "HTTP Server Async SSL" << std::endl;
	std::cout << "=====================" << std::endl;

	char cmd[] = "http-server-async-ssl";
	char* argv[] = { cmd };
	int argc = 1;
	ns_http_server_async_ssl::http_server_async_ssl(argc, argv);
}
