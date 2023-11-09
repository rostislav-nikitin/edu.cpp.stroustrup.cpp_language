#include <limits>
#include <iostream>

#include "cmathlib.h"

int main()
{
	std::cout << "Hello" << std::endl;
	// PLUS
	try
	{
		std::cout << "plus(4, 5)=" << plus(4, 5) << std::endl;
		std::cout << "plus(" << std::numeric_limits<int>::max() << ", 1)=" << plus(std::numeric_limits<int>::max(), 1) << std::endl;
	}
	catch(Overflow_Exception ofex)
	{
		std::cout << std::endl << "Overflow exception. Exit" << std::endl;
	}
	catch(Divide_By_Zero_Exception ex)
	{
		std::cout << std::endl << "Divide by zero exception. Exit" << std::endl;
	}
	catch(...)
	{
		std::cout << std::endl << "Unknown exception. Exit" << std::endl;
	}

	// MINUS
	try
	{
		std::cout << "minus(120, 15)=" << minus(120, 15) << std::endl;
		std::cout << "minus(" << std::numeric_limits<int>::min() << ", 1)=" << minus(std::numeric_limits<int>::min(), 1) << std::endl;
	}
	catch(Overflow_Exception ofex)
	{
		std::cout << std::endl << "Overflow exception. Exit" << std::endl;
	}
	catch(Divide_By_Zero_Exception ex)
	{
		std::cout << std::endl << std::endl << "Divide by zero exception. Exit" << std::endl;
	}
	catch(...)
	{
		std::cout << std::endl << "Unknown exception. Exit" << std::endl;
	}

	// MULTIPLY
	try
	{
		std::cout << "multiply(120, 10)=" << multiply(120, 10) << std::endl;
		std::cout << "multiply(" << std::numeric_limits<int>::max() << ", 2)=" << multiply(std::numeric_limits<int>::max(), 2) << std::endl;
	}
	catch(Overflow_Exception ofex)
	{
		std::cout << std::endl << "Overflow exception. Exit" << std::endl;
	}
	catch(Divide_By_Zero_Exception ex)
	{
		std::cout << std::endl << "Divide by zero exception. Exit" << std::endl;
	}
	catch(...)
	{
		std::cout << std::endl << "Unknown exception. Exit" << std::endl;
	}

	// DIVIDE
	try
	{
		std::cout << "divide(256, 8)=" << divide(256, 8) << std::endl;
		std::cout << "divide(16, 0)=" << divide(16, 0) << std::endl;
	}
	catch(Overflow_Exception ofex)
	{
		std::cout << std::endl << "Overflow exception. Exit" << std::endl;
	}
	catch(Divide_By_Zero_Exception ex)
	{
		std::cout << std::endl << "Divide by zero exception. Exit" << std::endl;
	}
	catch(...)
	{
		std::cout << std::endl << "Unknown exception. Exit" << std::endl;
	}

	return 0;
}
