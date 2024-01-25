#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<char> delimiters({' '});

	std::vector<std::string> words;
	std::vector<std::string> delims;
	// Read input data
	std::ifstream inf("./text.txt", std::ios_base::in);
	//  Detect max line size
	size_t BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];
	while(inf)
	{
		//get full line
		inf.getline(buffer, BUFFER_SIZE);
		std::string line(buffer);
		// iterate over words with delimiters
		std::string::iterator previous = line.begin();
		std::string::iterator delimiter = std::find_first_of(line.begin(), line.end(), delimiters.begin(), delimiters.end());
		while(delimiter != line.end())
		{
			std::string item(previous, delimiter);
			words.push_back(item);

			previous = delimiter + 1;
			delimiter = std::find_first_of(delimiter + 1, line.end(), delimiters.begin(), delimiters.end());
		}

		std::string item(previous, line.end());
		words.push_back(item);
		words.push_back("\n");
	}
	inf.close();

	// Process data
	std::vector<std::string>::iterator first_nonunique = std::unique(words.begin(), words.end());
	//std::for_each(words.begin(), first_nonunique, [](std::string const &s) { std::cout << s << std::endl; });

	// Write result data
	std::ofstream outf("./out.txt", std::ios_base::out);
	std::for_each(words.begin(), first_nonunique, [&outf](std::string const &s) 
	{
		outf.write(s.c_str(), s.size()); 
		if(!s.empty() && (s.back() != '\n'))
			outf.put(' ');
	});
	outf.close();
	
	return EXIT_SUCCESS;
}
