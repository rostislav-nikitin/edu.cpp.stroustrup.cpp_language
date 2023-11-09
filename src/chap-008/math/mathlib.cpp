#include <limits>

#include "mathlib.h"

int Mathlib::plus(int x, int y)
{
	long int result = static_cast<long int>(x) + static_cast<long int>(y);
	if(result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw Overflow_Exception{};

	return static_cast<int>(result);
}

int Mathlib::minus(int x, int y)
{
	long int result = static_cast<long int>(x) - static_cast<long int>(y);

	if(result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw Overflow_Exception{};

	return static_cast<int>(result);
}

int Mathlib::multiply(int x, int y)
{
	long int result = static_cast<long int>(x) * static_cast<long int>(y);

	if(result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw Overflow_Exception{};

	return static_cast<int>(result);
}

int Mathlib::divide(int x, int y)
{
	if(y == 0)
		throw Divide_By_Zero_Exception();

	return x / y;
}

