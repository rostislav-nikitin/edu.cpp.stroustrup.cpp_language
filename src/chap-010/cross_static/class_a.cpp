#include "class_a.h"
#include "class_b.h"

void A::print()
{
	std::cout << "x: " << x << "\t y: " << y << std::endl;
	std::cout << "m: " << m() << "\t n: " << n << std::endl;
}

int A::x = 10;
int A::y = B::y;

int A::m()
{
	static int value = 30;

	return value;
}

int A::n = B::n();
