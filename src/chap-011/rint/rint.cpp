#include <iostream>

class RInt
{
	private:
		int _value;
		//RInt(RInt &value);
		//RInt(RInt const &value);
	public:
		RInt(int value);

		RInt operator+();
		RInt operator-();

		friend RInt operator+(RInt const &operand1, RInt const &operand2);
		friend RInt operator-(RInt const &operand1, RInt const &operand2);
		friend RInt operator*(RInt const &operand1, RInt const &operand2);
		friend RInt operator/(RInt const &operand1, RInt const &operand2);
		friend RInt operator%(RInt const &operand1, RInt const &operand2);
		friend std::ostream& operator<<(std::ostream& stream, RInt const &operand);
};

void f(RInt value)
{
}

RInt::RInt(int value) : _value(value) { }
RInt RInt::operator+()
{
	return RInt(+_value);
}
RInt RInt::operator-()
{
	return RInt(-_value);
}

RInt operator+(RInt const &operand1, RInt const &operand2)
{
	return RInt(operand1._value + operand2._value);
}
RInt operator-(RInt const &operand1, RInt const &operand2)
{
	return RInt(operand1._value - operand2._value);
}
RInt operator*(RInt const &operand1, RInt const &operand2)
{
	return RInt(operand1._value * operand2._value);
}
RInt operator/(RInt const &operand1, RInt const &operand2)
{
	return RInt(operand1._value / operand2._value);
}
RInt operator%(RInt const &operand1, RInt const &operand2)
{
	return RInt(operand1._value % operand2._value);
}
std::ostream& operator<<(std::ostream& stream, RInt const &operand)
{
	stream << operand._value;

	return stream;
}

int main()
{
	RInt x = 300;
	RInt y = 100;

	std::cout << "x: " << x << "\ty: " << y << std::endl;	
	std::cout << "lvalue" << std::endl;
	std::cout << "+x: " << +x << std::endl;	
	std::cout << "-x: " << -x << std::endl;	

	std::cout << "x + y: " << x + y << std::endl;	
	std::cout << "x * y: " << x * y << std::endl;	
	std::cout << "x / y: "  << x / y << std::endl;	
	std::cout << "y % x: "  << y % x << std::endl;	

	f(x);

	std::cout << std::endl << "rvalue" << std::endl;
	std::cout << "+600: " << +RInt(600) << std::endl;	
	std::cout << "-600x: " << -RInt(600) << std::endl;	

	std::cout << "600 + 200: " << RInt(600) + RInt(200) << std::endl;	
	std::cout << "600 * 200: " << 600 * 200 << std::endl;	
	std::cout << "600 / 200: "  << 600 / 200 << std::endl;	
	std::cout << "200 % 600: "  << 200 % 600 << std::endl;	

	return 0;
}
