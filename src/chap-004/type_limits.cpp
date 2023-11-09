#include <iostream>
#include <limits>

int main()
{

	std::cout << "char\t\t\tMin=" << std::numeric_limits<char>::min() << "\tMax=" << std::numeric_limits<char>::max() << std::endl;

	std::cout << "bool\t\t\tMin=" << std::numeric_limits<bool>::min() << "\tMax=" << std::numeric_limits<bool>::max() << std::endl;

	std::cout << "short int\t\tMin=" << std::numeric_limits<short int>::min() << "\tMax=" << std::numeric_limits<short int>::max() << std::endl;
	std::cout << "int\t\t\tMin=" << std::numeric_limits<int>::min() << "\tMax=" << std::numeric_limits<int>::max() << std::endl;
	std::cout << "unsigned int\t\tMin=" << std::numeric_limits<unsigned int>::min() << "\tMax=" << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "long int\t\tMin=" << std::numeric_limits<long int>::min() << "\tMax=" << std::numeric_limits<long int>::max() << std::endl;

	std::cout << "float\t\t\tMin=" << std::numeric_limits<float>::min() << "\tMax=" << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double\t\t\tMin=" << std::numeric_limits<double>::min() << "\tMax=" << std::numeric_limits<double>::max() << std::endl;
	std::cout << "long double\t\tMin=" << std::numeric_limits<long double>::min() << "\tMax=" << std::numeric_limits<long double>::max() << std::endl;

	return 0;
}
