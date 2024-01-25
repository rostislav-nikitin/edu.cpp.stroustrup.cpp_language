#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> origin({3, 5455, 3, 2243, 53, 123, 12, 45, 4564, 21});

	std::cout << "origin" << std::endl;
	std::for_each(origin.begin(), origin.end(), [](int number) { std::cout << number << ", ";  });
	std::cout << std::endl << std::endl;

	std::cout << "list::sort" << std::endl;
	std::list<int> sorted;
	std::copy(origin.begin(), origin.end(), std::back_inserter(sorted));
	sorted.sort();
	std::for_each(sorted.begin(), sorted.end(), [](int number) { std::cout << number << ", ";  });
	std::cout << std::endl << std::endl;
		
	std::cout << "list::unique" << std::endl;
	sorted.unique();
	std::for_each(sorted.begin(), sorted.end(), [](int number) { std::cout << number << ", ";  });
	std::cout << std::endl << std::endl;
		
	std::cout << "list::reverse" << std::endl;
	sorted.reverse();
	std::for_each(sorted.begin(), sorted.end(), [](int number) { std::cout << number << ", ";  });
	std::cout << std::endl << std::endl;

	std::cout << "list::merge" << std::endl;
	std::list<int> another({2, 8, 16, 32, 64, 128, 256, 512, 1024});
	origin.merge(another);
	std::for_each(origin.begin(), origin.end(), [](int number) { std::cout << number << ", ";  });
	std::cout << std::endl << std::endl;

	return EXIT_SUCCESS;
}
