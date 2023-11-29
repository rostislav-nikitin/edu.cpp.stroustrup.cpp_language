//#include <iostream>

template<class T>
class Base
{
public:
	Base()
	{
//		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	T& self()
	{
		return reinterpret_cast<T&>(*this);
	}

	T der()
	{
		return self();
	}
};

class Derived : public Base<Derived>
{
public:	
	Derived() : Base()
	{
//		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

int main()
{
	Derived d;
	d.self();
	d.der();

	//std::cout << "main" << std::endl;
	return 0;
}
