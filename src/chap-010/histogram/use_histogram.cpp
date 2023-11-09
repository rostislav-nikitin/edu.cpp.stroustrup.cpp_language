#include <iostream>

#include "use_histogram.h"

int main()
{
	using Histogram::Histogram;

	Histogram hist(1, 16);

	hist
		.set_count(1, 10)
		.set_count(2, 25);

	print(hist);
	
	return 0;
}
