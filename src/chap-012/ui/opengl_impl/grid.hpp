#ifndef GRID_HPP
#define GRID_HPP

#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/igrid.hpp"

#include "../opengl_impl/line.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Grid : public IGrid
		{
		public:
			Grid(Color color, Point position, float width, float height, float line_width, float step,
				Color sub_color = Color(0.5f, 0.5f, 0.5f, 0.5f), int sub_divisions = 5);

			//void draw(IDrawContext *draw_context) override;
		};
	}
}

#endif
