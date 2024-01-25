#include <iostream>
#include <string>
#include <algorithm>

void build_anagrams(std::string instr)
{
	std::sort(instr.begin(), instr.end());
	int idx = 1;

	do
	{
		std::cout << idx++ << "\t\t" << instr << std::endl;
	}
	while(std::next_permutation(instr.begin(), instr.end()));
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "At leat one argumet is required." << std::endl;
		return EXIT_FAILURE;
	}

	build_anagrams(argv[1]);

	return EXIT_SUCCESS;
}
