#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<char> vec;

	char value = 'a';
	while(value <= 'z')
		vec.push_back(value++);

	std::for_each(vec.begin(), vec.end(), [](char value) { std::cout << value;  });
	std::cout << std::endl;
	std::for_each(vec.rbegin(), vec.rend(), [](char value) { std::cout << value;  });

	return 0;
}
