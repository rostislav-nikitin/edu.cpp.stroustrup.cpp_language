#include <iostream>

void f(char *, int &);

void (* ptr_f)(char *, int &);

void g(void (char *, int &));

typedef void (& ptr_fn_t) (char *, int &);

ptr_fn_t h(ptr_fn_t in_fn)
{
	return *in_fn;
}

int main()
{
	std::cout << "DECLARE" << std::endl;
	return 0;
}
