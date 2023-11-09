#include <iostream>

#include "date_abstractions/date_abstractions.h"
#include "date_mdy/date_mdy_impl.h"

#include "use_date_mdy_body.h"

int main()
{
	std::cout << "USE DATE" << std::endl;
	DateTime::Date::set_default(29, DateTime::IDate::Month::Feb, 2024);
	DateTime::Date date_one;

	run(date_one);

	return 0;
}
