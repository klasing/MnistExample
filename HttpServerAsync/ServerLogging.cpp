#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
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
//*                     prototype
//****************************************************************************
std::string date_for_http_response();

//****************************************************************************
//*                     write_logfile
//****************************************************************************
inline void
write_logfile(
	boost::filesystem::ofstream& ofs,
	const boost::filesystem::path& p,
	const tuple_logging& tl
)
{
	// write tuple to file
	ofs.open(p, std::ios_base::app);
	ofs << boost::tuples::set_delimiter('#') << tl << '\n';
	ofs.close();
}

//****************************************************************************
//*                     parse_logfile
//****************************************************************************
inline void parse_logfile(
	boost::filesystem::ifstream& ifs,
	const boost::filesystem::path& p,
	std::vector<tuple_logging>& vector_with_tuples
)
{
	typedef std::string one_line_from_logging;

	one_line_from_logging str;
	tuple_logging tlin;

	// clear vector
	vector_with_tuples.clear();

	// open log file for reading
	ifs.open(p);

	// read one line from log file, until eof
	while (std::getline(ifs, str))
	{
		size_t sBegin = 0, sEnd = 0;
		// 1
		// first character on a line is '(',
		// start at sBegin = 1
		sBegin = sEnd + 1;
		sEnd = str.find('#', sBegin);
		std::string current_gmt_ = str.substr(sBegin, sEnd - sBegin);
		// 2
		sBegin = sEnd + 1;
		sEnd = str.find('#', sBegin);
		std::string remote_endpoint_ = str.substr(sBegin, sEnd - sBegin);
		// 3
		sBegin = sEnd + 1;
		sEnd = str.find('#', sBegin);
		std::string request_ = str.substr(sBegin, sEnd - sBegin);
		// 4
		sBegin = sEnd + 1;
		sEnd = str.find('#', sBegin);
		std::string response_ = str.substr(sBegin, sEnd - sBegin);
		// 5
		sBegin = sEnd + 1;
		// last character on a line is ')'
		sEnd = str.find(')', sBegin);
		std::string elapsed_time_ = str.substr(sBegin, sEnd - sBegin);

		// create tuple from parsed log data out of file
		tlin = boost::tuples::make_tuple(
			current_gmt_,
			remote_endpoint_,
			request_,
			response_,
			elapsed_time_
		);

		// set tuple into vector
		vector_with_tuples.push_back(tlin);
	}

	// close log file
	ifs.close();
}

//****************************************************************************
//*                     show_vector_with_tuples
//****************************************************************************
inline void show_vector_with_tuples(
	const std::vector<tuple_logging>& vector_with_tuples
)
{
	int i = 0;
	tuple_logging tlin;

	for (auto ite : vector_with_tuples)
	{
		tlin = ite;
		std::cout << std::setw(2) << ++i << std::endl;
		std::cout << "current GMT.......: " << tlin.get<0>() << std::endl;
		std::cout << "remote_endpoint...: " << tlin.get<1>() << std::endl;
		std::cout << "request...........: " << tlin.get<2>() << std::endl;
		std::cout << "response..........: " << tlin.get<3>() << std::endl;
		std::cout << "elapsed...........: " << tlin.get<4>() << " (ms)" << std::endl;
	}
}

//****************************************************************************
//*                     get_filesize_logfile
//****************************************************************************
inline void get_filesize_logfile(
	const boost::filesystem::path& p
)
{
	boost::system::error_code ec;
	boost::uintmax_t filesize;

	// get file size
	filesize = boost::filesystem::file_size(p, ec);
	if (!ec)
		std::cout << "filesize: " << filesize << " (bytes)\n";
	else
		std::cout << ec << '\n';
}

//****************************************************************************
//*                     clear_logfile_if_too_big
//****************************************************************************
inline void clear_logfile_if_too_big(
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

class ServerLogging {
public:
	ServerLogging() {
		std::cout << "<<constructor>> ServerLogging()\n";
	}
private:
};
