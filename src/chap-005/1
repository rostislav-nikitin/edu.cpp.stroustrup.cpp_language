#include <iostream>

struct Date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

Date create_date(unsigned int year, unsigned int month, unsigned int day)
{
	Date result{year, month, day};

	return result;
}

Date input_date()
{
	std::cout << "Enter year: ";
	unsigned int year;
	std::cin >> year;
	std::cout << "Enter month: ";
	unsigned int month;
	std::cin >> month;
	std::cout << "Enter day: ";
	unsigned int day;
	std::cin >> day;

	Date result = create_date(year, month, day);
	return result;
}

void print_date(Date &date)
{
	std::cout << date.day << "/" << date.month << "/" << date.year << std::endl;
}

int main()
{
	Date date = input_date();
	std::cout << "Date is ";
	print_date(date);

	return 0;
}
