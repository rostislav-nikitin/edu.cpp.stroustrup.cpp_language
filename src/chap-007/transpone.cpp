#include <vector>
#include <iostream>

const int Array_Height = 2;
const int Array_Width = 3;

std::vector<std::vector<int>> transpone(std::vector<std::vector<int>> array)
{
	int rows = array.size();
	if(rows == 0)
		return std::vector<std::vector<int>>(0);

	int cols = array[0].size();
	if(cols == 0)
		return std::vector<std::vector<int>>(0);


	std::vector<std::vector<int>> result;
	for(int idx = 0; idx < cols; idx++)
	{
		std::vector<int> row_array;
		for(int jdx = 0; jdx < rows; jdx++)
		{
			row_array.push_back(array[jdx][idx]);
		}
		result.push_back(row_array);
	}

	return result;
}

void print_array(std::vector<std::vector<int>> array)
{
	for(int idx = 0; idx < array.size(); idx++)
	{
		for(int jdx = 0; jdx < array[idx].size(); jdx++)
		{
			std::cout << array[idx][jdx] << "\t";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "Initial matrix" << std::endl;
	std::vector<std::vector<int>> array = { {1, 2, 3}, {3, 4, 5}};
	print_array(array);


	std::cout << std::endl;
	std::cout << "Transponed matrix" << std::endl;
	std::vector<std::vector<int>> inverted = transpone(array);
	print_array(inverted);

	return 0;
}
