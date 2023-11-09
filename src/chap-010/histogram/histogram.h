#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <map>

#include "histogram_abstractions.h"

namespace Histogram
{
	class Histogram : public IHistogram
	{
		private:
			int _min;
			int _max;

			std::map<int, int> _values;

			void validate(int value);

		public:
			Histogram(int min, int max);

			int min() const override;
			int max() const override;

			IHistogram &set_count(int value, int count) override;
			int get_count(int value) override;
	};

}

#endif
