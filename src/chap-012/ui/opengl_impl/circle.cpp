#include "circle.hpp"

namespace UI
{
	namespace OpenGL
	{
		Circle::Circle(Color color, Point center, float radius) : ICircle(color, center, radius)
		{
		}

		void Circle::draw(IDrawContext *draw_context)
		{
			const int segments = 360;

			glBegin(GL_TRIANGLES);

			float step = 2 * M_PI / segments;
			for(float alpha = 0.0; alpha < 2 * M_PI - step / 2; alpha += step)
			{
				float x1 = _center.get_x() + _radius * cos(alpha);
				float y1 = _center.get_y() + _radius * sin(alpha);

				float x2 = _center.get_x() + _radius * cos(alpha + step);
				float y2 = _center.get_y() + _radius * sin(alpha + step);

				glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
				glVertex3f(_center.get_x(), _center.get_y(), 0.f);
				glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
				glVertex3f(x1, y1, 0.f);
				glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
				glVertex3f(x2, y2, 0.f);
			}

			glEnd();
		}
	}
}
