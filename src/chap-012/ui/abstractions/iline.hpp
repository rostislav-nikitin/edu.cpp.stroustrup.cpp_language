#ifndef ILINE_HPP
#define ILINE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ILine;
	}
}

#include "itriangle.hpp"
#include "irectangle.hpp"
#include "icircle.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ILine : public IColorShape
		{
		protected:
			Point _start_position;
			Point _end_position;
			float _size;

		public:
			ILine(Color const color, Point start_position, Point end_position, float size);

			Point get_start_positon();
			Point get_end_position();
			float get_size();

			bool intersects(IColorShape const *shape) const override;
			bool intersects(ILine const *line) const override;
			bool intersects(ITriangle const *triangle) const override;
			bool intersects(IRectangle const *rectangle) const override;
			bool intersects(ICircle const *circle) const override;
		};
	}
}

#endif
