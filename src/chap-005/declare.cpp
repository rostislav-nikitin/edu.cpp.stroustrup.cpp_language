#include<iostream>

char ch = 'X';
char *ptr_ch = &ch;
int int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *int_array_ptr = int_array;

char **ptr_ptr_char = &ptr_ch;
int const int_const = 10;
int const *ptr_int_const = &int_const;

int int_val = 20;
int * const ptr_int_val = &int_val;


int main()
{
	std::cout << "Declaration\t - \t[OK]" << std::endl;
	std::cout << *int_array_ptr << std::endl;


	return 0;
}
