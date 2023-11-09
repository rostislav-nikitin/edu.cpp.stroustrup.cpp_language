#include <string>
#include <complex>
#include "definitions.h"

struct Date;

int day(Date *p);
double sqrt(double x)
{
	return x * x;
}

template<class T> T abs(T x);

typedef std::complex<short> Point;

class Point2 : public std::complex<short>
{
};


enum Beer {Carlsberg, Tuborg};


class User
{
private:
	std::string first_name;
	std::string last_name;

public:
	std::string get_first_name()
	{
		return first_name;
	}
	std::string get_last_name()
	{
		return last_name;
	}
};


void f()
{
}

int main()
{

	char ch2 = ch;

	return 0;
}
