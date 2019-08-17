#include <iostream>
#include <time.h>
#include <random>

#include "http_server_async.cpp"

//****************************************************************************
//*                     date_for_http_response
//****************************************************************************
inline std::string
date_for_http_response()
{
	std::string dow[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	std::string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	time_t tt;
	time(&tt);
	tm t;
	localtime_s(&t, &tt);
	struct tm gmt;
	gmtime_s(&gmt, &tt);
	std::ostringstream oss;
	oss << dow[gmt.tm_wday] << ", "
		<< std::setw(2) << std::setfill('0') << gmt.tm_mday << " "
		<< month[gmt.tm_mon] << " "
		<< gmt.tm_year + 1900 << " "
		<< std::setw(2) << std::setfill('0') << gmt.tm_hour << ":"
		<< std::setw(2) << std::setfill('0') << gmt.tm_min << ":"
		<< std::setw(2) << std::setfill('0') << gmt.tm_sec << " "
		<< "GMT";
	return oss.str();
}

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