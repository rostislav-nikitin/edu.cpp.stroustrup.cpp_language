#include "line.hpp"
#include <iostream>

#include <GLFW/glfw3.h>

namespace UI
{
	namespace OpenGL
	{
		void Line::draw(IDrawContext *draw_context)
		{
			//std::cout << "Line should be drawing there" << std::endl;

			glLineWidth(_size);
 
			glBegin(GL_LINES);
			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_start_position.get_x(), _start_position.get_y(), 0.f);
			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_end_position.get_x(), _end_position.get_y(), 0.f);

			glEnd();
		}
	}
}
