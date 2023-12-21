#include <iostream>

template<class B, class D>
struct is_base
{
	void check()
	{
		D *d;
		B *b = d;
	}

	is_base()
	{
		void (is_base::*fptr)() = &is_base::check;
	}

};

class A
{
public:
	~A(){}	
};

class B : public A
{
};

class C
{
public:
	~C(){}
};


template<class T, class R>
	R* dcast(T* t)
	{
		bool downcast = typeid(T).before(typeid(R));
		bool upcast = !downcast;
		try
		{
			//R* ret = t;
			return static_cast<R*>(t);
		}
		catch(...)
		{
			return 0;
		}
	}

template<class T>
	struct is_ptr
	{
		static bool const value = false;
	};

template<class T>
	struct is_ptr<T *>
	{
		static bool const value = true;
	};

template<bool, class T>
	struct enable_if_true
	{
	};
	

template<class T>
	struct enable_if_true<true, T>
	{
		using type = T;
	};

template<class B, class D>
	struct is_base_for
	{
		static bool const value = false;
		static D *convert(B *base) 
		{
			return nullptr;
		}
		
	};

template<class B, class D>
	struct is_base_for<B*, D*>
	{
		static D * convert(B *base)
		{ 
				return static_cast<D *>(base); 
		}
		static bool const value = true;
	};

//SIGNED
template<class T>
	struct is_integral_type
	{
		static int const value = false;
	};

template<>
	struct is_integral_type<signed char>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<signed short int>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<signed int>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<signed long int>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<signed long long>
	{
		static int const value = true;
	};
//UNSIGNED
template<>
	struct is_integral_type<unsigned char>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<unsigned short int>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<unsigned int>
	{
		static int const value = true;
	};

template<>
	struct is_integral_type<unsigned long int>
	{
		static int const value = true;
	};

int main()
{
	is_base<A, B>();
	//is_base<B, A>();
	B b;
	A *a = &b;

	A *a2 = dcast<B, A>(&b);
	B *b2 = dcast<A, B>(a);

	//C *c = dcast<A, C>(a);
	
	std::cout << typeid(A).before(typeid(C)) << std::endl;

	std::cout << is_ptr<A *>::value << std::endl;

	std::cout << is_base_for<A*, C*>::value << std::endl;
	//is_base_for<A*, C*>::convert(b2);
	
	std::cout << typeid(enable_if_true<true, A>::type).name() << std::endl;

	std::cout << is_integral_type<int>::value << std::endl;
	std::cout << is_integral_type<float>::value << std::endl;
	
	return EXIT_SUCCESS;
}
