#include <iostream>

int main()
{
	int n = 10;
	for(int i = 0; i < 100; ++i)
	{
		std::cout << (double(rand()) / RAND_MAX) * n << std::endl;
	}
}
