#ifndef ITRIANGLE_HPP
#define ITRIANGLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ITriangle : public IColorShape
		{
		protected:
			Point _points[3];
		public:
			ITriangle(Color color, Point point_lb, Point point_ct, Point point_rb);
		};
	}
}

#endif
