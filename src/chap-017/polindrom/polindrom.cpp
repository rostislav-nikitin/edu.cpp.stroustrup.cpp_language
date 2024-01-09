#include <iostream>
#include <string>
#include <deque>
#include <vector>

template<class T, class U>
bool IsPolyndrom(T container)
{
		static_assert(std::is_same_v<typename T::value_type, U>);

		std::deque<U> fw(container.begin(), container.end());
		std::deque<U> bk(container.rbegin(), container.rend());

		while(!fw.empty())
		{
			if(fw.back() != bk.back())
				return false;

			fw.pop_back();
			bk.pop_back();
		}

		return true;
}

int main()
{
	std::cout << "kazak=" << IsPolyndrom<std::string, char>("kazak") << std::endl;
	
	std::cout << "pes=" << IsPolyndrom<std::string, char>("pes") << std::endl;
	std::cout << "100001=" << IsPolyndrom<std::string, char>(std::to_string(100001)) << std::endl;
	std::cout << "1000001=" << IsPolyndrom<std::string, char>(std::to_string(1000001)) << std::endl;
	std::cout << "11000001=" << IsPolyndrom<std::string, char>(std::to_string(11000001)) << std::endl;

	std::vector<std::string> sentance {"pes", "da", "pes"};
	std::cout << "pes da pes=" << IsPolyndrom<std::vector<std::string>, std::string>(sentance) << std::endl;
	std::vector<std::string> sentance2 {"pes", "da", "ne", "pes"};
	std::cout << "pes da ne pes=" << IsPolyndrom<std::vector<std::string>, std::string>(sentance2) << std::endl;
	
	return EXIT_SUCCESS;
}
