#include "icircle.hpp"

namespace UI
{
	namespace Abstractions
	{
		ICircle::ICircle(Color color, Point center, float radius) 
				: IColorShape(color), _center(center), _radius(radius)
		{
		}
	}
}
