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
		/*
		"-----BEGIN CERTIFICATE-----\n"
		"MIIDaDCCAlCgAwIBAgIJAO8vBu8i8exWMA0GCSqGSIb3DQEBCwUAMEkxCzAJBgNV\n"
		"BAYTAlVTMQswCQYDVQQIDAJDQTEtMCsGA1UEBwwkTG9zIEFuZ2VsZXNPPUJlYXN0\n"
		"Q049d3d3LmV4YW1wbGUuY29tMB4XDTE3MDUwMzE4MzkxMloXDTQ0MDkxODE4Mzkx\n"
		"MlowSTELMAkGA1UEBhMCVVMxCzAJBgNVBAgMAkNBMS0wKwYDVQQHDCRMb3MgQW5n\n"
		"ZWxlc089QmVhc3RDTj13d3cuZXhhbXBsZS5jb20wggEiMA0GCSqGSIb3DQEBAQUA\n"
		"A4IBDwAwggEKAoIBAQDJ7BRKFO8fqmsEXw8v9YOVXyrQVsVbjSSGEs4Vzs4cJgcF\n"
		"xqGitbnLIrOgiJpRAPLy5MNcAXE1strVGfdEf7xMYSZ/4wOrxUyVw/Ltgsft8m7b\n"
		"Fu8TsCzO6XrxpnVtWk506YZ7ToTa5UjHfBi2+pWTxbpN12UhiZNUcrRsqTFW+6fO\n"
		"9d7xm5wlaZG8cMdg0cO1bhkz45JSl3wWKIES7t3EfKePZbNlQ5hPy7Pd5JTmdGBp\n"
		"yY8anC8u4LPbmgW0/U31PH0rRVfGcBbZsAoQw5Tc5dnb6N2GEIbq3ehSfdDHGnrv\n"
		"enu2tOK9Qx6GEzXh3sekZkxcgh+NlIxCNxu//Dk9AgMBAAGjUzBRMB0GA1UdDgQW\n"
		"BBTZh0N9Ne1OD7GBGJYz4PNESHuXezAfBgNVHSMEGDAWgBTZh0N9Ne1OD7GBGJYz\n"
		"4PNESHuXezAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCmTJVT\n"
		"LH5Cru1vXtzb3N9dyolcVH82xFVwPewArchgq+CEkajOU9bnzCqvhM4CryBb4cUs\n"
		"gqXWp85hAh55uBOqXb2yyESEleMCJEiVTwm/m26FdONvEGptsiCmF5Gxi0YRtn8N\n"
		"V+KhrQaAyLrLdPYI7TrwAOisq2I1cD0mt+xgwuv/654Rl3IhOMx+fKWKJ9qLAiaE\n"
		"fQyshjlPP9mYVxWOxqctUdQ8UnsUKKGEUcVrA08i1OAnVKlPFjKBvk+r7jpsTPcr\n"
		"9pWXTO9JrYMML7d+XRSZA1n3856OqZDX4403+9FnXCvfcLZLLKTBvwwFgEFGpzjK\n"
		"UEVbkhd5qstF6qWK\n"
		"-----END CERTIFICATE-----\n";
		*/
///*
"-----BEGIN CERTIFICATE-----\n"
"MIID4zCCAsugAwIBAgIJAJt4xVIOqXrcMA0GCSqGSIb3DQEBCwUAMIGHMQswCQYD\n"
"VQQGEwJOTDEQMA4GA1UECAwHVVRSRUNIVDEQMA4GA1UEBwwHVVRSRUNIVDESMBAG\n"
"A1UECgwJTVlDT01QQU5ZMRowGAYDVQQDDBF3d3cubG9jYWxob3N0LmNvbTEkMCIG\n"
"CSqGSIb3DQEJARYVa2xhc2luZzExNTlAZ21haWwuY29tMB4XDTE5MDcyMDA4MTg0\n"
"MFoXDTQ2MTIwNTA4MTg0MFowgYcxCzAJBgNVBAYTAk5MMRAwDgYDVQQIDAdVVFJF\n"
"Q0hUMRAwDgYDVQQHDAdVVFJFQ0hUMRIwEAYDVQQKDAlNWUNPTVBBTlkxGjAYBgNV\n"
"BAMMEXd3dy5sb2NhbGhvc3QuY29tMSQwIgYJKoZIhvcNAQkBFhVrbGFzaW5nMTE1\n"
"OUBnbWFpbC5jb20wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCzNTKU\n"
"DOKms+9Yru1LTu6x33kKmwNOF6EUC6KVJyVAOyICZGA8Vi5W8/YeHTtFX+FpZzQ6\n"
"TbQrPWjVq5UUaRW3HO3Bsf6ITFBmBUlfZumcigqsLjPwzcDhmJGEhfiYc9+ouxTx\n"
"BwmjstPPg9Xvq2gtRJR6/T9CS9vUlcboI0jX9mzdk3ckfXN6ljFhrrOi5dzHvPrY\n"
"t9Nqx0aXBKcgIgVjQ/wqcCVuNCJEFxrzlM6V5u0lVq1uxtIibhUT+j9N1XbBvoXY\n"
"/aT0GfGQZ7+PgF8jUJqnpPgz/1DmLs0vgZ/121aNTxTtkfdnAyAoWqS9zg0IetL/\n"
"wi9fFg+8Dt1LOaBlAgMBAAGjUDBOMB0GA1UdDgQWBBSsLhOG79NBLOHoTETQR73o\n"
"810tUTAfBgNVHSMEGDAWgBSsLhOG79NBLOHoTETQR73o810tUTAMBgNVHRMEBTAD\n"
"AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCUXeLCXnbEw6owyqqKpEoNz4ltV1YW3584\n"
"Nlz0Ln3GQWIfzBfgrdMTPQvkat5KbMTuGvk8kHrGmwV8i+d1969G5VxKmw8Dtk67\n"
"gjRwrGKI1r2miXAxYnke0+0V4SXpxxDbVjMmZhS4UC+btRp7nHq3x6fa1qSgU59x\n"
"UbKeNAV3E+zc2VoHCt7gn6aYsZVhY1VfQ+Rm7r/9uP8BGwiUvMFewzTjyGAFVZSv\n"
"Aognc/7LxP2hqKHvek8JarJljsns78jr2xtjWp5SNI8BE37CX4x144BFKCkBw5/8\n"
"mlbJdWi81Tda/REn6lZ0MAl8EltcxG9bw9H86MgsxC8V6JoOtqTL\n"
"-----END CERTIFICATE-----\n";
//*/

	std::string const key =
		/*
		"-----BEGIN PRIVATE KEY-----\n"
		"MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDJ7BRKFO8fqmsE\n"
		"Xw8v9YOVXyrQVsVbjSSGEs4Vzs4cJgcFxqGitbnLIrOgiJpRAPLy5MNcAXE1strV\n"
		"GfdEf7xMYSZ/4wOrxUyVw/Ltgsft8m7bFu8TsCzO6XrxpnVtWk506YZ7ToTa5UjH\n"
		"fBi2+pWTxbpN12UhiZNUcrRsqTFW+6fO9d7xm5wlaZG8cMdg0cO1bhkz45JSl3wW\n"
		"KIES7t3EfKePZbNlQ5hPy7Pd5JTmdGBpyY8anC8u4LPbmgW0/U31PH0rRVfGcBbZ\n"
		"sAoQw5Tc5dnb6N2GEIbq3ehSfdDHGnrvenu2tOK9Qx6GEzXh3sekZkxcgh+NlIxC\n"
		"Nxu//Dk9AgMBAAECggEBAK1gV8uETg4SdfE67f9v/5uyK0DYQH1ro4C7hNiUycTB\n"
		"oiYDd6YOA4m4MiQVJuuGtRR5+IR3eI1zFRMFSJs4UqYChNwqQGys7CVsKpplQOW+\n"
		"1BCqkH2HN/Ix5662Dv3mHJemLCKUON77IJKoq0/xuZ04mc9csykox6grFWB3pjXY\n"
		"OEn9U8pt5KNldWfpfAZ7xu9WfyvthGXlhfwKEetOuHfAQv7FF6s25UIEU6Hmnwp9\n"
		"VmYp2twfMGdztz/gfFjKOGxf92RG+FMSkyAPq/vhyB7oQWxa+vdBn6BSdsfn27Qs\n"
		"bTvXrGe4FYcbuw4WkAKTljZX7TUegkXiwFoSps0jegECgYEA7o5AcRTZVUmmSs8W\n"
		"PUHn89UEuDAMFVk7grG1bg8exLQSpugCykcqXt1WNrqB7x6nB+dbVANWNhSmhgCg\n"
		"VrV941vbx8ketqZ9YInSbGPWIU/tss3r8Yx2Ct3mQpvpGC6iGHzEc/NHJP8Efvh/\n"
		"CcUWmLjLGJYYeP5oNu5cncC3fXUCgYEA2LANATm0A6sFVGe3sSLO9un1brA4zlZE\n"
		"Hjd3KOZnMPt73B426qUOcw5B2wIS8GJsUES0P94pKg83oyzmoUV9vJpJLjHA4qmL\n"
		"CDAd6CjAmE5ea4dFdZwDDS8F9FntJMdPQJA9vq+JaeS+k7ds3+7oiNe+RUIHR1Sz\n"
		"VEAKh3Xw66kCgYB7KO/2Mchesu5qku2tZJhHF4QfP5cNcos511uO3bmJ3ln+16uR\n"
		"GRqz7Vu0V6f7dvzPJM/O2QYqV5D9f9dHzN2YgvU9+QSlUeFK9PyxPv3vJt/WP1//\n"
		"zf+nbpaRbwLxnCnNsKSQJFpnrE166/pSZfFbmZQpNlyeIuJU8czZGQTifQKBgHXe\n"
		"/pQGEZhVNab+bHwdFTxXdDzr+1qyrodJYLaM7uFES9InVXQ6qSuJO+WosSi2QXlA\n"
		"hlSfwwCwGnHXAPYFWSp5Owm34tbpp0mi8wHQ+UNgjhgsE2qwnTBUvgZ3zHpPORtD\n"
		"23KZBkTmO40bIEyIJ1IZGdWO32q79nkEBTY+v/lRAoGBAI1rbouFYPBrTYQ9kcjt\n"
		"1yfu4JF5MvO9JrHQ9tOwkqDmNCWx9xWXbgydsn/eFtuUMULWsG3lNjfst/Esb8ch\n"
		"k5cZd6pdJZa4/vhEwrYYSuEjMCnRb0lUsm7TsHxQrUd6Fi/mUuFU/haC0o0chLq7\n"
		"pVOUFq5mW8p0zbtfHbjkgxyF\n"
		"-----END PRIVATE KEY-----\n";
		*/
///*
"-----BEGIN PRIVATE KEY-----\n"
"MIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQCzNTKUDOKms+9Y\n"
"ru1LTu6x33kKmwNOF6EUC6KVJyVAOyICZGA8Vi5W8/YeHTtFX+FpZzQ6TbQrPWjV\n"
"q5UUaRW3HO3Bsf6ITFBmBUlfZumcigqsLjPwzcDhmJGEhfiYc9+ouxTxBwmjstPP\n"
"g9Xvq2gtRJR6/T9CS9vUlcboI0jX9mzdk3ckfXN6ljFhrrOi5dzHvPrYt9Nqx0aX\n"
"BKcgIgVjQ/wqcCVuNCJEFxrzlM6V5u0lVq1uxtIibhUT+j9N1XbBvoXY/aT0GfGQ\n"
"Z7+PgF8jUJqnpPgz/1DmLs0vgZ/121aNTxTtkfdnAyAoWqS9zg0IetL/wi9fFg+8\n"
"Dt1LOaBlAgMBAAECggEAF6Or0VXFzCGuL++bQ7Tczb/h0qFSFUoOqHtEbhJk2o0y\n"
"VkhxXWQs5rF1xNEsUWFtdZ70h8BaRN3r50uj9bZK9AWv4z4cilQuwtZtsFT9+fVH\n"
"pSDPHzO0/s1GXMnjWhDm7vYGtCiuf9aGFDiazuu4aUhDodmoL5GcJPXA8Dw/TqVt\n"
"TswBu9NG85ykTXYa0UlQx/5rQVkhEDk9Y0gmM4OMt57qBgB3Hm07RNiKTyonV6aj\n"
"7MIUo3QrAbrHfQjxLtK4GGkxfqhpJjS/rsuOQxv6Eyiz101lfifDTxET+AUd7qXW\n"
"y/WOwYuhpt/UM3QqMmG9CG6OSyWzLQ2MOPvF1gOEQQKBgQDpIHWoR+Dxocm41Cb0\n"
"WTurggsdpLzFLXPwiAHEoFGpwWf8pmOlspvOLEzI/n0ttuI3MHhwHpzVVUvO5JyA\n"
"cG1Mr232t1D6L82yYkPdv/mE+OHQz2xmOQ5JpO8WCjLB1SqNIQM6wGmmVChWkzby\n"
"ha2wlFVW3AgEnE+FzfV1iI2JkQKBgQDEym7IUocpyFihHnEV3PQS2d6pD/XkD5hJ\n"
"Gj+ET9lacVXdMopv89kwWS4rO6UpPhM0Lso9RIgzaOblCC0V9lBbulPRvASA4F+d\n"
"3WjReXc9sHcrNdlA8bHheXEjOnp9AXTHWyt28R8Z8yewWCgPPtmxhn0dzY4YFSpp\n"
"36YCwjAflQKBgQC5l5vTgpW0CAcd29e/Q6LbYUYULWgS2aKpZL1zmeYpbM2qN5Sw\n"
"/0ZGlsHyaZeiYywon6/iIpzcwXD+nsVxAxAgsrCqbzpKUvBBCTXaPdEZaUHtCJTV\n"
"tKqJOoMUWr4Zzeh4PkXh6fix7+HFOqHN5Vpnb0+ZPMYtVXuBnHvDPBjh4QKBgQCf\n"
"KphF4DJAgjHlRyjyJP8ojB1Coo0gQ9jJL7i1/JtxQn/PZASCnjlJmKf2Ac0JOZLw\n"
"vvOGcHq1EiDGmEFXJR1Dw8XtumPuFQxhM+aGnvbp52PLiEdK9vIHy2DNvIu7tcTN\n"
"RZk3H7knFPtB71ufURdkNcHWrB5ErkHa1jCAxK2FrQKBgQDimDGrnPt3w25ZmUaC\n"
"U9sXdClX7zj2G/iNB+ayIRKGIV9FNKNdYgTbwE4vNwoEByFx75PV5TC6tiPCmzHv\n"
"Da+Sdm4/QJ1G62Jq54htPD8UeDfS992IsXUnH8IKOWrOGSFXnGcAaWpkL8y+pkuP\n"
"mncg8wYJwArpqKh+BIgW67VnFw==\n"
"-----END PRIVATE KEY-----\n";
//*/

	std::string const dh =
		/*
		"-----BEGIN DH PARAMETERS-----\n"
		"MIIBCAKCAQEArzQc5mpm0Fs8yahDeySj31JZlwEphUdZ9StM2D8+Fo7TMduGtSi+\n"
		"/HRWVwHcTFAgrxVdm+dl474mOUqqaz4MpzIb6+6OVfWHbQJmXPepZKyu4LgUPvY/\n"
		"4q3/iDMjIS0fLOu/bLuObwU5ccZmDgfhmz1GanRlTQOiYRty3FiOATWZBRh6uv4u\n"
		"tff4A9Bm3V9tLx9S6djq31w31Gl7OQhryodW28kc16t9TvO1BzcV3HjRPwpe701X\n"
		"oEEZdnZWANkkpR/m/pfgdmGPU66S2sXMHgsliViQWpDCYeehrvFRHEdR9NV+XJfC\n"
		"QMUk26jPTIVTLfXmmwU0u8vUkpR7LQKkwwIBAg==\n"
		"-----END DH PARAMETERS-----\n";
		*/
///*
"-----BEGIN DH PARAMETERS-----\n"
"MIIBCAKCAQEAu2rRI4TgXKOmY98GOsnaWaANMgGRVsMYE/iSrkLY4tDsKwIO11ly\n"
"MfmMQnDue8cRFgFwnwi2hqzkFGBbvy1iD746DNIGy135nP6YIAfZXqUfMzA1RDKN\n"
"0PfhJpH6SFIQdxNpixy5VZtHeTCpwKimZqbQCyu6KJXa0yZr3P9Q/DhNwG956pny\n"
"f0ilUuWoyUIldLxYjhvWCzGeWsywyCxlbHQGXZ5I7T5pQ8kCVRV7ve8+C7qC7kBX\n"
"xRu9He6Xtf4vgAN6M+EsTrl0S4dcADYzhWmwGvJQHWcraebeCREP8z5m/X6BqEWy\n"
"lgmZGHkDDFQ40byUxF1kFslammIW+hjswwIBAg==\n"
"-----END DH PARAMETERS-----\n";
//*/

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
