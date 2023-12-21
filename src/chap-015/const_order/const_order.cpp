#include <cstdlib>
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::cout << typeid(*this).name() << std::endl;
	}

	virtual ~A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class B : public A
{
public:
	B()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::cout << typeid(*this).name() << std::endl;
	}

	virtual ~B() override
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::cout << typeid(*this).name() << std::endl;
	}

	virtual ~C() override
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

int main()
{
	C c;
	std::cout << "test" << std::endl;

	return EXIT_SUCCESS;
}
