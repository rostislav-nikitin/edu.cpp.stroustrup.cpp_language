#include <iostream>

class A
{
private:
	int _value;
public:
	A(int value);
	~A();
	int value() const;
};

A::A(int value)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	_value = value;
}
A::~A()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
int A::value() const
{
	return _value;
}

template<typename T>
struct Holder
{
	T* value;
	int refs;

	Holder(T *value);
	~Holder();
};

template<typename T>
Holder<T>::Holder(T *value) : value(value), refs(1) { }

template<typename T>
Holder<T>::~Holder()
{
	delete value;
}

template<>
Holder<char>::~Holder()
{
	delete[] value;
}

template<typename T>
class Shared_ptr
{
private:
	Holder<T> *_holder;

public:
	Shared_ptr(T *value);
	Shared_ptr(Shared_ptr<T> &ptr);
	Shared_ptr(Shared_ptr<T> const &ptr);
	~Shared_ptr();
	T *operator->();
	T &operator*();
};

template<typename T>
Shared_ptr<T>::Shared_ptr(T *value) 
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	_holder = new Holder<T>(value);
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T> &ptr)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	_holder = ptr._holder;
	_holder->refs++;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T> const &ptr)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	_holder = ptr._holder;
	_holder->refs++;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	_holder->refs--;
	if(_holder->refs == 0)
		delete _holder;
}

template<typename T>
T* Shared_ptr<T>::operator->()
{
	return _holder->value;
}

template<typename T>
T& Shared_ptr<T>::operator*()
{
	return *_holder->value;
}

void f(Shared_ptr<A> ptr)
{
	std::cout << "f :" << ptr->value() << std::endl;
}

int main()
{
	A a(10);
	std::cout << "a: " << a.value() << std::endl;

	Shared_ptr<A> ptr_a = Shared_ptr<A>(new A(50));
	std::cout << "ptr_a->value(): " << ptr_a->value() << std::endl;
	f(ptr_a);

	A &a2 = *ptr_a;
	std::cout << "*ptr_a: " << ptr_a->value() << std::endl;

	char *cstr = new char[] {"Hello, world"};
	Shared_ptr<char> cstr_ptr = Shared_ptr<char>(cstr);
	std::cout << "cstr_ptr: " << cstr_ptr.operator->() << std::endl;

	return 0;
}
