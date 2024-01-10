#include <iostream>
#include <map>
#include <bitset>

int main()
{
	std::map<std::string, std::bitset<32>> visit_list;

	visit_list["John Doe"] = std::bitset<32>(0b010101010101011111);
	visit_list["Peter Valda"] = std::bitset<32>(0b111111111111);
	visit_list["Sobak"] = std::bitset<32>(0b000000000111);

	for(std::map<std::string, std::bitset<32>>::iterator it = visit_list.begin(); it != visit_list.end(); ++it)
	{
		int acc = 0;
		for(int idx = 0; idx < 12; ++idx)
			if(it->second.test(idx))
				++acc;

		if(acc == 12)
			std::cout << it->first << "\t\t\tA" << std::endl;
		else if(acc >= 8)
			std::cout << it->first << "\t\t\t8" << std::endl;
	}

	return EXIT_SUCCESS;
}
