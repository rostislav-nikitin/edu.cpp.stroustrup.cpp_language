#include <iostream>
#include <exception>
#include <ostream>
#include <limits>

class Int
{
	int _value;
public:
	class IntException : public std::exception { };
	class OverflowException : public IntException { };
	class LostPrecisionException : public IntException { };
	
	Int(int value);

	Int operator=(Int x)
	{
		_value = x._value;

		return *this;
	}

	operator short()
	{
		if(_value > std::numeric_limits<short>::max()
			|| _value < std::numeric_limits<short>::min())
			throw LostPrecisionException();

		return static_cast<short>(_value);
	}

	friend Int operator+(Int a, Int b);
	friend std::ostream& operator<<(std::ostream& stream, Int value);
};

Int::Int(int value) : _value(value)
{
}

Int operator+(Int a, Int b)
{
	int result = a._value + b._value;

	if(a._value > 0 && b._value > 0 && result <= 0)
		throw Int::OverflowException();

	if(a._value < 0 && b._value < 0 && result >= 0)
		throw Int::OverflowException();

	return result;
}
std::ostream& operator<<(std::ostream& stream, Int value)
{
	stream << value._value;

	return stream;
}

int main()
{
	try
	{
		Int x(100);
		Int y(200);
		Int z = x + y;
		std::cout << "x + y = " << z << std::endl;

		y = std::numeric_limits<int>::max();
		z = x + y;
		std::cout << "x + y = " << z << std::endl;
	}
	catch(Int::OverflowException &oex)
	{
		std::cout << "Overflow exception" << std::endl;
	}
	catch(...)
	{
		std::cout << "Unexpected exception." << std::endl;
	}

	try
	{
		Int x (std::numeric_limits<short>::max());
		short y = x;
		std::cout << "y = " << y << std::endl;

		x = std::numeric_limits<short>::max() + 1;
		y = x;
		std::cout << "y = " << y << std::endl;
	}
	catch(Int::LostPrecisionException &lpex)
	{
		std::cout << "Lost precision exception." << std::endl;
	}


	return 0;
}
