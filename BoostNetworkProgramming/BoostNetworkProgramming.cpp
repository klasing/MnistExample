// BoostNetworkProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main() {
	int iChar;

    cout << "Table of Contents" << endl;
	cout << endl;
	cout << "Chapter 1: Getting started with Boost.Asio" << endl;
	cout << "  1.1 What is Boost.Asio?" << endl;
	cout << "    1.1.1 History" << endl;
	cout << "    1.1.2 Dependencies" << endl;
	cout << "    1.1.3 Building Boost.Asio" << endl;
	cout << "    1.1.4 Important macros" << endl;
	cout << "  1.2 Synchronous versus asynchronous" << endl;
	cout << "  1.3 Exceptions versus error codes" << endl;
	cout << "  1.4 Threading in Boost.Asio" << endl;
	cout << "  1.5 Not just networking" << endl;
	cout << "  1.6 timers" << endl;
	cout << "  1.7 The io_service class" << endl;
	cout << "  1.8 Summary" << endl;
	cout << "Chapter 2: Boost.Asio Fundamentals" << endl;
	cout << "  2.1 The Network API" << endl;
	cout << "    2.1.1 Boost.Asio namespaces" << endl;
	cout << "    2.1.2 IP addresses" << endl;
	cout << "    2.1.3 Endpoints" << endl;
	cout << "    2.1.4 Sockets" << endl;
	cout << "      2.1.4.1 Synchronous error codes" << endl;
	cout << "      2.1.4.2 Socket member functions" << endl;
	cout << "        Connection-related functions" << endl;
	cout << "        Read/write functions" << endl;
	cout << "        Socket control" << endl;
	cout << "        TCP versus UDP versus ICMP" << endl;
	cout << "        Miscellaneous functions" << endl;
	cout << "      2.1.4.3 Other considerations" << endl;
	cout << "        Socket buffers" << endl;
	cout << "        The buffer function wrapper" << endl;
	cout << "    2.1.5 The read/write/connect free functions" << endl;
	cout << "      2.1.5.1 The connect functions" << endl;
	cout << "      2.1.5.2 The read/write functions" << endl;
	cout << "        The read_until/async_read_until functions" << endl;
	cout << "        The *_at functions" << endl;
	cout << "  2.2 Asynchronous programming" << endl;
	cout << "    2.2.1 The need for going asynchronous" << endl;
	cout << "    2.2.2 Asynchronous run(), run_one(), poll(), poll_one()" << endl;
	cout << "      2.2.2.1 Running forever" << endl;
	cout << "      2.2.2.2 The run_one(), poll(), poll_one() functions" << endl;
	cout << "    2.2.3 Asynchronous work" << endl;
	cout << "    2.2.4 Asynchronous post() versus dispatch() versus wrap()" << endl;
	cout << "  2.3 Staying alive" << endl;
	cout << "  2.4 Summary" << endl;
	cout << "Chapter 3: Echo Server/Clients" << endl;
	cout << "  3.1 TCP Echo server/clients" << endl;
	cout << "    3.1.1 TCP synchronous client" << endl;
	cout << "    3.1.2 TCP synchronous server" << endl;
	cout << "    3.1.3 TCP asynchronous client" << endl;
	cout << "    3.1.4 TCP asynchronous server" << endl;
	cout << "    3.1.5 The code" << endl;
	cout << "  3.2 UDP Echo server/clients" << endl;
	cout << "    3.2.1 UDP synchronous Echo client" << endl;
	cout << "    3.2.2 UDP synchronous Echo server" << endl;
	cout << "  3.3 Summary" << endl;
	cout << "Chapter 4: Client and Server" << endl;
	cout << "  4.1 The synchronous client/server" << endl;
	cout << "    4.1.1 Synchronous client" << endl;
	cout << "    4.1.2 Synchronous server" << endl;
	cout << "  4.2 The asynchronous client/server" << endl;
	cout << "    4.2.1 Asynchronous client" << endl;
	cout << "    4.2.2 Asynchronous server" << endl;
	cout << "  4.3 Summary" << endl;
	cout << "Chapter 5: Synchronous Versus Asynchronous" << endl;
	cout << "  5.1 Mixing synchronous and asynchronous programming" << endl;
	cout << "  5.2 Passing client to server messages and vice versa" << endl;
	cout << "  5.3 Synchronous I/O in client applications" << endl;
	cout << "  5.4 Synchronous I/O in server applications" << endl;
	cout << "    5.4.1 Threading in a synchronous server" << endl;
	cout << "  5.5 Asynchronous I/O in client applications" << endl;
	cout << "  5.6 Asynchronous I/O in server applications" << endl;
	cout << "    5.6.1 Threading in an asynchronous server" << endl;
	cout << "  5.7 Asynchronous operations" << endl;
	cout << "  5.8 Implementing proxies" << endl;
	cout << "  5.9 Summary" << endl;
	cout << "Chapter 6: Boost.Asio - Other Features" << endl;
	cout << "  6.1 std streams and std buffer I/O" << endl;
	cout << "    6.1.1 Boost.Asio and the STL streams" << endl;
	cout << "    6.1.2 The streambuf class" << endl;
	cout << "    6.1.3 The free functions that deal with streambuf objects" << endl;
	cout << "  6.2 Co-routines" << endl;
	cout << "  6.3 Summary" << endl;
	cout << "Chapter 7: Boost.Asio - Advanced Topics" << endl;
	cout << "  7.1 Asio versus Boost.Asio" << endl;
	cout << "  7.2 Debugging" << endl;
	cout << "    7.2.1 Handler tracking information" << endl;
	cout << "    7.2.2 An example" << endl;
	cout << "    7.2.3 Handler tracking to file" << endl;
	cout << "  7.3 SSL" << endl;
	cout << "  7.4 Boost.Asio Windows features" << endl;
	cout << "    7.4.1 Stream handlers" << endl;
	cout << "    7.4.2 Random access Handles" << endl;
	cout << "    7.4.3 Object Handles" << endl;
	cout << "  7.5 Boost.Asio POSIX features" << endl;
	cout << "    7.5.1 Local sockets" << endl;
	cout << "    7.5.2 Connecting local sockets" << endl;
	cout << "    7.5.3 POSIX file descriptor" << endl;
	cout << "    7.5.4 Fork" << endl;
	cout << "  7.6 Summary" << endl;

	cin >> iChar;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
