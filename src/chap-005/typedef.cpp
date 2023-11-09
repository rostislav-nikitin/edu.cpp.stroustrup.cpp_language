#include<iostream>

typedef unsigned char uchar;
typedef const unsigned char const_uchar;
typedef int const * ptr_const_int;
typedef char ** ptr_ptr_char;
typedef char * ptr_arr_char;
//typedef int ptr_int[7];
typedef int * ptr_int[7];
typedef int* arr_ptr_int_8_7 [8][7];

arr_ptr_int_8_7 int_array;

int main()
{
	std::cout << "Declaration\t - \t[OK]" << std::endl;


	return 0;
}
