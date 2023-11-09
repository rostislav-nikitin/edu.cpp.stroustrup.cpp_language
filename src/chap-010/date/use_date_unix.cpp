#include <iostream>

#include "date_abstractions/date_abstractions.h"
#include "date_unix/date_unix_impl.h"

#include "use_date_unix_body.h"

int main()
{
	std::cout << "USE DATE" << std::endl;
	DateTime::Date::set_default(29, DateTime::Date::Month::Feb, 2024);

	DateTime::Date date_one {10, DateTime::Date::Month::Jan, 2023};

	run(date_one);

	return 0;
}
