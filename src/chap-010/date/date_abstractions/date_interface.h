#ifndef DATE_INTERFACE_H
#define DATE_INTERFACE_H

namespace DateTime
{
	class IDate
	{
		public:
			enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

			class Invalid_Date_Exception { };

			static void set_default(int year, Month month, int day);

			virtual int day() const = 0;
			virtual Month month() const = 0;
			virtual int year() const = 0;

			virtual IDate& add_day(int days) = 0;
			virtual IDate& add_month(int months) = 0;
			virtual IDate& add_year(int years) = 0;
	};
}

#endif
