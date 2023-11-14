#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <GLFW/glfw3.h>

#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/color.hpp"
#include "../abstractions/point.hpp"
#include "../abstractions/itriangle.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Triangle : public ITriangle
		{
		public:
			Triangle(Color color, Point point_lb, Point point_ct, Point point_rb);
			
			void draw(IDrawContext *draw_context) override;
		};
	}
}

#endif
