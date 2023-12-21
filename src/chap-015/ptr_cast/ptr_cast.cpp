#include <cstdlib>
#include <typeinfo>
#include <iostream>


template<class T, class R>
	R* PtrCast(T* ptr) throw(std::bad_cast)
	{
		R* result = dynamic_cast<R *>(ptr);

		if(result == 0)
			throw std::bad_cast();

		return result;
	}

class A
{
public:
	virtual ~A(){};
};

class B : public A
{
};

class C
{
};

int main()
{
	B b;
	A *a = &b;

	B *b2 = PtrCast<A, B>(a);
	try
	{
		C *c = PtrCast<A, C>(a);
	}
	catch(std::bad_cast bcex)
	{
		std::cout << bcex.what() << std::endl;
	}
		
	return EXIT_SUCCESS;
}
