#include <iostream>

class X
{
public:
	X(int i) { }
};

class Y
{
public:
	Y(X x) { }
};


class Z
{
public:
	Z(Y y) { }
};

void f(Y y)
{
}

int main()
{
	Y y = Y(1);
	//Z z = Z(1);
	f(Y(1));

	return 0;
}
