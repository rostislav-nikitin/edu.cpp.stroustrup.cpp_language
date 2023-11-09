#include "date_mdy_impl.h"

DateTime::Date::Date() : Date(default_date.day(), default_date.month(), default_date.year()) { }
DateTime::Date::Date(int day) : Date(day, default_date.month(), default_date.year()) { }
DateTime::Date::Date(int day, Month month) : Date(day, month, default_date.year()) { }
DateTime::Date::Date(int day, Month month, int year) : _day(day), _month(month), _year(year) { }

int DateTime::Date::day() const 
{
	return _day;
}

DateTime::Date::Month DateTime::Date::month() const
{
	return _month;
}

int DateTime::Date::year() const
{
	return _year;
}

DateTime::Date &DateTime::Date::add_day(int days)
{
	while(days > 0)
	{
		if(_day == 1 && _month == DateTime::Date::Month::Jan && days >= DateTime::days_in_year(_year))
		{
			days -= DateTime::days_in_year(_year);
			_year++;
			continue;
		}

		if(days >= DateTime::days_in_month(_month, DateTime::leap(_year)) - _day + 1)
		{
			days -= DateTime::days_in_month(_month, DateTime::leap(_year)) - _day + 1;
			if(_month == DateTime::Date::Month::Dec)
			{
				_month = DateTime::Date::Month::Jan;
				_year++;
				_day = 1;
			}
			else
			{
				_month = static_cast<DateTime::Date::Month>(static_cast<int>(_month) + 1);
				_day = 1;
			}
			continue;
		}

		_day += days;
		days = 0;

	}

	return *this;
}

DateTime::Date &DateTime::Date::add_month(int months)
{
	if(months == 0)
		return *this;

	int years_to_add = (_year * 12 + _month + months) / 12 - _year; 
	DateTime::Date::Month month_to_set = static_cast<DateTime::Date::Month>((_year * 12 + _month + months) % 12);

	bool leap = DateTime::leap(_year + years_to_add);
	int days = DateTime::days_in_month(month_to_set, leap);

	if(_day > days)
	{
		_day = _day - days;
	}
	_month = month_to_set;
	add_year(years_to_add);
	
	return *this;
}

DateTime::Date &DateTime::Date::add_year(int years)
{
	if(years == 0)
		return *this;

	if(_day == 29 && _month == 2 && !DateTime::leap(_year + years))
	{
		_day = 1;
		_month = DateTime::Date::Month::Mar;
	}

	_year += years;

	return *this;
}

DateTime::Date DateTime::Date::default_date = Date(1, Jan, 1970);

void DateTime::Date::set_default(int day, Month month, int year)
{
	default_date._day = day;
	default_date._month = month;
	default_date._year = year;
}
