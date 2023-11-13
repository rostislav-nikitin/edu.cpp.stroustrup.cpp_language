#ifndef IGRID_HPP
#define IGRID_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"
#include "compositeshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IGrid : public virtual CompositeShape
		{
		protected:
			Color _color;
			Point _position;
			float _width;
			float _height;
			float _line_width;
			float _step;

			Color _sub_color;
			int _sub_divisions;

		public:
			IGrid(Color color, Point position, float width, float height, float line_width, float step = -0.1f,
					Color sub_color = Color(0.5f, 0.5f, 0.5f, 05.f), int sub_divisions = 5); 
		};
	}
}

#endif
