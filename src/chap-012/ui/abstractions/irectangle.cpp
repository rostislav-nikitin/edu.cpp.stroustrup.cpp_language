#include "irectangle.hpp"

#include <iostream>

namespace UI
{
	namespace Abstractions
	{
		IRectangle::IRectangle(Color color, Point position, float width, float height) 
				: IColorShape(color), _position(position), _width(width), _height(height)
		{
		}

		bool IRectangle::intersects(IColorShape const *shape) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return shape->intersects(this);
		}

		bool IRectangle::intersects(ILine const *line) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool IRectangle::intersects(ITriangle const *triangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool IRectangle::intersects(IRectangle const *rectangle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool IRectangle::intersects(ICircle const *circle) const
		{
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
	}
}
