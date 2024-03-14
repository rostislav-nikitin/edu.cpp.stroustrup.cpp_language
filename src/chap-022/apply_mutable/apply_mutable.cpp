#include <iostream>
#include <valarray>

template<class T>
class Apply
{
	T (*_fn) (T const &value1, T const &value2);
	T _value;
public:
	Apply(T (*fn)(T const &value1, T const &value2), T value);

	T operator()(T value)
	{
		return _fn(_value, value);
	}
};


template<class T>
Apply<T>::Apply(T (*fn)(T const &value1, T const &value2), T value) : _fn(fn), _value(value)
{
}


template<class T>
void apply_fno(std::valarray<T> &va, Apply<T> fno)
{
	for(size_t idx = 0; idx < va.size(); ++idx)
	{
		va[idx] = fno(va[idx]);
	}
}

template<class T>
T addition(T const &a, T const &b)
{
	return a + b;
}

template<class T>
std::ostream &operator<<(std::ostream &stream, std::valarray<T> const &va)
{
	for(size_t idx = 0; idx < va.size(); ++idx)
	{
		if(idx > 0)
			stream << ", ";
		
		stream << va[idx];
	}

	return stream;
}

int main()
{
	int v[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::valarray<int> va(v, 10);

	apply_fno(va, Apply(addition, 20));

	std::cout << va << std::endl;	

	return EXIT_SUCCESS;
}
