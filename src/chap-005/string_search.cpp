#include <iostream>

std::string source = "xabaacbaxabb";

unsigned int calculate(std::string source, std::string search)
{
	unsigned int result = 0;
	size_t current_position = 0;
	while((current_position = source.find(search, current_position)) != std::string::npos)
	{
		current_position += search.size();
		result++;
	 }

	return result;
}

unsigned int c_calculate(char const source[], char const search[], size_t search_size)
{
	unsigned int result = 0;
	char const *source_begin = source;
	while(*source_begin != '\0')
	{
		bool found = true;
		for(size_t idx = 0; found && (idx < search_size); ++idx)
		{
			found &= source_begin[idx] != '\0' && source_begin[idx] == search[idx];
		}

		if(found)
			result++;

		source_begin++;
	}

	return result;
}

int main()
{
	std::string search = "ab";
	std::cout << "C++ string:\t" << "'" << search << "' found " << calculate(source, search) << " times" << std::endl;
	std::cout << "C string:\t" << "'" << search << "' found " << c_calculate(source.c_str(), search.c_str(), search.size()) << " times" << std::endl;
	return 0;
}
