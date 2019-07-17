// HttpServerAsyncSSL.cpp
// File server for uploading
#include <iostream>
#include <time.h>
#include <random>

#include "http_server_async_ssl.cpp"

//****************************************************************************
//*                     generate_random_string
//****************************************************************************
inline std::string
	generate_random_string()
{
	const int RANDOM_CHARACTER_MAX = 16;
	std::string random_string = "";
	std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(65, 90);
	for (int i = 0; i < RANDOM_CHARACTER_MAX; i++)
		random_string += dist(eng);
	return random_string;
}

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	std::cout << "HTTP Server Async SSL" << std::endl;
	std::cout << "=====================" << std::endl;
	char cmd[] = "http-server-async-ssl";
	char address[] = "0.0.0.0";
	char port[] = "8080";
	char doc_root[] = ".";
	char threads[] = "1";
	char* argv[] = { cmd, address , port, doc_root, threads };
	ns_http_server_async_ssl::http_server_async_ssl(5, argv);
}
