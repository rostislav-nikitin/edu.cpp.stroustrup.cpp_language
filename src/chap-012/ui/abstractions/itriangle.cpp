#include "itriangle.hpp"

#include <iostream>

namespace UI
{
	namespace Abstractions
	{
		ITriangle::ITriangle(Color color, Point point_lb, Point point_ct, Point point_rb) : IColorShape(color), _points{point_lb, point_ct, point_rb}
		{
		}

		bool ITriangle::intersects(IColorShape const *shape) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return shape->intersects(this);
		}

		bool ITriangle::intersects(ILine const *line) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
			
		bool ITriangle::intersects(ITriangle const *triangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ITriangle::intersects(IRectangle const *rectangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ITriangle::intersects(ICircle const *circle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
	}
}
