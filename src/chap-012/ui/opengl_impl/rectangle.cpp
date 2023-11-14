#include "rectangle.hpp"

namespace UI
{
	namespace OpenGL
	{
		Rectangle::Rectangle(Color color, Point position, float width, float height) : IRectangle(color, position, width, height)
		{
		}

		void Rectangle::draw(IDrawContext *draw_context)
		{
			glBegin(GL_TRIANGLES);

			//1
			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x(), _position.get_y(), 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x() + _width, _position.get_y(), 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x(), _position.get_y() - _height, 0.f);

			//2
			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x(), _position.get_y() - _height, 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x() + _width, _position.get_y(), 0.f);

			glColor4f(_color.get_r(), _color.get_g(), _color.get_b(), _color.get_a());
			glVertex3f(_position.get_x() + _width, _position.get_y() - _height, 0.f);

			glEnd();
		}
	}
}
