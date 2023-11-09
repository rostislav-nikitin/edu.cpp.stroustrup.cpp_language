#include <iostream>


void f(char ch)
{
}

void g(char &ch)
{
}

void h(char const &ch)
{
}

void k(char *cj)
{
}

int main()
{
	f('a'); 
//	g('a'); 
	h('a');


	f(49); 
//	g(49); 
	h(49);

	f(3300); 
//	g(3300); 
	h(3300);
	
	char val_char = 'x';
	f(val_char); 
	g(val_char); 
	h(val_char);

	unsigned char val_uchar = 'x';
	f(val_uchar); 
//	g(val_uchar); 
	h(val_uchar);
//	k(&val_uchar);

	signed char val_schar = 'x';
	f(val_schar); 
//	g(val_schar); 
	h(val_schar);
//	k(&val_schar);



	std::cout << "CONST" << std::endl;

	return 0;
}
