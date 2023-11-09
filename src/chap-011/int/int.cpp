#include <iostream>

class Int
{
	private:
		int _value;
	public:
		Int(int);
		operator int();

};

Int::Int(int value) : _value(value) { }
Int::operator int() { return _value; }

int main()
{
	Int x = 10;
	int y = 20;

	std:: cout << "x + y = " << x + y << std::endl;

	int z = x * y;
	std:: cout << "z = x * y: " << z << std::endl;

	return 0;
}
