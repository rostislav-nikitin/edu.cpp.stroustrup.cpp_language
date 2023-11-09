#include "histogram.h"

namespace Histogram
{
	void Histogram::validate(int value)
	{
		if(value < _min || value > _max)
			throw Out_of_range_exception();
	}

	Histogram::Histogram(int min = 0, int max = 255) : _min(min), _max(max)
	{
		if(_min > _max)
			throw Out_of_range_exception();

		for(int value = _min; value < _max; value++)
		{
			_values[value] = 0;
		}
	}

	int Histogram::min() const
	{
		return _min;
	}

	int Histogram::max() const
	{
		return _max;
	}

	IHistogram &Histogram::set_count(int value, int count)
	{
		validate(value);
		
		_values[value] = count;

		return *this;
	}

	int Histogram::get_count(int value)
	{
		validate(value);

		return _values[value];
	}
}
