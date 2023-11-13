#ifndef LINE_HPP
#define LINE_HPP

#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/iline.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Line : public ILine
		{
		public:
			Line(Color const color, Point const start_position, Point const end_position, float size)
					: ILine(color, start_position, end_position, size)
			{
			}

			void draw(IDrawContext *draw_context) override;
		};
	}
}

#endif
