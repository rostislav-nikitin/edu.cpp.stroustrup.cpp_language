#include "date_helpers_impl.h"

int DateTime::days_in_month(DateTime::IDate::Month const month, bool const leap_year = false)
{
	switch(month)
	{
		case DateTime::IDate::Month::Feb:
			if(leap_year)
				return 29;
			else
				return 28;
			break;
		case DateTime::IDate::Month::Jan:
		case DateTime::IDate::Month::Mar:
		case DateTime::IDate::Month::May:
		case DateTime::IDate::Month::Jul:
		case DateTime::IDate::Month::Aug:
		case DateTime::IDate::Month::Oct:
		case DateTime::IDate::Month::Dec:
			return 31;
		case DateTime::IDate::Month::Apr:
		case DateTime::IDate::Month::Jun:
		case DateTime::IDate::Month::Sep:
		case DateTime::IDate::Month::Nov:
			return 30;

		default:
			throw DateTime::IDate::Invalid_Date_Exception();
	}
	return 0;
}

int DateTime::days_in_year(int const year)
{
	if(DateTime::leap(year))
		return DateTime::DAYS_IN_LEAP_YEAR;
	else
		return DateTime::DAYS_IN_NONLEAP_YEAR;
}

bool DateTime::leap(int const year)
{
	bool result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ;

	return result;
}

std::string DateTime::to_string(DateTime::IDate const &date)
{
	std::string result = std::to_string(date.day()) + "/" + DateTime::to_string(date.month()) + "/" + std::to_string(date.year());

	return result;
}

std::string DateTime::to_string(DateTime::IDate::Month const month)
{
	switch(month)
	{
		case DateTime::IDate::Month::Jan:
			return std::string("Jan");
		case DateTime::IDate::Month::Feb:
			return std::string("Feb");
		case DateTime::IDate::Month::Mar:
			return std::string("Mar");
		case DateTime::IDate::Month::Apr:
			return std::string("Apr");
		case DateTime::IDate::Month::May:
			return std::string("May");
		case DateTime::IDate::Month::Jun:
			return std::string("Jun");
		case DateTime::IDate::Month::Jul:
			return std::string("Jul");
		case DateTime::IDate::Month::Aug:
			return std::string("Aug");
		case DateTime::IDate::Month::Sep:
			return std::string("Sep");
		case DateTime::IDate::Month::Oct:
			return std::string("Oct");
		case DateTime::IDate::Month::Nov:
			return std::string("Nov");
		case DateTime::IDate::Month::Dec:
			return std::string("Dec");
		default:
			throw DateTime::IDate::Invalid_Date_Exception();
	}
}
