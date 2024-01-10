#include <limits>
#include <iostream>
#include <bitset>

int main()
{
	std::bitset<16> bs("1111");
	std::cout << bs.to_ulong() << std::endl;
	std::cout << bs.to_string() << std::endl;

	std::bitset<32> neg(-1);
	std::cout << neg.to_ulong() << std::endl;
	std::cout << neg.to_string() << std::endl;
	neg.flip(31);
	std::cout << neg.to_ulong() << std::endl;
	std::cout << neg.to_string() << std::endl;

	std::bitset<32> max_uint(std::numeric_limits<unsigned int>::max());
	std::cout << max_uint.to_ulong() << std::endl;
	std::cout << max_uint.to_string() << std::endl;

	std::bitset<32> max_int(std::numeric_limits<int>::max());
	std::cout << max_int.to_ulong() << std::endl;
	std::cout << max_int.to_string() << std::endl;

	return EXIT_SUCCESS;
}
