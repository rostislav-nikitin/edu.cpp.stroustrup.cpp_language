#ifndef IAPPLICATIONWINDOW_HPP
#define IAPPLICATIONWINDOW_HPP

#include <vector>

#include "point2i.hpp"
#include "ishape.hpp"
#include "compositeshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IApplicationWindow
		{
		public:
			virtual Point2i get_top_left() = 0;
			virtual void set_top_left(Point2i const) = 0;
			virtual int get_width() const = 0;
			virtual int get_height() const = 0;
			virtual void set_width(int value) = 0;
			virtual void set_height(int value) = 0;

			virtual CompositeShape *get_shapes_root() const = 0;

			virtual void draw() = 0;

			virtual ~IApplicationWindow() {}
		};
	}
}

#endif
