#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "color.hpp"
#include "idrawcontext.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IShape
		{
		public:
			virtual void draw(IDrawContext *context) = 0;

			virtual ~IShape() { };
		};
	}
}

#endif
