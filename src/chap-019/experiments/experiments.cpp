#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	//	Iterator traits
	typedef std::iterator_traits<typename std::vector<int>::iterator> traits;
	static_assert(std::is_same<int, typename traits::value_type>::value, "Wrong type");


	//	Stream iterators
	//		std::ostream_iterator
	std::vector<std::string> strs({"Str one", "Str two", "Str ...", "Str n"});
	std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(std::cout));

	//		std::istream_iterator
	std::vector<std::string> in_strs(10);
	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(in_strs));

	return EXIT_SUCCESS;
}
