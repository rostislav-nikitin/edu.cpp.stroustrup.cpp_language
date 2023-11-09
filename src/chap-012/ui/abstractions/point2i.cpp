#include "point2i.hpp"

namespace UI
{
	namespace Abstractions
	{
		Point2i::Point2i(int x, int y) : _x(x), _y(y) { }

		int Point2i::get_x() const
		{
			return _x;
		}
		int Point2i::get_y() const
		{
			return _y;
		}

		void Point2i::set_x(int x)
		{
			_x = x;
		}
		void Point2i::set_y(int y)
		{
			_y = y;
		}
	}
}
