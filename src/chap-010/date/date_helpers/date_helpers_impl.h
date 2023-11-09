#ifndef DATE_HELPERS_IMPL_H
#define DATE_HELPERS_IMPL_H

#include <string>

#include "../date_abstractions/date_interface.h"

namespace DateTime
{
	const int DAYS_IN_LEAP_YEAR = 366;
	const int DAYS_IN_NONLEAP_YEAR = 365;

	int days_in_month(IDate::Month const month, bool const leap_year);
	int days_in_year(int const year);
	bool leap(int const year);
	std::string to_string(IDate const &date);
	std::string to_string(IDate::Month const month);
}

#endif
