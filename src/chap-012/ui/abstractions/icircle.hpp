#ifndef ICIRCLE_HPP
#define ICIRCLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ICircle : public IColorShape
		{
		protected:
			Point _center;
			float _radius;
		public:
			ICircle(Color color, Point center, float radius);
		};
	}
}

#endif
