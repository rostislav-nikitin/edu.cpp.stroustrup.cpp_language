#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void build_anagrams(std::vector<std::string> inseq)
{
	std::sort(inseq.begin(), inseq.end());
	int idx = 1;

	do
	{
		std::cout << idx++ << std::endl;
		std::for_each(inseq.begin(), inseq.end(), [](std::string const &word)
			{
				std::cout << word << " ";
			});
		std::cout << std::endl;
	}
	while(std::next_permutation(inseq.begin(), inseq.end()));
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "At leat one argumet is required." << std::endl;
		return EXIT_FAILURE;
	}

	const size_t MAX_SIZE = 16384;
	std::vector<std::string> invec;
	char buffer[MAX_SIZE];
	std::istringstream iss(argv[1]);
	while(true)
	{
		iss.getline(buffer, MAX_SIZE, ' ');
		if(!iss)
			break;
		invec.push_back(buffer);
	}

	build_anagrams(invec);
	

	return EXIT_SUCCESS;
}
