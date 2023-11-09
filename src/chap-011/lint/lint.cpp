#include <iostream>
#include <limits>


class X
{
	public:
		X();
};
X::X() {}

class Y
{
	public:
		Y(X);
};
Y::Y(X x) { }

class LInt
{
	private:
		long int _value;
	public:
		LInt(long int);
		LInt(Y y);

		LInt operator+();
		LInt operator-();

		friend LInt operator+(LInt const &lhv, LInt const &rhv);
		friend LInt operator-(LInt const &lhv, LInt const &rhv);
		friend LInt operator*(LInt const &lhv, LInt const &rhv);
		friend LInt operator/(LInt const &lhv, LInt const &rhv);
		friend LInt operator%(LInt const &lhv, LInt const &rhv);

		friend std::ostream & operator<< (std::ostream &stream, LInt const &value);
};

LInt::LInt(long int value) : _value(value) { }
LInt::LInt(Y y) { }
LInt LInt::operator+()
{
	return LInt(+_value);
}
LInt LInt::operator-()
{
	return LInt(-_value);
}

LInt operator+(LInt const &lhv, LInt const &rhv)
{
	return LInt(lhv._value + rhv._value);
}
LInt operator-(LInt const &lhv, LInt const &rhv)
{
	return LInt(lhv._value - rhv._value);
}
LInt operator*(LInt const &lhv, LInt const &rhv)
{
	return LInt(lhv._value * rhv._value);
}
LInt operator/(LInt const &lhv, LInt const &rhv)
{
	return LInt(lhv._value / rhv._value);
}
LInt operator%(LInt const &lhv, LInt const &rhv)
{
	return LInt(lhv._value % rhv._value);
}

std::ostream & operator<<(std::ostream &stream, LInt const &value)
{
	stream << value._value;

	return stream;
}

int main()
{
	LInt m = std::numeric_limits<long int>::max();
	LInt x = 1000;
	LInt y = 200;

	std::cout << "m: " << m << std::endl;
	std::cout << "+m: " << +m << std::endl;
	std::cout << "-m: " << -m << std::endl;

	std::cout << "x: " << x << " y: " << y << std::endl;
	std::cout << "x + y: " << x + y << std::endl;
	std::cout << "x - y: " << x - y << std::endl;
	std::cout << "x * y: " << x * y << std::endl;
	std::cout << "x / y: " << x / y << std::endl;
	std::cout << "y % x: " << y % x << std::endl;

	LInt z = 'a';
	std::cout << "z: " << z << std::endl;

	X cx;
	LInt icx = Y(cx);

	return 0;
}
