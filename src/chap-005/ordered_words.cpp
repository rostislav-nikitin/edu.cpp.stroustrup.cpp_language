#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

//typedef unsigned int uin32_t;

std::vector<std::string> words;



bool add_word(std::string &word)
{
	for(uint32_t idx = 0; idx < words.size(); ++idx)
	{
		if(words[idx] == word)
			return false;
	}
	words.push_back(word);

	return true;
}

void print(std::vector<std::string> &items)
{

	std::vector<std::string>::iterator it_begin = items.begin();
	while(it_begin != items.end())
		std::cout << *it_begin++ << std::endl;
}

int main()
{

	// INPUT WORDS
	std::string user_input;
	while(getline(std::cin, user_input) && !user_input.empty())
	{
		add_word(user_input);
	}


	std::cout << "UNORDERED WORDS" << std::endl;
	print(words);

	std::cout << "ORDERED WORDS" << std::endl;
	std::sort(words.begin(), words.end());
	print(words);

	return 0;
}
