#ifndef IDOT_HPP
#define IDOT_HPP

#include <stdexcept>

#include "icolorshape.hpp"
#include "color.hpp"
#include "point.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IDot;
	}
}

#include "iline.hpp"
#include "itriangle.hpp"
#include "irectangle.hpp"
#include "icircle.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IDot : public IColorShape
		{
		protected:
			Point _position;
		public:
			IDot(Color color = Color(1.f, 1.f, 1.f, 1.f), Point position = Point(0.f, 0.f));

			virtual Point get_position() const;
			virtual void set_position(Point const position);

			bool intersects(IColorShape const *shape) const override;
			bool intersects(ILine const *line) const override;
			bool intersects(ITriangle const *triangle) const override;
			bool intersects(IRectangle const *rectangle) const override;
			bool intersects(ICircle const *circle) const override;
		};
	}
}

#endif
