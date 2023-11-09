#include "cross_static.h"

int main()
{
	std::cout << "CROSS STATIC" << std::endl;

	A a{};
	B b{};

	
	std::cout << "A output:" << std::endl;
	a.print();

	std::cout << "B output:" << std::endl;
	b.print();

	return 0;
}
