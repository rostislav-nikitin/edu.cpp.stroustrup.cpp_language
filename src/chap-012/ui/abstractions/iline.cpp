#include "iline.hpp"

#include <iostream>

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

		bool ILine::intersects(IColorShape const *shape) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return shape->intersects(this);
		}

		bool ILine::intersects(ILine const *line) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ILine::intersects(ITriangle const *triangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ILine::intersects(IRectangle const *rectangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ILine::intersects(ICircle const *circle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
	}
}
