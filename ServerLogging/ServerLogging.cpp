#include <boost/timer/timer.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

//****************************************************************************
//*                     global
//****************************************************************************
// typedef tuple
typedef std::string td_current_gmt, td_remote_endpoint,
td_request, td_response, td_elapsed_time;
typedef boost::tuples::tuple<td_current_gmt, td_remote_endpoint,
	td_request, td_response, td_elapsed_time> tuple_logging;

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
//*                     write_logfile
//****************************************************************************
void
write_logfile(
	boost::filesystem::ofstream& ofs,
	const boost::filesystem::path& p,
	const tuple_logging& tl
)
{
	// write tuple to file
	ofs.open(p, std::ios_base::app);
	ofs << boost::tuples::set_delimiter('#') << tl;
	ofs.close();
}

//****************************************************************************
//*                     read_logfile
//****************************************************************************
void
read_logfile(
	boost::filesystem::ifstream& ifs,
	const boost::filesystem::path& p,
	tuple_logging& tlin
)
{
	// read tuple from file
	ifs.open(p);
	ifs >> boost::tuples::set_delimiter('#') >> tlin;
	ifs.close();
}

//****************************************************************************
//*                     get_filesize_logfile
//****************************************************************************
void get_filesize_logfile(
	const boost::filesystem::path& p
)
{
	boost::system::error_code ec;
	boost::uintmax_t filesize;

	// get file size
	filesize = boost::filesystem::file_size(p, ec);
	if (!ec)
		std::cout << filesize << '\n';
	else
		std::cout << ec << '\n';
}

//****************************************************************************
//*                     clear_logfile_if_too_big
//****************************************************************************
void clear_logfile_if_too_big(
	boost::filesystem::ofstream& ofs,
	const boost::filesystem::path& p,
	const boost::uintmax_t& LOGGING_BYTES_MAX
)
{
	// get file size
	boost::system::error_code ec;
	boost::uintmax_t filesize = boost::filesystem::file_size(p, ec);
	if (!ec)
	{
		// when file size is bigger than LOGGING_BYTES_MAX, clear the file
		if (filesize > LOGGING_BYTES_MAX)
		{
			ofs.open(p);
			ofs.clear();
			ofs.close();
			std::cout << "log file cleared\n";
		}
	}
	else
		std::cout << ec << '\n';
}

//****************************************************************************
//*                     main
//****************************************************************************
int main()
{
	const boost::uintmax_t LOGGING_BYTES_MAX = 100;
	const std::string LOGGING_FILE_NAME = "logging";
	const boost::filesystem::path p{ LOGGING_FILE_NAME };
	boost::filesystem::ofstream ofs;
	boost::filesystem::ifstream ifs;

	std::cout << "Server Logging\n";
	std::cout << "==============\n";

	// start timing
	boost::timer::cpu_timer timer;

	// get current gmt
	std::string current_gmt = date_for_http_response();
	// get remote endpoint
	std::string remote_endpoint = "192.168.178.14:52832";
	// request
	std::string request = "TRACE / HTTP/1.1";
	// response
	std::string response = "HTTP/1.1 200 OK";

	// stop timer
	timer.stop();
	// elapsed time
	boost::timer::cpu_times times = timer.elapsed();
	std::string elapsed_time = std::to_string(times.wall / (double)1e6);

	// show collected data
	std::cout << "current GMT.......: " << current_gmt << '\n'
		<< "remote endpoint...: " << remote_endpoint << '\n'
		<< "request...........: " << request << '\n'
		<< "response..........: " << response << '\n'
		<< "elapsed time......: " << elapsed_time << "ms\n";

	// store in tuple
	tuple_logging tl{ current_gmt, remote_endpoint,
		request, response, elapsed_time };

	// write tuple to file
	write_logfile(ofs, p, tl);
	get_filesize_logfile(p);

	// read tuple from file
	tuple_logging tlin{ current_gmt, remote_endpoint,
		request, response, elapsed_time };
	read_logfile(ifs, p, tlin);
	std::cout << tlin << '\n';

	// store in tuple, once more
	write_logfile(ofs, p, tl);
	get_filesize_logfile(p);

	// clear file if too big
	clear_logfile_if_too_big(ofs, p, LOGGING_BYTES_MAX);

	return EXIT_SUCCESS;
}

