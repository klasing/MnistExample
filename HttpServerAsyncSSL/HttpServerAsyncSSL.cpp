// HttpServerAsyncSSL.cpp
#include <iostream>

#include "http_server_async_ssl.cpp"

int main()
{
    std::cout << "HTTP Server Async SSL" << std::endl;
	std::cout << "=====================" << std::endl;

	char cmd[] = "http-server-async-ssl";
	char address[] = "0.0.0.0";
	char port[] = "8080";
	char doc_root[] = "/";
	char threads[] = "1";
	char* argv[] = { cmd, address , port, doc_root, threads };
	int argc = 5;
	ns_http_server_async_ssl::http_server_async_ssl(argc, argv);
}
