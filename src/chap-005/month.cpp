#include <iostream>

char const * month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int const month_days_count[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Month
{
	char const *name;
	unsigned short int days;
};

Month months[] = 
{
	{"Jan", 31},
	{"Feb", 28},
	{"Mar", 31},
	{"Apr", 30},
	{"May", 31},
	{"Jun", 30},
	{"July", 31},
	{"Aug", 31},
	{"Sep", 30},
	{"Oct", 31},
	{"Nov", 30},
	{"Dec", 31}
};

int main()
{
	std::cout << "TWO ARRAYS :: BY INDEX" << std::endl;
	for(unsigned int idx = 0; idx < 12; ++idx)
	{

		std::cout << month_names[idx] << "\tdays\t" << month_days_count[idx] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TWO ARRAYS :: BY PTR" << std::endl;
	char const **month_names_begin = month_names;
	char const **month_names_end = &month_names[11];
	int const *month_days_count_begin = month_days_count;

	while(month_names_begin != month_names_end)
	{
		std::cout << *month_names_begin << "\tdays\t" << *month_days_count_begin << std::endl;

		month_names_begin++;
		month_days_count_begin++;
	}
	std::cout << std::endl;

	std::cout << "STRUCT :: BY INDEX" << std::endl;
	for(unsigned int idx = 0; idx < 12; ++idx)
	{

		std::cout << months[idx].name << "\tdays\t" << months[idx].days << std::endl;
	}
	std::cout << std::endl;

	std::cout << "STRUCT :: BY PTR" << std::endl;
	Month *month_begin = months;
	Month *month_end = &months[11];

	while(month_begin != month_end)
	{

		std::cout << month_begin->days << "\tdays\t" << month_begin->days << std::endl;

		month_begin++;
	}

	return 0;
}
