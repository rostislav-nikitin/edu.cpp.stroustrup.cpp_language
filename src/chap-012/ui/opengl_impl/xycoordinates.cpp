#include "xycoordinates.hpp"
#include <iostream>

namespace UI
{
	namespace OpenGL
	{
		XYCoordinates::XYCoordinates(Color color, Point position, float line_width)
			: IXYCoordinates(color, position, line_width)
		{
			//std::cout << "XYCoodrinates()" << std::endl;
			append(new Line(color, Point(-1.f, position.get_y()), Point(1.f, position.get_y()), line_width));
			append(new Line(color, Point(position.get_x(), -1.f), Point(position.get_x(), 1.f), line_width));
		}
	}
}
