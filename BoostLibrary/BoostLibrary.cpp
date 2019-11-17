#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/cast.hpp>
#include <boost/coroutine/all.hpp>
#include <boost/cstdint.hpp>
#include <boost/exception/all.hpp>
#include <boost/foreach.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/iterator.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/view.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/mpl/arg.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/parameter.hpp>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/system/error_code.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/type_traits.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>
#include <string>
#include <tuple>
#include <typeinfo>
#include <utility>
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
//****************************************************************************
//*                     chapter_60
//****************************************************************************
auto
chapter_60() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 60. Boost.Random\n";
		std::cout << "========================\n";
		std::cout << " 1) Example 1: Pseudo-random numbers with boost::random::mt19937\n";
		std::cout << " 2) Example 2: Real random numbers with boost::random::random_device\n";
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
		case 1:
		{
			std::time_t now = std::time(0);
			boost::random::mt19937 gen{ static_cast<std::uint32_t>(now) };
			std::cout << "generated random number: " << gen() << '\n';
			break;
		} // eof case 1
		case 2:
		{
			boost::random::random_device gen;
			std::cout << "generated random number: " << gen() << '\n';
			break;
		} // eof case 2
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
//*                     chapter_61
//****************************************************************************
auto
chapter_61() -> void
{
	bool bProceed = true;
	unsigned int iChar = 0;
	while (bProceed)
	{
		std::cout << "Chapter 61. Boost.NumericConversion\n";
		std::cout << "===================================\n";
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
		std::cout << "Enter the number of a subject, or enter a zero to quit: ";
		std::cin >> iChar;
		// get rid of the newline character, to ensure the buffer sanity
		std::cin.get();
		switch (iChar)
		{
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
		case 60:
			chapter_60();
			break;
		case 61:
			chapter_61();
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
