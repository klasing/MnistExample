// HttpClientAsyncSSL.cpp
#include <iostream>

#include "http_client_async_ssl.cpp"

int main()
{
    std::cout << "HTTP Client Async SSL" << std::endl;
	std::cout << "=====================" << std::endl;

	char cmd[] = "http-client-async-ssl";
	char* argv[] = { cmd };
	int argc = 1;
	ns_http_client_async_ssl::http_client_async_ssl(argc, argv);
}
