#include <GLFW/glfw3.h>

#include "dot.hpp"

namespace UI
{
	namespace OpenGL
	{
		Dot::Dot(Color const color, Point const position, float size) : IDot(color, position), _size(size)
		{
		}

		void Dot::draw(IDrawContext *context)
		{
			glPointSize(GLfloat(_size));

			glBegin(GL_POINTS);

			glColor4f(GLfloat(_color.get_r()), GLfloat(_color.get_g()), GLfloat(_color.get_b()), GLfloat(_color.get_a()));
			glVertex3f(GLfloat(_position.get_x()), GLfloat(_position.get_y()), GLfloat(0.f));
 
			glEnd();
		}
	}
}
