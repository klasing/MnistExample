// File server for uploading
#include "http_server_async.cpp"

int main() {
	char cmd[] = "http-server-async";
	char address[] = "0.0.0.0";
	char port[] = "8080";
	char doc_root[] = ".";
	char threads[] = "1";
	char* argv[] = { cmd, address , port, doc_root, threads };
	ns_http_server_async::http_server_async(5, argv);
}
