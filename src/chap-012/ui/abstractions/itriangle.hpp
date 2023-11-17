#ifndef ITRIANGLE_HPP
#define ITRIANGLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "ishape.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ITriangle;
	}
}

#include "iline.hpp"
#include "irectangle.hpp"
#include "icircle.hpp"

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

			bool intersects(IColorShape const *shape) const override;
			bool intersects(ILine const *line) const;
			bool intersects(ITriangle const *triangle) const;
			bool intersects(IRectangle const *rectangle) const;
			bool intersects(ICircle const *circle) const;
		};
	}
}

#endif
