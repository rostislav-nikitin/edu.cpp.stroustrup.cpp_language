#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class SqrGenerator
{
	int _initial;
public:
	SqrGenerator(int initial) : _initial(initial)
	{
	}
	int operator() ()
	{
		int result = _initial * _initial;

		++_initial;

		return result;
	}
};


void print(int x)
{
	std::cout << x << ", ";
}

int sqrt(int x)
{
	return static_cast<int>(std::sqrt(x));
}

int main()
{
	std::vector<int> numbers(100);

	std::generate_n(numbers.begin(), 100, SqrGenerator(1));
	std::for_each(numbers.begin(), numbers.end(), &print);
	std::cout << std::endl;

	std::vector<int> sqr_roots(100);
	std::transform<std::vector<int>::iterator, std::vector<int>::iterator, int (*)(int)>(numbers.begin(), numbers.end(), sqr_roots.begin(), &sqrt);
	std::for_each(sqr_roots.begin(), sqr_roots.end(), &print);
	std::cout << std::endl;
	
	return EXIT_SUCCESS;
}
