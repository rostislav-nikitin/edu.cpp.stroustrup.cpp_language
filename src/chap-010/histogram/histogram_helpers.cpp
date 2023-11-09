#include <iostream>

#include "histogram_helpers.h"

void Histogram::print(Histogram::IHistogram &histogram)
{
	for(int value = histogram.min(); value <= histogram.max(); value++)
	{
		std::cout << "histogram[" << value << "] = " << histogram.get_count(value) << std::endl;
	}
}

