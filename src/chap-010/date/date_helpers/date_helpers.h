#ifndef DATE_HELPERS_H
#define DATE_HELPERS_H

#include <string>

#include "../date_abstractions/date_interface.h"

namespace DateTime
{
	extern std::string to_string(IDate const &date);
}

#endif
