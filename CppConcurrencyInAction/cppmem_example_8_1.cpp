// CppMem goto:
// http://svr-pes20-cppmem.cl.cam.ac.uk/cppmem/index.html
// For example goto:
// https://people.mpi-inf.mpg.de/~jblanche/ppdp2011-cpp-mem.pdf

//int main() {
//	atomic_int x = 0;
//	atomic_int y = 0;
//	{ { { 
//        x.store(1, ord_relaxed);
//        printf("y: %d\n", y.load(ord_relaxed);
//	|||
//        y.store(1, ord_relaxed);
//        printf("x: %d\n", x.load(ord_relaxed);
//	}}};
//	return 0;
//}
