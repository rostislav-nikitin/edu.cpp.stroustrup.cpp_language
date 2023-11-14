#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>

#include <GLFW/glfw3.h>

#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/icircle.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Circle : public ICircle
		{
		public:
			Circle(Color color, Point center, float radius);
			void draw(IDrawContext *draw_context) override;
		};
	}
}

#endif
