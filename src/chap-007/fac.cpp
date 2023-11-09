#include <iostream>

long int fac(int n)
{
	long int result = 1;
	for(int i = 2; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

int main()
{
	int n = 10;
	std::cout << "fac(" << n << ") = " << fac(n);

	return 0;
}
