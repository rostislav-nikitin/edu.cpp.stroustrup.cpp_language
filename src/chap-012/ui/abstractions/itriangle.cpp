#include "itriangle.hpp"

namespace UI
{
	namespace Abstractions
	{
		ITriangle::ITriangle(Color color, Point point_lb, Point point_ct, Point point_rb) : IColorShape(color), _points{point_lb, point_ct, point_rb}
		{
		}
	}
}
