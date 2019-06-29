// BoostTestCertSSL.cpp
// Taken from:
// https://gist.github.com/derofim/5d1abf6d3c6244afd969a5ba9b06ae1f
#define _WIN32_WINNT 0x0601

#include "server_certificate.hpp"

#include <boost/system/error_code.hpp>
#include <boost/beast/ssl.hpp>
#include <iostream>
#include <string>

//****************************************************************************
//*                     loadSSLContext
//****************************************************************************
/*  Load a signed certificate into the ssl context, and configure
	the context for use with a server.

	For this to work with the browser or operating system, it is
	necessary to import the "Beast Test CA" certificate into
	the local certificate store, browser, or operating system
	depending on your environment Please see the documentation
	accompanying the Beast certificate for more details.
*/
static bool 
	loadSSLContext(
		boost::asio::ssl::context& ctx,
		const std::string cert,
		const std::string key,
		const std::string dh,
		const std::string certPassword) 
{
	boost::system::error_code ec;

	// password of certificate
	ctx.set_password_callback(
		[certPassword](std::size_t, boost::asio::ssl::context_base::password_purpose) {
		return certPassword.c_str();
	}, ec);
	if (ec) {
		std::cerr << "loadSSLContext: set_password_callback error: " << ec.message() << std::endl;
		return false;
	}

	ctx.set_options(boost::asio::ssl::context::default_workarounds |
		boost::asio::ssl::context::no_sslv2 |
		boost::asio::ssl::context::single_dh_use,
		ec);
	if (ec) {
		std::cerr << "loadSSLContext: set_options error: " << ec.message() << std::endl;
		return false;
	}

	ctx.use_certificate_chain(boost::asio::buffer(cert.data(), cert.size()), ec);
	if (ec) {
		std::cerr << "loadSSLContext: use_certificate_chain error: " << ec.message() << std::endl;
		// never mind the use_certificate_chain error
		//return false;
	}

	std::cerr << "cert: " << cert << std::endl; // TODO <<<

	ctx.use_private_key(boost::asio::buffer(key.data(), key.size()),
		boost::asio::ssl::context::file_format::pem, ec);
	if (ec) {
		std::cerr << "loadSSLContext: use_private_key error: " << ec.message() << std::endl;
		return false;
	}

	std::cerr << "key: " << key << std::endl; // TODO <<<

	ctx.use_tmp_dh(boost::asio::buffer(dh.data(), dh.size()), ec);
	if (ec) {
		std::cerr << "loadSSLContext: use_tmp_dh error: " << ec.message() << std::endl;
		return false;
	}

	std::cerr << "dh: " << dh << std::endl; // TODO <<<

	return true;
}

struct ServerConfig {
	std::string cert_;
	std::string key_;
	std::string dh_;
	std::string certPass_;
};

//****************************************************************************
//*                     main
//****************************************************************************
int main()
{
    std::cout << "Boost Test Certificate SSL" << std::endl;
	std::cout << "==========================" << std::endl;

	// The SSL context is required, and holds certificates
	boost::asio::ssl::context sslCtx_{ boost::asio::ssl::context::tlsv12 };

	// This holds the self-signed certificate used by the server
	load_server_certificate(sslCtx_);

	ServerConfig serverConfig;

	// This holds the self-signed certificate used by the server
	bool isCertsValid = loadSSLContext(sslCtx_,
		serverConfig.cert_,
		serverConfig.key_,
		serverConfig.dh_,
		serverConfig.certPass_);
}
