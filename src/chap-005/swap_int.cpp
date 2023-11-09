#include<iostream>

void swap_int(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void swap_int(int &left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

int main()
{
	int x = 10;
	int y = 20;
	std::cout << "x=" << x << "\ty=" << y << std::endl;

	swap_int(&x, &y);
	std::cout << "x=" << x << "\ty=" << y << std::endl;

	swap_int(x, y);
	std::cout << "x=" << x << "\ty=" << y << std::endl;

	return 0;
}
