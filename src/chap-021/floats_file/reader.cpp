#include <vector>

#include <ostream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <locale>

class CustomCType : public std::ctype<char>
{
	mask my_table[table_size];
public:
	CustomCType(size_t refs = 0) : std::ctype<char>(&my_table[0], false, refs)
	{
		std::copy_n(classic_table(), refs, my_table);
		my_table[','] = (mask)space;
		my_table[' '] = (mask)space;
		std::cout << "\"" << (mask)space  << "\"" << std::endl;
	}
};

int main()
{
	std::ifstream numbers("./numbers.dat");
	std::locale loc(std::locale::classic(), new CustomCType());
	numbers.imbue(loc);

//	numbers >> std::skipws;
	std::cout << "Result:" << std::endl;
	std::copy(
		std::istream_iterator<float>(numbers), 
		std::istream_iterator<float>(), 
		std::ostream_iterator<float>(std::cout, ", "));

	return EXIT_SUCCESS;
}
