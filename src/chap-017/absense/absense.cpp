#include <iostream>
#include <map>
#include <bitset>

int main()
{
	std::map<std::string, std::bitset<32>> visit_list;

	visit_list["John Doe"] = std::bitset<32>(0b010101010101);
	visit_list["Peter Valda"] = std::bitset<32>(0b111111111111);

	for(std::map<std::string, std::bitset<32>>::iterator it = visit_list.begin(); it != visit_list.end(); ++it)
	{
		int acc = 0;
		for(int idx = 0; idx < 12; ++idx)
			if(it->second.test(idx))
				++acc;

		if(acc == 12)
			std::cout << it->first;
	}

	return EXIT_SUCCESS;
}
