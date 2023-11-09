#ifndef HISTOGRAM_ABSTRACTIONS_H
#define HISTOGRAM_ABSTRACTIONS_H

namespace Histogram
{
	class IHistogram
	{
		public:
			class Out_of_range_exception {};

			virtual int min() const = 0;
			virtual int max() const = 0;

			virtual IHistogram &set_count(int value, int count) = 0;
			virtual int get_count(int value) = 0;
	};
}

#endif
