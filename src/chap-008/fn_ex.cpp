#include <iostream>

void fn_throw()
{
	throw 1;
}

void fn_catch()
{
	try
	{
		fn_throw();
	}
	catch(...)
	{
		std::cout << "CATCHED" << std::endl;
	}
}	

int main()
{
	std::cout << "FN_EX" << std::endl;

	fn_catch();	

	return 0;
}
