#include "igrid.hpp"

namespace UI
{
	namespace Abstractions
	{
		IGrid::IGrid(Color color, Point position, float width, float height, float line_width, float step, Color sub_color, int sub_divisions) 
			: _color(color),  _position(position), _width(width), _height(height), _line_width(line_width),
			_step(step), _sub_color(sub_color), _sub_divisions(sub_divisions)
		{
		}
	}
}
