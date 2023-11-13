#include "grid.hpp"

#include <iostream>

namespace UI
{
	namespace OpenGL
	{
		Grid::Grid(Color color, Point position, float width, float height, float line_width, float step, Color sub_color, int sub_divisions) 
				: IGrid(color, position, width, height, line_width, step, sub_color, sub_divisions)
		{
			for(float x = position.get_x(); x <= position.get_x() + width + step / 10.f; x+=step)
			{
				if((sub_divisions > 0) && (x > position.get_x()))
				{
					float sub_step = step / (sub_divisions);
					float sub_x = x - step + sub_step;

					for(int sub_division = 0; sub_division < sub_divisions ; sub_division++, sub_x+=sub_step)
					{
						append(new Line(sub_color, Point(sub_x, position.get_y()), Point(sub_x, position.get_y() + height), line_width));
					}
				}
				append(new Line(color, Point(x, position.get_y()), Point(x, position.get_y() + height), line_width));
			}
			
			for(float y = position.get_y(); y <= position.get_y() + height + step / 10.f; y+=step)
			{
				if((sub_divisions > 0) && (y > position.get_y()))
				{
					float sub_step = step / (sub_divisions);
					float sub_y = y - step + sub_step;

					for(int sub_division = 0; sub_division < sub_divisions ; sub_division++, sub_y+=sub_step)
					{
						append(new Line(sub_color, Point(position.get_x(), sub_y), Point(position.get_x() + width, sub_y), line_width));
					}
				}
				append(new Line(color, Point(position.get_x(), y), Point(position.get_x() + width, y), line_width));
			}
		}
	}
}
