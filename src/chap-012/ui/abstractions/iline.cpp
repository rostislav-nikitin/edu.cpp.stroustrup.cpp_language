#include "iline.hpp"

namespace UI
{
	namespace Abstractions
	{
		ILine::ILine(Color const color, Point start_position, Point end_position, float size) : 
				IColorShape(color), _start_position(start_position), _end_position(end_position), _size(size)
		{
		}

		Point ILine::get_start_positon()
		{
			return _start_position;
		}

		Point ILine::get_end_position()
		{
			return _end_position;
		}

		float ILine::get_size()
		{
			return _size;
		}
	}
}
