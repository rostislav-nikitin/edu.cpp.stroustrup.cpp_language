#include <iostream>

int x = 10;

int const &y = x;

int main()
{
	std::cout << "Ref. example" << std::endl;	

	return 0;
}
