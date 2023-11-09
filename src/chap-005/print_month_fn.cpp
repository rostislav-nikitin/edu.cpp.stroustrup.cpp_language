#include <iostream>

char const * month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
unsigned int const month_names_count = 12;

void print(char const * month_names[], unsigned int const month_names_count)
{
	for(unsigned int idx = 0; idx < month_names_count; ++idx)
	{
		std::cout << month_names[idx] << std::endl;
	}
}


int main()
{
	print(month_names, month_names_count);

	return 0;
}
