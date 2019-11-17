// Exercise 32.1
// File server for uploading
//#include "http_server_async.cpp"
//// File client
//#include "http_client_async.cpp"
//
//using namespace std;
//namespace ns_exercise_32_1 {
//	inline void exercise_32_1() {
//		//char cmd[] = "http-server-async";
//		//char address[] = "0.0.0.0";
//		//char port[] = "8080";
//		//char doc_root[] = ".";
//		//char threads[] = "1";
//		//char* argv[] = { cmd, address , port, doc_root, threads };
//		//ns_http_server_async::http_server_async(5, argv);
//
//		char cmd[] = "http-client-async";
//		char host[] = "www.example.com"; //"127.0.0.1";
//		char port[] = "80"; //"8080";
//		char target[] = "/";
//		char version[] = "1.0";
//		char* argv[] = { cmd, host , port, target, version };
//		ns_http_client_async::http_client_async(5, argv);
//	}
//}