// Example 1.9
// Using boost::intrusive_ptr
#include <boost/intrusive_ptr.hpp>
#include <atlbase.h>
#include <iostream>

using namespace std;
namespace ns_example_1_9 {
	//void intrusive_ptr_add_ref(IDispatch* p) { p->AddRef(); }
	//void intrusive_ptr_release(IDispatch* p) { p->Release(); }

	//void check_windows_folder() {
	//	CLSID clsid;
	//	CLSIDFromProgID(CComBSTR{ "Scripting.FileSystemObject" }, &clsid);
	//	void* p;
	//	CoCreateInstance(clsid, 0, CLSCTX_INPROC_SERVER, __uuidof(IDispatch), &p);
	//	boost::intrusive_ptr<IDispatch> disp{ static_cast<IDispatch*>(p), false };
	//	CComDispatchDriver dd{ disp.get() };
	//	CComVariant arg{ "C:\\Windows" };
	//	CComVariant ret{ false };
	//	dd.Invoke1(CComBSTR{ "FolderExists" }, &arg, &ret);
	//	cout << "-> " << boolalpha << (ret.boolVal != 0) << '\n';

	//}
	//inline void example_1_9() {
	//	CoInitialize(0);
	//	check_windows_folder();
	//	CoUninitialize();
	//}
	inline void example_1_9() {
		//TODO
	}
}

// Compiler reports:
//1 > C:\Program Files\boost\boost_1_70_0\boost\smart_ptr\intrusive_ptr.hpp(98) : error C3861 : 'intrusive_ptr_release' : identifier not found
//1 > C:\Program Files\boost\boost_1_70_0\boost\smart_ptr\intrusive_ptr.hpp(98) : message:  'intrusive_ptr_release' : function was not declared in the template definition context and can be found only via argument - dependent lookup in the instantiation context
//1 > C:\Program Files\boost\boost_1_70_0\boost\smart_ptr\intrusive_ptr.hpp(97) : message:  while compiling class template member function 'boost::intrusive_ptr<IDispatch>::~intrusive_ptr(void)'
//1 > C:\Users\Klasing\MyProgramming\MyCpp\Projects_2019\CNN\MnistExample\BoostLibrary\example_1_9.cpp(17) : message:  see reference to function template instantiation 'boost::intrusive_ptr<IDispatch>::~intrusive_ptr(void)' being compiled
