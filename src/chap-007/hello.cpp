#include <iostream>

int main(int argc, char *argv[])
{
	for(int idx = 1; idx < argc; idx++)
		std::cout << "Hello, " << argv[idx] << std::endl;
	
	return 0;
}
