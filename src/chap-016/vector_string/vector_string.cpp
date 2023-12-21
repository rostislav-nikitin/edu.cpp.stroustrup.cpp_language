#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::vector<std::string> fruits;

	std::string input;
	do
	{
		std::cout << "Enter fruit name=>";
		std::cin >> input;

		if(input == "END")
			break;

		fruits.push_back(input);
		std::cout << "input: " << input << std::endl;
	}
	while(true);

	// Sort fruits
	// std::sort(fruits.begin(), fruits.end());
	// Show all fruits
	//std::for_each(fruits.begin(), fruits.end(), [](std::string const value) { std::cout << value << std::endl; });
	// Show fruits starting by 'a'
	//std::for_each(fruits.begin(), fruits.end(), [](std::string const value) { if(value.front() == 'a'){ std::cout << value << std::endl; } });
	// Delete fruits starting by a
	/*
	std::sort(fruits.begin(), fruits.end());
	std::vector<std::string>::iterator first_a = std::find_if(fruits.begin(), fruits.end(), [](std::string const &value){ return value.front() == 'a'; });
	std::vector<std::string>::iterator last_a = std::find_if(first_a, fruits.end(), [](std::string const &value){ return value.front() != 'a';  });
	fruits.erase(first_a, last_a);
	std::for_each(fruits.begin(), fruits.end(), [](std::string const value) { std::cout << value << std::endl; });
	*/
	//Deleting fruits from black list
	std::vector<std::string> black_list {"lemon", "orange", "grape"};
	for(std::string const &fruit : black_list)
	{
		std::vector<std::string>::iterator item_to_erase = std::find(fruits.begin(), fruits.end(), fruit);
		if(item_to_erase != fruits.end())
		{
			fruits.erase(item_to_erase);
		}
	}
	std::for_each(fruits.begin(), fruits.end(), [](std::string const &value) { std::cout << value << std::endl; });
	
	return 0;
}
