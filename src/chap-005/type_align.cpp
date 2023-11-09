#include<iostream>

struct type_align_check
{
	char 		val1_char;
	char 		val2_char;
	long int 	val_int;
//	void	*val_any;
};



char val_char1 = 'a';
char val_char2 = 'b';
int val_int = 10;
long int val_long_int1 = 10L;
char val_char3 = 'a';
long int val_long_int2 = 10L;

char *ptr_char1 = &val_char1;
char *ptr_char2 = &val_char2;
int  *ptr_int = &val_int;
long int  *ptr_long_int1 = &val_long_int1;
char *ptr_char3 = &val_char3;
long int  *ptr_long_int2 = &val_long_int2;

int main()
{
	std::cout << "sizeof(char *)\t = " << sizeof(char *)  << std::endl;
	std::cout << "sizeof(int *)\t = " << sizeof(int *)  << std::endl;
	std::cout << "sizeof(void *)\t = " << sizeof(void *)  << std::endl;


	std::cout << "sizeof(char)\t = " << sizeof(char)  << std::endl;
	std::cout << "sizeof(int)\t = " << sizeof(int)  << std::endl;
	std::cout << "sizeof(void)\t = " << sizeof(void)  << std::endl;

	std::cout << "sizeof(type_align_check)" << sizeof(type_align_check)  << std::endl;
	
	std::cout << "address of (ptr_char1) = " << static_cast<void *>(ptr_char1)  << std::endl;
	std::cout << "address of (ptr_char2) = " << static_cast<void *>(ptr_char2)  << std::endl;
	std::cout << "address of (ptr_int) = " << static_cast<void *>(ptr_int)  << std::endl;
	std::cout << "address of (ptr_long_int1) = " << static_cast<void *>(ptr_long_int1)  << std::endl;
	std::cout << "address of (ptr_char3) = " << static_cast<void *>(ptr_char3)  << std::endl;
	std::cout << "address of (ptr_long_int2) = " << static_cast<void *>(ptr_long_int2)  << std::endl;
	
	return 0;
}	
