#include <iostream>
#include <string>

template<class Itor, class Predicate>
Itor find_if(Itor begin, Itor end, Predicate predicate)
{
	for(Itor it = begin; it != end; ++it)
	{
		if(predicate(*it))
			return it;
	}

	return end;
}

template<class Itor, class T>
Itor find(Itor begin, Itor end, T const &value)
{
	return find_if(begin, end, [&value](T item) { return item == value; });
}

int main()
{
	std::string s = "Hello world";

	std::string::iterator it = find_if(s.begin(), s.end(), [](char c) { return c == 'w'; });
	if(it != s.end())
	{
		std::cout << *it << std::endl;
	}
	else
		std::cout << "Not found" << std::endl;

	std::string::iterator itf = find(s.begin(), s.end(), 'd');
	if(itf != s.end())
	{
		std::cout << *itf << std::endl;
	}
	else
		std::cout << "Not found" << std::endl;
	
	return 0;
}
