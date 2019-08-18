#include <boost/timer/timer.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "ServerLogging.cpp"

//*                     main
//****************************************************************************
int main()
{
	// create a ServerLogging instance
	ServerLogging server_logging;
	// start timing
	boost::timer::cpu_timer timer;
	// simulate database startup, sleep for 15 ms
	std::chrono::milliseconds timespan(15);
	std::this_thread::sleep_for(timespan);
	// stop timer
	timer.stop();
	server_logging.store_log(
		"0.0.0.0",
		"sqlite3 db startup",
		"sqlite3 db started",
		timer.elapsed()
	);
	server_logging.show_log();
	server_logging.show_filesize_logfile();

	return EXIT_SUCCESS;
}