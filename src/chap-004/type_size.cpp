#include <iostream>

enum Beer {Carlsberg, Tuborg};
enum Cars {BMW, Mercedes, Toyota, Mazda, Jaguar, RolseRoyse, Bentley, Alfa, Mazeratti};

Beer beer;
Cars cars;

int main()
{
	std::cout << "Sizes" << std::endl << "char=" << sizeof(char) << "\t\tbool=" << sizeof(bool) << std::endl << 
		"short int=" << sizeof(short int) << "\tint=" << sizeof(int) << "\t\tlong int=" << sizeof(long int) << std::endl <<
		"float=" << sizeof(float) << "\t\tdouble=" << sizeof(double) << "\tlong double=" << sizeof(long double) << std::endl <<
		"char *=" << sizeof(char *) << "\tint *=" << sizeof(int *) << "\t\tdouble *=" << sizeof(double *) << std::endl <<
		"enum Beer=" << sizeof(Beer) << "\tenum Cars=" << sizeof(Cars) << std::endl <<
		"enum beer=" << sizeof(beer) << "\tenum cars=" << sizeof(cars) << std::endl;

	return 0;
}
