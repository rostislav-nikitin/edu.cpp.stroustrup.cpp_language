#include "triangle.hpp"

namespace UI
{
	namespace OpenGL
	{
		Triangle::Triangle(Color color, Point point_lb, Point point_ct, Point point_rb) : ITriangle(color, point_lb, point_ct, point_rb)
		{
		}
			
		void Triangle::draw(IDrawContext *draw_context)
		{
			glBegin(GL_TRIANGLES);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_points[0].get_x(), _points[0].get_y(), 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_points[1].get_x(), _points[1].get_y(), 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_points[2].get_x(), _points[2].get_y(), 0.f);

			glEnd();
		}
	}
}
