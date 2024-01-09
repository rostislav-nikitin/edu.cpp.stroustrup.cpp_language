#include <iostream>

#include "column.hpp"

int main()
{
	using Solatire::Engine::Column;

	Column<int> column;
	column.push_invisible(14);
	column.push_visible(20);
	column.push_visible(30);


	std::cout << column.invisible_top() << std::endl;
	std::cout << column.visible_top() << std::endl;

	for(int idx = 0; idx < column.visible_size(); ++idx)
	{
		std::cout << column[idx] << std::endl;
	}

	column.pop_invisible();
	column.pop_visible();
	column.pop_visible();


	return EXIT_SUCCESS;
}
