#include <iostream>
#include <algorithm>

template<class TInOne, class TInTwo>
	std::pair<TInOne, TInTwo> match(TInOne firstOne, TInOne lastOne, TInTwo firstTwo)
	{
		std::pair<TInOne, TInTwo> result;

		for(;(firstOne != lastOne) && (*firstOne != *firstTwo); firstOne++, firstTwo++)
		{
		}

		result.first = firstOne;
		result.second = firstTwo;
		return result;

	}
template<class TInOne, class TInTwo, class Cmp>
	std::pair<TInOne, TInTwo> match(TInOne firstOne, TInOne lastOne, TInTwo firstTwo, Cmp op)
	{
		std::pair<TInOne, TInTwo> result;

		for(;(firstOne != lastOne) && !op(*firstOne, *firstTwo); firstOne++, firstTwo++)
		{
		}

		result.first = firstOne;
		result.second = firstTwo;
		return result;

	}

int main()
{
	int a[] = {123, 5, 1, 8, 5, 25, 110};
	int b[] = {7, 5, 2, 8, 123, 25, 1};

	std::pair<int*, int*> result = match<int *, int *>(a, a + 4, b);
	std::cout << *result.first << "==" << *result.second << std::endl;

	result = match(a, a + 4, b, [](int a, int b) { return a == b;  });
	std::cout << *result.first << "==" << *result.second << std::endl;
	
	std::pair<int*, int*> miss_result = std::mismatch<int *, int *>(a, a + 4, b);
	std::cout << *miss_result.first << "==" << *miss_result.second << std::endl;
	
	return EXIT_SUCCESS;
}
