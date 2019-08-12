#include <iostream>
#include <time.h>
#include <random>

#include "http_server_async.cpp"

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
	std::cout << "http server async\n";
	std::cout << "=================\n";
	char cmd[] = "http_server_async";
	char address[] = "0.0.0.0";
	char port[] = "8080";
	char doc_root[] = ".";
	char threads[] = "1";
	char* argv[] = { cmd, address , port, doc_root, threads };
	http_server_async(5, argv);
	return EXIT_SUCCESS;
}