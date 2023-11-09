#include "class_b.h"
#include "class_a.h"

void B::print()
{
	std::cout << "x: " << x << "\t y: " << y << std::endl;
	std::cout << "m: " << m << "\t n: " << n() << std::endl;
}

int B::x = A::x;
int B::y = 20;

int B::m = A::m();
int B::n()
{
	static int value = 40;

	return value;
}
