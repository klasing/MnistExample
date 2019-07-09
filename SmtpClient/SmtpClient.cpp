// whois smtp.gmail.com -> 74.125.142.109
// port 587
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <string>
#include <memory>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

using namespace std;
namespace ns_smtp_client {
	//****************************************************************************
	//*                     read_socket
	//****************************************************************************
	void read_socket(SOCKET& sock) {
		int size_recv, total_size = 0;
		char chunk[BUFSIZ];
		char recvbuf[BUFSIZ] = "";

		memset(chunk, 0, BUFSIZ);  //clear the variable
		if ((size_recv = recv(sock, chunk, BUFSIZ, 0)) < 0)
			return;
		else
		{
			total_size += size_recv;
			strcat_s(recvbuf, BUFSIZ, chunk);
		}
		std::cout << recvbuf;
	}

	//****************************************************************************
	//*                     read_socket_ssl
	//****************************************************************************
	void read_socket_ssl(SSL* ssl) {
		int size_recv, total_size = 0;
		char chunk[BUFSIZ];
		char recvbuf[BUFSIZ] = "";

		memset(chunk, 0, BUFSIZ);  //clear the variable
		if ((size_recv = SSL_read(ssl, chunk, BUFSIZ)) < 0)
			return;
		else
		{
			total_size += size_recv;
			chunk[total_size] = '\0';
			strcat_s(recvbuf, BUFSIZ, chunk);
			std::cout << recvbuf;
		}
	}

	//****************************************************************************
	//*                     write_socket
	//****************************************************************************
	void write_socket(SOCKET& sock, const std::string& str) {
		char* buf = const_cast<char*>(str.c_str());
		int sended = 0;
		int all = strlen(buf);

		std::cout << str;
		while (all > 0) {
			sended = send(sock, buf, all, 0);
			*buf += sended;
			all -= sended;
		}
	}

	//****************************************************************************
	//*                     write_socket_ssl
	//****************************************************************************
	void write_socket_ssl(SSL* ssl, const std::string& str) {
		char* buf = const_cast<char*>(str.c_str());
		int sended = 0;

		std::cout << str;
		sended = SSL_write(ssl, buf, strlen(buf));
	}

	//****************************************************************************
	//*                     smtp_client
	//****************************************************************************
	int
		smtp_client(
			const string& mail_from,
			const string& rcpt_to,
			const string from,
			const string& to,
			const string& subject,
			const string& data
		)
	{
		WSADATA wsaData = { 0 };
		int iResult = 0;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			std::cout << "WSAStartup failed: %d" << std::endl;
			return iResult;
		}

		SOCKET sock = INVALID_SOCKET;
		int iFamily = AF_INET;
		int iType = SOCK_STREAM;
		int iProtocol = 0;

		// Initialize socket
		sock = socket(iFamily, iType, iProtocol);
		if (sock == INVALID_SOCKET) {
			std::cout << "socket function failed with error = %d" << std::endl;
			return sock; // an INVALID_SOCKET value is returned
		}

		// Connect to server
		struct sockaddr_in server;
		char host_id[] = "74.125.142.109";
		if (inet_addr(host_id) != INADDR_NONE)
			server.sin_addr.s_addr = inet_addr(host_id);
		server.sin_family = AF_INET;
		server.sin_port = htons(587);
		if (connect(sock, (struct sockaddr*) & server, sizeof server) == -1)
		{
			std::cout << "Can't connect to server" << std::endl;
			return -1;
		}

		read_socket(sock);
		write_socket(sock, "EHLO smtp.gmail.com\r\n");
		read_socket(sock);
		write_socket(sock, "STARTTLS\r\n");
		read_socket(sock);

		// switch over to the Secure Socket Layer (SSL)*/
		SSL* ssl = nullptr; 
		SSL_CTX* ctx;
				
		//Associate socket to SLL
		SSL_library_init();
		SSL_load_error_strings();
		ctx = SSL_CTX_new(TLSv1_client_method());
		ssl = SSL_new(ctx);
		SSL_set_fd(ssl, sock);

		// reconnect with SSL
		SSL_connect(ssl);
		write_socket_ssl(ssl, "EHLO smtp.gmail.com\r\n");
		read_socket_ssl(ssl);
		write_socket_ssl(ssl, "auth plain AGtsYXNpbmdzbXRwQGdtYWlsLmNvbQBwcHJ5cGRudGZxcWlpc3Ru\r\n");
		read_socket_ssl(ssl);

		// from/to part
		write_socket_ssl(ssl, "MAIL FROM:<" + mail_from + ">\r\n");
		read_socket_ssl(ssl);
		write_socket_ssl(ssl, "RCPT TO:<" + rcpt_to + ">\r\n");
		read_socket_ssl(ssl);

		// message data
		write_socket_ssl(ssl, "DATA\r\n");
		write_socket_ssl(ssl, "FROM:<" + from + ">\r\n");
		write_socket_ssl(ssl, "TO:<" + to + ">\r\n");
		write_socket_ssl(ssl, "SUBJECT:<" + subject + ">\r\n");
		write_socket_ssl(ssl, data + "\r\n");
		write_socket_ssl(ssl, "\r\n");
		write_socket_ssl(ssl, "\r\n");
		write_socket_ssl(ssl, ".\r\n");

		// start sending message to recipient
		write_socket_ssl(ssl, "QUIT\r\n");
		read_socket_ssl(ssl);

		return 0;
	}
}

int main() {
	cout << "main()" << endl;
	cout << "solely for testing purposes" << endl;
	ns_smtp_client::smtp_client(
		"klasingsmtp@gmail.com",
		"klasing1159@gmail.com",
		"klasingsmtp@gmail.com",
		"klasing1159@gmail.com",
		"no subject",
		"This message concerns a 'no subject' matter.\r\nIt is really of no importance or what so ever.");

	return EXIT_SUCCESS;
}
//// whois smtp.gmail.com -> 74.125.142.109
//// port 587
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#pragma comment(lib, "Ws2_32.lib")
//
//#include <iostream>
//#include <string>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <openssl/err.h>
//#include <openssl/ssl.h>
//
////****************************************************************************
////*                     global
////****************************************************************************
//SOCKET sock = INVALID_SOCKET;
//int iFamily = AF_INET;
//int iType = SOCK_STREAM;
//int iProtocol = 0;
//SSL* ssl = nullptr; /*Socket secured*/
//SSL_CTX* ctx;
//
////****************************************************************************
////*                     read_socket
////****************************************************************************
//void read_socket() {
//	int size_recv, total_size = 0;
//	char chunk[BUFSIZ];
//	char recvbuf[BUFSIZ] = "";
//
//	memset(chunk, 0, BUFSIZ);  //clear the variable
//	if ((size_recv = recv(sock, chunk, BUFSIZ, 0)) < 0)
//		return;
//	else
//	{
//		total_size += size_recv;
//		strcat_s(recvbuf, BUFSIZ, chunk);
//	}
//	std::cout << recvbuf;
//}
//
////****************************************************************************
////*                     read_socket_ssl
////****************************************************************************
//void read_socket_ssl() {
//	int size_recv, total_size = 0;
//	char chunk[BUFSIZ];
//	char recvbuf[BUFSIZ] = "";
//
//	memset(chunk, 0, BUFSIZ);  //clear the variable
//	if ((size_recv = SSL_read(ssl, chunk, BUFSIZ)) < 0)
//		return;
//	else
//	{
//		total_size += size_recv;
//		chunk[total_size] = '\0';
//		strcat_s(recvbuf, BUFSIZ, chunk);
//		std::cout << recvbuf;
//	}
//}
//
////****************************************************************************
////*                     write_socket
////****************************************************************************
//void write_socket(const std::string& str) {
//	char* buf = const_cast<char*>(str.c_str());
//	int sended = 0;
//	int all = strlen(buf);
//
//	std::cout << str;
//	while (all > 0) {
//		sended = send(sock, buf, all, 0);
//		*buf += sended;
//		all -= sended;
//	}
//}
//
////****************************************************************************
////*                     write_socket_ssl
////****************************************************************************
//void write_socket_ssl(const std::string& str) {
//	char* buf = const_cast<char*>(str.c_str());
//	int sended = 0;
//
//	std::cout << str;
//	sended = SSL_write(ssl, buf, strlen(buf));
//}
//
////****************************************************************************
////*                     main
////****************************************************************************
//int main() {
//	WSADATA wsaData = { 0 };
//	int iResult = 0;
//
//	// Initialize Winsock
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		std::cout << "WSAStartup failed: %d" << std::endl;
//		return iResult;
//	}
//
//	// https://github.com/rbingabo/SMTP-Client-TLS/blob/master/SMTP/SMTP.cpp
//	// Initialize socket
//	sock = socket(iFamily, iType, iProtocol);
//	if (sock == INVALID_SOCKET) {
//		std::cout << "socket function failed with error = %d" << std::endl;
//		return 1;
//	}
//
//	// Connect to server
//	struct sockaddr_in server;
//	char host_id[] = "74.125.142.109";
//	if (inet_addr(host_id) != INADDR_NONE)
//		server.sin_addr.s_addr = inet_addr(host_id);
//	server.sin_family = AF_INET;
//	server.sin_port = htons(587);
//	if (connect(sock, (struct sockaddr*) & server, sizeof server) == -1)
//	{
//		std::cout << "Can't connect to server" << std::endl;
//		return 1;
//	}
//
//	read_socket();
//	write_socket("EHLO smtp.gmail.com\r\n");
//	read_socket();
//	write_socket("STARTTLS\r\n");
//	read_socket();
//
//	//Associate socket to SLL
//	SSL_library_init();
//	SSL_load_error_strings();
//	ctx = SSL_CTX_new(TLSv1_client_method());
//	ssl = SSL_new(ctx);
//	SSL_set_fd(ssl, sock);
//
//	// reconnect with SSL
//	SSL_connect(ssl);
//	write_socket_ssl("EHLO smtp.gmail.com\r\n");
//	read_socket_ssl();
//	write_socket_ssl("auth plain AGtsYXNpbmdzbXRwQGdtYWlsLmNvbQBwcHJ5cGRudGZxcWlpc3Ru\r\n");
//	read_socket_ssl();
//
//	// from/to part
//	write_socket_ssl("MAIL FROM:<klasingsmtp@gmail.com>\r\n");
//	read_socket_ssl();
//	write_socket_ssl("RCPT TO:<klasing1159@gmail.com>\r\n");
//	read_socket_ssl();
//
//	// message data
//	write_socket_ssl("DATA\r\n");
//	write_socket_ssl("FROM:<klasingsmtp@gmail.com>\r\n");
//	write_socket_ssl("TO:<klasing1159@gmail.com>\r\n");
//	write_socket_ssl("SUBJECT:<no subject>\r\n");
//	write_socket_ssl("hier is je eigen bagger\r\n");
//	write_socket_ssl("\r\n");
//	write_socket_ssl("\r\n");
//	write_socket_ssl(".\r\n");
//
//	// start sending message to recipient
//	write_socket_ssl("QUIT\r\n");
//	read_socket_ssl();
//}
