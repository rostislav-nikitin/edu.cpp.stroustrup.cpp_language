#include "icircle.hpp"

#include <iostream>

namespace UI
{
	namespace Abstractions
	{
		ICircle::ICircle(Color color, Point center, float radius) 
				: IColorShape(color), _center(center), _radius(radius)
		{
		}

		bool ICircle::intersects(IColorShape const *shape) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return shape->intersects(this);
		}

		bool ICircle::intersects(ILine const *line) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ICircle::intersects(ITriangle const *triangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ICircle::intersects(IRectangle const *rectangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool ICircle::intersects(ICircle const *circle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
	}
}
