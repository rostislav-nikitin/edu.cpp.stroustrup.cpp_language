#include "date_unix_impl.h"

DateTime::Date::Date() : Date(default_date.day(), default_date.month(), default_date.year()) { }
DateTime::Date::Date(int day) : Date(day, default_date.month(), default_date.year()) { }
DateTime::Date::Date(int day, Month month) : Date(day, month, default_date.year()) { }
DateTime::Date::Date(int day, Month month, int year)
{
	_date = get_secs(day, month, year);
}

int DateTime::Date::get_secs(int day, Month month, int year)
{
	int result = 0;

	for(int cur_year = 1970; cur_year < year; cur_year++)
	{
		result += (DateTime::leap(cur_year) ? DateTime::DAYS_IN_LEAP_YEAR : DAYS_IN_NONLEAP_YEAR) * 24 * 60 * 60;
	}

	for(int cur_month = 1; cur_month < static_cast<int>(month); cur_month++)
	{
		result += DateTime::days_in_month(static_cast<DateTime::Date::Month>(month), DateTime::leap(year)) * 24 * 60 * 60;
	}

	for(int cur_day = 1; cur_day <= day; cur_day++)
	{
		result += 1 * 24 * 60 * 60;
	}

	return result;
}

int DateTime::Date::day() const
{
	int all_days = days();
	int year = DateTime::Date::get_year(&all_days);
	DateTime::Date::Month month = DateTime::Date::get_month(&all_days, DateTime::leap(year));
	int day = all_days;

	return day;
}

DateTime::Date::Month DateTime::Date::month() const
{
	int all_days = days();
	int year = DateTime::Date::get_year(&all_days);
	DateTime::Date::Month month = DateTime::Date::get_month(&all_days, DateTime::leap(year));

	return month;
}

DateTime::Date::Month DateTime::Date::get_month(int *days, int leap_year)
{
	DateTime::Date::Month cur_month = DateTime::Date::Month::Jan;

	int days_in_cur_month = DateTime::days_in_month(cur_month, leap_year);
	while(*days > days_in_cur_month)
	{
		cur_month = static_cast<DateTime::Date::Month>(static_cast<int>(cur_month) + 1);
		*days -= days_in_cur_month;
		days_in_cur_month = DateTime::days_in_month(cur_month, leap_year);
	}

	return cur_month;
}

int DateTime::Date::year() const
{
	int all_days = days();
	int year = DateTime::Date::get_year(&all_days);

	return year;
}

int DateTime::Date::days() const
{
	int all_days = _date / 60 / 60 / 24;

	return all_days;
}

int DateTime::Date::get_year(int *days)
{
	int cur_year = 1970;
	int days_in_cur_year = DateTime::days_in_year(cur_year);
	while(*days > days_in_cur_year)
	{
		cur_year++;
		*days -= days_in_cur_year;
		days_in_cur_year = DateTime::days_in_year(cur_year);
	}

	return cur_year;
}

DateTime::Date &DateTime::Date::add_day(int days)
{
	return *this;
}

DateTime::Date &DateTime::Date::add_month(int months)
{
	return *this;
}

DateTime::Date &DateTime::Date::add_year(int years)
{
	return *this;
}

DateTime::Date DateTime::Date::default_date = Date(1, Jan, 1970);

void DateTime::Date::set_default(int day, Month month, int year)
{
	default_date._date = get_secs(day, month, year);
}
