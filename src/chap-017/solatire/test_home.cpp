#include <iostream>

#include "home.hpp"

void show(Solatire::Engine::Home<int> &home)
{
	for(int idx = 0; idx < home.size(); ++idx)
	{
		int item = home.top();
		std::cout << item << std::endl;

		home.pop();
		home.push(item);
	}
}

int main()
{
	using Solatire::Engine::Home;

	Home<int> home;
	home.push(10);
	home.push(20);
	home.push(30);

	show(home);
	show(home);

	
	return EXIT_SUCCESS;
}
