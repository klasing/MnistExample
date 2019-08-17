#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/filesystem.hpp>
#include <string>

//****************************************************************************
//*                     prototype
//****************************************************************************
std::string date_for_http_response();

//****************************************************************************
//*                     global
//****************************************************************************
// typedef tuple
typedef std::string td_current_gmt, td_remote_endpoint,
td_request, td_response, td_elapsed_time;
typedef boost::tuples::tuple<td_current_gmt, td_remote_endpoint,
	td_request, td_response, td_elapsed_time> tuple_logging;

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
	ofs << boost::tuples::set_delimiter('#') << tl;
	ofs.close();
}
