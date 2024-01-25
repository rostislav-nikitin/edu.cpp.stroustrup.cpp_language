#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>

template<class T>
class Binder3
{
public:
	typedef T (*Func)(T a, T b, T c);
private:
	Func _f;
	T _b;
	T _c;
public:

	Binder3(Func f, T b, T c) : _b(b), _c(c), _f(f)
	{
	}

	T operator()(T a)
	{
		return _f(a, _b, _c);
	}
	
};

template<class T>
Binder3<T> bind3(typename Binder3<T>::Func f, T b, T c)
{
	return Binder3<T>(f, b, c);
}

int mul(int a, int b, int c)
{
	return a * b * c;
}

class RandomGenerator
{
	int _max_value;
public:
	RandomGenerator(int max_value) : _max_value(max_value) 
	{
		std::srand(time(0));
   	}

	int operator()()
	{
		return std::rand() % _max_value;
	}
};

void print(int x)
{
	std::cout << x << ", ";
}

int main()
{
	std::vector<int> nums(100);
	std::generate_n(nums.begin(), 100, RandomGenerator(20));
	std::for_each(nums.begin(), nums.end(), &print);
	std::cout << std::endl;

	std::vector<int> res(100);
	std::transform(nums.begin(), nums.end(), res.begin(), Binder3(&mul, 5, 10));
	std::for_each(res.begin(), res.end(), &print);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
