#include <iostream>

struct X
{
	int i;
	X(int);
	X operator+ (int);
	int val() const;
};

X::X(int i) : i(i)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

X X::operator+ (int operand)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	X result = i + operand;

	return result;
}

int X::val() const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return i;
}

struct Y
{
	int i;
	Y(X);
	Y operator+ (X);
	operator int();
	int val() const;
};

Y::Y(X x) : i(x.val())
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Y Y::operator+(X operand)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	Y result = operand;
	result.i += i;

	return result;
}

Y::operator int()
{
	return i;
}

int Y::val() const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return i;
}

X operator* (X x, Y y)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	X result = x.val() * y.val();

	return result;
}

int f(X x)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return 0;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
	std::cout << "i + 10" << std::endl;
	i + 10;

	// Ambiguous
	//std::cout << std::endl << "y + 10" << std::endl;
	//y + 10;

	// Ambiguous
	//std::cout << std::endl << "y + 10 * y" << std::endl;
	//y + 10 * y;
	
	std::cout << std::endl << "x + y + i" << std::endl;
	x + y + i;

	std::cout << std::endl << "x * x + i" << std::endl;
	x * x + i;

	std::cout << std::endl << "f(7)" << std::endl;
	f(7);

	// Can not convert Y to X
	//std::cout << std::endl << "f(y)" << std::endl;
	//f(y);
	
	std::cout << std::endl << "y + y" << std::endl;
	y + y;

	std::cout << std::endl << "106 + y" << std::endl;
	106 + y;

	return 0;
}
