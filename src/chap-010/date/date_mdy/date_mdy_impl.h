#ifndef DATE_MDY_IMPL_H
#define DATE_MDY_IMPL_H

#include <string>
#include "../date_abstractions/date_interface.h"
#include "../date_helpers/date_helpers_impl.h"

namespace DateTime
{
	class Date : public IDate
	{
		private:
			static Date default_date;

			int _day;
			Month _month;
			int _year;

		public:
			static void set_default(int year, Month month, int day);

			Date();
			Date(int day);
			Date(int day, Month month);
			Date(int day, Month month, int year);

			int day() const override;
			Month month() const override;
			int year() const override;

			Date& add_day(int days) override;
			Date& add_month(int months) override;
			Date& add_year(int years) override;
	};
}

#endif
