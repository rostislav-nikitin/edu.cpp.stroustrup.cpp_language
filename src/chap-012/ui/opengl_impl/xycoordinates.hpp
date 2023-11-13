#ifndef XYCOORDINATES_HPP
#define XYCOORDINATES_HPP

#include "../abstractions/ixycoordinates.hpp"
#include "line.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class XYCoordinates : public IXYCoordinates
		{
		public:
			XYCoordinates(Color color, Point position, float line_width);
		};
	}
}

#endif
