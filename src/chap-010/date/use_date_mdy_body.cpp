#include <iostream>

#include "use_date_mdy_body.h"

void run(DateTime::IDate &date)
{
	std::cout << "Date one: " << DateTime::to_string(date) << std::endl;
	std::cout << "Date one + 10 years: " << DateTime::to_string(date.add_year(10)) << std::endl;
	std::cout << "Date one + 24 month: " << DateTime::to_string(date.add_month(24)) << std::endl;
	std::cout << "Date one + 25 month: " << DateTime::to_string(date.add_month(25)) << std::endl;
	std::cout << "Date one + 5 days: " << DateTime::to_string(date.add_day(5)) << std::endl;
	std::cout << "Date one + 26 days: " << DateTime::to_string(date.add_day(26)) << std::endl;
	std::cout << "Date one + 400 days: " << DateTime::to_string(date.add_day(400)) << std::endl;
	std::cout << "Date one + 366 days: " << DateTime::to_string(date.add_day(366)) << std::endl;
}
