// server_certificate.hpp
// Taken from:
// https://www.boost.org/doc/libs/1_70_0/libs/beast/example/common/server_certificate.hpp
#ifndef BOOST_BEAST_EXAMPLE_COMMON_SERVER_CERTIFICATE_HPP
#define BOOST_BEAST_EXAMPLE_COMMON_SERVER_CERTIFICATE_HPP

#include <boost/asio/buffer.hpp>
#include <boost/asio/ssl/context.hpp>
#include <cstddef>
#include <memory>

/*  Load a signed certificate into the ssl context, and configure
	the context for use with a server.

	For this to work with the browser or operating system, it is
	necessary to import the "Beast Test CA" certificate into
	the local certificate store, browser, or operating system
	depending on your environment Please see the documentation
	accompanying the Beast certificate for more details.
*/
inline
void
load_server_certificate(boost::asio::ssl::context& ctx)
{
	/*
		The certificate was generated from CMD.EXE on Windows 10 using:

		winpty openssl dhparam -out dh.pem 2048
		winpty openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days 10000 -out cert.pem -subj "//C=US\ST=CA\L=Los Angeles\O=Beast\CN=www.example.com"
	*/
	std::string const cert =
"-----BEGIN CERTIFICATE-----\n"
"MIIDfzCCAmegAwIBAgIJAOXHAlO+SjxsMA0GCSqGSIb3DQEBCwUAMFYxCzAJBgNV\n"
"BAYTAk5MMRAwDgYDVQQIDAdVVFJFQ0hUMRAwDgYDVQQHDAdVVFJFQ0hUMRIwEAYD\n"
"VQQKDAlNWUNPTVBBTlkxDzANBgNVBAMMBkxBUFBJRTAeFw0xOTA2MzAxNTUwMTJa\n"
"Fw00NjExMTUxNTUwMTJaMFYxCzAJBgNVBAYTAk5MMRAwDgYDVQQIDAdVVFJFQ0hU\n"
"MRAwDgYDVQQHDAdVVFJFQ0hUMRIwEAYDVQQKDAlNWUNPTVBBTlkxDzANBgNVBAMM\n"
"BkxBUFBJRTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMTrvb6ACHC2\n"
"k15Ay9tOdZTiBVxgsCZl1OEWxPO+QY9JNqrkFYLxT3u69L3MXmNgn88ZirOD7p1x\n"
"bjClOT92bSX1kgWLbubGxqKu42NLBDZzPKvUVZf5d1sLE+4hdEd/gEEGZLtBjyOk\n"
"e5nB+y4BYK7GRVJLbDS0Qwy+d5I4fx5oqFxYXx67HVqtpN2NHYVzLM5V+nCDec31\n"
"qmBazFqAK9oNP2ffQKCN7VjCbFQOFm29+cvTzxQWb+KAk8KIi2eN2FuAbCJR4NdM\n"
"gk4gLkvasqvp+iWnTZZciPqT+Ug5SAyhE59/iLcgEAaJbTw3VFqE/fPxVRoPYnX1\n"
"aKaAfKeOX0sCAwEAAaNQME4wHQYDVR0OBBYEFGuL0/opcpoBr3j9iekEvipNK6ZP\n"
"MB8GA1UdIwQYMBaAFGuL0/opcpoBr3j9iekEvipNK6ZPMAwGA1UdEwQFMAMBAf8w\n"
"DQYJKoZIhvcNAQELBQADggEBAElV/jkQEh+/a5mmlp8ITHGDvHqwauyLB9RDbLdI\n"
"vZDPl8rxMnMdN1gJj8uWiRTM/yqlQ7MZSClYzFjNvRXK379LBjPatmXJfPQHzP6O\n"
"nFoF/kHK7itZmAIUhaQYDDpgPuiJ/oaWb67VnV86ohF7S4qTHPs+J+yzLX/FpF1F\n"
"uiAwF33f08YudT3+FD6M7EgEzKxsliItGzcQ//VnV8U+gG5rEDX7vDOqQMIwYqA0\n"
"fF6qDd+mdf/Hd8oxkqeOONYh65biUI9jAp7KLnLiReYXkH1D9JDPJFTeDNA5ZXQr\n"
"iN/3XWoy7enMt1Qu2Q1jjormAG8nLhgaUC377xEIJE+j3a0=\n"
"-----END CERTIFICATE-----\n";

	std::string const key =
"-----BEGIN PRIVATE KEY-----\n"
"MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDE672+gAhwtpNe\n"
"QMvbTnWU4gVcYLAmZdThFsTzvkGPSTaq5BWC8U97uvS9zF5jYJ/PGYqzg+6dcW4w\n"
"pTk/dm0l9ZIFi27mxsairuNjSwQ2czyr1FWX+XdbCxPuIXRHf4BBBmS7QY8jpHuZ\n"
"wfsuAWCuxkVSS2w0tEMMvneSOH8eaKhcWF8eux1araTdjR2FcyzOVfpwg3nN9apg\n"
"WsxagCvaDT9n30Cgje1YwmxUDhZtvfnL088UFm/igJPCiItnjdhbgGwiUeDXTIJO\n"
"IC5L2rKr6folp02WXIj6k/lIOUgMoROff4i3IBAGiW08N1RahP3z8VUaD2J19Wim\n"
"gHynjl9LAgMBAAECggEBAKCVrhJfzoI8IUlHhfa9sN1MxBplLsDhYgx8yPgMOuJi\n"
"ThZmEbTKnIrGFzeAJajc7vWwWo+yEzCJg9ZfpqO+K5w8+mtTHYlMqEeaXwxl7HWK\n"
"2/s0GOjqIw83pXUYCv8TVr+wOw0JlXT3eWQV8IO/09wzC+zkXMVOCy+lU1UGhYOB\n"
"XIujDYcTXth/+WBZmQ3az1mjNK19DC+IQF8nTW9DaakW9h8cT+bxfpToZgZuw9hc\n"
"HzzMiE0sfGUPEEF5LacOmIq0FH9yV+oQNvny67u/2JavQw2mVHMYmPGWvBn8xRaV\n"
"Cy5hH86OYvMbAmQK9pr6MemmYQi/1QubiTWdMzXnp8ECgYEA/Vi61EgXBWvAj9QN\n"
"vH9pUCADWuJiXGNG2EuG6tYwttzrhqme0q+9RXy/Wz0MOM8Gk895pODtHZSCfGuu\n"
"aNyS6fJkYA82Q8pzpaZeWG/vVQ2SrnIVLcNogKBcXliJEb0YLFq0d/ePLg0PJTY+\n"
"NDDbhjYRkN61d08RDvTjF5nFZ/kCgYEAxvu5KnPFFAZ15X+9hzGDhhf6r5HgYjMA\n"
"SlphgrgFEo9qzXbx26fibdmQeXYYhXfIbwtMXTwMSUXVN1Cs9ZKa00/Qp8rNeydd\n"
"QRU6zhsEHn4YU6rxKxBz3pxl8hynOv0nmWd9r5aXQYAWkHQeb+X78sU2CEE/mlsZ\n"
"0pvMhmWe+mMCgYA3PauvMfDjG7WnJuO/4EBEWlag8I/l+TevXfiTKBUDKnSorj+V\n"
"TQCGMEdBS7Rohqu2exzZGLpbItC49HnZH49hN5svXuHEMla5HeegfPfAoe8D3phD\n"
"nEIjGdRKNh/dIFAvC7AiIHa14d8VjBhQJP8Y6p0163nCBBmCG1+Q+9SRcQKBgQCj\n"
"Ev2nqwVi6gCJO21KdOvDY7eRV8467G1agkPT65hMo7j19ns0d5x8Roe+42gpSge7\n"
"6diFuIahLlgVY0q8X4//ijQIr45DVfl5MzrkWwO/MbwiJcBMeMldMXPjPlRXZc2k\n"
"TUqWMqZ3ic/0RxYCwsr/JVyo20CS8gJxtjmiE3p83QKBgGAklFx6Z5LaamaSHYIL\n"
"dFrRITAGl1yk+3ycdXMHHrwCWJs0Ajg/E56kRS3J0J7sSuLVN7x0ZohMCaviTd4C\n"
"M3S7HwUfHPc3cocjRovKF/h/U5Ew4FfBdlhWj9vbBwI49MSjiTDGLv/r0gSZt+Fu\n"
"TP6IHXLTEz00ls8L4jwY2j9X\n"
"-----END PRIVATE KEY-----\n";

	std::string const dh =
"-----BEGIN DH PARAMETERS-----\n"
"MIIBCAKCAQEAqoQqJTcROwqbP6/7XP8GDizthkAyJJXJSq3tMwzcJ7AOv/NFKmh4\n"
"RVKVvFdvHqOBkrurJRJXVEX73ez9MbbT11lnC+Ql2QSTtjDyE6om7O0g/DuAchtc\n"
"Rz2LUvkeP/aYHxJsIqOhlmKj3CwUE8h7+v7ewxva7swUyYv4XOxyVcf640HfwKC6\n"
"NpS+vdj5TdRq2M8o0WFX7mtfWBdvvwaATsptrjBW4eKhPLBzKg3pJfJCAz6PN6lv\n"
"EvlET2CCSl/Xbd1Sv49XxnixY51x2nj3PWGwTGIsm8la5qSDU3lw9OgJ5uYi40Vn\n"
"BjXR9ijYE5PDrhiWQF8+dV2xO2XDo3Z5mwIBAg==\n"
"-----END DH PARAMETERS-----\n";

	ctx.set_password_callback(
		[](std::size_t,
			boost::asio::ssl::context_base::password_purpose)
	{
		return "test";
	});

	ctx.set_options(
		boost::asio::ssl::context::default_workarounds |
		boost::asio::ssl::context::no_sslv2 |
		boost::asio::ssl::context::single_dh_use);

	ctx.use_certificate_chain(
		boost::asio::buffer(cert.data(), cert.size()));

	ctx.use_private_key(
		boost::asio::buffer(key.data(), key.size()),
		boost::asio::ssl::context::file_format::pem);

	ctx.use_tmp_dh(
		boost::asio::buffer(dh.data(), dh.size()));
}
#endif
