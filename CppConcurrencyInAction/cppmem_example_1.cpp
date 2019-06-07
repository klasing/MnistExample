// CppMem goto:
// http://svr-pes20-cppmem.cl.cam.ac.uk/cppmem/index.html
// For example goto:
// https://www.modernescpp.com/index.php/cppmem-an-overview

// the code is specific for the site, and won't fit into this project,
// so uncomment this code and paste it into the website for a test run
//int main() {
//	atomic_int x = 2;
//	int y = 0;
//	{ { { x.store(3);
//	||| y = ((x.load()) == 3);
//		}}};
//	return 0;
//}