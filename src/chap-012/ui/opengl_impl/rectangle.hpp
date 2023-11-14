#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <GLFW/glfw3.h>

#include "../abstractions/color.hpp"
#include "../abstractions/point.hpp"
#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/irectangle.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Rectangle : public IRectangle
		{
		public:
			Rectangle(Color color, Point position, float width, float height);

			void draw(IDrawContext *draw_context) override;
		};
	}
}

#endif
