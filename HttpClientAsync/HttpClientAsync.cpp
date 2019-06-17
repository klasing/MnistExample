#include <string>

// File client
#include "http_client_async.cpp"

using namespace std;
//****************************************************************************
//*                     input_to_string
//****************************************************************************
string input_to_string(const string& hdr, string& val) {
	string inpt;

	cout << hdr << val << " ";
	getline(cin, inpt, '\n');

	return inpt.length() > 0 ? inpt : val;
}

//****************************************************************************
//*                     cnnct
//****************************************************************************
void cnnct(string& ip_addr, string& str_port, string& file_name) {

	ip_addr   = input_to_string("IP.....: ", ip_addr);
	str_port  = input_to_string("Port...: ", str_port);
	file_name = input_to_string("File...: ", file_name);

	cout << "IP: " << ip_addr 
		<< ", Port: " << str_port 
		<< ", File: " << file_name << endl;
}

//****************************************************************************
//*                     download
//****************************************************************************
void download(const string ip_addr, const string str_port, 
	const string file_name) {

	char cmd[] = "http-client-async";
	//char host[] = "192.168.178.14";//"lappie";//"127.0.0.1";
	char* host = const_cast<char*>(ip_addr.c_str());
	//char port[] = "8080";
	char* port = const_cast<char*>(str_port.c_str());
	char target[] = "/";
	char version[] = "1.0";
	char* argv[] = { cmd, host , port, target, version };
	ns_http_client_async::http_client_async(5, argv);
}

//****************************************************************************
//*                     upload
//****************************************************************************
void upload() {
}

//****************************************************************************
//*                     main
//****************************************************************************
int main() {
	string ip_addr = "192.168.178.14";
	string port = "8080";
	string file_name = "index.html";

	bool bProceed = true;
	int iChar;
	char char_new_line;

	while (bProceed) {
		cout << "HTTP Client Async" << endl;
		cout << "=================" << endl;
		cout << " 1) Connect" << endl;
		cout << " 2) Download" << endl;
		cout << " 3) Upload" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;
		// getting rid of new-line character
		cin.get(char_new_line);

		switch (iChar) {
		case 1:
			cnnct(ip_addr, port, file_name);
			break;
		case 2:
			download(ip_addr, port, file_name);
			break;
		case 3:
			upload();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
}

