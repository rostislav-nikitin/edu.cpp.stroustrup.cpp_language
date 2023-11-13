#include "ixycoordinates.hpp"

namespace UI
{
	namespace Abstractions
	{
		IXYCoordinates::IXYCoordinates(Color color, Point position, float line_width) 
				: _color(color), _position(position), _line_width(line_width)
		{
		}
	}
}
