#include "irectangle.hpp"

namespace UI
{
	namespace Abstractions
	{
		IRectangle::IRectangle(Color color, Point position, float width, float height) 
				: IColorShape(color), _position(position), _width(width), _height(height)
		{
		}

	}
}
