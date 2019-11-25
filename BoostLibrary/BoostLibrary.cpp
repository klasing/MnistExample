#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/atomic.hpp>
//#include <boost/accumulators/accumulators.hpp>
//#include <boost/accumulators/statistics.hpp>
//#include <boost/algorithm/minmax.hpp>
//#include <boost/algorithm/minmax_element.hpp>
//#include <boost/cast.hpp>
#include <boost/chrono.hpp>
//#include <boost/core/null_deleter.hpp>
//#include <boost/coroutine/all.hpp>
//#include <boost/cstdint.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/foreach.hpp>
#include <boost/function.hpp>
//#include <boost/fusion/adapted.hpp>
//#include <boost/fusion/algorithm.hpp>
//#include <boost/fusion/container.hpp>
//#include <boost/fusion/sequence.hpp>
//#include <boost/fusion/iterator.hpp>
//#include <boost/fusion/tuple.hpp>
//#include <boost/fusion/view.hpp>
#include <boost/lockfree/policies.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>
//#include <boost/log/attributes.hpp>
//#include <boost/log/attributes/clock.hpp>
//#include <boost/log/attributes/counter.hpp>
//#include <boost/log/common.hpp>
//#include <boost/log/exceptions.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/sinks.hpp>
//#include <boost/log/sources/channel_logger.hpp>
//#include <boost/log/sources/logger.hpp>
//#include <boost/log/sources/severity_logger.hpp>
//#include <boost/log/support/date_time.hpp>
//#include <boost/log/utility/exception_handler.hpp>
//#include <boost/log/utility/string_literal.hpp>
#include <boost/make_shared.hpp>
//#include <boost/math/constants/constants.hpp>
//#include <boost/mpl/arg.hpp>
//#include <boost/mpl/int.hpp>
//#include <boost/mpl/placeholders.hpp>
//#include <boost/numeric/conversion/cast.hpp>
//#include <boost/parameter.hpp>
#include <boost/phoenix/phoenix.hpp>
//#include <boost/random.hpp>
#include <boost/ref.hpp>
//#include <boost/random/random_device.hpp>
#include <boost/scoped_array.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/system/error_code.hpp>
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <boost/thread/scoped_thread.hpp>
//#include <boost/tuple/tuple.hpp>
//#include <boost/type_traits.hpp>
//#include <boost/utility/enable_if.hpp>

#include <Windows.h>

#include <algorithm>
//#include <array>
#include <atomic>
#include <cstdlib>
//#include <cstddef>
//#include <cstdint>
#include <ctime>
//#include <exception>
#include <functional>
#include <iostream>
//#include <limits>
//#include <new>
//#include <stdexcept>
//#include <string>
#include <thread>
//#include <tuple>
//#include <typeinfo>
//#include <utility>
#include <vector>
//****************************************************************************
//*                     chapter_1
//****************************************************************************
auto
chapter_1() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 1. Boost.SmartPointers\n";
		std::cout << "==============================\n";
		std::cout << "    Sole Ownership\n";
		std::cout << " 1) Example 1: Using boost::scoped_ptr\n";
		std::cout << " 2) Example 2: Using boost::scoped_array\n";
		std::cout << "    Shared Ownership\n";
		std::cout << " 3) Example 3: \n";
		std::cout << " 4) Example 4: \n";
		std::cout << " 5) Example 5: \n";
		std::cout << " 6) Example 6: \n";
		std::cout << " 7) Example 7: \n";
		std::cout << "    Special Smart Pointers\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 1:
		{
			boost::scoped_ptr<int> p{ new int{1} };
			std::cout << "p has value: " << *p << '\n';
			p.reset(new int{ 2 });
			std::cout << "p has value: " << *p.get() << '\n';
			p.reset();
			std::cout << "p has state: " << std::boolalpha << static_cast<bool>(p) << '\n';
			break;
		} // eof case 1
		case 2:
		{
			const std::size_t ARRAY_SIZE = 2;
			boost::scoped_array<int> p{ new int[ARRAY_SIZE] };
			*p.get() = 1;
			p[1] = 2;
			for (int i = 0; i < ARRAY_SIZE; i++)
				std::cout << "p[i] has value....: " << p[i] << '\n';
			const std::size_t NEW_ARRAY_SIZE = 3;
			p.reset(new int[NEW_ARRAY_SIZE]);
			std::cout << "p's size is now...: " << NEW_ARRAY_SIZE << '\n';
			break;
		} // eof case 2
		case 3:
		{
			boost::shared_ptr<int> p1{ new int{1} };
			std::cout << "p1 has value: " << *p1 << '\n';
			boost::shared_ptr<int> p2{ p1 };
			p1.reset(new int{ 2 });
			std::cout << "p1 has value: " << *p1.get() << '\n';
			p1.reset();
			std::cout << "p2 has state: " << std::boolalpha << static_cast<bool>(p2) << '\n';
			break;
		} // eof case 3
		case 4:
		{
			boost::shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION
				, FALSE
				, GetCurrentProcessId())
				, CloseHandle);
			std::cout << "boost::shared_ptr with a user-defined deleter\n";
			break;
		} // eof case 4
		case 5:
		{
			auto p1 = boost::make_shared<int>(1);
			std::cout << "p1 is of type: " << typeid(p1).name() << '\n';
			auto p2 = boost::make_shared<int[]>(10);
			std::cout << "p2 is of type: " << typeid(p2).name() << '\n';
			break;
		} // eof case 5
		case 6:
		{
			break;
		} // eof case 6
		case 7:
		{
			break;
		} // eof case 7
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_2
//****************************************************************************
auto
chapter_2() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 2. Boost.PointerContainer\n";
		std::cout << "=================================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_3
//****************************************************************************
auto
chapter_3() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 3. Boost.ScopeExit\n";
		std::cout << "==========================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_4
//****************************************************************************
auto
chapter_4() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 4. Boost.Pool\n";
		std::cout << "=====================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_39
//****************************************************************************
//bool is_odd(int i) { return i % 2 == 1; }
//struct is_odd6_impl
//{
//	typedef bool result_type;
//	template<typename T>
//	bool operator()(T t) const { return t % 2 == 1; }
//};
//boost::phoenix::function<is_odd6_impl> is_odd6;
//BOOST_PHOENIX_ADAPT_FUNCTION(bool, is_odd7, is_odd, 1)
//auto
//chapter_39() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 39. Boost.Phoenix\n";
//		std::cout << "=========================\n";
//		std::cout << " 1) Example 1: Predicates as global function, lambda function, and Phoenix function\n";
//		std::cout << " 2) Example 2: Phoenix function versus lambda function\n";
//		std::cout << " 3) Example 3: Phoenix functions as deferred C++ code\n";
//		std::cout << " 4) Example 4: Explicit Phoenix types\n";
//		std::cout << " 5) Example 5: boost::phoenix::placeholders::arg1 and boost::phoenix::val()\n";
//		std::cout << " 6) Example 6: Creating your own Phoenix functions\n";
//		std::cout << " 7) Example 7: Transforming free-standing funtions into Phoenix functions\n";
//		std::cout << " 8) Example 8: Phoenix functions with boost::phoenix::bind()\n";
//		std::cout << " 9) Example 9: Arbitrarily complex Phoenix functions\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), is_odd) << '\n';
//			auto lambda = [](int i) { return i % 2 == 1; };
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), lambda) << '\n';
//			using namespace boost::phoenix::placeholders;
//			auto phoenix = arg1 % 2 == 1;
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), phoenix) << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			auto lambda = [](int i) { return i % 2 == 1; };
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), lambda) << '\n';
//			std::vector<long> v2;
//			v2.insert(v2.begin(), v.begin(), v.end());
//			using namespace boost::phoenix::placeholders;
//			auto phoenix = arg1 % 2 == 1;
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), phoenix) << '\n';
//			std::cout << "nof odd numbers: " << std::count_if(v2.begin(), v2.end(), phoenix) << '\n';
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix::placeholders;
//			auto phoenix = arg1 > 2 && arg1 % 2 == 1;
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), phoenix) << '\n';
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix;
//			using namespace boost::phoenix::placeholders;
//			auto phoenix = arg1 > val(2) && arg1 % val(2) == val(1);
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), phoenix) << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			using namespace boost::phoenix::placeholders;
//			std::cout << "first element in arg1...: " << arg1(1, 2, 3, 4, 5) << '\n';
//			auto v = boost::phoenix::val(2);
//			std::cout << "value holded in v.......: " << v() << '\n';
//			break;
//		} // eof case 5
//		case 6:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix::placeholders;
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), is_odd6(arg1)) << '\n';
//			break;
//		} // eof case 6
//		case 7:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix::placeholders;
//			std::cout << "nof odd numbers: " << std::count_if(v.begin(), v.end(), is_odd7(arg1)) << '\n';
//			break;
//		} // eof case 7 
//		case 8:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix::placeholders;
//			std::cout << "nof odd numbers: " 
//				<< std::count_if(v.begin(), v.end(), bind(is_odd, arg1)) 
//				<< '\n';
//			break;
//		} // eof case 8
//		case 9:
//		{
//			std::vector<int> v{ 1, 2, 3, 4, 5 };
//			using namespace boost::phoenix;
//			using namespace boost::phoenix::placeholders;
//			int count = 0;
//			std::for_each(v.begin(), v.end(),
//				if_(arg1 > 2 && arg1 % 2 == 1)
//				[
//					++ref(count)
//				]
//			);
//			std::cout << "nof odd numbers: " << count << '\n';
//			break;
//			break;
//		} // eof case 9
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_40
//****************************************************************************
//struct world
//{
//	void hello(std::ostream& os)
//	{
//		os << "Hello, world\n";
//	}
//};
//auto
//chapter_40() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 40. Boost.Function\n";
//		std::cout << "==========================\n";
//		std::cout << " 1) Example 1: Using boost::function\n";
//		std::cout << " 2) Example 2: boost::bad::function_call thrown if boost::function is empty\n";
//		std::cout << " 3) Example 3: Binding a class member function to boost::function\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::function<int(const char*)> f = std::atoi;
//			std::cout << "\"42\" converted to an int is...: " << f("42") << '\n';
//			f = std::strlen;
//			std::cout << "length of string \"42\" is......: " << f("42") << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			try
//			{
//				boost::function<int(const char*)> f;
//				f("");
//			}
//			catch (boost::bad_function_call & ex)
//			{
//				std::cerr << "exception thrown: " << ex.what() << '\n';
//			}
//			break;
//		} // eof case 2
//		case 3:
//		{
//			boost::function<void(world*, std::ostream&)> f = &world::hello;
//			world w;
//			f(&w, std::ref(std::cout));
//			break;
//		} // eof case 3
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_41
//****************************************************************************
//void print(int i)
//{
//	std::cout << "i has value: " << i << '\n';
//}
//class print2 : public std::binary_function<std::ostream*, int, void>
//{
//public:
//	void operator()(std::ostream* os, int i) const
//	{
//		*os << "i has value: " << i << '\n';
//	}
//};
//void print3(std::ostream* os, int i)
//{
//	*os << "i has value: " << i << '\n';
//}
//bool compare(int i, int j)
//{
//	return i > j;
//}
//auto
//chapter_41() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 41. Boost.Bind\n";
//		std::cout << "======================\n";
//		std::cout << " 1) Example 1: std::for_each() with a compatible function\n";
//		std::cout << " 2) Example 2: std::for_each() with std::bind1st()\n";
//		std::cout << " 3) Example 3: std::for_each() winth boost::bind()\n";
//		std::cout << " 4) Example 4: std::sort() with boost::bind()\n";
//		std::cout << " 5) Example 5: std::sort() with boost::bind() and changed order of placeholders\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::for_each(v.begin(), v.end(), print);
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::for_each(v.begin(), v.end(), std::bind1st(print2{}, &std::cout));
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::for_each(v.begin(), v.end(), boost::bind(print3, &std::cout, _1));
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::sort(v.begin(), v.end(), boost::bind(compare, _1, _2));
//			for (int i : v)
//				std::cout << "i has value: " << i << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::sort(v.begin(), v.end(), boost::bind(compare, _2, _1));
//			for (int i : v)
//				std::cout << "i has value: " << i << '\n';
//			break;
//		} // eof case 5
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_42
//****************************************************************************
//void print42(std::ostream& os, int i)
//{
//	os<< "i has value: " << i << std::endl;
//}
//auto
//chapter_42() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 42. Boost.Ref\n";
//		std::cout << "=====================\n";
//		std::cout << " 1) Example 1: Using boost::ref()\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::for_each(v.begin(), v.end()
//				, std::bind(print42, boost::ref(std::cout), std::placeholders::_1)
//			);
//			break;
//		} // eof case 1
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_43
//****************************************************************************
//auto
//chapter_43() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 43. Boost.Lambda\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: std::for_each() with a lambda function\n";
//		std::cout << " 2) Example 2: A lambda function with boost::lambda::if_then()\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::cout << "i has value:\n";
//			std::for_each(v.begin(), v.end()
//				, std::cout << boost::lambda::_1 << '\n'
//			);
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::vector<int> v{ 1, 3, 2 };
//			std::cout << "i has value:\n";
//			std::for_each(v.begin(), v.end()
//				, boost::lambda::if_then(boost::lambda::_1 > 1
//				, std::cout << boost::lambda::_1 << '\n')
//			);
//			break;
//		} // eof case 2
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_44
//****************************************************************************
//void wait(int seconds)
//{
//	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
//}
//void thread()
//{
//	std::cout << "thread is waiting\n";
//	for (int i = 0; i < 5; ++i)
//	{
//		wait(1);
//		std::cout << i << '\n';
//	}
//	std::cout << "thread has finished\n";
//}
//void thread3()
//{
//	std::cout << "thread is waiting\n";
//	try
//	{
//		for (int i = 0; i < 5; ++i)
//		{
//			wait(1);
//			std::cout << i << '\n';
//		}
//		std::cout << "thread has finished\n";
//	}
//	catch (boost::thread_interrupted&)
//	{
//		std::cout << "thread interrupted\n";
//	}
//}
//void thread4()
//{
//	boost::this_thread::disable_interruption no_interruption;
//	std::cout << "thread is waiting\n";
//	try
//	{
//		for (int i = 0; i < 5; ++i)
//		{
//			wait(1);
//			std::cout << i << '\n';
//		}
//		std::cout << "thread has finished\n";
//	}
//	catch (boost::thread_interrupted&)
//	{
//		std::cout << "thread interrupted\n";
//	}
//}
//boost::mutex mutex;
//void thread7()
//{
//	using boost::this_thread::get_id;
//	for (int i = 0; i < 5; ++i)
//	{
//		wait(1);
//		mutex.lock();
//		std::cout << "Thread " << get_id() << ": " << i << std::endl;
//		mutex.unlock();
//	}
//}
//void thread8()
//{
//	using boost::this_thread::get_id;
//	for (int i = 0; i < 5; ++i)
//	{
//		wait(1);
//		boost::lock_guard<boost::mutex> lock{ mutex };
//		std::cout << "Thread " << get_id() << ": " << i << std::endl;
//	}
//}
//boost::timed_mutex tmd_mutex;
//void thread19()
//{
//	using boost::this_thread::get_id;
//	for (int i = 0; i < 5; ++i)
//	{
//		wait(1);
//		boost::unique_lock<boost::timed_mutex> lock{ tmd_mutex };
//		std::cout << "Thread " << get_id() << ": " << i << std::endl;
//		boost::timed_mutex* m = lock.release();
//		m->unlock();
//	}
//}
//void thread29()
//{
//	using boost::this_thread::get_id;
//	for (int i = 0; i < 5; ++i)
//	{
//		wait(1);
//		boost::unique_lock<boost::timed_mutex> lock{ tmd_mutex
//			, boost::try_to_lock
//		};
//		if (lock.owns_lock() || lock.try_lock_for(boost::chrono::seconds{1}))
//			std::cout << "Thread " << get_id() << ": " << i << std::endl;
//	}
//}
//boost::shared_mutex shrd_mutex;
//std::vector<int> random_numbers;
//void fill()
//{
//	std::srand(static_cast<unsigned int>(std::time(0)));
//	for (int i = 0; i < 3; ++i)
//	{
//		boost::unique_lock<boost::shared_mutex> lock{ shrd_mutex };
//		random_numbers.push_back(std::rand());
//		lock.unlock();
//		wait(1);
//	}
//}
//void print()
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		wait(1);
//		boost::shared_lock<boost::shared_mutex> lock{ shrd_mutex };
//		std::cout << random_numbers.back() << '\n';
//	}
//}
//int sum = 0;
//void count()
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		wait(1);
//		boost::shared_lock<boost::shared_mutex> lock{ shrd_mutex };
//		sum += random_numbers.back();
//	}
//}
//boost::condition_variable_any cond;
//void fill11()
//{
//	std::srand(static_cast<unsigned int>(std::time(0)));
//	for (int i = 0; i < 3; ++i)
//	{
//		boost::unique_lock<boost::mutex> lock{ mutex };
//		random_numbers.push_back(std::rand());
//		cond.notify_all();
//		cond.wait(mutex);
//	}
//}
//void print11()
//{
//	std::size_t next_size = 1;
//	for (int i = 0; i < 3; ++i)
//	{
//		boost::unique_lock<boost::mutex> lock{ mutex };
//		while (random_numbers.size() != next_size)
//			cond.wait(mutex);
//		std::cout << "random_number: " << random_numbers.back() << '\n';
//		++next_size;
//		cond.notify_all();
//	}
//}
//void init()
//{
//	static bool done = false;
//	boost::lock_guard<boost::mutex> lock{ mutex };
//	if (!done)
//	{
//		done = true;
//		std::cout << "done" << '\n';
//	}
//}
//void thread12()
//{
//	init();
//	init();
//}
//void init13()
//{
//	static boost::thread_specific_ptr<bool> tls;
//	if (!tls.get())
//	{
//		tls.reset(new bool{ true });
//		boost::lock_guard<boost::mutex> lock{ mutex };
//		std::cout << "done" << '\n';
//	}
//}
//void thread13()
//{
//	init();
//	init();
//}
//void accumulate(boost::promise<int>& p)
//{
//	int sum = 0;
//	for (int i = 0; i < 5; ++i)
//		sum += i;
//	p.set_value(sum);
//}
//int accumulate15()
//{
//	int sum = 0;
//	for (int i = 0; i < 5; ++i)
//		sum += i;
//	return sum;
//}
//auto
//chapter_44() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 44. Boost.Thread\n";
//		std::cout << "========================\n";
//		std::cout << "    Creating and Managing Threads\n";
//		std::cout << " 1) Example 1: Using boost::thread\n";
//		std::cout << " 2) Example 2: Waiting for a thread with boost::scoped_thread\n";
//		std::cout << " 3) Example 3: An interruption point with boost::this_thread_sleep_for()\n";
//		std::cout << " 4) Example 4: Disabling interruption points with disable_interruption\n";
//		std::cout << " 5) Example 5: Setting thread attributes with boost::thread::attributes\n";
//		std::cout << " 6) Example 6: Detecting the thread ID and number of available processors\n";
//		std::cout << " .) Exercise 1: Use two threads to calculate a sum\n";
//		std::cout << " .) Exercise 2: Use as many threads as there are CPU Cores to calculate a sum\n";
//		std::cout << "    Synchronizing Threads\n";
//		std::cout << " 7) Example 7: Exclusive access with boost::mutex\n";
//		std::cout << " 8) Example 8: boost::lock::guard with guaranteed mutex release\n";
//		std::cout << " 9) Example 9: The versatile lock boost::unique_lock\n";
//		std::cout << "10) Example 10: Shared locks with boost::shared_lock\n";
//		std::cout << "11) Example 11: Condition variables with boost::condition_variable_any\n";
//		std::cout << "    Thread Local Storage\n";
//		std::cout << "12) Example 12: Synchronizing multiple threads with static variables\n";
//		std::cout << "13) Example 13: Synchronizing multiple threads with TLS\n";
//		std::cout << "    Futures and Promises\n";
//		std::cout << "14) Example 14: Using boost::future and boost::promise\n";
//		std::cout << "15) Example 15: Using boost::packaged_task\n";
//		std::cout << "16) Example 16: Using boost::async()\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::thread t{ thread };
//			t.join();
//			std::cout << "main thread passed join()\n";
//			break;
//		} // eof case 1
//		case 2:
//		{
//			boost::scoped_thread<> t{ boost::thread{thread} };
//			std::cout << "main thread passed thread execution\n";
//			break;
//		} // eof case 2
//		case 3:
//		{
//			boost::thread t{ thread3 };
//			wait(3);
//			t.interrupt();
//			t.join();
//			break;
//		} // eof case 3
//		case 4:
//		{
//			boost::thread t{ thread4 };
//			wait(3);
//			t.interrupt();
//			t.join();
//			break;
//		} // eof case 4
//		case 5:
//		{
//			boost::thread::attributes attrs;
//			attrs.set_stack_size(1024);
//			boost::thread t{ attrs, thread };
//			t.join();
//			break;
//		} // eof case 5
//		case 6:
//		{
//			std::cout << "thread ID.............: " << boost::this_thread::get_id() << '\n';
//			std::cout << "number of CPU Cores...: " << boost::thread::hardware_concurrency() << '\n';
//			break;
//		} // eof case 6
//		case 7:
//		{
//			boost::thread t1{ thread7 };
//			boost::thread t2{ thread7 };
//			t1.join();
//			t2.join();
//			break;
//		} // eof case 7
//		case 8:
//		{
//			boost::thread t1{ thread8 };
//			boost::thread t2{ thread8 };
//			t1.join();
//			t2.join();
//			break;
//		} // eof case 8
//		case 9:
//		{
//			boost::thread t1{ thread19 };
//			boost::thread t2{ thread29 };
//			t1.join();
//			t2.join();
//			break;
//		} // eof case 9
//		case 10:
//		{
//			boost::thread t1{ fill }, t2{ print }, t3{ count };
//			t1.join();
//			t2.join();
//			t3.join();
//			std::cout << "Sum: " << sum << '\n';
//			break;
//		} // eof case 10
//		case 11:
//		{
//			boost::thread t1{ fill11 };
//			boost::thread t2{ print11 };
//			t1.join();
//			t2.join();
//			break;
//		} // eof case 11
//		case 12:
//		{
//			boost::thread t[3];
//			for (int i = 0; i < 3; ++i)
//				t[i] = boost::thread{ thread12 };
//			for (int i = 0; i < 3; ++i)
//				t[i].join();
//			break;
//		} // eof case 12
//		case 13:
//		{
//			boost::thread t[3];
//			for (int i = 0; i < 3; ++i)
//				t[i] = boost::thread{ thread13 };
//			for (int i = 0; i < 3; ++i)
//				t[i].join();
//			break;
//		} // eof case 13
//		case 14:
//		{
//			boost::promise<int> p;
//			boost::future<int> f = p.get_future();
//			boost::thread t{ accumulate, std::ref(p) };
//			std::cout << "sum is: " << f.get() << '\n';
//			break;
//		} // eof case 14
//		case 15:
//		{
//			boost::packaged_task<int> task{ accumulate15 };
//			boost::future<int> f = task.get_future();
//			boost::thread t{ std::move(task) };
//			std::cout << "sum is: " << f.get() << '\n';
//			break;
//		} // eof case 15
//		case 16:
//		{
//			boost::future<int> f = boost::async(accumulate15);
//			std::cout << "sum is: " << f.get() << '\n';
//			break;
//		} // eof case 16
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_45
//****************************************************************************
//boost::atomic<int> a{ 0 };
//void thread()
//{
//	++a;
//}
//void thread3()
//{
//	a.fetch_add(1, boost::memory_order_seq_cst);
//}
//void thread4()
//{
//	a.fetch_add(1, boost::memory_order_relaxed);
//}
//int b = 0;
//void thread15()
//{
//	b = 1;
//	a.store(1, boost::memory_order_release);
//}
//void thread25()
//{
//	while (a.load(boost::memory_order_acquire) != 1)
//		;
//	std::cout << "b is: " << b << '\n';
//}
//auto
//chapter_45() -> void
//{
//	// further explanation of this stuff at:
//	// https://gcc.gnu.org/wiki/Atomic/GCCMM/AtomicSync
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 45. Boost.Atomic\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: Using boost::atomic\n";
//		std::cout << " 2) Example 2: boost::atomic with or without lock\n";
//		std::cout << " 3) Example 3: boost::atomic with boost::memory_order_seq_cst\n";
//		std::cout << " 4) Example 4: boost::atomic with boost::memory_order_relaxed\n";
//		std::cout << " 5) Example 5: boost::atomic with memory_order_release and memory_order_acquire\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::thread t1{ thread };
//			std::thread t2{ thread };
//			t1.join();
//			t2.join();
//			std::cout << "atomic<int> a is: " << a << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::cout.setf(std::ios::boolalpha);
//			boost::atomic<short> s;
//			std::cout << "s is lock free...: " << s.is_lock_free() << '\n';
//			boost::atomic<int> i;
//			std::cout << "i is lock free...: " << i.is_lock_free() << '\n';
//			boost::atomic<long> l;
//			std::cout << "l is lock free...: " << l.is_lock_free() << '\n';
//			// macro for lock free chacking on variables
//			// BOOST_ATOMIC_[INT | LONG | ...]_LOCK_FREE
//			// trivial classes define objects that can be copied with std::memcpy()
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::thread t1{ thread3 };
//			std::thread t2{ thread3 };
//			t1.join();
//			t2.join();
//			std::cout << "atomic<int> a is: " << a << '\n';
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::thread t1{ thread4 };
//			std::thread t2{ thread4 };
//			t1.join();
//			t2.join();
//			std::cout << "atomic<int> a is: " << a << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			std::thread t1{ thread15 };
//			std::thread t2{ thread25 };
//			t1.join();
//			t2.join();
//			break;
//		} // eof case 5
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_46
//****************************************************************************
//boost::lockfree::spsc_queue<int> q{ 100 };
//int sum = 0;
//void produce()
//{
//	for (int i = 1; i <= 100; ++i)
//		q.push(i);
//}
//void consume()
//{
//	int i;
//	while (q.pop(i))
//		sum += i;
//}
//using namespace boost::lockfree;
//spsc_queue<int, capacity<100>> q2;
//int sum2 = 0;
//void produce2()
//{
//	for (int i = 1; i <= 100; ++i)
//		q2.push(i);
//}
//void consume2()
//{
//	while (q2.consume_one([](int i) { sum2 += i; }))
//		;
//}
//boost::lockfree::queue<int> q3{ 100 };
//std::atomic<int> sum3{ 0 };
//void produce3()
//{
//	for (int i = 0; i <= 10000; ++i)
//		q3.push(i);
//}
//void consume3()
//{
//	int i;
//	while (q3.pop(i))
//		sum3 += i;
//}
//queue<int> q4{ 10000 };
//std::atomic<int> sum4{ 0 };
//void produce4()
//{
//	for (int i = 0; i <= 10000; ++i)
//		q4.push(i);
//}
//void consume4()
//{
//	int i;
//	while (q4.pop(i))
//		sum4 += i;
//}
//auto
//chapter_46() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 46. Boost.LockFree\n";
//		std::cout << "==========================\n";
//		std::cout << " 1) Example 1: Using boost::lockfree::spsc_queue\n";
//		std::cout << " 2) Example 2: boost::lockfree::spsc_queue with boost::lockfree::capacity\n";
//		std::cout << " 3) Example 3: boost::lockfree::queue with variable container size\n";
//		std::cout << " 4) Example 4: boost::lockfree::queue with constant container size\n";
//		std::cout << " 5) Exercise 5: implement 46.1 with std::queue instead of boost::lock::spsc_queue\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::thread t1{ produce };
//			std::thread t2{ consume };
//			t1.join();
//			t2.join();
//			consume();
//			std::cout << "sum is: " << sum << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::thread t1{ produce2 };
//			std::thread t2{ consume2 };
//			t1.join();
//			t2.join();
//			q2.consume_all([](int i) {sum2 += i; });
//			std::cout << "sum is: " << sum2 << '\n';
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::thread t1{ produce3 };
//			std::thread t2{ consume3 };
//			std::thread t3{ consume3 };
//			t1.join();
//			t2.join();
//			t3.join();
//			consume3();
//			std::cout << "sum is: " << sum3 << '\n';
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::thread t1{ produce4 };
//			std::thread t2{ consume4 };
//			std::thread t3{ consume4 };
//			t1.join();
//			t2.join();
//			t3.join();
//			consume4();
//			std::cout << "sum is: " << sum4 << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 5
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_47
//****************************************************************************
//auto
//chapter_47() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 47. Boost.MPI\n";
//		std::cout << "=====================\n";
//		std::cout << "    Development and Runtime Environment\n";
//		std::cout << "    Simple Data Exchange\n";
//		std::cout << " 1) Example 1: MPI environment and communicator\n";
//		std::cout << " 2) Example 2: Blocking functions to send and receive data\n";
//		std::cout << " 3) Example 3: Receiving data from an process\n";
//		std::cout << " 4) Example 4: Detecting the sender with boost::mpi::status\n";
//		std::cout << " 5) Example 5: Transmitting an array with send() and recv()\n";
//		std::cout << " 6) Example 6: Transmitting a string with send() and recv()\n";
//		std::cout << "    Asynchronous data exchange\n";
//		std::cout << " 7) Example 7: Receiving data asynchronously with irecv()\n";
//		std::cout << " 8) Example 8: Waiting for multiple asynchonous operations with wait_all()\n";
//		std::cout << "    Collective Data Exchange\n";
//		std::cout << " 9) Example 9: Receiving data from multiple processes with gather()\n";
//		std::cout << "10) Example 10: Collecting data from all processes with gather()\n";
//		std::cout << "11) Example 11: Scattering data with scatter() across all processes\n";
//		std::cout << "12) Example 12: Sending data to all processes with broadcast()\n";
//		std::cout << "13) Example 13: Gathering and analyzing data with reduce()\n";
//		std::cout << "14) Example 14: Gathering and analyzing data with all_reduce()\n";
//		std::cout << "    Communicators\n";
//		std::cout << "15) Example 15: Working with multiple communicators\n";
//		std::cout << "16) Example 16: Grouping processes with group\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 1
//		case 2:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 4
//		case 5:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 5
//		case 6:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 6
//		case 7:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 7
//		case 8:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 8
//		case 9:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 9
//		case 10:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 10
//		case 11:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 11
//		case 12:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 12
//		case 13:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 13
//		case 14:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 14
//		case 15:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 15
//		case 16:
//		{
//			std::cout << "TODO\n";
//			break;
//		} // eof case 16
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_48
////****************************************************************************
//auto
//chapter_48() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 48. Boost.TypeTraits\n";
//		std::cout << "============================\n";
//		std::cout << " 1) Example 1: Determining type categories\n";
//		std::cout << " 2) Example 2: boost::true_type and boost::false_type\n";
//		std::cout << " 3) Example 3: Checking type properties with Boost.TypeTraits\n";
//		std::cout << " 4) Example 4: Changing type properties with Boost.TypeTraits\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//			std::cout.setf(std::ios::boolalpha);
//			std::cout << "int is integral.....: ";
//			std::cout << boost::is_integral<int>::value << '\n';
//			std::cout << "int is float........: ";
//			std::cout << boost::is_float<int>::value << '\n';
//			std::cout << "int is arithmetic...: ";
//			std::cout << boost::is_arithmetic<int>::value << '\n';
//			std::cout << "int is reference....: ";
//			std::cout << boost::is_reference<int>::value << '\n';
//			break;
//		case 2:
//			std::cout.setf(std::ios::boolalpha);
//			std::cout << "int is integral, is same as.....: ";
//			std::cout << boost::is_same<boost::is_integral<int>::type, boost::true_type>::value << '\n';
//			std::cout << "int is float, is same as........: ";
//			std::cout << boost::is_same < boost::is_float<int>::type, boost::true_type>::value << '\n';
//			std::cout << "int is arithmetic, is same as...: ";
//			std::cout << boost::is_same < boost::is_arithmetic<int>::type, boost::true_type>::value << '\n';
//			std::cout << "int is reference, is same as....: ";
//			std::cout << boost::is_same < boost::is_reference<int>::type, boost::true_type>::value << '\n';
//			break;
//		case 3:
//			std::cout.setf(std::ios::boolalpha);
//			std::cout << "int has operator+............: ";
//			std::cout << boost::has_plus<int>::value << '\n';
//			std::cout << "int has operator++...........: ";
//			std::cout << boost::has_pre_increment<int>::value << '\n';
//			std::cout << "int has trivial copy.........: ";
//			std::cout << boost::has_trivial_copy<int>::value << '\n';
//			std::cout << "int has virtual destructor...: ";
//			std::cout << boost::has_virtual_destructor<int>::value << '\n';
//			break;
//		case 4:
//			std::cout.setf(std::ios::boolalpha);
//			std::cout << "add constant to int type...............: ";
//			std::cout << boost::is_const<boost::add_const<int>::type>::value << '\n';
//			std::cout << "remove pointer from int*...............: ";
//			std::cout << boost::is_same<boost::remove_pointer<int*>::type, int>::value << '\n';
//			std::cout << "turn int type into unsigned int type...: ";
//			std::cout << boost::is_same<boost::make_unsigned<int>::type, unsigned int>::value << '\n';
//			std::cout << "make int type a rvalue reference.......: ";
//			std::cout << boost::is_same<boost::add_rvalue_reference<int>::type, int&&>::value << '\n';
//			break;
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_49
////****************************************************************************
//template<typename T>
//typename boost::enable_if<std::is_same<T, int>, T>::type create()
//{
//	return 1;
//}
//template<typename T>
//typename boost::enable_if<std::is_same<T, std::string>, T>::type create()
//{
//	return "Boost";
//}
//template<typename T>
//void print(typename boost::enable_if<std::is_integral<T>, T>::type i)
//{
//	std::cout << "Integral.........: " << i << '\n';
//}
//template<typename T>
//void print(typename boost::enable_if<std::is_floating_point<T>, T>::type f)
//{
//	std::cout << "Floating point...: " << f << '\n';
//}
//template<class T>
//void
//print_has_post_increment()
//{
//	std::cout << typeid(T).name() 
//		<< ' '
//		<< ((boost::has_post_increment<T>::value) ? 
//			"has a post increment operator" :
//			"does not have a post increment operator")
//		<< '\n';
//}
//auto
//chapter_49() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 49. Boost.EnableIf\n";
//		std::cout << "==========================\n";
//		std::cout << " 1) Example 1: Overloading functions with boost::enable_if on their return value\n";
//		std::cout << " 2) Example 2: Specializing functions for a group of types with boost::enable_if\n";
//		std::cout << " 3) Exercise: function that prints whether a type has a 'post increment' operator\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//			std::cout << "This concept is using Substitution Failure Is Not An Error (SFINAE)\n";
//			std::cout << "Using the second version of the function create() ...: ";
//			std::cout << create<std::string>() << '\n';
//			break;
//		case 2:
//			print<short>(1);
//			print<long>(2);
//			print<double>(3.14);
//			break;
//		case 3:
//			print_has_post_increment<int>();
//			print_has_post_increment<long>();
//			print_has_post_increment<std::string>();
//			break;
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_50
////****************************************************************************
//struct struct_print
//{
//	template<typename T>
//	void operator()(const T& t) const
//	{
//		std::cout << std::boolalpha << t << '\n';
//	}
//};
//struct strct
//{
//	int i;
//	double d;
//};
//BOOST_FUSION_ADAPT_STRUCT(strct,
//	(int, i)
//	(double, d)
//)
//struct animal
//{
//	std::string name;
//	int legs;
//	bool has_tail;
//};
//struct important_numbers
//{
//	const float pi = boost::math::constants::pi<float>();
//	const double e = boost::math::constants::e<double>();
//};
//template<class T>
//void debug(const T& t)
//{
//	// TODO: Write member variables of t to standard output.
//}
//auto
//chapter_50() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 50. Boost.Fusion\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: Processing Fusion tuples\n";
//		std::cout << " 2) Example 2: Iterating over a tuple with boost::fusion::for_each()\n";
//		std::cout << " 3) Example 3: Filtering a Fusion container with boost::fusion::filter_view\n";
//		std::cout << " 4) Example 4: Accessing elements in Fusion containers with Iterators\n";
//		std::cout << " 5) Example 5: A heterogeneous vector with boost::fusion::vector\n";
//		std::cout << " 6) Example 6: A heterogeneous map with boost::fusion::map\n";
//		std::cout << " 7) Example 7: Fusion adapters for structures\n";
//		std::cout << " 8) Example 8: Fusion support for std::pair\n";
//		std::cout << " 9) Exercise: function that writes member variables of structures\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			typedef boost::fusion::tuple<int, std::string, bool, double> tuple_type;
//			tuple_type t{ 10, "Boost", true, 3.14 };
//			std::cout << boost::fusion::get<0>(t) 
//				<< ' '
//				<< boost::fusion::get<1>(t)
//				<< ' '
//				<< std::boolalpha
//				<< boost::fusion::get<2>(t)
//				<< ' '
//				<< boost::fusion::get<3>(t)
//				<< '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			typedef boost::fusion::tuple<int, std::string, bool, double> tuple_type;
//			tuple_type t{ 10, "Boost", true, 3.14 };
//			boost::fusion::for_each(t, struct_print{});
//			break;
//		} // eof case 2
//		case 3:
//		{
//			typedef boost::fusion::tuple<int, std::string, bool, double> tuple_type;
//			tuple_type t{ 10, "Boost", true, 3.14 };
//			boost::fusion::filter_view<tuple_type, boost::is_integral<boost::mpl::arg<1>>> v{ t };
//			boost::fusion::for_each(v, struct_print{});
//			break;
//		} // eof case 3
//		case 4:
//		{
//			typedef boost::fusion::tuple<int, std::string, bool, double> tuple_type;
//			tuple_type t{ 10, "Boost", true, 3.14 };
//			auto it = begin(t);
//			std::cout << *it << '\n';
//			auto it2 = boost::fusion::advance<boost::mpl::int_<2>>(it);
//			std::cout << std::boolalpha << *it2 << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			typedef boost::fusion::vector<int, std::string, bool, double> vector_type;
//			vector_type v{ 10, "Boost", true, 3.14 };
//			// added for clarity
//			std::cout << "vector v contains:\n";
//			boost::fusion::for_each(v, struct_print{});
//
//			std::cout << "first element in v...: " << boost::fusion::at<boost::mpl::int_<0>>(v) << '\n';
//			auto v2 = boost::fusion::push_back(v, 'X');
//			std::cout << "size of vector v.....: " << boost::fusion::size(v) << '\n';
//			std::cout << "size of vector v2....: " << boost::fusion::size(v2) << '\n';
//			std::cout << "last element in v2...: " << boost::fusion::back(v2) << '\n';
//			break;
//		} // eof case 5
//		case 6:
//		{
//			auto m = boost::fusion::make_map<int, std::string, bool, double>(
//				"Boost", 10, 3.14, true);
//			if (boost::fusion::has_key<std::string>(m))
//				std::cout << "value at std::string key type...: " << boost::fusion::at_key<std::string>(m) << '\n';
//			// added for clarity
//			if (boost::fusion::has_key<double>(m))
//				// value type is bool, by the way
//				std::cout << "value at double key type........: " << std::boolalpha << boost::fusion::at_key<double>(m) << '\n';
//
//			auto m2 = boost::fusion::erase_key<std::string>(m);
//			auto m3 = boost::fusion::push_back(m2, boost::fusion::make_pair<float>('X'));
//			std::cout << "m3 has std::string key type.....: " << std::boolalpha << boost::fusion::has_key<std::string>(m3) << '\n';
//			break;
//		} // eof case 6
//		case 7:
//		{
//			strct s = { 10, 3.14 };
//			std::cout << "first element in struct s...: " << boost::fusion::at<boost::mpl::int_<0>>(s) << '\n';
//			std::cout << "last element in struct s....: " << boost::fusion::back(s) << '\n';
//			break;
//		} // eof case 7
//		case 8:
//		{
//			auto p = std::make_pair(10, 3.14);
//			std::cout << "element at 0, in pair...: " << boost::fusion::at<boost::mpl::int_<0>>(p) << '\n';
//			std::cout << "last element, in pair...: " << boost::fusion::back(p) << '\n';
//			break;
//		} // eof case 8
//		case 9:
//		{
//			animal a{ "cat", 4, true };
//			debug(a);
//			important_numbers in;
//			debug(in);
//			std::cout << "TODO\n";
//			break;
//		} // eof case 9
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_51
////****************************************************************************
//void cooperative(boost::coroutines::coroutine<void>::push_type& sink)
//{
//	std::cout << "Hello";
//	sink();
//	std::cout << "world";
//}
//void cooperative2(boost::coroutines::coroutine<int>::push_type& sink
//	, int i
//)
//{
//	int j = i;
//	sink(++j);
//	sink(++j);
//	std::cout << "end\n";
//}
//void cooperative3(boost::coroutines::coroutine<std::tuple<int, std::string>>::pull_type& source)
//{
//	auto args = source.get();
//	std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';
//	source();
//	args = source.get();
//	std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';
//}
//void cooperative4(boost::coroutines::coroutine<void>::push_type& sink)
//{
//	sink();
//	throw std::runtime_error("error");
//}
//auto
//chapter_51() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 51. Boost.Coroutine\n";
//		std::cout << "===========================\n";
//		std::cout << " 1) Example 1: Using coroutines\n";
//		std::cout << " 2) Example 2: Returning a value from a coroutine\n";
//		std::cout << " 3) Example 3: Passing two values to a coroutine\n";
//		std::cout << " 4) Example 4: Coroutines and exceptions\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::coroutines::coroutine<void>::pull_type source{ cooperative };
//			std::cout << ", ";
//			source();
//			std::cout << "!\n";
//			break;
//		} // eof case 1
//		case 2:
//		{
//			using std::placeholders::_1;
//			boost::coroutines::coroutine<int>::pull_type source{ 
//				std::bind(cooperative2, _1, 0)
//			};
//			std::cout << "from coroutine: " << source.get() << '\n';
//			source();
//			std::cout << "from coroutine: " << source.get() << '\n';
//			source();
//			break;
//		} // eof case 2
//		case 3:
//		{
//			boost::coroutines::coroutine<std::tuple<int, std::string>>::push_type sink{ cooperative3 };
//			sink(std::make_tuple(0, "aaa"));
//			sink(std::make_tuple(1, "bbb"));
//			std::cout << "end\n";
//			break;
//		} // eof case 3
//		case 4:
//		{
//			boost::coroutines::coroutine<void>::pull_type source{ cooperative4 };
//			try
//			{
//				source();
//			}
//			catch (const std::runtime_error& e)
//			{
//				std::cerr << "error from coroutine: " << e.what() << '\n';
//			}
//			break;
//		} // eof case 4
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_52
////****************************************************************************
//auto
//chapter_52() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 52. Boost.Foreach\n";
//		std::cout << "=========================\n";
//		std::cout << " 1) Example 1: Using BOOST_FOREACH and BOOST_REVERSE_FOREACH\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::array<int, 4> a{ {0, 1, 2, 3} };
//			BOOST_FOREACH(int& i, a)
//				i *= i;
//			std::cout << "the array holds, in reverse order:\n";
//			BOOST_REVERSE_FOREACH(int i, a)
//				std::cout << i << '\n';
//			break;
//		} // eof case 1
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_53
////****************************************************************************
//BOOST_PARAMETER_NAME(a)
//BOOST_PARAMETER_NAME(b)
//BOOST_PARAMETER_NAME(c)
//BOOST_PARAMETER_NAME(d)
//BOOST_PARAMETER_NAME(e)
//BOOST_PARAMETER_FUNCTION((void)
//	, complicated
//	, tag
//	, (required
//		(a, (int))
//		(b, (char))
//		(c, (double))
//		(d, (std::string))
//		(e, *))
//)
//{
//	std::cout.setf(std::ios::boolalpha);
//	std::cout << "value given by parameter a: " << a << '\n';
//	std::cout << "value given by parameter b: " << b << '\n';
//	std::cout << "value given by parameter c: " << c << '\n';
//	std::cout << "value given by parameter d: " << d << '\n';
//	std::cout << "value given by parameter e: " << e << '\n';
//}
//BOOST_PARAMETER_FUNCTION((void)
//	, complicated2
//	, tag
//	, (required
//		(a, (int))
//		(b, (char)))
//	  (optional
//		(c, (double), 3.14)
//		(d, (std::string), "Boost")
//		(e, *, true))
//)
//{
//	std::cout.setf(std::ios::boolalpha);
//	std::cout << "value given by parameter a: " << a << '\n';
//	std::cout << "value given by parameter b: " << b << '\n';
//	std::cout << "value given by parameter c: " << c << '\n';
//	std::cout << "value given by parameter d: " << d << '\n';
//	std::cout << "value given by parameter e: " << e << '\n';
//}
//BOOST_PARAMETER_TEMPLATE_KEYWORD(integral_type);
//BOOST_PARAMETER_TEMPLATE_KEYWORD(floating_point_type);
//BOOST_PARAMETER_TEMPLATE_KEYWORD(any_type);
//using namespace boost::parameter;
//using boost::mpl::placeholders::_;
//typedef parameters<boost::parameter::required<tag::integral_type, std::is_integral<_>>
//	, boost::parameter::required<tag::floating_point_type, std::is_floating_point<_>>
//	, boost::parameter::required<tag::any_type, std::is_object<_>>
//> complicated_signature;
//template <class A, class B, class C>
//class complicated3
//{
//public:
//	typedef typename complicated_signature::bind<A, B, C>::type args;
//	typedef typename value_type<args, tag::integral_type>::type integral_type;
//	typedef typename value_type<args, tag::floating_point_type>::type 
//		floating_point_type;
//	typedef typename value_type<args, tag::any_type>::type any_type;
//};
////****************************************************************************
////*                     My_OpenFile
////****************************************************************************
//// for intermezzo
//class My_File;
//class My_OpenFile
//{
//	friend class My_File;
//	std::string filename_;
//	bool readonly_;				// defaults to false (for example)
//	bool createIfNotExist_;		// defaults to false (for example)
//	// ...
//	unsigned blockSize_;		// defaults to 4096 (for example)
//	// ...
//	bool appendWriting_;
//	bool unbuffered_;
//	bool exclusiveAccess_;
//public:
//	inline My_OpenFile(const std::string& filename)
//		: filename_			(filename)
//		, readonly_			(false)
//		, createIfNotExist_	(false)
//		, blockSize_		(4096u)
//		, appendWriting_	(false)
//		, unbuffered_		(true)
//		, exclusiveAccess_	(true)
//	{}
//	inline My_OpenFile& readonly()
//	{
//		readonly_ = true;
//		return *this;
//	}
//	inline My_OpenFile& readwrite()
//	{
//		readonly_ = false;
//		return *this;
//	}
//	inline My_OpenFile& createIfNotExist()
//	{
//		createIfNotExist_ = true;
//		return *this;
//	}
//	inline My_OpenFile& blockSize(unsigned nbytes)
//	{
//		blockSize_ = nbytes;
//		return *this;
//	}
//	inline My_OpenFile& appendWriting()
//	{
//		appendWriting_ = true;
//		return *this;
//	}
//	inline My_OpenFile& unbuffered()
//	{
//		unbuffered_ = true;
//		return *this;
//	}
//	inline My_OpenFile& exclusiveAccess()
//	{
//		exclusiveAccess_ = true;
//		return *this;
//	}
//};
////****************************************************************************
////*                     My_File
////****************************************************************************
//// for intermezzo
//class My_File
//{
//public:
//	My_File(const My_OpenFile& params)
//	{
//		std::cout << "filename..............: " << params.filename_ << '\n';
//		std::cout.setf(std::ios::boolalpha);
//		std::cout << "readonly..............: " << params.readonly_ << '\n';
//		std::cout << "create if not exist...: " << params.createIfNotExist_ << '\n';
//		std::cout << "blocksize.............: " << params.blockSize_ << '\n';
//		std::cout << "append writing........: " << params.appendWriting_ << '\n';
//		std::cout << "unbuffered............: " << params.unbuffered_ << '\n';
//		std::cout << "exclusive access......: " << params.exclusiveAccess_ << '\n';
//	}
//};
//auto
//chapter_53() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 53. Boost.Parameter\n";
//		std::cout << "===========================\n";
//		std::cout << " 1) Example 1: Function parameters as key/value pairs\n";
//		std::cout << " 2) Example 2: Optional function parameters\n";
//		std::cout << " 3) Example 3: Template parameters as key/value pairs\n";
//		std::cout << " 4) Example 4: Optional template parameters\n";
//		std::cout << "99) Intermezzo: The named parameter idiom\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//			complicated(_c = 3.14
//				, _a = 1
//				, _d = "Boost"
//				, _b = 'B'
//				, _e = true
//			);
//			std::cout << "In C++ parameters for a function can be passed as key/value pairs\n"
//				<< "with the named parameter idiom\n"
//				<< "see: http://www.parashift.com/c++-faq/named-parameter-idiom.html \n"
//				<< "(it uses method chaining to set the parameters)\n";
//			break;
//		case 2:
//			complicated2(_b = 'B'
//				, _a = 1
//			);
//			break;
//		case 3:
//			typedef complicated3<floating_point_type<double>,
//				integral_type<int>, any_type<bool>> c;
//			std::cout << "c has integral type.........: " << typeid(c::integral_type).name() << '\n';
//			std::cout << "c has floating point type...: " << typeid(c::floating_point_type).name() << '\n';
//			std::cout << "c has any type..............: " << typeid(c::any_type).name() << '\n';
//			break;
//		case 4:
//			std::cout << "TODO\n";
//			break;
//		case 99:
//		{
//			// this intermezzo handles the Named Parameter Idiom
//			std::cout << "this intermezzo handles the Named Parameter Idiom\n";
//			My_File f = My_OpenFile("foo.txt")
//				.readonly()
//				.createIfNotExist()
//				.appendWriting()
//				.blockSize(1024)
//				.unbuffered()
//				.exclusiveAccess();
//			break;
//		} // eof case 99
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_54
////****************************************************************************
//struct base1 { virtual ~base1() = default; };
//struct base2 { virtual ~base2() = default; };
//struct derived : public base1, public base2 {};
//void downcast(base1* b1)
//{
//	std::cout << "downcast()\n";
//	derived* d = dynamic_cast<derived*>(b1);
//}
//void crosscast(base1* b1)
//{
//	std::cout << "crosscast()\n";
//	base2* b2 = dynamic_cast<base2*>(b1);
//}
//void downcast2(base1* b1)
//{
//	std::cout << "polymorphic_downcast()\n";
//	derived* d = boost::polymorphic_downcast<derived*>(b1);
//}
//void crosscast2(base1* b1)
//{
//	std::cout << "polymorphic_cast()\n";
//	base2* b2 = boost::polymorphic_cast<base2*>(b1);
//}
//auto
//chapter_54() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 54. Boost.Conversion\n";
//		std::cout << "============================\n";
//		std::cout << " 1) Example 1: Down and cross casts with dynamic_cast\n";
//		std::cout << " 2) Example 2: Down and cross casts with polymorphic_downcast and polymorphic_cast\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			derived* d = new derived;
//			downcast(d);
//			base1* b1 = new derived;
//			crosscast(b1);
//			break;
//		} // eof case 1
//		case 2:
//		{
//			derived* d = new derived;
//			downcast2(d);
//			base1* b1 = new derived;
//			crosscast2(b1);
//			break;
//
//		} // eof case 2
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_55
////****************************************************************************
//void fail(boost::system::error_code& ec)
//{
//	ec = boost::system::errc::make_error_code(
//		boost::system::errc::not_supported);
//}
//void fail5()
//{
//	throw boost::system::system_error{
//		boost::system::errc::make_error_code(boost::system::errc::not_supported) };
//}
//class application_category :
//	public boost::system::error_category
//{
//public:
//	const char* name() const noexcept { return "my app"; }
//	std::string message(int ev) const { return "error message"; }
//};
//application_category cat;
//auto
//chapter_55() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 55. Boost.System\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: Using boost::system::error_code\n";
//		std::cout << " 2) Example 2: Using boost::system::error_category\n";
//		std::cout << " 3) Example 3: Creating error categories\n";
//		std::cout << " 4) Example 4: Using boost::system::error_condition\n";
//		std::cout << " 5) Example 5: Using boost::system::system_error\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::system::error_code ec;
//			fail(ec);
//			std::cout << "value: " << ec.value() << " message: " << ec.message() << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			boost::system::error_code ec;
//			fail(ec);
//			std::cout << "value......: " << ec.value() << '\n';
//			std::cout << "category...: " << ec.category().name() << '\n';
//			break;
//		} // eof case 2
//		case 3:
//		{
//			boost::system::error_code ec{ 129, cat };
//			std::cout << "value......: " << ec.value() << '\n';
//			std::cout << "category...: " << ec.category().name() << '\n';
//			std::cout << "message....: " << ec.message() << '\n';
//			break;
//		} // eof case 3
//		case 4:
//		{
//			boost::system::error_code ec;
//			fail(ec);
//			boost::system::error_condition ecnd = ec.default_error_condition();
//			std::cout << "ecnd value......: " << ecnd.value() << '\n';
//			std::cout << "ecnd category...: " << ecnd.category().name() << '\n';
//			break;
//		} // eof case 4
//		case 5:
//		{
//			try
//			{
//				fail5();
//			}
//			catch (boost::system::system_error & e)
//			{
//				boost::system::error_code ec = e.code();
//				std::cerr << "ec value......: " << ec.value() << '\n';
//				std::cerr << "ec category...: " << ec.category().name() << '\n';
//			}
//			break;
//		} // eof case 5
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_56
////****************************************************************************
//typedef boost::error_info<struct tag_errmsg, std::string> errmsg_info;
//// in example 2 and 3, deriving from boost::exception is left out
//struct allocation_failed : public boost::exception, public std::exception
//{
//	const char* what() const noexcept
//	{
//		return "allocation failed";
//	}
//};
//char* allocate_memory(std::size_t size)
//{
//	char* c = new (std::nothrow) char[size];
//	if (!c)
//		throw allocation_failed{};
//	return c;
//}
//char* allocate_memory2(std::size_t size)
//{
//	char* c = new (std::nothrow) char[size];
//	if (!c)
//		BOOST_THROW_EXCEPTION(allocation_failed{});
//	return c;
//}
//// avoid error when using the function max() 
//// error C2589: '(': illegal token on right side of '::'
//#undef max
//char* write_lots_of_zeros(int i = 1)
//{
//	try
//	{
//		char* c = nullptr;
//		if (i == 1)
//			c = allocate_memory(std::numeric_limits<std::size_t>::max());
//		if (i == 2)
//			c = allocate_memory2(std::numeric_limits<std::size_t>::max());
//		std::fill_n(c, std::numeric_limits<std::size_t>::max(), 0);
//		return c;
//	}
//	catch (boost::exception & e)
//	{
//		e << errmsg_info{ "writing lost of zeros failed" };
//		throw;
//	}
//}
//auto
//chapter_56() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 56. Boost.Exception\n";
//		std::cout << "===========================\n";
//		std::cout << " 1) Example 1: Using boost::exception\n";
//		std::cout << " 2) Example 2: More data with BOOST_THROW_EXCEPTION\n";
//		std::cout << " 3) Example 3: Selectivly accessing data with boost::get_error_info()\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//			try
//			{
//				char* c = write_lots_of_zeros();
//				delete[] c;
//			}
//			catch (boost::exception & e)
//			{
//				std::cerr << boost::diagnostic_information(e);
//			}
//			break;
//		case 2:
//			try
//			{
//				char* c = write_lots_of_zeros(2);
//				delete[] c;
//			}
//			catch (boost::exception & e)
//			{
//				std::cerr << boost::diagnostic_information(e);
//			}
//			break;
//		case 3:
//			try
//			{
//				char* c = write_lots_of_zeros(2);
//				delete[] c;
//			}
//			catch (boost::exception & e)
//			{
//				std::cerr << *boost::get_error_info<errmsg_info>(e) << '\n';
//			}
//			break;
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_57
////****************************************************************************
//auto
//chapter_57() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 57. Boost.Integer\n";
//		std::cout << "=========================\n";
//		std::cout << " 1) Example 1: Types for integers with number of bits\n";
//		std::cout << " 2) Example 2: More specialized types for integers\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::int8_t i8 = 1;
//			std::cout << "int8_t number of byte...........: " << sizeof(i8) << " (byte)\n";
//#ifndef BOOST_NO_INT64_T
//			boost::uint64_t ui64 = 1;
//			std::cout << "uint64_t number of byte.........: " << sizeof(ui64) << " (byte)\n";
//#endif
//			boost::int_least8_t il8 = 1;
//			std::cout << "int_least8_t number of byte.....: " << sizeof(il8) << " (byte)\n";
//			boost::uint_least32_t uil32 = 1;
//			std::cout << "uint_least32_t number of byte...: " << sizeof(uil32) << " (byte)\n";
//			boost::int_fast8_t if8 = 1;
//			std::cout << "int_fast8_t number of byte......: " << sizeof(if8) << " (byte)\n";
//			boost::uint_fast16_t uif16 = 1;
//			std::cout << "uint_fast16_t number of byte....: " << sizeof(uif16) << " (byte)\n";
//			break;
//		} // eof case 1
//		case 2:
//		{
//			boost::intmax_t imax = 1;
//			std::cout << "intmax_t number of byte...: " << sizeof(imax) << " (byte)\n";
//			std::cout << "UINT8_C number of byte....: " << sizeof(UINT8_C(1)) << " (byte)\n";
//#ifndef BOOST_NO_INT64_T
//			std::cout << "INT64_C number of byte....: " << sizeof(INT64_C(1)) << " (byte)\n";
//#endif
//			break;
//		} // eof case 2
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_58
////****************************************************************************
//auto
//chapter_58() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 58. Boost.Accumulators\n";
//		std::cout << "==============================\n";
//		std::cout << " 1) Example 1: Counting with boost::accumulators::tag::count\n";
//		std::cout << " 2) Example 2: Using mean and variance\n";
//		std::cout << " 3) Example 3: Calculating the weighted variance\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			boost::accumulators::accumulator_set<int,
//				boost::accumulators::features<boost::accumulators::tag::count>> acc;
//			acc(4);
//			acc(-6);
//			acc(9);
//			std::cout << "number of values passed into accumulator: "
//				<< boost::accumulators::count(acc) << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			boost::accumulators::accumulator_set<double
//				, boost::accumulators::features<
//					  boost::accumulators::tag::mean
//					, boost::accumulators::tag::variance>> acc;
//			acc(8);
//			acc(9);
//			acc(10);
//			acc(11);
//			acc(12);
//			std::cout << "the mean is.......: "
//				<< boost::accumulators::mean(acc) << '\n';
//			std::cout << "the variance is...: "
//				<< boost::accumulators::variance(acc) << '\n';
//			break;
//		} // eof case 2
//		case 3:
//		{
//			boost::accumulators::accumulator_set<double
//				, boost::accumulators::features<
//					  boost::accumulators::tag::mean
//					, boost::accumulators::tag::variance>
//				, int> acc;
//			acc(8, boost::accumulators::weight = 1);
//			acc(9, boost::accumulators::weight = 1);
//			acc(10, boost::accumulators::weight = 4);
//			acc(11, boost::accumulators::weight = 1);
//			acc(12, boost::accumulators::weight = 1);
//			std::cout << "the mean is.......: "
//				<< boost::accumulators::mean(acc) << '\n';
//			std::cout << "the variance is...: "
//				<< boost::accumulators::variance(acc) << '\n';
//			break;
//		} // eof case 3
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_59
////****************************************************************************
//auto
//chapter_59() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 59. Boost.MinMax\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: Using boost::minmax()\n";
//		std::cout << " 2) Example 2: Using boost::minmax_element()\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			int i = 2;
//			int j = 1;
//			boost::tuples::tuple<const int&, const int&> t = boost::minmax(i, j);
//			std::cout << "min is...: " << t.get<0>() << '\n';
//			std::cout << "max is...: " << t.get<1>() << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			typedef std::array<int, 4> array;
//			array a{ {2, 3, 0, 1} };
//			std::pair<array::iterator, array::iterator> p =
//				boost::minmax_element(a.begin(), a.end());
//			std::cout << "min is...: " << *p.first << '\n';
//			std::cout << "max is...: " << *p.second << '\n';
//			break;
//		} // eof case 2
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_60
////****************************************************************************
//auto
//chapter_60() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 60. Boost.Random\n";
//		std::cout << "========================\n";
//		std::cout << " 1) Example 1: Pseudo-random numbers with boost::random::mt19937\n";
//		std::cout << " 2) Example 2: Real random numbers with boost::random::random_device\n";
//		std::cout << " 3) Example 3: The random numbers 0 and 1 with bernoulli_distribution\n";
//		std::cout << " 4) Example 4: Random numbers between 1 and 100 with uniform_distribution\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			std::time_t now = std::time(0);
//			boost::random::mt19937 gen{ static_cast<std::uint32_t>(now) };
//			std::cout << "generated random number: " << gen() << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			boost::random::random_device gen;
//			std::cout << "generated random number: " << gen() << '\n';
//			break;
//		} // eof case 2
//		case 3:
//		{
//			std::time_t now = std::time(0);
//			boost::random::mt19937 gen{ static_cast<std::uint32_t>(now) };
//			boost::random::bernoulli_distribution<> dist;
//			std::cout << "generated random number: " << dist(gen) << '\n';
//			break;
//		} // eof case 3
//		case 4:
//		{
//			std::time_t now = std::time(0);
//			boost::random::mt19937 gen{ static_cast<std::uint32_t>(now) };
//			boost::random::uniform_int_distribution<> dist{ 1, 100 };
//			std::cout << "generated random number: " << dist(gen) << '\n';
//			break;
//		} // eof case 4
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_61
////****************************************************************************
//auto
//chapter_61() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 61. Boost.NumericConversion\n";
//		std::cout << "===================================\n";
//		std::cout << " 1) Example 1: Implicit conversion from int to short\n";
//		std::cout << " 2) Example 2: Overflow detection with boost::numeric_cast\n";
//		std::cout << " 3) Example 3: Overflow detection for negative numbers\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			int i = 0x10000;
//			short s = i;
//			std::cout << "int converted to short (errornous): " << s << '\n';
//			break;
//		} // eof case 1
//		case 2:
//		{
//			try
//			{
//				int i = 0x10000;
//				short s = boost::numeric_cast<short>(i);
//				std::cout << "int converted to short: " << s << '\n';
//			}
//			catch (boost::numeric::bad_numeric_cast & e)
//			{
//				std::cout << "catched exception: " << e.what() << '\n';
//			}
//			break;
//		} // eof case 2
//		case 3:
//		{
//			try
//			{
//				int i = -0x10000;
//				short s = boost::numeric_cast<short>(i);
//				std::cout << "int converted to short: " << s << '\n';
//			}
//			catch (boost::numeric::negative_overflow & e)
//			{
//				std::cout << "catched exception: " << e.what() << '\n';
//			}
//			break;
//		} // eof case 3
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
////****************************************************************************
////*                     chapter_62
////****************************************************************************
//bool only_warnings(const boost::log::attribute_value_set& set)
//{
//	return set["Severity"].extract<int>() > 0;
//}
//void severity_and_message(const boost::log::record_view& view
//	, boost::log::formatting_ostream& os
//)
//{
//	os << view.attribute_values()["Severity"].extract<int>() << ": "
//		<< view.attribute_values()["Message"].extract<std::string>();
//}
//BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
//BOOST_LOG_ATTRIBUTE_KEYWORD(counter, "LineCounter", int)
//BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "Timestamp", 
//	boost::posix_time::ptime)
//BOOST_LOG_ATTRIBUTE_KEYWORD(channel, "Channel", std::string)
//struct handler
//{
//	void operator()(const boost::log::runtime_error& ex) const
//	{
//		std::cerr << "boost::log::runtime_error: " << ex.what() << '\n';
//	}
//	void operator()(const std::exception& ex) const
//	{
//		std::cerr << "std::exception: " << ex.what() << '\n';
//	}
//};
//BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(lg10, boost::log::sources::wlogger_mt)
//auto
//chapter_62() -> void
//{
//	bool bProceed = true;
//	unsigned int iChar = 0;
//	while (bProceed)
//	{
//		std::cout << "Chapter 62. Boost.Log\n";
//		std::cout << "=====================\n";
//		std::cout << " 1) Example 1: Back-end, front-end, core, and logger\n";
//		std::cout << " 2) Example 2: boost::sources::severity_logger with a filter\n";
//		std::cout << " 3) Example 3: Changing the format of a log entry with set_formatter()\n";
//		std::cout << " 4) Example 4: Filtering log entries and formatting them with lambda functions\n";
//		std::cout << " 5) Example 5: Defining keywords for attributes\n";
//		std::cout << " 6) Example 6: Defining attributes\n";
//		std::cout << " 7) Example 7: Helper functions for filters and formats\n";
//		std::cout << " 8) Example 8: Several loggers, front-ends, and back-ends\n";
//		std::cout << " 9) Example 9: Handling exceptions centrally\n";
//		std::cout << "10) Example 10: A macro to define a global logger\n";
//		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
//		std::cin >> iChar;
//		// get rid of the newline character, to ensure the buffer sanity
//		std::cin.get();
//		switch (iChar)
//		{
//		case 1:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			// it's not going to work
//			// <boost/utility/empty_deleter.hpp>
//			// will not be found
//			//boost::shared_ptr<std::ostream> stream{ &std::clog,
//			//	boost::empty_deleter{} };
//			// changed, according to a hint in the comment
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::sources::logger lg;
//			BOOST_LOG(lg) << "note";
//			sink->flush();
//			break;
//		} // eof case 1
//		case 2:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_filter(&only_warnings);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::sources::logger lg;
//			// it will mess up the stream buffer
//			BOOST_LOG(lg) << "note";
//			BOOST_LOG_SEV(lg, 0) << "another note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			sink->flush();
//			break;
//		} // eof case 2
//		case 3:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_formatter(&severity_and_message);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::sources::severity_logger<int> lg;
//			BOOST_LOG_SEV(lg, 0) << "note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			sink->flush();
//			break;
//		} // eof case 3
//		case 4:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_filter(boost::log::expressions::attr<int>("Severity") > 0);
//			sink->set_formatter(boost::log::expressions::stream
//				<< boost::log::expressions::attr<int>("Severity")
//				<< ": "
//				<< boost::log::expressions::smessage);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::sources::severity_logger<int> lg;
//			BOOST_LOG_SEV(lg, 0) << "note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			BOOST_LOG_SEV(lg, 2) << "error";
//			sink->flush();
//			break;
//		} // eof case 4
//		case 5:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_filter(severity > 0);
//			sink->set_formatter(boost::log::expressions::stream
//				<< severity
//				<< ": "
//				<< boost::log::expressions::smessage);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::sources::severity_logger<int> lg;
//			BOOST_LOG_SEV(lg, 0) << "note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			BOOST_LOG_SEV(lg, 2) << "error";
//			sink->flush();
//			break;
//		} // eof case 5
//		case 6:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_filter(severity > 0);
//			sink->set_formatter(boost::log::expressions::stream
//				<< counter
//				<< " - "
//				<< severity
//				<< ": "
//				<< boost::log::expressions::smessage
//				<< " ("
//				<< timestamp
//				<< ")"
//			);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::core::get()->add_global_attribute("LineCounter"
//				, boost::log::attributes::counter<int>{});
//			boost::log::sources::severity_logger<int> lg;
//			BOOST_LOG_SEV(lg, 0) << "note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			{
//				BOOST_LOG_SCOPED_LOGGER_ATTR(lg, "Timestamp"
//					, boost::log::attributes::local_clock())
//				BOOST_LOG_SEV(lg, 2) << "error";
//			}
//			
//			BOOST_LOG_SEV(lg, 2) << "another error";
//			sink->flush();
//			break;
//		} // eof case 6
//		case 7:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			sink->set_filter(boost::log::expressions::is_in_range(severity, 1, 3));
//			sink->set_formatter(boost::log::expressions::stream
//				<< std::setw(5)
//				<< counter
//				<< " - "
//				<< severity
//				<< ": "
//				<< boost::log::expressions::smessage
//				<< " ("
//				<< boost::log::expressions::format_date_time(timestamp, "%H:%M:%S")
//				<< ")"
//			);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::core::get()->add_global_attribute("LineCounter"
//				, boost::log::attributes::counter<int>{});
//			boost::log::sources::severity_logger<int> lg;
//			BOOST_LOG_SEV(lg, 0) << "note";
//			BOOST_LOG_SEV(lg, 1) << "warning";
//			{
//				BOOST_LOG_SCOPED_LOGGER_ATTR(lg, "Timestamp"
//					, boost::log::attributes::local_clock())
//					BOOST_LOG_SEV(lg, 2) << "error";
//			}
//			BOOST_LOG_SEV(lg, 2) << "another error";
//			sink->flush();
//			break;
//		} // eof case 7
//		case 8:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> ostream_sink;
//			boost::shared_ptr<ostream_sink> ostream = boost::make_shared<ostream_sink>();
//			boost::shared_ptr<std::ostream> clog{ &std::clog,
//				boost::null_deleter{} };
//			ostream->locked_backend()->add_stream(clog);
//			boost::log::core::get()->add_sink(ostream);
//			typedef boost::log::sinks::synchronous_sink<
//				boost::log::sinks::text_multifile_backend> multifile_sink;
//			boost::shared_ptr< multifile_sink> multifile = boost::make_shared<multifile_sink>();
//			multifile->locked_backend()->set_file_name_composer(
//				boost::log::sinks::file::as_file_name_composer(
//					boost::log::expressions::stream
//					<< channel.or_default<std::string>("None")
//					<< "-"
//					<< severity.or_default(0)
//					<< ".log"
//				)
//			);
//			boost::log::core::get()->add_sink(multifile);
//			boost::log::sources::severity_logger<int> severity_lg;
//			boost::log::sources::channel_logger<> channel_lg{
//				boost::log::keywords::channel = "Main"
//			};
//			BOOST_LOG_SEV(severity_lg, 1) << "severity message";
//			BOOST_LOG(channel_lg, 1) << "channel message";
//			ostream->flush();
//			break;
//		} // eof case 8
//		case 9:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			boost::log::core::get()->add_sink(sink);
//			boost::log::core::get()->set_exception_handler(
//				boost::log::make_exception_handler<
//					  boost::log::runtime_error
//					, std::exception>(handler{})
//			);
//			boost::log::sources::logger lg;
//			BOOST_LOG(lg) << "note";
//			break;
//		} // eof case 9
//		case 10:
//		{
//			typedef boost::log::sinks::asynchronous_sink<
//				boost::log::sinks::text_ostream_backend> text_sink;
//			boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
//			boost::shared_ptr<std::ostream> stream{ &std::clog,
//				boost::null_deleter{} };
//			sink->locked_backend()->add_stream(stream);
//			boost::log::core::get()->add_sink(sink);
//			BOOST_LOG(lg10::get()) << "note";
//			break;
//		} // eof case 10
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			std::cout << "The entered number is not recognized, please try again.\n";
//			break;
//		} // eof switch
//	}
//}
//****************************************************************************
//*                     chapter_63
//****************************************************************************
auto
chapter_63() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 63. Boost.ProgramOptions\n";
		std::cout << "=================================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_64
//****************************************************************************
auto
chapter_64() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 64. Boost.Serialization\n";
		std::cout << "===============================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     chapter_65
//****************************************************************************
auto
chapter_65() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 65. Boost.Uuid\n";
		std::cout << "======================\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}
//****************************************************************************
//*                     main
//****************************************************************************
int main()
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "The Boost C++ Libraries\n";
		std::cout << "=======================\n";
		std::cout << "Part I. RAII and Memory Management\n";
		std::cout << " 1) Chapter 1. Boost.SmartPointers\n";
		std::cout << " 2) Chapter 2. Boost.PointerContainer\n";
		std::cout << " 3) Chapter 3. Boost.ScopeExit\n";
		std::cout << " 4) Chapter 4. Boost.Pool\n";
		std::cout << "Part IX. Functional Programming\n";
		std::cout << "39) Chapter 39. Boost.Phoenix\n";
		std::cout << "40) Chapter 40. Boost.Function\n";
		std::cout << "41) Chapter 41. Boost.Bind\n";
		std::cout << "42) Chapter 42. Boost.Ref\n";
		std::cout << "43) Chapter 43. Boost.Lambda\n";
		std::cout << "Part X. Parallel Programming\n";
		std::cout << "----------------------------\n";
		std::cout << "44) Chapter 44. Boost.Thread\n";
		std::cout << "45) Chapter 45. Boost.Atomic\n";
		std::cout << "46) Chapter 46. Boost.Lockfree\n";
		std::cout << "47) Chapter 47. Boost.MPI\n";
		std::cout << "Part XI. Generic Programming\n";
		std::cout << "----------------------------\n";
		std::cout << "48) Chapter 48. Boost.TypeTraits\n";
		std::cout << "49) Chapter 49. Boost.EnableIf\n";
		std::cout << "50) Chapter 50. Boost.Fusion\n";
		std::cout << "Part XII. Language Extensions\n";
		std::cout << "-----------------------------\n";
		std::cout << "51) Chapter 51. Boost.Coroutine\n";
		std::cout << "52) Chapter 52. Boost.Foreach\n";
		std::cout << "53) Chapter 53. Boost.Parameter\n";
		std::cout << "54) Chapter 54. Boost.Conversion\n";
		std::cout << "Part XIII. Error Handling\n";
		std::cout << "-------------------------\n";
		std::cout << "55) Chapter 55. Boost.System\n";
		std::cout << "56) Chapter 56. Boost.Exception\n";
		std::cout << "Part XIV. Number Handling\n";
		std::cout << "-------------------------\n";
		std::cout << "57) Chapter 57. Boost.Integer\n";
		std::cout << "58) Chapter 58. Boost.Accumulators\n";
		std::cout << "59) Chapter 59. Boost.MinMax\n";
		std::cout << "60) Chapter 60. Boost.Random\n";
		std::cout << "61) Chapter 61. Boost.NumericConversion\n";
		std::cout << "Part XV. Application Libraries\n";
		std::cout << "==============================\n";
		std::cout << "62) Chapter 62. Boost.Log\n";
		std::cout << "63) Chapter 63. Boost.ProgramOptions\n";
		std::cout << "64) Chapter 64. Boost.Serialization\n";
		std::cout << "65) Chapter 65. Boost.Uuid\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 1:
			chapter_1();
			break;
		case 2:
			chapter_2();
			break;
		case 3:
			chapter_3();
			break;
		case 4:
			chapter_4();
			break;
		//case 39:
		//	chapter_39();
		//	break;
		//case 40:
		//	chapter_40();
		//	break;
		//case 41:
		//	chapter_41();
		//	break;
		//case 42:
		//	chapter_42();
		//	break;
		//case 43:
		//	chapter_43();
		//	break;
		//case 44:
		//	chapter_44();
		//	break;
		//case 45:
		//	chapter_45();
		//	break;
		//case 46:
		//	chapter_46();
		//	break;
		//case 47:
		//	chapter_47();
		//	break;
		//case 48:
		//	chapter_48();
		//	break;
		//case 49:
		//	chapter_49();
		//	break;
		//case 50:
		//	chapter_50();
		//	break;
		//case 51:
		//	chapter_51();
		//	break;
		//case 52:
		//	chapter_52();
		//	break;
		//case 53:
		//	chapter_53();
		//	break;
		//case 54:
		//	chapter_54();
		//	break;
		//case 55:
		//	chapter_55();
		//	break;
		//case 56:
		//	chapter_56();
		//	break;
		//case 57:
		//	chapter_57();
		//	break;
		//case 58:
		//	chapter_58();
		//	break;
		//case 59:
		//	chapter_59();
		//	break;
		//case 60:
		//	chapter_60();
		//	break;
		//case 61:
		//	chapter_61();
		//	break;
		//case 62:
		//	chapter_62();
		//	break;
		case 63:
			chapter_63();
			break;
		case 64:
			chapter_64();
			break;
		case 65:
			chapter_65();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			std::cout << "The entered number is not recognized, please try again.\n";
			break;
		} // eof switch
	}
}

//////////////////////////////////////////////////////////////////////////////

//#include <boost/filesystem.hpp>
//#include <iostream>
//#include <string>
//using namespace boost::filesystem;
//int main()
//{
//	// example 35.5 accessing components of a path
//	path p5{ "C:\\Windows\\System" };
//	std::cout << "root name........: " << p5.root_name() << '\n';
//	std::cout << "root directory...: " << p5.root_directory() << '\n';
//	std::cout << "root path........: " << p5.root_path() << '\n';
//	std::cout << "relative path....: " << p5.relative_path() << '\n';
//	std::cout << "parent path......: " << p5.parent_path() << '\n';
//	std::cout << "filename.........: " << p5.filename() << '\n';
//
//	// example  35.6 receiving file name and file extension
//	path p6{ "photo.jpg" };
//	std::cout << "stem........: " << p6.stem() << '\n';
//	std::cout << "extension...: " << p6.extension() << '\n';
//
//	// example 35.7 iterating over components of a path
//	path p7{ "C:\\Windows\\System" };
//	for (const path& pp : p7)
//		std::cout << pp << '\n';
//
//	//example 35.8 concatenating paths with operator /=
//	path p8{ "C:\\" };
//	p8 /= "Windows\\System";
//	std::cout << p8.make_preferred() << '\n';
//
//	// obj.remove_filename();
//	// obj.replace_extension();
//	// obj.make_absolute();
//
//	// example 35.9 preferred notation with make_preferred()
//	path p9{ "C:/Windows/System" };
//	// the function also modifies the object p
//	// p will contain: C:\Windows\System
//	std::cout << p9.make_preferred() << '\n';
//
//	// example 35.14 creating, renaming, and deleting directories
//	path p14{ "C:\\Test" };
//	try
//	{
//		if (create_directory(p14))
//		{
//			rename(p14, "C:\\Test2");
//			boost::filesystem::remove("C:\\Test2");
//		}
//	}
//	catch (filesystem_error& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	// example 35.15 using boost::filesystem::absolute()
//	try
//	{
//		std::cout << absolute("photo.jpg") << '\n';
//	}
//	catch (filesystem_error& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	// example 35.16 creating an absolute path relative to another directory
//	try
//	{
//		std::cout << absolute("photo.jpg", "D:\\") << '\n';
//	}
//	catch (filesystem_error& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	// example 35.17 using boost::filesystem::current_path()
//	try 
//	{
//		std::cout << current_path() << '\n';
//		current_path("C:\\");
//		std::cout << current_path() << '\n';
//	}
//	catch (filesystem_error& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	return EXIT_SUCCESS;
//}
//// //BoostLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//// //1) Configuration Properties C / C++ General
//// //   Additional Include Directories : C:\Program Files\boost\boost_1_70_0
//// //   Precompiled Header : Not Using Precompiled Headers
//// //2) Configuration Properties Linker General
//// //   Additional Include Directories : C:\Program Files\boost\boost_1_70_0\stage\lib
////#define _WIN32_WINNT 0x0601
////
////#include <iostream>
////#include <string>
////
////#include "example_1_1.cpp"
////#include "example_1_2.cpp"
////#include "example_1_3.cpp"
////#include "example_1_4.cpp"
////#include "example_1_5.cpp"
////#include "example_1_6.cpp"
////#include "example_1_7.cpp"
////#include "example_1_8.cpp"
////#include "example_1_9.cpp"
////#include "example_2_1.cpp"
////#include "example_2_2.cpp"
////#include "example_2_3.cpp"
////#include "exercise_2_1_starter.cpp"
////#include "exercise_2_1.cpp"
////#include "example_3_1.cpp"
////#include "example_3_2.cpp"
////#include "example_3_3.cpp"
////#include "exercise_3_1.cpp"
////#include "example_4_1.cpp"
////#include "example_4_2.cpp"
////#include "example_4_3.cpp"
////#include "example_4_4.cpp"
////#include "example_4_5.cpp"
////#include "example_4_6.cpp"
////#include "example_5_1.cpp"
////#include "example_5_2.cpp"
////#include "example_5_3.cpp"
////#include "example_5_4.cpp"
////#include "example_5_5.cpp"
////#include "example_5_6.cpp"
////#include "example_5_7.cpp"
////#include "example_5_8.cpp"
////#include "example_5_9.cpp"
////#include "example_5_10.cpp"
////#include "example_5_11.cpp"
////#include "example_5_12.cpp"
////#include "exercise_5_1.cpp"
////#include "example_6_1.cpp"
////#include "example_6_2.cpp"
////#include "example_7_1.cpp"
////#include "example_7_2.cpp"
////#include "example_7_3.cpp"
////#include "example_7_4.cpp"
////#include "example_7_5.cpp"
////#include "example_7_6.cpp"
////#include "example_7_7.cpp"
////#include "example_7_8.cpp"
////#include "example_7_9.cpp"
////#include "example_8_1.cpp"
////#include "example_8_2.cpp"
////#include "example_8_3.cpp"
////#include "example_8_4.cpp"
////#include "example_8_5.cpp"
////#include "example_8_6.cpp"
////#include "example_8_7.cpp"
////#include "example_8_8.cpp"
////#include "example_32_1.cpp"
////#include "example_32_2.cpp"
////#include "example_32_3.cpp"
////#include "example_32_4.cpp"
////#include "example_32_5.cpp"
////#include "example_32_6.cpp"
////#include "exercise_32_1.cpp"
////#include "example_32_7.cpp"
////#include "example_http_client_sync.cpp"
////#include "example_websocket_client_sync.cpp"
////
////// used in exercise_2_1_starter.cpp
////const string ns_exercise_2_1_starter::muuuh = "Muuuh!";
////const string ns_exercise_2_1_starter::oiink = "Oiiink";
////
////// used in example_32_5
////io_service ns_example_32_5::ioservice;
////tcp::resolver ns_example_32_5::resolv{ ns_example_32_5::ioservice };
////tcp::socket ns_example_32_5::tcp_socket{ ns_example_32_5::ioservice };
////array<char, 4096> ns_example_32_5::bytes;
////
////// used in example_32_6
////io_service ns_example_32_6::ioservice;
////tcp::endpoint ns_example_32_6::tcp_endpoint{ tcp::v4(), 2014 };
////tcp::acceptor ns_example_32_6::tcp_acceptor{ ns_example_32_6::ioservice,
////	ns_example_32_6::tcp_endpoint };
////tcp::socket ns_example_32_6::tcp_socket{ ns_example_32_6::ioservice };
////string ns_example_32_6::data;
////
////// used in example_32_7
////io_service ns_example_32_7::ioservice;
////tcp::endpoint ns_example_32_7::tcp_endpoint{ tcp::v4(), 2014 };
////tcp::acceptor ns_example_32_7::tcp_acceptor{ 
////	ns_example_32_7::ioservice, 
////	ns_example_32_7::tcp_endpoint };
////list<tcp::socket> ns_example_32_7::tcp_sockets;
////
////int main() {
////	ns_example_1_1::example_1_1();
////	ns_example_1_2::example_1_2();
////	ns_example_1_3::example_1_3();
////	ns_example_1_4::example_1_4();
////	ns_example_1_5::example_1_5();
////	ns_example_1_6::example_1_6();
////	ns_example_1_7::example_1_7();
////	ns_example_1_8::example_1_8();
////	ns_example_1_9::example_1_9(); // has issues
////	ns_example_2_1::example_2_1();
////	ns_example_2_2::example_2_2();
////	ns_example_2_3::example_2_3();
////	ns_exercise_2_1_starter::exercise_2_1_starter();
////	ns_exercise_2_1::exercise_2_1();
////	ns_example_3_1::example_3_1();
////	ns_example_3_2::example_3_2();
////	ns_example_3_3::example_3_3();
////	ns_exercise_3_1::exercise_3_1();
////	_example_4_1::example_4_1();
////	ns_example_4_2::example_4_2();
////	ns_example_4_3::example_4_3();
////	ns_example_4_4::example_4_4();
////	ns_example_4_5::example_4_5();
////	ns_example_4_6::example_4_6();
////	ns_example_5_1::example_5_1();
////	ns_example_5_2::example_5_2();
////	ns_example_5_3::example_5_3();
////	ns_example_5_4::example_5_4();
////	ns_example_5_5::example_5_5();
////	ns_example_5_6::example_5_6();
////	ns_example_5_7::example_5_7();
////	ns_example_5_8::example_5_8();
////	ns_example_5_9::example_5_9();
////	ns_example_5_10::example_5_10();
////	ns_example_5_11::example_5_11();
////	ns_example_5_12::example_5_12(); // has issues
////	ns_exercise_5_1::exercise_5_1(); // has issues
////	ns_example_6_1::example_6_1();
////	ns_example_6_2::example_6_2();
////	ns_example_7_1::example_7_1();
////	ns_example_7_2::example_7_2();
////	ns_example_7_3::example_7_3();
////	ns_example_7_4::example_7_4();
////	ns_example_7_5::example_7_5();
////	ns_example_7_6::example_7_6();
////	ns_example_7_7::example_7_7();
////	ns_example_7_8::example_7_8();
////	ns_example_7_9::example_7_9();
////	ns_example_8_1::example_8_1();
////	ns_example_8_2::example_8_2();
////	ns_example_8_3::example_8_3();
////	// this example does not output what was suggested
////	ns_example_8_4::example_8_4();
////	ns_example_8_5::example_8_5();
////	ns_example_8_6::example_8_6();
////	ns_example_8_7::example_8_7();
////	ns_example_8_8::example_8_8();
////	ns_example_32_1::example_32_1();
////	ns_example_32_2::example_32_2();
////	ns_example_32_3::example_32_3();
////	ns_example_32_4::example_32_4();
////	ns_example_32_5::example_32_5();
////	ns_example_32_6::example_32_6();
////	ns_exercise_32_1::exercise_32_1();
////	ns_example_32_7::example_32_7();
////	// example taken from:
////	// https://www.boost.org/doc/libs/1_70_0/libs/beast/doc/html/beast/examples.html
////	char cmd[] = "http-client-sync";
////	char host[] = "www.example.com";
////	char port[] = "80";
////	char target[] = "/";
////	char* argv[] = { cmd, host , port, target };
////	ns_example_http_client_sync::example_http_client_sync(
////		4, argv);
////	// example taken from:
////	// https://www.boost.org/doc/libs/1_70_0/libs/beast/doc/html/beast/examples.html
////	char cmd[] = "websocket-client-sync";
////	char host[] = "echo.websocket.org";
////	char port[] = "80";
////	char text[] = "\"Hello, world!\"";
////	char* argv[] = { cmd, host , port, text };
////	ns_example_websocket_client_sync::example_websocket_client_sync(
////		4, argv);
////}
